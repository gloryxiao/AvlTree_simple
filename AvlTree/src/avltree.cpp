
/*this is a file to complete the avltree declaration;
 * and this is the cpp file
 * */

#ifndef __AVL_TREE_CPP__
#define __AVL_TREE_CPP__

#include "avltree.h"
using namespace std;

AvlTree::AvlTree(){
	root = NULL;
}

AvlTree::AvlTree(const AvlTree& rhs){
	root = clone(rhs.root);
}

AvlTreeNode* AvlTree::clone(const AvlTreeNode* root){
	//todo deepcopy a tree
	//return root;
}


AvlTree::~AvlTree(){
	destroy();
}

int AvlTree::height()const{
	return height(root);
} 

void AvlTree::destroy(){
	destroy(root);	
}

void AvlTree::destroy(AvlTreeNode* &node){
	if(node == NULL)
		return;
	destroy(node->left);
	destroy(node->right);
	delete node;
	node = NULL; 
}

int AvlTree::height(AvlTreeNode* node)const{
	return NULL==node ? -1 : node->height;
}

void AvlTree::rotateWithLeftChild(AvlTreeNode* &k){
	AvlTreeNode* k1 = k, *k2 = k->left;
	k1->left = k2->right;
	k2->right = k1;

	k1->height = max(height(k1->left), height(k1->right)) + 1;
	k2->height = max(height(k2->left), k1->height) + 1;

	k = k2;
}

void AvlTree::rotateWithRightChild(AvlTreeNode* &k){
	AvlTreeNode* k1 = k->right;
	k->right = k1->left;
	k1->left = k;

	k->height = max(height(k->left), height(k->right)) + 1;
	k1->height = max(k->height, height(k1->left)) + 1;

	k = k1;
}

void AvlTree::doubleWithLeftChild(AvlTreeNode* &k){
	rotateWithRightChild(k->left);
	rotateWithLeftChild(k);
}

void AvlTree::doubleWithRightChild(AvlTreeNode* &k){
	rotateWithLeftChild(k->right);
	rotateWithRightChild(k);
}

void AvlTree::insert(const int &key){
	insert(root, key);
}

void AvlTree::insert(AvlTreeNode* &node, const int &key){
	if (NULL == node){
		node = new AvlTreeNode(key, NULL, NULL, 0);
	}
	if (isLessThan(key, node->key)){
		insert(node->left, key);
		if (2 == node->left->height - node->right->height){
			if (isLessThan(key, node->left->key))
				rotateWithLeftChild(node);
			else
				doubleWithLeftChild(node);
		}
	}
	else if(isLessThan(node->key, key)){
		insert(node->right, key);
		if (2 == height(node->right) - height(node->left)){
			if (isLessThan(node->right->key, key))
				rotateWithRightChild(node);
			else
				doubleWithRightChild(node);

		}
	}
	else
		; //多余的不可能出现的情况
	node->height = max(height(node->left), height(node->right)) + 1;
}

void AvlTree::remove(const int& key){
	remove(root, key);
}

void AvlTree::remove(AvlTreeNode* &node, const int &key){
	// 未找到返回
	if (NULL == node) return;
	/*如果值比节点数值小，在左子树中删除*/
	if (isLessThan(key, node->key)){
		remove(node->left, key);
		if (2 == node->right->height - node->left->height){
			AvlTreeNode* k = node->right;
			if (isLessThan(height(k->right), height(k->left)))
				doubleWithRightChild(node);
			else
				rotateWithRightChild(node);
		}
	}
	else if (isLessThan(node->key, key)){
		remove(node->right, key);
		if (2 == height(node->left) - height(node->right)){
			AvlTreeNode* k = node->left;
			if (isLessThan(height(k->left), height(k->right)))
				doubleWithLeftChild(node);
			else
				rotateWithLeftChild(node);
		}	
	}
	else{
		/*找到节点删除*/
		if (NULL != node->left && NULL != node->right){
			// 删除节点有两个子树
			if (isLessThan(height(node->left), height(node->right))){
				AvlTreeNode* right_min = findMin(node->right);
				node->key = right_min->key;
				remove(node, right_min->key);
			}
			else{
				AvlTreeNode* left_max = findMax(node->left);
				node->key = left_max->key;
				remove(node, left_max->key);
			}
		}	
		else{
			// 删除节点有一个或者没有子树
			AvlTreeNode* child = (NULL == node->left) ? node->right : node->left;
			delete node;
			node = child;
		}
	}
	
}

AvlTreeNode* AvlTree::findMin(AvlTreeNode* node)const{
	if (NULL == node) return NULL;
	while(NULL != node->left)
		node = node->left;
	return node;
}

AvlTreeNode* AvlTree::findMax(AvlTreeNode* node)const{
	if (NULL == node) return NULL;
	while(NULL != node->right)
		node = node->right;
	return node;
}

void AvlTree::print()const{
	if(NULL != root)
		print(root, root->key, 0);
	
}

void AvlTree::print(AvlTreeNode* node, int key, int direction)const{
	if(NULL != node){
		if(0 == direction)
			cout<<setw(2)<<node->key<<" is root "<<endl;
		else{
			cout<<setw(2)<<node->key<<"is "<<setw(2)<<key<<" 's"<<setw(2)<<(direction == 1 ? "right child" : "left child")<<endl;

		}
		print(node->left, node->key, -1);
		print(node->right, node->key, 1);
	}
}

#endif
