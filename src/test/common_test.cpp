#include "Kid/common.h"
#include <iostream>
#include <cstdlib>

using namespace std;
using namespace kid;

int main()
{
    auto(a, 123);
    cout << a << endl;

    cout << tostr(12345) << endl;
    cout << strto<int>(tostr(12345)) << endl;
    cout << strto<int>("a12a") << endl;

    cout << fmt("%d %s", 1991, "huang") << endl;

    return 0;
}
