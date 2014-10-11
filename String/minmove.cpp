#include "../template.h"
#include "minmove.h"

int main() {
    cout << minmove("mississippi") << endl; // 10
    cout << minmove("cdefab") << endl; // 4
    cout << minmove("zzzzzz") << endl; // 0
}
