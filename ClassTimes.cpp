#include "ClassTimes.h"
#include <iostream>

using namespace std;

void printTime(double time) {
  int hour = static_cast<int>(time);
  int minute = (time - hour) * 60;
  cout << hour << ":" << minute;
}

ClassTimes::ClassTimes() {
    for (double i = 8.0; i < 22.0; i += 0.5) {
      times.push_back(i);
    }
  }

void ClassTimes::printSchedule() {
    const double gymOpen = 9.0;
    const double gymClose = 18.0;


    for (auto const &[day, times] : schedule) {
        
      cout << "Day " << day << " available times: " << endl;

      vector<pair<double, double>> nonOverlapTimes;
      double lastEndTime = gymOpen;

      for (auto const &time : times) {
        if (time.first >= gymClose) {
          // Class starts after gym closes, skip
          continue;
        }

        if (time.second <= gymOpen) {
          // Class ends before gym opens, skip
          continue;
        }

        if (time.first >= lastEndTime) {
          // No overlap, add to non-overlapping times
          nonOverlapTimes.push_back(make_pair(lastEndTime, time.first));
        }

        lastEndTime = max(lastEndTime, time.second);
      }

      if (lastEndTime < gymClose) {
        // Add remaining time after last class if gym is still open
        nonOverlapTimes.push_back(make_pair(lastEndTime + .5, gymClose));
      }

        
      for (auto const &time : nonOverlapTimes) {
        cout << "Start time: ";
        printTime(time.first);
        cout << " End time: ";
        printTime(time.second);
        cout << endl;
      }
    }
  }

  void ClassTimes::addClassTime() {
   int dayChoice;
    do {
      cout << "Select a day of the week (1-7):" << endl;
      cin >> dayChoice;
    } while (dayChoice < 1 || dayChoice > 7);

    cout << "Select a start time:" << endl;
    for (int i = 0; i < times.size(); i++) {
      cout << i + 1 << ". ";
      printTime(times[i]);
      cout << endl;
    }

    int startChoice;
    do {
      cin >> startChoice;
    } while (startChoice < 1 || startChoice > times.size());

    double startTime = times[startChoice - 1];

    cout << "Select an end time:" << endl;
    for (int i = startChoice; i < times.size(); i++) {
      cout << i - startChoice + 1 << ". ";
      printTime(times[i]);
      cout << endl;
    }

    int endChoice;
    do {
      cin >> endChoice;
    } while (endChoice < 1 || endChoice > times.size() - startChoice + 1);

    double endTime = times[startChoice + endChoice - 2];

    schedule[dayChoice].push_back(make_pair(startTime, endTime));
  }
