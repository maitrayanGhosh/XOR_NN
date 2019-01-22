#include <iostream>
#include <cmath>
using namespace std;

class Neuron{
public:
    float val;
    float weight1;
    float weight2;

    float bias;

    Neuron *first;
    Neuron *second;



    Neuron(float data){
        this->val=data;
    }
};

float sigmoid(float n);

int main() {

      Neuron  *x1=new Neuron(0);
      Neuron  *x2=new Neuron(0);
      Neuron  *h1=new Neuron(0);
      Neuron  *h2=new Neuron(0);
      Neuron  *O=new Neuron(0);


      x1->val=1;
      x2->val=1;


      x1->first=h1;
      x1->second=h2;
      x1->weight1=20;
      x1->weight2=-20;
      h1->bias=-10;


      x2->first=h1;
      x2->second=h2;
      x2->weight1=20;
      x2->weight2=-20;
      h2->bias=30;


      h1->weight1=20;
      h2->weight1=20;
      h1->first=O;
      h1->second=NULL;
      h2->first=O;
      h2->second=NULL;
      O->bias=-30;



      x1->first->val=sigmoid(((x1->val)*(x1->weight1))+((x2->val)*(x2->weight1))+(h1->bias));


      x2->second->val=sigmoid(((x1->val)*(x1->weight2))+((x2->val)*(x2->weight2))+(h2->bias));


      h1->first->val=sigmoid((h1->weight1*h1->val)+(h2->weight1*h2->val)+(O->bias));


      cout<<ceilf(O->val)<<" "<<"answer"<<endl;


}


float sigmoid(float n){
    float y= n / (1 + abs(n));
    return y;
}

