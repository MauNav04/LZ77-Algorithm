#ifndef LZ77_TOOL_MAINSCREEN_H
#define LZ77_TOOL_MAINSCREEN_H

#include <QMainWindow>
#include <cstdlib>
#include <iostream>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainScreen; }
QT_END_NAMESPACE

class MainScreen : public QMainWindow {
Q_OBJECT

public:
    MainScreen(QWidget *parent = nullptr);

    ~MainScreen();

    void compress();

    void inputChars();

    void inputSearchBuffer();

    bool checkMatch();

    void setNext();

    void solution();

    void createMatrix();

    void showMatrix();

    void decompress();

private slots:

    void on_compressButton_clicked();

    void on_decompressButton_clicked();

private:
    Ui::MainScreen *ui;
    int const window = 13;
    int const dataBuffer = 6;
    int const searchBuffer = window - dataBuffer;
    int offset;
    int match;
    int current = 0;
    int fila = 0;
    string nextChar;
    string word;
    string codedWord;
    string decodedWord;
    string **compresMat = new string *[word.length()];
    string dBArr[6];
    string sBArr[7];
};

#endif // LZ77_TOOL_MAINSCREEN_H