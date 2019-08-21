
#include <iostream>
using namespace std;

void largestElements(int A[], int n, int k){
	int i,j,temp;
	for(i=0;i<k;i++){
		for(j=0; j<n-1-i;j++){
			if(A[j]>A[j+1]){
				temp = A[j+1];
				A[j+1]=A[j];
				A[j]=temp;
			}
		}
		cout<<A[n-i-1]<<"\t";
	}
}
int main()
{
	int *A, n, k;
	cout<<"Enter number of elements :";
	cin>>n;
	A = new int[n];
	for(int i=0;i<n;i++){
		cout<<"Enter element :";
		cin>>A[i];
	}
	cout<<"Enter k :";
	cin>>k;
	largestElements(A,n,k);
	cout<<"\n";
	return 0;
}
