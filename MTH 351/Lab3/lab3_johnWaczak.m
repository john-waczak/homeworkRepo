%% MTH 351    LAB 3    John Waczak 
clear all;  
format long; 
%% 1 Using the bisection method
xT = 1;
tol = 10e-6;
maxIter = 100;

roots = zeros(1,3) ;
iterations = zeros(1,3) ; 
trueVal = [1, 1, 1];
interval = {'[0,3]', '[0.5,2]', '[0.9,1.2]'};

[itCount, root, xn] = bisect('x^5-x^4+x-1', 0, 3, tol, maxIter);
roots(1) = root; 
iterations(1) = itCount; 
[itCount, root, xn] = bisect('x^5-x^4+x-1', 0.5,2.0, tol, maxIter);
roots(2) = root; 
iterations(2) = itCount;
[itCount, root, xn] = bisect('x^5-x^4+x-1', 0.9, 1.2, tol, maxIter); 
roots(3) = root; 
iterations(3) = itCount;

error = abs(trueVal-roots);

T =table(interval.', roots.', error.', iterations.');
T.Properties.VariableNames = {'Interval', 'root', 'error', 'n'};
display(T); 
%%
% (a) The second interval takes exactly one step less because the interval 
% is exactly half as wide as the first i.e. 2-0.5 = 1.5 where as 3-0 = 3
%
% (b) I don't think there will be an advantage either way as the code
% doesn't presuppose the value of the root. No matter what the interval
% gets halved each time and so where the root is located shouldn't really
% matter because all the program is doing is to check when the length of
% the interval is within your specified tolerance. I will check this by
% increasing the tolerance and trying the bisection with two different
% intervals 

[itCount, root, xn] = bisect('x^5-x^4+x-1', 0.5, 1.5, 1e-10, 300);
itCount 
root
[itCount, root, xn] = bisect('x^5-x^4+x-1', 0.9, 1.9, 1e-10, 300); 
itCount
root
%%
% as we can see, both intervals took the same number of iterations so there
% is no clear advantage either way. 


%% 2 Using Newton's Method
clear all; 
format long; 
xT = 1;
tol = 10e-6;
maxIter = 100;

roots = zeros(1,7) ;
iterations = zeros(1,7) ; 
trueVal = [1, 1, 1,1,1,1,1];
iterates =[-100, 0, 0.9, 0.99, 1.1, 1.4, 1000000];

[itCount, root, xn] = newton('x^5-x^4+x-1', '5*x^4-4*x^3+1', iterates(1), tol, maxIter);
roots(1) = root; 
iterations(1) = itCount; 
[itCount, root, xn] =newton('x^5-x^4+x-1', '5*x^4-4*x^3+1',iterates(2), tol, maxIter);
roots(2) = root; 
iterations(2) = itCount;
[itCount, root, xn] = newton('x^5-x^4+x-1','5*x^4-4*x^3+1',iterates(3), tol, maxIter); 
roots(3) = root; 
iterations(3) = itCount;
[itCount, root, xn] = newton('x^5-x^4+x-1','5*x^4-4*x^3+1',iterates(4), tol, maxIter);
roots(4) = root; 
iterations(4) = itCount; 
[itCount, root, xn] = newton('x^5-x^4+x-1','5*x^4-4*x^3+1',iterates(5), tol, maxIter);
roots(5) = root; 
iterations(5) = itCount; 
[itCount, root, xn] = newton('x^5-x^4+x-1','5*x^4-4*x^3+1',iterates(6), tol, maxIter);
roots(6) = root; 
iterations(6) = itCount; 
[itCount, root, xn] = newton('x^5-x^4+x-1','5*x^4-4*x^3+1',iterates(7), tol, maxIter);
roots(7) = root; 
iterations(7) = itCount; 

error = abs(trueVal-roots);

T =table(iterates.', roots.', error.', iterations.');
T.Properties.VariableNames = {'Iterate', 'root', 'error', 'n'};
display(T); 

%%
% (a) When the initial iterate is close to the true root, Newton is MUCH
% more efficient. For example when the inital iterate was a value of 1.1 it
% took 4 iterations versus the 17 it took bisection given an interval of
% [0.5, 2]. For these examples, Newtons method was 4 times faster than
% Bisection however we must already know the derivative before hand. 
%
% (b) This is likely because the iteration that takes us below the
% tolerance is extremely precise and cuts down multiple orders of
% magnitude. From class we know for values close to the root the error goes
% like the square of the error for the last iteration. So if the previous
% error was near 10^-4 for example, then one more step would put us well
% below our tolerance. 
%
% (c) We know that the error for bisection goes like 1/2 the previous error
% so we need to figure out how many times we need to halve 2000000 in order
% to get to the epsilon of 1.3*10^-12. If we solve the equation 
% 2^n = 2000000/(epsilon) we get roughly 60 iterations. This is actually
% fewer than was required for using Newton's method which took 67 iterations. 


%% Using the secant method 
clear all; 
xT = 1;
tol = 10e-6;
maxIter = 100;

roots = zeros(1,3) ;
iterations = zeros(1,3) ; 
trueVal = [1, 1, 1];
iterates = {'[0,3]', '[0.5,2]', '[0.9,1.2]'};

[itCount, root, xn] = secant('x^5-x^4+x-1', 0, 3, tol, maxIter);
roots(1) = root; 
iterations(1) = itCount; 
[itCount, root, xn] = secant('x^5-x^4+x-1', 0.5,2.0, tol, maxIter);
roots(2) = root; 
iterations(2) = itCount;
[itCount, root, xn] = secant('x^5-x^4+x-1', 0.9, 1.2, tol, maxIter); 
roots(3) = root; 
iterations(3) = itCount;

error = abs(trueVal-roots);

T =table(iterates.', roots.', error.', iterations.');
T.Properties.VariableNames = {'Iterates', 'root', 'error', 'n'};
display(T); 

%%
% (a) The method is comparable to Newton's method (a tad slower) and still
% significantly faster than the bisection method. 
%
% (b) The inital iterate distance doesn't seem to impact the convergence as
% much as the bisection method. In fact for the shorter interval of [0.5,
% 2] the secant method was worse than for the interval [0,3]. 

%% 4 Explain the output of roots(poly(1:21)). 
clear all; 
roots(poly(1:21))
%%
% the poly(1:21) generates a polynomial with zeros at positions 1,2,3..21.
% If we are to take 2.3 problem 11 as an example this polynomial could be
% easily constructed by simply writing out the factored form. 
% Then the roots() function takes that polynomial and finds all of its
% roots again which we can verify are at 1,2,3,...21 with some
% numerical error. 


