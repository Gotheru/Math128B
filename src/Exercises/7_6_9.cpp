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
    vector<vector<db>> A(25, vector<db>(25));
    for (int i = 1; i <= 25; ++i) {
        for (int j = 1; j <= 25; ++j) {
            if (i == j) A[i-1][j-1] = 4;
            else if (j == i + 1 && i % 5 != 0) A[i-1][j-1] = -1;
            else if (j == i - 1 && i % 5 != 1) A[i-1][j-1] = -1;
            else if (j == i + 5 || j == i - 5) A[i-1][j-1] = -1;
            else A[i-1][j-1] = 0;
        }
    }
    for (int i = 0; i < 25; ++i) {
        for (int j = 0; j < 25; ++j) cout << setw(2) << A[i][j] << ' ';
        cout << endl;
    }
    vector<db> b(25, 0);
    for (int i = 0; i < 25; ++i) {
        if (i % 5 == 0) b[i] = 1;
        else if (i % 5 == 2) b[i] = -1;
        else if (i % 5 == 4) b[i] = 2;
    }
    int n = 25;
    vector<db> x0(25, 0);

    // (a)
    cout << "Jacobi:\n";
    vector<db> jacobi_solution = jacobi(n, A, b, x0, (db)1e-5, 100);
    for (db xi : jacobi_solution) cout << xi << '\n';
    // (b)
    cout << "Gauss-Seidel:\n";
    vector<db> gauss_solution = gauss_seidel(n, A, b, x0, (db)1e-5, 100);
    for (db xi : gauss_solution) cout << xi << '\n';
    // (c)
    cout << "SOR:\n";
    vector<db> sor_solution = SOR(n, A, b, x0, db(1.2), db(1e-5), 100);
    for (db xi : sor_solution) cout << xi << '\n';
    // (d)
    cout << "CG:\n";
    vector<vector<db>> C(25, vector<db>(25));
    for (int i = 0; i < 25; ++i) C[i][i] = db(1) / db(sqrt(A[i][i]));
    vector<db> cg_solution = CG(n, A, b, C, x0, 100, db(1e-5));
    for (db xi : cg_solution) cout << xi << '\n';

    return 0;

}