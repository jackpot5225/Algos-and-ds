#include <iostream>

// below is the code to create a singly linked list

struct node { // defines what each node of the linked list will contain: some data and a pointer to the next node

    int value;
    node *next;
    
    node () { next = nullptr; }

};

class linkedList {

    public:

        node *head, *tail; // pointers to 2 nodes: the head and the tail of the linked list

        linkedList () { // constructor that creates an empty linked list

            head = nullptr;
            tail = nullptr;

        }

        ~linkedList () {

            node *travPtr = head; // creates a pointer to traverse and delete all nodes

            while (travPtr != nullptr) { // loops through and deletes all nodes

                node *temp = travPtr;
                travPtr = travPtr->next;
                delete temp;

            }
        }
        
        int getHead () { // function the returns the value stored at the head node

            return head->value;

        }

        int getTail () { // function the returns the value stored at the tail node

            return tail->value;

        }

        void appendNode (int value) { // function to add a node to the end of a linked list

            node *newNode = new node; // allocates memory on the heap and creates a new node
            newNode->value = value;
            newNode->next = nullptr;

            if (head == nullptr) { // checks if the linked list is empty, and if so adds new node as the first node

                head = newNode;
                tail = newNode;

            } else { // makes the tail of the linked list list point to the new node and makes said node the new tail of the linked list

                tail->next = newNode;
                tail = tail->next;

            }

        }

        void deleteNode (int value) { // function to delete a node of a linked list

            if (head->next == nullptr) { // checks if there is only one node in the linked list

                std::cout << "sorry bro can't delete anything there's only one node \n";
                return;

            }
            
            if (value == head->value) { // checks if the node to be deleted is the head

                node *oldHead = head;
                head = head->next;
                delete oldHead;
                return;

            }

            node *previousNode = head; // initalizes two pointers to nodes that will iterate through the linked list
            node *currentNode = head->next;

            while (currentNode != nullptr && currentNode->value != value) { // moves these pointers through the linked list

                previousNode = previousNode->next;
                currentNode = currentNode->next;

            }

            if (currentNode == nullptr) { // checks if the value specified isn't in the linked list

                std::cout << "sorry bro that value isn't in the linked list \n";
                return;

            }

            if (currentNode->value == value) {

                if (currentNode->next == nullptr) { // checks if the node to be deleted is the tail

                    node *oldTail = tail;
                    tail = previousNode;
                    previousNode->next = nullptr;
                    delete oldTail;

                } else {

                    previousNode->next = currentNode->next;
                    delete currentNode;

                }
            }
        }

        void print () { // function that prints all elements of a linked list

            node *travPtr = head; // creates a pointer to iterate through all nodes of the linked list
            
            if (travPtr == nullptr) { // checks if the linked list has no nodes

                std::cout << "sorry bro this linked list is empty \n";
                return;

            }
            
            std::cout << '[';
            
            while (true) {

                if(travPtr->next == nullptr) { // checks if the current node is the last in the linked list

                    std::cout << travPtr->value << ']' << '\n';
                    return;

                } else { // prints the value of the current node and moves to the next node

                    std::cout << travPtr->value << ", ";
                    travPtr = travPtr->next;

                }
            }
        }

        int numOfNodes () { // function that counts the number of elements in a linked list 

            node *travPtr = head;
            int count = 0;

            if (head == nullptr) { // checks if the list is empty

                return count;

            }

            while (true) {

                if (travPtr->next == nullptr) { // checks if the node that travPtr is pointing to is the last node

                    ++count;
                    return count;

                } else { // counts each node and makes travPtr point to the next node

                    ++count;
                    travPtr = travPtr->next;

                }
            }
        }

        void reverse (node *aNode) { // takes the head of the linked list and recursively reverses it
            
            node *previous = aNode;
            node *current = previous->next;
            
            if (current->next == nullptr) { // checks for base case

                head = current;
                current->next = previous;
                return;

            }

            reverse(previous->next); // calls itself

            current->next = previous; // makes the current node point to the previous node
            previous->next = nullptr;
            tail = previous;
            return;
        
        }
};

int main () {

    linkedList aList = linkedList();
    return 0;
    
}