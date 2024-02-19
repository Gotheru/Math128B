#include <bits/stdc++.h>
#include "../Chapter 7/CG.cpp"
using namespace std;

using db = long double;

int main() {

    int n; // number of data entries
    int m; // polynomial degree
    cin >> n >> m;
    vector<pair<db, db>> data(n);
    for (int i = 0; i < n; ++i) {
        cin >> data[i].first >> data[i].second;
    }
    // Normal equations
    vector<vector<db>> A(m + 1, vector<db>(m + 1));
    vector<db> b(m + 1);

    // Calculate normal equations
    // A[i][j] = sum(x_k^(i + j)) for k in 0..n-1
    // b[j] = sum(y_k * x_k^j) for k in 0..n-1
    // O(nm^2)
    for (int i = 0; i < n; ++i) {
        db aux = 1, xi = data[i].first, yi = data[i].second;
        for (int pot = 0; pot <= 2 * m; ++pot) {
            if (pot <= m) {
                b[pot] += yi * aux;
            }
            for (int row = 0; row <= m; ++row) {
                int column = pot - row;
                if (0 <= column && column <= m) {
                    A[row][column] += aux;
                }
            }
            aux *= xi;
        }
    }

    cout << "The normal equations are: \n";
    cout << "A:\n";
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= m; ++j) {
            cout << fixed << setprecision(4) << A[i][j] << " \n"[j == m];
        }
    }
    cout << '\n';
    cout << "b:\n";
    for (int j = 0; j <= m; ++j) cout << fixed << setprecision(4) << b[j] << " \n"[j == m];
    cout << '\n';
    
    // Solve the equation with any method from last chapter
    using namespace chapter_7::section_6;
    // Calculate D^(1/2)
    vector<vector<db>> D(m + 1, vector<db>(m + 1));
    for (int i = 0; i <= m; ++i) D[i][i] = db(1) / db(sqrt(A[i][i]));
    vector<db> x0(m + 1, 0);
    cout << "Calculating coefficients using CG...\n";
    auto a = CG(m + 1, A, b, D, x0, m + 1, db(1e-5));
    
    cout << '\n';
    cout << "Coefficients are \n";
    for (db ai : a) cout << fixed << setprecision(4) << ai << ' ';
    cout << '\n';

    auto polyeval = [&](db x) -> db {
        db ans = a.back();
        for (int i = int(a.size()) - 2; i >= 0; --i) {
            ans = ans * x + a[i];
        }
        return ans;
    };
    
    db E = 0;
    for (int i = 0; i < n; ++i) {
        db aux = data[i].second - polyeval(data[i].first);
        E += aux * aux;
    }
    cout << "\nThe error is E = " << E << '\n';

    return 0;


}