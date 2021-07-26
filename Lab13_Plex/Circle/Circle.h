#pragma once

#include "Base.h"
#include <iostream>

class Circle : public TBase {
protected:
	double x0, x1;
	double radius;

	virtual TBase* GetChild(int i);
	virtual void SetChild(TBase* c, int i);

public:
	Circle(double _x0 = 0, double _x1 = 0, double _radius = 0);
	Circle(const Circle& p);

	virtual void Print();
	virtual double GetVal(int i);
	virtual void SetVal(double val, int i);
	virtual double& operator[](int i);
	double& operator[](char* name);

	double GetX0();
	double GetX1();
	double GetRadius();

	void SetX0(double x);
	void SetX1(double x);
	void SetRadius(double r);
	virtual TBase* Clone();

	friend std::ostream& operator<<(std::ostream& out, const Circle& point);
};