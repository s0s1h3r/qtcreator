#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "movie.h"
#include <vector>
#include <algorithm>
#include <fstream> // для str::ifstream (чтение файлов)
#include <sstream> // для std::stringstream (разбиение строк)
#include <string> //для std::string
#include <QString>
#include "csvreader.h"
#include "csvwriter.h"

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

    CsvReader reader("movie.csv"); //просим csvreader прочесть файл
    std::vector<Movie> library = reader.readData();
    if (library.empty()) {
        ui->textEdit->setText("ты ошибсяя, беда, переделая всё");
        return;
    } else{
        //СОРТИРОВКА
        std::sort(library.begin(), library.end(), compareByYear);
        displayMovies(library);
    }

    //добавление

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayMovies(const std::vector<Movie>& moviesToDisplay) {
    //выводим фильм на экран
    ui->textEdit->clear();
    ui->textEdit->append("--- список ---");

    for (const Movie& movie : moviesToDisplay) {
        QString outputLine = QString("Название: %1 | Сценарист: %2  | Режиссер: %3 | Год: %4")
                                 .arg(QString::fromStdString(movie.getTitle()))
                                 .arg(QString::fromStdString(movie.getScreenwriter()))
                                 .arg(QString::fromStdString(movie.getDirector()))
                                 .arg(movie.getYear());
        ui->textEdit->append(outputLine);
    }
}

//живой поиск
void MainWindow::on_lineEdit_search_textChanged(const QString &arg1) {

    std::string query = arg1.toStdString();

    CsvReader reader("movie.csv"); //так как нет кэша открываем еще раз
    std::vector<Movie> currentLibrary = reader.readData();

    std::sort(currentLibrary.begin(), currentLibrary.end(), compareByYear);
    if (query.empty()) {
        displayMovies(currentLibrary);
        return;
    }

    //ищем совпадения
    std::vector<Movie> searchResults;

    for (const Movie& movie : currentLibrary) {
        if (movie.getTitle().find(query) != std::string::npos) {
            searchResults.push_back(movie);
        }
    }

    //выводим результат
    if (searchResults.empty()) {
        ui->textEdit->setText("ищи сам, я не справляюсь");
    } else {
        displayMovies(searchResults);
    }
}



void MainWindow::on_button_search_clicked()
{
    CsvReader reader("movie.csv");
    std::vector<Movie> currentLibrary = reader.readData();

    //создаем новый фильм
    Movie testMovie("matrica", "ne znay", "ne znay2", 1999);
    currentLibrary.push_back(testMovie);//добавляем его
    std::sort(currentLibrary.begin(), currentLibrary.end(), compareByYear);//сортировка

    //вызываем писателя и сохраняем наш новый фильм
    CsvWriter writer("movie.csv");
    if (writer.writeData(currentLibrary)) {
        ui->textEdit->append("film dobavlen");
        displayMovies(currentLibrary);
    } else {
        ui->textEdit->append("film ne dobavlen:( :( :(");
    }
}
