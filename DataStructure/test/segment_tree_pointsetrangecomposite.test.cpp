#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include "bits/stdc++.h"
using namespace std;

#include "../SegTree.h"
#include "../../Math/modulo_anta.h"
#include "../../buffered_reader.h"

struct Func {
    modular a, b;
};

Func op(Func l, Func r) {
    return Func{
        l.a * r.a,
        r.a * l.b + r.b
    };
}
Func e() {
    return Func{1, 0};
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n = IO::get_int<int>();
    int q = IO::get_int<int>();
    vector<Func> funcs(n);
    for (auto& f : funcs) {
        int a = IO::get_int<int>();
        int b = IO::get_int<int>();
        f = {a, b};
    }

    SegTree<Func, op, e> seg_tree(funcs);
    while (q--) {
        int typ = IO::get_int<int>();
        if (typ == 0) {
            int pos = IO::get_int<int>();
            int a = IO::get_int<int>();
            int b = IO::get_int<int>();
            seg_tree.set(pos, {a, b});
        } else {
            int l = IO::get_int<int>();
            int r = IO::get_int<int>();
            auto f = seg_tree.prod(l, r);
            int x = IO::get_int<int>();
            cout << f.a * x + f.b << '\n';
        }
    }
    return 0;
}
