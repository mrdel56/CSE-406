#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cout << "Enter number of disk requests: ";
    cin >> n;

    int requests[100];
    for (int i = 0; i < n; i++) {
        cout << "Enter request " << i + 1 << ": ";
        cin >> requests[i];
    }

    int head;
    cout << "Enter initial head position: ";
    cin >> head;

    int done[100] = {0}; // 0 = not done, 1 = done
    int totalSeek = 0;

    cout << "\nSSTF Disk Scheduling Order:\n" << head;

    for (int count = 0; count < n; count++) {
        int minDist = 9999;
        int index = -1;

        // Find nearest request
        for (int i = 0; i < n; i++) {
            if (!done[i]) {
                int dist = abs(head - requests[i]);
                if (dist < minDist) {
                    minDist = dist;
                    index = i;
                }
            }
        }

        // Move head to closest request
        totalSeek += abs(head - requests[index]);
        head = requests[index];
        done[index] = 1;

        cout << " --> " << head;
    }

    cout << "\nTotal Seek Time: " << totalSeek << endl;

    return 0;
}
