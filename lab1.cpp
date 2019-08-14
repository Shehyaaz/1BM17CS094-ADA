/* A program to return floor of square root of  number using binary search*/
#include <iostream>
#include <fstream>
using namespace std;

int floorSqrt(int num){
	int beg = 0, end = num/2, mid = 0, res = 0;
	while(beg<=end){
		mid = (beg+end)/2;
		if(mid*mid == num) return mid;
		else if(num > mid*mid) {
			beg = mid+1; // move right
			res = mid;
		}
		else end = mid-1; //move left
	}
	return res;
}

int main()
{
	ifstream inFile;
	inFile.open("/home/bmsce/Documents/ADA lab/shehyaaz_floorsqrt/test.txt");
	if(!inFile){
		cout<<"Something unexpected has occurred"<<endl;
		return -1;
	}
	int num;
	while(inFile>>num){
		cout<<"Square root of"<<num<<" : "<<floorSqrt(num)<<endl;
	}
	return 0;
}
