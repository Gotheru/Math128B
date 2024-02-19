function res = sor_sparse(n, A, D, L, U, b, x0, w, TOL, MAX_IT)
    x = x0;
    residuals = zeros(1, MAX_IT);
    T1 = (1 - w) * D + w * U;
    T2 = D - w * L;
    for k = 1 : MAX_IT
        y = T1 * x + w * b;
        x = T2\y;
        r = norm(b - A * x) / norm(b);
        residuals(k) = r;
        if (r < TOL)
            res.conv = k;
            break
        end
    end
    res.x = x;
    res.residuals = residuals;
end