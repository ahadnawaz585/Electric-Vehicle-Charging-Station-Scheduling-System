#ifndef CHARGINGPORT_H
#define CHARGINGPORT_H

#include "Vehicle.h"
#include <string>

// Represents an individual charging port
class ChargingPort {
private:
    int portID;                 // Unique identifier for the port
    bool isOccupied;            // Port occupancy status
    Vehicle* currentVehicle;    // Vehicle currently using the port

public:
    // Constructor
    ChargingPort(int id);

    // Getters
    int getPortID() const;
    bool getOccupiedStatus() const;
    Vehicle* getCurrentVehicle() const;

    // Setters
    void setOccupiedStatus(bool status);
    void assignVehicle(Vehicle* vehicle);
    void releaseVehicle();

    // Display port status
    void displayPortStatus() const;
};

#endif // CHARGINGPORT_H
