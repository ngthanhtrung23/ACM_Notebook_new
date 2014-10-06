// Đếm số lần lặp lại chuỗi thao tác xoay rubik để nó quay trở lại trạng thái ban đầu
// U (trên), D (dưới), L (trái), R (phải), F (trước), B (sau)
// Chữ thường là xoay 90 độ theo chiều kim đồng hồ, chữ hoa là xoay 90 độ ngược chiều kim đồng hồ

int r[][8] = { { 1, 2, 3, 6, 9, 8, 7, 4 }, { 28, 29, 30, 33, 36, 35, 34, 31 },
        { 37, 38, 39, 42, 45, 44, 43, 40 }, { 19, 20, 21, 24, 27, 26, 25, 22 },
        { 46, 47, 48, 51, 54, 53, 52, 49 }, { 10, 11, 12, 15, 18, 17, 16, 13 } };

int c[][12] = { { 21, 20, 19, 10, 13, 16, 43, 44, 45, 54, 51, 48 },
                { 25, 26, 27, 46, 49, 52, 39, 38, 37, 18, 15, 12 },
                { 34, 35, 36, 52, 53, 54, 7, 8, 9, 16, 17, 18 },
                { 3, 2, 1, 48, 47, 46, 30, 29, 28, 12, 11, 10 },
                { 27, 24, 21, 1, 4, 7, 45, 42, 39, 36, 33, 30 },
                { 19, 22, 25, 28, 31, 34, 37, 40, 43, 9, 6, 3 } };

int a[55], flag[55], b[55];

void duyet(int x) {
    For(i, 1, 54) b[i] = a[i];
    Rep(i, 8) b[r[x][i]] = a[r[x][(i + 6) % 8]];
    Rep(i, 12) b[c[x][i]] = a[c[x][(i + 9) % 12]];
    For(i, 1, 54) a[i] = b[i];
}

ll rubik(string query) {
    string s = "";
    Rep(i, sz(query)) {
        if (query[i] >= 'a' && query[i] <= 'z') {
            query[i] += 'A' - 'a';
            s.pb(query[i]); s.pb(query[i]); s.pb(query[i]);
        } else s.push_back(query[i]);
    }

    For(i, 1, 54) a[i] = i;
    ms(flag, 0);

    Rep(i, sz(s)) {
        if (s[i] == 'U') duyet(0);
        else if (s[i] == 'D') duyet(1);
        else if (s[i] == 'L') duyet(2);
        else if (s[i] == 'R') duyet(3);
        else if (s[i] == 'F') duyet(4);
        else duyet(5);
    }

    ll ret = 1;
    For(i, 1, 54) if (!flag[i]) {
        int t = i;
        ll nhan = 1;
        flag[i] = 1;

        while (flag[a[t]] == 0) {
            t = a[t];
            flag[t] = 1;
            nhan++;
        }

        ret = lcm(ret, nhan);
    }

    return ret - 1;
}
