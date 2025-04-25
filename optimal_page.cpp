#include <iostream>

using namespace std;

const int MAX = 100;

// Function to find which page to replace
int findPageToReplace(int memory[], int capacity, int pages[], int totalPages, int currentIndex) {
    int farthestIndex = -1;
    int positionToReplace = -1;

    for (int i = 0; i < capacity; i++) {
        bool foundInFuture = false;

        for (int j = currentIndex + 1; j < totalPages; j++) {
            if (memory[i] == pages[j]) {
                if (j > farthestIndex) {
                    farthestIndex = j;
                    positionToReplace = i;
                }
                foundInFuture = true;
                break;
            }
        }

        // If the page is never used again, replace it immediately
        if (!foundInFuture) {
            return i;
        }
    }

    // If all pages are used again, replace the one used farthest in the future
    if (positionToReplace == -1)
        return 0; // Just a fallback (shouldn't usually happen)

    return positionToReplace;
}

// Optimal Page Replacement algorithm
void optimalPageReplacement(int pages[], int totalPages, int capacity) {
    int memory[MAX];
    int pageCount = 0;
    int pageFaults = 0;

    for (int i = 0; i < totalPages; i++) {
        int currentPage = pages[i];
        bool alreadyInMemory = false;

        // Check if current page is already in memory
        for (int j = 0; j < pageCount; j++) {
            if (memory[j] == currentPage) {
                alreadyInMemory = true;
                break;
            }
        }

        // If page is not in memory, it's a page fault
        if (!alreadyInMemory) {
            pageFaults++;

            // If there is space in memory, just add the page
            if (pageCount < capacity) {
                memory[pageCount] = currentPage;
                pageCount++;
            }
            // Otherwise, replace the best page using optimal logic
            else {
                int replacePos = findPageToReplace(memory, capacity, pages, totalPages, i);
                memory[replacePos] = currentPage;
            }
        }
    }

    cout << "Total Page Faults: " << pageFaults << endl;
}

int main() {
    int pages[MAX], totalPages, capacity;

    cout << "Enter total number of pages: ";
    cin >> totalPages;

    cout << "Enter the page reference string: ";
    for (int i = 0; i < totalPages; i++) {
        cin >> pages[i];
    }

    cout << "Enter the frame capacity: ";
    cin >> capacity;

    optimalPageReplacement(pages, totalPages, capacity);

    return 0;
}
