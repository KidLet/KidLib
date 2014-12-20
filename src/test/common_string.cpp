#include "Kid/common.h"
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;
using namespace kid;

int main()
{
    string str = "         \r\n\r\n    \r  ";

    cout << trim(str) << endl;
    cout << trim(str).length() << endl;

    string a[] = {"a", "b", "c"};

    cout << a[0] << endl;

    return 0;
}
