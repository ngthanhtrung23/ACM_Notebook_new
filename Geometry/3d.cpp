struct point3 { 
   double x, y, z; 
   point3(double X=0, double Y=0, double Z=0) : x(X), y(Y), z(Z) {} 
   point3 operator+(point3 p) { return point3(x + p.x, y + p.y, z + p.z); } 
   point3 operator*(double k) { return point3(k*x, k*y, k*z); } 
   point3 operator-(point3 p) { return *this + (p*-1.0); } 
   point3 operator/(double k) { return *this*(1.0/k); } 
   double mag2() { return x*x + y*y + z*z; } 
   double mag() { return sqrt(mag2()); } 
   point3 norm() { return *this/this->mag(); } 
}; 
double dot(point3 a, point3 b) {  return a.x*b.x + a.y*b.y + a.z*b.z; } 
point3 cross(point3 a, point3 b) { 
   return point3(a.y*b.z - b.y*a.z, b.x*a.z - a.x*b.z, a.x*b.y - b.x*a.y); 
} 
struct line { 
   point3 a, b; 
   line(point3 A=point3(), point3 B=point3()) : a(A), b(B) {} 
   point3 dir() { return (b - a).norm(); } 
}; 
point3 cpoint_iline(line u, point3 p) {// Closest point on line u to a given point p 
   point3 ud = u.dir(); 
   return u.a - ud*dot(u.a - p, ud); 
} 
double dist_ilines(line u, line v) { // Shortest distance between two lines u and v 
   return dot(v.a - u.a, cross(u.dir(), v.dir()).norm()); 
} 
point3 cpoint_ilines(line u, line v) { // Finds the closest point line u to line v. 
   // Assumes non-parallel lines 
   point3 ud = u.dir(); point3 vd = v.dir(); 
   double uu = dot(ud, ud), vv = dot(vd, vd), uv = dot(ud, vd); 
   double t = dot(u.a, ud) - dot(v.a, ud); t *= vv; 
   t -= uv*(dot(u.a, vd) - dot(v.a, vd)); 
   t /= (uv*uv - uu*vv); 
   return u.a + ud*t; 
} 
point3 cpoint_lineseg(line u, point3 p) { // Closest point on a segment u       
   point3 ud = u.b - u.a; double s = dot(u.a - p, ud)/ud.mag2(); 
   if (s < -1.0) return u.b; 
   if (s > 0.0) return u.a; 
   return u.a - ud*s; 
} 
struct plane { 
   point3 n, p; 
   plane(point3 ni = point3(), point3 pi = point3()) : n(ni), p(pi) {} 
   plane(point3 a, point3 b, point3 c) : n(cross(b-a, c-a).norm()), p(a) {} 
   double d() { return -dot(n, p); } 
}; 
point3 cpoint_plane(plane u, point3 p) { // Closest point on a plane u 
   return p - u.n*(dot(u.n, p) + u.d()); 
} 
point3 iline_isect_plane(plane u, line v) {
   // Point of intersection between an infinite line v and a plane u. 
   // Assumes line not parallel to plane. 
   point3 vd = v.dir(); 
   return v.a - vd*((dot(u.n, v.a) + u.d())/dot(u.n, vd)); 
} 
line isect_planes(plane u, plane v) { 
   // Infinite line of intersection between two planes u and v. 
   // Assumes planes not parallel. 
   point3 o = u.n*-u.d(), uv = cross(u.n, v.n); 
   point3 uvu = cross(uv, u.n); 
   point3 a = o - uvu*((dot(v.n, o) + v.d())/(dot(v.n, uvu)*uvu.mag2())); 
   return line(a, a + uv); 
}
