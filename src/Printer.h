#pragma once
#include "PrintRequest.h"

class Printer {
    bool busy;
    PrintRequest* current;
public:
    Printer();
    void startProcessing(PrintRequest* req);
    void finishProcessing();
    bool isFree();
};
