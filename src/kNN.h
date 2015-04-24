#ifndef __KNN_H_INCLUDED__
#define __KNN_H_INCLUDED__

#include<stdio.h>
#include<iostream>
#include<vector>


using namespace std;
//using std::vector;


class kNN {

private:
    vector< vector<double> > data ; //  parameters of the restautants in the training set.
    int dim; // dim = dimension of parameters
    int num; // num = number of restaurants in training set
public:
    kNN(int, int, vector< vector<double> > );
    vector<double> find_distance(int, vector <double>);
    const vector<int> find_smallest_k(int,vector <double>,int);

    void print_dim(){cout<< dim << endl;}

    void print_num(){cout<< num << endl;}

    void print_data_size(){cout<< data.size() << endl;}

};



/*
#use min_heap to find the first
class min_heap{

private:
    double * ptr;
    int *order;
    int dim;


public:
    min_heap(double *loc, int size){
        p=new double [size];
        dim=size;
        order=new int[size];
        for (int i=0;i<dim; i++){   *(order+i)=0;}
        for (int i=0; i< dim; i++){  * }

    }
}
*/



#endif
