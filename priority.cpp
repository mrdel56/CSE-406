#include <iostream>
using namespace std;

int main() {
    int n;
    
    // Taking the number of processes as input
    cout << "Enter the number of processes: ";
    cin >> n;
    
    int process[n], priority[n], AT[n], BT[n], CT[n], TAT[n], WT[n], remainingBT[n];
    
    for (int i = 0; i < n; i++) {
        cout << "Process " << i+1 << ":\n";
        cout << "Priority: ";
        cin >> priority[i];
        cout << "Arrival Time (AT): ";
        cin >> AT[i];
        cout << "Burst Time (BT): ";
        cin >> BT[i];
        process[i] = i + 1; 
        remainingBT[i] = BT[i]; 
    }

    int currentTime = 0;
    int completed = 0;

    while (completed != n) {
        int highestPriority = -1;
        int highestPriorityIndex = -1;

        for (int i = 0; i < n; i++) {
            
            if (AT[i] <= currentTime && remainingBT[i] > 0) {
                
                if (highestPriority == -1 || priority[i] > highestPriority) {
                    highestPriority = priority[i];
                    highestPriorityIndex = i;
                }
            }
        }

        if (highestPriorityIndex == -1) {
            currentTime++;  
        } else {
            remainingBT[highestPriorityIndex]--;  
            currentTime++;  

           
            if (remainingBT[highestPriorityIndex] == 0) {
                completed++;
                CT[highestPriorityIndex] = currentTime;  
                TAT[highestPriorityIndex] = CT[highestPriorityIndex] - AT[highestPriorityIndex];  
                WT[highestPriorityIndex] = TAT[highestPriorityIndex] - BT[highestPriorityIndex];  
            }
        }
    }

    cout << "\nProcess\tPriority\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << process[i] << "\t" << priority[i] << "\t\t" << AT[i] << "\t" << BT[i] << "\t" 
             << CT[i] << "\t" << TAT[i] << "\t" << WT[i] << endl;
    }

    return 0;
}
