#include "mainscreen.h"
#include "./ui_mainscreen.h"

MainScreen::MainScreen(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainScreen) {
    ui->setupUi(this);
}

MainScreen::~MainScreen() {
    delete ui;
}

// Función que ejecuta el algoritmo
void MainScreen::compress() {
    // Se crea una matriz de dimensiones (tamaño del texto X 3)
    createMatrix();
    current = 0;
    fila = 0;
    // Ejecución del algoritmo (Se repite hasta que se acabe el texto introducido)
    while (current <= word.length()) {
        inputChars();
        inputSearchBuffer();
        checkMatch();
        setNext();
        solution();
        current = current + match + 1;
        *(*(compresMat + fila) + 0) = to_string(offset);
        *(*(compresMat + fila) + 1) = to_string(match);
        *(*(compresMat + fila) + 2) = nextChar;
        fila++;
    }
    // Método para imprimir el contenido de la matriz en la consola
    // se muestra como códigos con formato (offset, match, letter)
    showMatrix();
}

// Coloca los caracteres de la palabra en el dataBuffer dependiendo del caracter que se está leyendo
void MainScreen::inputChars() {
    for (int i = 0; i < dataBuffer; i++) {
        if (current + i < word.length()) {
            dBArr[i] = word.at(current + i);

            cout << dBArr[i] << " ";
        } else {
            break;
        }
    }
    cout << endl;
}

//Coloca los valores correspondientes en el buffer de busqueda
void MainScreen::inputSearchBuffer() {
    if (current > 0) {
        int arrCoutn = 0;
        for (int i = current - 1; i >= 0; i--) {
            if (arrCoutn == searchBuffer) {
                break;
            }
            sBArr[arrCoutn] = word[i];
            cout << sBArr[arrCoutn] << " ";
            arrCoutn++;
        }
        cout << endl;
    }
}

/*Verifica si hay una coincidencia en los arrays
* En caso de que se sí, toma la que tenga más datos iguales seguidos y actualiza el offset y el match y retrona true
* En caso de que no, coloca valores de cero en offset y array y retorna false
*/
bool MainScreen::checkMatch() {
    int possibleMatchIndex = -1;
    int equalChars = 0;
    int maxCharsMatched = 0;

    //Verifica el primer caso donde buffer de busqueda está vacío
    if (sBArr->length() == 0) {
        offset = 0;
        match = 0;
        return false;
    } else {
        for (int i = 0; i < searchBuffer; i++) {
            if (sBArr[i] == dBArr[equalChars]) {
                equalChars++;
                for (int j = i - 1; j >= 0; j--) {
                    if (sBArr[j] == dBArr[equalChars]) {
                        equalChars++;
                    } else {
                        break;
                    }
                }
                if (equalChars > maxCharsMatched) {
                    maxCharsMatched = equalChars;
                    possibleMatchIndex = i;
                }
                equalChars = 0;
            }
        }
    }

    if (possibleMatchIndex == -1) {
        offset = 0;
        match = 0;
        return false;
    } else {
        offset = possibleMatchIndex;
        match = maxCharsMatched;
        return true;
    }
}

// Determina el valor de la siguiente letra del string para colocarla en la solución
void MainScreen::setNext() {
    nextChar = dBArr[match];
}

// Guarda y muestra la solución en el formato indicado
void MainScreen::solution() {
    cout << "offset: " << offset << " , " << "match: " << match << " , " << "next: " << nextChar << endl;
    cout << endl;
}

void MainScreen::createMatrix() {
    // crear matriz para guardar los datos comprimidos
    for (int i = 0; i < word.length(); ++i) {
        compresMat[i] = new string[3];
    }
}

void MainScreen::showMatrix() {
    cout << "--- Codes Matrix ---" << endl;
    for (int i = 0; i < word.length(); ++i) {
        for (int j = 0; j < 3; ++j) {
            if ((*(compresMat + i) + j)->empty()) {
                break;
            } else if (j == 0) {
                cout << "(" << *(*(compresMat + i) + j) << ", ";
                codedWord = codedWord + "(" + *(*(compresMat + i) + j) + ",";
            } else if (j == 1) {
                cout << *(*(compresMat + i) + j) << ", ";
                codedWord = codedWord + *(*(compresMat + i) + j) + ",";
            } else {
                cout << *(*(compresMat + i) + j) << ")" << endl;
                codedWord = codedWord + *(*(compresMat + i) + j) + ") ";
            }
        }
    }
    QString userTextCompressed = QString::fromStdString(codedWord);
    ui->compressResult->setPlainText(userTextCompressed);
    ui->decompressResult->setPlainText("");
    codedWord = "";
}

void MainScreen::decompress(const string &userInput) {

}

void MainScreen::on_compressButton_clicked() {
    std::cout << "\n\n----------------- Compressing -------------------" << std::endl;

    QString userText = ui->userText->toPlainText();
    word = userText.toStdString();
    this->compress();
}

void MainScreen::on_decompressButton_clicked() {
    std::cout << "\n\n----------------- Decompressing -----------------" << std::endl;

    QString userText = ui->userText->toPlainText();
    this->decompress(userText.toStdString());

    QString userTextDecompressed = QString::fromStdString(decodedWord);
    ui->compressResult->setPlainText("");
    ui->decompressResult->setPlainText(userTextDecompressed);
}