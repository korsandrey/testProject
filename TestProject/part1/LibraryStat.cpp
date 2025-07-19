#include <string>
#include <iostream>
#include <fstream>
#include <ctime>

void LevelChecking();
std::string showTime();
std::string fileName;
char ILevel;

//ручное заполнение названия файла и уровня сообщений по умолчанию 
void makeNewEnterense() {
	std::cout << "File name: ";
	std::cin >> fileName;
	std::cout << "Default level('A','B','C'): ";
	LevelChecking();
}
//имя файла
void makeFName(std::string _fileName) {
	fileName = _fileName;
}
//уровня сообщений по умолчанию 
void makeILevel(char _ILevel) {
	ILevel = _ILevel;
}

//запись в журнал
void writeSomeInformation(std::string text, char curentILevevl= ILevel) {
	if (curentILevevl == 'A' || curentILevevl == 'B' || curentILevevl == 'C') {//проверка на правильность уровня
		
	}
	else {
		std::cout<<  "Mesage level is not correct and changed to default "<<std::endl;
		curentILevevl = ILevel;
	}

	if (curentILevevl >= ILevel) {//проверка на соответствие уровню заданной минимальной приемлемой планки
		std::string path ="..\\"+fileName + ".txt";
		

		
		std::ofstream fout;
		fout.open(path, std::ofstream::app);

		if (!fout.is_open()) {
			//журнал не открыт
			std::cout << "[-]File is not oppen"<<std::endl;
		}
		else {
			time_t now = time(NULL);
			fout << showTime() << " / " << curentILevevl << " / " << text<< '\n';//формат записи
			fout.close();
		}
	}

}

//изменение уровня сообщений по умолчанию 
void changeDefaultLevel() {
	std::cout << "Set new default level('A','B','C'):";
	LevelChecking();
}

//попытка избежать ошибок при вводе уровня сообщений
void LevelChecking() {
	bool lvl = false;
	while (!lvl) {
		
		std::string input;
		std::cin >> input;

		if (input.size() == 1 && (input[0] == 'A' || input[0] == 'B' || input[0] == 'C')) {
			ILevel = input[0];
			std::cout << "New default level set succesfuly!" << std::endl;
			lvl = true;

		}
		else {
			std::cout << "Somethin is not correct, please try again" << std::endl;
			std::cout << "Default level('A','B','C'): ";
		}
	}

}



//получение информации о времени
std::string showTime() {
	std::string output;
	time_t now = time(NULL);

	tm now_tm = {};
	char str[26] = {};
	localtime_s(&now_tm, &now);
	asctime_s(str, 26, &now_tm);
	
	for (int i = 4; i < 24; i++) {
		output+= str[i];
	}
	return output;
}
