// z[i] = độ dài xâu con dài nhất bắt đầu từ vị trí i mà trùng với đoạn đầu của v[]
void zfunc(string v, vector<int> &z) {
    int n = v.length(); z.resize(n);
    int l = 0, r = -1;
    z[0] = 0;
    for(int i = 1; i < n-1; ++i) {
        int k = (i > r) ? 0 : min(z[i - l], r - i + 1);
        while (i + k < n && v[k] == v[i + k]) ++k;
        z[i] = k;
        if (i + k - 1 > r) {
            l = i;
            r = i + k - 1;
        }
    }
    z[0] = n;
}
