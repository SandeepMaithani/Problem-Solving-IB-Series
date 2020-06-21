#include<bits/stdc++.h>

using namespace std;

//  structure for new BST node

struct bstnode {
	int data;
	bstnode* left;
	bstnode* right;
};

// Function to create new node in heap

bstnode* getnode(int data) {
	bstnode* child = new bstnode();
	child -> data = data;
	child -> left = child -> right = NULL;
	
	return child;		
}

// To insert data in BST, returns address of root node 

bstnode* insert(bstnode* root,int data) {
	
	// when tree is empty
	
	if(root == NULL) {
		root = getnode(data);
	}
	
	// if data to be inserted is lesser, insert in left subtree. 
	
	else if(data <= root -> data) {
		root -> left = insert(root -> left,data);		
	}
	
	// if data to be inserted is greater, insert in right subtree. 
	
	else {
		root -> right = insert(root -> right,data);
	}
	
	return root;
}

// Function to find the Height or Maximum Depth of the tree

int bstheight(bstnode* root) {
	if(root == NULL) {
		return -1;        // since we are adding 1 in our logic so for tree height 0 we dont get wrong answer
	}
	
	// here we are finding the maximum height from left or right subtree recursively we are adding 1 because at any point 
	// we ae ignoring current node finding height of its child subtree so to get final answer we are adding 1 each time.
	
	else {
		return (max(bstheight(root -> left),bstheight(root -> right)) + 1);
	}
}

int main() {
	ios_base::sync_with_stdio (false);
	cin.tie(NULL);
	
	//creating an empty tree
	bstnode* root = NULL;
	
	root = insert(root,20);
	root = insert(root,15);
	root = insert(root,25);
	root = insert(root,23);
	root = insert(root,28);
	root = insert(root,21);
	root = insert(root,24);
	root = insert(root,26);
	root = insert(root,30);
	root = insert(root,10);
	root = insert(root,18);
	root = insert(root,4);
	root = insert(root,8);
	root = insert(root,16);
	root = insert(root,19);
	
	cout<<"\nHeight of the tree is "<<bstheight(root);
	
	return 0;
}
