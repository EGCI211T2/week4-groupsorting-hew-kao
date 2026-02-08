#include <cstdio>

void display(int* a, int N) {
  for (int i = 0; i < N; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}

void swap(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}

void insertion_sort(int *a, int N) {
  for (int i = 1; i < N; i++) {
    for (int j = i; j > 0 && a[j-1] > a[j]; j--) {
      swap(a[j-1], a[j]);
    }
  }
}

int findminwoffset(int *a, int N, int startat) {
  // for selection sort
  int min = a[startat];
  int k = startat;
  for (int i = startat; i < N; i++) {
    if (a[i] < min) {
      min = a[i];
      k = i;
    }
  }
  return k;
}

void selection_sort(int *a, int N) {
  for (int i = 0; i < N - 1; i++) {
    swap(a[i], a[findminwoffset(a, N, i)]);
  }
}


void bubble_sort(int *a, int N) {
  int swappedflag = 0;
  for (int i = 0; i < N; i++) {
    swappedflag = 0;
    for (int j = 0; j < N-i-1; j++) {
      if (a[j] > a[j+1]) {
        swap(a[j], a[j+1]);
        swappedflag = 1;
      }
    }
    if (!swappedflag) {break;}
  }
}