#include "timer.h"

// Constructor
Timer::Timer() : isRunning(false) {}

// Start the timer
void Timer::start() {
    isRunning = true;
    startTime = std::chrono::steady_clock::now();
}

// Stop the timer
void Timer::stop() {
    if (isRunning) {
        endTime = std::chrono::steady_clock::now();
        isRunning = false;
    }
}

// Get the elapsed time in seconds
double Timer::getElapsedTime() const {
    if (isRunning) {
        auto now = std::chrono::steady_clock::now();
        return std::chrono::duration<double>(now - startTime).count();
    }
    return std::chrono::duration<double>(endTime - startTime).count();
}
