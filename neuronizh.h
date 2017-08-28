#ifndef NEURONIZH_H
#define NEURONIZH_H
#include <stdio.h>
#include <deque>
using namespace std;

class neuronIzh
{
public:
    neuronIzh();
    neuronIzh(int, bool, int,int , int, int);
    int ID;
    bool is_exitory;
    deque<float> input;

};

#endif // NEURONIZH_H
