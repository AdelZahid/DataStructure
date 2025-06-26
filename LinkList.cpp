#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *root = NULL;
node *root1=NULL;
node *root2=NULL;
void insert_first(int val)
{
    node *temp;
    temp = new node();
    temp->data = val;
    temp->next = NULL;
    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        temp->next = root;
        root = temp;
        return;
    }
}

void insert_last(int val)
{
    node *temp;
    temp = new node();
    temp->data = val;
    temp->next = NULL;
    node *Curr_Node = root;
    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        while (Curr_Node->next != NULL)
        {
            Curr_Node = Curr_Node->next;
        }
        Curr_Node->next = temp;
        return;
    }
    
}
void insert_last_1stlist(int val)
{
    node *temp;
    temp = new node();
    temp->data = val;
    temp->next = NULL;
    node *Curr_Node = root1;
    if (root1 == NULL)
    {
        root1 = temp;
    }
    else
    {
        while (Curr_Node->next != NULL)
        {
            Curr_Node = Curr_Node->next;
        }
        Curr_Node->next = temp;
        return;
    }
    
}
void insert_last_2ndlist(int val)
{
    node *temp;
    temp = new node();
    temp->data = val;
    temp->next = NULL;
    node *Curr_Node = root2;
    if (root2 == NULL)
    {
        root2 = temp;
    }
    else
    {
        while (Curr_Node->next != NULL)
        {
            Curr_Node = Curr_Node->next;
        }
        Curr_Node->next = temp;
        return;
    }
    
}
bool search(int val)
{
    node *curr_node = root;
    while (curr_node != NULL)
    {
        if (curr_node->data == val)
        {
            return true;
        }
        curr_node = curr_node->next;
    }
    return false;
}
void insert_anywhere(int val, int K)
{
    node *temp;
    temp = new node();
    temp->data = val;
    temp->next = NULL;
    node *curr_node = root;
    node *next_node = root->next;
    while (curr_node != NULL)
    {
        if (curr_node->data == K)
        {
            curr_node->next = temp;
            temp->next = next_node;
            return;
        }
        curr_node = curr_node->next;
        next_node = curr_node->next;
    }
}
void insert_after(int val, int K)
{
    node *temp;
    temp = new node();
    temp->data = val;
    temp->next = NULL;
    node *curr_node = root;
    node *next_node = root->next;
    while (curr_node != NULL)
    {
        if (curr_node->data == K)
        {
            curr_node->next = temp;
            temp->next = next_node;
            return;
        }
        curr_node = curr_node->next;
        next_node = curr_node->next;
    }
}
void insert_before(int val, int K)
{
    node *temp;
    temp = new node();
    temp->data = val;
    temp->next = NULL;
    node *curr_node = root;
    node *prev_node;
    while (curr_node != NULL)
    {
        if (curr_node->data == K)
        {
            prev_node->next = temp;
            temp->next = curr_node;
            return;
        }
        prev_node = curr_node;
        curr_node = curr_node->next;
    }
}
void deletfirst()
{
    if (root->next != NULL)
    {
        root = root->next;
    }
}
void deletelast()
{
    node *curr_node = root;
    node *prev_node = root;
    while (curr_node->next != NULL)
    {
        prev_node = curr_node;
        curr_node = curr_node->next;
    }
    prev_node->next = NULL;
    return;
}
void deletanywhere(int K)
{
    node *curr_node = root;
    node *next_node = root->next;
    node *prev_node = root;
    if (curr_node->data == K)
    {
        deletfirst();
        return;
    }

    while (curr_node->next != NULL)
    {
        if (curr_node->data == K)
        {
            prev_node->next = next_node;
            return;
        }
        prev_node = curr_node;
        curr_node = curr_node->next;
        next_node = curr_node->next;
    }
    if (curr_node->data==K)
    {
        deletelast();
        return;
    }
    return;
}
void print()
{
    node *curr_node = root;
    while (curr_node != NULL)
    {
        cout << curr_node->data << " ";
        curr_node = curr_node->next;
    }
    return;
}
void recprint()
{
}
void reverse()
{
    node *prev_node = NULL;
    node *curr_node = root;
    node *next_node;
    while (curr_node != NULL)
    {
        next_node = curr_node->next;
        curr_node->next = prev_node;
        prev_node = curr_node;
        curr_node = next_node;
    }
    root = prev_node;
}
void lastnode()
{
    node *curr_node = root;
    while (curr_node->next != NULL)
    {
        curr_node = curr_node->next;
    }
    cout << curr_node->data << endl;
}
void prev_lastnode()
{
    node *curr_node = root;
    while (curr_node->next->next != NULL)
    {
        curr_node = curr_node->next;
    }
    cout << curr_node->data << endl;
}
int listsize()
{
    node *curr_node = root;
    int count = 0;
    while (curr_node != NULL)
    {
        count++;
        curr_node = curr_node->next;
    }
    return count;
}
void showmid()
{
    node *slow = root;
    node *fast = root;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << "Middle element is : " << slow->data << endl;
}
void swap()
{
    node *curr_node = root;
    node *next_node = curr_node->next;
    while (curr_node->next != NULL && next_node->next != NULL)
    {
        int temp = curr_node->data;
        curr_node->data = next_node->data;
        next_node->data = temp;
        curr_node = curr_node->next->next;
        if (curr_node->next != NULL)
        {
            next_node = curr_node->next;
        }
    }
}
void SwaptowNode(node *N1, node *N2)
{
    int temp = N1->data;
    N1->data = N2->data;
    N2->data = temp;
}
void oddparity()
{
    node *tortoile = root;
    node *hair = root;
    while (hair != NULL)
    {
        if ((tortoile->data) % 2 != 0 && (hair->data) % 2 == 0)
        {
            SwaptowNode(tortoile, hair);
        }
        else if ((tortoile->data) % 2 != 0)
        {
            hair = hair->next;
        }
        else
        {
            tortoile = tortoile->next;
        }
    }
    return;
}
void detectCritical()
{
    node *prev = root;
    node *curr_node = prev->next;
    node *next_node = curr_node->next;
    int count = 0;
    while (next_node != NULL)
    {
        if ((prev->data > curr_node->data) && (curr_node->data < next_node->data))
        {
            count++;
        }
        else if ((prev->data < curr_node->data) && (curr_node->data > next_node->data))
        {
            count++;
        }
            prev = curr_node;
            curr_node = curr_node->next;
            next_node = curr_node->next;
    }
    cout<<count<<endl;
}
void removeDuplicate(node *N)
{
    node *tortoile = N;
    node *hare = N->next;
    while (hare != NULL)
    {
        if (tortoile->data == hare->data)
        {
            deletanywhere(hare->data);
        }
        hare = hare->next;
    }
}
void Remove()
{
    node *temp = root;
    while (temp != NULL)
    {
        removeDuplicate(temp);
        temp = temp->next;
    }
}
 void Make_cycle(int p)
{
    node *temp = root;
    node *Standing_node;
    int count = 0;
    while (temp->next != NULL)
    {
        if (count == p)
        {
            Standing_node = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = Standing_node;
}
void detectCycle()
{
    node *tortoile = root;
    node *haire = root;
    while (tortoile != NULL)
    {
        tortoile = tortoile->next;
        haire = haire->next->next;
        if (tortoile == haire)
        {
            cout << "The linklist has a Cycle" << endl;
            return;
        }
    }
    cout << "The linklist has no Cycle" << endl;
}
int CycleNode()
{
    node *tortoile = root;
    node *haire = root;
    while (tortoile != NULL)
    {
        tortoile = tortoile->next;
        haire = haire->next->next;
        if (tortoile == haire)
        {
            break;
        }
    }
    node *tortoile2 = root;
    while (tortoile != tortoile2)
    {
        tortoile = tortoile->next;
        tortoile2 = tortoile2->next;
    }
    return tortoile->data;
}
int Cyclelength()
{
    int k = CycleNode();
    node *tortoile = root;
    node *tortoile2 = root;
    int count = 1;
    while (tortoile->data != k)
    {
        tortoile = tortoile->next;
        tortoile2 = tortoile2->next;
    }
    tortoile2 = tortoile2->next;
    while (tortoile2->data != k)
    {
        count++;
        tortoile2 = tortoile2->next;
    }
    return count;
}
int Total_length()
{
    int a = Cyclelength();
    int k = CycleNode();
    node *tortoile = root;
    int count = 0;
    while (tortoile->data != k)
    {
        count++;
        tortoile = tortoile->next;
    }
    return count + a;
}
void deletCycle()
{
    int K = CycleNode();
    node *tortoile = root;
    node *tortoile2 = root;
    int count = 1;
    while (tortoile->data != K)
    {
        tortoile = tortoile->next;
        tortoile2 = tortoile2->next;
    }
    tortoile2 = tortoile2->next;
    while (tortoile2->next->data != K)
    {
        tortoile2 = tortoile2->next;
    }
    tortoile2->next = NULL;
    return;
}
void rotate(int K)
{
    while (K--)
    {
        node *curr_node = root;
        while (curr_node->next != NULL)
        {
            curr_node = curr_node->next;
        }
        int x = curr_node->data;
        deletelast();
        insert_first(x);
    }
}
void sumof_Towlinklist()
{
    node *curr_node1 = root1;
    node *curr_node2 = root2;
    node *curr_node = root;
    string sum1;
    string sum2;
    while (curr_node1 != NULL)
    {
        sum1 += to_string(curr_node1->data);  
        curr_node1 = curr_node1->next;
    }
    
    while (curr_node2 != NULL)
    {
        sum2 += to_string(curr_node2->data);  
        curr_node2 = curr_node2->next;
    }
    int res1 = stoi(sum1);
    int res2 = stoi(sum2);
    int res3 = res1 + res2;
    string sum3 = to_string(res3);
    for (auto ch : sum3)
    {
        int val = ch - '0';  
        insert_last(val);    
    }
}

void delet_linklist()
{
    while (root)
    {
        node *temp = root;
        root = root->next;
        delete temp;
    }
}
int main()
{
    int n;
    cout << "Enter the size of linklist to insert first" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        insert_last(x);
    }
    int m;
    cout << "Enter the seze of linklist to insert last" << endl;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int y;
        cin >> y;
        insert_first(y);
    }
    int T;
    do
    {
        cin >> T;
        cout << "1.->Print the list" << endl;
        cout << "2.->find the element" << endl;
        cout << "3.->Print the size of list" << endl;
        cout << "4.->Input the value you want to insert also the element after which you want to insert your value" << endl;
        cout << "5.->delet first element" << endl;
        cout << "6.->delet last element" << endl;
        cout << "7.->delet any value" << endl;
        cout << "8.->show the last node" << endl;
        cout << "9.->show the previous of last node" << endl;
        cout << "10.->make cycle" << endl;
        cout << "11.->find the cycle node" << endl;
        cout << "12.->Cycle Length" << endl;
        cout << "13.->total length" << endl;
        cout << "14.->Odd parity" << endl;
        cout<<"15.->swap the element"<<endl;
        cout<<"16.->print reccursively"<<endl;
        cout<<"17.->Remove the duplicate elemnt"<<endl;
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "The elements of linklist are" << endl;
            print();
            break;
        case 2:
            cout << "Which element you want to find" << endl;
            int k;
            cin >> k;
            if (search(k))
            {
                cout << "Found" << endl;
            }
            else
            {
                cout << "Not Found" << endl;
            }
            break;
        case 3:
            cout << "The size of list is: " << listsize() << endl;
            break;
        case 4:
            int A, B;
            cin >> A >> B;
            insert_anywhere(A, B);
            print();
            cout << endl;
            break;
        case 5:
            cout << "After deleting first element" << endl;
            deletfirst();
            print();
            cout << endl;
            break;
        case 6:
            cout << "After deleting last element" << endl;
            deletelast();
            print();
            cout << endl;
            break;
        case 7:
            cout << "Insert the value you want to delet" << endl;
            int D;
            cin >> D;
            deletanywhere(D);
            cout << "After deleting the value" << endl;
            print();
            cout << endl;
            break;
        case 8:
            cout << "The last node is: " << endl;
            lastnode();
            break;
        case 9:
            cout << "The previous of last node is " << endl;
            prev_lastnode();
            showmid();
            cout << endl;
            break;
        case 10:
            cout << "Input the value where you want to make cycle: " << endl;
            int c;
            cin >> c;
            Make_cycle(c);
            detectCycle();
            cout << endl;
            break;
        case 11:
            cout << "CycleNode is: " << CycleNode() << endl;
            break;
        case 12:
            cout << "Cycle Length is: " << Cyclelength() << endl;
            break;
        case 13:
            cout << "Total length is: " << Total_length() << endl;
            break;
        case 14:
            oddparity();
            print();
            cout << endl;
            break;
        case 15:
            swap();
            print();
            cout<<endl;
            break;
        case 16:
            recprint();
            cout<<endl;
            break;
        case 17:
            Remove();
            print();
            cout<<endl;
        default:
            cout << endl;
            print();
            delet_linklist();
            print();
            break;
        }
    } while (T);
        int n,m;
        cin >> n>>m ;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            insert_last_1stlist(x);
        }
        for (int i = 0; i < m; i++)
        {
            int u;
            cin >> u;
            insert_last_2ndlist(u);
        }
        sumof_Towlinklist();
        print();
}
