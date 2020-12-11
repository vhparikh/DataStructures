//Created by Vatsal Parikh
//Date: 12/1/20
//Uses Shunting yard algorithm to convert infix to postfix
//Creates binary expression tree with postfix
//Can print in infix, prefix or postfix using tree

//imports
#include <iostream>
#include <cstring>
#include "List.h"
#include "Node.h"
#include "Tree.h"

using namespace std;

int main() {

  //prompt user for an infix equation
  cout << "enter an equation in infix form with spaces" << endl;
  List* list = new List();
  char* input = new char[80];
  char* post = new char[80];
  cin.get(input, 80);
  cin.get();

  //goes through input and either pushes to stack or enqueues
  for (int i = 0; i < strlen(input); i++) {
    char val;
    val = input[i];
    
    //if and operator push
    if (val == '+') {
      Node* n = new Node();                                                                                     
      n->setNum(-1);
      n->setPrecedence(2);
      n->setAssociate(1);
      list->push(n, false);
    }
    else if (val == '-') {
      Node* n = new Node();                                                                                                       
      n->setNum(-2);                                                                                                              
      n->setPrecedence(2);                                                                                                        
      n->setAssociate(1);                                                                                                          
      list->push(n, false);
    }
    else if (val == '*') {
      Node* n = new Node();                                                                                                   
      n->setNum(-3);                                                                                                              
      n->setPrecedence(3);                                                                                                       
      n->setAssociate(1);
      list->push(n, false);
    }
    else if (val == '/') {
      Node* n = new Node();                                                                                                        
      n->setNum(-4);                                                                                                               
      n->setPrecedence(3);                                                                                                         
      n->setAssociate(1);                                                                                                          
      list->push(n, false);
    }
    else if (val == '^') {
      Node* n = new Node();                                                                                                       
      n->setNum(-5);                                                                                                              
      n->setPrecedence(4);                                                                                                        
      n->setAssociate(2);                                                                                                         
      list->push(n, false);
    }
    else if (val == '(') {
      Node* n = new Node();                                                                                                       
      n->setNum(-6);                                                                                                              
      list->push(n, false);
    }
    else if (val == ')') {
      Node* n = new Node();                                                                                                        
      n->setNum(-7);                                                                                                               
      list->push(n, false);
    }
    //else if not a space enqueue
    else if (input[i] != ' ') {

      //take string # and convert to int to enter into node
      char num[5];
      int counter = 0;
      while (input[i] != ' ' && i < strlen(input)) {
	num[counter] = input[i];
	i++;
	counter++;
      }
      num[counter] = '\0';
      int data = 0;
      for (int j = 0; j < strlen(num); j++) {
	data *= 10;
	data += num[j] - 48;
      }
      
      Node* n = new Node();
      n->setNum(data);
      list->enqueue(n);
    }
  }

  //print postfix
  list->print();

  Node* n = list->getQueue();
  
  //build the tree with postfix form
  Tree* tree = new Tree(n);
  Node* t = tree->build();

  //ask if user wants infix, postfix or prefix
  cout << "Would you like to convert to infix, postfix or prefix?" << endl;
  cin.get(input, 80);
  cin.get();

  //if user wants infix call infix
  if (strcmp(input, "infix") == 0) {
    cout << "Here is infix form" << endl;
    tree->infix(t);
    cout << endl;
  }

  //else if user wants postfix call postfix
  else if (strcmp(input, "postfix") == 0) {
    cout << "Here is postfix form" << endl;
    tree->postfix(t);
    cout << endl;
  }

  //else if user wants prefix call prefix
  else if (strcmp(input, "prefix") == 0) {
    cout << "Here is prefix form" << endl;
    tree->prefix(t);
    cout << endl;
  }
}
