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

void input(Node *&list, int &n)
{
    do
    {
        cout << "Cho n = ";
        cin >> n;
    } while (n < 20);
    
    for (int i = 2; i <= n; i += 2)
        list = insertToTail(list, i);
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

void solve(Node *&list, int x)
{
    if (x % 2 == 0)
    {
        list = insertToHead(list, x);
        cout << "Them x vao dau danh sach!\n";
    }
    else
    {
        list = insertToTail(list, x);
        cout << "Them x vao cuoi danh sach!\n";
    }
}

int main()
{
    int n;
    Node *list = NULL;

    input(list, n);
    output(list);

    cout << "\nCho so nguyen x = ";
    int x;
    cin >> x;

    solve(list, x);
    output(list);

    return 0;
}