#include "utilities.h"
#include <iostream>
#include <chrono>
#include <thread>

// Display a message to the console
void displayMessage(const std::string& message) {
    std::cout << message << std::endl;
}

// Get the current time as a string
std::string getCurrentTime() {
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);

    char buffer[100];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %X", localtime(&in_time_t));
    return std::string(buffer);
}

// Delay execution for a specified amount of time (in milliseconds)
void delay(int milliseconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}
