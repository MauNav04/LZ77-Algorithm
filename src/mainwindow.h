#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

#include <iostream>
#include <stdlib.h>
using namespace std;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void compress();
    void inputChars();
    void inputSearchBuffer();
    bool checkMatch();
    void setNext();
    void solution();
    void createMatrix();
    void showMatrix();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    // atributos
    int const window = 13;
    int const dataBuffer = 6;
    int const searchBuffer = window - dataBuffer;
    int offset;
    int match;
    int current = 0;
    int fila=0;
    string nextChar;
    string word = "";
    string texto;
    string **compresMat = new string *[word.length()];

    string dBArr[6];
    string sBArr[7];
};
#endif // MAINWINDOW_H
