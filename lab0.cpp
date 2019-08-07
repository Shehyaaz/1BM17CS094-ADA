#include<iostream>
using namespace std;

int* inputArray(int n){
	int *a = new int[n];
	cout<<"Enter "<<n<<" elements :\n";
	for(int i = 0; i<n; i++){
		cout<<"Enter number :";
		cin>>a[i];
	}
	return a;
}

int findMax(int a[], int size){
	int max  = a[0];
	for(int i = 1; i< size; i++){
		if(a[i]> max) 
			max = a[i];
	}
	return max;
}

int main(){
	int n;
	cout<<"Enter the number of elements :";
	cin>>n;
	int *a = inputArray(n);
	cout<<"Maximum element :"<<findMax(a,n)<<endl;
	return 0;
}
