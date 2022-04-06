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

Node *insertHead(Node *list, double data)
{
    Node *tmp = list;
    Node *p = createNode(data);

    p->next = tmp;
    list = p;

    return list;
}

Node *insertTail(Node *list, double data)
{
    Node *tmp = list;
    Node *p = createNode(data);

    if (list == NULL)   
        list = p;
    else
    {
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }

        tmp->next = p;
    }

    return list;
}

void input(Node *&list)
{
    double data;
    
    do
    {
        cout << "Nhap phan tu: ";
        cin >> data;

        if (data != 0)
            list = insertTail(list, data);

    } while (data != 0);
}

void output(Node *list)
{
    cout << "\nIn danh sach:";

    Node *tmp = list;
    while (tmp != NULL)
    {
        cout << " " << tmp->data;
        tmp = tmp->next;
    }
}

int lengthList(Node *list)
{
    Node *tmp = list;
    int cnt = 0;

    while (tmp != NULL)
    {
        cnt++;
        tmp = tmp->next;
    }

    return cnt;
}

int main()
{
    Node *list = NULL;

    input(list);
    output(list);

    double x;

    cout << "\nCho x = ";
    cin >> x;
    cout << "Hay them x vao dau va cuoi danh sach:";
    list = insertHead(list, x);
    list = insertTail(list, x);
    output(list);

    cout << "\nDo dai cua DS = " << lengthList(list);

    return 0;
}