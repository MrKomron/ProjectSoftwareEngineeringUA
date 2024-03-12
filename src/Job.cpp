#include "Job.h"

using namespace std;

// Constructor definition
Job::Job(const std::string& name, int priority, int pages)
        : jobName(name), jobPriority(priority), jobPages(pages), jobPrinted(false) {}

// Setter and getter definitions
void Job::setName(const std::string& name) {
    jobName = name;
}

std::string Job::getName() const {
    return jobName;
}

void Job::setPriority(int priority) {
    jobPriority = priority;
}

int Job::getPriority() const {
    return jobPriority;
}

void Job::setPages(int pages) {
    jobPages = pages;
}

int Job::getPages() const {
    return jobPages;
}

void Job::markPrinted() {
    jobPrinted = true;
}

bool Job::isPrinted() const {
    return jobPrinted;
}