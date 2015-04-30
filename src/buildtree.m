function buildtree( X, y, depth, flag )
% function buidtree is designed to build a decision regression tree 
% X includes all the independent variables
% y is the dependent variable we are interested in; in this problem, y is
% always the revenue
n = length(y);
min_node = 13;
sigma = 2e5;
fprintf('The depth of the node is %d. The value of the node is %f. The flag is %d.\n', depth, mean(y), flag);
if(n>=min_node)
    [index,p,sd,sub1,sub2]=buildnode(X,y);
    if(sd<sigma)
        return;
    end
    y_left=y(sub1); y_right=y(sub2);
    X_left=X(sub1,:); X_right=X(sub2,:);
    fprintf('The column is %d,the value for splitting is %f, and the std is %f.\n', index, p, sd);
    depth = depth+1;
    buildtree(X_left, y_left, depth, 1);  
    buildtree(X_right, y_right, depth, 0);
    depth = depth-1;
end

end




