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
    } while (n <= 0);
    
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
    cout << "\nIn day so:";
    for (auto x : a)
        cout << x << " ";
    cout << "\n";
}

bool isPerfectNum(int n)
{
    if (n < 1) return false;

    int sq = sqrt(n);

    return sq*sq == n;
}

int maxPerfectNum(vector<int> a)
{
    int max = a[0];

    for (auto x : a)
        if (isPerfectNum(x) && (x > max || !isPerfectNum(x)))
            max = x;

    if (isPerfectNum(max))
        return max;

    return -1;
}

int main()
{
    int n;
    vector<int> a;

    input(n, a);
    output(a);

    int res = maxPerfectNum(a);
    if (res != -1)
        cout << "\nSo chinh phuong lon nhat la: " << res;
    else
        cout << "\nDay khong co so chinh phuong!";

    return 0;
}