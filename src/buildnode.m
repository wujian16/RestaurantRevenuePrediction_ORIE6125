function [ index, p, sd, sub1, sub2 ] = buildnode( X, y )
% function buidtree is designed to build a node for a decision regression tree 
% X includes all the independent variables
% y is the dependent variable we are interested in; in this problem, y is
% always the revenue

[x_row, x_col] = size(X);
sd = std(y);
index = 0;
for i = 1:x_col
    [p_i,sd_i,sub1_i,sub2_i]=split(X(:,i),y);
    if(sd_i<sd)
        sd = sd_i;
        index = i;
    end
end
[p,sd,sub1,sub2]=split(X(:,index),y);
end

