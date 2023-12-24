#pragma once
#include <bits/stdc++.h>
using namespace std;

template<class T>
vector<T> operator + (vector<T> const& v, vector<T> const& w) {
    assert(v.size() == w.size());
    vector<T> ans(v);
    for (int i = 0; i < v.size(); ++i)
        ans[i] += w[i];
    return ans;
}

template<class T>
vector<T> operator - (vector<T> const& v, vector<T> const& w) {
    assert(v.size() == w.size());
    vector<T> ans(v);
    for (int i = 0; i < v.size(); ++i)
        ans[i] -= w[i];
    return ans;
}

template<class T>
vector<T> operator * (T k, vector<T> const& v) {
    vector<T> ans(v);
    for (int i = 0; i < v.size(); ++i)
        ans[i] *= k;
    return ans;
}

template<class T>
vector<T> operator * (vector<T> const& v, T k) {
    return k * v;
}

template<class T>
T l2_norm(vector<T> const& v) {
    T ans = 0;
    for (int i = 0; i < v.size(); ++i) ans += v[i] * v[i];
    return sqrt(ans);
}

template<class T>
T l_inf_norm(vector<T> const& v) {
    T ans = 0;
    for (int i = 0; i < v.size(); ++i) ans = max(ans, T(abs(v[i])));
    return ans;
}

template<class T>
T dist_l2(vector<T> const& v, vector<T> const& w) {
    return l2_norm(v - w);
}

template<class T>
T dist_l_inf(vector<T> const& v, vector<T> const& w) {
    return l_inf_norm(v - w);
}