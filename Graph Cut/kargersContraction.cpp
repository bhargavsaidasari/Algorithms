#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>
#include<time.h>
#include<climits>

using namespace std;


int findIfEdge(vector<vector<int>> &adjMatrix,int v1, int v2){
	if(adjMatrix[v1][v2] >= 1){
		return 1;
	}
	else{
		return 0 ;
	}
} 

void deleteRow(vector<vector<int>> &adjMatrix , int row){
	if(adjMatrix.size() > row){
		adjMatrix.erase(adjMatrix.begin() + row);
	}
	return;
}

void deleteColumn(vector<vector<int>> &adjMatrix , int column){
	for(int i =0; i < adjMatrix.size();i++){
		if(adjMatrix[i].size() > column){
			adjMatrix[i].erase(adjMatrix[i].begin() + column);
		}
	}
	return;


}

void contractEdge(vector<vector<int>> &adjMatrix,int v1, int v2){
	for(int index = 0 ; index < adjMatrix.size() ; index++){
		if(index == v1){
			continue;
		}
		else{
			adjMatrix[v1][index] = adjMatrix[v1][index] + adjMatrix[v2][index];
			adjMatrix[index][v1] = adjMatrix[v1][index];
	}
	
	
	}
	deleteRow(adjMatrix,v2);
	deleteColumn(adjMatrix,v2);
	return;
}

int minEdge(vector<vector<int>> &adjMatrix){
	int length = adjMatrix.size();
	int v1;
	int v2;
	while(length>2){
		v1= rand()%length ;
		v2= rand()%length ;
		if(findIfEdge(adjMatrix,v1,v2)==1 && v1 != v2){
			contractEdge(adjMatrix,v1,v2);
			length = adjMatrix.size();
		}
	}
	return(adjMatrix[1][0]);
	}

int main(int argc,char* argv[]){
	int numTimes = 1;
	int result = INT_MAX;
	if(argc > 1){
		numTimes = atoi(argv[1]);
	}
	srand(time(NULL));

	for(int i =0 ; i< numTimes; i++){

		string fileText;
		string vertex;
		int vertices = 200;
		vector< vector<int> > adjMatrix(vertices, vector<int>(vertices));
		ifstream myfile ("week4.txt");

		if(myfile){
			int vert = 0;
			while(getline(myfile,fileText)){
				istringstream ss(fileText);
				int value;

				while(ss >> value){
					adjMatrix[vert][value-1] = 1;

				}
				vert = vert+1;


			}
		}
		else{
			cout << "Check File" << endl;
			return 0;
		}
		//cout << adjMatrix.size() << endl ;
		result = min(minEdge(adjMatrix),result);
	}
	cout << result << endl;

}
