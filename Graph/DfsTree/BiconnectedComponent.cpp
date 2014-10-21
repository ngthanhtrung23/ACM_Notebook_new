// http://vn.spoj.com/problems/SAFENET2/
// Problem: Output the maximum size of a biconnected component

#include <bits/stdc++.h>
using namespace std;

int n;
vector <int> a[30000];

struct BiconnectedComponent {
  vector<int> low, num, s;
  vector< vector<int> > components;
  int counter;

  BiconnectedComponent() : num(n, -1), low(n, -1), counter(0) {
    for (int i = 0; i < n; i++)
      if (num[i] < 0)
        dfs(i, 1);
  }

  void dfs(int x, int isRoot) {
    low[x] = num[x] = ++counter;
    if (a[x].empty()) {
      components.push_back(vector<int>(1, x));
      return;
    }
    s.push_back(x);

    for (int i = 0; i < a[x].size(); i++) {
      int y = a[x][i];
      if (num[y] > -1) low[x] = min(low[x], num[y]);
      else {
        dfs(y, 0);
        low[x] = min(low[x], low[y]);

        if (isRoot || low[y] >= num[x]) {
          components.push_back(vector<int>(1, x));
          while (1) {
            int u = s.back();
            s.pop_back();
            components.back().push_back(u);
            if (u == y) break;
          }
        }
      }
    }
  }
};

int main()
{
  int m, x, y;
  scanf("%d%d", &n, &m);
  while (m--)
  {
    scanf("%d%d", &x, &y);
    a[--x].push_back(--y);
    a[y].push_back(x);
  }

  BiconnectedComponent bc;
  int ans = 0;
  for (int i = 0; i < bc.components.size(); i++)
    ans = max(ans, int(bc.components[i].size()));
  printf("%d\n", ans);
}
