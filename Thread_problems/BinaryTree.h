#pragma once
#include <iostream>
#include <vector>

class BinaryTree
{
public:
	struct Node
	{
		int val = NULL;
		Node* right = nullptr;
		Node* left = nullptr;
	};

	Node* root = nullptr;

	Node* insertNode(Node* node, int item)
	{
		if (node == nullptr)
		{
			node = new Node();
			node->val = item;
			return node;
		}
		else
		{
			if (item < node->val)
				node->left = insertNode(node->left, item);
			else
				node->right = insertNode(node->right, item);
		}

		return node;
	}

	void insert(int item)
	{
		if (root == nullptr)
		{
			root = new Node();
		}
		else
			insertNode(this->root, item);

	}

	void print(Node* node)
	{
		if (node != nullptr)
		{
			print(node->left);
			std::cout << node->val << std::endl;
			print(node->right);
		}
	}

	void Print()
	{
		print(root);
	}

	int run();
};

class A
{
public:
	void f1()
	{
		std::cout << "A1" << std::endl;
	}
	virtual void f2()
	{
		std::cout << "A2" << std::endl;
	}
	virtual void f3(int) = 0;
	virtual void f3() = 0;
};

class B : public A
{
public:
	void f1()
	{
		std::cout << "B1" << std::endl;
	}
	void f2()
	{
		std::cout << "B2" << std::endl;
	}
	virtual void f3(int a)
	{
		std::cout << "F3 parameter" << std::endl;
	}
	virtual void f3()
	{
		std::cout << "F3 normal" << std::endl;
	}
};

class C : public B
{
	void f1()
	{
		std::cout << "C1" << std::endl;
	}
	void f2()
	{
		std::cout << "C2" << std::endl;
	}
	virtual void f3(int a)
	{
		std::cout << "C_F3 parameter" << std::endl;
	}
	virtual void f3()
	{
		std::cout << "C_F3 normal" << std::endl;
	}
};

void g(A* x)
{
	x->f1();
	x->f2();
	x->f3();
}


int BinaryTree::run()
{
	//A* clasa_A_ob_a = new A();
	A* clasa_A_ob_b = new C();
	//g(clasa_A_ob_a);
	g(clasa_A_ob_b);

	//delete clasa_A_ob_a;
	delete clasa_A_ob_b;

	return 0;
}
