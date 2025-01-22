#include "QueueManager.h"
#include <iostream>
using namespace std;

// Constructor
QueueManager::QueueManager() : roundRobinPointer(0) {}

// Destructor
QueueManager::~QueueManager() {}

// Add a vehicle to the FCFS queue
void QueueManager::addToFCFS(Vehicle* vehicle) {
    fcfsQueue.push(vehicle);
}

// Add a vehicle to the priority queue
void QueueManager::addToPriorityQueue(Vehicle* vehicle) {
    priorityQueue.push(vehicle);
}

// Add a vehicle to the Round Robin queue
void QueueManager::addToRoundRobinQueue(Vehicle* vehicle) {
    roundRobinQueue.push(vehicle);
}

// Process the vehicle in FCFS queue
void QueueManager::processFCFS() {
    if (!fcfsQueue.empty()) {
        Vehicle* vehicle = fcfsQueue.front();
        fcfsQueue.pop();
        // Implement charging process here
        cout << "Processing Vehicle (FCFS): " << vehicle->getId() << endl;
    }
}

// Process the vehicle in Priority queue
void QueueManager::processPriorityQueue() {
    if (!priorityQueue.empty()) {
        Vehicle* vehicle = priorityQueue.top();
        priorityQueue.pop();
        // Implement charging process here
        cout << "Processing Vehicle (Priority): " << vehicle->getId() << endl;
    }
}

// Process the vehicle in Round Robin queue
void QueueManager::processRoundRobinQueue() {
    if (!roundRobinQueue.empty()) {
        Vehicle* vehicle = getNextRoundRobinVehicle();
        // Implement charging process here
        cout << "Processing Vehicle (Round Robin): " << vehicle->getId() << endl;
    }
}

// Get the next vehicle for charging in Round Robin scheduling
Vehicle* QueueManager::getNextRoundRobinVehicle() {
    if (roundRobinPointer >= roundRobinQueue.size()) {
        roundRobinPointer = 0; // Reset pointer when all vehicles have been processed
    }

    Vehicle* vehicle = roundRobinQueue.front();
    roundRobinQueue.push(vehicle); // Rotate the queue for round-robin
    roundRobinQueue.pop();
    roundRobinPointer++;

    return vehicle;
}

// Display the queue statuses (for debugging purposes)
void QueueManager::displayQueues() const {
    cout << "FCFS Queue Size: " << fcfsQueue.size() << endl;
    cout << "Priority Queue Size: " << priorityQueue.size() << endl;
    cout << "Round Robin Queue Size: " << roundRobinQueue.size() << endl;
}
