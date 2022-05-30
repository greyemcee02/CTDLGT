#include <iostream>
using namespace std;
int main()
{
    int *p;
    p = new int(3);
    cout << p << endl;
    cout << *p << endl;
    delete p;
    cout << p << endl;
    cout << *p << endl;
    system("pause");
    return 0;
}
