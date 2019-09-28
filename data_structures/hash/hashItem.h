#ifndef HASH_ITEM
#define HASH_ITEM

#include<string>
using namespace std;


class HashItem{

	private:
		string key;
		int value;

	public:
		HashItem(string key, int value){
			this->key = key;
			this->value = value;
		}
		int getValue() {return value;}
		string getKey(){return key;}
		void update(int k) {key = k;}
};



#endif
