#include <string>
#include <iostream>
#include "..\part1\LibraryStatHeader.h"
#include <thread>
using std::cout;

void makeMessageToJornal();

int main(int argc, char* argv[])
{


	if (argc ==1) {//если программа запущена без дополнительных параметров
		makeNewEnterense();
	}else {
		if (argc == 3 && (*argv[2] == 'A' || *argv[2] == 'B' || *argv[2] == 'C')) {//если данные переданны коректно
			makeFName(argv[1]);
			makeILevel(*argv[2]);

		}
		else {//если данные не корректны
			std::cout << "Somethin is not correct" << std::endl;
			makeNewEnterense();
		}



	}
	
	
	


	
	
	bool need = true;
	
	
	while (need) {
		std::cout << "Chose: " << std::endl << "1 -  make new write" << std::endl << "2 -  change level" << std::endl << "3 -  Exit"<<std::endl;//выбор действия
		std::string ch = "";
		std::getline(std::cin, ch);

		switch (ch[0])
		{
		case '1': 

			makeMessageToJornal();
			break; 
		case '2':
			changeDefaultLevel();
			break;
		case '3':
			break;
		default:
			std::cout << "Incorrect chose"<<std::endl;
			break;
		}


		

	}




	
}

void makeMessageToJornal() {
	std::string text;
	char curentILevevl;
	std::cout << "Mesage level: ";
	std::cin >> curentILevevl;
	std::cout << "Mesage text: ";
	std::getline(std::cin, text);
	std::getline(std::cin, text);
	//создание нового потока (в данном случае не имеет большого смысла, так как нет затратных по времени участков кода)
	std::thread th(writeSomeInformation, text, curentILevevl);
	th.join();

}



