// Tested:
// - http://codeforces.com/gym/100216 - C
// - SRM 676 - 1000
// - SRM 694 - 900
// m = # inequalities, n = #variables
// variables numbered from 0
// C[0] = objective function (max)
// C[1..m] = leq equations:
//    sum( C[i][j] * X[j] ) <= C[i][n]
// Return: -INF if infeasible, INF if unbounded, max otherwise
#define MAXM 400 // leave one extra 
#define MAXN 400 // leave one extra 
#define EPS 1e-9 
#define INF 1.0/0.0 
double A[MAXM][MAXN]; 
int basis[MAXM], out[MAXN]; 
void pivot(int m, int n, int a, int b) { 
    int i,j; 
    for (i=0;i<=m;i++) 
        if (i!=a) 
            for (j=0;j<=n;j++)
                if (j!=b) 
                    A[i][j] -= A[a][j] * A[i][b] / A[a][b]; 
    for (j=0;j<=n;j++) 
        if (j!=b) A[a][j] /= A[a][b]; 
    for (i=0;i<=m;i++) 
        if (i!=a) A[i][b] = -A[i][b]/A[a][b]; 
            A[a][b] = 1/A[a][b]; 
    swap(basis[a], out[b]);
} 
double simplex(int m, int n, double C[][MAXN], double X[]) { 
    int i,j,ii,jj; // i,ii are row indexes; j,jj are column indexes 
    for (i=1;i<=m;i++) 
        for (j=0;j<=n;j++) 
            A[i][j] = C[i][j]; 
    for (j=0;j<=n;j++) A[0][j] = -C[0][j]; 
    for (i=0;i<=m;i++) basis[i] = -i; 
    for (j=0;j<=n;j++) out[j] = j; 
    for(;;) { 
        for (i=ii=1;i<=m;i++) 
            if (A[i][n]<A[ii][n] || (A[i][n]==A[ii][n] && basis[i]<basis[ii])) 
                ii=i; 
        if (A[ii][n] >= -EPS) break; 
        for (j=jj=0;j<n;j++) 
            if (A[ii][j]<A[ii][jj]-EPS || (A[ii][j]<A[ii][jj]-EPS && out[i]<out[j])) 
                jj=j;
        if (A[ii][jj] >= -EPS) return -INF; 
        pivot(m,n,ii,jj); 
    } 
    for(;;) { 
        for (j=jj=0;j<n;j++) 
            if (A[0][j]<A[0][jj] || (A[0][j]==A[0][jj] && out[j]<out[jj])) 
                jj=j; 
        if (A[0][jj] > -EPS) break; 
        for (i=1,ii=0;i<=m;i++) 
            if ((A[i][jj]>EPS) && 
                    (!ii || (A[i][n]/A[i][jj] < A[ii][n]/A[ii][jj]-EPS) || 
                ((A[i][n]/A[i][jj] < A[ii][n]/A[ii][jj]+EPS) && (basis[i] < basis[ii])))) 
            ii=i; 
        if (A[ii][jj] <= EPS) return INF; 
        pivot(m,n,ii,jj); 
    } 
    for (j=0;j<n;j++)
        X[j] = 0; 
    for (i=1;i<=m;i++) 
        if (basis[i] >= 0) 
            X[basis[i]] = A[i][n]; 
    return A[0][n]; 
} 
