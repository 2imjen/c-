#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef struct SinhVien
{
    string id;
    string name;
    int score;
} SV;

void inputSV(SV &sv)
{
    cout << "Nhap Ma SV: ";
    cin >> sv.id;
    cin.ignore();
    cout << "Nhap Ten SV: ";
    getline(cin, sv.name);
    cout << "Nhap Diem: ";
    cin >> sv.score;
}

void input(int &n, vector<SV> &listSV)
{
    do
    {
        cout << "Nhap so sinh vien n = ";
        cin >> n;
    } while (n <= 0);
    cin.ignore();

    for (int i = 0; i < n; i++)
    {
        SV sv;
        inputSV(sv);
        listSV.push_back(sv);
    }
}

void swap(SV &a, SV &b)
{
    SV tmp = a;
    a = b;
    b = tmp;
}

void sortSV(vector<SV> &sv)
{
    int len = sv.size();

    for (int i = 0; i < len-1; i++)
        for (int j = i+1; j < len; j++)
            if (sv[i].score > sv[j].score)
                swap(sv[i], sv[j]);
}

void output(vector<SV> listSV)
{
    cout << "Danh sach Sinh vien:";
    for (SV sv : listSV)
    {
        cout << "\n" << sv.id << "\t" << sv.name << "\t" << sv.score;
    }
}

int main()
{
    int n;
    vector<SV> listSV;

    input(n, listSV);

    sortSV(listSV);

    output(listSV);

    return 0;
}