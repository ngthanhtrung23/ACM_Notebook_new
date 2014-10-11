#include "../template.h"
#include "zfunc.h"

int main() {
    vector<int> z;
    zfunc("abcabcabc", z); // 9 0 0 6 0 0 3 0 0
    PR0(z, z.size());
    zfunc("aaaaaaaaa", z); // 9 8 7 6 5 4 3 2 1
    PR0(z, z.size());
    return 0;
}
