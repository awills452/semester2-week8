#include <stdbool.h>
#include <math.h>

#include "shapes.h"

Point makePoint( float x, float y ) {
    Point new;
    new.x = x;
    new.y = y;
    return new;
}

Line makeLine( Point p1, Point p2 ) {
    Line new;
    new.p[0] = p1;
    new.p[1] = p2;
    return new;
}

Triangle makeTriangle( Point p1, Point p2, Point p3 ) {
    Triangle new;
    new.p[0] = p1;
    new.p[1] = p2;
    new.p[2] = p3;
    return new;
}

float lineLength( Line l ) {
    float dx = l.p[1].x - l.p[0].x;
    float dy = l.p[1].y - l.p[0].y;
    return sqrt(dx*dx + dy*dy);
}

float triangleArea( Triangle t ) {
    // shoelace formula
    float area = (t.p[0].x * (t.p[1].y - t.p[2].y) +
                  t.p[1].x * (t.p[2].y - t.p[0].y) +
                  t.p[2].x * (t.p[0].y - t.p[1].y)) / 2.0;
    
    if (area < 0) {
        area = -area;
    }
    return area;
}

bool samePoint( Point p1, Point p2 ) {
    // Ccompare points are close
    float dx = p1.x - p2.x;
    float dy = p1.y - p2.y;
    
    if (dx < 0) dx = -dx;
    if (dy < 0) dy = -dy;
    
    return (dx < 1.0e-6 && dy < 1.0e-6);
}

bool pointInLine( Point p, Line l ) {
    //endpoint match means in line
    return (samePoint(p, l.p[0]) || samePoint(p, l.p[1]));
}

bool pointInTriangle( Point p, Triangle t ) {
    // three vertics means triangle
    return (samePoint(p, t.p[0]) || samePoint(p, t.p[1]) || samePoint(p, t.p[2]));
}
