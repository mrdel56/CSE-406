#include <iostream>
#include <algorithm>  
using namespace std;

struct Process {
    int processNumber;   
    int arrivalTime;      
    int burstTime;        
    int completionTime;   
    int turnaroundTime;   
    int waitingTime;      
};

bool compareByCompletionTime(const Process &a, const Process &b) {
    return a.completionTime < b.completionTime;
}

int main()
{
    Process processes[6];  

    
    for (int i = 0; i < 6; i++)
    {
        processes[i].processNumber = i + 1;
        cout << "Enter burst time for Process P" << i + 1 << ": ";
        cin >> processes[i].burstTime;
        cout << "Enter arrival time for Process P" << i + 1 << ": ";
        cin >> processes[i].arrivalTime;
    }

    
    sort(processes, processes + 6, [](const Process &a, const Process &b) {
        return a.arrivalTime < b.arrivalTime;
    });

    int currentTime = 0;  
    bool completed[6] = {false};  

    for (int i = 0; i < 6; i++) 
    {
        int minBurstTime = 9999; 
        int selectedProcess = -1;

        
        for (int j = 0; j < 6; j++)
        {
            if (!completed[j] && processes[j].arrivalTime <= currentTime && processes[j].burstTime < minBurstTime)
            {
                minBurstTime = processes[j].burstTime;
                selectedProcess = j;
            }
        }

        
        if (selectedProcess == -1)
        {
            currentTime++;
            i--;  
            continue;
        }

        
        completed[selectedProcess] = true;
        currentTime += processes[selectedProcess].burstTime;  
        processes[selectedProcess].completionTime = currentTime;  

       
        processes[selectedProcess].turnaroundTime = processes[selectedProcess].completionTime - processes[selectedProcess].arrivalTime;
        processes[selectedProcess].waitingTime = processes[selectedProcess].turnaroundTime - processes[selectedProcess].burstTime;
    }

    
    sort(processes, processes + 6, compareByCompletionTime);

    
    cout << "\nProcess\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < 6; i++)
    {
        cout << "P" << processes[i].processNumber << "\t"
             << processes[i].arrivalTime << "\t"
             << processes[i].burstTime << "\t"
             << processes[i].completionTime << "\t"
             << processes[i].turnaroundTime << "\t"
             << processes[i].waitingTime << endl;
    }

    return 0;
}
