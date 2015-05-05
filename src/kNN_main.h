//
//  kNN_main.h
//  
//
//  Created by CHEUNG SIN SHUEN on 5/5/15.
//
//
#ifndef _kNN_main_h
#define _kNN_main_h




#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include"kNN.h"
#include <time.h>

vector<double> get_revenue__TRAIN_CSV__();
vector<vector<double> > get_params_CSV_(string);
vector <double> naive_kNN(int, vector<vector <double> > , vector<vector<double> > , vector< double>  );


#endif
