#include <iostream>

using namespace std;

struct Node
{
    double data;
    Node *next;
};

Node *createNode(double data)
{
    Node *p = new Node;

    p->data = data;
    p->next = NULL;

    return p;
}

Node *insertToHead(Node *list, double data)
{
    Node *p = createNode(data);
    Node *tmp = list;

    p->next = tmp;
    list = p;

    return list;
}

Node *insertToTail(Node *list, double data)
{
    Node *p = createNode(data);
    Node *tmp = list;

    if (list == NULL)
        list = p;
    else
    {
        while (tmp->next != NULL)
            tmp = tmp->next;

        tmp->next = p;
    }

    return list;
}

Node *deleteHead(Node *list)
{
    Node *tmp = list;

    list = list->next;
    tmp->next = NULL;

    delete tmp;

    return list;
}

Node *deleteTail(Node *list)
{
    Node *tmp = list;

    while (tmp->next->next != NULL)
    {
        tmp = tmp->next;
    }

    Node *p = tmp->next;

    tmp->next = NULL;

    delete p;

    return list;
}

void input(int &n, Node *&list)
{
    do
    {
        cout << "Cho n = ";
        cin >> n;
    } while (n < 5 || n > 10);
    
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap phan tu thu " << i+1 << ": ";
        double x;
        cin >> x;

        list = insertToTail(list, x);
    }
}

void output(Node *list)
{
    Node *tmp = list;

    cout << "Hien thi danh sach:";
    while (tmp != NULL)
    {
        cout << " " << tmp->data;

        tmp = tmp->next;
    }
}

int main()
{
    int n;
    Node *list = NULL;

    input(n, list);
    output(list);

    cout << "\nCho x = ";
    double x;
    cin >> x;

    cout << "Hay them x vao dau va cuoi danh sach!\n";
    list = insertToHead(list, x);
    list = insertToTail(list, x);
    output(list);

    cout << "\nHay xoa phan tu o dau va cuoi danh sach!\n";
    list = deleteHead(list);
    list = deleteTail(list);
    output(list);

    return 0;
}