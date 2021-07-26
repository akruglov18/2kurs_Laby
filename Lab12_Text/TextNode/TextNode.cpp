#include "TextNode.h"

TextNode* TextNode::firstFree = NULL;
vector<TextNode*> TextNode::textNodes;

TextNode::TextNode(int _l, char _c)
{
  next = NULL;
  down = NULL;
  c = _c;
  level = _l;
}

TextNode::TextNode(const TextNode& node)
{
  next = NULL;
  down = NULL;
  c = node.c;
  level = node.level;
}

TextNode::TextNode(char* s, int l)
{
  if (l < 1 || l > 3)
    throw std::exception();
  if (l == 1) {
    next = NULL;
    c = 0;
    level = l;
    int sz = strlen(s);
    if (sz > 0) {
      int start = 0;
      TextNode* wcur = new TextNode(2);
      this->setDown(wcur);
      for (int i = 0; i < sz; i++) {
        if (s[i] == ' ' || i == sz - 1) {
          if (start != 0) {
            wcur->setNext(new TextNode(2));
            wcur = wcur->getNext();
          }
          TextNode* lcur = new TextNode(3, s[start]);
          wcur->setDown(lcur);
          for (int j = start + 1; j <= i; j++) {
            lcur->setNext(new TextNode(3, s[j]));
            lcur = lcur->getNext();
          }
          lcur->setNext(NULL);
          start = i + 1;
        }
      }
      wcur->setNext(NULL);
    }
  }
  if (l == 2) {
    next = NULL;
    c = 0;
    level = l;
    int sz = strlen(s);
    if (sz > 0) {
      TextNode* lcur = new TextNode(3, s[0]);
      this->setDown(lcur);
      for (int i = 1; i < sz; i++) {
        lcur->setNext(new TextNode(3, s[i]));
        lcur = lcur->getNext();
      }
      lcur->setNext(NULL);
    }
  }
  if (l == 3) {
    c = s[0];
    level = l;
    next = NULL;
    down = NULL;
  }
}

TextNode::~TextNode()
{
}

TextNode* TextNode::getNext()
{
  return next;
}

TextNode* TextNode::getDown()
{
  return down;
}

char TextNode::getC()
{
  return c;
}

int TextNode::getLevel()
{
  return level;
}

void TextNode::setNext(TextNode* node)
{
  next = node;
}

void TextNode::setDown(TextNode* node)
{
  down = node;
}

void TextNode::setC(char _c)
{
  c = _c;
}

void TextNode::setLevel(int _l)
{
  if (_l >= 1 && _l <= 3)
    level = _l;
  else
    throw std::exception();
}


std::ostream& operator<<(std::ostream& out, const TextNode& node)
{
  if (node.level == 3) {
    out << node.c;
    if (node.next != NULL)
      out << *(node.next);
  }
  else {
    if (node.down != NULL)
      out << *(node.down);
    if (node.next != NULL)
      out << *(node.next);
  }
  return out;
}

void TextNode::initMem(int size)
{
  if (size <= 0)
    throw std::exception();
  TextNode* new_nodes = new TextNode[size];
  for (int i = 1; i < size; i++) {
    new_nodes[i - 1].next = &new_nodes[i];
  }
  textNodes.push_back(firstFree);
  firstFree = new_nodes;
}

void TextNode::freeMem()
{
  for (int i = 0; i < textNodes.size(); i++) {
    delete[] textNodes[i];
  }
  textNodes.clear();
}

void* TextNode::operator new(size_t size)
{
  if (firstFree == NULL)
    initMem();

  TextNode* node = firstFree;
  firstFree = firstFree->next;
  node->next = NULL;
  return node;
}

void TextNode::operator delete(void* p)
{
  TextNode* node = (TextNode*)p;

  node->next = firstFree;
  node->down = NULL;
  node->c = 0;
  node->level = 3;
  firstFree = node;
}