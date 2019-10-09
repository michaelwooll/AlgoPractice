#include <iostream>

using namespace std;


template <class T>
class Tnode{
	public:
		T value;
		Tnode *left;
		Tnode *right;
		Tnode(T val): value(val), left(NULL), right(NULL){}
};

template <class T>
class BST{
	public:
		BST(){
			root = NULL;
		}
		bool insert(int value){
			if(root == NULL){
				root = new Tnode<T>(value);
				return true;
			}else
				return insert(root,value);
			return false;
		}

		void print_inorder(){
			print_inorder(root);
			cout << endl;
		}
		void deleteNode(int value){
			if(root != NULL)
				deleteNode(value,root);
		}
		
	
	private:
		Tnode<T> *root;
		bool insert(Tnode<T> *cur, int value);
		void print_inorder(Tnode<T> *cur);
		Tnode<T>* removeLM(Tnode<T> *cur);
		Tnode<T>* deleteNode(int value, Tnode<T> *cur);
		Tnode<T>* findLMN(Tnode<T> *cur);
	
};
