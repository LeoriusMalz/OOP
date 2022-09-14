#define PI 3.14159265358979323846

#include <iostream>
#include <cmath>

#include "circle.h"

Circle::Circle(const Point& acenter, float aradius) {
	mCenter = Point(acenter.getX(), acenter.getY());
	mRadius = aradius;
}

Circle::Circle() {
	mCenter = Point();
	mRadius = 1;
}

Circle::Circle(const Circle& circle) {
	mCenter = Point(circle.mCenter.getX(), circle.mCenter.getX());
	mRadius = circle.mRadius;
}

void Circle::setCenter(const Point& p) {
	mCenter = Point(p.getX(), p.getY());
}

void Circle::setRadius(float r) {
	mRadius = r;
}

Point Circle::getCenter() const {
	return mCenter;
}

float Circle::getRadius() const {
	return mRadius;
}

float Circle::getArea() const {
	return PI*mRadius*mRadius;
}

float Circle::getDistance(const Point& p) const {
	return mCenter.distance(p)-mRadius;
}

bool Circle::isColliding(const Circle& c) const {
	if (getDistance(c.mCenter) > c.mRadius)
		return false;
	return true;
}

void Circle::move(const Point& p) {
	mCenter = mCenter + p;
}