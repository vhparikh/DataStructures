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

  //if the 
  if (n == NULL) {
    return;
  }
  
  space += 10;  
  print(n->getRight(), space);  
  cout<<endl;
  
  for (int i = 10; i < space; i++) {
    cout<<" ";
  }

  cout<<n->getNum()<<"\n";
  print(n->getLeft(), space);
}

void search(Node* n, int val) {

  if (n == NULL) {
    cout << "the tree is empty" << endl;
    return;
  }

  if (n->getNum() == val) {
    cout << "yes the number exists" << endl;
    return ;
  }

  if (n->getNum() > val) {
    if (n->getLeft() != NULL) {
      Node* temp = n->getLeft();
      search(temp, val);
    }
    else {
      cout << "The number isn't on the tree" << endl;
      return;
    }
  }

  if (n->getNum() < val) {
    if (n->getRight() != NULL) {
      Node* temp = n->getRight();
      search(temp, val);
    }
    else {
      cout << "The number isn't on the tree" << endl;
      return;
    }
  }
  
}


void remove(Node* &n, int val, Node* &p, Node* &head) {

  if (n->getNum() == val) {

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

    if (n->getLeft() != NULL) {
      Node* temp = n->getLeft();
      n->setNum(temp->getNum());
      n->setRight(temp->getRight());
      n->setLeft(temp->getLeft());
      delete temp;
      return;
    }

    if (n->getRight() != NULL) {
      Node* temp = n->getRight();
      n->setNum(temp->getNum());
      n->setRight(temp->getRight());
      n->setLeft(temp->getLeft());
      delete temp;
      return;
    }

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

