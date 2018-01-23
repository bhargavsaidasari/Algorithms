#include<iostream>
using namespace std;


struct Node{
	int data;
	Node* next;
};

Node* Insert_tail(Node* head,int data){
	Node *naya=new Node();
	naya->data= data;
	naya->next=NULL;
	head=naya;
	Node *counter=head;
	return head;

    
  // Complete this method
	if(counter==NULL){
        	
        	head=naya;
        	
        	
        }
	else{
        	while(counter->next!=NULL){
            		counter=counter->next;
        		}
        naya->next=counter->next;
        counter->next=naya;
        
    }
	return(head); 


}

int main(){

	int numElements;
	cin>>numElements;
	int input;
	Node* init=NULL;
	for(int i=0;i<numElements;i++){
		cin>>input;	
		init=Insert(init,input);	
	}
	return(0);}

	




