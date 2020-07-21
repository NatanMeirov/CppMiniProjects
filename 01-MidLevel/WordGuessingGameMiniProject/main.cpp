/* Tip: You can modify the current WordBank.txt file by adding more words to the words bank, and the system will work exactly the same */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include <cctype>


//Prototypes
std::string getWordFromBank();
void displayBoard(int livesLeft);
void printBlanks(std::string chosenWord, std::string lettersGuessedByUser);
int generateRandomNumber(int numberOfWordsInTheBank);
bool checkIfWonGame(std::string word, std::string lettersGuessedByUser);
void runWordGuessingGameEngine();


//Consts
const std::string FILENAME{ "WordBank.txt" }; // Can be replaced by other words bank text file in the same format of lowercase words


//Program
int main()
{
	runWordGuessingGameEngine();
	return 0;
}


std::string getWordFromBank()
{
	std::string tempWord{ "" };
	std::vector<std::string> wordsList{};
	size_t index{ 0 };

	std::ifstream inputFile(FILENAME);
	if (!inputFile)
	{
		std::cout << "Error: -10//WordBank not found...\n\n";
	}

	inputFile.ignore(255, '\n'); // To ignore the header of the WordBank.txt

	// Pre-Read
	inputFile >> tempWord;
	while (!inputFile.eof()) // Filling the list with words from the WordBank file
	{
		wordsList.push_back(tempWord);

		// Post-Read
		inputFile >> tempWord;
	}

	inputFile.close();

	return wordsList.at(generateRandomNumber(wordsList.size())); // Returning random word
}


void printBlanks(std::string chosenWord, std::string lettersGuessedByUser)
{
	for (size_t i{ 0 }; i < chosenWord.size(); i++)
	{
		if (lettersGuessedByUser.find(chosenWord.at(i)) != -1) // Single letter was found (guessed correctly by the user)
		{
			if (i != 0)
			{
				std::cout << chosenWord.at(i) << " ";
			}
			else
			{
				std::cout << static_cast<char>(toupper(chosenWord.at(i))) << " "; // Uppercases the first letter in the word
			}
		}
		else // Letter not found yet - a blank will be printed
		{
			std::cout << "_" << " ";
		}
	}
}


int generateRandomNumber(int numberOfWordsInTheBank)
{
	srand(time(NULL)); // Seed
	return rand() % numberOfWordsInTheBank + 1;
}

void runWordGuessingGameEngine()
{
	bool loseGame{ false };
	bool winGame{ false };
	int userLives{ 7 };
	std::string word = getWordFromBank();
	std::string lettersGuessedByUser{ "" };
	char currentCharGuess{};

	while (!loseGame && !winGame)
	{
		displayBoard(userLives);
		std::cout << std::endl << std::endl;
		printBlanks(word, lettersGuessedByUser);

		std::cout << "\n\nLetters Guessed: " << lettersGuessedByUser << std::endl;
		std::cout << "\n\nTry to guess a letter: ";
		std::cin >> currentCharGuess;
		lettersGuessedByUser += currentCharGuess;

		system("cls");


		winGame = checkIfWonGame(word, lettersGuessedByUser);
		
		if (word.find(currentCharGuess) == -1) // Not a correct character
		{
			userLives--;

			if (userLives == 0)
			{
				loseGame = true;
			}
		}

		if (winGame)
		{
			std::cout << "\nYOU WON!!!" << std::endl;
			std::cout << "The word was: " << word << std::endl << std::endl;
		}
		else if (loseGame)
		{
			std::cout << "\nYOU LOSE..." << std::endl;
			std::cout << "The word was: " << word << std::endl << std::endl;
		}
	}
}


bool checkIfWonGame(std::string word, std::string lettersGuessedByUser)
{
	for (size_t i{ 0 }; i < word.size(); i++)
	{
		if (lettersGuessedByUser.find(word.at(i)) != -1)
		{
			if (i == word.size() + 1) // Reached the end of the word successfully
			{
				return true;
			}
		}
		else
		{
			return false;
		}
	}
}


void displayBoard(int livesLeft)
{
	switch (livesLeft)
	{
	case 0:
	{
		std::cout << "\t\t\t|------|" << std::endl;
		std::cout << "\t\t\t|      0" << std::endl;
		std::cout << "\t\t\t|     /|\\" << std::endl;
		std::cout << "\t\t\t|      |" << std::endl;
		std::cout << "\t\t\t|     / \\" << std::endl;
		std::cout << "\t\t\t|" << std::endl;
		std::cout << "\t\t\t|_____________";
		break;
	}
	case 1:
	{
		std::cout << "\t\t\t|------|" << std::endl;
		std::cout << "\t\t\t|      0" << std::endl;
		std::cout << "\t\t\t|     /|\\" << std::endl;
		std::cout << "\t\t\t|      |" << std::endl;
		std::cout << "\t\t\t|       \\" << std::endl;
		std::cout << "\t\t\t|" << std::endl;
		std::cout << "\t\t\t|_____________";
		break;
	}
	case 2:
	{
		std::cout << "\t\t\t|------|" << std::endl;
		std::cout << "\t\t\t|      0" << std::endl;
		std::cout << "\t\t\t|     /|\\" << std::endl;
		std::cout << "\t\t\t|      |" << std::endl;
		std::cout << "\t\t\t|" << std::endl;
		std::cout << "\t\t\t|" << std::endl;
		std::cout << "\t\t\t|_____________";
		break;
	}
	case 3:
	{
		std::cout << "\t\t\t|------|" << std::endl;
		std::cout << "\t\t\t|      0" << std::endl;
		std::cout << "\t\t\t|     /|" << std::endl;
		std::cout << "\t\t\t|      |" << std::endl;
		std::cout << "\t\t\t|" << std::endl;
		std::cout << "\t\t\t|" << std::endl;
		std::cout << "\t\t\t|_____________";
		break;
	}
	case 4:
	{
		std::cout << "\t\t\t|------|" << std::endl;
		std::cout << "\t\t\t|      0" << std::endl;
		std::cout << "\t\t\t|      |" << std::endl;
		std::cout << "\t\t\t|      |" << std::endl;
		std::cout << "\t\t\t|" << std::endl;
		std::cout << "\t\t\t|" << std::endl;
		std::cout << "\t\t\t|_____________";
		break;
	}
	case 5:
	{
		std::cout << "\t\t\t|------|" << std::endl;
		std::cout << "\t\t\t|      0" << std::endl;
		std::cout << "\t\t\t|      |" << std::endl;
		std::cout << "\t\t\t|" << std::endl;
		std::cout << "\t\t\t|" << std::endl;
		std::cout << "\t\t\t|" << std::endl;
		std::cout << "\t\t\t|_____________";
		break;
	}
	case 6:
	{
		std::cout << "\t\t\t|------|" << std::endl;
		std::cout << "\t\t\t|      0" << std::endl;
		std::cout << "\t\t\t|" << std::endl;
		std::cout << "\t\t\t|" << std::endl;
		std::cout << "\t\t\t|" << std::endl;
		std::cout << "\t\t\t|" << std::endl;
		std::cout << "\t\t\t|_____________";
		break;
	}
	case 7:
	{
		std::cout << "\t\t\t|------|" << std::endl;
		std::cout << "\t\t\t|" << std::endl;
		std::cout << "\t\t\t|" << std::endl;
		std::cout << "\t\t\t|" << std::endl;
		std::cout << "\t\t\t|" << std::endl;
		std::cout << "\t\t\t|" << std::endl;
		std::cout << "\t\t\t|_____________";
		break;
	}
	}
}