#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

// Represents an Electric Vehicle in the system
class Vehicle {
private:
    std::string vehicleID;  // Unique identifier for the vehicle
    int batteryLevel;       // Battery level percentage (0-100)
    int priority;           // Priority level (1=High, 2=Medium, 3=Low)
    bool isCharging;        // Indicates if the vehicle is currently charging

public:
    // Constructor
    Vehicle(const std::string& id, int battery, int prio);

    // Getters
    std::string getVehicleID() const;
    int getBatteryLevel() const;
    int getPriority() const;
    bool getChargingStatus() const;

    // Setters
    void setBatteryLevel(int battery);
    void setPriority(int prio);
    void setChargingStatus(bool status);

    // Utility Methods
    void displayInfo() const; // Prints vehicle details to the console
};

#endif // VEHICLE_H
