// Specification file for the charBinaryTree class
//Note all in one file




#ifndef CHARBINARYTREE_H
#define CHARBINARYTREE_H

#include <iostream>
using namespace std;

class charBinaryTree
{
private:
   struct TreeNode
   {
      char value;         // The value in the node
      TreeNode *left;    // Pointer to left child node
      TreeNode *right;   // Pointer to right child node
   };
   TreeNode *root;       // Pointer to the root node
   int count;// countung trys
   
   // Private member functions
   void insert(TreeNode *&, TreeNode *&);
   void destroySubTree(TreeNode *);
   void deleteNode(char, TreeNode *&);
   void makeDeletion(TreeNode *&);
   void displayInOrder(TreeNode *) const;
   void displayPreOrder(TreeNode *) const;
   void displayPostOrder(TreeNode *) const;
   void MoveLeft(TreeNode *);// moving left
   void MoveRight(TreeNode *);// moveing right
   void Game(TreeNode *);// the game
   void loop(TreeNode *);// the loop
   bool Check(TreeNode *);
   
public:
	bool Games;// for while loops
   // Constructor
   charBinaryTree()
      { root = NULL;// calling fuctions
		count =0;
		Games = false;}
     TreeNode *Tempy;
   // Destructor
   ~charBinaryTree()
      { destroySubTree(root); }
    
   // Binary tree operations
   void insertNode(char);
   bool searchNode(char);
   void remove(char);
   bool NewGame()// for leaving the game
   { Games=true;
	return true;}
   void Game()// game time
   { Game(root);}
  
   void displayInOrder() const
      {  displayInOrder(root); }
      
   void displayPreOrder() const
      {  displayPreOrder(root); }
      
   void displayPostOrder() const
      {  displayPostOrder(root); }
};
#endif



// Implementation file for the IntBinaryTree class
#include <iostream>
//#include "charBinaryTree.h"
using namespace std;

//*************************************************************
// insert accepts a TreeNode pointer and a pointer to a node. *
// The function inserts the node into the tree pointed to by  *
// the TreeNode pointer. This function is called recursively. *
//*************************************************************

void charBinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
   if (nodePtr == NULL)
      nodePtr = newNode;                  // Insert the node.
   else if (newNode->value < nodePtr->value)
      insert(nodePtr->left, newNode);     // Search the left branch
   else 
      insert(nodePtr->right, newNode);    // Search the right branch
}

//**********************************************************
// insertNode creates a new node to hold num as its value, *
// and passes it to the insert function.                   *
//**********************************************************

void charBinaryTree::insertNode(char c)
{
   TreeNode *newNode;      // Pointer to a new node.

   // Create a new node and store num in it.
   newNode = new TreeNode;
   newNode->value = c;
   newNode->left = newNode->right = NULL;
   
   // Insert the node.
   insert(root, newNode);
}

//***************************************************
// destroySubTree is called by the destructor. It   *
// deletes all nodes in the tree.                   *
//***************************************************

void charBinaryTree::destroySubTree(TreeNode *nodePtr)
{
   if (nodePtr)
   {
      if (nodePtr->left)
         destroySubTree(nodePtr->left);
      if (nodePtr->right)
         destroySubTree(nodePtr->right);
      delete nodePtr;
   }
}
   
//***************************************************
// searchNode determines if a value is present in   *
// the tree. If so, the function returns true.      *
// Otherwise, it returns false.                     *
//***************************************************

bool charBinaryTree::searchNode(char c)
{
   TreeNode *nodePtr = root;

   while (nodePtr)
   {
      if (nodePtr->value == c)
         return true;
      else if (c < nodePtr->value)
         nodePtr = nodePtr->left;
      else
         nodePtr = nodePtr->right;
   }
   return false;
}

//**********************************************
// remove calls deleteNode to delete the       *
// node whose value member is the same as num. *
//**********************************************

void charBinaryTree::remove(char c)
{
   deleteNode(c, root);
}


//********************************************
// deleteNode deletes the node whose value   *
// member is the same as num.                *
//********************************************

void charBinaryTree::deleteNode(char c, TreeNode *&nodePtr)
{
   if (c < nodePtr->value)
      deleteNode(c, nodePtr->left);
   else if (c > nodePtr->value)
      deleteNode(c, nodePtr->right);
   else
      makeDeletion(nodePtr);
}


//***********************************************************
// makeDeletion takes a reference to a pointer to the node  *
// that is to be deleted. The node is removed and the       *
// branches of the tree below the node are reattached.      *
//***********************************************************

void charBinaryTree::makeDeletion(TreeNode *&nodePtr)
{
   // Define a temporary pointer to use in reattaching
   // the left subtree.
   TreeNode *tempNodePtr;

   if (nodePtr == NULL)
      cout << "Cannot delete empty node.\n";
   else if (nodePtr->right == NULL)
   {
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->left;   // Reattach the left child
      delete tempNodePtr;
   }
   else if (nodePtr->left == NULL)
   {
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->right;  // Reattach the right child
      delete tempNodePtr;
   }
   // If the node has two children.
   else
   {
      // Move one node the right.
      tempNodePtr = nodePtr->right;
      // Go to the end left node.
      while (tempNodePtr->left)
         tempNodePtr = tempNodePtr->left;
      // Reattach the left subtree.
      tempNodePtr->left = nodePtr->left;
      tempNodePtr = nodePtr;
      // Reattach the right subtree.
      nodePtr = nodePtr->right;
      delete tempNodePtr;
   }
}

//****************************************************************
// The displayInOrder member function displays the values        *
// in the subtree pointed to by nodePtr, via inorder traversal.  *
//****************************************************************

void charBinaryTree::displayInOrder(TreeNode *nodePtr) const
{
   if (nodePtr)
   {
      displayInOrder(nodePtr->left);
      cout << nodePtr->value << endl;
      displayInOrder(nodePtr->right);
   }
}

//****************************************************************
// The displayPreOrder member function displays the values       *
// in the subtree pointed to by nodePtr, via preorder traversal. *
//****************************************************************

void charBinaryTree::displayPreOrder(TreeNode *nodePtr) const
{
   if (nodePtr)
   {
      cout << nodePtr->value << endl;
      displayPreOrder(nodePtr->left);     
      displayPreOrder(nodePtr->right);
   }
}

//****************************************************************
// The displayPostOrder member function displays the values      *
// in the subtree pointed to by nodePtr, via postorder traversal.*
//****************************************************************

void charBinaryTree::displayPostOrder(TreeNode *nodePtr) const
{
   if (nodePtr)
   {
      displayPostOrder(nodePtr->left);    
      displayPostOrder(nodePtr->right);
      cout << nodePtr->value << endl;
   }
}
void charBinaryTree::Game(TreeNode * nodePtr)
{
	bool Play = false;
	while(Play != true)
	{
		loop(nodePtr);
		Play=NewGame();
	}
}
void charBinaryTree::MoveLeft(TreeNode * nodePtr)
{
	TreeNode * Temp;
	if(nodePtr->left !=NULL)//  moving left and checking for dead end
	{
		Temp=nodePtr->left;
		cout << Temp->value << endl;
		loop(Temp);
	}
	else
	{
		count++;
		cout << "You have hit a dead end, Please Play Again" << endl;
		cout << "Times Played: " << count << endl;
		Game();
	}
	
}
void charBinaryTree :: loop(TreeNode *nodePtr)
{
	
	char B;
	while(Games != true)// chosing the path
	{
	
		cout << " Do you want to go Left(L) or Right(R)" << endl;
		cout << "If you want to Quit college press Q" << endl;
		cin >> B;
		if(B=='L')// decinging on the path
		{
			MoveLeft(nodePtr);
		}
		if(B== 'R')
		{
			MoveRight(nodePtr);
		}
		if(B=='Q')
		{
			NewGame();
		}
	}
}

void charBinaryTree::MoveRight(TreeNode * nodePtr)
{
	TreeNode * Temp;
	if(nodePtr->right !=NULL)// checking for dead end
	{
		Temp=nodePtr->right;// moving right and checking for a win
		cout << Temp->value << endl;
		if(Temp->value=='Z')
		{
			NewGame();
		}
		loop(Temp);
	}
	else
	{// in case of dead end
		count++;
		cout << "You have hit a dead end, Please Play Again" << endl;
		cout << "Times Played: " << count << endl;
		Game();
	}
	
}
