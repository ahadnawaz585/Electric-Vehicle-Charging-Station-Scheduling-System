#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "Vehicle.h"
#include <queue>
#include <vector>
#include <string>

// Represents the core scheduling system for EVs
class Scheduler {
private:
    // Queues for scheduling algorithms
    std::queue<Vehicle*> fcfsQueue;                 // First-Come, First-Serve queue
    std::priority_queue<Vehicle*, std::vector<Vehicle*>, 
        bool(*)(Vehicle*, Vehicle*)> priorityQueue; // Priority scheduling queue
    std::queue<Vehicle*> roundRobinQueue;           // Round-Robin queue

    int timeQuantum;    // Time slice for Round-Robin
    int numPorts;       // Total available charging ports

public:
    // Constructor
    Scheduler(int numPorts, int timeQuantum);

    // Add vehicle to respective queue
    void addVehicleToFCFS(Vehicle* vehicle);
    void addVehicleToPriorityQueue(Vehicle* vehicle);
    void addVehicleToRoundRobin(Vehicle* vehicle);

    // Scheduling Algorithms
    void scheduleFCFS();           // First-Come, First-Serve
    void schedulePriority();       // Priority Scheduling
    void scheduleRoundRobin();     // Round-Robin Scheduling

    // Helper methods
    void displayQueueStatus();     // Show the current status of all queues
    void processCharging();        // Allocate charging ports and handle charging
};

#endif // SCHEDULER_H
