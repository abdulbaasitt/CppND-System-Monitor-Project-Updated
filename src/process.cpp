#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "process.h"

using std::string;
using std::to_string;
using std::vector;

Process::Process(int pid) {
  pid_ = pid;
  cpu_utilization_ = Process::CpuUtilization();
  command_ = LinuxParser::Command(pid);
}


// TODO: Return this process's ID
int Process::Pid(){ return pid_; }

// TODO: Return this process's CPU utilization
float Process::CpuUtilization() {
    long int Hertz = sysconf(_SC_CLK_TCK);
    total_time_ = LinuxParser::ActiveJiffies(pid_)/Hertz;
    seconds_ = LinuxParser::UpTime(pid_);
    cpu_utilization_ = total_time_/seconds_;

    return cpu_utilization_;
}

// TODO: Return the command that generated this process
string Process::Command() {
    command_ = LinuxParser::Command(pid_);
    return command_;
}

// TODO: Return this process's memory utilization
string Process::Ram() {
    ram_ = LinuxParser::Ram(pid_);
    return ram_;
}

// TODO: Return the user (name) that generated this process
string Process::User() {
    user_ = LinuxParser::User(pid_);
    return user_;
}

// TODO: Return the age of this process (in seconds)
long int Process::UpTime() {
    uptime_ = LinuxParser::UpTime(pid_);
    return uptime_;}

// TODO: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const& a) const {
    return a.cpu_utilization_ < cpu_utilization_;
}