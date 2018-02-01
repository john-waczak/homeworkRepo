%% Lab 1 -- MTH 351 -- John Waczak
%%
clear all;
format long e; 

%% 1) Consider the Taylor expansion for ln(1-x), ln((1+x)/(1-x))
% see function files for calculation of taylor expansions and relative error. 
% taylor1 corresponds to the first function and taylor2 to the second. 
% a) To get ln(1.9) an x value of -0.9 must be used. 
% b) Write a script in Matlab to demonstrate how many terms are necessary to
%    achieve ten digits of accuracy.
xT1 = log(1.9);
xA1 = taylor1(-0.9,1);
n1 = 1;
while relative(xT1, xA1) > (5*10^(-10-1))
    n1 = n1 + 1 ;
    xA1 = taylor1(-0.9, n1) ;
end 
n1
xT1
xA1

%% 
% c) Do the same as (a) for series two. 
val = (1.9-1)/(1+1.9) 
% ^ that is the value for x to get ln(1.9) 

%%
% d) Do the same as (b) for series two 
xT2 = log(1.9); 
xA2 = taylor2(val, 1); 
n2 = 1; 
while relative(xT2, xA2)>(5*10^(-10-1))
    n2 = n2 + 1; 
    xA2 = taylor2(val, n2); 
end 
n2 
xT2
xA2
%% 
% e) which is more efficient? 
% we can measure the time to compute using the tic,toc commands however
% it would appear 2 should be faster as it took 9 iterations versus 174. 

tic
    taylor1(-0.9, n1) 
toc
    
tic 
    taylor2(val, n2) 
toc
%%
% This timing command reflects my suspicion that (2) is the more efficient
% method. 
%% 2.) 
% Write a script in Matlab to create a table of values (similar to Table 2.7) obtained by
% evaluating a given function as it is written, and also as a reformulation designed to
% eliminate loss-of-significance errors. Choose x from 10−1 to 10−20 decreasing by a factor of 0.1.
% a) see f1 and fixed_f1 function files. This function was fixed by
% multiplying top and bottom by the conjugate. 
 fprintf('\n\nTable:\n\n');
 fprintf('x \t f(x) \t fixed f(x) \n');
 for i=1:20
     x=10^(-i);
     fprintf('%g \t %0.15f \t %0.15f\n',x,f1(x), fixed_f1(x))
 end  

%%
% b) see f2 and fixed_f2 function files. This function was fixed by expanding using a Taylor polynomial for exp(-x)  
 fprintf('\n\nTable:\n\n');
 fprintf('x \t f(x) \t fixed f(x) \n');
 for i=1:20
     x=10^(-i);
     fprintf('%g \t %0.15f \t %0.15f\n',x,f2(x), fixed_f2(x))
 end 
    
%%
% This loss of significance error is occuring whenever we subtract two
% numbers that are nearly the same. When we fix the functions by rewriting
% them to remove the subtraction, we get rid of the loss of significance
% error.   
    
