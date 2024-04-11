#include <iostream>
#include <thread>
#include <mutex>

#include <vector>
#include <algorithm>
#include <unordered_map>
#include <functional>
#include <chrono>
#include <vector>
#include "Loader.h"
#include "ThreadPool.h"
#include "LinkedList.h"
#include "BinaryTree.h"
#include "Model.h"

#define MAX_BETIVI 8
/////
int timp = 10;

std::string betivii[MAX_BETIVI];

class Fridge
{
private:
	std::vector<std::string> saracia_SALCIILOR;
public:
	void add(std::string alimente_bazatBere)
	{
		saracia_SALCIILOR.push_back(alimente_bazatBere);
	}

	void consuma(std::string aliment_Bere)
	{
		for (int bereaDinFrigider = 0; bereaDinFrigider < saracia_SALCIILOR.size(); bereaDinFrigider++)
		{
			if (saracia_SALCIILOR[bereaDinFrigider] == aliment_Bere)
			{
				saracia_SALCIILOR[bereaDinFrigider] = "E GOAlA COAIE MINUS O IESIRE CU BAIETII";
			}
		}
	}
};

class BeerPZDMS_City_Fridge
{
private:
	std::string locatia_PLii = "LA CURTE BA";
public:
	void alegeINPLM_undeBEI(std::string acas_afar)
	{
		if (acas_afar == locatia_PLii)
			std::cout << "Bv ba pula azi se iese";
		else
			std::cout << "Vai de pl noastra iesim maine";

		if (timp > 18 && timp < 24)
			std::cout << std::endl << "Bun ca mergem";
		else
			std::cout << "Nu i ora korekta de berue";
	}

	std::string vedem_cine_iese(int i)
	{
		if (betivii[i] == "Nosferat")
		{
			std::cout << "S-a spalat pe cap in plm si pleaca in centru, jet acas";
			return;
		}

		if (i > MAX_BETIVI)
		{
			std::cout << "prea multi boscai";
			return;
		}
		else
			return vedem_cine_iese(++i);
	}
};

/* cine modifica aici fara sa ma intrebe masa practica o meserie care nu este din domeniul IT :p */
class Zoaie{

	/* daca nu iei bere*/
	void ia_bere
	{
		fwprintf("ia bere");
	}
	/* andrei variabila invariabla */
	if (char andrei == bou)
	{
		int cnt = 0;
		for (bere = null; bere < int size_of_frifider; bere--)
		{
			cnt++;
			/* dan = variabila primara , vatzi prins ca e primar gen pe nicolinna lidl*/
			andrei = dan + bere;

			if (cnt == 16)
			{
				return HEX(float nr_beri = andrei + bere * 4.56);
				bere->insert(frigider[cnt]);
			}
			else
			{
				bere = 0;
				ia_bere();
			}
		}
	}
};//kkkkkkkkkkkk PLM COIE clasa z mortii lui mai
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

void print_yes()
{
	std::cout << "YEEEEAHHH" << std::endl;
}

void print_something(int a)
{
	std::cout << a << " -> Functie scoasa din thread !!!" << std::endl;
}

void change_number(int& a)
{
	a = 200;
}

int main()
{
	int the_number = 0;
	//Dupa cum poti observa noi avem doar functii "void()":
	threads.addJob(print_yes);											//AICI E NORMAL
	threads.addJob(std::bind(print_something, 2));						//te folosesti de "std::bind()" "https://stackoverflow.com/questions/6610046/stdfunction-and-stdbind-what-are-they-and-when-should-they-be-used"
																		//cand folosesti ceva diferit de o functie "void" goala (ex:" "void do_some()" vs "void do_some(int a, int b)" ")
	threads.addJob(std::bind(change_number, std::ref(the_number)));		//aici este schema cu referinta, folosesti foarte usor -> "std::ref" de unde "ref" == "referinta" :))
	


	//Ca sa fie mai usor incerci sa folosesti doar functii "void()" pentru a nu te incurca la functiile cu tip de returnare. Daca vrei sa folosesti asa ceva te poti documenta pe net
	//pentru functiile "std::future" si variabile "auto" si poate despre "for_each" cu "std::execution::par" daca esti curios: "https://en.cppreference.com/w/cpp/algorithm/execution_policy_tag_t"



	threads.joinThreads();//Ai dat "join" la thread-uri si gata

	std::cout << std::endl;
	std::cout << the_number << std::endl; //Sa nu uitam de numarul schimbat prin referinta la linia 70 ;) asta dupa ce dai "join()" abia atunci poti sa vezi daca totul este in regula.

	threads.stop();//Inchizi totul si "return 0;"
	//Daca o sa iti apara afisarile in consola pe aceeasi linie e normal :)) deoarece sunt 2 thread-uri care afiseaza in acelasi timp xDD

	return 0;
}

//In caz de eroare nu te speria, se poate sa primesti o eroare de "out of range" deoarece ai "threads.joinThreads();" si "threads.stop();" la o diferenta de nanosecunde intre executari

//Acest threadpool este cat se poate de dinamic si usor in acelasi timp astfel incat tu sa partajezi tot ce ai nevoie intre functii si variabile

//LINKS:
/*
"https://www.youtube.com/watch?v=TPVH_coGAQs&list=PLk6CEY9XxSIAeK-EAh3hB4fgNvYkYmghp"
"https://www.youtube.com/watch?v=xPqnoB2hjjA"
"https://www.youtube.com/watch?v=_n2hE2gyPxU" -> in caz de vrei sa faci in "C" si nu in "C++"
https://www.geeksforgeeks.org/multithreading-in-cpp/

https://en.cppreference.com/w/cpp/thread/thread
https://en.cppreference.com/w/cpp/utility/functional/function
https://en.cppreference.com/w/cpp/thread/mutex
*/