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
            // Aufruf Training
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

    // Netz testen
    std::cout << "Trainierte Netz\n";
    for (int i=0; i< 4; i++){

        std::cout << "Eingang: " << input[i][0] << "," << input[i][1]
        << "-->" << net.forward(input[i]) << "\n";
    }
//net.layers[2].neurons[0].output
    return 0;
}
