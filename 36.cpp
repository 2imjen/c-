#include <iostream>
#include <cmath>
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

bool isPrime(int n)
{
    if (n < 2) return false;

    int sq = sqrt(n);

    for (int i = 2; i <= sq; i++)
        if (n%i == 0)
            return false;

    return true;
}

void input(int &n, Node *&list)
{
    do
    {
        cout << "Cho n = ";
        cin >> n;
    } while (n < 10 || n > 100);
    
    for (int i = n; i > 1; i--)
        if (isPrime(i))
            list = insertToTail(list, i);
}

void output(Node *list)
{
    Node *tmp = list;

    cout << "Hien thi lai danh sach:";
    while (tmp != NULL)
    {
        cout << " " << tmp->data;
        tmp = tmp->next;
    }
}

void solve(Node *&list, int x)
{
    if (isPrime(x))
    {
        list = insertToHead(list, x);
        cout << "x la so nguyen to. Hay them x vao dau danh sach.\n";
    }
    else
        cout << "x khong phai la so nguyen to!\n";
}

int main()
{
    int n;
    Node *list = NULL;

    input(n, list);
    output(list);

    cout << "\nCho so nguyen x = ";
    int x;
    cin >> x;
    
    solve(list, x);
    output(list);

    return 0;
}