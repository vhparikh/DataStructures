//Created by Vatsal Parikh
//Date: 12/9/20
//Creates a binary tree
//print function logic is from geekforgeeks 

//imports
#include <iostream>
#include <cstring>
#include <fstream> 
#include "Node.h"

using namespace std;

//prototypes
void add(Node* &n, int val);
void print(Node* n, int space);
void search(Node* n, int val);
void remove(Node* &n, int val, Node* &p, Node* &head);

int main() {

  char input[80]; //stores user commands
  int data; //stores value user wants to add
  Node* head = NULL; //head node of tree
  bool quit = false;

  cout << "Welcome to Binary Search Tree" << endl;

  //while user hasn't typed quit
  while (!quit) {

    //gets users command
    cin.get(input, 80);
    cin.get();

    //if user wants to add ask for number then call add
    if (strcmp(input, "add") == 0) {
      cout << "Enter the number you would like to add" << endl;
      cin >> data;
      cin.get();
      add(head, data);
    }

    //else if user wants to use file input get file path get each value in file and call add on it
    else if (strcmp(input, "file") == 0) {
      cout << "Enter the file path" << endl;
      cin.get(input, 80);
      cin.get();
      ifstream file;
      file.open(input);

      while (file >> data) {
	add(head, data);
      }
      file.close();
    }

    //else if user wants to search ask for value and call search on it
    else if (strcmp(input, "search") == 0) {
      cout << "Enter the number you would like to search for" << endl;
      cin >> data;
      cin.get();
      search(head, data);
    }

    //else if user wants to remove ask for value check if tree isn't empty then call remove on it
    else if (strcmp(input, "remove") == 0) {
      cout << "Enter the number you would like to remove" << endl;
      cin >> data;
      cin.get();
      if (head != NULL) {	
	remove(head, data, head, head);
      }
      else {
	cout << "The tree is empty there is nothing to delete" << endl;
      }
    }

    //else if user wants to print call print
    else if (strcmp(input, "print") == 0) {
      cout << endl;
      print(head, 0);
      cout << endl;
    }

    //else if user wants to quit set quit to true
    else if (strcmp(input, "quit") == 0) {
      quit = true;
    }

    //else user typed an invalid command
    else {
      cout << "invalid command" << endl;
    }
    
  }
  
}

//adds value into the tree
void add(Node* &n, int val) {

  //if the head node is null make the value the head node
  if (n == NULL) {
    n = new Node();
    n->setNum(val);
    return;
  }

  //if the value is less than the current nodes value
  if (n->getNum() > val) {

    //if the current nodes left is empty add the node there
    if (n->getLeft() == NULL) {
      Node* temp = new Node();
      temp->setNum(val);
      n->setLeft(temp);
    }

    //else call add on the left node
    else {
      Node* temp = n->getLeft();
      add(temp, val);
    }
  }

  //if the value is more than the current nodes value
  if (n->getNum() <= val) {

    //if the current nodes right is empty add the node there
    if (n->getRight() == NULL) {
      Node* temp = new Node();
      temp->setNum(val);
      n->setRight(temp);
    }

    //else call add on the right node
    else {
      Node* temp = n->getRight();
      add(temp, val);
    }
  }
  
}

//prints out the tree sideways
void print(Node* n, int space) {

  //if the node is null we end the print
  if (n == NULL) {
    return;
  }

  //add 10 spaces for printing
  space += 10;

  //print right subtree
  print(n->getRight(), space);  
  cout << endl;

  //print spaces until space limit is met
  for (int i = 10; i < space; i++) {
    cout<<" ";
  }

  //print number
  cout<<n->getNum()<<"\n";

  //print right subtree
  print(n->getLeft(), space);
}

//searches for a value in the tree
void search(Node* n, int val) {

  //the head node is null the tree is empty
  if (n == NULL) {
    cout << "the tree is empty" << endl;
    return;
  }

  //if the number of node matches val the node has been found
  if (n->getNum() == val) {
    cout << "yes the number exists" << endl;
    return ;
  }

  //if value is less than node value check left tree
  if (n->getNum() > val) {
    if (n->getLeft() != NULL) {
      Node* temp = n->getLeft();
      search(temp, val);
    }

    //if left tree was empty return
    else {
      cout << "The number isn't on the tree" << endl;
      return;
    }
  }

  //if value is more than node value check right tree
  if (n->getNum() < val) {
    if (n->getRight() != NULL) {
      Node* temp = n->getRight();
      search(temp, val);
    }

    //if right tree was empty return
    else {
      cout << "The number isn't on the tree" << endl;
      return;
    }
  }
  
}

//removes values from tree n is current node, val is value to delete, p is previous node, head is head node of tree
void remove(Node* &n, int val, Node* &p, Node* &head) {

  //if the value is found
  if (n->getNum() == val) {

    //if node has two children we will find the next largest node in tree
    if (n->getLeft() != NULL && n->getRight() != NULL) {
      Node* temp = n->getLeft();
      Node* prev = n;
      int counter = 0;
      int nval;
      while (temp->getRight() != NULL) {
	if (counter >= 1) {
	  temp = temp->getRight();
	  prev = prev->getRight();
	}
	else {
	  temp = temp->getRight();
	  prev = n->getLeft();
	}
	counter++;
      }

      nval = temp->getNum();

      //delete the next largest node as its values will be put into a new node
      remove(temp, temp->getNum(), prev, head);
      Node* replace = new Node();
      replace->setNum(nval);
      replace->setRight(n->getRight());
      replace->setLeft(n->getLeft());
      
      if (p->getNum() > val) {
	p->setLeft(replace);
      }
      else {
	p->setRight(replace);
      }

      //if we are deleting the head node delete head and set it to the new node we made
      if (n == head) {
	delete n;
	n = NULL;
	n = replace;
	return;
      }
      
      delete n;
      n = NULL;
      return;
    }

    //if there is only a left child
    if (n->getLeft() != NULL) {

      //set n to everything temp has and then delete temp
      Node* temp = n->getLeft();
      n->setNum(temp->getNum());
      n->setRight(temp->getRight());
      n->setLeft(temp->getLeft());
      delete temp;
      return;
    }

    //if there is only a right child
    if (n->getRight() != NULL) {

      //set n to everything temp has and then delete temp
      Node* temp = n->getRight();
      n->setNum(temp->getNum());
      n->setRight(temp->getRight());
      n->setLeft(temp->getLeft());
      delete temp;
      return;
    }

    //if there are no children deletion is dependent on what side number is of previous node
    if (n->getLeft() == NULL && n->getRight() == NULL) {
      
      if (p->getNum() > n->getNum()) {
	delete n;
	n = NULL;
	p->setLeft(n);
      }
      else if (p->getNum() < n->getNum()) {
	delete n;
	n = NULL;
	p->setRight(n);
      }
      else {
	delete p;
	p = NULL;
      }
      return;
    }
    
  }

  //if val is less than current node value traverse to left subtree if not null
  if (n->getNum() > val) {
    if (n->getLeft() != NULL) {
      Node* temp = n->getLeft();
      remove(temp, val, n, head);
    }
    else {
      cout << "This value is not in the tree" << endl;
      return;
    }
  }

  //if val is more than current node value traverse to right subtree if not null
  if (n->getNum() < val) {
    if (n->getRight() != NULL) {
      Node* temp = n->getRight();
      remove(temp, val, n, head);
    }
    else {
      cout << "This value is not in the tree" << endl;                                                            
      return;
    }
  }
  
}

