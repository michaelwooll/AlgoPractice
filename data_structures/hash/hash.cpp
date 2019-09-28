#include<iostream>
#include<list>
#include<vector>
#include <iterator>
#include"hash.h"
#include <map>
using namespace std;

Hash::Hash(){
	hash_table.resize(size);	
}

int Hash::hashKey(string key){
	int val = 0;
	for(int i = 0; i < key.size(); i++){
		val += key[i];
	}

	return val%size;
}

void Hash::insert(string key, int val){
	hash_table[hashKey(key)].push_back(HashItem(key,val));
}

int Hash::getVal(string key){
	list<HashItem> p = hash_table[hashKey(key)];
	list<HashItem>::iterator it = p.begin();
	for(it; it != p.end(); it++){
		if(it->getKey() == key){
			return it->getValue();
		}
	}
	
	// Key value pair not in hash. insert default
	insert(key,0);
	return 0;

}
void Hash::print(){
	for(int i = 0; i < size; i++){
		cout << "index: " << i << ": ";
		list<HashItem> p = hash_table[i];
		list<HashItem>::iterator it = p.begin();
		for(it; it != p.end(); it++){
			cout << "{" <<  it->getKey() << ":" << it->getValue() << "}"<< " "; 
		}
		cout << endl;
	}
}
