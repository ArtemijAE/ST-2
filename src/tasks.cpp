// Copyright 2022 UNN-CS
#include "tasks.h"
#include "circle.h"
#include <cmath>

const double PI_CONST = 3.14159265358979323846;

double earthRopeGap() {
    const double EARTH_R = 6378100.0;
    Circle earthCircle(EARTH_R);
    double ropeLen = earthCircle.getFerence();
    double newRopeLen = ropeLen + 1.0;
    Circle newCircle(0.0);
    newCircle.setFerence(newRopeLen);
    double gapVal = newCircle.getRadius() - EARTH_R;
    return gapVal;
}

double poolCost() {
    const double POOL_R = 3.0;
    const double WALK_W = 1.0;
    const double CONCRETE_PR = 1000.0;
    const double FENCE_PR = 2000.0;
    Circle poolArea(POOL_R);
    Circle walkArea(POOL_R + WALK_W);
    double walkSquare = walkArea.getArea() - poolArea.getArea();
    double concreteTotal = walkSquare * CONCRETE_PR;
    double fenceLen = walkArea.getFerence();
    double fenceTotal = fenceLen * FENCE_PR;
    double finalCost = concreteTotal + fenceTotal;
    return finalCost;
}
