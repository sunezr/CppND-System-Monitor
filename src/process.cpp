#include <unistd.h>
//#include <cctype>
//#include <sstream>
#include <string>
//#include <vector>

#include "process.h"
#include "linux_parser.h"

using std::string;
using std::to_string;


Process::Process(int pid) {
  pid_ = pid;
  user_ = LinuxParser::User(pid);
  command_ = LinuxParser::Command(pid);
  // dynamic
  cpuUtilization_ = 1.0 * LinuxParser::ActiveJiffies(pid) / sysconf(_SC_CLK_TCK) / LinuxParser::UpTime(pid);
  ram_ = LinuxParser::Ram(pid);
  upTime_ = LinuxParser::UpTime(pid_);
}

// TODO: Return this process's ID
int Process::Pid() { return pid_; }

// TODO: Return this process's CPU utilization
float Process::CpuUtilization() { return cpuUtilization_; }

// TODO: Return the command that generated this process
string Process::Command() { return command_; }

// TODO: Return this process's memory utilization
string Process::Ram() { return ram_; }

// TODO: Return the user (name) that generated this process
string Process::User() { return user_; }

// TODO: Return the age of this process (in seconds)
long int Process::UpTime() { return upTime_; }

// TODO: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const &a) const {
  return cpuUtilization_ > a.cpuUtilization_;  // Sort by CPU utilization
  //return ram_ > a.ram_; // Sort by ram, does not work!
}