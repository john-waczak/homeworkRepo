%% Lab 1 -- MTH 351 -- John Waczak

%%
clear all;

%% TASK A 
% Fire up MATLAB on your computer can create two 3x5 matrices and name them
% tut1 and tut2. The matrix you call tut2 should contain no zeros.
% Use the size command to verify the size of the matrices you created above
tut1 = [1,2,3,4,5;5,4,3,2,1;0,0,0,0,0]; 
size(tut1)
tut2 = ones(3,5); 
size(tut2)

%% TASK B 
% use only the commands ones and diag to create a 5x5 identity matrix
% Create a row vector of all even integers between 5 and 25.

%%
% creating identity matrix
diag_ones = ones(5,1);
id_mat = diag(diag_ones);
diag_ones
id_mat

%%
% creating even integer vector
even_ints = 6:2:24;
even_ints

%% TASK C

fdj = [ 1 2 3;5 4 3; 6 5 8 ];

fdj
fdj+3
fdj-6
fdj./2
% Demonstrates component-wise addition, subtraction, and addition
%%
abc = 1:10;
def = 5:14;
% initialize two vectors of integers over two specified ranges
ghi = 3*abc + def
% perform vector arithmetic 

%%
abc = [1 2 3 4;5 6 7 8];
def = [4 3 2 1;8 7 6 5];
% initialize two 2x4 arrays
abc + def
% add arrays component-wise

%%
tut1 .* tut2
tut2 .* tut1
tut1 ./ tut2
tut2 ./ tut1
tut1 .^ 2
% demonstrates component-wise operations on matrices from TASK A
% inf are created upon dividing by zero element wise 

%% TASK E 
% graph has poor resolution... only using 10 data points 
figure()
x1 = linspace(-5,5,10) ;
y=x1./(1+x1.^2);
plot(x1,y)


%%
% better resolution due to increased number of points
figure()
x2 = linspace(-5,5,100) ;
y=x2./(1+x2.^2);
plot(x2,y)


%%
% square makes sure that axes have same length in screen so circles aren't 
% distorted
figure()
theta = 0 : 0.05 : 2*pi;
hold on 
axis('square')
plot(cos(theta),sin(theta))
hold off 
 

%%
% example of a parametric polar plot
figure() 
theta = 0 : 0.1 : 2*pi;
r = sin(3*theta);
plot(r .* cos(theta), r .* sin(theta))
















