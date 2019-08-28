// Program to sort elements of an array using merge sort
#include <iostream>
using namespace std;

void combine(int a[], int low, int mid, int high){
	int c[high];
	int i = low, j = mid+1, k = low;
	while(i<= mid && j<= high){
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

void split(int a[], int low, int high){
	if(low<high){
		int mid = (low+high)/2;
		split(a,low,mid);
		split(a, mid+1, high);
		combine(a,low, mid, high);
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
	split(arr,0,n-1);
	cout<<"Sorted element are :\n";
	for(int i=0; i<n; i++)
		cout<<arr[i]<<"\t";
	cout<<"\n";
	return 0;
}
