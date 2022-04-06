#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(int n)
{
    if (n < 2) return false;

    int sq = sqrt(n);

    for (int i = 2; i <= sq; i++)
        if (n%i == 0)
            return false;

    return true;
}

void input(int &n, vector<int> &a)
{
    do
    {
        cout << "So phan tu n = ";
        cin >> n;
    } while (n <= 0 || n >= 100);
    
    for (int i = 0; i < n; i++)
    {
        cout << "Phan tu thu " << i+1 << ": ";
        int x;
        cin >> x;

        a.push_back(x);
    }
}

int maxArr(vector<int> a)
{
    int max = a[0];

    for (auto x : a)
        if (x > max)
            max = x;

    return max;
}

int minArr(vector<int> a)
{
    int min = a[0];

    for (auto x : a)
        if (x < min)
            min = x;

    return min;
}

void output(vector<int> a)
{
    cout << "\nDay so:";
    for (auto x : a)
        cout << x << " ";
    cout << "\n";
}

int cntPrime(vector<int> a)
{
    int cnt = 0;

    for (auto x : a)
        if (isPrime(x))
            cnt++;

    return cnt;
}

double tbc(vector<int> a)
{
    int sum = 0;

    for (auto x : a)
        sum += x;

    return double(sum) / a.size();
}

int main()
{
    int n;
    vector<int> a;

    input(n, a);
    output(a);

    cout << "\nSo max = " << maxArr(a) << ", so min = " << minArr(a);
    cout << "\nDay co " << cntPrime(a) << " so nguyen to.";
    cout << "\nTBC day so: " << tbc(a);
}