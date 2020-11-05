#include <iostream>
#include <cstring>

using namespace std;

int main()
{
  cout << "Welcome to the cooler version of StudentList commands: ADD, PRINT, DELETE, QUIT" << endl;

  char input[100];
  bool quit = false;

  while (!quit) {

    cin.get(input, 100);
    cin.get();

    if (strcmp(input, "ADD") == 0 || strcmp(input, "add") == 0) {

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
}
