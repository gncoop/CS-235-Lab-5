#include "QS.h"
using namespace std;
QS::QS(){}
QS::~QS(){}

bool QS::createArray(int capacity) {
  size = capacity;
  counter = 0;

  if(capacity < 0) {
    return false;
  }
  if(sizeof(table) != 0) {
    delete [] table;
  }
  table = new int[capacity];

  return true;
}

bool QS::addToArray(int value) {
  if (counter == size) {
    return false;
  }
  table[counter] = value;
  ++counter;
  cout << endl;

  return true;
}

string QS::getArray() const {
  string empty;
  string actual;
  int holder = 0;
  
  if(counter == 0) {
    return empty;
  }
  for(int i = 0; i < counter; i++){
    if(i == counter - 1) {
      holder = table[i];
      actual += to_string(holder);
    }
    else {
      holder = table[i];
      actual += to_string(holder);
      actual += ',';
    }
  }
  return actual;
}

void QS::sortAll() {
  if(size == 0) {
    return;
  }
  quicksort(0, counter - 1);
}

void QS::quicksort(int left, int right) {
  cout << left << " " << right << endl;
  if(right < left) {
    return;
  }
  int middle = medianOfThree(left, right);
  int pivotIndex = partition(left, right, middle);
  if (pivotIndex == -1) {
    return;
  }
  quicksort(left, pivotIndex - 1);
  quicksort(pivotIndex + 1, right);
}

int QS::medianOfThree(int left, int right) {
  int middle;
  int placeHolder;

  middle = (left + right) / 2;
  if (middle < 0 || middle > right) {
    return -1;
  }
  if(table[left] > table[middle]) {
    placeHolder = table[left];
    table[left] = table[middle];
    table[middle] = placeHolder;
  }
  if(table[left] > table[right]) {
    placeHolder = table[left];
    table[left] = table[right];
    table[right] = placeHolder;
  }
  if(table[middle] > table[right]) {
    placeHolder = table[middle];
    table[middle] = table[right];
    table[right] = placeHolder;
  } 

  return middle;
}

int QS::partition(int left, int right, int pivot_index) {
  if (pivot_index <= 1) {
    return -1;
  }
  int tmp;
  tmp = table[pivot_index]; 
  table[pivot_index] = table[left];
  table[left] = tmp;

  int up = left + 1; 
  int down = right;
  
  do {
    while ((table[up] <= table[left]) && (up < right)) {
      up++;
    }
    while ((table[down] > table[left]) && (down > left)) {
      down--;
    }
    if (up < down) {
      tmp = table[up];
      table[up] = table[down];
      table[down] = tmp;
    }
  } while(up < down);
  
  tmp = table[left];
  table[left] = table[down];
  table[down] = tmp;

  return down;
}

int QS::getSize() const {

  return counter;
}

void QS::clear() {

  delete [] table; 
  table = nullptr;
  counter = 0;
  size = 0;
}