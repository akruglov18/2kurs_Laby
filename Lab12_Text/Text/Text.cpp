#include "Text.h"

TextIter::TextIter(Text& _text, TextNode* _node, TStack<TextNode*> _st) : text(_text) {
  node = _node;
  st = _st;
}

TextIter::TextIter(const TextIter& t) : text(t.text)
{
  node = t.node;
  st = t.st;
}

bool TextIter::GoNext()
{
  if (node->getLevel() == 3)
  {
    if (node->getNext() != 0) {
      node = node->getNext();
    }
    else
    {
      node = st.get();
      if (node->getNext() != 0) {
        node = node->getNext();
      }
      else
      {
        node = st.get();
        if (node->getNext() != 0) {
          node = node->getNext();
        }
        else
        {
          node = 0;
          return false;
        }
      }
    }
  }
  else
  {
    st.push(node);
    node = node->getDown();
  }
  return true;
}

bool TextIter::GoNextChar()
{
  if (node->getLevel() == 1) {
    st.push(node);
    node = node->getDown();
    st.push(node);
    node = node->getDown();
    return true;
  }
  if (node->getLevel() == 2) {
    st.push(node);
    node = node->getDown();
    return true;
  }
  if (node->getLevel() == 3 && node->getNext() != NULL) {
    node = node->getNext();
    return true;
  }
  if (node->getLevel() == 3 && node->getNext() == NULL) {
    if (st.isEmpty()) {
      throw std::exception();
    }
    TextNode* prev= st.get();
    if (prev->getNext() != NULL) {
      st.push(prev->getNext());
      node = prev->getNext()->getDown();
      return true;
    }
    return false;
  }
  return false;
}

bool TextIter::IsEnd()
{
  if (node == NULL) {
    return true;
  }
  if (node->getLevel() == 1 || node->getLevel() == 2) {
    return false;
  }
  if (node->getLevel() == 3 && node->getNext() != NULL) {
    return false;
  }
  if (node->getLevel() == 3 && node->getNext() == NULL) {
    if (st.isEmpty()) {
      throw std::exception();
    }
    TextNode* prev = st.get();
    if (prev->getNext() != NULL) {
      return false;
    }
    return true;
  }
  return true;
}

void TextIter::ResetToString() {
  while (node->getLevel() > 1) {
    if (st.isEmpty())
      throw - 1;
    node = st.get();
  }
}

void TextIter::ResetToWord()
{
  if (node->getLevel() == 1)
  {
    st.push(node);
    node = node->getDown();
  }
  else if (node->getLevel() == 3)
  {
    node = st.get();
  }
}

TextNode* TextIter::Get() {
  return node;
}

Text::Text(char* s) {
  root = new TextNode(s, 1);
}

Text::~Text()
{
  //TStack<TextNode*> st;
  //st.push(root);
  //while (!st.isEmpty())
  //{
  //  TextNode* str = st.get();
  //  if (str->getNext() != nullptr)
  //    st.push(str->getNext());
  //  if (str->getDown() != nullptr)
  //    st.push(str->getDown());
  //}
  TextNode::freeMem();
}


TextIter Text::GetRoot()
{
  TStack<TextNode*> s(100);
  TextIter it(*this, root, s);
  return it;
}

TextIter Text::Find(char c)
{
  TextIter iter = GetRoot();
  while (iter.GoNextChar())
  {
    if (iter.Get()->getC() == c)
      return iter;
  }
  return iter;
}

TextIter Text::FindWord(char* c) {
  TextIter i = GetRoot();
  while (i.GoNext()) {
    if (i.Get()->getLevel() == 2) {
      TextIter res = i;
      bool ok = true;
      int j = 0;
      int n = strlen(c);
      while (i.GoNext() && j < n) {
        if (i.Get()->getLevel() == 2) {
          ok = false;
          break;
        }
        if (i.Get()->getC() != c[j]) {
          ok = false;
          break;
        }
        j++;
      }
      if (ok) {
        return res;
      }
    }
  }
  return i;
}

TextIter Text::Find(char* s)
{
  TextIter iter = GetRoot();
  int n = strlen(s);
  while (iter.GoNextChar()) {
    TextIter cur = iter;
    int i = 0;
    bool ok = true;
    bool isGo = true;
    while (i < n) {
      if (!isGo) {
        ok = false;
        break;
      }
      if (s[i] != cur.Get()->getC()) {
        ok = false;
        break;
      }
      isGo = cur.GoNextChar();
    }
    if (ok) {
      return iter;
    }
  }
}

void Text::Insert(char* c, TextIter i)
{
  TextNode* node = new TextNode(c, i.Get()->getLevel());
  TextNode* next = i.Get()->getNext();
  node->setNext(next);
  i.Get()->setNext(node);
}

void Text::Delete(int count, TextIter i)
{
  if (count == 0)
    return;
  TStack<TextNode*> stacks[3];
  int deleted = 0;

  // перейти к букве, с которой начнётся удаление
  if (i.Get()->getLevel() < 3)
    i.GoNextChar();

  int level = i.Get()->getLevel();
  if (level >= 1 && level <= 3) {
    stacks[level - 1].push(i.Get());
    if (level == 3) {
      deleted++;
    }
  }
  TextIter j = i;
  while (j.GoNext() && deleted < count) {
    level = j.Get()->getLevel();
    if (level >= 1 && level <= 3) {
      stacks[level - 1].push(j.Get());
      if (level == 3) {
        deleted++;
      }
    }
  }
  if (deleted < count)
    throw std::exception();
  // удаление букв в одном слове ----------------------------------
  if (stacks[0].isEmpty() && stacks[1].isEmpty()) {
    TextIter prev = i;
    prev.ResetToWord();
    while (prev.Get()->getNext() != i.Get() && prev.Get()->getDown() != i.Get()) {
      prev.GoNext();
    }
    TextNode* last = stacks[2].get();
    if (prev.Get()->getLevel() == 2) {
      prev.Get()->setDown(last->getNext());
    }
    else {
      prev.Get()->setNext(last->getNext());
    }
    delete last;
    return;
  }
  //--------------------------------------------------------------
  // установка nulltr для буквы, после которой начинается удаление
  {
    TextIter prev = i;
    prev.ResetToWord();
    while (prev.Get()->getNext() != i.Get() && prev.Get()->getDown() != i.Get()) {
      prev.GoNext();
    }
    if (prev.Get()->getNext() == i.Get()) {
      prev.Get()->setNext(NULL);
    }
    else {
      prev.Get()->setDown(NULL);
    }
  }
  // -------------------------------------------------------------
  //удалеение букв в одной строке --------------------------------
  if (stacks[0].isEmpty()) {
    TextNode* last_word = stacks[1].get();
    TextNode* last_letter = stacks[2].get();
    TextIter cur = i;
    cur.ResetToWord();
    cur.Get()->setNext(last_word);
    last_word->setDown(last_letter->getNext());
    delete last_letter;
    for (int i = 1; i < 3; i++) {
      while (!stacks[i].isEmpty()) {
        TextNode* del = stacks[i].get();
        delete del;
      }
    }
    return;
  }
  // -------------------------------------------------------------
  //удаление букв в разных строках --------------------------------
  TextNode* last_string = stacks[0].get();
  TextNode* last_word = stacks[1].get();
  TextNode* last_letter = stacks[2].get();
  TextIter cur = i;
  cur.ResetToString();
  cur.Get()->setNext(last_string);
  cur.ResetToWord();
  cur.Get()->setNext(last_word);
  last_word->setDown(last_letter->getNext());
  delete last_letter;
  for (int i = 0; i < 3; i++) {
    while (!stacks[i].isEmpty()) {
      TextNode* del = stacks[i].get();
      delete del;
    }
  }
}

char* Text::Copy(int count, TextIter i)
{
  if (count < 0)
    throw std::exception();
  char* res = new char[count + 1];
  TextIter cur = i;
  while (cur.Get()->getLevel() < 3) {
    cur.GoNext();
  }
  if (count > 0) {
    res[0] = cur.Get()->getC();
    int j = 1;
    while (cur.GoNextChar() && j < count) {
      res[j] = cur.Get()->getC();
      j++;
    }
  }
  res[count] = '\0';
  return res;
}

bool Text::Save(const string& fileName) const
{
  ofstream fout(fileName);
  if (fout.is_open()) {
    fout << *root;
    fout.close();
    return true;
  }
  else {
    return false;
  }
}

bool Text::Load(const string& fileName)
{
  ifstream fin(fileName);
  if (fin.is_open()) {
    TextNode::freeMem();
    TextNode* cur = NULL;
    while (fin.eof()) {
      string s;
      getline(fin, s);
      char* str = new char[s.size() + 1];
      for (int i = 0; i < s.size(); i++)
        str[i] = s[i];
      str[s.size()] = '\0';
      if (cur == NULL) {
        root = new TextNode(str, 1);
        cur = root;
      }
      else {
        TextNode* add = new TextNode(str, 1);
        cur->setNext(add);
        cur = add;
      }
    }
    fin.close();
    return true;
  }
  else {
    return false;
  }
}

std::ofstream& operator<<(std::ofstream& out, Text& t)
{
  out << *(t.root);
  return out;
}
