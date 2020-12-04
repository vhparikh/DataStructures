#include "List.h"

List::List() {
  stackHead = NULL;
  queueHead = NULL;
}

Node* List::peek() {
  return stackHead;
}

Node* List::pop() {
  if (stackHead == NULL) {
    return NULL;
  }
  Node* temp = stackHead;
  stackHead = stackHead->getNext();
  temp->setNext(NULL);
  return temp;
}

void List::push(Node* n) {

  if (strcmp(n->getCh(), "+") == 0 || strcmp(n->getCh(), "-") == 0) {
    n->setPrecedence(2);
    n->setAssociate(1);
  }
  else if (strcmp(n->getCh(), "*") == 0 || strcmp(n->getCh(), "/") == 0) {
    n->setPrecedence(3);
    n->setAssociate(1);
  }
  else if (strcmp(n->getCh(), "^") == 0) {
    n->setPrecedence(4);
    n->setAssociate(2);
  }

  if (strcmp(n->getCh(), ")") == 0) {
    while (strcmp(stackHead->getCh(), "(") != 0 && stackHead != NULL) {
      enqueue(pop());
    }

    if (strcmp(stackHead->getCh(), "(") == 0) {
      Node* temp = pop();
      temp->~Node();
      n->~Node();
    }
    else {
      cout << "there is a parenthesis mix up" << endl;
      return;
    }
    
    return;
  }

  /*if (stackHead == NULL) {
    stackHead = n;
    cout << "empty" << endl;
    return;
    }*/
  
  while ((stackHead != NULL) && ((stackHead->getPrecedence() > n->getPrecedence()) ||
				 (stackHead->getPrecedence() == n->getPrecedence() && n->getAssociate() == 1)) &&
	 (strcmp(stackHead->getCh(), "(") != 0)) {
    //cout << "jumped in" << endl;
    //cout << stackHead->getPrecedence() << endl;
    enqueue(pop());
    //cout << "popped" << endl;
  }
  n->setNext(stackHead);
  stackHead = n;
  //cout << "done" << endl;
}

void List::dequeue() {
  if (queueHead == NULL) {
    return;
  }

  Node* temp = queueHead->getNext();
  queueHead->~Node();
  queueHead = temp;

}

void List::enqueue(Node* n) {

  if (queueHead == NULL) {
    queueHead = n;
    return;
  }

  Node* current = queueHead;
  while(queueHead->getNext() != NULL) {
    current = current->getNext();
  }

  current->setNext(n);
}

//for debug
void List::printStack() {
  Node* current = stackHead;
  //  cout << current->getNext()->getCh() << endl;
  while (current != NULL) {
    cout << current->getCh() << endl;
    current = current->getNext();
    //cout << "next" << endl;
  }

  /*if (stackHead->getNext() == NULL) {
    cout << "uh oh" << endl;
    cout << stackHead->getPrecedence() << endl;
  }
  
  cout << stackHead->getNext()->getCh() << endl;*/
  
}

void List::print() {
  Node* current = queueHead;
  cout << "D" << endl;
  while (current != NULL) {
    cout << current->getCh();
    current = current->getNext();
  }
  cout << "E" << endl;
  cout << endl;
}
