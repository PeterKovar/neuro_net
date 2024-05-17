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

// Layerklasse
class Layer{
public:
    Neuron *neurons;    //Zeiger auf die Neuronenklasse
    int numNeurons;  //Anzahl der Neuronen
	int numInputs;
    Layer(){}
	//Neuronen erzeugen
	void makeNeurons() {
	    neurons = new Neuron[numNeurons];
	}
    ~Layer() {              //Destruktor
        delete[] neurons;   //Dynamischen Speicher freigeben
    }
};

class NeuronNet{
public:
    Layer *layers;      //Zeiger auf die Layerklasse
    int numLayer;
    
	NeuronNet(int *netStructure){
        //numLayer = sizeof(lay_struc)/sizeof(int); ACHTUNG ZEIGER 
	    numLayer = 3;   //NOCH ÄNDERN
		//Layer erzeugen
		layers = new Layer[numLayer];  // 3 Layer erzeugen layers[0 .. 2]
		//Neuronen im Layer erzeugen
		for(int i=0; i<numLayer; ++i){
            layers[i].numNeurons = netStructure[i];  //Anzahl Neuronen ueberg.
			layers[i].makeNeurons();   // Neuronen erzeugen
			if (i==0) layers[i].numInputs=0;
			else layers[i].numInputs = layers[i-1].numNeurons; //Anz. Eing.
        }
    }
    ~NeuronNet(){
        delete[] layers;
    }

    void forward(double *input){    //Vorwärts Durchlauf
        //Setze Werte in den Eingangslayer
		for (int i=0; i<layers[0].numNeurons; ++i){   
            layers[0].neurons[i].output = input[i];
        }
        //Berechne Ausgaben für jede Schicht
        for(int i=1; i<numLayer; ++i){   //Layer festlegen
            for(int j=0; j<layers[i].numNeurons; ++j){     //Neuronen festlegen
                double sum = 0.0;
                for(int k=0; k<layers[i].numInputs; ++k){      //Summe berechnen
                    //Alle Eingänge mit Gewicht mult. und aufsummieren
					sum += layers[i-1].neurons[k].output * layers[i].neurons[j].weight;
                }
				layers[i].neurons[j].output = sigmod(sum);
            }
        }
    }
};



int main(int argc, char ** argv){

		int netStructure[] = {2, 3, 1}; //Layerstruktur 
		NeuronNet net(netStructure);
		//std::cout << sizeof(netStructure)/sizeof(int) << "\n"; //Achtung binaer
        double neur_input[] = {0.5, 0.8};
		net.forward(neur_input);
		std::cout << net.layers[2].neurons[0].output;

    return 0;
}