#pragma once

#include<math.h>
#include<string.h>
#include<TStack.h>
#include<ctype.h>
#include<cstdlib>
#include<fstream>

class Lexem
{
public:
  virtual int prioritet() = 0;
  virtual int getNumber() = 0;
  virtual Lexem* Calc(Lexem* a, Lexem* b) = 0;
};

class TNum : public Lexem
{
protected:
  int data;
public:
  TNum(int _d);
  TNum(TNum& _d);
  TNum(char* s);

  virtual int prioritet();
  virtual int getNumber();
  virtual Lexem* Calc(Lexem* a, Lexem* b);
};


class TOper : public Lexem
{
protected:
  char data;
public:
  TOper(char _d);
  TOper(TOper& _d);

  virtual int getNumber();
};


class TPlus : public TOper
{
public:
  TPlus(char _d) : TOper(_d) {}
  virtual int prioritet();
  virtual Lexem* Calc(Lexem* a, Lexem* b);
};


class TSub : public TOper
{
public:
  TSub(char _d) : TOper(_d) {}
  virtual int prioritet();
  virtual Lexem* Calc(Lexem* a, Lexem* b);
};

class TMultiplication : public TOper
{
public:
  TMultiplication(char _d) : TOper(_d) {}
  virtual int prioritet();
  virtual Lexem* Calc(Lexem* a, Lexem* b);
};

class TDivision : public TOper
{
public:
  TDivision(char _d) : TOper(_d) {}
  virtual int prioritet();
  virtual Lexem* Calc(Lexem* a, Lexem* b);
};

class TBracketOpen : public TOper
{
public:
  TBracketOpen(char _d) : TOper(_d) {}
  virtual int prioritet();
  virtual Lexem* Calc(Lexem* a, Lexem* b);
};

class TBracketClose : public TOper
{
public:
  TBracketClose(char _d) : TOper(_d) {}
  virtual int prioritet();
  virtual Lexem* Calc(Lexem* a, Lexem* b);
};

class TOperFactory
{
public:
  static void create(char* s, int& n, Lexem**& opers);
};

class TPolish
{
public:
  static int Calculation(char* s);
};
