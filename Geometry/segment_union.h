double segment_union(vector< pair<double, double> > segs) {
    int n = SZ(segs);
    vector< pair<double, bool> > x(n*2);
    REP(i,n) {
        x[i*2] = make_pair(segs[i].first, false);
        x[i*2+1] = make_pair(segs[i].second, true);
    }
    sort(x.begin(), x.end());

    double res = 0.0;
    int c = 0;
    REP(i,n*2) {
        if (c && i) res += x[i].first - x[i-1].first;
        if (x[i].second) ++c;
        else --c;
    }
    return res;
}

