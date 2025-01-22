#include "Scheduler.h"
#include <iostream>
#include <algorithm>
#include <thread>
#include <chrono>

using namespace std;

// Comparator for priority queue
bool comparePriority(Vehicle* v1, Vehicle* v2) {
    return v1->getPriority() > v2->getPriority(); // Higher priority first
}

// Constructor
Scheduler::Scheduler(int numPorts, int timeQuantum)
    : numPorts(numPorts), timeQuantum(timeQuantum), 
      priorityQueue(comparePriority) {}

// Add vehicles to respective queues
void Scheduler::addVehicleToFCFS(Vehicle* vehicle) {
    fcfsQueue.push(vehicle);
}

void Scheduler::addVehicleToPriorityQueue(Vehicle* vehicle) {
    priorityQueue.push(vehicle);
}

void Scheduler::addVehicleToRoundRobin(Vehicle* vehicle) {
    roundRobinQueue.push(vehicle);
}

// FCFS Scheduling
void Scheduler::scheduleFCFS() {
    cout << "Scheduling vehicles using First-Come, First-Serve..." << endl;
    while (!fcfsQueue.empty() && numPorts > 0) {
        Vehicle* vehicle = fcfsQueue.front();
        fcfsQueue.pop();

        vehicle->setChargingStatus(true);
        numPorts--;
        cout << "Charging Vehicle: " << vehicle->getVehicleID() << endl;

        // Simulate charging
        this_thread::sleep_for(chrono::seconds(2));
        vehicle->setChargingStatus(false);
        numPorts++;
        cout << "Finished Charging: " << vehicle->getVehicleID() << endl;
    }
}

// Priority Scheduling
void Scheduler::schedulePriority() {
    cout << "Scheduling vehicles using Priority Scheduling..." << endl;
    while (!priorityQueue.empty() && numPorts > 0) {
        Vehicle* vehicle = priorityQueue.top();
        priorityQueue.pop();

        vehicle->setChargingStatus(true);
        numPorts--;
        cout << "Charging High Priority Vehicle: " << vehicle->getVehicleID() << endl;

        // Simulate charging
        this_thread::sleep_for(chrono::seconds(2));
        vehicle->setChargingStatus(false);
        numPorts++;
        cout << "Finished Charging: " << vehicle->getVehicleID() << endl;
    }
}

// Round-Robin Scheduling
void Scheduler::scheduleRoundRobin() {
    cout << "Scheduling vehicles using Round-Robin..." << endl;
    while (!roundRobinQueue.empty() && numPorts > 0) {
        Vehicle* vehicle = roundRobinQueue.front();
        roundRobinQueue.pop();

        vehicle->setChargingStatus(true);
        numPorts--;
        cout << "Charging Vehicle: " << vehicle->getVehicleID() << " for time slice: " 
             << timeQuantum << " seconds." << endl;

        // Simulate time-slice charging
        this_thread::sleep_for(chrono::seconds(timeQuantum));

        vehicle->setBatteryLevel(vehicle->getBatteryLevel() + 10); // Increment battery
        vehicle->setChargingStatus(false);
        numPorts++;

        // Check if charging is complete
        if (vehicle->getBatteryLevel() < 100) {
            roundRobinQueue.push(vehicle); // Requeue the vehicle
            cout << "Requeued Vehicle: " << vehicle->getVehicleID() << " for next round." << endl;
        } else {
            cout << "Finished Charging: " << vehicle->getVehicleID() << endl;
        }
    }
}

// Display the queue status
void Scheduler::displayQueueStatus() {
    cout << "\nQueue Status:\n";

    // FCFS Queue
    cout << "FCFS Queue: ";
    queue<Vehicle*> tempFCFS = fcfsQueue;
    while (!tempFCFS.empty()) {
        cout << tempFCFS.front()->getVehicleID() << " ";
        tempFCFS.pop();
    }
    cout << endl;

    // Priority Queue
    cout << "Priority Queue: ";
    auto tempPriority = priorityQueue;
    while (!tempPriority.empty()) {
        cout << tempPriority.top()->getVehicleID() << " ";
        tempPriority.pop();
    }
    cout << endl;

    // Round Robin Queue
    cout << "Round-Robin Queue: ";
    queue<Vehicle*> tempRoundRobin = roundRobinQueue;
    while (!tempRoundRobin.empty()) {
        cout << tempRoundRobin.front()->getVehicleID() << " ";
        tempRoundRobin.pop();
    }
    cout << endl;
}

// Process Charging
void Scheduler::processCharging() {
    cout << "Processing Charging..." << endl;

    // Call scheduling functions
    schedulePriority();
    scheduleFCFS();
    scheduleRoundRobin();
}
