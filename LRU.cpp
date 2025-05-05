#include <iostream>
using namespace std;

const int MAX = 100; // Maximum number of reference pages

// Function to check if a page is in the frame
bool isInFrame(int frame[], int frameSize, int page) {
    for (int i = 0; i < frameSize; i++) {
        if (frame[i] == page) return true;
    }
    return false;
}

// Function to find index of least recently used page
int findLRU(int recent[], int frame[], int frameSize) {
    int minTime = recent[0], pos = 0;
    for (int i = 1; i < frameSize; i++) {
        if (recent[i] < minTime) {
            minTime = recent[i];
            pos = i;
        }
    }
    return pos;
}

int main() {
    int frameSize, n, time = 0;
    int refStr[MAX], frame[10], recent[10];
    int pageHit = 0, pageMiss = 0;

    cout << "Enter the number of frames: ";
    cin >> frameSize;

    cout << "Enter the number of pages in reference string: ";
    cin >> n;

    cout << "Enter the page reference string:\n";
    for (int i = 0; i < n; i++) {
        cin >> refStr[i];
    }

    // Initialize frame with -1 (empty)
    for (int i = 0; i < frameSize; i++) {
        frame[i] = -1;
        recent[i] = 0;
    }

    cout << "\nLRU Page Replacement Algorithm:\nReference String: ";
    for (int i = 0; i < n; i++) cout << refStr[i] << " | ";
    cout << "\n";

    for (int i = 0; i < n; i++) {
        int page = refStr[i];
        bool hit = false;

        // Check if page is already in frame
        for (int j = 0; j < frameSize; j++) {
            if (frame[j] == page) {
                time++;
                recent[j] = time;
                pageHit++;
                hit = true;
                break;
            }
        }

        if (!hit) {
            pageMiss++;
            time++;
            bool inserted = false;

            // Check for empty slot
            for (int j = 0; j < frameSize; j++) {
                if (frame[j] == -1) {
                    frame[j] = page;
                    recent[j] = time;
                    inserted = true;
                    break;
                }
            }

            // If no empty slot, replace LRU
            if (!inserted) {
                int lruIndex = findLRU(recent, frame, frameSize);
                frame[lruIndex] = page;
                recent[lruIndex] = time;
            }
        }

        cout << "\n" << (hit ? "Hit" : "Miss") << " [ ";
        for (int j = 0; j < frameSize; j++) {
            if (frame[j] == -1) cout << "_ ";
            else cout << frame[j] << " ";
        }
        cout << "]";
    }

    cout << "\n\nTotal Page Hits: " << pageHit;
    cout << "\nTotal Page Faults: " << pageMiss << "\n";

    return 0;
}
