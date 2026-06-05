// Copyright 2022 UNN-CS
#include "circle.h"
#include <cmath>

const double PI_VAL = 3.14159265358979323846;

Circle::Circle(double r) {
    radius = r;
    ference = 2.0 * PI_VAL * radius;
    area = PI_VAL * radius * radius;
}

double Circle::getRadius() const {
    return radius;
}

double Circle::getFerence() const {
    return ference;
}

double Circle::getArea() const {
    return area;
}

void Circle::setRadius(double r) {
    radius = r;
    ference = 2.0 * PI_VAL * radius;
    area = PI_VAL * radius * radius;
}

void Circle::setFerence(double f) {
    ference = f;
    radius = ference / (2.0 * PI_VAL);
    area = PI_VAL * radius * radius;
}

void Circle::setArea(double a) {
    area = a;
    radius = std::sqrt(area / PI_VAL);
    ference = 2.0 * PI_VAL * radius;
}