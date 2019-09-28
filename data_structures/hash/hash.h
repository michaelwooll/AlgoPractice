#ifndef HASH_H
#define HASH_H

#include<list>
#include<vector>
#include"hashItem.h"


class Hash{
	private:
		int size = 29; // Prime number 
		vector<list<HashItem>> hash_table;
	public:
		Hash();
		int hashKey(string key);
		int getVal(string key);
		void insert(string key, int val);
		void remove(string key, int val);
		void print();
};




#endif
