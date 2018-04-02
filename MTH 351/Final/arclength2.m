function r = arclength2(a, b, n)
    
    f = inline('exp(x^2)','x');
    x = linspace(a,b,n);
    dx = (b-a)/n;
    
    % now we need to find f' so we can compute arclength. We are asked to
    % use central difference method. In order to make sure I have the
    % correct number of points in df 'vector' I will use Right difference
    % for x_1 and Left difference for x_n points. 
    df = zeros(1,n); 
    
    df(1) = (f(x(2))-f(x(1)))/dx;
    df(n) = (f(x(n))-f(x(n-1)))/dx;
    for i=2:n-1
        df(i)=(f(x(i+1))-f(x(i-1)))/(2*dx);
    end
   
    y = sqrt(1+df.^2);
    
    r = trapz(x,y);
end

