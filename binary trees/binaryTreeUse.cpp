#include <iostream>
#include <queue>
#include "binaryTreeNode.h"
using namespace std;

// void printLevelWise(BinaryTreeNode<int> *root)
// {
//     if (!root)
//         return;
//     queue<BinaryTreeNode<int> *> pendingNodes;
//     pendingNodes.push(root);
//     while (!pendingNodes.empty())
//     {
//         BinaryTreeNode<int> *front = pendingNodes.front();
//         pendingNodes.pop();
//         cout << front->data << ":";
//         if (front->left)
//         {
//             pendingNodes.push(front->left);
//             cout << front->left->data;
//         }
//         else
//             cout << "L:-1";
//             cout<< ",";
//         if (front->right)
//         {
//             pendingNodes.push(front->right);
//             cout << front->right->data << endl;
//         }
//         else
//             cout << "R:-1" << endl;
//     }
// }
void printLevelWise(BinaryTreeNode<int> *root)
{

    if (!root)
        return;

    queue<BinaryTreeNode<int> *> pn;
    pn.push(root);

    while (!pn.empty())
    {
        BinaryTreeNode<int> *front = pn.front();
        pn.pop();
        cout << front->data << ":";

        if (front->left)
        {
            pn.push(front->left);
            cout << "L:" << front->left->data;
        }
        else
            cout << "L:-1";

        cout << ",";

        if (front->right)
        {
            pn.push(front->right);
            cout << "R:" << front->right->data << endl;
        }
        else
            cout << "R:-1" << endl;
    }
}
BinaryTreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "enter left child of " << front->data << endl;
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child);
        }
        cout << "enter right child of " << front->data << endl;
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightChildData);
            front->left = child;
            pendingNodes.push(child);
        }
    }
    return root;
}
void printTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left)
    {
        cout << "L" << root->left->data << " ";
    }
    if (root->right)
    {
        cout << "R" << root->right->data;
    }
    cout << endl;
    printTree(root->left);
    printTree(root->right);
}

BinaryTreeNode<int> *takeInput()
{
    int rootData;
    cout << "enter data" << endl;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int> *leftChild = takeInput();
    BinaryTreeNode<int> *rightChild = takeInput();
    root->left = leftChild;
    root->right = rightChild;
    return root;
}

int numNodes(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    return 1 + numNodes(root->left) + numNodes(root->right);
}

void inorder(BinaryTreeNode<int> *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

//diameter of binary tree
int height(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}
int diameter(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    int opt1 = height(root->left) + height(root->right);
    int opt2 = diameter(root->left);
    int opt3 = diameter(root->right);
    return 1 + max(opt1, max(opt2, opt3));
}

//balanced bt
int height(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}
bool isBalanced(BinaryTreeNode<int> *root)
{
    // Write your code here
    if (root == NULL)
        return true;
    int hleft = height(root->left);
    int hright = height(root->right);
    if ((abs(hleft - hright) == 0 || abs(hleft - hright) == 1) && isBalanced(root->left) && isBalanced(root->right))
    {
        return true;
    }
    return false;
}
//return both diameter and height
pair<int, int> heightDiameter(BinaryTreeNode<int> *root)
{
    if (root = NULL)
    {
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }
    pair<int, int> leftans = heightDiameter(root->left);
    pair<int, int> rightans = heightDiameter(root->right);
    int ld = leftans.second;
    int lh = leftans.first;
    int rd = rightans.second;
    int rh = rightans.first;
    int height = 1 + max(lh, rh);
    int diameter = max((lh + rh), max(ld, rd));
    pair<int, int> p;
    p.first = height;
    p.second = diameter;
    return p;
}
//1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main()
{
    /*
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int> *node1 = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int> *node2 = new BinaryTreeNode<int>(1);
    root->left = node1;
    root->right = node2; */
    BinaryTreeNode<int> *root = takeInputLevelWise();
    //printLevelWise(root);
    inorder(root);
    cout << "num of nodes " << numNodes(root) << endl;
    pair<int, int> p = heightDiameter(root);
    cout << "height: " << p.first << endl;
    cout << "diameter: " << p.second << endl;
    delete root;
    return 0;
}