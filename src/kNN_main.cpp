//
//  main.cpp
//
//
//  Created by CHEUNG SIN SHUEN on 4/19/15.
//
//
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>
#include"kNN.h"
#include <time.h>
#include"kNN_main.h"

using namespace std;

/* moved to header
vector<double> get_revenue__TRAIN_CSV__();
vector<vector<double> > get_params_CSV_(string);
vector <double> naive_kNN(int num_of_NN, vector<vector <double> > test_data_param, vector<vector<double> > training_data_param, vector< double>  training_data_rev);
*/

int main(){

    /*  READING IN REVENUE*/

    vector<double> training_data_rev= get_revenue__TRAIN_CSV__();

    
    for (int i=0; i< training_data_rev.size();i++) cout<< training_data_rev[i]<<endl;

    /*cout<<"size of training_data_rev: "<< training_data_rev.size()<<endl;

    TESTED.
    */


    /*  READING IN DATA PARAMS*/

    vector< vector <double> > training_data_param  = get_params_CSV_("train_DR.csv");


    //cout<< training_data_param.size()<<"  "<<training_data_param[0].size() << endl;
    /*
    TESTED.
    */


    /* READING IN TESTING DATA PATAMS*/

    vector< vector <double> > test_data_param  = get_params_CSV_("test_DR.csv");

    /*
    cout<< test_data_param.size()<< "  "<<test_data_param[0].size() << endl;

    TESTED.
    */

    int k=6;

    /* Find Predicts for Test Set*/
    vector<double> naive_predicts = naive_kNN(k,test_data_param,training_data_param,training_data_rev);
    // naive_predicts has the predicted rev for the test set
    for (int i=0; i<naive_predicts.size(); i++) cout<<naive_predicts[i]<<endl;

    
    
    /* DO SOME CROSS-VALIDATION HERE  */
    
    
    /*for(int i=0; i<predicts.size();i++){
        cout<<predicts[i]<<endl;
    }*/
    
    
    /* choose part of the training data as testing set
    srand (time(NULL));
    vector<vector<double> > training_testing_param, training_training_param;
    vector<double> training_training_rev, training_testing_rev;
    for (int i=0; i< 137; i++){
        int irand=rand() %10;cout<<irand<<endl;
        if(irand >6) {
            training_testing_param.push_back(training_data_param[i]);
            training_testing_rev.push_back(training_data_rev[i]);
        }
        else
        {
            training_training_param.push_back(training_data_param[i]);
            training_training_rev.push_back(training_data_rev[i]);
        }
    }
    cout<< training_testing_param.size()<<"  "<< training_training_param.size()<<endl;
    vector<double> training_testing_rev_predicts=naive_kNN(k,training_testing_param,training_training_param,training_training_rev);
    for (int i=0; i<training_testing_rev.size(); i++){
        cout<<training_testing_rev_predicts[i]<< "   "<<training_testing_rev[i]<< endl;
    }
    */
    
    

}




    
vector <double> naive_kNN(int k, vector<vector <double> > test_data_param, vector<vector<double> > training_data_param, vector<double> training_data_rev){
    
    kNN my_kNN ( training_data_param[0].size(), training_data_rev.size(), training_data_param );

    //my_kNN.print_num();
    //my_kNN.print_dim();
    vector<double> predicts;

    for (int ind=0; ind < training_data_param.size();ind++){
    
        vector <double> distance = my_kNN.find_distance(k, test_data_param[ind]);
        //for (int k=0; k< distance.size();k++){cout<< distance[k]<<endl;}
        vector <int> index= my_kNN.find_smallest_k(k, distance, distance.size());
        //for (int k=0; k< index.size();k++){cout<< index[k]<<endl;}

        double est_rev= 0;
        for(int i=0; i< index.size(); i++){
            est_rev+=training_data_rev[index[i]];
        }
        predicts.push_back(est_rev/k);
        //cout<< predicts.back()<<endl<<endl;

    }
    return predicts;


}



// read from file "train.csv" to get revenues from the training set (ID: 0 - 136)
// TESTED.
vector<double> get_revenue__TRAIN_CSV__(){
    vector<double> data;
    ifstream infile("train.csv");
    string skip;
    getline(infile,skip); //skip first line

    while (infile)
    {
        string s;
        if (!getline( infile, s )) break;

        istringstream ss( s );

        while (ss)
        {
            string s;
            for(int i=0; i< 43; i++){getline( ss, s, ',' );  }
            data.push_back(stof(s));
            break;
        }

    }

    if (!infile.eof())
    {
        cerr << "Fooey!\n";
    }

    return data;

}



// read from file "train_DR.csv" to get the 3-dim params for training set (ID: 0 - 136)
// TESTED.
vector<vector<double> > get_params_CSV_(string arg){
    vector< vector <double> > data;
    ifstream infile( arg );

    while (infile)
    {
        string s;
        if (!getline( infile, s )) break;

        istringstream ss( s );
        vector<double> temp;
        while (ss)
        {
            string s;
            if(!getline( ss, s, ',' )) { break;}
            temp.push_back( stof(s) );
        }
        data.push_back(temp);
    }

    if (!infile.eof())
    {
        cerr << "Fooey!\n";
    }

    return data;

}














