#include <string>
#include <vector>

#include "processor.h"
#include "linux_parser.h"

using std::string;
using std::vector;

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() {
  utilization_ = 1 - 1.0 * LinuxParser::IdleJiffies() / LinuxParser::Jiffies();
  return utilization_;
}

/*
*user: normal processes executing in user mode
*nice: niced processes executing in user mode
*system: processes executing in kernel mode
*idle: twiddling thumbs
*iowait: waiting for I/O to complete
*irq: servicing interrupts
*softirq: servicing softirqs
*steal: involuntary wait
*guest: running a normal guest
*guest_nice: running a niced guest
*/