#include "template.h"
#include "Graph/Matching/GeneralMatching.h"

int main() {
    //freopen("input.txt","r",stdin);
    int n,m,u,v;
    scanf("%d%d",&n,&m);
    edmonds.init(n);
    for(int i=0; i<m; ++i){
        scanf("%d%d",&u,&v);
        edmonds.add(u,v);
        edmonds.add(v,u);
    }
    printf("%d\n",n - edmonds.maxmat());
}
