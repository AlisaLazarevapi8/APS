#include "Dispatcher.h"

Printer* Dispatcher::selectPrinter(std::vector<Printer>& printers) {
    for (auto& printer : printers)
        if (printer.isFree())
            return &printer;
    return nullptr;
}
