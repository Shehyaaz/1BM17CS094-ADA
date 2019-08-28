//Program to compare number of comparisons for selection, bubble, and merge sort
#include <iostream>
using namespace std;

void selectionSort(int A[], int n){
	int i,j,temp, min;
	int comp =0;
	for(i=0;i<n-1;i++){  //using Selection Sort
		min=i;
		for(j=i+1;j<n;j++){
			comp++;   //to count number of comparisons, this statement must be before the if
			if(A[j]<A[min]){ 
				min = j;
			}
		}
		temp  =A[i];
		A[i] = A[min];
		A[min]=temp;
	}
	cout<<"Number of comparisons for Selection Sort :"<<comp<<endl;
}

void bubbleSort(int A[], int n){
	int i,j,temp;
	int comp =0;
	for(i=0;i<n-1;i++){
		for(j=0; j<n-1-i;j++){
			comp++;  //to count number of comparisons, this statement must be before the if
			if(A[j]>A[j+1]){
				temp = A[j+1];
				A[j+1]=A[j];
				A[j]=temp;
			}
		}
	}
	cout<<"Number of comparisons for bubble sort :"<<comp<<endl;
}

void combine(int a[], int low, int mid, int high, int &comp){
	int c[high];
	int i = low, j = mid+1, k = low;
	while(i<= mid && j<= high){
		comp++;
		if(a[i]<a[j])
			c[k++]=a[i++];
		else
			c[k++]= a[j++];
	}
	if(i>mid){
		while(j<=high)
			c[k++] = a[j++];
	}
	if(j>high){
		while(i<=mid)
			c[k++] = a[i++];
	}
	for(i = low; i<=high; i++)
		a[i] = c[i];
}

void split(int a[], int low, int high, int &comp){
	if(low<high){
		int mid = (low+high)/2;
		split(a,low,mid,comp);
		split(a, mid+1, high,comp);
		combine(a,low, mid, high,comp);
	}
}

void mergeSort(int a[], int n){
	int comp = 0;
	split(a,0,n-1,comp);
	cout<<"Number of comparisons for merge sort :"<<comp<<endl;
}

int main()
{
	int n, *arr1, *arr2, *arr3;
	cout<<"Enter number of elements :";
	cin>>n;
	arr1 = new int[n];
	arr2 = new int[n];
	arr3 = new int[n];
	for(int i = 0; i<n; i++){
		cout<<"Enter element :";
		cin>>arr1[i];
		arr2[i] = arr1[i];
		arr3[i] = arr1[i];
	}
	selectionSort(arr1,n);
	bubbleSort(arr2,n);
	mergeSort(arr3,n);
	cout<<endl;
	return 0;
}
