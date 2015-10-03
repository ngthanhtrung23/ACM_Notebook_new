// Checks if rectangle of sides x,y fits inside one of sides X,Y
// Not tested with doubles but should work fine :)
// Code as written rejects rectangles that just touch.
bool rect_in_rect(int X, int Y, int x, int y) {
    if (Y > X) swap(Y, X);
    if (y > x) swap(y, x);
    double diagonal = sqrt(double(X)*X + double(Y)*Y);
    if (x < X && y < Y) return true;
    else if (y >= Y || x >= diagonal) return false;
    else {
        double w, theta, tMin = PI/4, tMax = PI/2;
        while (tMax - tMin > EPS) {
            theta = (tMax + tMin)/2.0;
            w = (Y-x*cos(theta))/sin(theta);
            if (w < 0 || x * sin(theta) + w * cos(theta) < X) tMin = theta;
            else tMax = theta;
        }
        return (w > y);
    }
}
