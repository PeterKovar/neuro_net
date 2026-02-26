//
// Created by kova on 18.02.2026.
//
#include "layer.h"
#ifndef NEURONET_NEURONNET_H
#define NEURONET_NEURONNET_H
class NeuronNet {
public:
    int numberLayers;
    Layer *layers;
    NeuronNet(int *layer_struct, int maxLayer);
    ~NeuronNet();
    double forward(double *);
    double sigmoid(double x);
};



#endif //NEURONET_NEURONNET_H
