/* Numbered from 0
 * For man i, L[i] = list of women in order of decreasing preference
 * For women j, R[j][i] = index of man i in j-th women's list of preference
 * OUTPUTS:
 *      - L2R[]:    the mate of man i (always between 0 and n-1)
 *      - R2L[]:    the mate of woman j (or -1 if single)
 * COMPLEXITY: M^2
 */

#define MAXM 1024
#define MAXW 1024
int m;
int L[MAXM][MAXW], R[MAXW][MAXM];
int L2R[MAXM], R2L[MAXW];
int p[MAXM];
void stableMarriage(){
    static int p[128];
    memset(R2L, -1, sizeof R2L);
    memset(p, 0, sizeof p);
    // Each man proposes...
    for(int i = 0; i < m; i++) {
        int man = i;
        while (man >= 0) { // propose until success
            int wom;
            while (1) {
                wom = L[man][p[man]++];
                if (R2L[wom] < 0 || R[wom][man] > R[wom][R2L[wom]]) break;
            }
            int hubby = R2L[wom];
            R2L[L2R[man] = wom] = man;
            man = hubby; // remarry the dumped guy
        }
    }
}
