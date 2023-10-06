#include <iostream>
#include <thread>
#include <mutex>

#include <vector>
#include <algorithm>
#include <unordered_map>
#include <functional>
#include <chrono>

#include "Loader.h"
#include "ThreadPool.h"
#include "LinkedList.h"
#include "BinaryTree.h"
#include "Model.h"


void listTest()
{
	LikedList* list = new LikedList();
	list->insert(0);
	list->insert(1);
	list->insert(2);
	list->insert(3);

	list->insertEnd(-1);

	list->show_TailAndHead();

	list->deleteNode(2);

	list->printRecursive();
	list->print();
	std::cout << std::endl;
}


std::vector<int> vec;
int i = 0;
std::mutex m;
void edit_vec()
{
	m.lock();
	vec[i] = vec[i] + vec[i];
	m.unlock();
}
void my_vec_fun()
{
	for (int i = 0; i < 20; i++)
	{
		vec.push_back(i);
	}

	while (i < 20)
	{
		threads.addJob(edit_vec);
		i++;
	}
	std::cout << std::endl;
	for (int i = 0; i < 20; i++)
	{
		std::cout << vec[i] << std::endl;
	}
}

void binaryTest()
{
	BinaryTree* tree = new BinaryTree();
	tree->insert(1);
	tree->insert(0);
	tree->insert(2);
	tree->insert(3);

	tree->Print();
	std::cout << std::endl;
	tree->run();
}

using namespace std;

int removeDuplicates(vector<int>& nums)
{
	int counter = 0;
	vector<int> numbers;
	for (int i = 0; i < nums.size(); i++)
	{
		if (counter == 0 || counter == 1)
		{
			numbers.push_back(nums[i]);
			if (i == nums.size() - 1)
				break;
		}
		if (nums[i] == nums[i + 1])
		{
			counter++;
		}
		else if (nums[i] != nums[i + 1])
		{
			counter = 0;
		}

	}

	nums = numbers;

	return numbers.size();
}

void Log(string s)
{
	std::cout << s << std::endl;
}

void change_nnn(int& a)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	a = 200;
}



int main()
{
	Loader tex_load;
	tex_load.loadThread();
	tex_load.joinThread();

	threads.addJob(listTest);
	threads.addJob(binaryTest);

	vector<int> nums;
	int b[9] = { 0,0,1,1,1,1,2,3,3 };
	for (int i = 0; i < 9; i++)
	{
		nums.push_back(b[i]);
	}

	removeDuplicates(nums);

	int a[6] = { 6,2,4,5,3,1 };
	int n = 6;
	for (unsigned int i = 0; i < n; i++)
	{
		for (unsigned int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
			{
				int aux = a[i];
				a[i] = a[j];
				a[j] = aux;
			}
		}
	}

	Model* a1 = new Model();
	Model* a2 = new Model();
	Model* a3 = new Model();
	Model* a4 = new Model();
	Model* a5 = new Model();
	Model* a6 = new Model();

	threads.addJob(std::bind(Log, "aaaa"));

	threads.joinThreads();

	a1->output_v();
	a2->output_v();
	a3->output_v();
	a4->output_v();
	a5->output_v();
	a6->output_v();

	int aaa = 0;
	threads.addJob(std::bind(change_nnn, std::ref(aaa)));

	threads.joinThreads();
	
	a1->show();

	threads.stop();
	return 0;
}