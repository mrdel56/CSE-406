#include <iostream>
#include <algorithm>  // For sorting
using namespace std;

struct Process {
    int processNumber;    // Process ID
    int arrivalTime;      // Arrival Time
    int burstTime;        // Burst Time
    int completionTime;   // Completion Time
    int turnaroundTime;   // Turnaround Time
    int waitingTime;      // Waiting Time
};

bool compareByCompletionTime(const Process &a, const Process &b) {
    return a.completionTime < b.completionTime;
}

int main()
{
    Process processes[5];  // Array to store information of processes

    // Input the burst time and arrival time
    for (int i = 0; i < 5; i++)
    {
        processes[i].processNumber = i + 1;
        cout << "Enter burst time for Process P" << i + 1 << ": ";
        cin >> processes[i].burstTime;
        cout << "Enter arrival time for Process P" << i + 1 << ": ";
        cin >> processes[i].arrivalTime;
    }

    // Sort the processes based on arrival time
    sort(processes, processes + 5, [](const Process &a, const Process &b) {
        return a.arrivalTime < b.arrivalTime;
    });

    int currentTime = 0;  // Start time for execution
    bool completed[5] = {false};  // Track whether the process has been completed

    for (int i = 0; i < 5; i++) // Loop to process all 5 processes
    {
        int minBurstTime = 9999; // Initially a large value to find the min burst time
        int selectedProcess = -1;

        // Find the process that is ready and has the shortest burst time
        for (int j = 0; j < 5; j++)
        {
            if (!completed[j] && processes[j].arrivalTime <= currentTime && processes[j].burstTime < minBurstTime)
            {
                minBurstTime = processes[j].burstTime;
                selectedProcess = j;
            }
        }

        // If no process is ready, increment the current time and try again
        if (selectedProcess == -1)
        {
            currentTime++;
            i--;  // Decrease index so the loop doesn't skip processes
            continue;
        }

        // Process the selected process
        completed[selectedProcess] = true;
        currentTime += processes[selectedProcess].burstTime;  // Add burst time to current time
        processes[selectedProcess].completionTime = currentTime;  // Store the completion time

        // Calculate turnaround time and waiting time
        processes[selectedProcess].turnaroundTime = processes[selectedProcess].completionTime - processes[selectedProcess].arrivalTime;
        processes[selectedProcess].waitingTime = processes[selectedProcess].turnaroundTime - processes[selectedProcess].burstTime;
    }

    // Sort the processes by their completion time
    sort(processes, processes + 5, compareByCompletionTime);

    // Print the results
    cout << "\nProcess\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < 5; i++)
    {
        cout << "P" << processes[i].processNumber << "\t"
             << processes[i].arrivalTime << "\t\t"
             << processes[i].burstTime << "\t\t"
             << processes[i].completionTime << "\t\t"
             << processes[i].turnaroundTime << "\t\t"
             << processes[i].waitingTime << endl;
    }

    return 0;
}
