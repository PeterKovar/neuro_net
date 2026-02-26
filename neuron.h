//
// Created by kova on 11.02.2026.
//
#ifndef NEURONET_NEURON_H
#define NEURONET_NEURON_H

class Neuron{
public:
    double output;    // Ausgang des Neurons
    double weight;    // Gewichtung des Eingangs
    double bias;      // Gleichverschiebung
    double delta;     // Abweichung

    Neuron();         // Konstruktor
};


#endif //NEURONET_NEURON_H
