function [ p, sd, sub1, sub2 ] = split( x, y )
% function split is to find a split point (value) which divides x into 2 subsets with the largest loss of the standard deviation of y
% in this problem, y is always the revenue (dependent variable), x denotes the attribute
% sd is the minimum standard deviation
% sub1 and sub2 are the indices of subsets
% min_node = 7; % the minimum number of subset
%if(length(x)<7)
%    return;
%end
x_min = min(x);
x_max = max(x);
inc = (x_max - x_min)/1000; % the length of increacement 
sd = std(y);

for pt = x_min:inc:x_max
    sub_index1 = find(x>pt);
    sub_index2 = find(x<=pt);
    sd1_temp = std(y(sub_index1));
    sd2_temp = std(y(sub_index2));
    num_sub1 = length(sub_index1);
    num_sub2 = length(sub_index2);
    sd_temp = (num_sub1*sd1_temp+num_sub2*sd2_temp)/length(x);
    %a = (sd_temp<sd) && (num_sub1>=min_node) && (num_sub2>=min_node);
    if(sd_temp<sd)
        p = pt;
        sd = sd_temp;
        sub1 = sub_index1;
        sub2 = sub_index2;
    end    
end


end

