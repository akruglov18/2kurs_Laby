#include "Circle.h"

Circle::Circle(double _x0, double _x1, double _radius) {
	x0 = _x0;
	x1 = _x1;
	radius = _radius;
}

Circle::Circle(const Circle& p) {
	x0 = p.x0;
	x1 = p.x1;
	radius = p.radius;
}

void Circle::Print() {
	std::cout << "Point X0: " << x0 << " "
		<< "Point X1: " << x1 << " Radius: " << radius;
}

double Circle::GetVal(int i) {
	if (i < 0 || i > 1)
		throw - 1;
	if (i == 0)
		return x0;
	if (i == 1)
		return x1;
}

void Circle::SetVal(double val, int i) {
	if (i < 0 || i > 1)
		throw - 1;
	if (i == 0)
		x0 = val;
	if (i == 1)
		x1 = val;
}

double& Circle::operator[](char* name) {
	if (sizeof(name) != 2)
		throw std::exception();
	if (name[1] == 0)
		return x0;
	if (name[1] == 1)
		return x1;
	throw std::exception();
}

double& Circle::operator[](int i) {
	if (i < 0 || i > 1)
		throw - 1;
	if (i == 0)
		return x0;
	if (i == 1)
		return x1;
}

TBase* Circle::GetChild(int i) {
	return 0;
}
void Circle::SetChild(TBase* c, int i) {
}

double Circle::GetX0() {
	return x0;
}

double Circle::GetX1() {
	return x1;
}

double Circle::GetRadius()
{
	return radius;
}

void Circle::SetX0(double x) {
	x0 = x;
}

void Circle::SetX1(double x) {
	x1 = x;
}

void Circle::SetRadius(double r)
{
	if (r < 0)
		throw std::exception();
	radius = r;
}

TBase* Circle::Clone()
{
	return new Circle(*this);
}

std::ostream& operator<<(std::ostream& out, const Circle& cir)
{
	out << cir.x0 << " " << cir.x1 << " " << cir.radius;
	return out;
}
