#include "template.h"
#include "Graph/Matching/HungarianAssignment.h"

int m,n,e;

int main() {
    freopen("input.txt","r",stdin);
    scanf("%d",&m); n=m;
    hungary.init(m,n);
    int x,y,w;
    while(scanf("%d%d%d",&x,&y,&w) == 3) hungary.add(y,x,w);
    printf("%d\n",hungary.mincost());
    for(int y=1; y<=hungary.ny; ++y){
        int x=hungary.maty[y];
        if(hungary.cost[x][y] < inf) printf("%d %d\n",y,x);
    }
}
