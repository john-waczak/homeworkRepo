%% MTH 351    LAB 5    John Waczak 
clear all;  
format long;
%% 1. 
% Use a computer algebra system to compute the arclength of f(x) = e^x^2 
% from 0 to 1 with 16 digits of accuracy 


%%
% using Mathematica to perform the integraiton. I am using the arc length 
% formula: a = int(a,b) sqrt(1-f'(x)^2) dx

TrueVal = 2.127616414686636;

%% 2. 
% See arclength.m for my function defintion. 
r = arclength(0,1,2^10)
Error = TrueVal-r
relE = abs(Error)/TrueVal

%% 3.
% See arclength1.m for my function definition
r1 = arclength2(0, 1, 2^10)
Error1 = TrueVal-r1
relE1 = abs(Error1)/TrueVal

%% 4. 
%  use newton's method with aprime and arclength to find when the arclength
%  is equal to pi. 
clear all ;
xold = 1 ;
n = 2^8 ;
tol = 1e-8;
maxiter = 50; 
for i = 1:maxiter
    % must subtract pi from arclength as newton's methods wants to find zeros so we must shift entire function to make pi a zero 
    x = xold - (arclength(0,xold,n)-pi)/aprime(xold);
    if abs(x-xold)<tol
       i
       break
    end
    xold = x;
end
    

%% 
% Thus we can see that it took 9 iterations to find the x value to a
% tolerance of 1e-8. Now I will verify that the function does truly
% evaluate to pi

arc_pi = arclength(0, xold,n)
diff = abs(arc_pi - pi)




