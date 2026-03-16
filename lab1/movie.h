#ifndef MOVIE_H //защита от двойного включения(чтобы меню не распечаталось дважды)
#define MOVIE_H

#include <QMainWindow>
#include <string> //подключаем стандартные строки с++

class Movie{
private:
    //инкапсуляция в действие: эти данные скрыты от внешнего мира(никто не сможет случайно изменить год на -500)
    std::string title;
    std::string screenwriter;
    std::string director;
    int year;
public:
    //конструктор - это функция, которая вызывается при рождение объекта
    Movie(std::string t = "", std::string s = "", std::string d = "", int y = 0);

    //геттеры - публичные кнопки, чтобы только ЧИТАТЬ  данные
    std::string getTitle() const;
    std::string getScreenwriter() const;
    std::string getDirector() const;
    int getYear() const;

    //сеттеры -  публичные кнопки, чтобы  ИЗМЕНЯТЬ данные безопасно
    void setTitle(const std::string& t);
    void setScreenwriter(const std::string& s);
    void setDirector(const std::string& d);
    void setYear(const int& y);
};

#endif // MOVIE_H



