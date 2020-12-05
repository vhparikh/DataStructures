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
  //cout << "g" << endl;
  return temp;
}

void List::push(Node* n, bool tree) {

  if (n->getCh() == '+' || n->getCh() == '-') {
    n->setPrecedence(2);
    n->setAssociate(1);
    //    cout << "d" << endl;
  }
  else if (n->getCh() == '*' || n->getCh() == '/') {
    n->setPrecedence(3);
    n->setAssociate(1);
  }
  else if (n->getCh() == '^') {
    n->setPrecedence(4);
    n->setAssociate(2);
  }

  if (n->getCh() == ')') {
    while (stackHead->getCh() != '(' && stackHead != NULL) {
      enqueue(pop());
    }

    if (stackHead->getCh() == '(') {
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
	 (stackHead->getCh() != '(') && (tree == false)) {
    //cout << "e" << endl;
    /*    cout << endl;
    cout << stackHead->getCh() << endl;
    cout << stackHead->getPrecedence() << endl;
    cout << endl;
    cout << n->getCh() << endl;
    cout << n->getPrecedence() << endl;
    cout << endl;*/
    enqueue(pop());
    //cout << "f" << endl;
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
    //cout << "h" << endl;
    return;
  }

  Node* current = queueHead;
  //cout << "i" << endl;
  while(current->getNext() != NULL) {
    current = current->getNext();
    //cout << "j" << endl;
  }

  //cout << "k" << endl;
  current->setNext(n);
  //cout << "l" << endl;
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

char* List::print() {
  Node* current = queueHead;
  char* post = new char[80];
  int counter = 0;
  
  //cout << "D" << endl;
  while (current != NULL) {
    cout << current->getCh();
    post[counter] = current->getCh();
    counter++;
    current = current->getNext();
  }

  while (stackHead != NULL) {
    char ch = pop()->getCh();
    cout << ch;
    post[counter] = ch;
    counter++;
  }
  
  //cout << "E" << endl;
  cout << endl;
  return post;
}
