#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void input(vector<int> &a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "So thu " << i << ": ";
        int x;
        cin >> x;
        
        a.push_back(x);
    }
}

void output(vector<int> a)
{
    cout << "\nDay so:";
    for (auto x : a)
        cout << x << " ";
    cout << "\n";
}

void outputReverseArr(vector<int> a)
{
    cout << "\nDao nguoc day so:";
    for (int i = a.size(); i >= 0; i--)
        cout << " " << a[i];
}

int soChiaHetCho3(vector<int> a)
{
    int cnt = 0;

    for (auto x : a)
        if (x%3 == 0)
            cnt++;

    return cnt;
}

bool isPerfectNum(int n)
{
    if (n < 1) return false;

    int sq = sqrt(n);

    return sq*sq == n;
}

int cntPerfectNum(vector<int> a)
{
    int cnt = 0;

    for (auto x : a)
        if (isPerfectNum(x))
            cnt++;

    return cnt;
}

int main()
{
    int n;

    cout << "Nhap n = ";
    cin >> n;

    vector<int> a;

    input(a, n);
    output(a);
    outputReverseArr(a);
    cout << "\nDay co " << soChiaHetCho3(a) << " so chia het cho 3.";
    cout << "\nDay co " << cntPerfectNum(a) << " so chinh phuong.";

    return 0;
}