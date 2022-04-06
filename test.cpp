#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;

    getline(cin, s);
    cin.ignore();

    cout << int(s[0]);
}