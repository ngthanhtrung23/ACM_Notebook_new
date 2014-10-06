#include "../template.h"

const int maxn = 1000111;

// d[i] = diameter of palindrome centered at i
int d[maxn];
int manacher(char s[], int n) {
    int res = 0;
    // Palindrom độ dài lẻ
    int l = 0, r = -1;
    for (int i = 0; i < n; ++i) {
        int k = (i > r) ? 1 : min(d[l + r - i], r - i) + 1;
        while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) ++k;
        d[i] = --k;
        res = max(res, k + k + 1);
        if (r < i + k) {
            l = i - k;
            r = i + k;
        }
    }
    // Palindrome độ dài chẵn
    l = 0; r = -1;
    for (int i = 0; i < n; ++i) {
        int k = (i > r) ? 1 : min(d[l + r - i + 1], r - i + 1) + 1;
        while (i - k >= 0 && i + k - 1 < n && s[i - k] == s[i + k - 1]) ++k;
        d[i] = --k;
        res = max(res, k + k);
        if (r < i + k - 1) {
            l = i - k;
            r = i + k - 1;
        }
    }
    return res; // Độ dài palindrome dài nhất là xâu con của s[]
}

int main() {
}
