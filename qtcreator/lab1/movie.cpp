#include "movie.h"
#include "./ui_movie.h"

//реализация конструктора
Movie::Movie(std::string t, std::string s, std::string d, int y) {
    title = t;
    screenwriter = s;
    director = d;
    year = y;
}

//реализация геттеров
std::string Movie::getTitle() const { return title; }
std::string Movie::getScreenwriter() const { return screenwriter; }
std::string Movie::getDirector() const { return director; }
int Movie::getYear() const { return year; }

//реализация сеттеров
void Movie::setTitle(const std::string& t) { title = t; }
void Movie::setScreenwriter(const std::string& s) { screenwriter = s; }
void Movie::setDirector(const std::string& d) { director = d; }
// void Movie::setYear(const int& y) { year = y; }
void Movie::setYear(const int& y) {
    if (y > 0) { //пример пользы инкапсуляции: мы не даем ввести отрицательный год
        year = y;
    }
}


