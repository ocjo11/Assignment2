#include <iostream>
#include "SingleLinkedList.h"
#include "Stack.h"

using namespace std;

int main() {
    // Test Single_Linked_List
    cout << "===== Testing Single_Linked_List =====" << endl;
    Single_Linked_List<int> list;

    // Test push_front
    cout << "\nTesting push_front:" << endl;
    list.push_front(10);
    list.push_front(20);
    list.push_front(30);
    list.print(); // Output: 30 -> 20 -> 10 -> nullptr

    // Test push_back
    cout << "\nTesting push_back:" << endl;
    list.push_back(40);
    list.push_back(50);
    list.print(); // Output: 30 -> 20 -> 10 -> 40 -> 50 -> nullptr

    // Test pop_front
    cout << "\nTesting pop_front:" << endl;
    list.pop_front();
    list.print(); // Output: 20 -> 10 -> 40 -> 50 -> nullptr

    // Test pop_back
    cout << "\nTesting pop_back:" << endl;
    list.pop_back();
    list.print(); // Output: 20 -> 10 -> 40 -> nullptr

    // Test front and back
    cout << "\nTesting front and back:" << endl;
    cout << "Front: " << list.front() << endl; // Output: Front: 20
    cout << "Back: " << list.back() << endl;   // Output: Back: 40

    // Test insert
    cout << "\nTesting insert:" << endl;
    list.insert(1, 15); // Insert 15 at index 1
    list.print(); // Output: 20 -> 15 -> 10 -> 40 -> nullptr

    // Test remove
    cout << "\nTesting remove:" << endl;
    list.remove(2); // Remove item at index 2 (value 10)
    list.print(); // Output: 20 -> 15 -> 40 -> nullptr

    // Test find
    cout << "\nTesting find:" << endl;
    size_t pos = list.find(15);
    if (pos < list.size()) {
        cout << "Item 15 found at position: " << pos << endl; // Output: Item 15 found at position: 1
    }
    else {
        cout << "Item 15 not found" << endl;
    }

    // Test size
    cout << "\nTesting size:" << endl;
    cout << "Size of the list: " << list.size() << endl; // Output: Size of the list: 3

    // Test empty
    cout << "\nTesting empty:" << endl;
    cout << "Is the list empty? " << (list.empty() ? "Yes" : "No") << endl; // Output: Is the list empty? No

    // Test Stack
    cout << "\n\n===== Testing Stack =====" << endl;
    Stack stack;

    // Test empty
    cout << "\nTesting empty:" << endl;
    cout << "Is the stack empty? " << (stack.empty() ? "Yes" : "No") << endl; // Output: Is the stack empty? Yes

    // Test push
    cout << "\nTesting push:" << endl;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    cout << "Stack after pushes: ";
    stack.print(); // Output: Stack after pushes: 10 -> 20 -> 30 -> 40 -> nullptr

    // Test pop
    cout << "\nTesting pop:" << endl;
    stack.pop();
    cout << "Stack after pop: ";
    stack.print(); // Output: Stack after pop: 10 -> 20 -> 30 -> nullptr

    // Test top
    cout << "\nTesting top:" << endl;
    cout << "Top of the stack: " << stack.top() << endl; // Output: Top of the stack: 30

    // Test average
    cout << "\nTesting average:" << endl;
    cout << "Average value of the stack elements: " << stack.average() << endl; // Output: Average value of the stack elements: 20

    return 0;
}