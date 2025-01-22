#include "ChargingStation.h"
#include <iostream>
using namespace std;

// Constructor
ChargingStation::ChargingStation(int numPorts, int timeQuantum) 
    : totalPorts(numPorts) {
    // Initialize charging ports
    for (int i = 1; i <= numPorts; i++) {
        chargingPorts.push_back(new ChargingPort(i));
    }

    // Initialize the scheduler
    scheduler = new Scheduler(numPorts, timeQuantum);
}

// Destructor
ChargingStation::~ChargingStation() {
    for (auto& port : chargingPorts) {
        delete port;
    }
    delete scheduler;
}

// Add a vehicle to the queue
void ChargingStation::addVehicleToQueue(Vehicle* vehicle, string queueType) {
    if (queueType == "FCFS") {
        scheduler->addVehicleToFCFS(vehicle);  // Corrected method name
    } else if (queueType == "Priority") {
        scheduler->addVehicleToPriorityQueue(vehicle);  // Corrected method name
    } else if (queueType == "RoundRobin") {
        scheduler->addVehicleToRoundRobin(vehicle);  // Corrected method name
    }
}

// Display the status of all charging ports
void ChargingStation::displayPortStatuses() const {
    cout << "Charging Port Statuses:" << endl;
    for (const auto& port : chargingPorts) {
        port->displayPortStatus();
    }
}

// Start the charging process
void ChargingStation::startCharging() {
    scheduler->processCharging();
}

// Process vehicle exits after charging
void ChargingStation::processExit() {
    cout << "Processing vehicle exits..." << endl;
    for (auto& port : chargingPorts) {
        if (port->getOccupiedStatus() && port->getCurrentVehicle()->getBatteryLevel() >= 100) {
            port->releaseVehicle();
        }
    }
}

// Display statistics for charging
void ChargingStation::displayStatistics() const {
scheduler->displayQueueStatus();
}
