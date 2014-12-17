#include "template.h"
// sinh bo 3 pytago voi x, y, z <= n
vector< vector<int> > genPytTriples(int n) {
    vector< vector<int> > ret;
    for (int r=1; r*r<=n; ++r) for (int s=(r%2==0)?1:2; s<r; s+=2) if (__gcd(r,s)==1) {
        vector<int> t,h;
        t.push_back(r*r+s*s); //z 
        t.push_back(2*r*s); // y
        t.push_back(r*r-s*s); // x
        h=t;
        while (h[0]<=n) {
            ret.push_back(h);        
            h[0]+=t[0]; h[1]+=t[1]; h[2]+=t[2];            
        }
    }
    sort(ret.begin(), ret.end());
    return ret;
}
// sinh bo 3 pytago nguyen thuy voi x, y, z <= n
vector< vector<int> > genPrimitivePytTriples(int n) {
    vector< vector<int> > ret;
    for (int r=1; r*r<=n; ++r) for (int s=(r%2==0)?1:2; s<r; s+=2) if (__gcd(r,s)==1) {
        vector<int> t;
        t.push_back(r*r+s*s); //z 
        t.push_back(2*r*s); // y
        t.push_back(r*r-s*s); // x
        if (t[0]<=n) ret.push_back(t);        
    }
    sort(ret.begin(), ret.end());
    return ret;
}
