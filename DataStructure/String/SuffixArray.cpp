// O(N*logN) implementation. Should switch to dc3 algo in O(N)
// Input: a, Output: s. Indices from 1
void initsuffix() {
     int i,h,x;
     memset(tam,0,sizeof(tam));
     FOR(i,1,n) tam[a[i]]++;
     FOR(i,1,256) tam[i] += tam[i-1];
     DOWN(i,n,1) s[tam[a[i]]--] = i;
     x = 0;
     pos[0] = 1;
     key[s[1]] = 0;
     FOR(i,2,n) {
         if (a[s[i]] != a[s[i-1]]) pos[++x] = i;
         key[s[i]] = x;
     }
     h = 1;
     while (h < n) {
           FOR(i,1,n) tam[i]=s[i];
           FOR(i,1,n) if (tam[i] > h) {
               x = tam[i] - h;
               s[pos[key[x]]] = x;
               pos[key[x]]++;
           }
           x = 0;
           pos[0] = 1;
           tam[s[1]] = 0;
           FOR(i,2,n) {
              if ((key[s[i-1]] < key[s[i]]) || ((key[s[i-1]] == key[s[i]]) && (s[i-1] + h <=n) && (s[i] + h <= n) && (key[s[i-1] + h] < key[s[i] + h])))
              pos[++x] = i;
              tam[s[i]] = x;
           }
           FOR(i,1,n) key[i] = tam[i];
           if (x == n-1) break;
           h = h << 1;
     }
};
/*--------------------------------------*/
void initlcp() {
     int i,j,h = 0,x;
     a[n + 1] = '@';
     int result = 0;
     FOR(i,1,n) inv[s[i]] = i;
     FOR(i,1,n)
     if (inv[i] == 1) lcp[1] = 0;
     else {
              x = inv[i];
              j = s[x - 1];
              while (a[j + h] == a[i + h]) h++;
              lcp[x] = h;
              if (h > 0) h--;
          }
}