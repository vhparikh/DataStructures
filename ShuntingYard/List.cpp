//Created by Vatsal Parikh
//Date: 12/1/20
//.cpp file for list class

//imports
#include "List.h"

//constructor
List::List() {
  
  //set both heads to null
  stackHead = NULL;
  queueHead = NULL;
}

//peeks at top node in stack and returns it
Node* List::peek() {
  return stackHead;
}

//pops top node in stack and returns it and fixes the links
Node* List::pop() {
  if (stackHead == NULL) {
    return NULL;
  }
  Node* temp = stackHead;
  stackHead = stackHead->getNext();
  temp->setNext(NULL);
  return temp;
}

//pushes node onto stack
void List::push(Node* n, bool tree) {

  //if it is a + or - give it a precedence value of 2 and associative value of 1
  if (n->getCh() == '+' || n->getCh() == '-') {
    n->setPrecedence(2);
    n->setAssociate(1);
  }

  //else if it is a * or / give it a precedence value of 3 and associative value of 1
  else if (n->getCh() == '*' || n->getCh() == '/') {
    n->setPrecedence(3);
    n->setAssociate(1);
  }

  //else if it is a ^ give it a precedence value of 4 and associative value of 2
  else if (n->getCh() == '^') {
    n->setPrecedence(4);
    n->setAssociate(2);
  }

  //if it is a )
  if (n->getCh() == ')') {

    //loop through stack and keep popping nodes until a ( is found
    while (stackHead->getCh() != '(' && stackHead != NULL) {
      enqueue(pop());
    }

    //if ( is found pop it and delete it and the )
    if (stackHead->getCh() == '(') {
      Node* temp = pop();
      temp->~Node();
      n->~Node();
    }

    //else there was a paranthesis mix up in the input from the user
    else {
      cout << "there is a parenthesis mix up" << endl;
      return;
    }
    
    return;
  }

  //if the current node has lower or equal precedence than the one at top of stack pop the operator and enqueue until the stack is empty or lower precedence node is at top of stack
  while ((stackHead != NULL) && ((stackHead->getPrecedence() > n->getPrecedence()) ||
				 (stackHead->getPrecedence() == n->getPrecedence() && n->getAssociate() == 1)) &&
	 (stackHead->getCh() != '(') && (tree == false)) {
    enqueue(pop());
  }

  //add the node to stack
  n->setNext(stackHead);
  stackHead = n;
}

//removes top node in queue
void List::dequeue() {
  if (queueHead == NULL) {
    return;
  }

  Node* temp = queueHead->getNext();
  queueHead->~Node();
  queueHead = temp;

}

//adds node to the end of the queue
void List::enqueue(Node* n) {

  if (queueHead == NULL) {
    queueHead = n;
    return;
  }

  Node* current = queueHead;
  while(current->getNext() != NULL) {
    current = current->getNext();
  }
  current->setNext(n);
}

//prints out the postfix form and returns a char* with it
char* List::print() {

  //create a node to go through the queue
  Node* current = queueHead;

  //char* to store postfix to return
  char* post = new char[80];
  int counter = 0;

  //while the node isn't null print the value add it to post and go to next node
  while (current != NULL) {
    cout << current->getCh();
    post[counter] = current->getCh();
    counter++;
    current = current->getNext();
  }

  //while the stack isn't empty pop and print the value and add it to post
  while (stackHead != NULL) {
    char ch = pop()->getCh();
    cout << ch;
    post[counter] = ch;
    counter++;
  }
  
  cout << endl;

  //returns post
  return post;
}
