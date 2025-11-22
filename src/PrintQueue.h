#pragma once
#include <vector>
#include "PrintRequest.h"

class PrintQueue {
    std::vector<PrintRequest*> buffer;
    int maxSize;
public:
    PrintQueue(int size);
    bool addRequest(PrintRequest* req);
    PrintRequest* selectRequest();
    void rejectRequest(PrintRequest* req);
    void printQueue(); // просто мнение о состоянии очереди
};
