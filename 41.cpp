#include <iostream>
#include <string>
using namespace std;

typedef struct SinhVien
{
    string msv;
    string ten;
    double diem;
} SV;

struct Node
{
    SV sv;
    Node *next;
};

int lengthList(Node *list)
{
    int cnt = 0;

    Node *tmp = list;

    while (tmp != NULL)
    {
        cnt++;
        tmp = tmp->next;
    }

    return cnt;
}

Node *createNode(SV sv)
{
    Node *p = new Node;

    p->sv.msv = sv.msv;
    p->sv.ten = sv.ten;
    p->sv.diem = sv.diem;

    p->next = NULL;

    return p;
}

Node *insertToHead(Node *list, SV sv)
{
    Node *p = createNode(sv);

    p->next = list;
    list = p;

    return list;
}

Node *insertToTail(Node *list, SV sv)
{
    Node *p = createNode(sv);

    if (list == NULL)
    {
        list = p;

        return list;
    }

    Node *tmp = list;

    while (tmp->next != NULL)
        tmp = tmp->next;

    tmp->next = p;

    return list;
}

void inputSV(SV &sv)
{
    cout << "Nhap Ma SV: ";
    cin >> sv.msv;
    cin.ignore();

    cout << "Nhap ten SV: ";
    getline(cin, sv.ten);

    cout << "Diem: ";
    cin >> sv.diem;
    cin.ignore();
}

Node *insertToPos(Node *list, SV sv, int pos)
{
    int length = lengthList(list);

    if (length == 0)
    {
        list = insertToTail(list, sv);
        return list;
    }

    cout << "Hay them x vao vi tri thu 2!\n";

    Node *tmp = list;
    Node *tmp2 = list->next;
    Node *p = createNode(sv);

    tmp->next = p;
    p->next = tmp2;

    return list;
}

void input(Node *&list, int n)
{
    for (int i = 0; i < n; i++)
    {
        SV sv;
        inputSV(sv);

        list = insertToTail(list, sv);
    }
}

void output(Node *list)
{
    cout << "In danh sach:";
    Node *tmp = list;

    while (tmp != NULL)
    {
        cout << "\n" << tmp->sv.msv << "\t" << tmp->sv.ten << "\t" << tmp->sv.diem;
        tmp = tmp->next;
    }
}

int main()
{
    int n;

    do
    {
        cout << "Cho so phan tu n = ";
        cin >> n;
    } while (n < 0);
    cin.ignore();

    Node *list = NULL;
    
    input(list, n);
    output(list);

    cout << "\nCho thong tin 1 SV:\n";
    SV sv;
    cout << "MaSV: ";
    cin >> sv.msv;
    cin.ignore();

    cout << "Ten: ";
    getline(cin, sv.ten);

    cout << "Diem: ";
    cin >> sv.diem;
    cin.ignore();

    list = insertToPos(list, sv, 2);
    output(list);
    cout << "\n";

    return 0;
}