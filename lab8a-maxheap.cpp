/*
Program 8a :Check if a given array represents a Binary Max Heap.
*/

#include <iostream>
using namespace std;

bool isMaxHeap(int arr[], int n){
	for(int i =0; i<=n/2; i++){
		if(2*i+1 <n && arr[2*i+1]> arr[i]) //checking for left child 
			return false;
		if(2*i+2 <n && arr[2*i+2]>arr[i])// checking for right child
			return false;
	}//end of loop
	return true;
}//end of method

int main(){
	int n, *arr;
	cout<<"Enter number of elements :";
	cin>>n;
	arr = new int[n];
	cout<<"Enter "<<n<<" elements :\n";
	for(int i =0; i<n; i++)
		cin>>arr[i];
	if(isMaxHeap(arr,n))
		cout<<"True\n";
	else
		cout<<"False\n";
	return 0;
}//end of main

/*
OUTPUT :
Enter number of elements :6
Enter 6 elements :
90 15 10 7 12 2
True
*/
