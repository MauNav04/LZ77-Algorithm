#ifndef LZ77_TOOL_ALGORITHM_H
#define LZ77_TOOL_ALGORITHM_H

#include <iostream>
#include <stdlib.h>

using namespace std;

class Algorithm {
public:
    // constructor
    Algorithm();

    // métodos
    void compress();

    void inputChars();

    void inputSearchBuffer();

    bool checkMatch();

    void setNext();

    void solution();

    void createMatrix();

    void showMatrix();

    // atributos
    int const window = 13;
    int const dataBuffer = 6;
    int const searchBuffer = window - dataBuffer;
    int offset;
    int match;
    int current = 0;
    int fila = 0;
    string nextChar;
    string word = "cabracadabrarrarrad";
    string **compresMat = new string *[word.length()];

    string dBArr[6];
    string sBArr[7];
};

#endif //LZ77_TOOL_ALGORITHM_H