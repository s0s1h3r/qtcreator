#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "movie.h"
#include <vector>
#include <algorithm>
#include <fstream> // для str::ifstream (чтение файлов)
#include <sstream> // для std::stringstream (разбиение строк)
#include <string> //для std::string
#include <QString>

//функция, которая объясняет, как сортировать фильмы
bool compareByYear (const Movie& a, const Movie& b) {
    return a.getYear() < b.getYear(); //сначала старые, потом новые
}

//конструктор
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this); //Qt отрисовывает окошко

    std::vector<Movie> library; //создаем пустую библиотеку(вектор)
    std::ifstream file("movie.csv"); //открываем файл средствами чистого c++

    //проверяяем удалось ли открыть файл
    if (!file.is_open()) {

        ui->textEdit->setText("ты ошибсяя, беда, переделая всё");
        return; //завершаем программу с кодом ошибки (1)
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

    //СОРТИРОВКА
    std::sort(library.begin(), library.end(), compareByYear);

    //выводим результат на экран
    ui->textEdit->append("--- отсортированные фильмы ---");
    for (const Movie& movie : library) {
        QString outputLine = QString("Название: %1 | Сценарист: %2  | Режиссер: %3 | Год: %4")
                                 .arg(QString::fromStdString(movie.getTitle()))
                                 .arg(QString::fromStdString(movie.getScreenwriter()))
                                 .arg(QString::fromStdString(movie.getDirector()))
                                 .arg(movie.getYear());
        ui->textEdit->append(outputLine);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

