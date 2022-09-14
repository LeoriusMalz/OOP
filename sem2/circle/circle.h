#include "point.h"

class Circle
{
private:
	Point mCenter;
	float mRadius;

public:

	Circle(const Point& acenter, float aradius);
	Circle();
	Circle(const Circle& circle);

	void setCenter(const Point& p);
	void setRadius(float r);
	Point getCenter() const;
	float getRadius() const;

	float getArea() const;
	float getDistance(const Point& p) const;
	bool isColliding(const Circle& c) const;
	void move(const Point& p);
};