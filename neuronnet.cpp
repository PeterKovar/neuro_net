//
// Created by kova on 18.02.2026.
//
#include <iostream>
#include "neuronnet.h"
#include <math.h>

NeuronNet::NeuronNet(int *layer_struct, int maxLayer) {
    numberLayers = maxLayer;
    layers = new Layer[numberLayers];  // Layer erzeugen
    // Neuronen erzeugen
    for (int i=0; i< maxLayer; ++i){
        layers[i].numberNeurons = layer_struct[i];
        layers[i].makeNeurons();
        if(i == 0) layers[i].numberInputs = 0;
        else layers[i].numberInputs = layers[i-1].numberNeurons;
    }
}
NeuronNet::~NeuronNet(){
    delete[] layers;
}
double NeuronNet::sigmoid(double x) {
    return 1.0 / (1.0 + exp(-x) );
}

double NeuronNet::forward(double *input) {
    // Setzen der Werte in den Input - Layer
    for(int i=0; i < layers[0].numberNeurons; ++i){
        layers[0].neurons[i].output = input[i];
    }

    for (int i=0; i<numberLayers; ++i){
        for(int j=0; j<layers[i].numberNeurons; ++j){
            double sum = 0.0;
            for(int k=0; k< layers[i].numberInputs; ++k){
               sum += layers[i-1].neurons[k].output *
                       layers[i].neurons[j].weight;
               sum += layers[i].neurons[j].bias;
            }
            layers[i].neurons[j].output = sigmoid(sum);
        }
    }
    return layers[numberLayers-1].neurons[0].output;
}