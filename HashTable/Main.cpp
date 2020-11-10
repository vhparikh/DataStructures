#include <iostream>
#include <cstring>
#include "Student.h"
#include "Node.h"

using namespace std;

int hashFunc(int id, int size);
void ADD(int index, Node** &table, Student* std, Node* &head);

int main()
{
  cout << "Welcome to the cooler version of StudentList commands: ADD, PRINT, DELETE, QUIT" << endl;

  char input[100];
  bool quit = false;

  int size = 151;
  Node** hashId = new Node*[size];

  for (int i = 0; i < size; i++) {
    hashId[i] = NULL;
  }
  
  while (!quit) {

    cin.get(input, 100);
    cin.get();

    if (strcmp(input, "ADD") == 0 || strcmp(input, "add") == 0) {
      Student* newstd = new Student();
      int id;
      float gpa;
      /*cout << "First Name: ";
      cin.get(newstd->getFirst(), 100);
      cin.get();
      cout << "Last Name: ";
      cin.get(newstd->getLast(), 100);
      cin.get();*/
      cout << "Student ID: ";
      cin >> id;
      cin.get();
      newstd->setId(id);
      /*cout << "Student GPA: ";
      cin >> gpa;
      cin.get();
      newstd->setGpa(gpa);*/
      Node* head = hashId[hashFunc(id, size)];
      ADD(hashFunc(id, size), hashId, newstd, head);
    }
    else if (strcmp(input, "PRINT") == 0 || strcmp(input, "print") == 0) {
      
    }
    else if (strcmp(input, "DELETE") == 0 || strcmp(input, "delete") == 0) {
      
    }
    else if (strcmp(input, "QUIT") == 0 || strcmp(input, "quit") == 0) {
      quit = true;
    }
    else {
      cout << "Invalid command" << endl;
    }
  }

  for (int i = 0; i < 151; i++) {
    if (hashId[i] != NULL) {
      cout << hashId[i]->getStudent()->getId() << endl;
      cout << hashId[i]->getNext()->getStudent()->getId() << endl;
      hashId[i] = hashId[i]->getNext();
      cout << hashId[i]->getNext()->getStudent()->getId() << endl;
      hashId[i] = hashId[i]->getNext();
      cout << hashId[i]->getNext()->getStudent()->getId() << endl;
    }
    else {
      cout << i << endl; 
    }
  }
  
}

int hashFunc(int id, int size) {
  int index = id % size;
  return index;
}

void ADD(int index, Node** &table, Student* std, Node* &head) {
  if (head == NULL) {
    head = new Node(std);
    table[index] = head;
  }
  else {
    while (head->getNext() != NULL) {
      head = head->getNext();
    }
    Node* temp = new Node(std);
    head->setNext(temp);
  }
}
