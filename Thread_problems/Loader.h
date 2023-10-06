#pragma once
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "ThreadPool.h"
#include <functional>
#include <iostream>
#include <thread>
class Loader
{
public:
	unsigned char* data;
	const char* input = "metal.jpg";
	
	std::vector<int> vertex;
	std::vector<unsigned int> indici;

	void loadThread()
	{
		threads.addJob([this]() { this->loadImage(); });
		threads.addJob([this]() { this->loadVectors(); });
	}

	void joinThread()
	{
		threads.joinThreads();
		std::cout << vertex.size() << " and " << indici.size() << std::endl;
	}

	void loadImage()
	{
		int width, height, nrComponents;
		data = stbi_load(input, &width, &height, &nrComponents, 0);
		//data = stbi_load("metal.jpg", &width, &height, &nrComponents, 0);
		sometest();
		std::cout << "Done !" << std::endl;
	}

	void sometest()
	{
		std::cout << "weve been here" << std::endl;
	}

	void loadVectors()
	{
		loadVectorsAgain();
	}

	void loadVectorsAgain()
	{
		for (unsigned int i = 0; i < 100; i++)
		{
			vertex.push_back(i);
		}

		for (unsigned int i = 0; i < 100; i++)
		{
			indici.push_back(i);
		}
	}
};