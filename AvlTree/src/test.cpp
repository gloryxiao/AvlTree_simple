/*
 *this is a test file to test the avltree made by myself
 * */

#include <iostream>
#include "avltree.h"

using namespace std;

int main(){
	AvlTree atree;
	atree.insert(1);
	int key = 2;
	atree.insert(key);
	for (; key < 10; key ++)
		atree.insert(key);


	cout<<"the avl tree is build!"<<endl;
}
