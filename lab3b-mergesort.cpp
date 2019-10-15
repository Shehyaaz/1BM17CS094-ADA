// Program to sort elements of an array using merge sort
#include <iostream>
using namespace std;

void combine(int a[], int low, int mid, int high){
	int c[high];
	int i = low, j = mid+1, k = 0;
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
		a[i] = c[i-low];
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
/*
OUTPUT :
Enter number of elements :8 
Enter element :6
Enter element :8
Enter element :1
Enter element :3
Enter element :2
Enter element :5
Enter element :7
Enter element :4
Sorted element are :
1	2	3	4	5	6	7	8	
*/
