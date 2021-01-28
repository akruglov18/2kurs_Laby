#include <iostream>
#include "TQueue.h"

using namespace std;

int main()
{
  TQueue<int> q(10);
  for (int i = 0; i < 15; i++)
    q.push(i);
  cout << "Max: " << q.getMax()<<"\n";
  cout << "Min: " << q.getMin()<<"\n";
  while (!q.isEmpty())
    cout << q.get() << " ";
}
