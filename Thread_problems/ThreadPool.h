#pragma once
#include <vector>
#include <thread>
#include <mutex>
#include <queue>
#include <functional>


class Thread_Pool
{
/// <summary>
/// Partea privata a functiilor pentru a nu avea acces "user"-ul
/// 	Totul este ascuns pentru a putea fi usor la "debugging"
/// </summary>
private:
	std::mutex m;								//Mutex pentru asteptarea rezultatelor la "void wait()"
	std::vector<std::thread> threads;			//Vector sau Array de "Thread".
	std::queue<std::function<void()>> jobs;		//Structura de data de tip "Queue" unde se aloca dinamic fiecare functie folosind libraria "functional"
	std::mutex queue_mutex;						//Mutex pentru a nu se crea "race condition" intre thread-uri --mutex meaning:"https://youtu.be/eZ8yKZo-PGw?t=5"

	void loadThreads()							//Generare thread-uri
	{
		for (int i = 0; i < std::thread::hardware_concurrency(); i++)
		{
			threads.emplace_back(std::thread(&Thread_Pool::ThreadLoop, this));
		}
	}

	void ThreadLoop()//Functia care se ruleaza pe thread incontinuu asteptand sa fie un element in "Queue" pentru a putea fi executata
	{
		while (true)
		{
			if (jobs.empty())					//Termina functia daca nu sunt functii in "Queue"
				return;
			queue_mutex.lock();					//Blocheaza accesarea celorlalte thread-uri in functie de primul thread care a accesat aceasta linie de cod/functie
			std::function<void()> job;				// ->Se aloca separat "O treaba" sau job (aceasta fiind functia/pointer-ul functiei)
			job = jobs.front();						// ->Se preia prima functie din stiva
			jobs.pop();								// ->Se dealoca din structura "Queue" functia respectiva
			queue_mutex.unlock();					// ->Deblocarea "Queue"-ului pentru celelalte thread-uri
			
			job();								////Si aici se executa functia normala ca si cum ar fi "void do_something()" de catre thread-ul respectiv
		}
	}

	void joinEach()//Functie de a returna executia thread-ului  --LINK: "https://stackoverflow.com/questions/15148057/what-does-stdthread-join-do" 
	{	
		for (std::thread& active_thread : threads) 
		{
			active_thread.join();											//Se da join
			active_thread = std::thread(&Thread_Pool::ThreadLoop, this);	//Dupa ".join()" se reataseaza functia "ThreadLoop()" de mai sus pentru a cauta alte functii
		}
	}

public:

	Thread_Pool() { loadThreads(); }					//Generare thread-uri
	
	void addJob(const std::function<void()>& job)		//Adaugare functii in "Queue"
	{
		queue_mutex.lock();								
		jobs.push(job);				//Adaugare in "Queue" a functiilor
		queue_mutex.unlock();
	}
	
	void joinThreads()				//Metoda publica de ".join()" pt. fiecare thread (vezi linia 44)
	{
		joinEach();
	}

	bool busy()						//Vedem daca nu avem functii si dam return la un "bool" pentru da sau nu
	{
		queue_mutex.lock();
		bool poolbusy = true;
		if (jobs.empty())
			poolbusy = false;
		queue_mutex.unlock();
		return poolbusy;
	}

	void wait()						//Functia pentru asteptarea rezultatelor din tot "Queue"-ul pentru a putea continua in caz ca avem nevoie de niste variabile prelucrate in paralel
	{
		m.lock();
		while (true)
		{
			if (busy())
				joinThreads();
			else break;
		}
		m.unlock();
	}

	void stop()						//In urma inchiderii programului sau de a termina fiecare thread, aceasta functie inchide si dealoca thread-urile create
	{
		for (std::thread& active_thread : threads) {
			active_thread.join();
		}
		threads.clear();
	}								//Daca nu inchizi o sa primesti eroare :))
};

Thread_Pool threads;				//Obiect global pentru accesarea thread-urilor si alocarea functiilor pentru executare.


//Thread_problems.cpp este "main file" pentru ce am scris
//Daca vrei sa faci o functie dupa care sa fie executata in paralel si in acelasi timp functia sa poata fi alocata in "std::queue" te uiti la exemple in Thread_problems.cpp
