#include <iostream>

using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// LinkedList class
class LinkedList {
public:
    LinkedList() : head(nullptr) {}

    // Insert at the end of the list
    void insert(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        display();
    }

    // Delete a node by value
    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            display();
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;

        while (temp != nullptr && temp->data != value) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Value not found in list!" << endl;
            return;
        }

        prev->next = temp->next;
        delete temp;
        display();
    }

    // Display the list with visual arrows
    void display() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) {
                cout << " -> ";  // Arrow for visual representation
            }
            temp = temp->next;
        }
        cout << endl;
    }

private:
    Node* head;
};

int main() {
    LinkedList list;
    int choice = 0, value;

    do {
        cout << "\n1. Insert\n2. Delete\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input please try a valid number " << endl;
            continue;
        }

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input please enter an integer " << endl;
                continue;
            }
            list.insert(value);
            break;
        case 2:
            cout << "Enter value to delete: ";
            cin >> value;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input please enter an integer " <<endl;
                continue;
            }
            list.deleteNode(value);
            break;
        case 3:
            list.display();
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 4);

    return 0;
}
