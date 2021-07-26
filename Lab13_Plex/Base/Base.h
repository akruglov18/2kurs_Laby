#ifndef _BASE_H
#define _BASE_H

class TBase {
protected:

public:
	TBase() {};
	virtual void Print() = 0;
	virtual double GetVal(int i) = 0;
	virtual void SetVal(double val, int i) = 0;
	virtual double& operator[](char* name) = 0;
	virtual double& operator[](int i) = 0;

	virtual TBase* GetChild(int i) = 0;
	virtual void SetChild(TBase* c, int i) = 0;

	virtual int GetChildCount() {
		return 0;
	}
	virtual TBase* PrintAll(TBase* p) {
		return this;
	};
	virtual TBase* Clone() = 0;
};

#endif _BASE_H