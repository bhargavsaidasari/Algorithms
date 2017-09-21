//Quicksort
#include<iostream>
#include<fstream>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#include<iterator>

using namespace std;

void swap(int arr[], int rightindex,int leftindex){
	int temp;
	temp=arr[leftindex];
	arr[leftindex]=arr[rightindex];	
	arr[rightindex]=temp;
}

int partition(int arr[],int low,int high){
	int leftindex=low+1;
	int rightindex=high;
	
         while(rightindex>=leftindex){	
		if(arr[leftindex]<arr[low]){
			leftindex++;}
		else{
			if(arr[rightindex]<=arr[low]){
				swap(arr,rightindex,leftindex);}
			rightindex--; 
}
	}
        swap(arr,rightindex,low);
	return rightindex;}


void quicksort(int arr[],int low,int high){
	int pivot;
	cout<<low<<high<<endl;
	if(low < high){

	pivot=partition(arr,low,high);
	quicksort(arr,low,pivot-1);
	quicksort(arr,pivot+1,high);}}
	
	
int main(){

//	int a[100000];
//	ifstream in("integer.txt",ios::in);
//	int number;
//	int counter=0;
//	while(in>>number){
//		a[counter]=number;
//		counter++;
//}
//	in.close();
////		
////	mergesort(a,0,99999);
	int a[]={5,2,10,8,1,9,4,3,6,7,1,1,46,99,34};
        quicksort(a,0,14);
	copy(a,a+sizeof(a)/sizeof(a[0]),ostream_iterator<int>(cout,","));
	cout<<endl;


        
	}

