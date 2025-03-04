#include <iostream>
#include <cstdlib> 

using namespace std;

int main() {
    int n, head, totalSeekTime = 0;

    
    cout << "Enter the number of disk requests: ";
    cin >> n;

    int requests[n];  

    cout << "Enter the disk request sequence:\n";
    for (int i = 0; i < n; i++) {
        cin >> requests[i];
    }

    cout << "Enter the initial position of the disk head: ";
    cin >> head;

    
    for (int i = 0; i < n; i++) {
        totalSeekTime += abs(requests[i] - head);  
        head = requests[i];  
    }

    
    cout << "Total seek time: " << totalSeekTime << endl;

    return 0;
}
