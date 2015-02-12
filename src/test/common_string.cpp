#include "Kid/common.h"
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;
using namespace kid;

int main()
{


    string test = "||h;a";
    vector<string> delimiter;

    delimiter.push_back("||");
    delimiter.push_back(";");


    vector<string> vec = Split(test, delimiter, false);

    cout << "size:" << vec.size() << endl;
    for(size_t i=0; i<vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;

    cout << StartsWith("huangpeihonghuang", "pei", 4) << endl;
    cout << EndsWith("huangpeihonghuang1", "huang1") << endl;
    cout << Join("i", " love", " you") << endl;


    return 0;
}
