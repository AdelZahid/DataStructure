#include <bits/stdc++.h>
using namespace std;

struct node 
{
    int data;
    node* left;
    node* right;
};
node* root = nullptr;

void BST(node*& root, int val)
{
    node* temp = new node();
    temp->data = val;
    temp->left = nullptr;
    temp->right = nullptr;
    if (root == nullptr)
    {
        root = temp;
    }else
    {
        node* prev_node = root;
        node* curr_node = root;
        while (curr_node != nullptr) {
            prev_node = curr_node;
            if (curr_node->data < val) 
            {
                curr_node = curr_node->right;
            } 
            else 
            {
                curr_node = curr_node->left;
            }
        }
        if (prev_node->data < val) 
        {
            prev_node->right = temp;
        } 
        else
        {
            prev_node->left = temp;
        }
    }
}
void Inorder(node* temp)
{
    if (temp != nullptr)
    {
        Inorder(temp->left);
        cout << temp->data << " ";
        Inorder(temp->right);
    }
}

void Postorder(node* temp) 
{
    if (temp != nullptr) 
    {
        Postorder(temp->left);
        Postorder(temp->right);
        cout<<temp->data<<" ";
    }
}
void Preorder(node* temp) 
{
    if (temp != nullptr) 
    {
        cout<<temp->data<<" ";
        Preorder(temp->left);
        Preorder(temp->right);
    }
}
void Upsort(node* temp)
{
    if (temp != nullptr) 
    {
        Upsort(temp->right);
        cout<<temp->data<<" ";
        Upsort(temp->left);
    }
}
void search(node* temp,int val)
{
    if (temp != nullptr) 
    {
        search(temp->left, val);
        if(temp->data==val)
        {
            cout<<"Found"<<endl;
            return;
        }
        search(temp->right,val);
    }
}
int maxx=INT_MIN;
void Find_max(node *temp)
{
    if (temp != nullptr) {
        if(temp->data>maxx)
        {
            maxx=temp->data;
        }
        Find_max(temp->right);
    }
}
int minn=INT_MAX;
void Find_min(node *temp)
{
    if (temp != nullptr) {
        Find_min(temp->left);
        if(temp->data<minn)
        {
            minn=temp->data;
        }
    }
}
void BinarySrarching(node*temp,int val)
{
    if (temp!=nullptr)
    {
        if (temp->data==val)
        {
            cout<<"Found: "<<temp->data<<endl;
            return;
        }else
        {
            if (temp->data<val)
            {
                BinarySrarching(temp->right,val);
            }else
            {
                BinarySrarching(temp->left,val);
            }
        }
    }else
    {
        cout<<"Not Found"<<endl;
    }
    
    
}
int countlevel=0;
void Countleve_of_nod(node*temp,int val)
{
    if (temp!=nullptr)
    {
        if (temp->data==val)
        {
            countlevel++;
            return;
        }else
        {
            if (temp->data<val)
            {
                Countleve_of_nod(temp->right,val);
                countlevel++;
                return;
            }else
            {
                Countleve_of_nod(temp->left,val);
                countlevel++;
                return;
            }
        }
    }
}
void Delet_node(int val)
{
    node* curr_node = root;
    node* prev_node = nullptr;
    while (curr_node != nullptr && curr_node->data != val)
    {
        prev_node = curr_node;
        if (curr_node->data < val) 
        {
            curr_node = curr_node->right;
        }
        else 
        {
            curr_node = curr_node->left;
        }
    }
    if (curr_node == nullptr) 
    {
        return; 
    }
    if (curr_node->left == nullptr && curr_node->right == nullptr) 
    {
        if (prev_node == nullptr) 
        {
            root = nullptr;
        } else if (prev_node->left == curr_node) 
        {
            prev_node->left = nullptr;
        }
        else 
        {
            prev_node->right = nullptr;
        }
        delete curr_node;
    } else if (curr_node->left == nullptr || curr_node->right == nullptr) 
    {
        node* child = 
        (curr_node->left != nullptr) ? 
        curr_node->left : 
        curr_node->right;
        if (prev_node == nullptr) {
            root = child;
        } else if (prev_node->left == curr_node) {
            prev_node->left = child;
        } else {
            prev_node->right = child;
        }
        delete curr_node;
    }else 
    {
        node* temp = curr_node;
        prev_node = curr_node;
        curr_node = curr_node->right;
        while (curr_node->left != nullptr) 
        {
            prev_node = curr_node;
            curr_node = curr_node->left;
        }
        temp->data = curr_node->data;
        if (prev_node->left == curr_node)
        {
            prev_node->left = curr_node->right;
        } else 
        {
            prev_node->right = curr_node->right;
        }
        delete curr_node;
    }
}
void levelTravarsal(node* temp)
{
    if (root==nullptr)
    {
        return;
    }
    queue<node*>q;
    q.push(temp);
    q.push(nullptr);
    while (!q.empty())
    {
        node* curr_node=q.front();
        q.pop();
        if (curr_node==nullptr)
        {
            cout<<endl;
            if (q.empty())
            {
                break;
            }else
            {
                q.push(nullptr);
            }
        }
        else
        {
            cout<<curr_node->data<<" ";
            if (curr_node->left!=nullptr)
            {
                q.push(curr_node->left);
            }
            if (curr_node->right!=nullptr)
            {
                q.push(curr_node->right);
            }
        }
    }
    
}
int feq=0;
void Countoccurance(node* temp,int vl)
{
    if (temp != nullptr)
    {
        Countoccurance(temp->left,vl);
        if (temp->data==vl)
        {
            feq++;
        }
        Countoccurance(temp->right,vl);
    }
}

int main() 
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        BST(root, x);
    }
    Inorder(root);
    cout<<endl;
    Preorder(root);
    cout<<endl;
    Postorder(root);
    cout<<endl;
    Upsort(root);
    cout<<endl;
    cout<<"Enter the element to search:"<<endl;
    int y;
    cin>>y;
    search(root,y);
    BinarySrarching(root,y);
    int lv;
    cin>>lv;
    Countleve_of_nod(root,lv);
    cout<<countlevel<<endl;
    countlevel=0;
    Find_max(root);
    cout<<maxx<<endl;
    Find_min(root);
    cout<<minn<<endl;
    levelTravarsal(root);
    int D;
    cout<<"Enter the element you want to delet"<<endl;
    cin>>D;
    Delet_node(D);
    Inorder(root);
    cout<<endl;
    cout<<"check feq"<<endl;
    int fq;
    cin>>fq;
    Countoccurance(root,fq);
    cout<<feq<<endl;
    feq=0;
    return 0;
}
