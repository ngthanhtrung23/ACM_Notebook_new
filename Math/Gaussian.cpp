const double EPS = 1e-9;
int n;
vector < vector<double> > a (n, vector<double> (n+1));
//Input the matrix a
REP(i,n) {
   int k = i;
   for (int j=i+1; j<n; ++j)
      if (abs (a[j][i]) > abs (a[k][i]))  k = j;
   swap (a[i], a[k]);
   for (int j=i+1; j<=n; ++j)
      a[i][j] /= a[i][i];
   for (int j=0; j<n; ++j)
      if (j != i)
         for (int k=i+1; k<=n; ++k)
            a[j][k] -= a[i][k] * a[j][i];
}
REP(i,n)
        printf ("%.15lf\n", a[i][n]);