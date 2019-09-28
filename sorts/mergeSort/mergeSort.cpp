#include<iostream>
#include<vector>
#include "mergeSort.h"

using namespace std;

/*
* Merges two subarray of V
* First subarray is V[beg ... mid]
* Second subarray is V[mid+1 ... end]
*/ 
void merge(vector<int> &V, int beg, int mid, int end){
	// Create subarrays
	vector<int> left;
	vector<int> right;

	// Copy elements into temp arrays
	for(int i = beg; i <= mid; i++){
		left.push_back(V[i]);
	}

	for(int i = mid + 1; i <= end; i++){
		right.push_back(V[i]);
	}
	int l = 0; // Index for left array
	int r = 0; // Index for right array
	int k = beg; // Index for v

	/* Loops through until atleast 1 of the subarrays reaches the end*/
	while(l < int(left.size()) && r < int(right.size())){
		if(left[l] <= right[r]){
			V[k] = left[l++];
		}
		else{
			V[k] = right[r++];
		}
		k++;
	}
	
	/* In the case that the left array still had elements left over
	 copy them into v */
	while(l < int(left.size())){
		V[k++] = left[l++];
	}
	
	
	/* In the case that the left array still had elements left over
	 copy them into v */
	while(r < int(right.size())){
		V[k++] = right[r++];
	}

}

void mergeSort(vector<int> &V, int beg, int end){
	if(beg == end) return;
	
	int mid = (beg+end)/2;
	mergeSort(V,beg,mid);
	mergeSort(V, mid+1,end);
	merge(V,beg,mid,end);
}
