#include "ChargingPort.h"
#include <iostream>
using namespace std;

// Constructor
ChargingPort::ChargingPort(int id) 
    : portID(id), isOccupied(false), currentVehicle(nullptr) {}

// Getters
int ChargingPort::getPortID() const {
    return portID;
}

bool ChargingPort::getOccupiedStatus() const {
    return isOccupied;
}

Vehicle* ChargingPort::getCurrentVehicle() const {
    return currentVehicle;
}

// Setters
void ChargingPort::setOccupiedStatus(bool status) {
    isOccupied = status;
}

void ChargingPort::assignVehicle(Vehicle* vehicle) {
    if (!isOccupied) {
        currentVehicle = vehicle;
        isOccupied = true;
        cout << "Vehicle " << vehicle->getVehicleID() << " assigned to Port " << portID << endl;
    } else {
        cout << "Port " << portID << " is already occupied!" << endl;
    }
}

void ChargingPort::releaseVehicle() {
    if (isOccupied && currentVehicle != nullptr) {
        cout << "Releasing Vehicle " << currentVehicle->getVehicleID() 
             << " from Port " << portID << endl;
        currentVehicle = nullptr;
        isOccupied = false;
    } else {
        cout << "Port " << portID << " is already free!" << endl;
    }
}

// Display port status
void ChargingPort::displayPortStatus() const {
    cout << "Port " << portID << " Status: ";
    if (isOccupied) {
        cout << "Occupied by Vehicle " << currentVehicle->getVehicleID() << endl;
    } else {
        cout << "Available" << endl;
    }
}
