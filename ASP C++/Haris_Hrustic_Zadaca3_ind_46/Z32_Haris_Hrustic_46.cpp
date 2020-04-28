#include <iostream>
#include<list>
#include<cmath>
//Hrustic Haris br:46 H.H
using namespace std;

	
	void heapify(int niz[], int duzina, int i){
		
    int najveci = i;
    int lijevi = 2 * i + 1;
    int desni = 2 * i + 2;

    if (lijevi < duzina && niz[lijevi] > niz[najveci])
        najveci = lijevi;

    if (desni < duzina && niz[desni] > niz[najveci])
        najveci = desni;

    if (najveci != i)
    {
        swap(niz[i], niz[najveci]);

        heapify(niz, duzina, najveci);
    }
}//Hrustic Haris br:46 H.H

void heapSort(int niz[], int duzina)
{
    for (int i = duzina / 2 - 1; i >= 0; i--)
        heapify(niz, duzina, i);

    for (int i = duzina - 1; i >= 0; i--)
    {
        swap(niz[0], niz[i]);
        heapify(niz, i, 0);
    }
}//Hrustic Haris br:46 H.H

void ispis(int niz[], int duzina)
{//Hrustic Haris br:46 H.H
    for (int i = 0; i < duzina; ++i)
        cout << niz[i] << " ";
    cout << endl;
}
void display(int *array, int size) {
   for(int i = 1; i<=size; i++)
      cout << array[i] << " ";
   cout << endl;
}
int getMax(int array[], int size) {
   int max = array[1];
   for(int i = 2; i<=size; i++) {
      if(array[i] > max)
         max = array[i];
   }
   return max;  
}//Hrustic Haris br:46 H.H
void countSort(int *array, int size) {
   int output[size+1];
   int max = getMax(array, size);
   int count[max+1];      
   for(int i = 0; i<=max; i++)
      count[i] = 0;     
   for(int i = 1; i <=size; i++)
      count[array[i]]++;      
   for(int i = 1; i<=max; i++)
      count[i] += count[i-1];     
   for(int i = size; i>=1; i--) {
      output[count[array[i]]] = array[i];
      count[array[i]] -= 1;  
   }//Hrustic Haris br:46 H.H
   for(int i = 1; i<=size; i++) {
      array[i] = output[i];  
   }
}//Hrustic Haris br:46 H.H
 
void radixSort(int *arr, int n, int max) {
   int i, j, m, p = 1, index, temp, count = 0;
   list<int> pocket[10];       
   for(i = 0; i< max; i++) {
      m = pow(10, i+1);
      p = pow(10, i);
      for(j = 0; j<n; j++) {
         temp = arr[j]%m;
         index = temp/p;       
         pocket[index].push_back(arr[j]);
      }
      count = 0;
      for(j = 0; j<10; j++) {
         while(!pocket[j].empty()) {
            arr[count] = *(pocket[j].begin());
            pocket[j].erase(pocket[j].begin());
            count++;
         }
      }
   }
}
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    int L[n1], R[n2]; 
  
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    i = 0; 
    j = 0;  
    k = l;  
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        int m = l+(r-l)/2; 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
        merge(arr, l, m, r); 
    } 
} 
void display2(int *array, int size) {
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}
int main(){
	
	cout << "Primjer heap sorta, niz je vec definisan u programu, provjerite kod! \n";
	cout << "Enter za nastavak - Haris Hrustic 46 \n";
	system("pause");
	
    int niz[] = {2,12,24,3,13,25,9,18,185,231}; // unesite zeljene brojeve
    int duzina = sizeof(niz) / sizeof(niz[0]);
	
	printf("Dati niz je \n"); 
    ispis(niz, duzina);
    
	heapSort(niz, duzina);
    cout << "Niz nakon sortiranja: \n";
    ispis(niz, duzina); 
    //Hrustic Haris br:46 H.H
    cout << endl;
    cout << "Ovo je bio primjer heap sorta. - 46 Hrustic Haris. \n";
    cout << "Sljedeci je counting sort, enter za nastavak! - 46 Hrustic Haris.\n";
    
    system("pause");
    system("cls");
    //Hrustic Haris br:46 H.H
    int n;
   cout << "Unesite broj elemenata: ";
   cin >> n;
   int arr[n+1];      
   cout << "Unesite elemente:" << endl;
   for(int i = 1; i<=n; i++) {
      cin >> arr[i];
   }//Hrustic Haris br:46 H.H
   cout << "Niz prije sortiranja: ";
   display(arr, n);
   countSort(arr, n);
   cout << "Niz nakon sortiranja: ";
   display(arr, n);
    
    //Hrustic Haris br:46 H.H
    cout << endl;
    cout << "Ovo je bio primjer counting sorta. - 46 Hrustic Haris. \n";
    cout << "Sljedeci je radix sort, enter za nastavak! - 46 Hrustic Haris.\n";
    
    system("pause");
    system("cls");
    //Hrustic Haris br:46 H.H
    int y, max;
   cout << "Unesite broj elemenata: ";
   cin >> y;
   cout << "Maksimalan broj cifara: ";
   cin >> max;
   int arrr[y];  
   cout << "Unesite elemente:" << endl;
   for(int i = 0; i<y; i++) {
      cin >> arrr[i];
   }
   cout << "Niz prije sortiranja: ";
   display2(arrr, y);
   radixSort(arrr, y, max);
   cout << "Niz nakon sortiranja: ";
   display2(arrr, y);
    //Hrustic Haris br:46 H.H
    cout << endl;
    cout << "Ovo je bio primjer radix sorta. - 46 Hrustic Haris. \n";
    cout << "Sljedeci je merge sort, enter za nastavak! - 46 Hrustic Haris.\n";
    
    system("pause");
    system("cls");
    //Hrustic Haris br:46 H.H
    
    int arr3[] = {12, 11, 13, 5, 6, 7}; 
    int arr_size = sizeof(arr3)/sizeof(arr3[0]); 
  
    printf("Dati niz je \n"); 
    ispis(arr3, arr_size); 
  
    mergeSort(arr3, 0, arr_size - 1); 
  
    printf("\nSortiran niz je \n"); 
    ispis(arr3, arr_size); 
     //Hrustic Haris br:46 H.H
    cout << endl;
    cout << "Ovo je bio primjer merge sorta. - 46 Hrustic Haris. \n";
    system("pause");
    return 0;
}
