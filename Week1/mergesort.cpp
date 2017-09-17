#include <iostream>
#include<fstream>
#include<math.h>
#include<stdlib.h>
#include <stdio.h>
#include<iterator>



using namespace std;
long int inversion=0;




void merge(int arr[],int l,int m,int r){

          int counter=0;
	  int d[r-l+1];
	  for(int index2=0;index2<=r-l;index2++){        
	  d[index2]=arr[index2+l];
	  }	
	  int i=l;
	  int j=m+1;
	  int index;
          int j1=m+1;
          for(index=l;index<=r;index++){
		if((d[i-l]>=d[j-l] || i>m) && j<r+1){
		 	
			
			arr[index]=d[j-l];
			if(i<=m){		
			inversion=inversion+(j1-i);
			j1=j1-1;}
			j++;
			j1++;
				
			
}			else{
	
                        
			arr[index]=d[i-l];
		        i++;

}
}
}

void mergesort(int arr[],int l,int r){
        
        if(r>l){ 
	int m=(l+r)/2;
	mergesort(arr,l,m);
	mergesort(arr,m+1,r);

	merge(arr,l,m,r);
//	copy(arr,arr+4,ostream_iterator<int>(cout,","));
//        cout<<endl;
//	cout<<inversion<<endl;;
	}


}


int main(){

	int a[100000];
	ifstream in("integer.txt",ios::in);
	int number;
	int counter=0;
	while(in>>number){
		a[counter]=number;
		counter++;
}
	in.close();
//		
//	mergesort(a,0,99999);
//	int a[]={5,2,10,8,1,9,4,3,6,7};
	mergesort(a,0,sizeof(a)/sizeof(a[0])-1);
//	copy(a,a+sizeof(a)/sizeof(a[0]),ostream_iterator<int>(cout,","));
//	cout<<endl;
	cout<<inversion;

        
	}

	
