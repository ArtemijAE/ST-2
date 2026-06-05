// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cmath>
#include "circle.h"
#include "tasks.h"

const double MY_PI = 3.14159265358979323846;
const double EPS = 1e-8;

class CircleTest : public ::testing::Test {
 protected:
    void SetUp() override {
        c = new Circle(5.0);
    }
    void TearDown() override {
        delete c;
    }
    Circle* c;
};

TEST_F(CircleTest, constructorCheck) {
    EXPECT_NEAR(c->getRadius(), 5.0, EPS);
    EXPECT_NEAR(c->getFerence(), 2.0 * MY_PI * 5.0, EPS);
    EXPECT_NEAR(c->getArea(), MY_PI * 25.0, EPS);
}

TEST_F(CircleTest, setRadiusWorks) {
    c->setRadius(7.0);
    EXPECT_NEAR(c->getRadius(), 7.0, EPS);
    EXPECT_NEAR(c->getFerence(), 2.0 * MY_PI * 7.0, EPS);
    EXPECT_NEAR(c->getArea(), MY_PI * 49.0, EPS);
}

TEST(CircleMethods, setFerenceTest) {
    Circle obj(2.0);
    obj.setFerence(31.41592653589793);
    EXPECT_NEAR(obj.getRadius(), 5.0, EPS);
    EXPECT_NEAR(obj.getArea(), MY_PI * 25.0, EPS);
}

TEST(CircleMethods, setAreaTest) {
    Circle obj(1.0);
    obj.setArea(78.53981633974483);
    EXPECT_NEAR(obj.getRadius(), 5.0, EPS);
    EXPECT_NEAR(obj.getFerence(), 2.0 * MY_PI * 5.0, EPS);
}

TEST(CircleMethods, zeroRadiusCase) {
    Circle zero(0.0);
    EXPECT_DOUBLE_EQ(zero.getRadius(), 0.0);
    EXPECT_DOUBLE_EQ(zero.getFerence(), 0.0);
    EXPECT_DOUBLE_EQ(zero.getArea(), 0.0);
}

TEST(CircleMethods, negativeRadiusCase) {
    Circle neg(-4.0);
    EXPECT_DOUBLE_EQ(neg.getRadius(), -4.0);
    EXPECT_GT(neg.getArea(), 0.0);
}

TEST(EarthTask, gapPositive) {
    double result = earthRopeGap();
    EXPECT_GT(result, 0.0);
}

TEST(EarthTask, gapExpectedValue) {
    double result = earthRopeGap();
    double expected = 1.0 / (2.0 * MY_PI);
    EXPECT_NEAR(result, expected, 1e-8);
}

TEST(EarthTask, gapFormulaCheck) {
    double gap1 = earthRopeGap();
    Circle ground(5000.0);
    double rope1 = ground.getFerence() + 1.0;
    Circle rope2(0.0);
    rope2.setFerence(rope1);
    double gap2 = rope2.getRadius() - 5000.0;
    EXPECT_NEAR(gap1, gap2, 1e-8);
}

TEST(PoolTask, totalCostPositive) {
    double total = poolCost();
    EXPECT_GT(total, 0.0);
}

TEST(PoolTask, walkwayArea) {
    Circle inner(3.0);
    Circle outer(4.0);
    double expected = MY_PI * (16.0 - 9.0);
    double actual = outer.getArea() - inner.getArea();
    EXPECT_NEAR(actual, expected, EPS);
}

TEST(PoolTask, fenceLength) {
    Circle fence(4.0);
    double expected = 2.0 * MY_PI * 4.0;
    EXPECT_NEAR(fence.getFerence(), expected, EPS);
}

TEST(PoolTask, concreteExpense) {
    double area = MY_PI * 7.0;
    double expected = area * 1000.0;
    double total = poolCost();
    double fencePart = 2.0 * MY_PI * 4.0 * 2000.0;
    double concretePart = total - fencePart;
    EXPECT_NEAR(concretePart, expected, 1.0);
}

TEST(CircleMethods, multipleSettersChain) {
    Circle obj(1.0);
    obj.setRadius(2.0);
    obj.setFerence(25.132741228718345);
    obj.setArea(50.26548245743669);
    double r = obj.getRadius();
    double f = obj.getFerence();
    double a = obj.getArea();
    EXPECT_NEAR(f, 2.0 * MY_PI * r, EPS);
    EXPECT_NEAR(a, MY_PI * r * r, EPS);
}

TEST(CircleMethods, gettersAfterSet) {
    Circle obj(1.0);
    obj.setRadius(3.0);
    EXPECT_EQ(obj.getRadius(), 3.0);
    EXPECT_EQ(obj.getFerence(), 2.0 * MY_PI * 3.0);
    EXPECT_EQ(obj.getArea(), MY_PI * 9.0);
}