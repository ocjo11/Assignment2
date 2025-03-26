#include <stdexcept>
#include <iostream>

using namespace std;

// Single linked class with all functions in the same header file since using template Item_Type
template <typename Item_Type>
class Single_Linked_List {
private:
    struct Node {
        Item_Type data;
        Node* next;
        Node(const Item_Type& item) : data(item), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    size_t num_items;

public:
    // Constructor
    Single_Linked_List() : head(nullptr), tail(nullptr), num_items(0) {}

    // Destructor
    ~Single_Linked_List() {
        while (!empty()) {
            pop_front();
        }
    }

    // Push an item to the front of the list
    void push_front(const Item_Type& item) {
        Node* new_node = new Node(item);
        new_node->next = head;
        head = new_node;
        if (tail == nullptr) {
            tail = new_node;
        }
        num_items++;
    }

    // Push an item to the back of the list
    void push_back(const Item_Type& item) {
        Node* new_node = new Node(item);
        if (tail == nullptr) {
            head = tail = new_node;
        }
        else {
            tail->next = new_node;
            tail = new_node;
        }
        num_items++;
    }

    // Remove the item at the front of the list
    void pop_front() {
        if (empty()) {
            throw out_of_range("List is empty");
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        num_items--;
        if (head == nullptr) {
            tail = nullptr;
        }
    }

    // Remove the item at the back of the list
    void pop_back() {
        if (empty()) {
            throw out_of_range("List is empty");
        }
        if (head == tail) {
            delete head;
            head = tail = nullptr;
        }
        else {
            Node* temp = head;
            while (temp->next != tail) {
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = nullptr;
        }
        num_items--;
    }

    // Return the item at the front of the list
    Item_Type front() const {
        if (empty()) {
            throw out_of_range("List is empty");
        }
        return head->data;
    }

    // Return the item at the back of the list
    Item_Type back() const {
        if (empty()) {
            throw out_of_range("List is empty");
        }
        return tail->data;
    }

    // Check if the list is empty
    bool empty() const {
        return num_items == 0;
    }

    // Insert an item at a specific index
    void insert(size_t index, const Item_Type& item) {
        if (index >= num_items) {
            push_back(item);
            return;
        }
        if (index == 0) {
            push_front(item);
            return;
        }
        Node* new_node = new Node(item);
        Node* temp = head;
        for (size_t i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
        num_items++;
    }

    // Remove an item at a specific index
    bool remove(size_t index) {
        if (index >= num_items) {
            return false;
        }
        if (index == 0) {
            pop_front();
            return true;
        }
        Node* temp = head;
        for (size_t i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        Node* to_delete = temp->next;
        temp->next = to_delete->next;
        if (to_delete == tail) {
            tail = temp;
        }
        delete to_delete;
        num_items--;
        return true;
    }

    // Find the position of the first occurrence of an item
    size_t find(const Item_Type& item) const {
        Node* temp = head;
        size_t index = 0;
        while (temp != nullptr) {
            if (temp->data == item) {
                return index;
            }
            temp = temp->next;
            index++;
        }
        return num_items;
    }

    // Return the size of the list
    size_t size() const {
        return num_items;
    }

    // Print the list of values
    void print() const {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }

};