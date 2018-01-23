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

Node* Insert_head(Node* head,int data){

	Node *naya=new Node();
	naya->data=data;
	naya->next=head;
	head=naya;
	return(head);
	
}

Node* Insert_specifiedposition(Node* head,int data,int position){
	Node * naya=new Node();
	naya->data=data;
	if(position==0){
		head=Insert_head(head,data);
		return(head);}
	else{	
	Node* temp=head;
	for(int i=0;i<=position-1;i++){
		if(i==position-1){
		        Node* inter=temp->next;
			temp->next=naya;
			naya->next=inter;

			}
			
		else{temp=temp->next;}}	
	}
	return(head);

}

Node* Delete(Node* head,int posiion){
	Node * naya=new Node();
	
	if(position==0){
		head=head->next;
		return(head);}
	else{	
	Node* temp=head;
	for(int i=0;i<=position-1;i++){
		if(i==position-1){
		        Node* inter=temp->next;
			
			inter=inter->next;
			temp->next=inter;

			}
			
		else{temp=temp->next;}}	
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
		init=Insert_tail(init,input);	
	}
	
	return(0);}

	




