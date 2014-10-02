/*
 * PARAMETERS:
 * graph[i][j] is true iff there is an edge from pigeon i to hole j
 * RETURNS:
 *      - an integer corresponding to the number of assignments
 *      - matchL[m]: for each pigeon, a hole or -1
 *      - matchR[n]: for each hole, a pigeon or -1
 *  COMPLEXITY:
 *      - O(m*n^2)
 */
#include <string.h>
#define M 128
#define N 128
bool graph[M][N];
bool seen[N];
int matchL[M], matchR[N];
int n, m;
bool bpm( int u ){
    for( int v = 0; v < n; v++ ) if( graph[u][v] ){
        if( seen[v] ) continue;
        seen[v] = true;
        if( matchR[v] < 0 || bpm( matchR[v] ) ){
            matchL[u] = v;
            matchR[v] = u;
            return true;
        }
    }
    return false;
}
int main(){    
    // Read input and populate graph[][]
    // Set m, n
    memset( matchL, -1, sizeof( matchL ) );
    memset( matchR, -1, sizeof( matchR ) );
    int cnt = 0;
    for( int i = 0; i < m; i++ ) {
        memset( seen, 0, sizeof( seen ) );
        if( bpm( i ) ) cnt++;
    }
    return 0;
}