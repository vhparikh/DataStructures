//Created by Vatsal Parikh
//Date: 11/24/2020
//create max heap

//imports
#include <iostream>
#include <cstring>
#include <math.h>
#include <fstream>

using namespace std;

//prototypes
void print(int* vals, int size);
void deleteVal(int* vals, int* size, int num);
void sort(int* vals, int size);

int main() {

  char input[30]; //for commands
  int* heap = new int[100]; //stores heap
  int num; //number user inputs
  int inNum; //how many numbers the user wants to add
  int counter = 0; //counts and keeps track of heap index
  int size = 0; //keeps track of heap size
  bool quit = false;

  //sets all values in heap to 0
  for (int i = 0; i < 100; i++) {
    heap[i] = 0;
  }

  cout << "Welcome to heap your commands are: add, file, delete, print, quit" << endl;

  //while user hasn't typed quit
  while (quit == false) {
    cout << "Command:" << endl;
    cin >> input;

    if (strcmp(input, "add") == 0) {
      cout << "How many numbers would you like to input?" << endl;
      cin >> inNum;
      counter = 0;
      while (counter != inNum) {
	cout << "Enter a number:" << endl;
	cin >> num;
	if (num >= 1 && num <= 1000) {
	  heap[size] = num;
	  size++;
	  counter++;
	}
	else {
	  cout << "invalid number" << endl;
	}
      }
      sort(heap, size);
    }
    else if (strcmp(input, "file") == 0) {
      cout << "File name:" << endl;
      cin >> input;
      ifstream file;
      file.open(input);

      while (file >> num) {
	heap[counter] = num;
	counter++;
	size++;
      }
      file.close();
      sort(heap, size);
    }
    else if (strcmp(input, "delete") == 0) {
      cout << "What value would you like to delete from the heap?" << endl;
      cin >> num;
      deleteVal(heap, &size, num);
      sort(heap, size);
    }
    else if (strcmp(input, "print") == 0) {
      print(heap, size);
    }
    else if (strcmp(input, "quit") == 0) {
      quit = true;
    }
    else {
      cout << "invalid command" << endl;
    } 
  }
}

void sort(int* vals, int size) {
  
  for (int j = 0; j < size; j++) {
    for (int i = 0; i < size; i++) {
      if (vals[i] < vals[i+1]) {
	int temp = vals[i];
	vals[i] = vals[i+1];
	vals[i+1] = temp;
      }
    }
  }
}

void print(int* vals, int size) {

  int counter = 0;
  int factor = 1;

  if (vals[0] >= 1 && vals[0] <= 1000) {
    cout << vals[0] << endl;
  }
  
  for (int i = 1; i < size; i++) {
    if (vals[i] >= 1 || vals[i] <= 1000) {
      cout << vals[i] << "(" << vals[(int)floor((i-1)/2)] << ")" << " ";
      counter++;
      if (factor * 2 == counter) {
	factor = factor * 2;
	counter = 0;
	cout << endl;
      }
    }
  }
  cout << endl;
}

void deleteVal(int* vals, int* size, int num) {

  for (int i = 0; i < *size; i++) {
    if (vals[i] == num) {
      vals[i] = vals[*size-1];
      vals[*size-1] = 0;
      *size = *size - 1;
      return;
    }
  }
  cout << "value is not in the heap" << endl;
}
