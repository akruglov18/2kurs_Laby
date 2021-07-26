#pragma once

#include<iostream>
#include "TStack.h"
#include<vector>
#include<string.h>

class TextNode 
{
protected:
  static TextNode* firstFree;
  static vector<TextNode*> textNodes;

  TextNode* next;
  TextNode* down;
  char c;
  int level;
public:
  TextNode(int _l = 3, char _c = 0);
  TextNode(const TextNode& node);
  TextNode(char* s, int l);
  ~TextNode();
  TextNode* getNext();
  TextNode* getDown();
  char getC();
  int getLevel();

  void setNext(TextNode* node);
  void setDown(TextNode* node);
  void setC(char _c);
  void setLevel(int _l);

  friend std::ostream& operator<<(std::ostream& stream, const TextNode& node);

  static void initMem(int size = 100);
  static void freeMem();

  void* operator new (size_t size);
  void operator delete (void*);
};