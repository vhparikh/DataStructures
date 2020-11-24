#include <iostream>
#include <cstring>

using namespace std;

int* BUILD(int* vals);

int main() {

  int* heap = new int[6];

  cout << "Welcome heap lets start with some values to add to the heap" << endl;

  for (int i = 1; i < 6; i++) {
    cin >> heap[i];
  }

  heap = BUILD(heap);
  cout << heap[1] << endl;
}

int* BUILD(int* vals) {
  int* newHeap = new int[6];

  int highval = -1000;
  
  for (int i = 1; i < 6; i++) {
    if (vals[i] > highval) {
      highval = vals[i];
    }
  }

  newHeap[1] = highval;

  delete vals;
  return newHeap;
  
}
