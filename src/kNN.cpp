#include<unordered_map>
#include "kNN.h"
#include <algorithm>
#include<cmath>


using namespace std;

//using std::vector;


kNN::kNN(int dimension, int number_of_instances, vector< vector<double> > vdata  ) {
    data.resize(number_of_instances, vector<double> (dimension));
    for (int i=0; i<number_of_instances; i++){
        for (int j=0; j<dimension; j++){
            data[i][j] = vdata[i][j];
        }

    }
    //vector < vector<double> > mdata =vdata;
    //data=&mdata;
    dim=dimension;
    num=number_of_instances;
    cout<<"kNN created with dimension = "<< dim <<" and number of params = "<<num<<endl;

}


    /*find the k nearest neighbors and return their IDs (starting 0 to num-1)*/

vector<double> kNN::find_distance(int k, vector <double> guy){
        vector <double> distance ;
        for (int i=0; i< num; i++){
            distance.push_back(0);
        }
        /*cout<<"find_distance initialized"<<endl;
        cout<<"num = "<<num<<endl;
        cout<<"dim = "<<dim<<endl;
        cout<<"guy size = "<<guy.size()<<endl;
        cout<<"data size = "<< data.size()<<endl;*/
        for (int i=0; i< num; i++){
            for (int j=0; j< dim; j++) {
                    distance[i]+= (guy[j]-data[i][j])*(guy[j]-data[i][j]);
            }
            distance[i]=sqrt(distance[i]);
            // distance[i] is the squared distance from ID=i to guy.
        }
        //cout<<"found distance"<<endl;
        return distance;
    
}

    /*find_smallest_k finds the smallest k numbers in the given array of doubles and return their IDs as a vector.
       -- loc contains the distances from each known restaurants to the restaurant of interest
       -- num_loc has the number of elements in array loc, which is supposed be the same number as member num
       -- k is the number of nearest neighbors
       The function returns the IDs of the nearest k restaurants, and it is done by using a heap
    */
const vector<int> kNN::find_smallest_k(int k,vector <double> loc, int number_loc ){
        // myhash records the ID of each member in loc
        unordered_map<double, int>  myhash;
        for(int i=0; i< number_loc; i++){
            myhash[loc[i]]=i;
        }
        // p is a  copy of loc
        vector <double> p =loc;
        make_heap(p.begin(), p.end());
        sort_heap(p.begin(), p.end());
        vector<int> result;
        for (int i=0; i< k; i++){
            result.push_back(myhash[p[i]]);
        }
        //cout<<"found smallest k"<<endl;
        return result;
}

