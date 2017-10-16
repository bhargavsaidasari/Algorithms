#include<iostream>
#include<vector>
#include<cstdlib>
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
		if(list[dest].head != NULL && list[src].head != NULL){
		
			vector<int> src_elements=Elements(src);
			vector<int> dest_elements=Elements(dest);
			counter=counter-1;}
		else return(counter);
		
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
		node *newnode=new node;
		newnode=list[src].head;
		while(newnode != NULL){
			
			element.push_back(newnode->data);

			newnode=newnode->next;

		}return element;
		
		
		



}};

int main(){

	Graph gh(6);
	gh.addEdge(0,1,1);
	gh.addEdge(0,2,1);
	gh.addEdge(0,3,1);
	gh.addEdge(2,3,1);
	gh.addEdge(1,3,1);
	gh.addEdge(1,4,1);
	gh.addEdge(1,5,0);	
	gh.printGraph();
	int count=4;

		count=gh.edgeContraction(0,1,count);
		
			
        gh.printGraph();
} 

