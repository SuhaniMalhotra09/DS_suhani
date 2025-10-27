Q7.//Let A[1 .... n] be an array of n real numbers. A pair (A[i], A[j ]) is said to be an inversion
//if these numbers are out of order, i.e., i < j but A[i]>A[j ]. Write a program to count the number
//of inversions in an array.

  #include<iostream>

using namespace std;
int main(){
int n;
cout<<"enter number of elements in the array";
cin>>n;
int arr[n];
int count=0;
cout<<"enter array elemnts";
for(int i=0;i<n;i++){
     cin>>arr[i];
}
for(int i=0;i<n;i++){
	for(int j=i+1;j<n;j++){
		if(arr[i]>arr[j]){
			count++;
		}
	}
}
cout<<"number of inversions in the array are:"<<count;
return 0;
}
