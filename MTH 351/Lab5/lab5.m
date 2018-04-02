%% MTH 351    LAB 5    John Waczak 
clear all;  
format long; 
%% 1. Trapezoidal Rule 
% i. Integral of e^(-x^2) from 0 to 1 

a = 0; 
b = 2; 
n0 = 2; % This will get us up to n=512 points in our grid 
f = 'exp(-x^2)' ;
[inT, diT, raT] = trapezoidal(a,b,n0,f);
i = [1:1:9];
n = 2.^i;
n = transpose(n);
fprintf('n \t\t\tIntegral \t\t\t\t\t\t\tError \t\t\t\t\t\t\tRatio\n')
fprintf('%03d \t%0.12f \t%0.5e \t%0.5g\n', [n, inT, diT, raT]')



figure()
x = linspace(0,2,1000);
y = exp(-x.^2);
plot(x,y);
title("exp(-x^2)");
xlabel("x");
ylabel("y(x)");


%%
% ii. Integral of 1/(1+x^2) from 0 to 4
clear all; 
a = 0; 
b = 4; 
n0 = 2; % This will get us up to n=512 points in our grid 
f = '1/(1+x^2)' ;
[inT, diT, raT] = trapezoidal(a,b,n0,f);

i = [1:1:9];
n = 2.^i;
n = transpose(n);
fprintf('n \t\t\tIntegral \t\t\t\t\t\t\tError \t\t\t\t\t\t\tRatio\n')
fprintf('%03d \t%0.12f \t%0.5e \t%0.5g\n', [n, inT, diT, raT]')

figure()
x = linspace(0,4,1000);
y = 1./(1+x.^2);
plot(x,y);
title("1/(1+x^2)");
xlabel("x");
ylabel("y(x)");

%%
% iii. Integral of 1/(2+sin(x)) from 0 to 2pi 
clear all; 
a = 0; 
b = 2*pi; 
n0 = 2; % This will get us up to n=512 points in our grid 
f = '1/(2+sin(x))' ;
[inT, diT, raT] = trapezoidal(a,b,n0,f);

i = [1:1:9];
n = 2.^i;
n = transpose(n);
fprintf('n \t\t\tIntegral \t\t\t\t\t\t\tError \t\t\t\t\t\t\tRatio\n')
fprintf('%03d \t%0.12f \t%0.5e \t%0.5g\n', [n, inT, diT, raT]')

figure()
x = linspace(0,2*pi,1000);
y = 1./(2+sin(x));
plot(x,y);
title("1/(2+sin(x))");
xlabel("x");
ylabel("y(x)");


%%
% iv. Integral of sqrt(x) from 0 to 1
clear all; 
a = 0; 
b = 1; 
n0 = 2; % This will get us up to n=512 points in our grid 
f = 'sqrt(x)' ;
[inT, diT, raT] = trapezoidal(a,b,n0,f);

i = [1:1:9];
n = 2.^i;
n = transpose(n);
fprintf('n \t\t\tIntegral \t\t\t\t\t\t\tError \t\t\t\t\t\t\tRatio\n')
fprintf('%03d \t%0.12f \t%0.5e \t%0.5g\n', [n, inT, diT, raT]')

figure()
x = linspace(0,2*pi,1000);
y = sqrt(x);
plot(x,y);
title("sqrt(x)");
xlabel("x");
ylabel("y(x)");
%%
% b) Comment if the trapzoidal rule performed worse or better than expected
% for each integral. Explain what might be the cause. 
% 
% For the first function, the trapezoidal rule appeared to work as
% expected. We should see error that goes like order 2 i.e. if we halve the
% grid spaceing, the error should quarter. Looking at the error column for
% that integral we see that this is roughly what happens for each
% iteration. 
%
% For the second funciton. The error begins quite large and then slowly
% trickles down to the 10e-7 precision for the final iteration of 512 
% points (same as first function). This is likely performing differently
% because of the dramatic change in slope over the interval. In the 
% beginning, the slop is large and negative. Then after around x=2 the 
% function is very shallow so any error over here will be small. The ratio 
% column is almost 4 for all numbers of points though which suggests we
% still have order 2 convergence.
%
% The third functon converges very quickly to an error on the order of
% 10^-15. In class we said that periodic functions behave really well with
% the trapezoid rule so this is probably an effect due to the periodic
% nature of the sine function that is composed within f. The ratio column
% is all over the place.
%
% The final square root function appears to be converging linearly if we
% look at the error column. The ratio column confirms this with roughly 2
% for all number of points. 

%% 2. Repeat 1 using Composite Simpson's rule. Compare to trapezoid rule
% 
clear all;
a = 0; 
b = 2; 
n0 = 2; % This will get us up to n=512 points in our grid 
f = 'exp(-x^2)' ;
[inS, diS, raS] = simpson(a,b,n0,f);
i = [1:1:9];
n = 2.^i;
n = transpose(n);
fprintf('n \t\t\tIntegral \t\t\t\t\t\t\tError \t\t\t\t\t\t\tRatio\n')
fprintf('%03d \t%0.12f \t%0.5e \t%0.5g\n', [n, inS, diS, raS]')
%%
% Here we can see that for this function Simpson's rule converges much
% faster! It goes 4 orders of magnitude lower in the same number of
% points. Here we also verify that Simpson's rule is order 4 as the
% ratio column is consistantly right around 16 (i.e. 2^4) 
%%
clear all; 
a = 0; 
b = 4; 
n0 = 2; % This will get us up to n=512 points in our grid 
f = '1/(1+x^2)' ;
[inS, diS, raS] = simpson(a,b,n0,f);

i = [1:1:9];
n = 2.^i;
n = transpose(n);
fprintf('n \t\t\tIntegral \t\t\t\t\t\t\tError \t\t\t\t\t\t\tRatio\n')
fprintf('%03d \t%0.12f \t%0.5e \t%0.5g\n', [n, inS, diS, raS]')


%%
% We can see that this method is also much better than the trapezoid rule
% for this function. Again the ratio column indicates that we have 4th
% order convergence. It does take more points than for the first
% function to reach this rate-- just like with the trapezoid rule. 
%%
clear all; 
a = 0; 
b = 2*pi; 
n0 = 2; % This will get us up to n=512 points in our grid 
f = '1/(2+sin(x))' ;
[inS, diS, raS] = simpson(a,b,n0,f);

i = [1:1:9];
n = 2.^i;
n = transpose(n);
fprintf('n \t\t\tIntegral \t\t\t\t\t\t\tError \t\t\t\t\t\t\tRatio\n')
fprintf('%03d \t%0.12f \t%0.5e \t%0.5g\n', [n, inS, diS, raS]')

%%
% For this function we again have the odd behavior that it is converging to
% 10e-15 within 2^9 points. Once again we cant really specify what order
% the convergence is as the error and ratio columns are all over the place
% but I suspect something about the sine function is making this converge
% rapidly. 
%%

clear all; 
a = 0; 
b = 1; 
n0 = 2; % This will get us up to n=512 points in our grid 
f = 'sqrt(x)' ;
[inS, diS, raS] = trapezoidal(a,b,n0,f);

i = [1:1:9];
n = 2.^i;
n = transpose(n);
fprintf('n \t\t\tIntegral \t\t\t\t\t\t\tError \t\t\t\t\t\t\tRatio\n')
fprintf('%03d \t%0.12f \t%0.5e \t%0.5g\n', [n, inS, diS, raS]')

%%
% For this final function we have that the convergence is first oder again!
% Thus Simpson's method isn't any more efficient than the Trapezoid method
% for this problem. 
%% 3. Asymptotic Error Formula 
% By looking at the table for Simpson's rule we have that n= 128 has an
% error of 10e-9. Then for n = 256 we have error 10e-10. This seems to
% roughly agree with the statement that we need n=160 for an error of
% 10e-10. Similarly for the second integral we have that when n=256 the
% error is 10e-11 and when n=512 the error is 10e-12 so n = 360 seems to
% rougly agree with the asymptotic error formula. 

%% 4. Repeat 1 using the Gaussian Quadrature rule. 

clear all; 
a = 0; 
b = 2; 
n0 = 2; % This will get us up to n=512 points in our grid 
f = 'exp(-x^2)' ;
[inG, diG, raG] = gausstable(a,b,n0,f);
i = [1:1:9];
n = 2.^i;
n = transpose(n);
fprintf('n \t\t\tIntegral \t\t\t\t\t\t\tError \t\t\t\t\t\t\tRatio\n')
fprintf('%03d \t%0.12f \t%0.5e \t%0.5g\n', [n, inG, diG, raG]')
%%
% If we look at the output of the quadrature we see that there is extremely
% rapid convergence. With just 32 points we already have error at 10e-16
% which is better than just about every method we tried with 512 points. As
% we said in class, this is like magic!
%%

clear all; 
a = 0; 
b = 4; 
n0 = 2; % This will get us up to n=512 points in our grid 
f = '1/(1+x^2)' ;
[inG, diG, raG] = gausstable(a,b,n0,f);

i = [1:1:9];
n = 2.^i;
n = transpose(n);
fprintf('n \t\t\tIntegral \t\t\t\t\t\t\tError \t\t\t\t\t\t\tRatio\n')
fprintf('%03d \t%0.12f \t%0.5e \t%0.5g\n', [n, inG, diG, raG]')

%%
% For this functin, the Gaussian quadrature took one factor of 2 more
% points to reach the 10e-16 precision. This is till better than both the
% trapezoid and simpson's method. 
%%
clear all; 
a = 0; 
b = 2*pi; 
n0 = 2; % This will get us up to n=512 points in our grid 
f = '1/(2+sin(x))' ;
[inG, diG, raG] = gausstable(a,b,n0,f);

i = [1:1:9];
n = 2.^i;
n = transpose(n);
fprintf('n \t\t\tIntegral \t\t\t\t\t\t\tError \t\t\t\t\t\t\tRatio\n')
fprintf('%03d \t%0.12f \t%0.5e \t%0.5g\n', [n, inG, diG, raG]')
%%
% Yet again this function is having the same problem. Quadrature is
% missbehaving and we have the same weird convergence to 10e-15 for 512
% points. 
%%
clear all; 
a = 0; 
b = 1; 
n0 = 2; % This will get us up to n=512 points in our grid 
f = 'sqrt(x)' ;
[inG, diG, raG] = gausstable(a,b,n0,f);

i = [1:1:9];
n = 2.^i;
n = transpose(n);
fprintf('n \t\t\tIntegral \t\t\t\t\t\t\tError \t\t\t\t\t\t\tRatio\n')
fprintf('%03d \t%0.12f \t%0.5e \t%0.5g\n', [n, inG, diG, raG]')
%%
% This one was really surprising to me. For the past two methods, this
% function converged at order 1. Here we have that the ratio is around 8
% each time putting this closer to order 2 convergence. So Gaussian
% quadrature is still better for integrating this funciton but it isn't
% reaching machine epsilon as quickly as it did for the first two examples.









