#include <iostream>
using namespace std;

// Node class
class Node {
public:
  int data;   // Data stored in the node
  Node *next; // Pointer to the next node

  // Constructor to initialize a node
  Node(int value) : data(value), next(nullptr) {}
};

// LinkedList class
class LinkedList {
private:
  Node *head; // Pointer to the first node in the list
  Node *tail; // Pointer to the last node in the list

public:
  // Constructor to initialize an empty linked list
  LinkedList() : head(nullptr), tail(nullptr) {}

  // Declare the functions for linked list operations
  void appendNode(int value) { // Append a node to the list
    Node *newNode = new Node(value);
    if (!head) {
      head = tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
  }

  void prependNode(int value) { // Prepend a node to the list
    Node *newNode = new Node(value);
    if (!head) {
      head = tail = newNode;
    } else {
      head->next = newNode;
      head = newNode;
    }
  }

  void insertNodeAfter(int afterValue,
                       int value) { // Insert after a given value
    Node *curNode = head;
    Node *newNode = new Node(value);
    if (!head) {
      head = tail = newNode;
    }

    while (curNode) {
      if (curNode->data == afterValue) {
        Node *sucNode = curNode->next;
        newNode->next = sucNode;
        curNode->next = newNode;
      }
      curNode = curNode->next;
    }
  }

  void removeNodeAfter(int afterValue) { // Remove after a given value
    if (tail->data == afterValue) {
      cout << "Cannot remove after the tail." << endl;
    }

    Node *curNode = head;
    while (curNode) {
      Node *sucNode = curNode->next;
      if (curNode->data == afterValue) {
        curNode->next = sucNode->next;
        delete sucNode;
        sucNode = nullptr;
      }
      curNode = curNode->next;
    }
  }

  void deleteLastNode() { // Delete the last node
    if (head == nullptr)
      return;
    if (head == tail) {
      delete head;
      head = nullptr;
      tail = nullptr;
    } else {
      Node *curNode = head;
      while (curNode->next != tail) {
        curNode = curNode->next;
      }
      delete tail;
      tail = curNode;
      curNode->next = nullptr;
    }
  }

  Node *searchNode(int value) { // Search for a node by value
    Node *curNode = head;
    while (curNode) {
      if (curNode->data == value) {
        cout << curNode->data << endl;
        return curNode;
      }
      curNode = curNode->next;
    }
    return 0;
  }

  void printList() { // Print all elements in the list
    Node *curNode = head;
    while (curNode) {
      cout << curNode->data << " ";
      curNode = curNode->next;
    }
    cout << endl;
  }
};

int main() {
  LinkedList list; // Create an empty linked list

  // Menu-driven program for testing linked list operations
  int choice, value, afterValue;
  do {
    cout << "\nMenu:" << endl;
    cout << "1. Append Node" << endl;
    cout << "2. Prepend Node" << endl;
    cout << "3. Insert Node After" << endl;
    cout << "4. Remove Node After" << endl;
    cout << "5. Delete Last Node" << endl;
    cout << "6. Search Node" << endl;
    cout << "7. Print List" << endl;
    cout << "8. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
      cout << "Enter value to append: ";
      cin >> value;
      list.appendNode(value); // To be implemented by students
      break;
    case 2:
      cout << "Enter value to prepend: ";
      cin >> value;
      list.prependNode(value); // To be implemented by students
      break;
    case 3:
      cout << "Enter value to insert after: ";
      cin >> afterValue;
      cout << "Enter value to insert: ";
      cin >> value;
      list.insertNodeAfter(afterValue, value); // To be implemented by students
      break;
    case 4:
      cout << "Enter value after which to remove node: ";
      cin >> afterValue;
      list.removeNodeAfter(afterValue); // To be implemented by students
      break;
    case 5:
      list.deleteLastNode(); // To be implemented by students
      break;
    case 6:
      cout << "Enter value to search: ";
      cin >> value;
      if (list.searchNode(value)) { // To be implemented by students
        cout << "Value found in the list." << endl;
      } else {
        cout << "Value not found in the list." << endl;
      }
      break;
    case 7:
      cout << "List contents: ";
      list.printList(); // To be implemented by students
      break;
    case 8:
      cout << "Exiting..." << endl;
      break;
    default:
      cout << "Invalid choice! Try again." << endl;
    }
  } while (choice != 8);

  return 0;
}
