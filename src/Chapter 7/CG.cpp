#pragma once
#include "vector_utils.cpp"
#include <iostream>

/**
 * @namespace chapter_7
 * @brief Iterative Techniques in Matrix Algebra
*/
namespace chapter_7 {
    /**
     * @namespace section_6
     * @brief 7.6 The Conjugate Gradient Method
    */
    namespace section_6 {
        
        /**
         * CG
         * \todo add explanation
         * \param n Number of equations and unknowns
         * \param A Coefficient matrix
         * \param b Independent coefficient vector
         * \param C Preconditioning matrix C^-1
         * \param x Initial approximation
         * \param N Maximum number of iterations
         * \param TOL Error boundary of the solution
         * \returns x that solves Ax = b with error tolerance TOL
        */
        template <typename T>
        std::vector<T> CG(int n, std::vector<std::vector<T>> A, std::vector<T> b, std::vector<std::vector<T>> C, std::vector<T> x, int N, T TOL) {
            using namespace chapter_7::section_1;
            std::vector<T> r = b - A * x;
            auto D = transpose(C);
            std::vector<T> w = C * r;
            std::vector<T> v = D * w;
            T alpha = 0;
            for (int j = 0; j < n; ++j) alpha += w[j] * w[j];
            for (int k = 0; k < N; ++k) {
                if (l2_norm(v) < TOL) {
                    std::cout << "Reached the solution in " << k + 1 << " iterations\n";
                    return x;
                    // Residual r
                }
                std::vector<T> u = A * v;
                T t = alpha;
                T den = 0;
                for (int j = 0; j < n; ++j)  den += v[j] * u[j];
                t /= den;
                x = x + t * v;
                r = r - t * u;
                w = C * r;
                T beta = 0;
                for (int j = 0; j < n; ++j) beta += w[j] * w[j];
                if (abs(beta) < TOL && l2_norm(r) < TOL) {
                    std::cout << "Reached the solution in " << k + 1 << " iterations\n";
                    return x;
                    // Residual r
                }
                T s = beta / alpha;
                v = D * w + s * v;
                alpha = beta;
            }
            std::cout << "The procedure failed to find the solution in less than " << N << " iterations.\n";
            return {};
        }

    } // namespace section_3

} // namespace chapter_7