#include <iostream>
#include <string>

using namespace std;

typedef struct SinhVien
{
    string id;
    string name;
    int birth;
} SV;

struct Node
{
    SV sv;
    Node *next;
};

Node *createNode(SV sv)
{
    Node *p = new Node;

    p->sv.id = sv.id;
    p->sv.name = sv.name;
    p->sv.birth = sv.birth;

    p->next = NULL;

    return p;
}

Node *insertToHead(Node *listSV, SV sv)
{
    Node *p = createNode(sv);
    Node *tmp = listSV;

    p->next = tmp;
    listSV = p;

    return listSV;
}

Node *insertToTail(Node *listSV, SV sv)
{
    Node *p = createNode(sv);
    Node *tmp = listSV;

    if (listSV == NULL)
        listSV = p;
    else
    {
        while (tmp->next != NULL)
            tmp = tmp->next;

        tmp->next = p;
    }

    return listSV;
}

void inputSV(SV &sv)
{
    cout << "Nhap MaSV: ";
    getline(cin, sv.id);
    if (sv.id != "")
    {
        cout << "Nhap ten: ";
        getline(cin, sv.name);
        cout << "Nam sinh: ";
        cin >> sv.birth;
        cin.ignore();
    }
}

void input(Node *&listSV)
{
    SV sv;

    do
    {
        inputSV(sv);
        if (sv.id != "")
            listSV = insertToTail(listSV, sv);
    } while (sv.id != "");
}

void output(Node *listSV)
{
    Node *tmp = listSV;

    cout << "Hien thi danh sach:";
    while (tmp != NULL)
    {
        cout << "\n" << tmp->sv.id << "\t" << tmp->sv.name << "\t" << tmp->sv.birth;
        tmp = tmp->next;
    }
}

int main()
{
    Node *listSV = NULL;

    input(listSV);
    output(listSV);

    SV sv;
    cout << "\nCho SV can them vao dau DS:";
    cout << "\nMaSV: ";
    cin >> sv.id;
    cin.ignore();
    cout << "Ten: ";
    getline(cin, sv.name);
    cout << "Nam sinh: ";
    cin >> sv.birth;

    listSV = insertToHead(listSV, sv);
    output(listSV);

    return 0;
}