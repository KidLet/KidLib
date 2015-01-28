#include "Kid/common.h"
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;
using namespace kid;

int main()
{
    string str = "         \rb\n\r\n    \r  ";

    cout << trim(str) << endl;
    cout << trim(str).length() << endl;

    string test = "|hu|";
    vector<string> vec = split(test, "|", false);

    cout << "size:" << vec.size() << endl;
    for(size_t i=0; i<vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;

    char p[][10] = {"|", ","};
    split(test, );

    return 0;
}
