#pragma once

#include "TextNode.h"
#include <fstream>
#include <iostream>
#include <string>

class Text;

class TextIter {
protected:
  Text& text;
  TextNode* node;
  TStack<TextNode*> st;

public:
  TextIter(Text& _text, TextNode* _node, TStack<TextNode*> _st);
  TextIter(const TextIter& t);

  bool GoNext();
  bool GoNextChar();
  bool IsEnd();

  void ResetToString();
  void ResetToWord();

  TextNode* Get();
};

class Text {
protected:
  TextNode* root;

public:
  Text(char* s = 0);
  ~Text();

  TextIter GetRoot();
  TextIter Find(char c);
  TextIter FindWord(char* c);
  TextIter Find(char* c);

  void Insert(char* c, TextIter i); // вставить после i
  void Delete(int count, TextIter i); // удалить начиная с i count букв
  char* Copy(int count, TextIter i); // копирует count букв с i

  friend std::ofstream& operator<<(std::ofstream& o, Text& t);
  bool Save(const string& fileName) const;
  bool Load(const string& fileName);
};