// Original Recurrence:
//   dp[i] = min( dp[j] + b[j]*a[i] )  for j < i
// Condition:
//   b[j] >= b[j+1]
//   a[i] <= a[i+1]
// To solve:
// Hull hull;
// FOR(i,1,n) {
//   dp[i] = hull.get(a[i]);
//   hull.add(b[i], dp[i]);
// }

const int MAXN = 100100;

struct Hull {
    long long a[MAXN], b[MAXN];
    double x[MAXN];
    int head, tail;

    Hull(): head(1), tail(0) {}

    long long get(long long xQuery) {
        if (head > tail) return 0;
        while (head < tail && x[head + 1] <= xQuery) head++;
        x[head] = xQuery;
        return a[head] * xQuery + b[head];
    }

    void add(long long aNew, long long bNew) {
        double xNew = -1e18;
        while (head <= tail) {
            if (aNew == a[tail]) return;
            xNew = 1.0 * (b[tail] - bNew) / (aNew - a[tail]);
            if (head == tail || xNew >= x[tail]) break;
            tail--;
        }
        a[++tail] = aNew;
        b[tail] = bNew;
        x[tail] = xNew;
    }
};
