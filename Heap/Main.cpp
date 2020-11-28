#include <iostream>
#include <cstring>
#include <math.h>
#include <fstream>

using namespace std;

void buildHelper(int* vals, int size);
void build(int* vals, int index, int size);
void print(int* vals, int size);
void deleteVal(int* vals, int* size, int num);
void sort(int* vals, int size);

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

void buildHelper(int* vals, int size) {
  int startpoint = (size/2)-1;
  for (int i = startpoint; i >= 0; i--) {
    build(vals, i, size);
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

void print(int* vals, int size) {

  int counter = 0;
  int factor = 1;
  cout << vals[0] << endl;
  
  for (int i = 1; i < size; i++) {
    cout << vals[i] << "(" << vals[(int)floor((i-1)/2)] << ")" << " ";
    counter++;
    if (factor * 2 == counter) {
      factor = factor * 2;
      counter = 0;
      cout << endl;
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
