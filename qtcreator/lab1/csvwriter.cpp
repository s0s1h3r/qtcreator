#include "csvwriter.h"
#include <fstream>

CsvWriter::CsvWriter(const std::string& file) {
    filename = file;
}

bool CsvWriter::writeData(const std::vector<Movie>& library_of_movies) {
    std::ofstream file(filename); //полностью перезапишет файл

    if(!file.is_open()) {
        return false;
    }

    //пробегаемся по всем фильмам и пишем их в файл
    for(const Movie& film : library_of_movies) {
        file << film.getTitle() << ";"
             << film.getScreenwriter() << ";"
             << film.getDirector() << ";"
             << film.getYear() << "\n";
    }

    file.close();
    return true;
}
