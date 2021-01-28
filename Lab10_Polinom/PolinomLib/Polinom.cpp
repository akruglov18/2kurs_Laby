#include "Polinom.h"

TPolinomial::TPolinomial() : TList<TMonomData>()
{
}

TPolinomial::TPolinomial(const TPolinomial& p) : TList<TMonomData>(p)
{
}

TPolinomial::~TPolinomial()
{
}

TPolinomial& TPolinomial::operator+=(TMonom& p)
{
  if (_root == 0)
  {
    _root = p.clone();
    _end = _root;
  }
  else
  {
    TMonom* tmp = static_cast<TMonom*>(_root);

    while (tmp != 0)
    {
      if (*tmp == p)
      {
        tmp->setK(tmp->getK() + p.getK());
        return *this;
      }
      else
      {
        TMonom* temp2 = p.clone();
        if (*tmp < p)
        {
          temp2->setPrev(tmp->getPrev());
          temp2->setNext(tmp);

          if (tmp->getPrev() != 0)
            tmp->getPrev()->setNext(temp2);
          else
            _root = temp2;

          tmp->setPrev(temp2);
          return *this;
        }
        else
        {
          if (tmp->getNext() == 0)
          {
            temp2->setPrev(tmp);
            tmp->setNext(temp2);
            _end = temp2;
            return *this;
          }
          else
            tmp = static_cast<TMonom*>(tmp->getNext());
        }
      }
    }
  }
  return *this;
}

TPolinomial TPolinomial::operator*(TPolinomial& p)
{
  if (_root == 0 && p._root==0)
    throw new std::exception();

  TPolinomial res;
  TMonom* tmp1 = static_cast<TMonom*>(_root);
  while (tmp1 != 0)
  {
    TMonom* tmp2 = static_cast<TMonom*>(p._root);
    while (tmp2 != 0)
    {
      TMonom tmp3;
      tmp3 = (static_cast<TMonom&>(*tmp2)) * (static_cast<TMonom&>(*tmp1));
      res += tmp3;
      tmp2 = static_cast<TMonom*>(tmp2->getNext());
    }
    tmp1 = static_cast<TMonom*>(tmp1->getNext());
  }
  return res;
}

TPolinomial TPolinomial::operator+(TPolinomial& p)
{
  if (p._root == 0 || _root == 0)
    throw new std::exception();

  TPolinomial res;
  TMonom* tmp1 = static_cast<TMonom*>(p._root);
  TMonom* tmp2 = static_cast<TMonom*>(_root);
  TMonom* r = 0;

  while (tmp1 != 0 && tmp2 != 0)
  {
    TMonom temp3;
    if (*tmp1 == *tmp2)
    {
      temp3 = ((*tmp1) + (*tmp2))[0];
      tmp1 = static_cast<TMonom*>(tmp1->getNext());
      tmp2 = static_cast<TMonom*>(tmp2->getNext());
    }
    else if (*tmp1 < *tmp2)
    {
      temp3 = *tmp2;
      tmp2 = static_cast<TMonom*>(tmp2->getNext());
    }
    else
    {
      temp3 = *tmp1;
      tmp1 = static_cast<TMonom*>(tmp1->getNext());
    }

    if (r == 0)
    {
      res += temp3;
      r = static_cast<TMonom*>(res._root);
    }
    else
    {
      r->setNext(temp3.clone());
      r->getNext()->setPrev(static_cast<TMonom*>(r));
      r = static_cast<TMonom*>(r->getNext());
    }
  }
  if (tmp1 != 0)
  {
    while (tmp1 != 0)
    {
      r->setNext(new TMonom(*tmp1));
      r->getNext()->setPrev(r);
      r = static_cast<TMonom*>(r->getNext());
      tmp1 = static_cast<TMonom*>(tmp1->getNext());
    }
  }
  else if (tmp2 != 0)
  {
    while (tmp2 != 0)
    {
      r->setNext(new TMonom(*tmp2));
      r->getNext()->setPrev(r);
      r = static_cast<TMonom*>(r->getNext());
      tmp2 = static_cast<TMonom*>(tmp2->getNext());
    }
  }
  return res;
}

TPolinomial TPolinomial::operator-(TPolinomial& p)
{
  if (p._root == 0 || _root == 0)
    throw new std::exception();

  TPolinomial res;
  TMonom* temp = static_cast<TMonom*>(p._root);
  TMonom* temp2 = static_cast<TMonom*>(_root);
  TMonom* r = 0;

  while (temp != 0 && temp2 != 0)
  {
    TMonom temp3;
    if (*temp == *temp2)
    {
      temp3 = ((*temp) - (*temp2))[0];
      temp = static_cast<TMonom*>(temp->getNext());
      temp2 = static_cast<TMonom*>(temp2->getNext());
    }
    else if (*temp > *temp2)
    {
      temp3 = *temp;
      temp = static_cast<TMonom*>(temp->getNext());
    }
    else
    {
      temp3 = *temp2;
      temp2 = static_cast<TMonom*>(temp2->getNext());
    }

    if (r == 0)
    {
      res += temp3;
      r = static_cast<TMonom*>(res._root);
    }
    else
    {
      r->setNext(temp3.clone());
      r->getNext()->setPrev(static_cast<TMonom*>(r));
      r = static_cast<TMonom*>(r->getNext());
    }
  }
  if (temp != 0)
  {
    while (temp != 0)
    {
      r->setNext(new TMonom(*temp));
      r->getNext()->setPrev(r);
      r = static_cast<TMonom*>(r->getNext());
      temp = static_cast<TMonom*>(temp->getNext());
    }
  }
  else if (temp2 != 0)
  {
    while (temp2 != 0)
    {
      r->setNext(new TMonom(*temp2));
      r->getNext()->setPrev(r);
      r = static_cast<TMonom*>(r->getNext());
      temp2 = static_cast<TMonom*>(temp2->getNext());
    }
  }
  return res;
}

//bool TPolinomial::operator==(const TPolinomial& p) const
//{
//  TMonom* tmp1 = static_cast<TMonom*>(p._root);
//  TMonom* tmp2 = static_cast<TMonom*>(_root);
//  while (tmp1 != 0 && tmp2 != 0) {
//    if (*tmp1 != *tmp2)
//      return false;
//    tmp1 = static_cast<TMonom*>(tmp1->getNext());
//    tmp2 = static_cast<TMonom*>(tmp2->getNext());
//  }
//  //x^3+x^2+x
//  //x^3+x^2
//  //not equal
//  if (tmp1 == 0 && tmp2 == 0) // polinoms have equal size
//    return true;
//  return false; // not equal
//}
//
//bool TPolinomial::operator!=(const TPolinomial& p) const
//{
//  return !(*this==p);
//}

ofstream& operator<<(ofstream& out, const TPolinomial& p)
{
  TMonom* tmp = static_cast<TMonom*>(p._root);
  while (tmp != 0) {
    out << *(tmp);
    tmp = static_cast<TMonom*>(tmp->getNext());
  }
  return out;
}
