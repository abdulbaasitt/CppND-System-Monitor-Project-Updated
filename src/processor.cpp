#include "processor.h"

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() {
    std::vector<std::string> cpu_utilization = LinuxParser::CpuUtilization();

    for (std::size_t i{0}; i < cpu_utilization.size(); i++) {
        if (i != LinuxParser::kGuest_ && i != LinuxParser::kGuestNice_) {
            total_jiffies_ += std::stol(cpu_utilization[i]);
        }
        if (i == LinuxParser::kIdle_ || i == LinuxParser::kIOwait_) {
            idle_jiffies_ += std::stol(cpu_utilization[i]);
        }

    }
    util_jiffies_ = total_jiffies_ - idle_jiffies_;

    bool current_util = true;
    if (current_util) {
        usage = (util_jiffies_ - prev_util_jiffies_) / (total_jiffies_ - prev_total_jiffies_);
        prev_util_jiffies_ = util_jiffies_;
        prev_total_jiffies_ = total_jiffies_;
    }
    else {
        usage = (util_jiffies_) / (total_jiffies_);
    
    
    }
    return usage;
}


