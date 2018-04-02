clear all; 

n = 3; 
k = [0:1:n];
xcheb = cos((2.*k+1).*pi./(2*(n+1)));
tcheb = (1/2)+(1/2).*xcheb;
fcheb = exp(tcheb);
P3 = polyfit(tcheb, fcheb, n)