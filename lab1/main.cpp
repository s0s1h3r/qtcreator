#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv); //запускает движок Qt
    MainWindow w; //создает твое главное окно
    w.show(); //показывает его на экране
    return a.exec(); //запускает бесконечный цикл ожидания кликов
}
