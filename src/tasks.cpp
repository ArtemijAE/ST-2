// Copyright 2022 UNN-CS
#include <cmath>
#include "circle.h"
#include "tasks.h"

const double PI = 3.14159265358979323846;

double earthRopeGap() {
    double earthRadius = 6378100.0;
    Circle earth(earthRadius);
    double earthCircumference = earth.getFerence();
    double newRopeLength = earthCircumference + 1.0;
    Circle newCircle(0);
    newCircle.setFerence(newRopeLength);
    double gap = newCircle.getRadius() - earthRadius;
    return gap;
}

double poolCost() {
    double poolRadius = 3.0;
    double pathWidth = 1.0;
    const double concretePrice = 1000.0;
    const double fencePrice = 2000.0;
    Circle pool(poolRadius);
    Circle poolWithPath(poolRadius + pathWidth);
    double pathArea = poolWithPath.getArea() - pool.getArea();
    double concreteCost = pathArea * concretePrice;
    double fenceLength = poolWithPath.getFerence();
    double fenceCost = fenceLength * fencePrice;
    double totalCost = concreteCost + fenceCost;
    return totalCost;
}
