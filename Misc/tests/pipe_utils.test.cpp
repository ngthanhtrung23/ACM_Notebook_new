#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"

#include <bits/stdc++.h>
using namespace std;
#include "../../debug.h"
#include "../container_pipe_utils.h"

int main() {
    // min, max
    {
        vector<int> a {3, 5, 4, 1, 2};
        assert((a | MIN) == 1);
        assert((a | MAX) == 5);

        vector<int64_t> a64 {3000111000111LL, 5000111000111LL, 4000111000111LL, 1000111000111LL, 2000111000111LL};
        assert((a64 | MIN) == 1000111000111LL);
        assert((a64 | MAX) == 5000111000111LL);

        vector<string> as {"10", "3", "5", "4", "1"};
        assert((as | MIN) == "1");
        assert((as | MAX) == "5");
    }

    // sum
    {
        vector<int> a {1000111000, 1000111000, 1000111000};
        assert((a | SUM) == 3000333000LL);

        vector<int> a2 {1, 2, 3};
        assert((a2 | SUM_XOR) == 0);

        vector<int> a3 {1, 2, 4};
        assert((a3 | SUM_XOR) == 7);
    }

    // sort
    {
        vector<int> a {3, 5, 4, 1, 2};
        a | SORT | ADD_1;
        assert((a == vector<int>{2, 3, 4, 5, 6}));

        vector<int> a2 {30, 50, 0, 40, 10, 20};
        a2 | COMPRESS;
        assert((a2 == vector<int>{3, 5, 0, 4, 1, 2}));

        vector<int> a3 {2, 3, 4};
        a3 | SUB_1 | PREFIX_SUM;
        assert((a3 == vector<int>{1, 3, 6}));

        vector<int> a4 {3, 2, 1};
        a4 | REVERSE | SUB_1;
        assert((a4 == vector<int>{0, 1, 2}));
    }

    cout << "Hello World\n";
    return 0;
}
