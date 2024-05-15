#include <iostream>
#include <cmath>

//SigMod Aktivierungsfunktion
double sigmod(double x){
	return 1.0 / (1.0 + exp(-x));
}

// Neuronenklasse
class Neuron{
public:
    double weight, output;
    Neuron() : weight(0.5), output(0.0) {}
};
