#include "Vehicle.h"
#include <iostream>

// Constructor
Vehicle::Vehicle(const std::string& id, int battery, int prio)
    : vehicleID(id), batteryLevel(battery), priority(prio), isCharging(false) {}

// Getters
std::string Vehicle::getVehicleID() const {
    return vehicleID;
}

int Vehicle::getBatteryLevel() const {
    return batteryLevel;
}

int Vehicle::getPriority() const {
    return priority;
}

bool Vehicle::getChargingStatus() const {
    return isCharging;
}

// Setters
void Vehicle::setBatteryLevel(int battery) {
    if (battery >= 0 && battery <= 100) {
        batteryLevel = battery;
    } else {
        std::cerr << "Error: Battery level must be between 0 and 100." << std::endl;
    }
}

void Vehicle::setPriority(int prio) {
    if (prio >= 1 && prio <= 3) {
        priority = prio;
    } else {
        std::cerr << "Error: Priority must be 1 (High), 2 (Medium), or 3 (Low)." << std::endl;
    }
}

void Vehicle::setChargingStatus(bool status) {
    isCharging = status;
}

// Utility Methods
void Vehicle::displayInfo() const {
    std::cout << "Vehicle ID: " << vehicleID << std::endl;
    std::cout << "Battery Level: " << batteryLevel << "%" << std::endl;
    std::cout << "Priority: " << (priority == 1 ? "High" : priority == 2 ? "Medium" : "Low") << std::endl;
    std::cout << "Charging Status: " << (isCharging ? "Charging" : "Waiting") << std::endl;
}
