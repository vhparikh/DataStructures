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
  while (stackHead != NULL) {
    
  }
}

void List::dequeue() {
  if (queueHead == NULL) {
    return;
  }

  Node* temp = queueHead->getNext();
  delete queueHead;
  queueHead = temp;

}


