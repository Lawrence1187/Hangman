#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void createHiddenString(string underScores[], int wordLength) {
	for (int i = 0; i < wordLength; i++) {
		underScores[i] = "_";
	}
}

void displayHiddenString(string underScores[], int wordLength) {
	for (int i = 0; i < wordLength; i++) {
		cout << underScores[i];
	}
	cout << endl;
}

bool checkWin(string underScores[], int wordLength) {
	for (int i = 0; i < wordLength; i++) {
		if (underScores[i] == "_") {
			return false;
		}
	}
	return true;
}

int main() {
	string wordList[] = { "english", "french", "italian", "chinese", "japanese", "canadian", "german", "russian", "indian", "malaysian", "egyptian", "spanish", "mexican", "australian", "vietnamese", "mongolian", "korean", "brazilian", "polish" };
	int listLength = sizeof(wordList) / sizeof(wordList[0]);
	srand(time(nullptr));
	string chosenWord = wordList[rand() % listLength];
	//cout << "Chosen word is: " << chosenWord << endl;

	const int wordLength = chosenWord.length();
	string* underScores = new string[wordLength];
	createHiddenString(underScores, wordLength);
	int lives = 5;

	//cout << "List length is: " << listLength;

	cout << endl;
	cout << "Welcome to Hangman! A word has been chosen by the computer" << endl;
	char inputLetter;

	while (lives > 0) {
		displayHiddenString(underScores, wordLength);
		bool letterChecked = false;
		while (!letterChecked) {
			cout << "Please enter a letter: ";
			cin >> inputLetter;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			for (int i = 0; i < wordLength; i++) {
				if (chosenWord[i] == inputLetter) {
					*(underScores + i) = inputLetter;
					letterChecked = true;
				}
			}
			if (checkWin(underScores, wordLength)) {
				cout << "You win! Game Over." << endl;
				return 0;
			}
			if (!letterChecked) {
				lives--;
				cout << inputLetter << " is not in this word. " << lives << " lives left!" << endl;
				break;
			}
		}
	}
	cout << "Out of lives! Game Over." << endl;

	delete[] underScores;

	return 0;
}