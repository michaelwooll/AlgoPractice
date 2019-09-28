#include<vector>
#include"quickSort.h"


using namespace std;
// Will put V[index] into sorted index in V.
int partition(vector<int> &V, int low, int high, int index){
	int temp = V[high];
	V[high] = V[index];
	V[index] = temp;

	int pivot = V[high];

	int i = low;
	int j = high - 1;

	while(i <= j){
		while(i < high && V[i] <= pivot){
			i++;
		}
		while(j >= low && V[j] > pivot){
			j--;
		}
		if(i<j){
			int temp = V[i];
			V[i] = V[j];
			V[j] = temp;
			i++;
			j--;
		} // end if
	} // end while
	
	V[high] = V[i];
	V[i] = pivot;
	return i;
}

void quickSort(vector<int> &V, int low, int high){
	if (low < high){
		int pivotIndex = partition(V,low,high,high);
		quickSort(V,low,pivotIndex-1);
		quickSort(V,pivotIndex+1, high);
	}
}
