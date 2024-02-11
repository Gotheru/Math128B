#pragma once

#include <vector>
#include <cassert>
#include <cmath>

/**
 * @namespace chapter_7
 * @brief Iterative Techniques in Matrix Algebra
*/
namespace chapter_7 {
    /**
     * @namespace section_1
     * @brief 7.1. Norm of Vectors and Matrices
    */
    namespace section_1 {

        /**
         * Implements vector addition
         * \param v first vector
         * \param w second vector
         * \returns v + w
        */
        template <typename T>
        std::vector<T> operator + (std::vector<T> const& v, std::vector<T> const& w) {
            assert(v.size() == w.size());
            std::vector<T> ans(v);
            for (int i = 0; i < v.size(); ++i)
                ans[i] += w[i];
            return ans;
        }

        /**
         * Implements vector substraction
         * \param v first vector
         * \param w second vector
         * \returns v - w
        */
        template <typename T>
        std::vector<T> operator - (std::vector<T> const& v, std::vector<T> const& w) {
            assert(v.size() == w.size());
            std::vector<T> ans(v);
            for (int i = 0; i < v.size(); ++i)
                ans[i] -= w[i];
            return ans;
        }
        
        /**
         * Implements vector multiplication by scalar
         * \param k scalar
         * \param v vector
         * \returns k * v
        */
        template <typename T>
        std::vector<T> operator * (T k, std::vector<T> const& v) {
            std::vector<T> ans(v);
            for (int i = 0; i < v.size(); ++i)
                ans[i] *= k;
            return ans;
        }

        /**
         * Implements vector multiplication by scalar
         * \param v vector
         * \param k scalar
         * \returns v * k
        */
        template <typename T>
        std::vector<T> operator * (std::vector<T> const& v, T k) {
            return k * v;
        }

        /**
         * Implements the l2 norm of a vector
         * \param v vector
         * \returns ||v|| = sqrt(sum(v[i]^2))
        */
        template <typename T>
        T l2_norm(std::vector<T> const& v) {
            T ans = T(0);
            for (int i = 0; i < v.size(); ++i)
                ans += v[i] * v[i];
            return sqrt(ans);
        }

        /**
         * Implements the l infinity norm of a vector
         * \param v vector
         * \returns ||v|| = max(abs(v[i]))
        */
        template <typename T>
        T l_inf_norm(std::vector<T> const& v) {
            T ans = T(0);
            for (int i = 0; i < v.size(); ++i)
                ans = std::max(ans, T(std::abs(v[i])));
            return ans;
        }

        /**
         * Implements the l2 distance of two vectors
         * \param v first vector
         * \param w second vector
         * \returns ||v-w|| in l2
        */
        template <typename T>
        T dist_l2(std::vector<T> const& v, std::vector<T> const& w) {
            return l2_norm(v - w);
        }

        /**
         * Implements the l infinity distance of two vectors
         * \param v first vector
         * \param w second vector
         * \returns ||v-w|| in l infinity
        */
        template <typename T>
        T dist_l_inf(std::vector<T> const& v, std::vector<T> const& w) {
            return l_inf_norm(v - w);
        }

        template <typename T>
        std::vector<std::vector<T>> transpose(std::vector<std::vector<T>> const& A) {
            if (A.empty()) return A;
            std::vector<std::vector<T>> B(A[0].size(), std::vector<T>(A.size()));
            for (int i = 0; i < int(A[0].size()); ++i) {
                for (int j = 0; j < int(A.size()); ++j) {
                    B[i][j] = A[j][i];
                }
            }
            return B;
        }

        template <typename T>
        std::vector<T> operator * (std::vector<std::vector<T>> const& A, std::vector<T> const& x) {
            assert(x.size() == A[0].size());
            std::vector<T> ans(A.size());
            for (int i = 0; i < A.size(); ++i) {
                for (int j = 0; j < A[0].size(); ++j) {
                    ans[i] += A[i][j] * x[j];
                }
            }
            return ans;
        }

    } // namespace section_1

} // namespace chapter_7