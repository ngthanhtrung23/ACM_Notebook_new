#include "../template.h"
#include "SuffixArray.h"

int main() {
    string a = "abcdabcd";
    SuffixArray sa(a, 256);
    PR0(sa.SA, sa.SA.size()); // 4 0 5 1 6 2 7 3
    PR0(sa.LCP, sa.LCP.size()); // 0 4 0 3 0 2 0 1

    string b = "aaaaaa";
    SuffixArray sb(b, 256);
    PR0(sb.SA, sb.SA.size()); // 5 4 3 2 1 0
    PR0(sb.LCP, sb.LCP.size()); // 0 1 2 3 4 5
}
