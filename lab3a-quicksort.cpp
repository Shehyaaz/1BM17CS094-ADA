// Program to sort elements in an array in-place using QuickSort
#include <iostream>
using namespace std;

int partition(int arr[], int low, int high){
	int pivot = arr[low];
	int i = low+1;
	int j = high;
	int temp;
	while(1){
		while(arr[i]<=pivot && i<=high)
			i++;
		while(arr[j]>pivot && j>=low)
			j--;
		if(i<j){
			temp = arr[i];
			arr[i]=arr[j];
			arr[j]= temp;
		}
		else{
			arr[low]= arr[j];
			arr[j] = pivot;
			return j;
		}
	}
}

void quickSort(int arr[], int low, int high){
	if(low<high){
		int pivot_pos = partition(arr,low,high);
		quickSort(arr,low,pivot_pos-1);
		quickSort(arr,pivot_pos+1,high);
	}
}
int main()
{
	int n, *arr;
	cout<<"Enter number of elements :";
	cin>>n;
	arr = new int[n];
	for(int i = 0; i<n; i++){
		cout<<"Enter element :";
		cin>>arr[i];
	}
	quickSort(arr,0,n-1);
	cout<<"Sorted element are :\n";
	for(int i=0; i<n; i++)
		cout<<arr[i]<<"\t";
	cout<<"\n";
	return 0;
}
