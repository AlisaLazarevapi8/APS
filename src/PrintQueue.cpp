#include "PrintQueue.h"
#include <iostream>

PrintQueue::PrintQueue(int size) : maxSize(size) {
    // Просто создаём очередь с нужным размером
}

bool PrintQueue::addRequest(PrintRequest* req) {
    if (buffer.size() < maxSize) {
        buffer.push_back(req);
        return true;
    } else {
        rejectRequest(req);
        return false;
    }
}

void PrintQueue::rejectRequest(PrintRequest* req) {
    req->status = "rejected";
    std::cout << "Заявка #" << req->id << " отклонена, потому что очередь забита\n";
}

PrintRequest* PrintQueue::selectRequest() {
    if (buffer.empty()) return nullptr;
    auto* req = buffer.front();
    buffer.erase(buffer.begin());
    return req;
}

void PrintQueue::printQueue() {
    std::cout << "Сейчас в очереди: ";
    for (auto* req : buffer)
        std::cout << "#" << req->id << " ";
    std::cout << "\n";
}
