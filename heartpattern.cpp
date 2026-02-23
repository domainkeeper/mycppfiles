#include<iostream>
using namespace std;

int main() {
    int numLayers;
    cin >> numLayers;

    for (int layer = 0; layer < numLayers; layer++) {
        for (int space = 0; space <= numLayers - layer; space++) {
            cout << " ";
        }
        for (int star = 0; star < layer; star++) {
            if (numLayers-layer <= (numLayers/2)-2){
                int f = 0;
                if ( (layer - star == (numLayers/2) && numLayers - layer > 0 ) || (layer - star == (numLayers/2)-1 && numLayers - layer > 1 ) || (layer - star == (numLayers/2)-2 && numLayers - layer > 2 ) || (layer - star == (numLayers/2)-3 && numLayers - layer > 3 ) || (layer - star == (numLayers/2)-4 && numLayers - layer > 4 ) || (layer - star == (numLayers/2) - 5 && numLayers - layer > 5))
                    {
                        cout << "  ";
                    }
                
                else if (star != layer/2){
                    cout << "* ";
                }
            
                
                
            }
        }
        cout << endl;
    }

    for (int layer = 0; layer < numLayers; layer++) {
        for (int space = 0; space < layer; space++) {
            cout << "  ";
        }
        for (int star = layer; star <= numLayers - layer; star++) {
            cout << "* ";
        }
        cout << endl;
    }

    return 0;
}
