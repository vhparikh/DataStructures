#include <iostream>
#include <cstring>
#include <math.h>

using namespace std;

void buildHelper(int* vals, int size);
void build(int* vals, int index, int size);
//void print(int* vals, int size);
  
int main() {
  char input[30];
  int* heap = new int[100];
  int num;
  int inNum;
  int counter = 0;
  int size = 0;
  bool quit = false;

  for (int i = 0; i < 100; i++) {
    heap[i] = 0;
  }
  
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
	if (num >= 1 && num <= 100) {
	  heap[size] = num;
	  size++;
	  counter++;
	}
	else {
	  cout << "invalid number" << endl;
	}
      }
      buildHelper(heap, size);
      cout << "built" << endl;
    }
    else if (strcmp(input, "file") == 0) {
      //build with file
    }
    else if (strcmp(input, "delete") == 0) {
      //delete
    }
    else if (strcmp(input, "print") == 0) {
      //      print(heap, size);
    }
    else if (strcmp(input, "quit") == 0) {
      quit = true;
    }
    else {
      cout << "invalid command" << endl;
    } 
  }
}

void buildHelper(int* vals, int size) {
  int startpoint = (size/2)-1;
  for (int i = startpoint; i >= 0; i--) {
    build(vals, i, size);
    cout << "called " << i << endl;
  }
}

void build(int* vals, int index, int size) {
  int parentIndex = index;
  int leftIndex = (2*index)+1;
  int rightIndex = (2*index)+2;

  if (leftIndex < size && vals[leftIndex] > vals[parentIndex]) {
    parentIndex = leftIndex;
  }

  if (rightIndex < size && vals[rightIndex] > vals[parentIndex]) {
    parentIndex = rightIndex;
  }

  if (parentIndex != index) {
    int temp = vals[index];
    vals[index] = vals[parentIndex];
    vals[parentIndex] = temp;

    build(vals, parentIndex, size);
  }
  
}

