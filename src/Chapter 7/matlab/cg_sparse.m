function res = cg_sparse(n, A, D, L, U, b, x0, TOL, MAX_IT)
    x = x0;
    residuals = zeros(1, MAX_IT);
    w = A * x;
    r = b - w;
    v = r;
    for k = 1 : MAX_IT
        t = dot(r, r) / dot(v, A * v);
        x = x  + t * v;
        s = 1 / dot(r, r);
        r = r - t * A * v;
        s = s * dot(r, r);
        v = r + s * v;
        rr = norm(r) / norm(b);
        residuals(k) = rr;
        if (rr < TOL)
            res.conv = k;
            break
        end
    end
    res.x = x;
    res.residuals = residuals;
end