#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

long merge(vector<int> &inpArr, int low , int low_high, int high){
	
	vector<int> temp;
	int count = low;
	int count_right = low_high+1;
	//cout<<low<<endl;
	long inversions = 0;
	while(count <= low_high){
	// 
		if(count_right>high){
			temp.push_back(inpArr.at(count));
			//inversions += low_high - count + 1;
			count = count+1;
			
		}
		else if(inpArr.at(count_right) >= inpArr.at(count)){
			temp.push_back(inpArr.at(count));
			count= count+1;}
		else if(inpArr.at(count_right) < inpArr.at(count)){
			temp.push_back(inpArr.at(count_right));
			count_right=count_right+1;
			inversions += low_high - count + 1 ;
		}
		
		
		}

	//cout << "Count Right" << count_right <<endl;
	if(count_right <= high){
	
		for(int i=count_right;i<=high;i++){
			temp.push_back(inpArr.at(i));
			}
		}
	//cout << low << endl;

	for(int i=0;i<temp.size();i++){
		//cout << "last loop" << endl;
		inpArr.at(i+low) = temp.at(i);
	}

	
	return(inversions);

}
	

long mergeSort(vector<int>& inpArr, int low_index , int high_index){

	if(low_index >= high_index){
		//do nothing ;
		return(0);
	}
	else{
		long left_inversion,right_inversion,merge_inversion;
		long divider = low_index + floor((high_index-low_index)/2);
		left_inversion = mergeSort(inpArr,low_index,divider);
		right_inversion = mergeSort(inpArr,divider+1,high_index);
		merge_inversion = merge(inpArr,low_index,divider,high_index);
		return(left_inversion+right_inversion + merge_inversion);}
	}
		

	
int main(){

	vector<int> inputArray;
	ifstream myfile ("integerArray.txt");
	if(myfile.is_open()){
		int value;
		while(myfile >> value){
			inputArray.push_back(value);}}
	
	cout<< "Number of inversions is : " << mergeSort(inputArray,0,inputArray.size()-1) << endl;
	
}

