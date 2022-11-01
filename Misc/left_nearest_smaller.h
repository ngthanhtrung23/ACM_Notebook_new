// Nearest smaller {{{
// Tested:
// - https://cses.fi/problemset/task/1645
// - https://cses.fi/problemset/task/1142
// - https://oj.vnoi.info/problem/kagain
//
// return:
// - left[i] = largest j such that
//      j < i
//      a[j] < a[i]
// - no such j -> left[i] = -1
vector<int> leftNearestSmaller(const vector<int>& a) {
    int n = a.size();
    vector<int> left(n);
    stack<int> st;  // positions of candidates, A is increasing
    st.push(-1);
    for (int i = 0; i < n; i++) {
        while (st.top() >= 0 && a[st.top()] >= a[i]) st.pop();
        left[i] = st.top();
        st.push(i);
    }
    return left;
}

// return:
// - right[i] = smallest j such that:
//      j > i
//      a[j] < a[i]
// - no such j -> right[i] = n
vector<int> rightNearestSmaller(const vector<int>& a) {
    int n = a.size();
    vector<int> right(n);
    stack<int> st;   // positions of candidates, A is increasing
    st.push(n);
    for (int i = n-1; i >= 0; i--) {
        while (st.top() < n && a[st.top()] >= a[i]) st.pop();
        right[i] = st.top();
        st.push(i);
    }
    return right;
}
// }}}
