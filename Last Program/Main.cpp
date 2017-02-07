// Thomas COnti
//output maze
//intput: binary tree
#include <iostream>
#include "charBinaryTree.h"
using namespace std;

int main()
{
   charBinaryTree tree;
 
   bool Games = false;// for ending the game
   char choice;
   cout << "*************************************"<< endl;
   cout << "Welcome To College FInd your way out " << endl;
   cout << "*************************************"<< endl << endl;
   tree.insertNode('N');// creating the tree
   tree.insertNode('K');
   tree.insertNode('B');
   tree.insertNode('L');
   tree.insertNode('R');
   tree.insertNode('P');
   tree.insertNode('Q');
   tree.insertNode('T');
   tree.insertNode('S');
   tree.insertNode('U');
   tree.insertNode('Z');
   while(Games != true)
   {
		tree.Game();// calling the game
		Games=tree.NewGame();// leaving
   }
	cout << " YOU WIN YOU ARE NOW OUT OF THE MAZE AND INTO THE REAL WORLD" << endl;

   return 0;
}
