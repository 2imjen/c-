#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void input(int &n, vector<int> &a)
{
    do
    {
        cout << "So phan tu n = ";
        cin >> n;
    } while (n <= 0 || n >= 20);
    
    for (int i = 0; i < n; i++)
    {
        cout << "Phan tu thu " << i+1 << ": ";
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

int maxArr(vector<int> a)
{
    int max = a[0];

    for (auto x : a)
        if (x > max)
            max = x;

    return max;
}

bool isPerfectNum(int n)
{
    if (n < 1) return false;

    int sq = sqrt(n);

    return sq*sq == n;
}

int maxPerfectNum(vector<int> a)
{
    int res = a[0];

    for (auto x : a)
        if (isPerfectNum(x) && (x > res || !isPerfectNum(res)))
            res = x;

    return res;
}

int main()
{
    int n;
    vector<int> a;

    input(n, a);
    output(a);

    cout << "\nSo max = " << maxArr(a);
    cout << "\nSo chinh phuong lon nhat: " << maxPerfectNum(a);

    return 0;
}