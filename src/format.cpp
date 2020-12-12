#include <string>
#include <vector>

#include "format.h"

using std::string;
using std::to_string;
using std::vector;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
string Format::ElapsedTime(long time) { // seconds
  string elapsedTime;
  vector<string> timeVec; // store strings in reverse order
  for (size_t i = 0; i < 3; ++i) {
    int unit = (i == 2 ? 24 : 60);  // HH is restricted in 24h
    long tmp = time % unit;
    time /= unit;
    timeVec.push_back(to_string(tmp));
    // Add 0 to make sure 2 digits at MM and SS
    if (tmp < 10) timeVec.push_back("0");
    if (i != 2) timeVec.push_back(":");
  }
  //  // Handle HH, not limited to be smaller than 24
  //  timeVec.push_back(to_string(time));
  //  if (time < 10) timeVec.push_back("0");

  // Concatenate to get formatted uptime
  for (auto it = timeVec.rbegin(); it != timeVec.rend(); ++it ) {
    elapsedTime += *it;
  }
  return elapsedTime;
}
