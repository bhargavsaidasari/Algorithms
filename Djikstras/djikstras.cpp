#include<iostream>
#include<vector>
#include<cstdlib>
#include<iterator>
#include<algorithm>
#include<stdlib.h>
#include<ctime>
#include<limits>
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



int indexofSmallestElement(int array[], int size)
{
    int index = 0;

    for(int i = 1; i < size; i++)
    {
        if(array[i] < array[index])
            index = i;              
    }

    return index;
}   
    
void djikstra_simple(adjacency_matrix* g,int src,int* dist,int size){
	adjacency_matrix mat=*g;
	int distk;
	int count=1;
	int dist2[size];
	std::copy(dist,dist+size,dist2);
	int current_vertex=src;
	while(count<size)
	{
	for(int j=0;j<size;j++){
	if(mat.matrix[current_vertex][j]!=0){
	distk=dist[current_vertex]+mat.matrix[current_vertex][j];
	if(distk < dist[j]){
		dist[j]=distk;
		dist2[j]=distk;}}}
	count=count+1;
	dist2[current_vertex]=1000;
	current_vertex=indexofSmallestElement(dist2,size);}
	return;	}



int main(){
  int size=6;
  adjacency_matrix gh(size);
  adjacency_matrix *g=&gh;
  gh.addEdge(0,1,3);
  gh.addEdge(0,2,4);
  gh.addEdge(1,2,6);
  gh.addEdge(1,3,2);
  gh.addEdge(2,4,5);
  gh.addEdge(1,4,7);
  gh.addEdge(3,4,1);
  gh.addEdge(3,5,8);
  gh.addEdge(4,5,4);
  int source=0;	
  		
  int dist[size];
  for(int i=0;i<size;i++){	
  	dist[i] =1000;           // Unknown distance function from source to each node set to i
           }
  dist[source]=0;
  djikstra_simple(g,source,dist,size);
  for(int i=0;i<size;i++){
	cout<<dist[i]<<endl;}
  
  	
} 

