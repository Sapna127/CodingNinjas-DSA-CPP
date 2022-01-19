#include <iostream>
#include "BinaryTreeNode.h"
#include <queue>
#include <limits.h>
using namespace std;

BinaryTreeNode<int> *takeInputLevelWise()
{
	int rootData;
	cout << "Enter root data" << endl;
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
		cout << "Enter left child of " << front->data << endl;
		int leftChildData;
		cin >> leftChildData;
		if (leftChildData != -1)
		{
			BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftChildData);
			front->left = child;
			pendingNodes.push(child);
		}
		cout << "Enter right child of " << front->data << endl;
		int rightChildData;
		cin >> rightChildData;
		if (rightChildData != -1)
		{
			BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightChildData);
			front->right = child;
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
	cout << root->data << ":";
	if (root->left != NULL)
	{
		cout << "L" << root->left->data;
	}

	if (root->right != NULL)
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
	cout << "Enter data" << endl;
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
	{
		return 0;
	}
	return 1 + numNodes(root->left) + numNodes(root->right);
}

void inorder(BinaryTreeNode<int> *root)
{
	if (root == NULL)
	{
		return;
	}
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

BinaryTreeNode<int> *buildTreeHelper(int *in, int *pre, int inS, int inE, int preS, int preE)
{
	if (inS > inE)
	{
		return NULL;
	}

	int rootData = pre[preS];
	int rootIndex = -1;
	for (int i = inS; i <= inE; i++)
	{
		if (in[i] == rootData)
		{
			rootIndex = i;
			break;
		}
	}

	int lInS = inS;
	int lInE = rootIndex - 1;
	int lPreS = preS + 1;
	int lPreE = lInE - lInS + lPreS;
	int rPreS = lPreE + 1;
	int rPreE = preE;
	int rInS = rootIndex + 1;
	int rInE = inE;
	BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
	root->left = buildTreeHelper(in, pre, lInS, lInE, lPreS, lPreE);
	root->right = buildTreeHelper(in, pre, rInS, rInE, rPreS, rPreE);
	return root;
}

BinaryTreeNode<int> *buildTree(int *in, int *pre, int size)
{
	return buildTreeHelper(in, pre, 0, size - 1, 0, size - 1);
}

int height(BinaryTreeNode<int> *root)
{
	if (root == NULL)
	{
		return 0;
	}
	return 1 + max(height(root->left), height(root->right));
}

int diameter(BinaryTreeNode<int> *root)
{
	if (root == NULL)
	{
		return 0;
	}

	int option1 = height(root->left) + height(root->right);
	int option2 = diameter(root->left);
	int option3 = diameter(root->right);
	return max(option1, max(option2, option3));
}

pair<int, int> heightDiameter(BinaryTreeNode<int> *root)
{
	if (root == NULL)
	{
		pair<int, int> p;
		p.first = 0;
		p.second = 0;
		return p;
	}
	pair<int, int> leftAns = heightDiameter(root->left);
	pair<int, int> rightAns = heightDiameter(root->right);
	int ld = leftAns.second;
	int lh = leftAns.first;
	int rd = rightAns.second;
	int rh = rightAns.first;

	int height = 1 + max(lh, rh);
	int diameter = max(lh + rh, max(ld, rd));
	pair<int, int> p;
	p.first = height;
	p.second = diameter;
	return p;
}

BinaryTreeNode<int> *findNode(BinaryTreeNode<int> *root, int data)
{
	if (root == NULL)
	{
		return NULL;
	}

	if (root->data == data)
	{
		return root;
	}
	else if (data < root->data)
	{
		return findNode(root->left, data);
	}
	else
	{
		return findNode(root->right, data);
	}
}
void printBetweenK1K2(BinaryTreeNode<int> *root, int k1, int k2)
{
	if (root == NULL)
	{
		return;
	}

	if (root->data >= k1 && root->data <= k2)
	{
		cout << root->data << endl;
	}
	if (root->data > k1)
	{
		printBetweenK1K2(root->left, k1, k2);
	}

	if (root->data <= k2)
	{
		printBetweenK1K2(root->right, k1, k2);
	}
}

int maximum(BinaryTreeNode<int> *root)
{
	if (root == NULL)
	{
		return INT_MIN;
	}
	return max(root->data, max(maximum(root->left), maximum(root->right)));
}

int minimum(BinaryTreeNode<int> *root)
{
	if (root == NULL)
	{
		return INT_MAX;
	}
	return min(root->data, min(minimum(root->left), minimum(root->right)));
}

class IsBSTReturn
{
public:
	bool isBST;
	int minimum;
	int maximum;
};
IsBSTReturn isBST2(BinaryTreeNode<int> *root)
{
	if (root == NULL)
	{
		IsBSTReturn output;
		output.isBST = true;
		output.minimum = INT_MAX;
		output.maximum = INT_MIN;
		return output;
	}
	IsBSTReturn leftOutput = isBST2(root->left);
	IsBSTReturn rightOutput = isBST2(root->right);
	int minimum = min(root->data, min(leftOutput.minimum, rightOutput.minimum));
	int maximum = max(root->data, max(leftOutput.maximum, rightOutput.maximum));
	bool isBSTFinal = (root->data > leftOutput.maximum) && (root->data <= rightOutput.minimum) &&
					  leftOutput.isBST && rightOutput.isBST;
	IsBSTReturn output;
	output.minimum = minimum;
	output.maximum = maximum;
	output.isBST = isBSTFinal;
	return output;
}
bool isBST(BinaryTreeNode<int> *root)
{
	if (root == NULL)
	{
		return true;
	}

	int leftMax = maximum(root->left);
	int rightMin = minimum(root->right);
	bool output = (root->data > leftMax) && (root->data <= rightMin) && isBST(root->left) && isBST(root->right);
	return output;
}

bool isBST3(BinaryTreeNode<int> *root, int min = INT_MIN, int max = INT_MAX)
{
	if (root == NULL)
		return true;
	if (root->data < min || root->data > max)
	{
		return false;
	}
	bool isLeftOk = isBST3(root->left, min, root->data - 1);
	bool isRightOk = isBST3(root->right, root->data, max);
	return isLeftOk && isRightOk;
}

//binary tree from sorted array
BinaryTreeNode<int> *bst(int input[], int s, int e)
{
	if (s > e)
		return NULL;
	int mid = (s + e) / 2;
	BinaryTreeNode<int> *root = new BinaryTreeNode<int>(input[mid]);
	root->left = bst(input, s, mid - 1);
	root->right = bst(input, mid + 1, e);
	return root;
}
BinaryTreeNode<int> *constructTree(int *input, int n)
{
	bst(input, 0, n - 1);
}

//get root to given node path
vector<int> *getRootToNodePath(BinaryTreeNode<int> *root, int data)
{
	if (root == NULL)
		return;
	if (root->data == data)
	{
		vector<int> *output = new vector<int>();
		output->push_back(root->data);
		return output;
	}
	vector<int> *leftOutput = getRootToNodePath(root->left, data);
	if (leftOutput != NULL)
	{
		leftOutput->push_back(root->data);
		return leftOutput;
	}
	vector<int> *rightOutput = getRootToNodePath(root->right, data);
	if (rightOutput != NULL)
	{
		rightOutput->push_back(root->data);
		return rightOutput;
	}
	else
	{
		return NULL;
	}
}

//BST
//root to leaf sum to k
#include <vector>
void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k, vector<int> path)
{
	if (!root)
		return;
	path.push_back(root->data);
	k = k - root->data;
	if (!root->left && !root->right)
	{
		if (k == 0)
		{
			for (i : path)
			{
				cout << i << ' ';
			}
			cout << endl;
		}
		path.pop_back();
		return;
	}
	rootToLeafPathsSumToK(root->left, k, path);
	rootToLeafPathsSumToK(root->right, k, path);
}
void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k)
{
	{
		vector<int> v;
		rootToLeafPathsSumToK(root, k, v);
		return;
	}

	//print nodes at distance k from the node
	void printKdistanceNodesDown(BinaryTreeNode<int> * root, int k)
	{
		if (!root)
			return;
		if (k == 0)
		{
			cout << root->data << endl;
			return;
		}
		printKdistanceNodesDown(root->left, k - 1);
		printKdistanceNodesDown(root->right, k - 1);
	}
	int nodesAtDistanceKancestors(BinaryTreeNode<int> * root, int node, int k)
	{
		{
			if (!root)
				return -1;
			if (root->data == node)
			{
				printKdistanceNodesDown(root, k);
				return 0;
			}
			int dl = nodesAtDistanceKanscestors(root->left, data, k);
			if (dl != -1)
			{
				if (dl + 1 == k)
					cout << root->data << endl;
				else
					printKdistanceNodesDown(root->right, k - dl - 2);
				return 1 + dl;
			}
			int dr = nodesAtDistanceKanscestors(root->right, data, k);
			if (dr != -1)
			{
				if (dr + 1 == k)
					cout << root->data << endl;
				else
					printKdistanceNodesDown(root->right, k - dr - 2);
				return 1 + dr;
			}
			return -1;
		}
		void nodesAtDistanceK(BinaryTreeNode<int> * root, int node, int k)
		{
			int x = nodesAtDistanceK(root, node, k);
		}
//largest bst height in binary tree
#include <clinits>
#include <cmath>
		class pair
		{
			int minimum;
			int maximum;
			bool bst;
			int height;
		};
		pair bst(BinaryTreeNode<int> * root)
		{
			if (!root)
			{
				pair obj;
				obj.minimum = INT_MAX;
				obj.maximum = INT_MIN;
				obj.bst = true;
				obj.height = 0;
				return obj;
			}
			pair left = bst(root->left);
			pair right = bst(root->right);
			int minimum = min(root->data, min(left.minimum, right.minimum));
			int maximum = max(root->data, max(left.maximum, right.maximum));
			bool isBSTFinal = (root->data > left.maximum) && (root->data < right.maximum) && left.bst && right.bst;
			pair obj;
			obj.minimum = minimum;
			obj.maximum = maximum;
			obj.bst = isBSTfinal;
			if (isBSTfinal)
			{
				obj.height = 1 + max(left.height, right.height);
			}
			else
				obj.height = max(left.height, right.height);
			return obj;
		}

		int largestBSTSubtree(BinaryTreeNode<int> * root)
		{
			// Write your code here
			return BST(root).height;
		}
	}
	//bst to ll
	class pair
	{
	public:
		BinaryTreeNode<int> *head;
		BinaryTreeNode<int> *tail;
	};

	pair LL(BinaryTreeNode<int> * root)
	{
		if (!root)
		{
			pair ans;
			ans.head = NULL;
			ans.tail = NULL;
			return ans;
		}

		BinaryTreeNode<int> *node = new BinaryTreeNode<int>(root->data);
		pair leftans = LL(root->left);
		pair rightans = LL(root->right);
		pair ans;
		if (!leftans.head && !rightans.tail)
		{
			ans.head = node;
			ans.tail = node;
		}
		else if (!leftans.head && rightans.head)
		{
			ans.head = node;
			node->next = rightans.head;
			ans.tail = rightans.tail;
		}
		else if (leftans.head && !rightans.head)
		{
			ans.head = leftans.tail;
			leftans.tail->next = node;
			ans.tail = node;
		}
		else
		{
			ans.head = leftans.head;
			leftans.head->next = node;
			node->next = rightans.head;
			ans.tail = rightans.tail;
		}
		return ans;
	}
	Node<int> *constructLinkedList(BinaryTreeNode<int> * root)
	{
		// Write your code here
		return LL(root).head;
	}
	// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
	int main()
	{
		BinaryTreeNode<int> *root = takeInputLevelWise();
		cout << isBST(root) << endl;
		delete root;
	}
