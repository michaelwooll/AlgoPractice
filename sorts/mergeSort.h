#include<vector>
using namespace std;

/*
* Merges two subarray of V
* First subarray is V[beg ... mid]
* Second subarray is V[mid+1 ... end]
*/ 
void merge(vector<int> &V, int beg, int mid, int end);
void mergeSort(vector<int> &V, int beg, int end);
