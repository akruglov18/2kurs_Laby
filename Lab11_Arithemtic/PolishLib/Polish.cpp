#include <Polish.h>

TNum::TNum(int _d)
{
  data = _d;
}

TNum::TNum(TNum& _d)
{
  data = _d.data;
}

TNum::TNum(char* s)
{
  int i = 0;
  while (isdigit(s[i]))
    i++;
  if (s[i] != 0)
    throw std::exception();
  data = atof(s);
}

int TNum::prioritet()
{
  return -1;
}

int TNum::getNumber()
{
  return data;
}

Lexem* TNum::Calc(Lexem* a, Lexem* b)
{
  throw - 1;
}

TOper::TOper(TOper& _d)
{
  data = _d.data;
}

TOper::TOper(char s)
{
  data = s;
}

int TOper::getNumber()
{
  throw - 1;
}

int TPlus::prioritet()
{
  return 2;
}

Lexem* TPlus::Calc(Lexem* a, Lexem* b)
{
  TNum* res = new TNum(a->getNumber() + b->getNumber());
  return res;
}

int TSub::prioritet()
{
  return 2;
}

Lexem* TSub::Calc(Lexem* a, Lexem* b)
{
  TNum* res = new TNum(a->getNumber() - b->getNumber());
  return res;
}

int TMultiplication::prioritet()
{
  return 3;
}

Lexem* TMultiplication::Calc(Lexem* a, Lexem* b)
{
  TNum* res = new TNum(a->getNumber() * b->getNumber());
  return res;
}

int TDivision::prioritet()
{
  return 3;
}

Lexem* TDivision::Calc(Lexem* a, Lexem* b)
{
  if (b->getNumber() == 0)
    throw - 1;
  TNum* res = new TNum(a->getNumber() / b->getNumber());
  return res;
}

int TBracketOpen::prioritet()
{
  return 1;
}

Lexem* TBracketOpen::Calc(Lexem* a, Lexem* b)
{
  throw - 1;
}

int TBracketClose::prioritet()
{
  return 0;
}

Lexem* TBracketClose::Calc(Lexem* a, Lexem* b)
{
  throw - 1;
}

void TOperFactory::create(char* s, int& n, Lexem**& opers)
{
  int l = strlen(s);
  n = 0;
  for (int i = 0; i < l; i++) {
    if (isdigit(s[i]) == 0)
      n++;
  }
  n++;
  n = n * 2 - 1;
  Lexem** res = new Lexem *[n];
  int start = 0;
  int j = 0;
  for (int i = 0; i < l; i++)
  {
    if (isdigit(s[i]) == 0)
    {
      if (i == 0)
      {
        if (s[i] == '(')
          res[j] = new TBracketOpen('(');
        else
          throw - 1;
        j++;
        start = 1;
      }
      else {
        if (isdigit(s[i - 1]) != 0)
        {
          char ch[256];
          int l2 = i - start + 1;

          for (int k = 0; k < l2 - 1; k++)
            ch[k] = s[start + k];

          ch[l2 - 1] = 0;
          res[j] = new TNum(ch);
          j++;
        }
        if (isdigit(s[i]) == false) {
          switch (s[i])
          {
          case '+':res[j] = new TPlus('+'); break;
          case '-':res[j] = new TSub('-'); break;
          case '*':res[j] = new TMultiplication('*'); break;
          case '/':res[j] = new TDivision('/'); break;
          case '(':res[j] = new TBracketOpen('('); break;
          case ')':res[j] = new TBracketClose(')'); break;
          }
          j++;
          start = i + 1;
        }
      }
    }
  }
  int l2 = l - start + 1;
  char ch[256];
  if (l2 > 1)
  {
    for (int k = 0; k < l2 - 1; k++)
      ch[k] = s[start + k];

    ch[l2 - 1] = 0;
    res[j] = new TNum(ch);
    j++;
  }
  n = j;
  opers = new Lexem * [n];
  for (int i = 0; i < n; i++)
    opers[i] = res[i];
  delete[] res;
}

int TPolish::Calculation(char* s)
{
  int n = 0;
  Lexem** operands = 0;
  TOperFactory::create(s, n, operands);
  Lexem** res = new Lexem * [n];
  TStack<Lexem*> stack(n);
  int j = 0;
  for (int i=0; i < n; i++) {
    if (operands[i]->prioritet() == -1) {
      res[j] = operands[i];
      j++;
    }
    else {
      if (stack.isEmpty() || operands[i]->prioritet()==1)
        stack.push(operands[i]);
      else if (operands[i]->prioritet() == 0) 
      {
        Lexem* tmp = stack.get();
        while (tmp->prioritet() != 1) {
          res[j] = tmp;
          j++;
          tmp = stack.get();
        }
      }
      else {
        Lexem* top = stack.get();
        if (operands[i]->prioritet() > top->prioritet()) 
        {
          stack.push(top);
          stack.push(operands[i]);
        }
        else 
        {
          while (operands[i]->prioritet() <= top->prioritet()) 
          {
            res[j] = top;
            j++;
            if (stack.isEmpty())
              break;
            top = stack.get();
          }
          if (!stack.isEmpty())
            stack.push(top);
          stack.push(operands[i]);
        }
      }
    }
  }
  while (!stack.isEmpty())
  {
    Lexem* tmp = stack.get();
    res[j] = tmp;
    j++;
  }
  TStack<Lexem*> ns(n);
  for (int i = 0; i < j; i++)
  {
    if (res[i]->prioritet() == -1)
      ns.push(res[i]);
    else
    {
      Lexem* b = ns.get();
      Lexem* a = ns.get();
      Lexem* c = res[i]->Calc(a, b);
      ns.push(c);
    }
  }
  Lexem* r = ns.get();
  delete[] operands;
  delete[] res;
  return r->getNumber();
}

ofstream& operator<<(ofstream& out, Lexem** s)
{
  // TODO: вставьте здесь оператор return
}
