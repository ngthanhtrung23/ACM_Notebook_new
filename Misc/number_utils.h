// return digits of an integer (reversed order) {{{
vector<int> get_digits(int n) {
    if (n == 0) return {0};
    vector<int> res;
    while (n > 0) {
        res.push_back(n % 10);
        n /= 10;
    }
    return res;
}
// }}}
