#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "movie.h"
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_lineEdit_search_textChanged(const QString &arg1); //слот для поиска
private:
    Ui::MainWindow *ui;

    void displayMovies(const std::vector<Movie>& moviesToDisplay); //функция для вывода на экран
};
#endif // MAINWINDOW_H
