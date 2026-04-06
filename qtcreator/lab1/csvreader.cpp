#include "csvreader.h"
#include <fstream>
#include <sstream>

//реализация конструктора
CsvReader::CsvReader(const std::string& file) {
    filename = file;
}

//реализация метода чтения
std::vector<Movie> CsvReader::readData() {
    std::vector<Movie> library; //создаем пустую библиотеку(вектор)
    std::ifstream file(filename); //открываем файл средствами чистого c++

    //проверяяем удалось ли открыть файл
    if (!file.is_open()) {

        // ui->textEdit->setText("ты ошибсяя, беда, переделая всё");
        return library; //завершаем программу с кодом ошибки (1)
    }

    std::string line; //сюда будем считывать строку целиком

    //читаем файл построчно, пока не закончится
    while (std::getline(file, line)) {
        //создаем строковый поток из прочитанной строки, это нужно, чтобы резать её
        std::stringstream ss(line);

        std::string title;
        std::string screenwriter;
        std::string director;
        std::string yearStr;


        //режим строку по разделителю
        if (std::getline(ss, title, ';') &&
            std::getline(ss, screenwriter, ';') &&
            std::getline(ss, director, ';') &&
            std::getline(ss, yearStr, ';'))
        {
            int year = std::stoi(yearStr);

            Movie newMovie(title, screenwriter, director, year); //создаем фильм
            library.push_back(newMovie); //кладем фильм в библиотеку
        }
    }

    file.close(); //закрываем файл
    return library;
}

