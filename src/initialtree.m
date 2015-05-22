%Initialization for decision regression tree
%Dimension Reduction from 37 to 3.

X=csvread('train1.csv',1,5);
date=X(:,1);
bigcity=X(:,2);
IL=X(:,3);
FC=X(:,4);
revenue=X(:,42);

X=csvread('train_DR.csv',0,0);

X=[date,bigcity,IL,FC,X];
