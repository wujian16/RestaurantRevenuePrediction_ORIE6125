##K-Nearest Neighbor (KNN) Implementation  ##

###1. Introduction. ###

We implement the KNN algorithm in C++ and obtained predictions of revenues for the test data set. We also developed unittests for our cpp code. 


###2. Method.###

The KNN algorithm is one of the most basic and handy algorithm in machine learning. The idea is straight-forward. Consider each training datum as a pair $(x, r(x))$, where x is the vector that describes the restaurant, for instance location, type etc., and $r(x)$ is the revenue of the restaurant. For a datum in the testing set, denoted y, KNN computes its predicted revenue as $$r(y) = \mbox{avg}(\{r(x): x \mbox{ is one of the } K\mbox{ nearest neighbors of y} \}).$$ Here $K$ is a fixed number of  nearest neighbors that are taken into account. 

###3. Implementation in C++.###

We have the following source and header files associated to KNN implementation:
``` kNN.cpp, kNN.h, kNN_main.cpp, kNN_main.h, KNN_main_unittest.cpp```.

```kNN.cpp, kNN.h ``` define the class kNN, which computes the kNN prediction of testing data given training data.  

```kNN_main.cpp, kNN_main.h ``` have the main function and its header.  

```KNN_main_unittest.cpp``` has the unittests for each of the functions in ```kNN_main.cpp``` and member functions of class ```kNN```. 


---

Output of the algorithm is in file ```kNN_out.txt```, with predicted reveneus in original order of the testing data set. 


