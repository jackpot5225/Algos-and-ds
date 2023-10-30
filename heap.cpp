#include <iostream>
#include <cstdlib>
#include <ctime>

const int size = 10;
int heap[size];
int *max = &heap[0];

void populate() {
    std::srand(std::time(NULL));
    for (int i = 0; i < size; ++i) {
        heap[i] = std::rand() % 10;
    }
}

void heapify(int index = 0) {
    int current = heap[index];
    int left = heap[index + 1];
    int right = heap[index + 2];

    if (index + 1 >= size) {
        left = 0;
    }

    if (index + 2 >= size) {
        right = 0;
    }

    return;
}

int main() {
    populate();
    heapify();
    return 0;
}