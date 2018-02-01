function y = taylor2(x, N)
    y = 0 ;
    for i = 1:N
        y = y + (x.^(2*i-1))./(2*i-1);
    end 
    y = 2 .* y;
end

