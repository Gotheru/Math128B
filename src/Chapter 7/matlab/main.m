n = 1000000;
num_it = 100;
% Construct A, D, L, U

rows_A = ones(1, 3 * n - 2);
columns_A = ones(1, 3 * n - 2);
values_A = zeros(1, 3 * n - 2);
last_A = 1;

rows_D = ones(1, n);
columns_D = ones(1, n);
values_D = zeros(1, n);
last_D = 1;

rows_L = ones(1, n - 1);
columns_L = ones(1, n - 1);
values_L = zeros(1, n - 1);
last_L = 1;

rows_U = ones(1, n - 1);
columns_U = ones(1, n - 1);
values_U = zeros(1, n - 1);
last_U = 1;

for i = 1 : n

    rows_A(last_A) = i;
    columns_A(last_A) = i;
    values_A(last_A) = 2.1;
    last_A = last_A + 1;

    rows_D(last_D) = i;
    columns_D(last_D) = i;
    values_D(last_D) = 2.1;
    last_D = last_D + 1;

    if i ~= 1
        rows_A(last_A) = i;
        columns_A(last_A) = i - 1;
        values_A(last_A) = -1;
        last_A = last_A + 1;

        rows_L(last_L) = i;
        columns_L(last_L) = i - 1;
        values_L(last_L) = 1;
        last_L = last_L + 1;
    end
    if i ~= n
        rows_A(last_A) = i;
        columns_A(last_A) = i + 1;
        values_A(last_A) = -1;
        last_A = last_A + 1;

        rows_U(last_U) = i;
        columns_U(last_U) = i + 1;
        values_U(last_U) = 1;
        last_U = last_U + 1;
    end
end

A = sparse(rows_A, columns_A, values_A, n, n);
D = sparse(rows_D, columns_D, values_D, n, n);
L = sparse(rows_L, columns_L, values_L, n, n);
U = sparse(rows_U, columns_U, values_U, n, n);

b = ones(n, 1);
x0 = zeros(n, 1);

res1 = jacobi_sparse(n, A, D, L, U, b, x0, 1e-12, num_it);
res2 = sor_sparse(n, A, D, L, U, b, x0, 1.0, 1e-12, num_it);
res3 = sor_sparse(n, A, D, L, U, b, x0, 1.3, 1e-12, num_it);
res4 = sor_sparse(n, A, D, L, U, b, x0, 1.6, 1e-12, num_it);
res5 = cg_sparse(n, A, D, L, U, b, x0, 1e-12, num_it);

Iterations = 1:num_it;
Jacobi = res1.residuals(Iterations);
SOR1 = res2.residuals(Iterations);
SOR2 = res3.residuals(Iterations);
SOR3 = res4.residuals(Iterations);
CG = res5.residuals(Iterations);

tbl = table(Iterations, Jacobi, SOR1, SOR2, SOR3, CG);


semilogy(tbl, "Iterations", ...
    ["Jacobi", "SOR1", "SOR2", "SOR3", "CG"])
grid on
legend