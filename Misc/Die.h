const int rotations[6][4] = {
    {1, 4, 0, 5}, // left
    {1, 5, 0, 4}, // right
    {4, 3, 5, 2}, // up
    {4, 2, 5, 3}, // down
};
struct Die;
map<int, Die> dieMap;
struct Die {
    int arr[6]; /* 0 right, 1 left, 2 forward, 3 backward, 4 top, 5 bottom */
    Die(){ REP(i,6) arr[i] = i; }
    Die(int cipher) { // 0 -> 23
        if (dieMap.empty()) puts("Call openDie(die());"); else (*this) = dieMap[cipher];
    }
    Die move(int dir) {
        Die res = (*this);
        int t = res.arr[rotations[dir][0]];
        REP(i,3) res.arr[rotations[dir][i]] = res.arr[rotations[dir][i+1]];
        res.arr[rotations[dir][3]] = t;
        return res;
    }
    int encrypt() { // 0 -> 23
        int res = arr[0] * 4;
        FOR(i,3,5) if (arr[i] < arr[2]) res++;
        return res;
    }
};
void openDie(Die t) {
    dieMap[t.encrypt()] = t;
    REP(dir,4) if (!dieMap.count(t.move(dir).encrypt())) openDie(t.move(dir));
}

