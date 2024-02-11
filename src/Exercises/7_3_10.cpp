#include "../Chapter 7/gauss_seidel.cpp"
using namespace std;

using db = long double;

int main() {
    int n = 3;
    vector<vector<db>> A = {{1,2,-2},{1,1,1},{2,2,1}};
    vector<db> b = {7,2,5};
    vector<db> X0 = {0,0,0};
    db TOL = 1E-5;
    int MAX_IT = 10000;
    vector<db> x = chapter_7::section_3::gauss_seidel(n, A, b, X0, TOL, MAX_IT);
    for (auto xi : x) cout << xi << endl;
    return 0;
}
