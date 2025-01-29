#ifndef QUEUEMANAGER_H
#define QUEUEMANAGER_H

#include "Vehicle.h"
#include <queue>
#include <vector>
#include <string>

class QueueManager {
private:
    std::queue<Vehicle*> fcfsQueue;           // FCFS Queue
    std::priority_queue<Vehicle*, std::vector<Vehicle*>, std::greater<Vehicle*>> priorityQueue; // Priority Queue
    std::queue<Vehicle*> roundRobinQueue;    // Round Robin Queue
    int roundRobinPointer;                   // Round robin pointer for managing round-robin scheduling

public:
    // Constructor
    QueueManager();

    // Destructor
    ~QueueManager();

    // Add a vehicle to the FCFS queue
    void addToFCFS(Vehicle* vehicle);

    // Add a vehicle to the priority queue
    void addToPriorityQueue(Vehicle* vehicle);

    // Add a vehicle to the Round Robin queue
    void addToRoundRobinQueue(Vehicle* vehicle);

    // Process the vehicle in FCFS queue
    void processFCFS();

    // Process the vehicle in Priority queue
    void processPriorityQueue();

    // Process the vehicle in Round Robin queue
    void processRoundRobinQueue();
9
    // Get the next vehicle for charging (round robin)
    Vehicle* getNextRoundRobinVehicle();

    // Display the queue statuses (for debugging purposes)
    void displayQueues() const;
};

#endif // QUEUEMANAGER_H
