#include <iostream>
#include <queue>
using namespace std;

struct Process {
    int id, arrivalTime, burstTime, remainingTime, completionTime, turnAroundTime, waitingTime;
};

void roundRobinScheduling(Process processes[], int n, int timeQuantum) {
    queue<int> q;
    int time = 0, completed = 0;
    float totalWaitingTime = 0, totalTurnAroundTime = 0;
    
    for (int i = 0; i < n; i++)
        processes[i].remainingTime = processes[i].burstTime;
    
    q.push(0);
    int index = 1;
    while (completed < n) {
        int i = q.front(); q.pop();
        
        if (processes[i].remainingTime > timeQuantum) {
            time += timeQuantum;
            processes[i].remainingTime -= timeQuantum;
        } else {
            time += processes[i].remainingTime;
            processes[i].remainingTime = 0;
            processes[i].completionTime = time;
            processes[i].turnAroundTime = processes[i].completionTime - processes[i].arrivalTime;
            processes[i].waitingTime = processes[i].turnAroundTime - processes[i].burstTime;
            totalWaitingTime += processes[i].waitingTime;
            totalTurnAroundTime += processes[i].turnAroundTime;
            completed++;
        }
        
        for (; index < n && processes[index].arrivalTime <= time; index++)
            q.push(index);
        
        if (processes[i].remainingTime > 0)
            q.push(i);
        
        if (q.empty() && index < n)
            q.push(index++);
    }
    
    cout << "\nProcess\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++)
        cout << "P" << processes[i].id << "\t" << processes[i].arrivalTime << "\t" << processes[i].burstTime << "\t"
             << processes[i].completionTime << "\t" << processes[i].turnAroundTime << "\t" << processes[i].waitingTime << "\n";
    
    cout << "\nAverage Waiting Time: " << totalWaitingTime / n;
    cout << "\nAverage Turnaround Time: " << totalTurnAroundTime / n << endl;
}

int main() {
    int n, timeQuantum;
    cout << "Enter number of processes: ";
    cin >> n;
    Process processes[n];
    
    cout << "Enter time quantum: ";
    cin >> timeQuantum;
    
    cout << "Enter arrival time and burst time for each process:\n";
    for (int i = 0; i < n; i++) {
        cout << "Process " << i + 1 << ": ";
        processes[i].id = i + 1;
        cin >> processes[i].arrivalTime >> processes[i].burstTime;
    }
    
    roundRobinScheduling(processes, n, timeQuantum);
    return 0;
}
