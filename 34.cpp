#include <iostream>
#include <cmath>

using namespace std;

struct Node
{
    double data;
    Node *next;
};

Node *createNode(double data)
{
    Node *node = new Node;
    
    node->data = data;
    node->next = NULL;

    return node;
}

Node *insertToHead(Node *list, double data)
{
    Node *p = createNode(data);

    p->next = list;
    list = p;

    return list;
}

Node *insertToTail(Node *list, double data)
{
    Node *p = createNode(data);

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

Node *deleteTail(Node *list)
{
    Node *tmp = list;

    while (tmp->next->next != NULL)
    {
        tmp = tmp->next;
    }

    Node *p = tmp->next;
    delete p;

    tmp->next = NULL;

    return list;
}

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

void input(Node *&list, int n)
{
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
    Node *p = list;

    cout << "\nHien thi danh sach:";
    while (p != NULL)
    {
        cout << " " << p->data;
        
        p = p->next;
    }
}

int main()
{
    int n;

    do
    {
        cout << "Cho so phan tu n = ";
        cin >> n;
    } while (n <= 4);

    Node *list = NULL;

    input(list, n);
    output(list);

    double x;
    cout << "\nCho x = ";
    cin >> x;
    cout << "Hay them x vao dau va cuoi danh sach.";
    list = insertToHead(list, x);
    list = insertToTail(list, x);
    output(list);

    cout << "\nHay xoa o cuoi danh sach:";
    list = deleteTail(list);
    output(list);

    cout << "\nDo dai cua DS = " << lengthList(list);

    return 0;
}