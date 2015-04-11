%Dimension Reduction from 37 to 3.
clear
clc

X1=csvread('train.csv',1,5);
X1=X1(:,1:37);
Mu1=mean(X1);
Sigma1=cov(X1);
[W1,D1] = eigs(Sigma1,3);
W1=W1./repmat(sqrt(sum(W1.^2,1)),37,1);
Y1 = (X1-repmat(Mu1,[137,1]))*W1;

csvwrite('train_DR.csv',Y1);