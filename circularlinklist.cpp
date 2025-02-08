#include <iostream>
#include <memory>  // For using smart pointers

// Node class for Circular Linked List
struct Node {
    int data;            // Person's position
    std::shared_ptr<Node> next; // Pointer to the next node

    Node(int val) : data(val), next(nullptr) {}
};

// Function to create the circular linked list of 'n' people
std::shared_ptr<Node> createCircularList(int n) {
    std::shared_ptr<Node> head = std::make_shared<Node>(1);
    std::shared_ptr<Node> prev = head;
    for (int i = 2; i <= n; ++i) {
        std::shared_ptr<Node> newNode = std::make_shared<Node>(i);
        prev->next = newNode;
        prev = newNode;
    }
    prev->next = head;  // Complete the circle
    return head;
}

// Function to visualize the current circle of people
void visualizeCircle(std::shared_ptr<Node> head) {
    std::shared_ptr<Node> temp = head;
    do {
        std::cout << "Person " << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    std::cout << "(back to Person " << head->data << ")\n";
}

// Josephus problem solution using circular linked list
int josephus(int n, int k) {
    std::shared_ptr<Node> head = createCircularList(n);

    // Visualize initial circle
    std::cout << "Initial circle of people:\n";
    visualizeCircle(head);

    // Start eliminating every k-th person
    std::shared_ptr<Node> current = head;
    std::shared_ptr<Node> prev = nullptr;
    
    while (current->next != current) {
        // Step through k-1 nodes to find the k-th node to remove
        for (int i = 1; i < k; ++i) {
            prev = current;
            current = current->next;
        }

        // Remove the k-th node (person)
        std::cout << "Eliminating Person " << current->data << "\n";
        prev->next = current->next;  // Bypass the eliminated node
        current = prev->next;  // Move to the next person

        // Visualize current circle after elimination
        visualizeCircle(current);
    }

    std::cout << "The last remaining person is Person " << current->data << "\n";
    return current->data;
}

int main() {
    int n, k;
    std::cout << "Enter the number of people: ";
    std::cin >> n;
    std::cout << "Enter the k-th person to be eliminated: ";
    std::cin >> k;

    int survivor = josephus(n, k);
    std::cout << "Survivor: Person " << survivor << std::endl;

    return 0;
}
