#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <iostream>
#include "linux_parser.h"
#include <string>
#include <vector>

class Processor {
 public:
  float Utilization();  // TODO: See src/processor.cpp

  // TODO: Declare any necessary private members
 private:
    float prev_idle_{0};
    float prev_non_idle_{0};
    float prev_total_{0};
    float usage{0};
    float prev_total_jiffies_{0};
    float prev_util_jiffies_{0};
    float total_jiffies_{0};
    float idle_jiffies_{0};
    float util_jiffies_{0};

};

#endif