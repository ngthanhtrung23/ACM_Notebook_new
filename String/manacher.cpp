#include "../template.h"
#include "manacher.h"

int main() {
    cout << manacher("abcdcba") << endl; // 7
    cout << manacher("abcddcba") << endl; // 8
}

