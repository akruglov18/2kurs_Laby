#pragma once

#include "Base.h"
#include "Line.h"

class TSquare : public TBase {
protected:
	TLine l1, l2, l3, l4;
	virtual TBase* PrintAll(TBase* p);
	virtual void SetChild(TBase* c, int i);

public:
	TSquare() {
	}
	TSquare(
		const TLine& _l1,
		const TLine& _l2,
		const TLine& _l3,
		const TLine& _l4);
	TSquare(const TSquare& square);

	TLine GetLine(int i);
	void SetLine(const TLine l, int i);

	virtual void Print();
	virtual double GetVal(int i);
	virtual void SetVal(double val, int i);
	virtual double& operator[](char* name);
	virtual double& operator[](int i);

	virtual TBase* GetChild(int i);

	virtual TBase* Clone();
};