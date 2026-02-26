//
// Created by kova on 11.02.2026.
//

#include "neuron.h"

#ifndef NEURONET_LAYER_H
#define NEURONET_LAYER_H
class Layer {
public:
    Neuron *neurons;
    int numberNeurons;
    int numberInputs;

    Layer();
    ~Layer();
    void makeNeurons();
};

#endif //NEURONET_LAYER_H
