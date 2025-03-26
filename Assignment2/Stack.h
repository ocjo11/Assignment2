#include <vector>
#include <stdexcept>
#include <iostream>

using namespace std;

// Stack class with seperate cpp file
class Stack {
private:
    vector<int> stack;

public:
    // Check if the stack is empty
    bool empty() const;

    // Push an integer onto the stack
    void push(int value);

    // Pop an integer from the stack
    void pop();

    // Return the top element of the stack
    int top() const;

    // Calculate the average value of the stack elements
    double average() const;

    // Print the stack (for debugging purposes)
    void print() const;
};
