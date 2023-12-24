#pragma once
#include <bits/stdc++.h>
#include "../Section 1/vector_utils.cpp"
using namespace std;

template<class T>
vector<T> gauss_seidel(int n, vector<vector<T>> A, vector<T> b, vector<T> XO, T TOL, int MAX_IT) {
    for (int i = 0; i < n; ++i) assert(A[i][i] != 0);
    for (int k = 0; k < MAX_IT; ++k) {
        vector<T> x(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j)
                x[i] -= A[i][j] * x[j];
            for (int j = i + 1; j < n; ++j)
                x[i] -= A[i][j] * XO[j] + b[i];
            x[i] /= A[i][i];
        }
        if (dist_l_inf(x, XO) < TOL) return x;
        else XO = x;
    }
    cout << "Maximum number of iterations exceeded\n";
    return {};
}