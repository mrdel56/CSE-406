#include <iostream>
using namespace std;

int main() {
    int n;
    
    // Taking the number of processes as input
    cout << "Enter the number of processes: ";
    cin >> n;
    
    int process[n], priority[n], AT[n], BT[n], CT[n], TAT[n], WT[n], remainingBT[n];
    
    // Taking process, priority, arrival time (AT), and burst time (BT) as input from the user
    cout << "Enter Process ID, Priority, Arrival Time (AT), and Burst Time (BT) for each process:\n";
    for (int i = 0; i < n; i++) {
        cout << "Process " << i+1 << ":\n";
        cout << "Priority: ";
        cin >> priority[i];
        cout << "Arrival Time (AT): ";
        cin >> AT[i];
        cout << "Burst Time (BT): ";
        cin >> BT[i];
        process[i] = i + 1; // Process ID starting from 1
        remainingBT[i] = BT[i]; // Set the remaining burst time equal to the initial burst time
    }

    int currentTime = 0;
    int completed = 0;

    while (completed != n) {
        int highestPriority = -1;
        int highestPriorityIndex = -1;

        for (int i = 0; i < n; i++) {
            // Check if process is ready to execute (arrival time <= current time and remaining burst time > 0)
            if (AT[i] <= currentTime && remainingBT[i] > 0) {
                // Find the process with the highest priority
                if (highestPriority == -1 || priority[i] > highestPriority) {
                    highestPriority = priority[i];
                    highestPriorityIndex = i;
                }
            }
        }

        if (highestPriorityIndex == -1) {
            currentTime++;  // If no process is ready to execute, move time forward
        } else {
            remainingBT[highestPriorityIndex]--;  // Decrement remaining burst time
            currentTime++;  // Move the current time forward

            // When the process finishes execution
            if (remainingBT[highestPriorityIndex] == 0) {
                completed++;
                CT[highestPriorityIndex] = currentTime;  // Completion time
                TAT[highestPriorityIndex] = CT[highestPriorityIndex] - AT[highestPriorityIndex];  // Turnaround time
                WT[highestPriorityIndex] = TAT[highestPriorityIndex] - BT[highestPriorityIndex];  // Waiting time
            }
        }
    }

    // Output the results
    cout << "\nProcess\tPriority\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << process[i] << "\t" << priority[i] << "\t\t" << AT[i] << "\t" << BT[i] << "\t" 
             << CT[i] << "\t" << TAT[i] << "\t" << WT[i] << endl;
    }

    return 0;
}
