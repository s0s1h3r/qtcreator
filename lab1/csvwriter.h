#ifndef CSVWRITER_H
#define CSVWRITER_H

#include <string>
#include <vector>
#include "movie.h"

class CsvWriter
{
private:
    std::string filename;
public:
    CsvWriter(const std::string& file); //конструктор
    bool writeData(const std::vector<Movie>& library_of_movies); //возвращаем тру, если сохранение прошло без ошибок
};

#endif // CSVWRITER_H
