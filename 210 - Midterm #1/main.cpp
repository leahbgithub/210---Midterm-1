// 210 - Midterm 1 - Leah Balakrishnan

#include <iostream>

using namespace std;

const int MIN_NR = 10, MAX_NR = 99, MIN_LS = 5, MAX_LS = 20;

class DoublyLinkedList {
private:
    struct Node {
        int data; // date contained by the node
        Node* prev; // pointer to the node before
        Node* next; // pointer to next node
        
        // Constructor --- Intializes new node with a value as well could possibly set the prev and next pointers from above
        Node(int val, Node* p = nullptr, Node* n = nullptr) {
            data = val; // Set data of node to value passed in the constructor
            prev = p; // set "prev" pointer to point to previous node or later on nullptr
            next = n; // set "next" pointer to point to next node or later on nullptr
        }
    };
    Node* head; // Pointer --- Points to first node within the list
    Node* tail; // Pointer ---- Points to the last node within the list
public:
    // Constructor --- Initializes an empty list
    DoublyLinkedList() { head = nullptr; tail = nullptr; }

    // Will Check if a position is valid
    void insert_after(int value, int position) {
        if (position < 0) {
            cout << "Position must be >= 0." << endl;
            return;
        }
        // This will create new node with a specific given value
        Node* newNode = new Node(value);
        // This occurs if the list is empty, and will make the new node both the head as well as the tail
        if (!head) {
            head = tail = newNode;
            return;
        }
        // This will traverse the list which will find the position after which to input a new node
        Node* temp = head;
        for (int i = 0; i < position && temp; ++i)
            temp = temp->next;
        // This occurs if the position ever exceeds the size of the list
        if (!temp) {
            cout << "Position exceeds list size. Node not inserted.\n";
            delete newNode; // Helps avoid leak of memory
            return;
        }
        // Inserts a new node after a position found
        newNode->next = temp->next;
        newNode->prev = temp;
        // This will then update the pointers of adjacent nodes
        if (temp->next)
            temp->next->prev = newNode;
        else
            tail = newNode; // This updates the tail if the new node ends up being the last node
        // Links "temp" to new node
        temp->next = newNode;
    }

    // Method -- Which will delete first presence of "value" from within the list
    void delete_val(int value) {
        if (!head) return; // do not do anything if list ends up being empty
        Node* temp = head;
        // Find the node that has the value we need to delete
        while (temp && temp->data != value)
            temp = temp->next;
        if (!temp) return; // do not do anything if value not found
        if (temp->prev)
            temp->prev->next = temp->next;
        else
            head = temp->next; // Update head if first node ends up being deleted
        if (temp->next)
            temp->next->prev = temp->prev;
        else
            tail = temp->prev; // This will update the tail if last node has been deleted
        delete temp; // node is deleted
    }

    // Method -- Delete node at position "pos"
    void delete_pos(int pos) {
        if (!head) {
            cout << "List is empty." << endl; // prints list is empty
            return;
        }
        if (pos == 1) {
            pop_front(); // if last position is deleted, use pop_back() function
            return;
        }
        Node* temp = head; // Start at head of list
        for (int i = 1; i < pos; i++) {
            if (!temp) { // Only if end of list is reached, then another position wouldnt work
                cout << "Position doesn't exist." << endl;
                return;
            }
            else
                temp = temp->next; // move to next node
        }
        if (!temp) {
            cout << "Position doesn't exist." << endl;
            return;
        }
        if (!temp->next) {
            pop_back();
            return;
        }
        Node* tempPrev = temp->prev;
        tempPrev->next = temp->next;
        temp->next->prev = tempPrev;
        delete temp; // This will delete the node at the position
    }

    void push_back(int v) {
        Node* newNode = new Node(v);
        if (!tail)
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    //Method --- Adds new node with value of "v" to back of list
    void push_front(int v) {
        Node* newNode = new Node(v);
        if (!head) // if list empty, make new node the head and the tail
            head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode; // This will update the tail pointer
        }
    }
    
    // Method --- Adds new node with value "v" to front of the list
    void pop_front() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        if (head->next) {
            head = head->next;
            head->prev = nullptr; // updates head's prev pointer to a nullptr
        }
        else
            head = tail = nullptr; // only if list is empty
        delete temp; // deletes old head node
    }

    // Method --- Removes last node from list
    void pop_back() {
        if (!tail) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = tail;
        if (tail->prev) {
            tail = tail->prev;
            tail->next = nullptr; // tail's pointer is updated to nullptr
        }
        else
            head = tail = nullptr; // if list ever becomes empty
        delete temp; // deletes old tail node aga
    }

    // Destructor -- This will delete all nodes in the list
    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp; // deletes the node one at a time
        }
    }

    // Method --- prints list from end to front
    void print() {
        Node* current = head;
        if (!current) {
            cout << "List is empty." << endl;
            return;
        }
        while (current) {
            cout << current->data << " "; // will print the information stored for each individual node
            current = current->next; // proceeds to next node
        }
        cout << endl;
    }

    // Method -- Same as print() however will be from front to end
    void print_reverse() {
        Node* current = tail;
        if (!current) {
            cout << "List is empty." << endl;
            return;
        }
        while (current) {
            cout << current->data << " "; // Print information stored for each node
            current = current->prev; // Will move to the next node
        }
        cout << endl;
    }
    
    void every_other_element() {
        
        while(current != nullptr) {
            if (counter % 2 == 1) {
                cout << current-> data << " ";
            }
            current = current->next;
            counter++;
        }
        cout << endl;
    }
};

int main() {
    cout << MIN_NR + MIN_LS + MAX_NR + MAX_LS; // dummy statement to avoid compiler warning
    return 0;
}

