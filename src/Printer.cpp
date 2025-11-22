#include "Printer.h"
#include <iostream>

Printer::Printer() : busy(false), current(nullptr) {}

void Printer::startProcessing(PrintRequest* req) {
    busy = true;
    current = req;
    req->status = "processing";
    std::cout << "Принтер взялся за заявку #" << req->id << "\n";
}

void Printer::finishProcessing() {
    if (busy && current) {
        current->status = "done";
        std::cout << "Принтер закончил заявку #" << current->id << "\n";
        busy = false;
        current = nullptr;
    }
}

bool Printer::isFree() { return !busy; }
