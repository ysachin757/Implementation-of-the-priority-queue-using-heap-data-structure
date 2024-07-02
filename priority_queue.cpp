#include <bits/stdc++.h>
#include <stdexcept>
#include <vector>

using namespace std;

// Define a structure to hold priority queue elements
struct PriorityQueueElement {
    int priority;
    string value;  // Assuming string for example, can be any type

    // Constructor for PriorityQueueElement
    PriorityQueueElement(int priority, string value) : priority(priority), value(value) {}

    // Overloading operator < for comparing elements
    bool operator<(const PriorityQueueElement& other) const {
        // Higher priority elements should have higher priority value
        return priority > other.priority;  // Min-heap behavior (smallest priority on top)
    }
};

// Define a priority queue using a vector-based min-heap
class PriorityQueue {
private:
    vector<PriorityQueueElement> heap;

    // Helper function to maintain heap property after insertion or deletion
    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[parent] < heap[index])
                break;
            swap(heap[index], heap[parent]);
            index = parent;
        }
    }

    // Helper function to maintain heap property after deletion
    void heapifyDown(int index) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < heap.size() && heap[left] < heap[smallest])
            smallest = left;
        if (right < heap.size() && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    // Method to insert element into priority queue
    void insert(int priority, string value) {
        heap.push_back(PriorityQueueElement(priority, value));
        heapifyUp(heap.size() - 1);
    }

    // Method to delete element with highest priority (minimum priority value)
    string deleteMin() {
        if (heap.empty()) {
            throw runtime_error("Priority queue is empty");
        }
        string minValue = heap[0].value;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return minValue;
    }

    // Method to check if priority queue is empty
    bool isEmpty() {
        return heap.empty();
    }

    // Method to get the size of the priority queue
    int size() {
        return heap.size();
    }
};

// Function to display menu and handle user input
void displayMenu(PriorityQueue& pq) {
    cout << "Priority Queue Server" << endl;
    cout << "---------------------" << endl;
    cout << "1. Insert Element" << endl;
    cout << "2. Delete Minimum Element" << endl;
    cout << "3. Display Queue Size" << endl;
    cout << "4. Quit" << endl;
    cout << "---------------------" << endl;

    int choice;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            int priority;
            string value;
            cout << "Enter priority and value to insert: ";
            cin >> priority >> value;
            pq.insert(priority, value);
            cout << "Element inserted successfully!" << endl;
            break;
        }
        case 2: {
            try {
                string minValue = pq.deleteMin();
                cout << "Deleted minimum element: " << minValue << endl;
            } catch (runtime_error& e) {
                cout << "Error: " << e.what() << endl;
            }
            break;
        }
        case 3: {
            cout << "Queue size: " << pq.size() << endl;
            break;
        }
        case 4: {
            cout << "Exiting program..." << endl;
            exit(0);
        }
        default:
            cout << "Invalid choice. Please try again." << endl;
    }

    // Prompt user for next action
    cout << endl;
    displayMenu(pq);
}

// Main function to start the server
int main() {
    PriorityQueue pq;

    // Display menu and handle user actions
    displayMenu(pq);
    pq.insert(3, "task1");
    pq.insert(1, "task2");
    pq.insert(2, "task3");
    pq.insert(5, "task4");
    pq.insert(4, "task5");
    pq.insert(0, "task6");

    // Delete elements until empty
    while (!pq.isEmpty()) {
        cout << pq.deleteMin() << endl;
    }

    return 0;


    return 0;
}
