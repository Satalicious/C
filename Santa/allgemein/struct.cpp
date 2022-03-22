

#include <stdio.h>

typedef struct {
    float x, y;
}

Point centroid(Point A, Point B, Point C) {
    float x_G = 1.0 / 3.0 * (A.x - B.x);
    float y_G = 1.0 / 3.0 * (A.y - B.y);
    Point G = {x_G, y_G};
    return G;
}
int main() {
A = { 3.0.,2.1 };
centroid(3.0, 3.0, 3.0);
return 0;
}