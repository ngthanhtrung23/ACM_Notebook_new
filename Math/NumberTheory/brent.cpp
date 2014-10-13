#include "../../template.h"
#include "brent.h"

int main() {
    // print 1 2 3 2 5 2 7 2 3 2
    for(int i = 1; i <= 10; ++i)
        cout << brent(i) << ' ';
    cout << endl;

    for(int test = 0; test < 100000; ++test) {
        long long n = rand();
        if (n < 0) n = -n;
        long long x = brent(n);

        assert(n % x == 0);
        if (test % 100 == 0) {
            DEBUG(test);
        }
    }
}

