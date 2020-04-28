#include <iostream>
#include <conio.h>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

struct n  
{
  int priority;
  int info;
  struct n *next;
};
class Priority_Queue
{
private:
  n *f;

public:
  Priority_Queue()
  {

    f = NULL;
  }
  void insert(int i, int p)
  {
    n *t, *q;
    t = new n;
    t->info = i;
    t->priority = p;
    if (f == NULL || p < f->priority)
    {
      t->next = f;
      f = t;
    }
    else
    {
      q = f;
      while (q->next != NULL && q->next->priority <= p)
        q = q->next;
      t->next = q->next;
      q->next = t;
    }
  }
  void delet()
  {
    n *t;
    if (f == NULL)  
      cout << "Red Underflow\n";
    else
    {
      t = f;
      cout << "Obrisani item je: " << t->info << endl;
      f = f->next;
      free(t);
    }
  }
  void show()  
  {
    n *ptr;
    ptr = f;
    if (f == NULL)
      cout << "Red je prazan\n";
    else
    {
      cout << "Red je :\n";
      cout << "Prioritet Itema\n";
      while (ptr != NULL)
      {
        cout << ptr->priority << " " << ptr->info << endl;
        ptr = ptr->next;
      }
    }
  }
};
int main()
{
  int c, i, p;
  Priority_Queue pq;
  do
  {
    cout << "1.Stavi u prior red\n";
    cout << "2.Izvadi iz prior reda\n";
    cout << "3.Prikazi prior red\n";
    cout << "4.Exit\n";
    cout << "Unesite vas izbor : ";
    cin >> c;
    switch (c)
    {
    case 1:
      cout << "Unesite vrijednost itema koji se dodaje u red : ";
      cin >> i;
      cout << "Unesite njegov prioritet : ";
      cin >> p;
      pq.insert(i, p);
      break;
    case 2:
      pq.delet();
      break;
    case 3:
      pq.show();
      break;
    case 4:
      break;
    default:
      cout << "Pogresan izbor\n";
    }
  } while (c != 4);

  return 0;
}
