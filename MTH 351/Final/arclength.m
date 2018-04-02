function r  = arclength(a,b,n)
    
    df = inline('2.*x.*exp(x.^2)','x');
    x = linspace(a, b, n);
    y = sqrt(1+df(x).^2);
    r = trapz(x,y) ;
end

