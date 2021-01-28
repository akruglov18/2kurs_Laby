#include <iostream>
#include <fstream>
#include "TStack.h"

using namespace std;

int main()
{
    TStack<int> s(10);
    for (int i = 0; i < 10; i++)
      s.push(i);
    cout << s.get() << "\n";
    cout << s.get() << endl;
    ////cout<<(cout<<(cout, s.get()),s.get());
    cout << "Max in stack: " << s.getMax() << " Min in stack: " << s.getMin() << endl;
    ofstream fout("Prov.txt");
    fout << s;
    fout.close();
}
