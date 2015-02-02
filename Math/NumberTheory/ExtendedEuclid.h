// Dùng Extended Euclid để tìm nghiệm của phương trình ax + by = gcd(a, b).
// Giả sử kết quả trả về là (x0, y0), họ nghiệm của phương trình sẽ là (x_0+kb/d,y_0-ka/d) với k∈Z.
// Phương trình tổng quát ax + by = d chỉ có nghiệm khi d chia hết cho gcd(a, b).
// a x + b y = gcd(a, b)
int extgcd(int a, int b, int &x, int &y) {
    int g = a; x = 1; y = 0;
    if (b != 0) g = extgcd(b, a % b, y, x), y -= (a / b) * x;
    return g;
}
