#pragma once
#include <vector>
#include <thread>
#include <mutex>
#include <queue>


class Thread_Pool
{
private:
	std::vector<std::thread> threads;
	std::queue<std::function<void()>> jobs;
	std::mutex queue_mutex;

	void loadThreads()
	{
		for (int i = 0; i < std::thread::hardware_concurrency(); i++)
		{
			threads.emplace_back(std::thread(&Thread_Pool::ThreadLoop, this));
		}
	}

	void print_num(int i)
	{
		std::cout << i << '\n';
	}

	void ThreadLoop()
	{
		while (true)
		{
			if (jobs.empty())
				return;
			queue_mutex.lock();
			std::function<void()> job;			
			job = jobs.front();
			jobs.pop();
			queue_mutex.unlock();
			job();
		}
	}

	void joinNormal()
	{
		for (int i = 0; threads.size(); i++)
		{
			if(threads[i].joinable())
				threads[i].join();
				//threads[i] = std::thread(&Thread_Pool::ThreadLoop, this);			
		}
		threads.clear();
	}

	void joinEach()
	{	
		for (std::thread& active_thread : threads) {
			active_thread.join();
			active_thread = std::thread(&Thread_Pool::ThreadLoop, this);
		}
	}

public:

	Thread_Pool() { loadThreads(); }
	void addJob(const std::function<void()>& job)
	{
		queue_mutex.lock();
		jobs.push(job);
		queue_mutex.unlock();
	}
	
	void joinThreads()
	{
		joinEach();
	}

	void stop()
	{
		for (std::thread& active_thread : threads) {
			active_thread.join();
		}
		threads.clear();
	}
};

Thread_Pool threads;