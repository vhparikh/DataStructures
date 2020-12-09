#include <iostream>
#include <cstring>
#include <fstream> 
#include "Node.h"

using namespace std;

void add(Node* &n, int val);
void print(Node* n, int space);
void search(Node* n, int val);
void remove(Node* &n, int val);

int main() {

  char input[80];
  int data;
  Node* head = NULL;
  bool quit = false;

  cout << "Welcome to Binary Search Tree" << endl;
  
  while (!quit) {
    cin.get(input, 80);
    cin.get();

    if (strcmp(input, "add") == 0) {
      cout << "Enter the number you would like to add" << endl;
      cin >> data;
      cin.get();
      add(head, data);
    }
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
    else if (strcmp(input, "search") == 0) {
      cout << "Enter the number you would like to search for" << endl;
      cin >> data;
      cin.get();
      search(head, data);
    }
    else if (strcmp(input, "remove") == 0) {
      cout << "Enter the number you would like to remove" << endl;
      cin >> data;
      cin.get();
      remove(head, data);
    }
    else if (strcmp(input, "print") == 0) {
      print(head, 0);
    }
    else if (strcmp(input, "quit") == 0) {
      quit = true;
    }
    else {
      cout << "invalid command" << endl;
    }
    
  }
  
}

void add(Node* &n, int val) {
  if (n == NULL) {
    n = new Node();
    n->setNum(val);
    return;
  }

  if (n->getNum() > val) {
    if (n->getLeft() == NULL) {
      Node* temp = new Node();
      temp->setNum(val);
      n->setLeft(temp);
    }
    else {
      Node* temp = n->getLeft();
      add(temp, val);
    }
  }

  if (n->getNum() < val) {
    if (n->getRight() == NULL) {
      Node* temp = new Node();
      temp->setNum(val);
      n->setRight(temp);
    }
    else {
      Node* temp = n->getRight();
      add(temp, val);
    }
  }
  
}

void print(Node* n, int space) {

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
    return;
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

void remove(Node* &n, int val) {
}

/*
void remove(Node* &n, int val) {

  if (n->getNum() == val) {
    if (n->getLeft() != NULL && n->getRight() != NULL) {
      Node* temp = n->getLeft();
      Node* prev = n;
      int counter = 0;
      while (temp->getRight() != NULL) {
	if (counter >= 1) {
	  temp = temp->getRight();
	  prev = prev->getRight();
	}
	else {
	  temp = temp->getRight();
	  prev = prev->getLeft();
	}
	counter++;
      }

      if (temp->getLeft() != NULL) {
	Node* placeholder = temp->getLeft();
	n->setNum(temp->getNum());
	//prev->setNum(placeholder->getNum());
	//prev->setLeft(placeholder->getLeft());
	prev->setRight(placeholder);
	delete placeholder;
	delete temp;
	temp = NULL;
	placeholder = NULL;
      }
      else {
	n->setNum(temp->getNum());
	delete temp;
	temp = NULL;
	if (prev != n) {
	  prev->setRight(temp);
	}
      }
      
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
      //delete n;
      //n = NULL;
      return;
    }
    
  }
  
  if (n->getNum() > val) {
    if (n->getLeft() != NULL) {
      Node* temp = n->getLeft();
      remove(temp, val);
    }
    else {
      cout << "This value is not in the tree" << endl;
      return;
    }
  }

  if (n->getNum() < val) {
    if (n->getRight() != NULL) {
      Node* temp = n->getRight();
      remove(temp, val);
    }
    else {
      cout << "This value is not in the tree" << endl;                                                            
      return;
    }
  }
  
}
*/
