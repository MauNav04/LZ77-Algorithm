#include <cstdlib>
#include <iostream>

using namespace std;

int const window = 13;
int const dataBuffer = 6;
int const searchBuffer = window - dataBuffer;

string dBArr[dataBuffer];
string sBArr[searchBuffer];


string word = "cabracadabrarrarrad";

int offset;
int match;
string nextChar ;

int current = 0;

//Muestra la solución en el formato indicado
void printSolution() {
	cout << "offset: " << offset << " , " << "match: " << match << " , " << "next" << nextChar << endl;
	cout << endl;
}

// Determina el valor de la siguiente letra del string para colocarla en la solución
void setNext() {

	nextChar = dBArr[match];
}

/*Verifica si hay una coincidencia en los arrays
* En caso de que se sí, toma la que tenga más datos iguales seguidos y actualiza el offset y el match y retrona true
* En caso de que no, coloca valores de cero en offset y array y retorna false
*/
bool checkMatch() {
	int possibleMatchIndex = -1;
	int equalChars = 0;
	int maxCharsMatched = 0;

	//Verifica el primer caso donde buffer de busqueda está vacío
	if (sBArr->length() == 0) {
		offset = 0;
		match = 0;
		return false;
	}

	else {
		for (int i = 0; i < searchBuffer; i++)
		{
			if (sBArr[i] == dBArr[equalChars]) {
				equalChars++;
				for (int j = i-1; j >= 0; j--) {
					if (sBArr[j] == dBArr[equalChars]) {
						equalChars++;
					}
					else {
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
	}
	else { 
		offset = possibleMatchIndex;
		match = maxCharsMatched;
		return true; 
	}

}


//Places the chars of the word onto the data Buffer Array depending on the current char being read
void inputChars() {

	for (int i = 0; i < dataBuffer ; i++)
	{
		if (current + i < word.length()) {
			dBArr[i] = word.at(current + i);

			cout << dBArr[i] << " ";
		}
		else {
			break;
		}
	}

	cout << endl;

}

//Coloca los valores correspondientes en el buffer de busqueda
void inputSearchBuffer() {
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

int main() {
	while (current <= word.length()) {
		inputChars();
		inputSearchBuffer();
		checkMatch();
		setNext();
		printSolution();
		current = current + match + 1;
	}
}