#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *createNode(int data)
{
    Node *p = new Node;

    p->data = data;
    p->next = NULL;

    return p;
}

Node *insertToHead(Node *list, int data)
{
    Node *p = createNode(data);
    Node *tmp = list;

    p->next = tmp;
    list = p;

    return list;
}

Node *insertToTail(Node *list, int data)
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

Node *deleteTail(Node *list)
{
    Node *tmp = list;

    while (tmp->next->next != NULL)
        tmp = tmp->next;

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
    } while (n < 5);
    
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap phan tu: ";
        int x;
        cin >> x;

        list = insertToTail(list, x);
    }
}

void output(Node *list)
{
    Node *tmp = list;

    cout << "In danh sach:";
    while (tmp != NULL)
    {
        cout << " " << tmp->data;
        
        tmp = tmp->next;
    }
}

void evenNum(Node *list)
{
    Node *tmp = list;

    cout << "\nIn so chan trong danh sach:";
    while (tmp != NULL)
    {
        if (tmp->data % 2 == 0)
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

    cout << "\nHay xoa phan tu o cuoi danh sach!\n";
    list = deleteTail(list);
    output(list);

    cout << "\nCho x = ";
    int x;
    cin >> x;

    cout << "Hay them x vao dau danh sach!\n";
    list = insertToHead(list, x);
    output(list);

    evenNum(list);

    return 0;
}