#include <iostream>
#include <cmath>
using namespace std;

//sort array in ascending order
void sortArray(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (arr[i] > arr[j]) {
                
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int n, head;
    cout << "Enter the number of disk requests: ";
    cin >> n;

    int requests[100]; 

    cout << "Enter the disk requests:\n";
    for (int i = 0; i < n; i++) {
        cin >> requests[i];
    }

    cout << "Enter the initial head position: ";
    cin >> head;

    sortArray(requests, n);

    
    int left[100], right[100];
    int leftCount = 0, rightCount = 0;

    for (int i = 0; i < n; i++) {
        if (requests[i] < head)
            left[leftCount++] = requests[i];
        else
            right[rightCount++] = requests[i];
    }

    
    for (int i = 0; i < leftCount / 2; i++) {
        int temp = left[i];
        left[i] = left[leftCount - i - 1];
        left[leftCount - i - 1] = temp;
    }

    int total_seek = 0;
    int current_head = head;

    cout << "\nSequence of head movement:\n";
    cout << current_head;

    // Move right
    for (int i = 0; i < rightCount; i++) {
        total_seek += abs(current_head - right[i]);
        cout << " ---> " << right[i];
        current_head = right[i];
    }

    // Move left
    for (int i = 0; i < leftCount; i++) {
        total_seek += abs(current_head - left[i]);
        cout << " ---> " << left[i];
        current_head = left[i];
    }

    cout << "\n\nTotal Seek Time: " << total_seek << endl;

    return 0;
}
