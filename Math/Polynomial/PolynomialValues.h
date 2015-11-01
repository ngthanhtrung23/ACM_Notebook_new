// m = number of known points
// o = number of unknown points
// d[0] = values of known points
/* calculate differences */
for(i=0;i<m-1;i++) {
    for(j=1;j<m;j++) d[i+1][j]=d[i][j]-d[i][j-1];
}
for (j=0;j<o;j++) { /* generate j numbers */
    for (i=m-2;i>=0;i--)
        d[i][m-1]+=d[i+1][m-1] ;
    printf("%d%c",d[0][m-1], (j==o-1)?'\n':' ');
}
