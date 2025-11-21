#pragma once
#include <string>

class PrintRequest {
public:
    int id;
    std::string status; // просто "waiting", "processing", "rejected", "done"
    PrintRequest(int _id);
};
