 
template <typename HashedObj>
bool LinearProbHashTable<HashedObj>::Contains(const HashedObj & x, int & probes) const {
 
  probes = 1;
  int temp = FindPos(x, probes);
  return IsActive(temp);
}

template <typename HashedObj>
void LinearProbHashTable<HashedObj>::MakeEmpty() {
  current_size_ = 0;
  collisions_counter_ = 0;
  for (auto & entry : array_)
    entry.info_ = kEmpty;
}

template <typename HashedObj>
bool LinearProbHashTable<HashedObj>::Insert(const HashedObj & x) {
  int probes = 0;
	
  int current_pos = FindPos(x, probes);
  if (IsActive(current_pos))
    return false;
  
  array_[current_pos].element_ = x;
  array_[current_pos].info_ = kActive;
  
  if (++current_size_ > array_.size() / 2)
    Rehash();
  
  collisions_counter_ += probes;
  return true;
}
    
template <typename HashedObj>
bool LinearProbHashTable<HashedObj>::Insert(HashedObj && x) {
  int probes = 0;
	
  int current_pos = FindPos(x, probes);
  if (IsActive(current_pos))
    return false;
  
  array_[current_pos] = std::move(x);
  array_[current_pos].info_ = kActive;
  
  if (++current_size_ > array_.size() / 2)
    Rehash();
		
  collisions_counter_ += probes;
  return true;
}

template <typename HashedObj>
bool LinearProbHashTable<HashedObj>::Remove(const HashedObj & x) {
  int current_pos = FindPos(x);
  if (!IsActive(current_pos))
    return false;
  
  array_[current_pos].info_ = kDeleted;
  return true;
}

template <typename HashedObj>
int LinearProbHashTable<HashedObj>::FindPos(const HashedObj & x, int &probes) const {
  int current_pos = InternalHash(x);
  
  while (array_[current_pos].info_ != kEmpty && array_[current_pos].element_ != x ) {
    ++probes; 
    ++current_pos;
    if (current_pos >= array_.size())
      current_pos -= array_.size( );
  }
  return current_pos;
}

template <typename HashedObj>
void LinearProbHashTable<HashedObj>::Rehash() {
  vector<HashEntry> old_array = array_;
	 
  int temp_col_counter_ = collisions_counter_;
  array_.resize(NextPrime(2 * old_array.size()));
  for (auto & entry : array_)
    entry.info_ = kEmpty;
  
  current_size_ = 0;
  for (auto & entry : old_array)
    if (entry.info_ == kActive)
      Insert(std::move(entry.element_));
	
  collisions_counter_ = temp_col_counter_;
}
 
template <typename HashedObj>
int LinearProbHashTable<HashedObj>::CurrentSize() {
  return current_size_;
}
 
template <typename HashedObj>
int LinearProbHashTable<HashedObj>::TableSize() {
  return array_.size();
}
 
template <typename HashedObj>
int LinearProbHashTable<HashedObj>::CollisionCount() {
  return collisions_counter_;
}



