#include "Point.h"

TPoint::TPoint(double _x0, double _x1) {
	x0 = _x0;
	x1 = _x1;
}

TPoint::TPoint(const TPoint& p) {
	x0 = p.x0;
	x1 = p.x1;
}

void TPoint::Print() {
	std::cout << "Point X0: " << x0 << " "
		<< "Point X1: " << x1;
}

double TPoint::GetVal(int i) {
	if (i < 0 || i > 1)
		throw - 1;
	if (i == 0)
		return x0;
	if (i == 1)
		return x1;
}

void TPoint::SetVal(double val, int i) {
	if (i < 0 || i > 1)
		throw - 1;
	if (i == 0)
		x0 = val;
	if (i == 1)
		x1 = val;
}

double& TPoint::operator[](char* name) {
	if (sizeof(name) != 2)
		throw std::exception();
	if (name[1] == 0)
		return x0;
	if (name[1] == 1)
		return x1;
	throw std::exception();
}

double& TPoint::operator[](int i) {
	if (i < 0 || i > 1)
		throw - 1;
	if (i == 0)
		return x0;
	if (i == 1)
		return x1;
}

bool TPoint::operator==(const TPoint& point)
{
	return x0 == point.x0 && x1 == point.x1;
}

TBase* TPoint::GetChild(int i) {
	return 0;
}
void TPoint::SetChild(TBase* c, int i) {
}

double TPoint::GetX0() {
	return x0;
}

double TPoint::GetX1() {
	return x1;
}

void TPoint::SetX0(double x) {
	x0 = x;
}

void TPoint::SetX1(double x) {
	x1 = x;
}

TBase* TPoint::Clone()
{
	return new TPoint(*this);
}

std::ostream& operator<<(std::ostream& out, const TPoint& point)
{
	out << point.x0 << " " << point.x1;
	return out;
}
