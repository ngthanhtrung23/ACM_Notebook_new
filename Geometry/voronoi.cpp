// Source: http://web.mit.edu/~ecprice/acm/acm08/notebook.html#file7
#define MAXN 1024
#define INF 1000000

//Voronoi diagrams: O(N^2*LogN)
//Convex hull: O(N*LogN)
typedef struct {
  int id;
  double x;
  double y;
  double ang;
} chp;

int n;
double x[MAXN], y[MAXN]; // Input points
chp inv[2*MAXN]; // Points after inversion (to be given to Convex Hull)
int vors;
int vor[MAXN]; // Set of points in convex hull; 
               //starts at lefmost; last same as first!!
PT ans[MAXN][2];

int chpcmp(const void *aa, const void *bb) {
  double a = ((chp *)aa)->ang;
  double b = ((chp *)bb)->ang;
  if (a<b) return -1;
  else if (a>b) return 1;
  else return 0; // Might be better to include a 
                 // tie-breaker on distance, instead of the cheap hack below
}

int orient(chp *a, chp *b, chp *c) {
  double s = a->x*(b->y-c->y) + b->x*(c->y-a->y) + c->x*(a->y-b->y);
  if (s>0) return 1;
  else if (s<0) return -1;
  else if (a->ang==b->ang && a->ang==c->ang) return -1; // Cheap hack 
           //for points with same angles
  else return 0;
}

//the pt argument must have the points with precomputed angles (atan2()'s)
//with respect to a point on the inside (e.g. the center of mass)
int convexHull(int n, chp *pt, int *ans) {
  int i, j, st, anses=0;

  qsort(pt, n, sizeof(chp), chpcmp);
  for (i=0; i<n; i++) pt[n+i] = pt[i];
  st = 0;
  for (i=1; i<n; i++) { // Pick leftmost (bottommost) 
                        //point to make sure it's on the convex hull
    if (pt[i].x<pt[st].x || (pt[i].x==pt[st].x && pt[i].y<pt[st].y)) st = i;
  }
  ans[anses++] = st;
  for (i=st+1; i<=st+n; i++) {
    for (j=anses-1; j; j--) {
      if (orient(pt+ans[j-1], pt+ans[j], pt+i)>=0) break;
      // Should change the above to strictly greater,
      // if you don't want points that lie on the side (not on a vertex) of the hull
      // If you really want them, you might also put an epsilon in orient
    }
    ans[j+1] = i;
    anses = j+2;
  }
  for (i=0; i<anses; i++) ans[i] = pt[ans[i]].id;
  return anses;
}

int main(void) {
  int i, j, jj;
  double tmp;

  scanf("%d", &n);
  for (i=0; i<n; i++) scanf("%lf %lf", &x[i], &y[i]);
  for (i=0; i<n; i++) {
    x[n] = 2*(-INF)-x[i]; y[n] = y[i];
    x[n+1] = x[i]; y[n+1] = 2*INF-y[i];
    x[n+2] = 2*INF-x[i]; y[n+2] = y[i];
    x[n+3] = x[i]; y[n+3] = 2*(-INF)-y[i];
    for (j=0; j<n+4; j++) if (j!=i) {
      jj = j - (j>i);
      inv[jj].id = j;
      tmp = (x[j]-x[i])*(x[j]-x[i]) + (y[j]-y[i])*(y[j]-y[i]);
      inv[jj].x = (x[j]-x[i])/tmp;
      inv[jj].y = (y[j]-y[i])/tmp;
      inv[jj].ang = atan2(inv[jj].y, inv[jj].x);
    }
    vors = convexHull(n+3, inv, vor);
    // Build bisectors
    for (j=0; j<vors; j++) {
      ans[j][0].x = (x[i]+x[vor[j]])/2;
      ans[j][0].y = (y[i]+y[vor[j]])/2;
      ans[j][1].x = ans[j][0].x - (y[vor[j]]-y[i]);
      ans[j][1].y = ans[j][0].y + (x[vor[j]]-x[i]);
    }
    printf("Around (%lf, %lf)\n", x[i], y[i]);
    // List all intersections of the bisectors
    for (j=1; j<vors; j++) {
      PT vv;
      vv = ComputeLineIntersection(ans[j-1][0], ans[j-1][1],
				   ans[j][0], ans[j][1]);
      printf("%lf, %lf\n", vv.x, vv.y);
    }
    printf("\n");
  }
  return 0;
}
