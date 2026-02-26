//
// Created by kova on 18.02.2026.
//
#include "layer.h"

Layer::Layer() {}         // Standard Konstruktor
// Erzeugung der Neuronen im Layer
void Layer::makeNeurons() {
    neurons = new Neuron[numberNeurons];
}
Layer::~Layer() {
    delete[] neurons;    // Speicher freigeben
}