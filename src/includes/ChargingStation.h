#ifndef CHARGINGSTATION_H
#define CHARGINGSTATION_H

#include "ChargingPort.h"
#include "Scheduler.h"
#include <vector>
#include <string>

// Represents the central charging station
class ChargingStation {
private:
    std::vector<ChargingPort*> chargingPorts; // List of charging ports
    Scheduler* scheduler;                    // Scheduler instance
    int totalPorts;                          // Total number of ports

public:
    // Constructor
    ChargingStation(int numPorts, int timeQuantum);

    // Destructor
    ~ChargingStation();

    // Add a vehicle to the queue
    void addVehicleToQueue(Vehicle* vehicle, const std::string& algorithm);

    // Display the status of all charging ports
    void displayPortStatuses() const;

    // Start the charging process
    void startCharging();

    // Process vehicle exits after charging
    void processExit();

    // Display statistics for charging
    void displayStatistics() const;
};

#endif // CHARGINGSTATION_H
