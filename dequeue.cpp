#include <iostream>

class Dequeue { // needs fixing, super buggy

    private:

        int top, bottom;
        static constexpr int max = 20;

    public:

        int array[10];

        Dequeue () {

            top = -1;
            bottom = -1;

        }
        
        void pushTop (int value) {

            if (top >= max - 1) {

                std::cout << "Dequeue Overflow \n";

            } else if (top == -1) {

                ++bottom;
                ++top;
                array[top] = value;

            } else {

                ++top;
                array[top] = value;

            }

        }

        void pushBottom (int value) {

            if (bottom == 0) {

                std::cout << "Dequeue Overflow \n";

            } else if (bottom == -1) {

                ++top;
                ++bottom;
                array[bottom] = value;

            } else {

                --bottom;
                array[bottom] = value;

            }

        }

        void popTop () {

            if (top == -1) {

                std::cout << "Dequeue Underflow \n";

            } else if (top == bottom) {

                top = bottom = -1;

            } else {

                --top;

            }

        }

        void popBottom () {

            if (bottom == -1) {

                std::cout << "Dequeue Underflow \n";

            } else if (top == bottom) {

                top = bottom = -1;

            } else {

                ++bottom;

            }

        }

        int getTop () {

            if (top == -1) {

                std::cout << "Dequeue is empty \n";
                return -1;

            }

            return array[top];

        }

        int getBottom () {

            if (bottom == -1) {

                std::cout << "Dequeue is empty \n";
                return -1;

            }

            return array[bottom];

        }

};

int main () {

    Dequeue d = Dequeue();
    return 0;

}