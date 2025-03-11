#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;


int findClosestRequest(const vector<int>& requests, int currentHeadPosition) {
    int minSeek = INT_MAX;
    int closestIndex = -1;

    for (size_t i = 0; i < requests.size(); ++i) {
        int seek = abs(requests[i] - currentHeadPosition);
        if (seek < minSeek) {
            minSeek = seek;
            closestIndex = i;
        }
    }

    return closestIndex;
}


void sstf(vector<int> requests, int head) {
    int totalSeekTime = 0;
    int currentHeadPosition = head;

    cout << "SSTF Disk Scheduling Order: " << endl;

    
    cout << currentHeadPosition;

    while (!requests.empty()) {
        int closestIndex = findClosestRequest(requests, currentHeadPosition);
        int closestRequest = requests[closestIndex];

        
        int seekTime = abs(closestRequest - currentHeadPosition);
        totalSeekTime += seekTime;

        
        currentHeadPosition = closestRequest;

        
        cout << " --> " << currentHeadPosition;

       
        requests.erase(requests.begin() + closestIndex);
    }

    cout << endl << "Total Seek Time: " << totalSeekTime << endl;
}

int main() {
    vector<int> requests;
    int n, initialHeadPosition;

    
    cout << "Enter the number of disk requests: ";
    cin >> n;

    
    cout << "Enter the disk requests: ";
    for (int i = 0; i < n; ++i) {
        int request;
        cin >> request;
        requests.push_back(request);
    }

    
    cout << "Enter the initial head position: ";
    cin >> initialHeadPosition;

    
    sstf(requests, initialHeadPosition);

    return 0;
}