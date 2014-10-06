struct die;
map<int, die> dieMap;
struct die {
    int arr[6]; /* 0 right, 1 left, 2 forward, 3 backward, 4 top, 5 bottom */
    die(){ Rep(i,6) arr[i] = i; }
    die(int cipher) { // 0 -> 23
        if (dieMap.empty()) puts("Call openDie(die());"); else (*this) = dieMap[cipher];
    }
    die moveLeft() {
        die res =(*this);
        int t = res.arr[1];
        res.arr[1] = res.arr[4]; res.arr[4] = res.arr[0]; res.arr[0] = res.arr[5]; res.arr[5] = t;
        return res;
    }
    die moveRight() {
        die res =(*this);
        int t = res.arr[1];
        res.arr[1] = res.arr[5]; res.arr[5] = res.arr[0]; res.arr[0] = res.arr[4]; res.arr[4] = t;
        return res;
    }
    die moveUp() {
        die res =(*this);
        int t = res.arr[4];
        res.arr[4] = res.arr[3]; res.arr[3] = res.arr[5]; res.arr[5] = res.arr[2]; res.arr[2] = t;
        return res;
    }
    die moveDown() {
        die res =(*this);
        int t = res.arr[4];
        res.arr[4] = res.arr[2]; res.arr[2] = res.arr[5]; res.arr[5] = res.arr[3];
        res.arr[3] = t;
        return res;
    }
    int encrypt() { // 0 -> 23
        int res = arr[0] * 4;
        For(i,3,5) if (arr[i] < arr[2]) res++;
        return res;
    }
};
void openDie(die t) {
    dieMap[t.encrypt()] = t;
    if(dieMap.find(t.moveLeft().encrypt()) == dieMap.end()) openDie(t.moveLeft());
    if(dieMap.find(t.moveRight().encrypt()) == dieMap.end()) openDie(t.moveRight());
    if(dieMap.find(t.moveUp().encrypt()) == dieMap.end()) openDie(t.moveUp());
    if(dieMap.find(t.moveDown().encrypt()) == dieMap.end()) openDie(t.moveDown());
}
