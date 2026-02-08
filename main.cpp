#include <cstdio>
#include "sorting.h"
#include <cstdlib>
#include <string>

using namespace std;
int main(int argc, char** argv) {
  /*int arrayN = argc - 2;
  int* arr = new int[arrayN];

  for (int i = 2; i < argc; i++) {
    arr[i-2] = atoi(argv[i]);
  }*/

  // parsing 1,3,2,1,2,... into array
  // - count how many element exist
  int arrayN = 0;
  int i = 0;
  char c;
  while (c = argv[2][i]) {
    if (c == ',') {
      arrayN++;
    }
    i++;
  }
  if (!arrayN) {return 0;} // in case no element at all just return.
  arrayN++;
  // - convert numbers in the string into actual number array
  int* arr = new int[arrayN];
  int arri = 0;
  string buffer;
  i = 0;
  while (c = argv[2][i]) {
    if (c == ',') {
      arr[arri++] = stoi(buffer);
      buffer.clear();
    } else {
      buffer.append(1, c);
    }
    i++;
  }
  arr[arri++] = stoi(buffer);
  buffer.clear();
  buffer.shrink_to_fit();
  //display(arr, arrayN);

  string option = argv[1];
  
  if (option == "bubble") {
    bubble_sort(arr, arrayN);
    // 61.5651 62.3236 59.9378 60.4981 62.5408 59.021
    // avg 60.9811 ms
    // stddev 1.40 ms
  } else if (option == "insert") {
    insertion_sort(arr, arrayN);
    // 63.6458 60.3801 61.8664 61.9648 62.1389 59.289
    // avg 61.5475 ms
    // stddev 1.52 ms
  } else if (option == "selection") {
    selection_sort(arr, arrayN); 
    // 67.6123 66.0779 68.9154 68.8395 70.8055 69.7221
    // avg 68.6621 ms
    // stddev 1.65 ms
  }

  display(arr, arrayN);

  delete[] arr;
  return 0;
}