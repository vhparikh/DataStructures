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
void remove(int* vals, int size);

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

  cout << "Welcome to heap your commands are: add, file, delete, print, remove, quit" << endl;

  //while user hasn't typed quit
  while (quit == false) {
    cout << "Command:" << endl;
    cin >> input;

    //if user wants to add get values and then call sort
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

    //if user wants to use file input get file name and get values then call sort
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

    //if user wants to delete get value then delete and resort heap
    else if (strcmp(input, "delete") == 0) {
      cout << "What value would you like to delete from the heap?" << endl;
      cin >> num;
      deleteVal(heap, &size, num);
      sort(heap, size);
    }

    //if user wants to print call print
    else if (strcmp(input, "print") == 0) {
      print(heap, size);
    }

    //if users wants to remove call remove
    else if (strcmp(input, "remove") == 0) {
      remove(heap, size);
    }
    
    //if user wants to quit set quit to true
    else if (strcmp(input, "quit") == 0) {
      quit = true;
    }

    //otherwise it is an invalid command
    else {
      cout << "invalid command" << endl;
    } 
  }
}

//sorts array so it can form a max heap
void sort(int* vals, int size) {

  //bubble sort loops
  for (int j = 0; j < size; j++) {
    for (int i = 0; i < size; i++) {
      if (vals[i] < vals[i+1]) { //if the right val is higher then left val swap
	int temp = vals[i];
	vals[i] = vals[i+1];
	vals[i+1] = temp;
      }
    }
  }
}

//prints so you can visualize heap
void print(int* vals, int size) {

  int counter = 0; //counts prints made on each linge
  int factor = 1; //based on line number

  //print root
  if (vals[0] >= 1 && vals[0] <= 1000) {
    cout << vals[0] << endl;
  }

  //go through and print rest if counter has hit its number based on current line end line
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

//deletes value from heap
void deleteVal(int* vals, int* size, int num) {

  //loop through array and find value
  for (int i = 0; i < *size; i++) {

    //once value is found replace it with last val in array and reduce size by one
    if (vals[i] == num) { 
      vals[i] = vals[*size-1];
      vals[*size-1] = 0;
      *size = *size - 1;
      return;
    }
  }
  cout << "value is not in the heap" << endl;
}

//removes all values from heap and output lowest to highest
void remove(int* vals, int size) {

  //loop through array and print out values
  for (int i = 0; i < size; i++) {
    cout << vals[i] << " ";
    vals[i] = 0;
  }
  cout << endl;
  cout << "The heap is now completely empty and all the values have been outputted above" << endl;
  
}
