#ifndef CSVREADER_H
#define CSVREADER_H

#include <vector>
#include <string>
#include "movie.h"

class CsvReader
{
private:
    std::string filename; //храним имя файла, который будем читать
public:
    CsvReader(const std::string& file); //конструктор: при создание CsvReader  мы говорим ему какой файл читать

    std::vector<Movie> readData(); //главный метод, который читает файл и возвращает массив фильмов
};

#endif // CSVREADER_H
