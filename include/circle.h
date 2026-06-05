// Copyright 2022 UNN-CS
#ifndef INCLUDE_CIRCLE_H_
#define INCLUDE_CIRCLE_H_

class Circle {
 private:
    double radius;
    double ference;
    double area;

 public:
    explicit Circle(double r);

    double getRadius() const;
    double getFerence() const;
    double getArea() const;

    void setRadius(double r);
    void setFerence(double f);
    void setArea(double a);
};

#endif  // INCLUDE_CIRCLE_H_
