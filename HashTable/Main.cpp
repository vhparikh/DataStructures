//Created by Vatsal Parikh
//Date: 11/17/20
//Student list but with hash tables

//imports
#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include "Student.h"
#include "Node.h"

using namespace std;

//prototypes
int hashFunc(int id, int size);
void ADD(int index, Node** &table, Student* std, Node* &head);
bool resizeCheck(Node** table, int index);
void PRINT(Node** table, int size);
void rehash(Node** &table, int* size);
void DELETE(Node** &table, int index, int id);

int main()
{
  cout << "Welcome to the cooler version of StudentList commands: ADD, PRINT, DELETE, RANDOM, QUIT" << endl;

  char input[100];
  bool quit = false;

  //setup of array for storing students
  int size = 151;
  Node** hashId = new Node*[size];

  //set everything in array to NULL
  for (int i = 0; i < size; i++) {
    hashId[i] = NULL;
  }

  //open name files and set up variable for it
  ifstream first;
  first.open("Firstname.txt");
  ifstream last;
  last.open("Lastname.txt");
  int firstLine = 0;
  int lastLine = 0;
  int id;
  int rNum;
  int randId = 1;
  float gpa;
  char scan[20];
  srand(time(NULL));

  //while user hasn't typed quit
  while (!quit) {

    //get the input
    cin.get(input, 100);
    cin.get();

    //if user wants to manually add
    if (strcmp(input, "ADD") == 0 || strcmp(input, "add") == 0) {

      //create student
      Student* newstd = new Student();

      //get first name
      cout << "First Name: ";
      cin.get(newstd->getFirst(), 100);
      cin.get();

      //get last name
      cout << "Last Name: ";
      cin.get(newstd->getLast(), 100);
      cin.get();

      //get id
      cout << "Student ID: ";
      cin >> id;
      cin.get();
      newstd->setId(id);

      //get gpa
      cout << "Student GPA: ";
      cin >> gpa;
      cin.get();
      newstd->setGpa(gpa);

      //add the student to the list
      Node* head = hashId[hashFunc(id, size)];
      ADD(hashFunc(id, size), hashId, newstd, head);

      //if there are three nodes in one index rehash the table
      if (resizeCheck(hashId, hashFunc(id, size)) == true) {
	rehash(hashId, &size);
      }
    }

    //if user wants to have randomly generated students
    else if (strcmp(input, "random") == 0 || strcmp(input, "RANDOM") == 0) {

      //how many random students
      cout << "How many random students?" << endl;
      cin >> rNum;
      cin.get();

      //keep creating students until wanted number is met
      for (int i = 0; i < rNum; i++) {

	//create a student and get the first and last name lines
	Student* newstd = new Student();
	firstLine = (rand() % 13);
	lastLine = (rand() % 13);

	//scan the txt file
	for (int j = 0; j < 13; j++) {
	  if (firstLine == j) {
	    first >> newstd->getFirst();
	  }
	  else {
	    first >> scan;
	  }
	  
	  if (lastLine == j) {
	    last >> newstd->getLast();
	  }
	  else {
	    last >> scan;
	  }
	}

	//close and reopen files and setup the students info
	first.close();
	first.open("Firstname.txt");
	last.close();
	last.open("Lastname.txt");
	newstd->setId(randId);
	newstd->setGpa((float)(rand() % 400) / (float)(100));
	Node* head = hashId[hashFunc(randId, size)];
	ADD(hashFunc(randId, size), hashId, newstd, head);
	if (resizeCheck(hashId, hashFunc(randId, size)) == true) {
	  rehash(hashId, &size);
	}
	randId++;
      }
      cout << "Students have been generated" << endl;
    }

    //if user wants to print out the students
    else if (strcmp(input, "PRINT") == 0 || strcmp(input, "print") == 0) {
      PRINT(hashId, size);
    }

    //if the user wants to delete a student
    else if (strcmp(input, "DELETE") == 0 || strcmp(input, "delete") == 0) {

      //get the student id and delete it
      int id;
      cout << "Enter the id of the student you would like to delete: ";
      cin >> id;
      cin.get();
      DELETE(hashId, hashFunc(id, size), id);
    }

    //if the user wants to quit end the program
    else if (strcmp(input, "QUIT") == 0 || strcmp(input, "quit") == 0) {
      quit = true;
    }

    //otherwise an invalid command was entered
    else {
      cout << "Invalid command" << endl;
    }
  }
}

//gets a index for the id based on the hash function
int hashFunc(int id, int size) {
  int index = id % size;
  return index;
}

//adds students to the array
void ADD(int index, Node** &table, Student* std, Node* &head) {

  //if the index it null just put in the value
  if (head == NULL) {
    head = new Node(std);
    table[index] = head;
  }

  //otherwise loop through the chain until a empty slot is found
  else {
    while (head->getNext() != NULL) {
      head = head->getNext();
    }
    Node* temp = new Node(std);
    head->setNext(temp);
  }
}

//checks if rehashing is needed
bool resizeCheck(Node** table, int index) {
  int counter = 0;
  Node* current = table[index];

  //go through an array slot and see if there are 3 nodes in one index
  while (current != NULL) {
    current = current->getNext();
    counter++;
  }

  //if three nodes in one slot true else false
  if (counter == 3) {
    return true;
  }
  return false;
}

//prints out the students in the array
void PRINT(Node** table, int size) {

  //loop through the array and print out all the students
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

//rehashs the table
void rehash(Node** &table, int* size) {

  //change the table size
  int newSize = *(size) * 2;
  Node** newTbl = new Node*[newSize];

  for (int i = 0; i < newSize; i++) {
    newTbl[i] = NULL; 
  }

  //go through old table and rehash everything into the new table
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

  //modify some pointers
  delete[] table;
  table = newTbl;
  *size = newSize;
  
}

//deletes a student from the table
void DELETE(Node** &table, int index, int id) {
  Node* current = table[index];
  char input[20];

  //loop through nodes at slot to find the student
  while (current != NULL) {

    //if the student is the head delete as so
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

    //if the student is not the head delete as such
    else if (current->getNext()->getStudent()->getId() == id) {
      cout << "Do you want to remove this student from the table y/n? "
           << current->getNext()->getStudent()->getFirst() << " " << current->getNext()->getStudent()->getLast() << ", "
	   << current->getNext()->getStudent()->getId() << ", "
	   << fixed << setprecision(2) << current->getNext()->getStudent()->getGpa() << endl;
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
