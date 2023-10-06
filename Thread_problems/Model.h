#pragma once

#include <functional>
#include <iostream>
#include "ThreadPool.h"
#include "LinkedList.h"

class Model: public LikedList
{
public:

	std::vector<int> numbers;
	bool done = false;

	Model()
	{
		auto f = std::bind(&Model::input_number, this);
		threads.addJob(f);
	}

	void output_v()
	{
		while (done == false)
			continue;
		for (int i = 0; i < numbers.size(); i++)
			std::cout << numbers[i] << std::endl;
	}

	void input_number()
	{
		for (int i = 0; i < 10; i++)
		{
			numbers.push_back(i);
		}
		done = true;
	}

};