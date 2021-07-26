#pragma once

#include "Base.h"
#include "Point.h"
#include <iostream>
#include <string.h>

class TLine : public TBase {
protected:
	TPoint p1, p2;

	virtual void SetChild(TBase* c, int i);
public:
	TLine() {
	}
	TLine(const TPoint& _p1, const TPoint& _p2);
	TLine(const TLine& line);

	virtual void Print();
	TPoint& getFirst();
	TPoint& getSecond();
	virtual double GetVal(int i);
	virtual void SetVal(double val, int i);
	virtual double& operator[](char* name);
	virtual double& operator[](int i);

	virtual TBase* GetChild(int i);

	friend std::ostream& operator<<(std::ostream& out, const TLine& line);
	virtual TBase* Clone();
};