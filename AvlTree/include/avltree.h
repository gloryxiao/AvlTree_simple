/* this is a avltree declearation
 * */

#ifndef __AVL_TREE_H__
#define __AVL_TREE_H__

#include <iostream>
#include <iomanip>
struct AvlTreeNode {
	int key;
	int height;
	struct AvlTreeNode *left;
	AvlTreeNode *right;
	
	AvlTreeNode(int value, AvlTreeNode* pl, AvlTreeNode* pr, int h=0):key(value), height(h),left(pl),right(pr){}
};

class AvlTree{
	private:
		AvlTreeNode *root;

	public:
		AvlTree();
		AvlTree(const AvlTree& rhs);
		~AvlTree();

		int max(int a, int b){return a > b ? a : b;}
		bool isLessThan(int a, int b)const{return a < b ? true : false;}

		int height()const; //获取树的高度
		
		void insert(const int& key);
		void remove(const int &key);
		void destroy();
		void print()const;
	
	private:
	
		int height(AvlTreeNode * node)const;
		bool find(AvlTreeNode* node, const int& key);
		
		AvlTreeNode* findMin(AvlTreeNode* node)const;
		AvlTreeNode* findMax(AvlTreeNode* node)const;
		
		void insert(AvlTreeNode* &node, const int& key);
		void remove(AvlTreeNode* &node, const int& key);
		
		void destroy(AvlTreeNode* &node);
		
		void rotateWithLeftChild(AvlTreeNode* &k);
		void rotateWithRightChild(AvlTreeNode* &k);
		
		void doubleWithLeftChild(AvlTreeNode*& k);
		void doubleWithRightChild(AvlTreeNode*& k);
		
		AvlTreeNode* clone(const AvlTreeNode * root);
		
		void print(AvlTreeNode* node, int key, int direction)const;
				
};

#endif
