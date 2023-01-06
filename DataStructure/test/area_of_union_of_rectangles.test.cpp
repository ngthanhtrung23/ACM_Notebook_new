#define PROBLEM "https://judge.yosupo.jp/problem/area_of_union_of_rectangles"

#include <bits/stdc++.h>
using namespace std;
#include "../misc/area_of_union_of_rectangles.h"
using namespace area_of_union_of_rectangles;

int main() {
    int n; cin >> n;
    vector<Rect> rects(n);
    for (auto& r : rects) cin >> r;
    cout << solve(rects) << endl;
}
