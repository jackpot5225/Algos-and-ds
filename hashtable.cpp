#include <iostream>
#include <string>

struct entry { // a linked list node

    std::string key;
    int value;
    entry *next;

    entry () { next = nullptr; }

};

class hashtable {

    private:
        
        static constexpr int numOfBuckets = 10;
        entry *buckets[numOfBuckets]; // an array of linked list nodes

        int hash (std::string const &key) { // hashing function, maps the key to it's bucket

            int sum = 0;

            for (int i = 0; i < key.length(); ++i) {

                sum += int(key[i]);

            }
            
            int index = sum % numOfBuckets;
            return index;

        }

    public:

        hashtable () { buckets[numOfBuckets] = new entry[numOfBuckets]; } // constructor, creates an array of linked list nodes

        ~hashtable () { delete[] buckets[numOfBuckets]; } // destructor, frees up the memory used by all the linked list nodes

        void addElement (std::string const &key, int value) { // adds an element to the hashtable

            int index = hash(key); // runs the key through the hash function to get the index

            entry *newEntry = new entry; // dynamically allocates memory for a new node
            newEntry->key = key;
            newEntry->value = value;
            
            if (buckets[index] == nullptr) { // checks if the bucket has no nodes
                
                buckets[index] = newEntry;

            } else { // slaps the new node at the front of all other nodes in the bucket

                entry *oldEntry = buckets[index];
                newEntry->next = oldEntry;
                buckets[index] = newEntry;        

            }
        }

        void deleteElement (std::string const &key) { // function that deletes an element of the hashtable

            int index = hash(key); // passes the key through the hash function
            
            if (buckets[index]->key == key) { // checks if the first node in the bucket is to be deleted

                entry *temp = buckets[index];
                buckets[index] = buckets[index]->next;
                delete temp;
                return;

            }
            
            entry *previous = buckets[index]; // creates two pointers
            entry *current = previous->next;

            while (buckets[index] != nullptr && current != nullptr) { // loop that breaks if the bucket is empty or if there are no more nodes to loop through

                if (current->key == key) { 
               
                    break;
                
                } else {

                    previous = previous->next;
                    current = current ->next;

                }               
            }

            if (buckets[index] == nullptr || current == nullptr) { // checks if the bucket is empty, or if the while loop is done and the key is not found
                
                std::cout << "sorry bro, key not found \n"; 

            } else { // makes the previous node point tothe node after current, and deletes current

                previous->next = current->next;
                delete current;

            }
        }

        int getValue (std::string const &key) { // gets the value stored at a given key

            int index = hash(key);
            entry *travPtr = buckets[index]; // creates a pointer to traverse through all nodes in a bucket

            while (travPtr->key != key && travPtr != nullptr) { travPtr = travPtr->next; } // moves through the nodes until the key is found or there are no more modes

            if (travPtr->key == key) { // checks if the key has been found
                
                return travPtr->value;
                
            } else { // checks if he key has not been found

                std::cout << "sorry bro key not found \n";
                return -1;

            }
        }
};

int main () { // driver code

    hashtable aHashTable = hashtable();
    return 0;

}