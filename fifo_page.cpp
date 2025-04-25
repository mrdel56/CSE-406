#include <iostream>
#include <queue>

using namespace std;

const int MAX = 100;

int fifo_page_replacement(int pages[], int n, int frame_size) {
    int memory[MAX];
    int mem_count = 0;
    queue<int> q;
    int miss = 0;

    for (int i = 0; i < n; ++i) {
        int page = pages[i];
        bool found = false;

        // Check if page is already in memory
        for (int j = 0; j < mem_count; ++j) {
            if (memory[j] == page) {
                found = true;
                break;
            }
        }

        if (!found) {
            miss++;

            if (mem_count < frame_size) {
                memory[mem_count++] = page;
                q.push(page);
            } else {
                int oldest = q.front();
                q.pop();

                for (int j = 0; j < mem_count; ++j) {
                    if (memory[j] == oldest) {
                        memory[j] = page;
                        break;
                    }
                }

                q.push(page);
            }
        }
    }

    return miss;
}

int main() {
    int n, frame_size;
    int pages[MAX];

    cout << "Enter total number of pages: ";
    cin >> n;

    cout << "Enter the page reference string (space-separated): ";
    for (int i = 0; i < n; ++i) {
        cin >> pages[i];
    }

    cout << "Enter the frame size: ";
    cin >> frame_size;

    int miss = fifo_page_replacement(pages, n, frame_size);
    cout << "Total number of page misses = " << miss << endl;

    return 0;
}
