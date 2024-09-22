// Avik_Mahato->Roll=42;
// Avik_Mahato->Department=BCA->3rd_Year;
// Avik_Mahato->College=Bengal Institute Of Science And Technology;

                    // # Binary Search Tree Data Structure 
                    // # Operations : Insertion,Deletion,Display(Pre,In,Post) Order,Search.

#include <iostream>
#include <stdlib.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};
Node *MAX(Node **root, int max)
{
    if ((*root) != nullptr)
    {
        Node *point = (*root);
        if (point->data > max)
        {
            max = point->data;
        }
        if (point->right != nullptr)
        {
            MAX(&(point->right), max);
        }
        else
        {
            return point;
        }
    }
}
Node *MIN(Node **root, int min)
{
    if ((*root) != nullptr)
    {
        Node *point = (*root);
        if (point->data < min)
        {
            min = point->data;
        }
        if (point->left != nullptr)
        {
            MIN(&(point->left), min);
        }
        else
        {
            return point;
        }
    }
}
void In_Order(Node *root)
{
    if (root != nullptr)
    {
        In_Order(root->left);
        cout << root->data << " ";
        In_Order(root->right);
    }
}
void Pre_Order(Node *root)
{
    if (root != nullptr)
    {
        cout << root->data << " ";
        Pre_Order(root->left);
        Pre_Order(root->right);
    }
}
void Post_Order(Node *root)
{
    if (root != nullptr)
    {
        Post_Order(root->left);
        Post_Order(root->right);
        cout << root->data << " ";
    }
}
void Insert(Node **root, int ele)
{
    if ((*root) != nullptr)
    {
        Node *point = (*root);
        if (point->data > ele)
        {
            if (point->left == nullptr)
            {
                Node *newNode = new Node();
                newNode->data = ele;
                newNode->left = nullptr;
                newNode->right = nullptr;
                point->left = newNode;
            }
            Insert(&(point->left), ele);
        }
        else if (point->data < ele)
        {
            if (point->right == nullptr)
            {
                Node *newNode = new Node();
                newNode->data = ele;
                newNode->left = nullptr;
                newNode->right = nullptr;
                point->right = newNode;
            }
            Insert(&(point->right), ele);
        }
    }
}
void Delete(Node **root, int ele)
{
    if ((*root) != nullptr)
    {
        Node *point = (*root);
        Node *Left = point->left;
        Node *Right = point->right;
        if (Left != nullptr && Left->data == ele)
        {
            if (Left->left == nullptr && Left->right == nullptr)
            {
                delete (Left);
                point->left = nullptr;
            }
            else if (Left->left != nullptr && Left->right == nullptr)
            {

                Node *del = Left;
                point->left = Left->left;
                delete (del);
            }
            else if (Left->left == nullptr && Left->right != nullptr)
            {
                Node *del = Left;
                point->left = Left->right;
                delete (del);
            }
            else
            {
                Node *rep = MAX(&(Left->right), 0);
                int temp;
                temp = Left->data;
                Left->data = rep->data;
                rep->data = temp;
                Delete(&Left, ele);
            }
        }
        else if (Right != nullptr && Right->data == ele)
        {
            if (Right->left == nullptr && Right->right == nullptr)
            {
                delete (Right);
                point->right = nullptr;
            }
            else if (Right->left != nullptr && Right->right == nullptr)
            {
                Node *del = Right;
                point->right = Right->left;
                delete (del);
            }
            else if (Right->right != nullptr && Right->left == nullptr)
            {
                Node *del = Right;
                point->right = Right->right;
                delete (del);
            }

            else
            {
                Node *rep = MIN(&(Right->left), Right->data);
                int temp;
                temp = Right->data;
                Right->data = rep->data;
                rep->data = temp;
                Delete(&Right, ele);
            }
        }
        else
        {
            if (point->data > ele)
            {
                Delete(&(point->left), ele);
            }
            else
            {
                Delete(&(point->right), ele);
            }
        }
    }
}
void Search(Node **root, int target)
{
    if ((*root) != nullptr)
    {
        Node *point = (*root);
        if (point->data == target)
        {
            cout << "Element Is Found.\n";
        }
        else
        {
            if (point->data > target)
            {
                Search(&(point->left), target);
            }
            else
            {
                Search(&(point->right), target);
            }
        }
    }
    else
    {
        cout << "Element Not Found.\n";
    }
}
int main()
{
    Node *root = new Node();
    root->data = 68;
    root->left = nullptr;
    root->right = nullptr;
    int op, ele;
    while (true)
    {
        cout << "\n\n(1) Insert A Node \t";
        cout << "(2) Delete A Node \t";
        cout << "(3) Search A Node \t";
        cout << "(4) Display All Node Pre_Order\t";
        cout << "\n(5) Display All Node In_Order\t";
        cout << "(6) Display All Node Post_Order\t";
        cout << "\t(7) Exit \t";
        cout << "\n\nChoose An Option : ";
        cin >> op;
        system("cls");
        system("color 2");
        switch (op)
        {
        case 1:
            cout << "\nEnter An Node Data : ";
            cin >> ele;
            Insert(&root, ele);
            break;
        case 2:
            cout << "Enter Delete Node Data : ";
            cin >> ele;
            Delete(&root, ele);
            break;
        case 3:
            cout << "Search An Node Data : ";
            cin >> ele;
            Search(&root, ele);
            break;
        case 4:
            cout << "Display All Node In Pre_Order : ";
            Pre_Order(root);
            break;
        case 5:
            cout << "Display All Node In In_Order : ";
            In_Order(root);
            break;
        case 6:
            cout << "Display All Node In Post_Order : ";
            Post_Order(root);
            break;
        case 7:
            exit(0);
        default:
            cout << "Please Choose A Correct Option\n";
        }
    }
    return 0;
}