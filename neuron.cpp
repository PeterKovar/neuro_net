//
// Created by kova on 11.02.2026.
//
#include <cstdlib>
#include "neuron.h"

Neuron::Neuron() : weight((double)rand()/RAND_MAX*2-1),
                   bias((double)rand()/RAND_MAX*2-1),
                   output(0.0),
                   delta(0.0) {}