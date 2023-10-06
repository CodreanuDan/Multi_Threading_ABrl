#pragma once
#include <vector>
#include <functional>
#include <iostream>

class LikedList
{
public:
	struct Node
	{
		int val = NULL;
		Node* next = nullptr;
	};
	Node* head = nullptr;
	Node* tail = nullptr;
	unsigned int size = 0;

	std::vector<Node*> nodeVector;

	void insert(int number)
	{
		if (head == nullptr)
		{
			head = new Node();
			head->val = number;
			size++;
		}
		else
		{
			Node* newNode = new Node();
			newNode->val = number;
			newNode->next = head;
			head = newNode;
			size++;
		}
	}

	void insertEnd(int number)
	{
		if (head == nullptr)
		{
			head = new Node();
			head->val = number;
			size++;
		}

		else
		{
			Node* last = head;
			Node* newNode = new Node();
			newNode->val = number;
			newNode->next = nullptr;
			while (last->next != nullptr)
			{
				last = last->next;
			}
			last->next = newNode;
			last = last->next;
			tail = last;
			size++;

		}
	}

	void print()
	{
		Node* trav = head;
		while (trav != nullptr)
		{
			std::cout << trav->val << std::endl;
			trav = trav->next;
		}
	}

	void printRecursive(Node* node)
	{
		Node* schema = node;
		if (schema == nullptr)
			return;
		std::cout << schema->val << std::endl;
		printRecursive(schema->next);
	}

	void printRecursive()
	{
		printRecursive(head);
	}

	void deleteNode(int iterator)
	{
		if (head == nullptr)
			return;
		Node* last = head;
		int i = 0;
		while (i <= iterator)
		{
			if (i == iterator - 1)
			{
				break;
			}
			last = last->next;
			i++;
		}

		Node* now = last;
		Node* future = last->next->next;
		delete last->next;
		now->next = future;
		size--;
	}

	int getSize()
	{
		return size;
	}

	void show_TailAndHead()
	{
		if (head != nullptr && tail != nullptr)
		{
			std::cout << head->val << " and " << tail->val << std::endl;
		}
	}

	void show()
	{
		std::cout << "Merge !!" << std::endl;
	}

};