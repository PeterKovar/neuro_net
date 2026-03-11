#include <iostream>
#include <cmath>
#include "neuronnet.h"

int main() {
    // Neuronales Netz erzeugen
    int layer_struct[] = {2, 3,1};
    NeuronNet net(layer_struct,
                  sizeof(layer_struct)/sizeof(int));
    // Trainingsdaten UND Funktion
    double input [4][2] = {
            {0.0, 0.0},
            {0.0, 1.0},
            {1.0, 0.0},
            {1.0, 1.0}};

    double target[4][1] = {
            {0.0},
            {0.0},
            {0.0},
            {1.0}
    };
    double learning_rate = 0.5;
    int epochs = 5000;          // Trainingsdurchläufe

    for(int epoch=0; epoch < epochs; ++epoch) {
        double total_error = 0.0;
        for (int i = 0; i < 4; ++i) {

            net.train(input[i], target[i], learning_rate);

            //Fehler berechnen (MSE)
            double error =
                    pow(target[i][0] - net.forward(input[i]), 2);
            total_error += error;
        }
        // Nach 500 Iterationen Fehler ausgeben
        if(epoch % 500 == 0) {
        std::cout << "Epoche: " << epoch <<
        "Fehler: " << total_error / 4 << "\n";
        }
    }
    return 0;
}
