#include <iostream>
#include <vector>
#include <algorithm>
#include<fstream>

using namespace std;

int first_partition(vector<int> &inpArr, int low , int high){
	//Partition subroutine

	int pivot = inpArr[low];
	int left_position = low ;
	int right_position = low+1 ;

	while(right_position <= high){
		if(inpArr[right_position] < inpArr[low]){
			if(left_position != low){
				swap(inpArr[right_position],inpArr[left_position]);
				left_position=left_position+1;}
			right_position=right_position+1;}
		
		else if(inpArr[right_position] > inpArr[low]){
			if(left_position==low){
				left_position = right_position;}
			right_position = right_position + 1;	
			}
	}
	if(left_position == low){
		swap(inpArr[high],inpArr[low]);
		return high;}

	else if(inpArr[left_position - 1] > inpArr[low]){
		return(low);
	}
	else{
		swap(inpArr[left_position-1] , inpArr[low]);
		return(left_position-1);
	}	

}

int last_partition(vector<int> &inpArr, int low , int high){
	//Partition subroutine
	swap(inpArr[low],inpArr[high]);
	int pivot = inpArr[low];
	int left_position = low ;
	int right_position = low+1 ;

	while(right_position <= high){
		if(inpArr[right_position] < inpArr[low]){
			if(left_position != low){
				swap(inpArr[right_position],inpArr[left_position]);
				left_position=left_position+1;}
			right_position=right_position+1;}
		
		else if(inpArr[right_position] > inpArr[low]){
			if(left_position==low){
				left_position = right_position;}
			right_position = right_position + 1;	
			}
	}
	if(left_position == low){
		swap(inpArr[high],inpArr[low]);
		return high;}

	else if(inpArr[left_position - 1] > inpArr[low]){
		return(low);
	}
	else{
		swap(inpArr[left_position-1] , inpArr[low]);
		return(left_position-1);
	}	

}

void median_routine(vector<int> &inpArr,int low,int high){
	int median = low + (high-low)/2 ;
	if(inpArr[low] > inpArr[high]){
		if(inpArr[median] >= inpArr[low]){
			return;}
		else if(inpArr[median] > inpArr[high]){
			swap(inpArr[median],inpArr[low]);
			return;}
		else{
			swap(inpArr[low],inpArr[high]);}}
	else{
		if(inpArr[median] >= inpArr[high]){
			swap(inpArr[high],inpArr[low]);
			return;}
		else if(inpArr[median] > inpArr[low]){
			swap(inpArr[median],inpArr[low]);
			return;}
		else{
			return;}}
}

int median_partition(vector<int> &inpArr, int low , int high){
	//Partition subroutine
	median_routine(inpArr,low,high);
	int pivot = inpArr[low];
	int left_position = low ;
	int right_position = low+1 ;

	while(right_position <= high){
		if(inpArr[right_position] < inpArr[low]){
			if(left_position != low){
				swap(inpArr[right_position],inpArr[left_position]);
				left_position=left_position+1;}
			right_position=right_position+1;}
		
		else if(inpArr[right_position] > inpArr[low]){
			if(left_position==low){
				left_position = right_position;}
			right_position = right_position + 1;	
			}
	}
	if(left_position == low){
		swap(inpArr[high],inpArr[low]);
		return high;}

	else if(inpArr[left_position - 1] > inpArr[low]){
		return(low);
	}
	else{
		swap(inpArr[left_position-1] , inpArr[low]);
		return(left_position-1);
	}	

}

int quickSort(vector<int> &inpArr , int low , int high){
	//
	if(low >= high){
		return 0;
	}
	int pivot_pos;
	pivot_pos = median_partition(inpArr,low,high);
	return(high-low + quickSort(inpArr,low,pivot_pos-1)+quickSort(inpArr,pivot_pos+1,high));
	
}


int main(){

	vector<int> inputArray;
	ifstream myfile ("quickSort.txt");
	if(myfile.is_open()){
		int value;
		while(myfile >> value){
			inputArray.push_back(value);}}
	int length = inputArray.size();
	cout << quickSort(inputArray,0,length-1)<<endl;

}
