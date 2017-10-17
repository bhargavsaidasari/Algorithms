#include<iostream>
#include<vector>
#include<cstdlib>
#include<iterator>
#include<algorithm>
#include<stdlib.h>
#include<ctime>
using namespace std;

struct node
{
	int data;
	struct node* next;
	struct node* prev;
};

struct array
{
	struct node* head;
};

class Graph
{
	 private:
		int V;
		array* list;
	 public:
		Graph(int V)
	{
		this->V=V;
		list=new array [V];
		for(int i=0;i<V;i++)
			list[i].head=NULL;
		}

	void addEdge(int src,int dest,bool direction)
		{

			node * newNode=new node;
			newNode->data=dest;
			newNode->next=NULL;
			newNode->next=list[src].head;
			list[src].head=newNode;
			if(direction){
				newNode = new node;
				newNode->data=src;
				newNode->next=NULL;
				newNode->next = list[dest].head;
			list[dest].head = newNode;}
}
	int edgeContraction(int src,int dest,int counter){
		
		node *newnode=new node;
		int edge;
		newnode=list[dest].head;
		if(list[dest].head != NULL && list[src].head != NULL){
		
			vector<int> src_elements=Elements(src);
			while(list[dest].head != NULL){
			
			int x=newnode->data;

			newnode=newnode->next;
			list[dest].head=newnode;
			//if(std::find(src_elements.begin(), src_elements.end(), x) == src_elements.end()) 
				addEdge(src,x,0);
				replaceEdge(x,dest,src);
				}
		counter=counter-1;
		return(counter);}
		else return(counter);
		
		}
	
	void replaceEdge(int src,int replaced,int replace){
		node *newnode1 =new node;
		newnode1=list[src].head;
		while(newnode1 != NULL){
			int test=newnode1->data;
			if(test==replaced){
				newnode1->data=replace;
				
				}
			newnode1=newnode1->next;
			
			
			}
}
		

	void printGraph()
        {
            int v;
            for (v = 0; v < V; ++v)
            {
                node* tmp = list[v].head;		//tmp has the address of (0,1..)vertex head 
                cout<<"\n Adjacency list of vertex "<<v<<"\n head ";
                while (tmp)
                {
                    cout<<"-> "<<tmp->data;
                    tmp = tmp->next;
                }
                cout<<endl;
            }
        }
	
	vector<int> Elements(int src){
		vector<int> element;
		element.push_back(src);
		node *newnode=new node;
		newnode=list[src].head;
		while(newnode != NULL){
			
			element.push_back(newnode->data);

			newnode=newnode->next;

		}return element;
		
		
		



}};

int main(){

	Graph gh(4);
	gh.addEdge(0,1,1);
	gh.addEdge(0,2,1);
	gh.addEdge(0,3,1);
	gh.addEdge(1,3,1);
	gh.addEdge(1,3,1);
	gh.addEdge(2,3,1);	
	gh.printGraph();
	int count=4;
	int v1,v2;
	srand(time(NULL));
        while(count!=2){
	v1=rand()%4;
	v2=rand()%4;
	cout<<v1<<v2<<endl;
	if(v1 !=v2){
	count=gh.edgeContraction(v1,v2,count);}}
	
		
			
        gh.printGraph();
} 

