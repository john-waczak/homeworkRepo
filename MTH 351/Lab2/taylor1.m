function y = taylor1(x, N)
    y = 0;
    for i = 1:N
        y = y + (x.^i)./i;
    end
    y = -y;
end

