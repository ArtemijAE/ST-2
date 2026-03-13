// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cmath>
#include "circle.h"
#include "tasks.h"

const double PI = 3.14159265358979323846;
const double EPS = 1e-10;

TEST(CircleTest, ConstructorAndGetters) {
    Circle c(5.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 5.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * PI * 5.0);
    EXPECT_DOUBLE_EQ(c.getArea(), PI * 25.0);
}

TEST(CircleTest, ConstructorZero) {
    Circle c(0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTest, SetRadiusPositive) {
    Circle c(1.0);
    c.setRadius(3.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 3.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * PI * 3.0);
    EXPECT_DOUBLE_EQ(c.getArea(), PI * 9.0);
}

TEST(CircleTest, SetRadiusZero) {
    Circle c(5.0);
    c.setRadius(0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTest, SetRadiusNegative) {
    Circle c(5.0);
    c.setRadius(-2.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), -2.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 2 * PI * (-2.0));
    EXPECT_DOUBLE_EQ(c.getArea(), PI * 4.0);
}

TEST(CircleTest, SetFerencePositive) {
    Circle c(1.0);
    double newFerence = 10.0;
    c.setFerence(newFerence);
    double expectedRadius = newFerence / (2 * PI);
    EXPECT_NEAR(c.getRadius(), expectedRadius, EPS);
    EXPECT_DOUBLE_EQ(c.getFerence(), newFerence);
    EXPECT_NEAR(c.getArea(), PI * expectedRadius * expectedRadius, EPS);
}

TEST(CircleTest, SetFerenceZero) {
    Circle c(5.0);
    c.setFerence(0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTest, SetFerenceNegative) {
    Circle c(5.0);
    c.setFerence(-10.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), -10.0 / (2 * PI));
    EXPECT_DOUBLE_EQ(c.getFerence(), -10.0);
    EXPECT_GT(c.getArea(), 0.0);
}

TEST(CircleTest, SetAreaPositive) {
    Circle c(1.0);
    double newArea = 50.0;
    c.setArea(newArea);
    double expectedRadius = std::sqrt(newArea / PI);
    EXPECT_NEAR(c.getRadius(), expectedRadius, EPS);
    EXPECT_NEAR(c.getFerence(), 2 * PI * expectedRadius, EPS);
    EXPECT_DOUBLE_EQ(c.getArea(), newArea);
}

TEST(CircleTest, SetAreaZero) {
    Circle c(5.0);
    c.setArea(0.0);
    EXPECT_DOUBLE_EQ(c.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(c.getFerence(), 0.0);
    EXPECT_DOUBLE_EQ(c.getArea(), 0.0);
}

TEST(CircleTest, SetAreaNegative) {
    Circle c(5.0);
    c.setArea(-10.0);
    EXPECT_TRUE(std::isnan(c.getRadius()));
    EXPECT_TRUE(std::isnan(c.getFerence()));
    EXPECT_DOUBLE_EQ(c.getArea(), -10.0);
}

TEST(CircleTest, RadiusFerenceRelation) {
    Circle c(2.0);
    double r = c.getRadius();
    double f = c.getFerence();
    EXPECT_DOUBLE_EQ(f, 2 * PI * r);
}

TEST(CircleTest, RadiusAreaRelation) {
    Circle c(3.0);
    double r = c.getRadius();
    double a = c.getArea();
    EXPECT_DOUBLE_EQ(a, PI * r * r);
}

TEST(CircleTest, FerenceAreaRelation) {
    Circle c(4.0);
    double f = c.getFerence();
    double a = c.getArea();
    double r = f / (2 * PI);
    EXPECT_DOUBLE_EQ(a, PI * r * r);
}

TEST(CircleTest, ConsistencyAfterMultipleSets) {
    Circle c(1.0);
    c.setRadius(2.0);
    c.setFerence(20.0);
    c.setArea(100.0);
    
    double r = c.getRadius();
    double f = c.getFerence();
    double a = c.getArea();
    
    EXPECT_NEAR(f, 2 * PI * r, EPS);
    EXPECT_NEAR(a, PI * r * r, EPS);
}

TEST(EarthRopeTest, GapPositive) {
    double gap = earthRopeGap();
    EXPECT_GT(gap, 0.0);
}

TEST(EarthRopeTest, GapValue) {
    double gap = earthRopeGap();
    double expectedGap = 1.0 / (2 * PI);
    EXPECT_NEAR(gap, expectedGap, 1e-10);
}

TEST(EarthRopeTest, GapIndependenceFromRadius) {
    double gap1 = earthRopeGap();
    double theoreticalGap = 1.0 / (2 * PI);
    EXPECT_NEAR(gap1, theoreticalGap, 1e-10);
}

TEST(PoolCostTest, CostPositive) {
    double cost = poolCost();
    EXPECT_GT(cost, 0.0);
}

TEST(PoolCostTest, PathArea) {
    double poolRadius = 3.0;
    double pathWidth = 1.0;
    
    Circle pool(poolRadius);
    Circle poolWithPath(poolRadius + pathWidth);
    
    double pathArea = poolWithPath.getArea() - pool.getArea();
    double expectedPathArea = PI * (4.0*4.0 - 3.0*3.0);
    
    EXPECT_NEAR(pathArea, expectedPathArea, EPS);
}

TEST(PoolCostTest, FenceLength) {
    double poolRadius = 3.0;
    double pathWidth = 1.0;
    
    Circle poolWithPath(poolRadius + pathWidth);
    double fenceLength = poolWithPath.getFerence();
    double expectedFenceLength = 2 * PI * 4.0;
    
    EXPECT_NEAR(fenceLength, expectedFenceLength, EPS);
}

TEST(PoolCostTest, ConcreteCost) {
    double cost = poolCost();
    double pathArea = PI * (16.0 - 9.0);
    double expectedConcreteCost = pathArea * 1000.0;
    EXPECT_GT(cost, expectedConcreteCost);
}

TEST(PoolCostTest, TotalCostValue) {
    double cost = poolCost();
    double expectedCost = (PI * 7.0 * 1000.0) + (2 * PI * 4.0 * 2000.0);
    EXPECT_NEAR(cost, expectedCost, 1e-6);
}