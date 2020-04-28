 
#include "LinearProbing.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

template <typename HashTableType>
void TestFunctionForHashTable(HashTableType &hash_table, const string &words_filename, const string &query_filename) {
  ifstream fin;
  fin.open(words_filename);
  string word;
	
  while (fin >> word) {
    hash_table.Insert(word);
  }
	
  fin.close();
	 
  double n = hash_table.CurrentSize();
  cout << "Elementi u tabeli (N):" << '\t' << n << endl;
 
  double t = hash_table.TableSize();
  cout << "Velicina tabele (T): " << '\t' << '\t' << t << endl;
 
  cout << "Load Faktor (N/T):" << '\t' << '\t' << n/t << endl;

 
  float c = hash_table.CollisionCount();
  cout << "Ukupan broj kolizija: (C):" << '\t' << '\t' << '\t' << c << endl;
 
  cout << "Prosjecan broj kolizija (C/N):" << '\t' << c/n << endl;
	
  cout << endl << endl;
	
  fin.open(query_filename);
  int probes = 0;
  while (fin >> word) {
    if(hash_table.Contains(word, probes) == true)
      if(word.length() < 10)
        cout << word << '\t' << '\t' << "Pronadjeno" << '\t' << '\t' << probes << endl;
      else
        cout << word << '\t' << "Pronadjeno" << '\t' << '\t' << probes << endl;
    else
      if(word.length() < 10)
        cout << word << '\t' << '\t' << "Nije Pronadjeno" << '\t' << probes << endl;
      else
        cout << word << '\t' << "Nije Pronadjeno" << '\t' << probes << endl;
  }

  fin.close();
}

int main(int argc, char **argv) {
  if (argc != 4) {
    cout << "Koristi: " << argv[0] << " <wordsfilename> <queryfilename> <flag>" << endl;
    return 0;
  }
  
  const string words_filename(argv[1]);
  const string query_filename(argv[2]);
  const string param_flag(argv[3]);
  cout << "Unesena rijec je " << words_filename << ", i query fajl je " << query_filename << endl;
	
  ifstream fin;
  fin.open(words_filename);
  if (fin.fail()) {
    cout << "Fajl " << words_filename << " se nije uspio otvoriti." << endl;
    abort();
  } else {
    fin.close();
  }
 
  fin.open(query_filename);
  if (fin.fail()) {
    cout << "Fajl " << query_filename << " se nije uspio otvoriti." << endl;
    abort();
  } else {
    fin.close();
  }
	
  if (param_flag == "linear") { 
    LinearProbHashTable<string> linear_probing_table;
    TestFunctionForHashTable(linear_probing_table, words_filename, query_filename);    		
  else {
    cout << "Nepoznat tip kolizije " << param_flag << endl;
  }
	
  return 0;
}
