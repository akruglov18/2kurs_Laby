#include "Plex.h"

TPlex::TPlex() {
	left = new TPoint();
	right = new TPoint();
}

TPlex::TPlex(TPoint* a, TPoint* b) {
	if (a != NULL)
		left = a;

	if (b != NULL)
		right = b;
}

TPlex::TPlex(const TPlex& plex) : left(plex.left->Clone()), right (plex.right->Clone())
{
}

void TPlex::Print()
{
	PrintAll(0);
};

TBase* TPlex::PrintAll(TBase*)
{
	std::cout << *this << "\n";
	return 0;
}

double TPlex::GetVal(int i) {
	throw - 1;
}
void TPlex::SetVal(double val, int i) {
	throw - 1;
}
double& TPlex::operator[](char* name) {
	throw - 1;
}
double& TPlex::operator[](int i) {
	throw - 1;
}

TPlex& TPlex::operator=(const TPlex& plex)
{
	left = plex.right->Clone();
	right = plex.left->Clone();
	return *this;
}

TBase* TPlex::GetChild(int i) {
	if (i == 0)
		return left;
	else if (i == 1)
		return right;
	else
		throw - 1;
}

void TPlex::SetChild(TBase* c, int i)
{
	if (i == 0)
		left = c;
	else if (i == 1)
		right = c;
	else
		throw - 1;
}

TBase* TPlex::GetLeft()
{
	return left;
}
TBase* TPlex::GetRight()
{
	return right;
}

TPlex* TPlex::GetLeftPlex()
{
	return dynamic_cast<TPlex*>(left);
}

TPlex* TPlex::GetRightPlex()
{
	return dynamic_cast<TPlex*>(right);
}

void TPlex::SetLeft(TBase* x)
{
	left = x;
}
void TPlex::SetRight(TBase* x)
{
	right = x;
}
bool TPlex::AddLine(TPoint* a, TPoint* b)
{
	std::stack<TBase*> st;
	st.push(this);
	while (!st.empty()) {
		TBase* top = st.top();
		st.pop();
		TBase* ri = top->GetChild(1);
		TBase* le = top->GetChild(0);
		if (le->GetChildCount() != 0) {
			st.push(le);
		}
		else if (le == a) {
			top->SetChild(new TPlex(b, a), 0);
			return true;
		}
		/*else if (le == b) {
			top->SetChild(new TPlex(a, b), 0);
			return true;
		}*/

		if (ri->GetChildCount() != 0) {
			st.push(ri);
		}
		else if (ri == a) {
			top->SetChild(new TPlex(b, a), 1);
			return true;
		}
		/*else if (ri == b) {
			top->SetChild(new TPlex(a, b), 1);
			return true;
		}*/
	}
	return false;
}

TBase* TPlex::Clone()
{
	return new TPlex(*this);
}

bool TPlex::Save(const std::string& FileName)
{
	std::ofstream fout(FileName);
	if (fout.is_open()) {
		fout << *this;
		fout.close();
		return true;
	}
	else {
		return false;
	}
}

bool TPlex::Load(const std::string& FileName)
{
	std::ifstream fin(FileName);
	if (fin.is_open()) {
		std::vector<TPoint*> points;
		std::vector<std::pair<TPoint*, TPoint*>> lines;
		while (!fin.eof()) {
			double x0, x1, x2, x3;
			fin >> x0 >> x1 >> x2 >> x3;
			TPoint* p1 = NULL; 
			TPoint* p2 = NULL;
			for (int i = 0; i < points.size(); i++) {
				if (points[i]->GetX0() == x0 && points[i]->GetX1() == x1) {
					p1 = points[i];
					break;
				}
			}
			if (p1 == NULL) {
				p1 = new TPoint(x0, x1);
				points.push_back(p1);
			}

			for (int i = 0; i < points.size(); i++) {
				if (points[i]->GetX0() == x2 && points[i]->GetX1() == x3) {
					p2 = points[i];
					break;
				}
			}
			if (p2 == NULL) {
				p2 = new TPoint(x2, x3);
				points.push_back(p2);
			}
			lines.push_back({ p1,p2 });
		}
		lines.pop_back();
		if (lines.size() != 0) {
			this->left = lines.back().first;
			this->right = lines.back().second;
		}
		for (int i = lines.size() - 2; i >= 0; i--) {
			AddLine(lines[i].second, lines[i].first);
		}
		return true;
	}
	else {
		return false;
	}
}

std::ostream& operator<<(std::ostream& out, const TPlex& plex)
{
	TBase* curLine = const_cast<TPlex*>(&plex);
	TPoint* fp = NULL;
	TPoint* lp = NULL;
	std::stack<TBase*> st;
	st.push(curLine);
	while (!st.empty()) {
		curLine = st.top();
		st.pop();
		while (fp == NULL) {
			TBase* le = curLine->GetChild(0);
			TPlex* isPlex = dynamic_cast<TPlex*>(le);
			if (isPlex == NULL) {
				fp = dynamic_cast<TPoint*>(le);
			}
			else {
				st.push(curLine);
				curLine = le;
			}
		}
		if (lp == NULL) {
			TBase* ri = curLine->GetChild(1);
			TPlex* isPlex = dynamic_cast<TPlex*>(ri);
			if (isPlex == NULL) {
				lp = dynamic_cast<TPoint*>(ri);
			}
			else {
				st.push(curLine);
				fp = NULL;
				curLine = ri;
				st.push(curLine);
			}
		}
		if (fp != NULL && lp != NULL) {
			TLine p(*fp, *lp);
			out<< p << "\n";
			TBase* rp = lp;
			if (!st.empty()) {
				curLine = st.top();
				st.pop();
				TBase* le = curLine->GetChild(0);
				TBase* ri = curLine->GetChild(1);
				TPlex* isLeftPlex = dynamic_cast<TPlex*>(le);
				TPlex* isRightPlex = dynamic_cast<TPlex*>(ri);
				if (isLeftPlex != NULL && isRightPlex != NULL) {
					TPlex* add = new TPlex(lp, 0);
					add->SetChild(ri, 1);
					st.push(add);
					lp = NULL;
					fp = NULL;
				}
				else {
					if (isLeftPlex != NULL) {
						fp = dynamic_cast<TPoint*>(rp);
						lp = NULL;
					}
					else {
						lp = dynamic_cast<TPoint*>(rp);
						fp = NULL;
					}
					st.push(curLine);
				}
			}
		}
	}
	return out;
}
