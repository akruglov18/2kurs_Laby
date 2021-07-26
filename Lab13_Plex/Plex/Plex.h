#pragma once

#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
#include <algorithm>
#include "Base.h"
#include "Point.h"
#include "Line.h"

class TPlex : public TBase {
protected:
	TBase* left;
	TBase* right;
public:
	TPlex();
	TPlex(TPoint* a, TPoint* b);
	TPlex(const TPlex& plex);

	virtual void Print();
	virtual double GetVal(int i);
	virtual void SetVal(double val, int i);
	virtual double& operator[](char* name);
	virtual double& operator[](int i);

	TPlex& operator=(const TPlex& plex);
	

	virtual TBase* GetChild(int i);
	virtual void SetChild(TBase* c, int i);
	virtual TBase* PrintAll(TBase* p);
	TBase* GetLeft();
	TBase* GetRight();

	TPlex* GetLeftPlex();
	TPlex* GetRightPlex();

	void SetLeft(TBase* x);
	void SetRight(TBase* x);
	bool AddLine(TPoint* a, TPoint* b);
	virtual int GetChildCount()
	{
		return 2;
	}
	virtual TBase* Clone();
	friend std::ostream& operator<<(std::ostream& out, const TPlex& plex);

	bool Save(const std::string& FileName);
	bool Load(const std::string& FileName);
};