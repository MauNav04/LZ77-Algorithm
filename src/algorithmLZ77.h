#ifndef LZ77_ALGORITHMLZ77_H
#define LZ77_ALGORITHMLZ77_H

#include <iostream>
#include <stdlib.h>
using namespace std;

class algorithmLZ77 {
private:
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
    string **compresMat = new string *[word.length()];

    string dBArr[6];
    string sBArr[7];


public:
    // constructor
    algorithmLZ77(string txt){
        word = txt;
    }

    // métodos
    void compress();
    void inputChars();
    void inputSearchBuffer();
    bool checkMatch();
    void setNext();
    void solution();
    void createMatrix();
    void showMatrix();
};

#endif //LZ77_ALGORITHMLZ77_H
