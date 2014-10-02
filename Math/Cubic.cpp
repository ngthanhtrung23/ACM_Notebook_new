struct Result {
    int n; // Number of solutions
    double x[3]; // Solutions
};
Result solve_cubic(double a, double b, double c, double d) {
    long double a1 = b/a, a2 = c/a, a3 = d/a;
    long double q = (a1*a1 - 3*a2)/9.0, sq = -2*sqrt(q);
    long double r = (2*a1*a1*a1 - 9*a1*a2 + 27*a3)/54.0;
    double z = r*r-q*q*q, theta;
    Result s;
    if(z <= 0) {
        s.n = 3; theta = acos(r/sqrt(q*q*q));
        s.x[0] = sq*cos(theta/3.0) - a1/3.0;
        s.x[1] = sq*cos((theta+2.0*PI)/3.0) - a1/3.0;
        s.x[2] = sq*cos((theta+4.0*PI)/3.0) - a1/3.0;
    }
    else {
        s.n = 1; s.x[0] = pow(sqrt(z)+fabs(r),1/3.0);
        s.x[0] += q/s.x[0]; s.x[0] *= (r < 0) ? 1 : -1;
        s.x[0] -= a1/3.0;
    }
    return s;
}