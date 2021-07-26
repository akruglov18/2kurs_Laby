#include "Square.h"

TSquare::TSquare(
	const TLine& _l1,
	const TLine& _l2,
	const TLine& _l3,
	const TLine& _l4)
	: l1(_l1), l2(_l2), l3(_l3), l4(_l4) {
}

TSquare::TSquare(const TSquare& square)
	: l1(square.l1), l2(square.l2), l3(square.l3), l4(square.l4) {
}

TLine TSquare::GetLine(int i) {
	switch (i) {
	case 0:
		return l1;
	case 1:
		return l2;
	case 2:
		return l3;
	case 3:
		return l4;
	default:
		throw - 1;
	}
}

void TSquare::SetLine(const TLine l, int i) {
	switch (i) {
	case 0:
		l1 = l;
	case 1:
		l2 = l;
	case 2:
		l3 = l;
	case 3:
		l4 = l;
	default:
		throw - 1;
	}
}

void TSquare::Print() {
	std::cout << "Стороны квадрата: ";
	l1.Print();
	l2.Print();
	l3.Print();
	l4.Print();
}

double TSquare::GetVal(int i) {
	switch (i / 4) {
	case 0:
		return l1.GetVal(0);
	case 1:
		return l1.GetVal(1);
	case 2:
		return l1.GetVal(2);
	case 3:
		return l1.GetVal(3);
	case 4:
		return l2.GetVal(0);
	case 5:
		return l2.GetVal(1);
	case 6:
		return l2.GetVal(2);
	case 7:
		return l2.GetVal(3);
	case 8:
		return l3.GetVal(0);
	case 9:
		return l3.GetVal(1);
	case 10:
		return l3.GetVal(2);
	case 11:
		return l3.GetVal(3);
	case 12:
		return l4.GetVal(0);
	case 13:
		return l4.GetVal(1);
	case 14:
		return l4.GetVal(2);
	case 15:
		return l4.GetVal(3);
	default:
		throw - 1;
	}
}

void TSquare::SetVal(double val, int i) {
	switch (i / 4) {
	case 0:
		l1.SetVal(val, 0);
		break;
	case 1:
		l1.SetVal(val, 1);
		break;
	case 2:
		l1.SetVal(val, 2);
		break;
	case 3:
		l1.SetVal(val, 3);
		break;
	case 4:
		l2.SetVal(val, 0);
		break;
	case 5:
		l2.SetVal(val, 1);
		break;
	case 6:
		l2.SetVal(val, 2);
		break;
	case 7:
		l2.SetVal(val, 3);
		break;
	case 8:
		l3.SetVal(val, 0);
		break;
	case 9:
		l3.SetVal(val, 1);
		break;
	case 10:
		l3.SetVal(val, 2);
		break;
	case 11:
		l3.SetVal(val, 3);
		break;
	case 12:
		l4.SetVal(val, 0);
		break;
	case 13:
		l4.SetVal(val, 1);
		break;
	case 14:
		l4.SetVal(val, 2);
		break;
	case 15:
		l4.SetVal(val, 3);
		break;
	default:
		throw - 1;
	}
}

double& TSquare::operator[](char* name) {
	double a = 0;
	return a;
}

double& TSquare::operator[](int i) {
	double a = 0;
	return a;
}

TBase* TSquare::GetChild(int i) {
	switch (i) {
	case 0:
		return &l1;
	case 1:
		return &l2;
	case 2:
		return &l3;
	case 3:
		return &l4;
	default:
		throw - 1;
	}
}

TBase* TSquare::Clone()
{
	return new TSquare(*this);
}

TBase* TSquare::PrintAll(TBase* p) {
	Print();
	return this;
}

void TSquare::SetChild(TBase* c, int i) {
}