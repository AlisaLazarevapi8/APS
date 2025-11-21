#include <iostream>
#include <vector>
#include "PrintQueue.h"
#include "Printer.h"
#include "Dispatcher.h"
#include "PrintRequest.h"

int main() {
    int steps = 10, bufferSize = 4, printRequests = 1;
    PrintQueue queue(bufferSize);
    std::vector<Printer> printers(2); // два принтера, можно играть
    Dispatcher dispatcher;
    std::vector<PrintRequest*> allRequests;

    for (int step = 1; step <= steps; ++step) {
        std::cout << "\n--- Шаг " << step << " ---\n";
        // Я как студент подаю новую заявку
        PrintRequest* req = new PrintRequest(printRequests++);
        allRequests.push_back(req);
        std::cout << "Подал заявку #" << req->id << "\n";
        queue.addRequest(req);

        // Просто смотрю на очередь
        queue.printQueue();

        // Диспетчер ищет свободный принтер
        Printer* freePrinter = dispatcher.selectPrinter(printers);
        PrintRequest* nextReq = queue.selectRequest();
        if (freePrinter && nextReq && nextReq->status == "waiting") {
            freePrinter->startProcessing(nextReq);
        }

        // Все принтеры завершают текущую работу
        for (auto& printer : printers)
            printer.finishProcessing();
    }

    std::cout << "\n=== Итог ===\n";
    for (auto* req : allRequests)
        std::cout << "Заявка #" << req->id << " — " << req->status << "\n";

    return 0;
}
