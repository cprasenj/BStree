#include "tree.h"
#include <stdio.h>

Node* createTreeNode (int data) {
	Node *point; 
	point = calloc(sizeof(Node),1);
	point->data = data;
	return point;
} 
BSTree createBSTree(void) {
	BSTree *tree;
	tree = calloc(sizeof(BSTree),1);
	return *tree;
}
int insert(BSTree* tree,int data) {
	BSTree subTree = createBSTree();
	Node *node = createTreeNode(data);
	!tree->root && (tree->root = node);
	if(data < tree->root->data) {
		tree->root->leftChild && (subTree.root = tree->root->leftChild) && insert(&subTree,data);
		!tree->root->leftChild &&(tree->root->leftChild = node);
	}
	if(data > tree->root->data) {
		tree->root->rightChild && (subTree.root = tree->root->rightChild) && insert(&subTree,data);	
		!tree->root->rightChild && (tree->root->rightChild = node);
	}
	tree->count++; 
	return 1;
}

int isLeafNode(Node* node) {
	return !node->leftChild && !node->rightChild ? 1 :0;
}

Node* find(BSTree tree,int data) {
	BSTree subTree = createBSTree();
	if(!tree.root) return NULL;
	if(data == tree.root->data)
		return tree.root;
	tree.root->rightChild && (data > tree.root->data) && (subTree.root = tree.root->rightChild);
	tree.root->leftChild && (data < tree.root->data) && (subTree.root = tree.root->leftChild); 
	return find(subTree,data);
}

Node* delete(BSTree* tree,int data) {
	BSTree subTree = createBSTree();
	Node* node = NULL;
	tree->root->rightChild && tree->root->rightChild->data == data && (node = tree->root->rightChild) && (tree->root->rightChild = NULL);
	tree->root->leftChild && tree->root->leftChild->data == data && (node = tree->root->leftChild) && (tree->root->leftChild = NULL);
	if(!node){
		data < tree->root->data && (subTree.root = tree->root->leftChild) && (node = delete(&subTree,data));
		data > tree->root->data && (subTree.root = tree->root->rightChild) && (node = delete(&subTree,data));		 
	}
	return node; 
} 
