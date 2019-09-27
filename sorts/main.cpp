#include<iostream>
#include<vector>
#include<stdlib.h> // for rand function
#include<time.h> // For time function
#include<algorithm> // For sort function
#include "mergeSort.h"

using namespace std;



void compare(vector<int> A, vector<int> B);
void print(vector<int> A);

int main(){
	// Make a random vector
	srand(time(NULL));	

	vector<int> A; // Uses my sort algo
	vector<int> B; // Uses C++ sort
	int size = rand()%200;
	for(int i = 0; i < size; i++){
		int x = rand()%300;
		A.push_back(x);
		B.push_back(x);
	}
	mergeSort(A, 0, A.size()-1);
	sort(B.begin(), B.end());
	print(A);
	cout << endl << endl;
	print(B);
	compare(A,B);
	return 0;
}



void compare(vector<int> A, vector<int> B){
	int i = 0;
	int size = A.size();
	while( i < size){
		if(A[i] != B[i]){
			cout << endl << "Failed at index: " << i << endl;	
			return;
		}
		i++;	
	}
	cout << "Passed." << endl;
	return;
}

void print(vector<int> A){
	for(int i = 0; i < int(A.size()); i++){
		cout << A[i] << " ";
	}
	cout << endl;
	return;
}
