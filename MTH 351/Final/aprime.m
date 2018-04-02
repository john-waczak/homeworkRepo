function r = aprime(x)
    % by the FTC a'(x) should be the integrand evaluated on the boundary
    df = inline('2.*x.*exp(x.^2)','x');
    r = sqrt(1+df(x)^2);
end

