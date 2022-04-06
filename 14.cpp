#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void input(int &n, vector<int> &a)
{
    do
    {
        cout << "Nhap n = ";
        cin >> n;
    } while (n <= 4 || n >= 20);
    
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i << "] = ";
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

void soChan(vector<int> a)
{
    int cnt = 0;

    cout << "\nIn so chan:";
    for (auto x : a)
        if (x%2 == 0)
        {
            cout << " " << x;
            cnt++;
        }

    cout << "\nDay co " << cnt << " so chan!";
}

bool isPerfectNum(int n)
{
    if (n < 1) return false;

    int sq = sqrt(n);

    return sq*sq == n;
}

void perfectNum(vector<int> a)
{
    int cnt = 0;

    cout << "\nIn so chinh phuong:";
    for (auto x : a)
        if (isPerfectNum(x))
        {
            cout << " " << x;
            cnt++;
        }

    cout << "\nDay co " << cnt << " so chinh phuong!";
}

int main()
{
    int n;
    vector<int> a;

    input(n, a);
    output(a);
    soChan(a);
    perfectNum(a);

    return 0;
}