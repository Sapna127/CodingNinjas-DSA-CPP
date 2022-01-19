#include "BinaryTreeNode.h"
using namespace std;
class BST
{
    BinaryTreeNode<int> *root;

private:
    //to avoid taking 2 arguments from user we are creating private helper fuction here
    bool hasData(int data, BinaryTreeNode<int> *node)
    {
        if (node == NULL)
            return false;
        if (node->data == data)
            return true;
        else if (data < node->data)
        {
            return hasData(data, root->left);
        }
        else
        {
            return hasData(data, root->right);
        }
    }
    BinaryTreeNode<int> *insertData(int data, BinaryTreeNode<int> *node)
    {
        if (node == NULL)
        {
            BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }
        if (data < node->data)
        {
            node->left = insertData(data, node->left);
        }
        else
        {
            node->right = insertData(data, node->right);
        }
        return node;
    }
    BinaryTreeNode<int> *deleteData(int data, BinaryTreeNode<int> *node)
    {
        if (node == NULL)
            return NULL;
        if (data < node->data)
        {
            node->left = deleteData(data, node->left);
            return node;
        }
        if (data > node->data)
        {
            node->right = deleteData(data, node->right);
            return node;
        }
        if (data == node->data)
        {
            if (node->left == NULL && node->right == NULL)
            {
                delete node;
                return NULL;
            }
            if (node->left == NULL && node->right != NULL)
            {
                BinaryTreeNode<int> *temp = node->right;
                delete node;
                return temp;
            }
            if (node->left != NULL && node->right == NULL)
            {
                BinaryTreeNode<int> *temp = node->left;
                delete node;
                return temp;
            }
            if (node->left != NULL && node->right != NULL)
            {
                BinaryTreeNode<int> *minNode = node->right;
                while (minNode->left != NULL)
                {
                    minNode = minNode->left;
                }
                int rightMin = minNode->data;
                node->data = rightMin;
                node->right = deleteData(rightMin, node->right);
                return node;
            }
        }
    }

public:
    BST()
    {
        root = NULL;
    }
    ~BST()
    {
        delete root;
    }
    void deleteData(int data)
    {
        root = deleteData(data, root);
    }
    void insertData(int data)
    {
        this->data = insertData(data, this->root);
    }
    bool hasData(int data)
    {
        hasData(data, root);
    }
};