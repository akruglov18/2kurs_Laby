#include"Monom.h"

TMonom::TMonom(TMonomData _data) : TListElem<TMonomData>(_data)
{
}

TMonom::TMonom(double* _data, int _dim, double _K) : TListElem<TMonomData>()
{
  if (_dim < 0)
  {
    throw new std::exception();
  }

  data.dim = _dim;
  data.K = _K;

  if (data.dim > 0)
  {
    data.data = new double[data.dim];
    for (int i = 0; i < data.dim; i++)
      data.data[i] = _data[i];
  }
}

TMonom::TMonom(TMonom& m) : TListElem<TMonomData>(m)
{
  prev = 0;
  next = 0;
}

TMonom::~TMonom()
{
}

bool TMonom::operator==(const TMonom& m)
{
  if (data.dim != m.data.dim)
    return false;

  if (data.dim > 0)
  {
    for (int i = 0; i < data.dim; i++)
    {
      if (data.data[i] != m.data.data[i])
        return false;
    }
    return true;
  }
  return true;
}

bool TMonom::operator!=(const TMonom& m)
{
  return !this->operator==(m);
}

TMonomData& TMonom::operator*()
{
  return data;
}

TMonomData& TMonom::operator*(int)
{
  return data;
}

double TMonom::getK()
{
  return data.K;
}

void TMonom::setK(double _K)
{
  data.K = _K;
}

int TMonom::getDim()
{
  return data.dim;
}

void TMonom::setDim(int _dim)
{
  if (data.dim == _dim)
    return;

  if (_dim < 0) {
    throw new std::exception();
  }
  else if (_dim == 0)
  {
    if (data.dim > 0)
      delete[] data.data;

    data.dim = 0;
    data.data = 0;
  }
  else
  {
    if (data.dim > 0)
      delete[] data.data;

    data.dim = _dim;
    data.data = new double[data.dim];
    for (int i = 0; i < data.dim; i++)
      data.data[i] = 0;
  }
}

TMonom* TMonom::clone()
{
  TMonom* res = new TMonom(*this);
  return res;
}

double& TMonom::operator[](int i)
{
  return data.data[i];
}

TMonom& TMonom::operator=(const TMonom& m)
{
  if (this == &m)
    return *this;

  next = 0;
  prev = 0;
  data.K = m.data.K;

  if (data.dim == m.data.dim)
  {
    for (int i = 0; i < data.dim; i++)
      data.data[i] = m.data.data[i];
  }
  else if (m.data.dim == 0)
  {
    if (data.dim > 0)
      delete[] data.data;

    data.dim = 0;
    data.data = 0;
  }
  else
  {
    if (data.dim > 0)
      delete[] data.data;

    data.dim = m.data.dim;
    data.data = new double[data.dim];
    for (int i = 0; i < data.dim; i++)
      data.data[i] = m.data.data[i];

  }
  return *this;
}

TMonom TMonom::operator*(const TMonom& m)
{
  if (data.dim != m.data.dim)
    throw new std::exception();

  TMonom tmp(*this);
  tmp.data.K = data.K * m.data.K;

  for (int i = 0; i < data.dim; i++)
    tmp.data.data[i] = data.data[i] + m.data.data[i];

  return tmp;
}

TMonom TMonom::operator/(const TMonom& m)
{
  if (data.dim != m.data.dim)
    throw new std::exception();

  TMonom tmp(*this);
  tmp.data.K = data.K / m.data.K;

  for (int i = 0; i < data.dim; i++)
    tmp.data.data[i] = this->data.data[i] - m.data.data[i];

  return tmp;
}

TMonom* TMonom::operator+(const TMonom& m)
{
  if (data.dim != m.data.dim)
    throw new std::exception();

  TMonom* tmp;

  if (*this == m)
  {
    tmp = new TMonom(*this);
    tmp->data.K = this->data.K + m.data.K;
  }
  else
  {
    tmp = new TMonom[2];
    if (*this > m)
    {
      tmp[0] = *this;
      tmp[1] = m;
    }
    else
    {
      tmp[0] = m;
      tmp[1] = *this;
    }
  }
  return tmp;
}

TMonom* TMonom::operator-(const TMonom& m)
{
  if (data.dim != m.data.dim)
    throw new std::exception();

  TMonom* tmp = 0;

  if (*this == m)
  {
    tmp = new TMonom(*this);
    tmp->data.K = this->data.K - m.data.K;
  }
  else
  {
    tmp = new TMonom[2];
    if (*this > m)
    {
      tmp[0] = *this;
      tmp[1] = m;
    }
    else
    {
      tmp[0] = m;
      tmp[1] = *this;
    }
  }

  return tmp;
}

bool TMonom::operator>(const TMonom& _v)
{
  if (data.dim != _v.data.dim)
    return false;

  else if (data.dim > 0)
  {
    for (int i = 0; i < data.dim; i++)
    {
      if (data.data[i] > _v.data.data[i])
        return true;
      else if (data.data[i] < _v.data.data[i])
        return false;
    }
    return false;
  }
  else
  {
    return data.K > _v.data.K;
  }
}

bool TMonom::operator<(const TMonom& _v)
{
  if (data.dim != _v.data.dim)
    return false;

  if (data.dim > 0)
  {
    for (int i = 0; i < data.dim; i++)
    {
      if (data.data[i] < _v.data.data[i])
        return true;
      else if (data.data[i] > _v.data.data[i])
        return false;
    }
    return false;
  }
  else
    return data.K < _v.data.K;
}

ifstream& operator>>(ifstream& in, TMonom& m)
{
  in >> m.data.K;
  int dim = 0;
  in >> dim;
  m.setDim(dim);
  m.data.dim = dim;
  for (int i = 0; i < dim; i++)
    in >> m.data.data[i];

  return in;
}

ofstream& operator<<(ofstream& out, const TMonom& m)
{
  out << m.data.K;
  out << m.data.dim;
  for (int i = 0; i < m.data.dim; i++)
    out << "* x[" << i << "]^" << m.data.data[i];

  out << " ";
  return out;
}

TMonomData::TMonomData(int t)
{
  if (t < 0)
  {
    throw new std::exception();
  }
  else if (t == 0)
  {
    dim = 0;
    data = 0;
  }
  else
  {
    dim = t;
    data = new double[dim];
    for (int i = 0; i < dim; i++)
      data[i] = 0;
  }
}

TMonomData::TMonomData(double* _data, int _dim, double _K)
{
  if (_dim < 0)
    throw new std::exception();

  dim = _dim;
  K = _K;

  if (dim > 0)
  {
    data = new double[dim];
    for (int i = 0; i < dim; i++)
      data[i] = _data[i];
  }
}

TMonomData::TMonomData(const TMonomData& mData)
{
  dim = mData.dim;
  K = mData.K;

  if (dim > 0)
  {
    data = new double[dim];
    for (int i = 0; i < dim; i++)
      data[i] = mData.data[i];
  }
}

TMonomData::~TMonomData()
{
  if (data != 0)
  {
    delete[] data;
    data = 0;
    dim = 0;
    K = 0;
  }
}