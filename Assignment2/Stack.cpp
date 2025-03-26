#include "Stack.h"

// Check if the stack is empty
bool Stack::empty() const {
    return stack.empty();
}

// Push an integer onto the stack
void Stack::push(int value) {
    stack.push_back(value);
}

// Pop an integer from the stack
void Stack::pop() {
    if (empty()) {
        throw out_of_range("Stack is empty");
    }
    stack.pop_back();
}

// Return the top element of the stack
int Stack::top() const {
    if (empty()) {
        throw out_of_range("Stack is empty");
    }
    return stack.back();
}

// Calculate the average value of the stack elements
double Stack::average() const {
    if (empty()) {
        throw out_of_range("Stack is empty");
    }
    double sum = 0;
    for (int value : stack) {
        sum += value;
    }
    return sum / stack.size();
}

// Print the stack (for debugging purposes)
void Stack::print() const {
    for (int value : stack) {
        cout << value << " -> ";
    }
    cout << "nullptr" << endl;
}