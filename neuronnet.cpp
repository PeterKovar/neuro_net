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
double NeuronNet::sigmoid_derivative(double x) {
    return x * (1.0 - x);
}

double NeuronNet::forward(double *input) {
    // Setzen der Werte in den Input - Layer
    for(int i=0; i < layers[0].numberNeurons; ++i){
        layers[0].neurons[i].output = input[i];
    }

    for (int i=1; i<numberLayers; ++i){
        for(int j=0; j<layers[i].numberNeurons; ++j){
            double sum = 0.0;
            for(int k=0; k< layers[i].numberInputs; ++k){
               sum += layers[i-1].neurons[k].output *
                       layers[i].neurons[j].weight;
            }
            sum += layers[i].neurons[j].bias;
            layers[i].neurons[j].output = sigmoid(sum);
        }
    }
    return layers[numberLayers-1].neurons[0].output;
}

void NeuronNet::train(double *input, double *target, double learning_rate){
    //Einmal durchrechnen
    forward(input);
    //Fehler fuer den OutputLayer berechnen
    for(int i=0; i < layers[numberLayers-1].numberNeurons; ++i){
        double error = target[i] - layers[numberLayers-1].neurons[i].output;
        layers[numberLayers-1].neurons[i].delta =
                error * sigmoid_derivative(layers[numberLayers-1].neurons[i].output);
    }
    // Fehler zurueckrechnen (Backpropagation)
    for(int i = numberLayers-2; i > 0; --i){
        for(int j=0; j<layers[i].numberNeurons;j++){
            double error = 0.0;
            for(int k=0; k< layers[i+1].numberNeurons; ++k) {
                error += layers[i+1].neurons[k].delta * layers[i+1].neurons[k].weight;
            }
            layers[i].neurons[j].delta = error
                    * sigmoid_derivative(layers[i].neurons[j].output);
        }
    }
    //Gewichte und Bias anpassen
    for(int i=1; i< numberLayers; ++i){
        for(int j=0; j<layers[i].numberNeurons; ++j){
            for (int k=0; k< layers[i].numberInputs; ++k){
                layers[i].neurons[j].weight += learning_rate *
                        layers[i].neurons[j].delta * layers[i-1].neurons[k].output;
            }
            layers[i].neurons[j].bias +=
                    learning_rate * layers[i].neurons[j].delta;
        }
    }
}
