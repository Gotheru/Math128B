#include "../Chapter 7/jacobi.cpp"
#include "../Chapter 7/gauss_seidel.cpp"
#include "../Chapter 7/SOR.cpp"
#include "../Chapter 7/CG.cpp"
#include <iomanip>
using namespace std;
using namespace chapter_7::section_1;
using namespace chapter_7::section_3;
using namespace chapter_7::section_4;
using namespace chapter_7::section_6;

using db = long double;

int main() {
    int n = 100;
    int it = 100;
    vector<vector<db>> A(n, vector<db>(n));
    for (int i = 0; i < n; ++i) {
        A[i][i] = 2.1;
        if (i) A[i][i-1] = -1;
        if (i != n - 1) A[i][i+1] = -1;
    }
    
    vector<db> b(n, 1);
    vector<db> x0(n, 0);

    // (a)
    cout << "Jacobi:\n";
    vector<db> jacobi_solution = jacobi(n, A, b, x0, (db)1e-5, it);
    for (db xi : jacobi_solution) cout << xi << '\n';
    // (b)
    cout << "Gauss-Seidel:\n";
    vector<db> gauss_solution = gauss_seidel(n, A, b, x0, (db)1e-5, it);
    for (db xi : gauss_solution) cout << xi << '\n';
    // (c)
    cout << "SOR:\n";
    vector<db> sor_solution = SOR(n, A, b, x0, db(1.6), db(1e-5), it);
    for (db xi : sor_solution) cout << xi << '\n';
    // (d)
    cout << "CG:\n";
    vector<vector<db>> C(n, vector<db>(n));
    for (int i = 0; i < n; ++i) C[i][i] = db(1) / db(sqrt(A[i][i]));
    vector<db> cg_solution = CG(n, A, b, C, x0, it, db(1e-5));
    for (db xi : cg_solution) cout << xi << '\n';

    return 0;

}