#pragma once
#include "vector_utils.cpp"
#include <iostream>

/**
 * @namespace chapter_7
 * @brief Iterative Techniques in Matrix Algebra
*/
namespace chapter_7 {
    /**
     * @namespace section_3
     * @brief 7.3. The Jacobi and Gauss-Seidel Iterative Techniques.
    */
    namespace section_3 {
        
        /**
         * Implements the Jacobi Iterative technique to solve Ax = b given initial approximation XO
         * \todo add explanation
         * \param n Number of equations and unknowns
         * \param A Coefficient matrix
         * \param b Independent coefficient vector
         * \param XO Initial approximation
         * \param TOL Error boundary of the solution
         * \param MAX_IT Maximum number of iterations
         * \returns x that solves Ax = b with error tolerance TOL
        */
        template <typename T>
        std::vector<T> jacobi(int n, std::vector<std::vector<T>> A, std::vector<T> b, std::vector<T> XO, T TOL, int MAX_IT) {
            for (int i = 0; i < n; ++i) assert(A[i][i] != T(0));
            for (int k = 0; k < MAX_IT; ++k) {
                std::vector<T> x(n);
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < n; ++j)
                        if (j != i) x[i] -= A[i][j] * XO[j] + b[i];
                    x[i] /= A[i][i];
                }
                if (chapter_7::section_1::dist_l_inf(x, XO) < TOL) return x;
                else XO = x;
            }
            std::cout << "Maximum number of iterations exceeded\n";
            return std::vector<T>();
        }

    } // namespace section_3

} // namespace chapter_7