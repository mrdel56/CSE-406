#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

void cscanDiskScheduling(int request_sequence[], int n, int initial_head) {
    int current_head = initial_head;
    int total_seektime = 0;
    int left[100], right[100]; 
    int left_count = 0, right_count = 0;
    
    
    sort(request_sequence, request_sequence + n);

    
    for (int i = 0; i < n; i++) {
        if (request_sequence[i] < current_head)
            left[left_count++] = request_sequence[i];
        else
            right[right_count++] = request_sequence[i];
    }

    
    for (int i = 0; i < right_count; i++) {
        total_seektime += abs(right[i] - current_head);  
        current_head = right[i]; 
    }

    
    if (right_count > 0) {
        total_seektime += abs(current_head - right[right_count - 1]);
        current_head = right[right_count - 1];
    }

  
    for (int i = 0; i < left_count; i++) {
        total_seektime += abs(left[i] - current_head); 
        current_head = left[i]; 
    }

    
    cout << "Total Seek Operations: " << total_seektime << endl;

    
    cout << "Sequence of head movement: ";
    
    
    for (int i = 0; i < right_count; i++) {
        cout << right[i];
        if (i != right_count - 1) cout << " ---> "; 
    }

    
    for (int i = 0; i < left_count; i++) {
        cout << left[i];
        if (i != left_count - 1) cout << " ---> "; 
    }

    cout << endl;
}

int main() {
    int head, n;
    
    
    cout << "Enter the initial head position: ";
    cin >> head;

    
    cout << "Enter the total number of requests: ";
    cin >> n;

    int request_sequence[100]; 
    cout << "Enter the disk request sequence:\n";
    for (int i = 0; i < n; i++) {
        cin >> request_sequence[i]; 
    }

    cscanDiskScheduling(request_sequence, n, head);

    return 0;
}
