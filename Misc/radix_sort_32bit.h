// Note: Doesn't handle negative numbers
void radix_sort(std::vector<uint32_t>& arr) {
    const uint32_t FULL_MASK = (1<<16) - 1;
    auto get1 = [] (uint32_t x) { return x & FULL_MASK; };
    auto get2 = [] (uint32_t x) { return x >> 16; };

    std::vector<int> cnt1(1<<16, 0);  // frequencies of low bits
    std::vector<int> cnt2(1<<16, 0);  // frequencies of high bits
    for (auto x : arr) {
        cnt1[get1(x)]++;
        cnt2[get2(x)]++;
    }
    std::partial_sum(cnt1.begin(), cnt1.end(), cnt1.begin());
    std::partial_sum(cnt2.begin(), cnt2.end(), cnt2.begin());

    int n = arr.size();
    std::vector<uint32_t> tmp(n);
    for (int i = n-1; i >= 0; --i) tmp[--cnt1[get1(arr[i])]] = arr[i];
    for (int i = n-1; i >= 0; --i) arr[--cnt2[get2(tmp[i])]] = tmp[i];
}
