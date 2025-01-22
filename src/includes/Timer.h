#ifndef TIMER_H
#define TIMER_H

#include <chrono>

class Timer {
public:
    Timer();

    void start();          // Start the timer
    void stop();           // Stop the timer
    double getElapsedTime() const; // Get elapsed time in seconds

private:
    std::chrono::time_point<std::chrono::steady_clock> startTime;
    std::chrono::time_point<std::chrono::steady_clock> endTime;
    bool isRunning;
};

#endif // TIMER_H
