#include "QSInterface.h"
#include <algorithm>
#include <string>
#include <array>
#include <sstream>
using namespace std;

class QS: public QSInterface {
public: 
  QS();
  ~QS();

  bool addToArray(int value);

  bool createArray(int capacity);

  string getArray() const;
  
  void sortAll();
 
  int medianOfThree(int left, int right);
  
  int partition(int left, int right, int pivot_index);
  
  int getSize() const;
  
  void clear();
 
  void quicksort(int left, int right);

protected:
  int *table;
  int counter = 0;
  int size;
};