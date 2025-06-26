#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next;
    node *prev;
};
node *root = NULL;
node *tail = NULL;
void insert_first(int val)
{
    node *temp;
    temp = new node();
    temp->data = val;
    temp->next = NULL;
    temp->prev = NULL;

    if (root == NULL)
    {
        root = temp;
        tail = temp;
    }
    else
    {
        temp->next = root;
        root->prev = temp;
        root = temp;
    }
}

void insert_last(int val)
{
    node *temp;
    temp = new node();
    temp->data = val;
    temp->next = NULL;
    temp->prev = NULL;

    if (root == NULL)
    {
        root = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
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
    temp->prev=NULL;
    node *curr_node = root;
    node *next_node = root->next;
    while (curr_node != NULL)
    {
        if (curr_node->data == K)
        {
            curr_node->next = temp;
            temp->prev = curr_node;
            temp->next = next_node;
            next_node->prev = temp;
            return;
        }
        curr_node = curr_node->next;
        next_node = curr_node->next;
    }
}
void deletfirst()
{
    if (root->next != NULL)
    {
        root = root->next;
        root->prev = NULL;
    }
}
void deletelast()
{
    if (tail != NULL)
    {
        tail = tail->prev;
        tail->next = NULL;
    }
}
void deletanywhere(int K)
{
    node *curr_node = root;
    node *next_node = root->next;
    if (curr_node->data == K)
    {
        deletfirst();
        return;
    }

    while (curr_node->next != NULL)
    {
        if (curr_node->data == K)
        {
            next_node->prev = curr_node->prev;
            curr_node->prev->next = next_node;
            return;
        }
        curr_node = curr_node->next;
        next_node = curr_node->next;
    }
    if (next_node == NULL)
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
    cout << endl;
    curr_node = tail;
    while (curr_node != NULL)
    {
        cout << curr_node->data << " ";
        curr_node = curr_node->prev;
    }
    cout << endl;
}
void lastnode()
{
    cout << tail->data << endl;
}
void prev_lastnode()
{
    cout << tail->prev->data << endl;
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
int List(int l)
{
    int count = 1;
    node *first_node = root;
    while (count != l)
    {
        first_node = first_node->next;
        count++;
    }
    int x = first_node->data;
    return x;
}
void Binary_Search(int K)
{
    int l = 1;
    int h = listsize();
    while (l < h)
    {
        int mid = (l + h) / 2;
        if (List(mid) < K)
        {
            l = mid + 1;
        }
        else
        {
            h = mid;
        }
    }
    if (List(l) == K)
    {
        cout << "Fount at possition: " << l << "The element: " << List(l) << endl;
    }
    else if (List(h) == K)
    {
        cout << "Fount at possition: " << h << "The element: " << List(h) << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }
    return;
}
void makeCycle(int pos)
{
    node *curr_node;
    curr_node = root;
    int count = 1;
    while (count!=pos)
    {
        curr_node = curr_node->next;
        count++;
    }
    tail->next=curr_node;
}
void detectCycle()
{
    node *tortoile=root;
    node *hair=root;
    while(tortoile->next!=NULL)
    {
        tortoile=tortoile->next;
        hair=hair->next->next;
        if (hair=tortoile)
        {
            cout<<"The list has a cycle"<<endl;
            return;
        }
    }
    cout<<"The list has no cycle"<<endl;
    return;
}
node* Cycle_node()
{
      node *tortoile=root;
    node *hair=root;
    while(tortoile!=hair)
    {
        tortoile=tortoile->next;
        hair=hair->next->next;
    }
    tortoile=root;
    while (tortoile!=hair)
    {
        tortoile=tortoile->next;
        hair=hair->next;
    }
    return tortoile;
    
}
int CycleLength()
{
   node* hair=Cycle_node();
   node* tortoile=hair->next;
   int count=1;
   while (tortoile!=hair)
   {
     tortoile=tortoile->next;
     count++;
   }
   return count+1;
}
void deletCycle()
{
     node* hair=Cycle_node();
   node* tortoile=hair->next;
   while (tortoile->next!=hair)
   {
     tortoile=tortoile->next;
   }
   tortoile->next=NULL;
}
void SwaprNode(node* N1,node* N2)
{
    int temp=N1->data;
    N1->data=N2->data;
    N2->data=temp;
}
void SwapIndex(int i,int j)
{
   int count=1;
   node* Curr_node1=root;
   node *Curr_node2=root;
while (count!=i)
    {
        Curr_node1=Curr_node1->next;
        count++;
    }
    count=1;
   while (count!=j)
   {
        Curr_node2=Curr_node2->next;
        count++;
   }
   SwaprNode(Curr_node1,Curr_node2);
   return;
   
}
void Oddparity()
{
    node *tortoile=root;
    node *hair=root;
    while (hair!=NULL)
    {
        if ((tortoile->data)%2!=0 && (hair->data)%2==0)
        {
            SwaprNode(tortoile,hair);
        }if ((tortoile->data)%2!=0 )
        {
            hair=hair->next;
        }else
        {
            tortoile=tortoile->next;
        }
    }
    return;
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
        cout << "10.->Show the middle element" << endl;
        cout << "11.->Binary search" << endl;
        cout << "12.->Make Cycle" << endl;
        cout << "13.->Find the Cycle node" << endl;
        cout << "15.->Odd parity" << endl;
        cout << "14.->swap the element" << endl;
        cout<<"16.->Find the Cycle length"<<endl;
        cout<<"17.->Delet the cycle"<<endl;
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
            cout << endl;
            break;
        case 10:
            cout << "The middle element is: " << endl;
            showmid();
            print();
            cout << endl;
            break;
        case 11:
            int K;
            cout << "Enter the element you want to search in Binary" << endl;
            cin >> K;
            Binary_Search(K);
            cout << endl;
            break;
        case 12:
            cout<<"Enet the index where you want to set the cycle"<<endl;
            int index;
            cin>>index;
            makeCycle(index);
            cout<<endl;
            detectCycle();
            break;
        case 13:
            cout<<"The cycle node is: "<<endl;
            cout<<Cycle_node()->data<<endl;
            break;
        case 14:
            cout<<"Input the 2 indexs where you want to swap elements"<<endl;
            int index1,index2;
            cin>>index1>>index2;
            swap(index1,index2);
            print();
            break;
        case 15:
            Oddparity();
            cout<<"After rearranging the list in odd parity order"<<endl;
            print();
            break;
        case 16:
        cout<<"The cycle length is"<<CycleLength()<<endl;
        break;
        case 17:
        cout<<"Deleting the cycle"<<endl;
        deletCycle();
        print();
        break;
        default:
            cout << endl;
            print();
            delet_linklist();
            print();
            break;
        }
    } while (T);
}
