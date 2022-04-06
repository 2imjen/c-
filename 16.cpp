#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void input(string &s)
{
    cout << "Nhap ho va ten:\n";
    getline(cin, s);
}

void uprCase(char &c)
{
    if (c >= 97 && c <= 122)
        c -= 32;
}

void chuanHoa(string &s)
{
    //trim
    while (s[0] == ' ')
        s.erase(0, 1);

    while (s[s.length()-1] == ' ')
        s.erase(s.length()-1, 1);

    int i = 0;
    while (i < s.length()-1)
    {
        if (s[i] == ' ' && s[i+1] == ' ')
        {
            s.erase(i, 1);
            continue;
        }
        i++;
    }

    uprCase(s[0]);

    i = 0;
    while (i < s.length()-1)
    {
        if (s[i] == ' ' && s[i+1] != ' ')
            uprCase(s[i+1]);

        i++;
    }
}

int cntWord(string s)
{
    stringstream ss(s);
    int cnt = 0;

    string tmp;
    while (ss >> tmp)
        cnt++;

    return cnt;
}

int main()
{
    string s;

    input(s);

    cout << "Chuan hoa:\n";
    chuanHoa(s);
    cout << s;

    cout << "\nSo tu: " << cntWord(s);

    return 0;
}