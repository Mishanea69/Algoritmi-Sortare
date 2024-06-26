#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;

int *arr;
int n = 0;
void readArray(int nrElemente, string fName){
    arr = (int*) malloc(nrElemente* sizeof(int));
    ifstream f(fName);
    int a;
    while (f >> a)
    {
        arr[n]=a;
        n++;
    }
    f.close();
}

void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << "\n";
}

void saveSortedArray(int arr[], int size){
    ofstream f("sorted.txt");
    for (int i = 0; i < size; i++)
		f << arr[i] << "\n";
    f.close();
}

void bubbleSort(int arr[], int n)
{
	bool swapped;
    int temp;
	for (int i = 0; i<n-1; i++) {
		swapped = false;
		for (int j = i+1; j<n; j++) {
			if (arr[i] > arr[j]) {
				temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
				swapped = true;
			}
		}
		if (!swapped)
			break;
	}
}

void quickSort(int v[], int st, int dr)
{
	if(st < dr)
	{
		int m = (st + dr) / 2;
		int aux = v[st];
		v[st] = v[m];
		v[m] = aux;
		int i = st , j = dr, d = 0;
		while(i < j)
		{
			if(v[i] > v[j])
			{
				aux = v[i]; 
				v[i] = v[j];
				v[j] = aux;
				d = 1 - d;
			}
			i += d;
			j -= 1 - d;
		}
		quickSort(v, st , i - 1);
		quickSort(v, i + 1 , dr);
	}
}

void selectionSort(int arr[], int n) 
{ 
    int i, j, min_idx; 
  
    for (i = 0; i < n - 1; i++) { 
        if(i==100000) break;
        min_idx = i; 
        for (j = i + 1; j < n; j++) { 
            if (arr[j] < arr[min_idx]) 
                min_idx = j; 
        } 
        if (min_idx != i) 
            swap(arr[min_idx], arr[i]); 
    } 
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
 
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void merge(int array[], int const left, int const mid,
           int const right)
{
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;
 
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];
 
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
 
    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;
 
    while (indexOfSubArrayOne < subArrayOne
           && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
 
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
 
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}
void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return;
 
    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
void countSort(int arr[], int n, int exp)
{
    int output[n];
    int i, count[10] = { 0 };
 
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
 
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
 
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
void radixsort(int arr[], int n)
{
    int m = getMax(arr, n);

    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

bool isSorted(int a[], int n)
{
    while (--n > 0)
        if (a[n] < a[n - 1])
            return false;
    return true;
}
void shuffle(int a[], int n)
{
    for (int i = 0; i < n; i++)
        swap(a[i], a[rand() % n]);
}
void bogosort(int a[], int n)
{
    while (!isSorted(a, n))
        shuffle(a, n);
}
 
void SortingTime(){
	int *t;
	t = (int*) malloc(n * sizeof(int));
	for(int i =0; i<n; i++) t[i] = arr[i];

	struct timespec start, end;
	clock_gettime(CLOCK_MONOTONIC, &start);
	ios_base::sync_with_stdio(false);

    quickSort(t, 0, n);
		clock_gettime(CLOCK_MONOTONIC, &end);
	    double time_taken;
    	time_taken = (end.tv_sec - start.tv_sec) * 1e9;
    	time_taken = (time_taken + (end.tv_nsec - start.tv_nsec)) * 1e-9;
    	cout << "quickSort : " << fixed << time_taken << setprecision(9);
    	cout << " sec" << endl;
		clock_gettime(CLOCK_MONOTONIC, &start);

	for(int i =0; i<n; i++) t[i] = arr[i];	
	radixsort(t, n);
		clock_gettime(CLOCK_MONOTONIC, &end);
    	time_taken = (end.tv_sec - start.tv_sec) * 1e9;
    	time_taken = (time_taken + (end.tv_nsec - start.tv_nsec)) * 1e-9;
    	cout << "radixsort : " << fixed << time_taken << setprecision(9);
    	cout << " sec" << endl;	
		clock_gettime(CLOCK_MONOTONIC, &start); 


	for(int i =0; i<n; i++) t[i] = arr[i];	
	mergeSort(t, 0, n - 1);
		clock_gettime(CLOCK_MONOTONIC, &end);
    	time_taken = (end.tv_sec - start.tv_sec) * 1e9;
    	time_taken = (time_taken + (end.tv_nsec - start.tv_nsec)) * 1e-9;
    	cout << "mergeSort : " << fixed << time_taken << setprecision(9);
    	cout << " sec" << endl;	
		clock_gettime(CLOCK_MONOTONIC, &start); 

	for(int i =0; i<n; i++) t[i] = arr[i];	
	insertionSort(t, n);
		clock_gettime(CLOCK_MONOTONIC, &end);
    	time_taken = (end.tv_sec - start.tv_sec) * 1e9;
    	time_taken = (time_taken + (end.tv_nsec - start.tv_nsec)) * 1e-9;
    	cout << "insertionSort : " << fixed << time_taken << setprecision(9);
    	cout << " sec" << endl;	
		clock_gettime(CLOCK_MONOTONIC, &start);

	for(int i =0; i<n; i++) t[i] = arr[i];	
	selectionSort(t, n);
		clock_gettime(CLOCK_MONOTONIC, &end);
    	time_taken = (end.tv_sec - start.tv_sec) * 1e9;
    	time_taken = (time_taken + (end.tv_nsec - start.tv_nsec)) * 1e-9;
    	cout << "selectionSort : " << fixed << time_taken << setprecision(9);
    	cout << " sec" << endl;	
		clock_gettime(CLOCK_MONOTONIC, &start);

	for(int i =0; i<n; i++) t[i] = arr[i];	
	bubbleSort(t, n);
		clock_gettime(CLOCK_MONOTONIC, &end);
    	time_taken = (end.tv_sec - start.tv_sec) * 1e9;
    	time_taken = (time_taken + (end.tv_nsec - start.tv_nsec)) * 1e-9;
    	cout << "bubbleSort : " << fixed << time_taken << setprecision(9);
    	cout << " sec" << endl;	
}

int main()
{
    int nr; string nume;
    cout << "introduceti numarul de elemente sortate: ";
    cin >> nr; 
    cout << "\nIntroduceti numele fisierului: ";
    cin >> nume;

    readArray(nr, nume);
	
	SortingTime();

    //quickSort(arr, 0, n);
	//selectionSort(arr, n);
	//radixsort(arr, n);
	//insertionSort(arr, n);
	//mergeSort(arr, 0, n - 1);
	//bubbleSort(arr, n);
	//bogosort(arr, n);

	//printArray(arr, n);
    //saveSortedArray(arr, n);
	return 0;
}