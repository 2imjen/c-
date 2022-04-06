#include <iostream>
#include <string>

using namespace std;

typedef struct SinhVien
{
    string msv;
    string hoVaTen;
    double diem;
} SV;

void output(SV sv[], int n)
{
    cout << "Danh sach SV:";
    for (int i = 0; i < n; i++)
    {
        cout << "\n" << sv[i].msv << "\t" << sv[i].hoVaTen << "\t" << sv[i].diem;
    }
}

int main()
{
    int n;

    do
    {
        cout << "Nhap so sinh vien n = ";
        cin >> n;
    } while (n <= 0);

    cin.ignore();

    SV sv[1000];

    for (int i = 0; i < n; i++)
    {
        cout << "Nhap Ma SV: ";
        cin >> sv[i].msv;
        cin.ignore();

        cout << "Nhap Ten SV: ";
        getline(cin, sv[i].hoVaTen);

        cout << "Nhap Diem: ";
        cin >> sv[i].diem;
        cin.ignore();
    }

    output(sv, n);

    double diemMax = sv[0].diem;
    for (int i = 0; i < n; i++)
        if (sv[i].diem > diemMax)
            diemMax = sv[i].diem;

    cout << "\nCac Sinh vien co diem cao nhat:";
    for (int i = 0; i < n; i++)
        if (sv[i].diem == diemMax)
            cout << "\n" << sv[i].msv << "\t" << sv[i].hoVaTen << "\t" << sv[i].diem;
            
    return 0;
}