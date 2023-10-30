#include <iostream>

int MDarray[3][3] = { // creates a multidimensional array, first brackets defines number of rows, and the second defines the number of columns
                    {1, 1, 1},
                    {2, 2, 2},
                    {3, 3, 3},
                    };

void print (int array[3][3]) { //uses nested for loops to print all values of the multidimensional array, i acesses rows and j acesses columns

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            
            std::cout << array[i][j] << '\n';
        
        }
    }

}

int main () {

    print(MDarray);
    return 0;

}