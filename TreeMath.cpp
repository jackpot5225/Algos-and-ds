#include <iostream>

// caculates how many feet of lights are needed assuming the tree is a perfect cone.
//WARNING: formula rounds down for partial wraps and there need to be at least 2 full wraps for the fomula to work.
//Actual length of lights needed is likey higher than calculated due to the rounding down and the fact that trees aren't perfect cones.
float TreeMath(double radius, double height, double seperation) {
    float zero = 0;
    float *PastValue = &zero;
    float *NewValue;
    for (int i = 0; i < ((height / seperation) - 1); ++i) {
        *NewValue = (*PastValue + ((3.141 * radius) / height) * ((height - (i * seperation)) + (height - ((i + 1) * seperation))));
        *PastValue = *NewValue;
    }
    std::cout << *NewValue << " feet of lights are needed.";
    return *NewValue;
}

int main() {
    TreeMath(11.15, 25, 0.5);
    return 0;
}