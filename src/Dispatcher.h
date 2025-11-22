#pragma once
#include <vector>
#include "Printer.h"

class Dispatcher {
public:
    Printer* selectPrinter(std::vector<Printer>& printers);
};
