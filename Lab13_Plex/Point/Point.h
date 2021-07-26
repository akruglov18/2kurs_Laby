#pragma once

#include "Base.h"
#include <iostream>

class TPoint : public TBase {
protected:
	double x0, x1;

	virtual TBase* GetChild(int i);
	virtual void SetChild(TBase* c, int i);

public:
	TPoint(double _x0 = 0, double _x1 = 0);
	TPoint(const TPoint& p);

	virtual void Print();
	virtual double GetVal(int i);
	virtual void SetVal(double val, int i);
	virtual double& operator[](char* name);
	virtual double& operator[](int i);
	bool operator==(const TPoint& point);

	double GetX0();
	double GetX1();

	void SetX0(double x);
	void SetX1(double x);
	virtual TBase* Clone();

	friend std::ostream& operator<<(std::ostream& out, const TPoint& point);
};