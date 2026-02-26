#include <iostream>

#include "neuronnet.h"
int main() {
    int layer_struct[] = {2, 3, 1};
    double input [] = {1.0,1.0};
    NeuronNet net(layer_struct,
                  sizeof(layer_struct)/sizeof(int));
    std::cout << net.forward(input);
    return 0;
}
