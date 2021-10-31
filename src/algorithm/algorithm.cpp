#include "algorithm.h"

// Constructor
Algorithm::Algorithm() {}

// Función que ejecuta el algoritmo
void Algorithm::compress() {
    // Se crea una matriz de dimensiones (tamaño del texto X 3)
    createMatrix();
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
void Algorithm::inputChars() {
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
void Algorithm::inputSearchBuffer() {
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
bool Algorithm::checkMatch() {
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
void Algorithm::setNext() {
    nextChar = dBArr[match];
}

// Guarda y muestra la solución en el formato indicado
void Algorithm::solution() {
    cout << "offset: " << offset << " , " << "match: " << match << " , " << "next" << nextChar << endl;
    cout << endl;
}

void Algorithm::createMatrix() {
    // crear matriz para guardar los datos comprimidos
    for (int i = 0; i < word.length(); ++i) {
        compresMat[i] = new string[3];
    }
}

void Algorithm::showMatrix() {
    for (int i = 0; i < word.length(); ++i) {
        for (int j = 0; j < 3; ++j) {
            if (*(*(compresMat + i) + j) == "") {
                break;
            } else if (j == 0) {
                cout << "(" << *(*(compresMat + i) + j) << ", ";
            } else if (j == 1) {
                cout << *(*(compresMat + i) + j) << ", ";
            } else {
                cout << *(*(compresMat + i) + j) << ")" << endl;
            }
        }
    }
}