#include <iostream>

// below is the code to create a singly linked list

struct node { // defines what each node of the linked list will contain: some data and a pointer to the next node
    int value;
    node *next;
};

class linkedList {
    private:
        node *head, *tail; // pointers to 2 nodes: the head and the tail of the linked list
    public:
        linkedList() { // constructor that creates an empty linked list
            head = nullptr;
            tail = nullptr;
        }
        
        void appendNode(int value) { // function to add a node to the end of a linked list
            node *newNode = new node; // allocates memory on the heap and creates a new node
            newNode->value = value;
            newNode->next = nullptr;

            if(head == nullptr) { // checks if the linked list is empty, and if so adds new node as the first node
                head = newNode;
                tail = newNode;
            } else { // makes the tail of the linked list list point to the new node and makes said node the new tail of the linked list
                tail->next = newNode;
                tail = tail->next;
            }
        }

        void print() { // function that prints all elements of a linked list
            node *travPtr = head; // creates a pointer to iterate through all nodes of the linked list
            std::cout << '[';
            while(true) {
                if(travPtr->next == nullptr) { // checks if the current node is the last in the linked list
                    std::cout << travPtr->value << ']';
                    break;
                } else { // prints the value of the current node and moves to the next node
                    std::cout << travPtr->value << ", ";
                    travPtr = travPtr->next;
                }
            }
        }
};

int main() {
    linkedList aList = linkedList();
    aList.appendNode(1);
    aList.appendNode(2);
    aList.appendNode(3);
    aList.print();
    return 0;
}