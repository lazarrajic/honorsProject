#include <iostream>
#include "ClassTimes.h"

int main() {
  ClassTimes classTimes;
  char done;
  do {
    classTimes.addClassTime();
    cout << "Add another class time? (y/n):" << endl;
    cin >> done;
  } while (done != 'n');
  classTimes.printSchedule();

  return 0;
}
