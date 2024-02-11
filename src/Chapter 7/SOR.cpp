#pragma once
#include "vector_utils.cpp"
#include <iostream>

/**
 * @namespace chapter_7
 * @brief Iterative Techniques in Matrix Algebra
*/
namespace chapter_7 {
    /**
     * @namespace section_4
     * @brief 7.4. Relaxation Techniques for Solving Linear Systems.
    */
    namespace section_4 {
        
        /**
         * SOR
         * \todo add explanation
         * \param n Number of equations and unknowns
         * \param A Coefficient matrix
         * \param b Independent coefficient vector
         * \param XO Initial approximation
         * \param omega Over_Relaxation parameter
         * \param TOL Error boundary of the solution
         * \param MAX_IT Maximum number of iterations
         * \returns x that solves Ax = b with error tolerance TOL
        */
        template <typename T>
        std::vector<T> SOR(int n, std::vector<std::vector<T>> A, std::vector<T> b, std::vector<T> XO, T omega, T TOL, int MAX_IT) {
            for (int i = 0; i < n; ++i) assert(A[i][i] != 0);
            for (int k = 0; k < MAX_IT; ++k) {
                std::vector<T> x(n);
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < i; ++j)
                        x[i] -= A[i][j] * x[j];
                    for (int j = i + 1; j < n; ++j)
                        x[i] -= A[i][j] * XO[j];
                    x[i] += b[i];
                    x[i] *= omega;
                    x[i] /= A[i][i];
                    x[i] += (T(1) - omega) * XO[i];
                }
                if (chapter_7::section_1::dist_l_inf(x, XO) < TOL) {
                    std::cout << "Reached the solution in " << k + 1 << " iterations\n";
                    return x;
                }
                else XO = x;
            }
            std::cout << "Maximum number of iterations exceeded\n";
            return {};
        }

    } // namespace section_3

} // namespace chapter_7