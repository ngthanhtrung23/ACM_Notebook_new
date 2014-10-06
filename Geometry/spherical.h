struct Point3 {
    double x, y, z;

    Point3(Spherical P) {
        x = P.r * cos(P.theta) * sin(P.phi);
        y = P.r * sin(P.theta) * sin(P.phi);
        z = P.r * cos(P.phi);
    }
};

// http://mathworld.wolfram.com/images/eps-gif/SphericalCoordinates_1201.gif
struct Spherical {
    double r,
        theta, // 0 <= theta < 2*PI
        phi;   // 0 <= phi <= PI

    Spherical(Point3 P) {
        r = sqrt(P.x*P.x + P.y*P.y + P.z*P.z);
        theta = atan(P.y / P.x); if (theta < 0) theta += 2 * PI;
        phi = acos(P.z / r);
    }
};
