#ifndef LZ77_TOOL_MAINSCREEN_H
#define LZ77_TOOL_MAINSCREEN_H

#include <QMainWindow>
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainScreen; }
QT_END_NAMESPACE

class MainScreen : public QMainWindow {
Q_OBJECT

public:
    MainScreen(QWidget *parent = nullptr);

    ~MainScreen();

private slots:

    void on_compressButton_clicked();

    void on_decompressButton_clicked();

private:
    Ui::MainScreen *ui;
};

#endif // LZ77_TOOL_MAINSCREEN_H