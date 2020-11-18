#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include "Student.h"
#include "Node.h"

using namespace std;

int hashFunc(int id, int size);
void ADD(int index, Node** &table, Student* std, Node* &head);
bool resizeCheck(Node** table, int index);
void PRINT(Node** table, int size);
void rehash(Node** &table, int* size);
void DELETE(Node** &table, int index, int id);

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

  ifstream first;
  first.open("Firstname.txt");
  ifstream last;
  last.open("Lastname.txt");
  int firstLine = 0;
  int lastLine = 0;
  int id;
  int rNum;
  float gpa;
  char in[20];
  srand(time(NULL));
  
  while (!quit) {

    cin.get(input, 100);
    cin.get();

    if (strcmp(input, "ADD") == 0 || strcmp(input, "add") == 0) {
      Student* newstd = new Student();
      cout << "First Name: ";
      cin.get(newstd->getFirst(), 100);
      cin.get();
      cout << "Last Name: ";
      cin.get(newstd->getLast(), 100);
      cin.get();
      cout << "Student ID: ";
      cin >> id;
      cin.get();
      newstd->setId(id);
      cout << "Student GPA: ";
      cin >> gpa;
      cin.get();
      newstd->setGpa(gpa);
      Node* head = hashId[hashFunc(id, size)];
      ADD(hashFunc(id, size), hashId, newstd, head);
      if (resizeCheck(hashId, hashFunc(id, size)) == true) {
	rehash(hashId, &size);
      }
    }
    else if (strcmp(input, "random") == 0 || strcmp(input, "RANDOM") == 0) {
      cout << "How many random students?" << endl;
      cin >> rNum;
      cin.get();

      for (int i = 0; i < rNum; i++) {
	Student* newstd = new Student();
	firstLine = (rand() % 13);
	lastLine = (rand() % 13);
	cout << firstLine << " " << lastLine << endl;
	
	for (int j = 0; j < 13; j++) {
	  if (firstLine == j) {
	    first >> newstd->getFirst();
	  }
	  else {
	    first >> in;
	  }
	  
	  if (lastLine == j) {
	    last >> newstd->getLast();
	  }
	  else {
	    last >> in;
	  }
	}

	first.close();
	first.open("Firstname.txt");
	last.close();
	last.open("Lastname.txt");
	newstd->setId(i + 1);
	newstd->setGpa((float)(rand() % 400) / (float)(100));
	Node* head = hashId[hashFunc(newstd->getId(), size)];
	ADD(hashFunc(newstd->getId(), size), hashId, newstd, head);
	if (resizeCheck(hashId, hashFunc(newstd->getId(), size)) == true) {
	  rehash(hashId, &size);
	}
	cout << newstd->getFirst() << " " << newstd->getLast() << endl;
      }
      cout << "Students have been generated" << endl;
    }
    else if (strcmp(input, "PRINT") == 0 || strcmp(input, "print") == 0) {
      PRINT(hashId, size);
    }
    else if (strcmp(input, "DELETE") == 0 || strcmp(input, "delete") == 0) {
      int id;
      cout << "Enter the id of the student you would like to delete: ";
      cin >> id;
      cin.get();
      DELETE(hashId, hashFunc(id, size), id);
    }
    else if (strcmp(input, "QUIT") == 0 || strcmp(input, "quit") == 0) {
      quit = true;
    }
    else {
      cout << "Invalid command" << endl;
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

bool resizeCheck(Node** table, int index) {
  int counter = 0;
  Node* current = table[index];

  while (current != NULL) {
    current = current->getNext();
    counter++;
  }

  if (counter == 3) {
    return true;
  }
  return false;
}

void PRINT(Node** table, int size) {
  for (int i = 0; i < size; i++) {
    if (table[i] != NULL) {
      Node* current = table[i];
      while (current != NULL) {
	cout << current->getStudent()->getFirst() << " " << current->getStudent()->getLast() << ", "
	     << current->getStudent()->getId() << ", "
	     << fixed << setprecision(2) << current->getStudent()->getGpa() << endl;
	current = current->getNext();
      }
    }
  }
}

void rehash(Node** &table, int* size) {
  int newSize = *(size) * 2;
  Node** newTbl = new Node*[newSize];

  for (int i = 0; i < newSize; i++) {
    newTbl[i] = NULL; 
  }
  
  for (int i = 0; i < *size; i++) {
    if (table[i] != NULL) {
      Node* current = table[i];
      while (current != NULL) {
	Node* head = newTbl[hashFunc(current->getStudent()->getId(), newSize)];
	ADD(hashFunc(current->getStudent()->getId(), newSize), newTbl, current->getStudent(), head);
	current = current->getNext();
      }
    }
  }

  delete[] table;
  table = newTbl;
  *size = newSize;
  
}

void DELETE(Node** &table, int index, int id) {
  Node* current = table[index];
  char input[20];
  while (current != NULL) {
    if (current->getStudent()->getId() == id) {
      cout << "Do you want to remove this student from the table y/n? "
	   << current->getStudent()->getFirst() << " " << current->getStudent()->getLast() << ", "
	   << current->getStudent()->getId() << ", "
	   << fixed << setprecision(2) << current->getStudent()->getGpa() << endl;
      cin.get(input, 20);
      cin.get();
      if (strcmp(input, "Y") == 0 || strcmp(input, "y") == 0) {
	Node* temp = current->getNext();
	current->~Node();
	if (temp != NULL) {
	  table[index] = temp;
	}
	else {
	  table[index] = NULL;
	}
	cout << "Student has been removed" << endl;
      }
      return;
    }
    else if (current->getNext()->getStudent()->getId() == id) {
      cout << "Do you want to remove this student from the table y/n? "
           << current->getStudent()->getFirst() << " " << current->getStudent()->getLast() << ", "
	   << current->getStudent()->getId() << ", "
	   << fixed << setprecision(2) << current->getStudent()->getGpa() << endl;
      cin.get(input, 20);
      cin.get();
      if (strcmp(input, "Y") == 0 || strcmp(input, "y") == 0) {
	Node* temp = current->getNext()->getNext();
	current->getNext()->~Node();
	if (temp != NULL) {
	  current->setNext(temp);
	}
	else {
	  current->setNext(NULL);
	}
	cout << "Student has been removed" << endl;
      }
      return;
    }
    current = current->getNext();
  }
}
