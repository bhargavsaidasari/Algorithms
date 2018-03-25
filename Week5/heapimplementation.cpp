#include<iostream>
#include<vector>
#include<cstdlib>
#include<iterator>
#include<algorithm>
#include<stdlib.h>

using namespace std;

class adjacency_matrix{
	private:
		int N;
		
	public:
	int** matrix;
	adjacency_matrix(int N){
		this->N=N;
		matrix = new int*[N];
		for(int i = 0; i < N; ++i){
    			matrix[i] = new int[N];	}}
	void addEdge(int src,int dest,int weight){
		    this->matrix[src][dest]=weight;	}};

class Heap{
	private:
		vector<int> unresolved;
		void bubble_down(int num){
			int left_child=2*num+1;
			if(left_child>=unresolved.size()){
				return;}
			int right_child=2*num+2;
			if(unresolved[left_child]<unresolved[num] || unresolved[right_child]<unresolved[num]){
				if(unresolved[left_child] < unresolved[right_child]){
					swap(unresolved[num],unresolved[left_child]);
					num=left_child;}
				else{
					swap(unresolved[num],unresolved[left_child]);
					num=right_child;}
				bubble_down(num);		
				}
			
		};	
		void bubble_up(int num){
		     int parent_index= (num-1)/2;
		     if(unresolved[num]<unresolved[parent_index]){
		     	swap(unresolved[num],unresolved[parent_index]);
		     	num=parent_index;
		     	bubble_up(num);}
		}
	public:
	
	       Heap(int *array,int length){
	       
	            for(int i=0;i<length;i++){
	            	unresolved.push_back(array[i]);}
	            	heapify();}
	            	
	       void heapify(){
	       		int length=unresolved.size();
	       		for(int v=length-1;v>=0;v--){
	       			bubble_down(v);}}     	
	             		    
	
	       void Insert(int value){
	             unresolved.push_back(value);
	             bubble_up(unresolved.size()-1);}
	       int extract_min(){
	       	     int minimum=unresolved[0];
	       	     int length=unresolved.size();
	       	     swap(unresolved[0],unresolved[length-1]);
	       	     unresolved.pop_back();	
	             bubble_down(0);
	             return(minimum);}};
	             
int main()
{
    int array[] = {0, 5, 8, 4, 40,70,4,5};

    Heap minTest(array, 8);

    for(int i=0; i<8; ++i)
    {
        cout << minTest.extract_min()<<endl;
        
    }

    

    return 0;
}	             
		
				    
		    
