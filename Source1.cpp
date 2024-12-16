#include <bits/stdc++.h>
using namespace std;

int LinearSearch(int arr[], int n, int x){
	for(int i=0; i<n; i++){
		if(x == arr[i]){
			return 1;
		}
	}
	return 0;
}

int BinarySearch(int arr[], int n, int x){
	int left = 0, right = n - 1;
	while(left <= right){
		int mid = (left+right)/2;
		if(arr[mid] == x){
			return 1;
		}
		else if(arr[mid] < x){
			left = mid + 1;
		}else{
			right = mid - 1;
		}
	}
	return 0;
}

void swap(int &x, int &y){
	int temp = x;
	x = y;
	y = temp;
}

void InterchangeSort(int arr[], int n){
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(arr[i] > arr[j]){
				swap(arr[i], arr[j]);
			}
		}
	}
}

void SelectionSort(int arr[], int n){
	for(int i=0; i<n-1; i++){
		int min = i;
		for(int j=i+1; j<n; j++){
			if(arr[j] < arr[min]){
				min = j;
			}
		}
		swap(arr[i], arr[min]);
	}
}

void InsertionSort(int arr[], int n){
	for(int i=1; i<n; i++){
		int x = arr[i];
		int pos = i - 1;
		while(pos >= 0 && arr[pos] > x){
			arr[pos+1] = arr[pos];
			--pos;
		}
		arr[pos+1] = x;
	}
}

void BubbleSort1(int arr[], int n){
	for(int i=0; i<n-1; i++){
		for(int j=0; j<n-i-1; j++){
			if(arr[j] > arr[j+1]){
				swap(arr[j], arr[j+1]);
			}
		}
	}
}

void BubbleSort2(int arr[], int n){
	for(int i=0; i<n-1; i++){
		for(int j=n-1; j>i; j--){
			if(arr[j] < arr[j-1]){
				swap(arr[j], arr[j-1]);
			}
		}
	}
}

int Partition(int arr[], int left, int right){
	int i = left - 1;
	int pivot = arr[right];
	for(int j=left; j<right; j++){
		if(arr[j] < pivot){
			i++;
			swap(arr[i], arr[j]);
		}
	}
	++i;
	swap(arr[i], arr[right]);
	return i;
}

void QuickSort1(int arr[], int left, int right){
	if(left < right){
		int pos = Partition(arr, left, right);
		QuickSort1(arr, left, pos-1);
		QuickSort1(arr, pos+1, right);
	}
}

void QuickSort2(int arr[], int left, int right){
	int x = arr[(left+right)/2];
	int i = left;
	int j = right;
	do{
		while(arr[i] < x) i++;
		while(arr[j] > x)  j--;
		if(i<=j){
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}while(i < j);
	if(left < j) QuickSort2(arr, left, j);
	if(right > i) QuickSort2(arr, i, right);
}
int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	// int x;
	// cin >> x;
	// cout << LinearSearch(arr, n, x) << endl;
	//cout << BinarySearch(arr, n, x) << endl;
	// InterchangeSort(arr, n);
	//SelectionSort(arr, n);
	// InsertionSort(arr, n);
	// BubbleSort1(arr, n);
	// BubbleSort2(arr, n);
	 QuickSort1(arr, 0, n-1);
	// QuickSort2(arr, 0, n-1);
	for(int i=0; i<n; i++){
		cout << arr[i] << ' ';
	}
	return 0;
}