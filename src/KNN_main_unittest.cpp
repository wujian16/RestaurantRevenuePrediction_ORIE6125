//
//  KNN_main_unittest.cpp
//  
//
//  Created by CHEUNG SIN SHUEN on 5/5/15.
//
//
//#include <limits.h>

#include<limits.h>
#include"kNN.h"
#include"kNN_main.h"

#include "gtest/gtest.h"


//using namespace std;

vector<double> training_data_rev= get_revenue__TRAIN_CSV__();


TEST(test_get_revenue_TRAIN_CSV, Case1){

    EXPECT_EQ(training_data_rev.size(),137);
    EXPECT_EQ(training_data_rev[0],5653753);
    EXPECT_EQ(training_data_rev[99],13575224);

}

vector< vector <double> > training_data_param  = get_params_CSV_("train_DR.csv");

TEST(test_get_params_CSV_, input_train_DR){
    EXPECT_EQ(training_data_param.size(),137);
    EXPECT_EQ(training_data_param[0].size(),3);
    EXPECT_NEAR(training_data_param[0][0],3.5203, 0.0001);

}

vector< vector <double> > test_data_param  = get_params_CSV_("test_DR.csv");

TEST(test_get_params_CSV_, input_test_DR){
    EXPECT_EQ(test_data_param.size(),100000);
    EXPECT_EQ(test_data_param[0].size(),3);
    EXPECT_NEAR(test_data_param[0][0],-6.9824,0.0001);

}   


TEST(KNN_class_test, Create_KNN){
    kNN my_kNN ( training_data_param[0].size(), training_data_rev.size(), training_data_param );
    EXPECT_EQ(my_kNN.get_num(),137);
    EXPECT_EQ(my_kNN.get_dim(),3);
    EXPECT_NEAR(my_kNN.get_position(0,0),training_data_param[0][0],0.00001);

}


