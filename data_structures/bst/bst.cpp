#include"bst.h"
#include <iostream>
#include<time.h>
#include<stdlib.h>
#include<vector>

using namespace std;



template <class T>
bool BST<T>::insert(Tnode<T> *cur, int value){
	if(value < cur->value){
		if(cur->left == NULL){
			cur->left = new Tnode<T>(value);
			return true;
		}
		else{
			insert(cur->left,value);
			return true;
		}
	}
	else if (value > cur->value){
		if(cur->right == NULL){
			cur->right = new Tnode<T>(value);
			return true;
		}
		else{
			insert(cur->right,value);
			return true;
		}
	}
	
	return false;
}

template <class T>
void BST<T>::print_inorder(Tnode<T> *cur){
	if(cur == NULL)
		return;
	print_inorder(cur->left);
	cout << cur->value << " ";
	print_inorder(cur->right);
}

template <class T>
Tnode<T>* BST<T>::removeLM(Tnode<T> *cur){
	if(cur != NULL){
		if(cur->left != NULL){
			cur->left = removeLM(cur->left);
			return cur;
		}
		else{
			if(cur->right != NULL){
				Tnode<T> *temp = cur->right;
				delete cur;
				return temp;
			}
			else{
				delete cur;
				return NULL;
			}
		}
	}

}


template <class T>
Tnode<T>* BST<T>::findLMN(Tnode<T> *cur){
	if(cur != NULL){
		if(cur->left)
			return findLMN(cur->left);
		else{
			return cur;
		}
	}
}

template <class T>
Tnode<T>* BST<T>::deleteNode(int value, Tnode<T> *cur){
	if(cur == NULL)
		return NULL;
	if(value < cur->value){
		cur->left = deleteNode(value,cur->left);
	}
	else if (value > cur->value){
		cur->right = deleteNode(value,cur->right);
	}
	else{ // found node to delete
		// leaf node case
		if(cur->right == NULL && cur->left == NULL){
			delete cur;
			return NULL;
		}
		// one child case
		else if(cur->right && cur->left == NULL){	
			Tnode<T> *temp = cur->right;
			delete cur;
			return temp;
		}
		else if(cur->left && cur->right == NULL){
			Tnode<T> *temp = cur->left;
			delete cur;
			return temp;
		}
		else{ // two children case
			Tnode<T> *temp = findLMN(cur->right);// find left most node of subtree rooted at right child		
			cur->value = temp->value;
			cur->right = removeLM(cur->right);
			return cur;
		}
	}
}



int main(){
	BST<int> tree;
	int value;
	vector<int> inserted;
	srand(time(NULL));
	for(int i = 0; i < 20; i++){
		value = rand() % 100 + i;
		if(tree.insert(value)){
			inserted.push_back(value);
		}
	}
	cout << "Inserted: " << inserted.size() << " random values!" << endl << endl;
	tree.print_inorder();

	cout << endl << endl <<"Deleting " << inserted.size()/2 << " random values!" << endl;

	for(int i = 0; i < inserted.size()/2; i++){
		int index = rand() % inserted.size()/2;
		tree.deleteNode(inserted[index]);
		inserted.erase(inserted.begin() + index);
	}
	cout << "Deleting finished!" << endl;
	tree.print_inorder();
	cout << endl;
	return 0;
}


