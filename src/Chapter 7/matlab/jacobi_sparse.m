function res = jacobi_sparse(n, A, D, L, U, b, x0, TOL, MAX_IT)
    % y_(k+1) = b + (L + U)x_k
    % x_(k+1) = D^-1y_(k+1) <=> Dx_(k+1) = y_(k+1)
    T = L + U;
    x = x0;
    residuals = zeros(1, MAX_IT);
    for k = 1 : MAX_IT
        y = b + T * x;
        x = D\y;
        r = norm(b - A * x) / norm(b);
        residuals(k) = r;
        if r < TOL
            res.conv = k;
            break
        end
    end
    res.x = x;
    res.residuals = residuals;
end