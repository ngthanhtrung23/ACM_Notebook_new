---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - http://web.mit.edu/~ecprice/acm/acm08/notebook.html#file7
  bundledCode: "#line 1 \"Geometry/voronoi.cpp\"\n// Source: http://web.mit.edu/~ecprice/acm/acm08/notebook.html#file7\n\
    #define MAXN 1024\n#define INF 1000000\n\n//Voronoi diagrams: O(N^2*LogN)\n//Convex\
    \ hull: O(N*LogN)\ntypedef struct {\n  int id;\n  double x;\n  double y;\n  double\
    \ ang;\n} chp;\n\nint n;\ndouble x[MAXN], y[MAXN]; // Input points\nchp inv[2*MAXN];\
    \ // Points after inversion (to be given to Convex Hull)\nint vors;\nint vor[MAXN];\
    \ // Set of points in convex hull; \n               //starts at lefmost; last\
    \ same as first!!\nPT ans[MAXN][2];\n\nint chpcmp(const void *aa, const void *bb)\
    \ {\n  double a = ((chp *)aa)->ang;\n  double b = ((chp *)bb)->ang;\n  if (a<b)\
    \ return -1;\n  else if (a>b) return 1;\n  else return 0; // Might be better to\
    \ include a \n                 // tie-breaker on distance, instead of the cheap\
    \ hack below\n}\n\nint orient(chp *a, chp *b, chp *c) {\n  double s = a->x*(b->y-c->y)\
    \ + b->x*(c->y-a->y) + c->x*(a->y-b->y);\n  if (s>0) return 1;\n  else if (s<0)\
    \ return -1;\n  else if (a->ang==b->ang && a->ang==c->ang) return -1; // Cheap\
    \ hack \n           //for points with same angles\n  else return 0;\n}\n\n//the\
    \ pt argument must have the points with precomputed angles (atan2()'s)\n//with\
    \ respect to a point on the inside (e.g. the center of mass)\nint convexHull(int\
    \ n, chp *pt, int *ans) {\n  int i, j, st, anses=0;\n\n  qsort(pt, n, sizeof(chp),\
    \ chpcmp);\n  for (i=0; i<n; i++) pt[n+i] = pt[i];\n  st = 0;\n  for (i=1; i<n;\
    \ i++) { // Pick leftmost (bottommost) \n                        //point to make\
    \ sure it's on the convex hull\n    if (pt[i].x<pt[st].x || (pt[i].x==pt[st].x\
    \ && pt[i].y<pt[st].y)) st = i;\n  }\n  ans[anses++] = st;\n  for (i=st+1; i<=st+n;\
    \ i++) {\n    for (j=anses-1; j; j--) {\n      if (orient(pt+ans[j-1], pt+ans[j],\
    \ pt+i)>=0) break;\n      // Should change the above to strictly greater,\n  \
    \    // if you don't want points that lie on the side (not on a vertex) of the\
    \ hull\n      // If you really want them, you might also put an epsilon in orient\n\
    \    }\n    ans[j+1] = i;\n    anses = j+2;\n  }\n  for (i=0; i<anses; i++) ans[i]\
    \ = pt[ans[i]].id;\n  return anses;\n}\n\nint main(void) {\n  int i, j, jj;\n\
    \  double tmp;\n\n  scanf(\"%d\", &n);\n  for (i=0; i<n; i++) scanf(\"%lf %lf\"\
    , &x[i], &y[i]);\n  for (i=0; i<n; i++) {\n    x[n] = 2*(-INF)-x[i]; y[n] = y[i];\n\
    \    x[n+1] = x[i]; y[n+1] = 2*INF-y[i];\n    x[n+2] = 2*INF-x[i]; y[n+2] = y[i];\n\
    \    x[n+3] = x[i]; y[n+3] = 2*(-INF)-y[i];\n    for (j=0; j<n+4; j++) if (j!=i)\
    \ {\n      jj = j - (j>i);\n      inv[jj].id = j;\n      tmp = (x[j]-x[i])*(x[j]-x[i])\
    \ + (y[j]-y[i])*(y[j]-y[i]);\n      inv[jj].x = (x[j]-x[i])/tmp;\n      inv[jj].y\
    \ = (y[j]-y[i])/tmp;\n      inv[jj].ang = atan2(inv[jj].y, inv[jj].x);\n    }\n\
    \    vors = convexHull(n+3, inv, vor);\n    // Build bisectors\n    for (j=0;\
    \ j<vors; j++) {\n      ans[j][0].x = (x[i]+x[vor[j]])/2;\n      ans[j][0].y =\
    \ (y[i]+y[vor[j]])/2;\n      ans[j][1].x = ans[j][0].x - (y[vor[j]]-y[i]);\n \
    \     ans[j][1].y = ans[j][0].y + (x[vor[j]]-x[i]);\n    }\n    printf(\"Around\
    \ (%lf, %lf)\\n\", x[i], y[i]);\n    // List all intersections of the bisectors\n\
    \    for (j=1; j<vors; j++) {\n      PT vv;\n      vv = ComputeLineIntersection(ans[j-1][0],\
    \ ans[j-1][1],\n\t\t\t\t   ans[j][0], ans[j][1]);\n      printf(\"%lf, %lf\\n\"\
    , vv.x, vv.y);\n    }\n    printf(\"\\n\");\n  }\n  return 0;\n}\n"
  code: "// Source: http://web.mit.edu/~ecprice/acm/acm08/notebook.html#file7\n#define\
    \ MAXN 1024\n#define INF 1000000\n\n//Voronoi diagrams: O(N^2*LogN)\n//Convex\
    \ hull: O(N*LogN)\ntypedef struct {\n  int id;\n  double x;\n  double y;\n  double\
    \ ang;\n} chp;\n\nint n;\ndouble x[MAXN], y[MAXN]; // Input points\nchp inv[2*MAXN];\
    \ // Points after inversion (to be given to Convex Hull)\nint vors;\nint vor[MAXN];\
    \ // Set of points in convex hull; \n               //starts at lefmost; last\
    \ same as first!!\nPT ans[MAXN][2];\n\nint chpcmp(const void *aa, const void *bb)\
    \ {\n  double a = ((chp *)aa)->ang;\n  double b = ((chp *)bb)->ang;\n  if (a<b)\
    \ return -1;\n  else if (a>b) return 1;\n  else return 0; // Might be better to\
    \ include a \n                 // tie-breaker on distance, instead of the cheap\
    \ hack below\n}\n\nint orient(chp *a, chp *b, chp *c) {\n  double s = a->x*(b->y-c->y)\
    \ + b->x*(c->y-a->y) + c->x*(a->y-b->y);\n  if (s>0) return 1;\n  else if (s<0)\
    \ return -1;\n  else if (a->ang==b->ang && a->ang==c->ang) return -1; // Cheap\
    \ hack \n           //for points with same angles\n  else return 0;\n}\n\n//the\
    \ pt argument must have the points with precomputed angles (atan2()'s)\n//with\
    \ respect to a point on the inside (e.g. the center of mass)\nint convexHull(int\
    \ n, chp *pt, int *ans) {\n  int i, j, st, anses=0;\n\n  qsort(pt, n, sizeof(chp),\
    \ chpcmp);\n  for (i=0; i<n; i++) pt[n+i] = pt[i];\n  st = 0;\n  for (i=1; i<n;\
    \ i++) { // Pick leftmost (bottommost) \n                        //point to make\
    \ sure it's on the convex hull\n    if (pt[i].x<pt[st].x || (pt[i].x==pt[st].x\
    \ && pt[i].y<pt[st].y)) st = i;\n  }\n  ans[anses++] = st;\n  for (i=st+1; i<=st+n;\
    \ i++) {\n    for (j=anses-1; j; j--) {\n      if (orient(pt+ans[j-1], pt+ans[j],\
    \ pt+i)>=0) break;\n      // Should change the above to strictly greater,\n  \
    \    // if you don't want points that lie on the side (not on a vertex) of the\
    \ hull\n      // If you really want them, you might also put an epsilon in orient\n\
    \    }\n    ans[j+1] = i;\n    anses = j+2;\n  }\n  for (i=0; i<anses; i++) ans[i]\
    \ = pt[ans[i]].id;\n  return anses;\n}\n\nint main(void) {\n  int i, j, jj;\n\
    \  double tmp;\n\n  scanf(\"%d\", &n);\n  for (i=0; i<n; i++) scanf(\"%lf %lf\"\
    , &x[i], &y[i]);\n  for (i=0; i<n; i++) {\n    x[n] = 2*(-INF)-x[i]; y[n] = y[i];\n\
    \    x[n+1] = x[i]; y[n+1] = 2*INF-y[i];\n    x[n+2] = 2*INF-x[i]; y[n+2] = y[i];\n\
    \    x[n+3] = x[i]; y[n+3] = 2*(-INF)-y[i];\n    for (j=0; j<n+4; j++) if (j!=i)\
    \ {\n      jj = j - (j>i);\n      inv[jj].id = j;\n      tmp = (x[j]-x[i])*(x[j]-x[i])\
    \ + (y[j]-y[i])*(y[j]-y[i]);\n      inv[jj].x = (x[j]-x[i])/tmp;\n      inv[jj].y\
    \ = (y[j]-y[i])/tmp;\n      inv[jj].ang = atan2(inv[jj].y, inv[jj].x);\n    }\n\
    \    vors = convexHull(n+3, inv, vor);\n    // Build bisectors\n    for (j=0;\
    \ j<vors; j++) {\n      ans[j][0].x = (x[i]+x[vor[j]])/2;\n      ans[j][0].y =\
    \ (y[i]+y[vor[j]])/2;\n      ans[j][1].x = ans[j][0].x - (y[vor[j]]-y[i]);\n \
    \     ans[j][1].y = ans[j][0].y + (x[vor[j]]-x[i]);\n    }\n    printf(\"Around\
    \ (%lf, %lf)\\n\", x[i], y[i]);\n    // List all intersections of the bisectors\n\
    \    for (j=1; j<vors; j++) {\n      PT vv;\n      vv = ComputeLineIntersection(ans[j-1][0],\
    \ ans[j-1][1],\n\t\t\t\t   ans[j][0], ans[j][1]);\n      printf(\"%lf, %lf\\n\"\
    , vv.x, vv.y);\n    }\n    printf(\"\\n\");\n  }\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Geometry/voronoi.cpp
  requiredBy: []
  timestamp: '2015-04-09 07:01:21+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Geometry/voronoi.cpp
layout: document
redirect_from:
- /library/Geometry/voronoi.cpp
- /library/Geometry/voronoi.cpp.html
title: Geometry/voronoi.cpp
---
