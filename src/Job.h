// Job.h

#ifndef PROJECTFIRST_JOBFUNCTIONALITY_H
#define PROJECTFIRST_JOBFUNCTIONALITY_H

#include <string>

class Job {
private:
    std::string jobName;
    int jobPriority;
    int jobPages;
    bool jobPrinted;

public:
    // Constructor
    Job(const std::string& name, int priority, int pages);

    // Member function declarations
    void setName(const std::string& name);
    std::string getName() const;

    void setPriority(int priority);
    int getPriority() const;

    void setPages(int pages);
    int getPages() const;

    void markPrinted();
    bool isPrinted() const;
};

#endif //PROJECTFIRST_JOBFUNCTIONALITY_H