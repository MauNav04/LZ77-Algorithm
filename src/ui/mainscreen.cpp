//#include "src/algorithm/algorithm.h"
#include "mainscreen.h"
#include "./ui_mainscreen.h"

//Algorithm algorithm;

MainScreen::MainScreen(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainScreen) {
    ui->setupUi(this);
}

MainScreen::~MainScreen() {
    delete ui;
}

void MainScreen::on_compressButton_clicked() {
    std::cout << "\n\n----------------- Compressing -------------------" << std::endl;

    QString userText = ui->userText->toPlainText();
//    algorithm.Compressed(userText.toStdString());

//    QString userTextCompressed = QString::fromStdString(algorithm.getEncodedString());
//    ui->compressResult->setPlainText(userTextCompressed);
    ui->decompressResult->setPlainText("");
}

void MainScreen::on_decompressButton_clicked() {
    std::cout << "\n\n----------------- Decompressing -----------------" << std::endl;

    QString userText = ui->userText->toPlainText();
//    algorithm.Decompressed(userText.toStdString());

//    QString userTextDecompressed = QString::fromStdString(algorithm.getDecodedString());
    ui->compressResult->setPlainText("");
//    ui->decompressResult->setPlainText(userTextDecompressed);
}