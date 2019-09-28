#include<iostream>
#include<vector>
#include <string>
#include <fstream>
#include<time.h>
#include<stdlib.h>
#include"hash.h"

using namespace std;


int main(){
	srand(time(NULL));
	ifstream f;
	f.open("words.txt"); // holds random words for keys
    string key;
	Hash t;


	while(getline(f,key)){
		t.insert(key,rand()%1000);	
	}
	t.print();
    return 0;

}

