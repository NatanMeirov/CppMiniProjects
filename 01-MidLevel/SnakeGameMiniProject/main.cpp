#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include <conio.h>


// Enums:
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };


// Prototypes:
void gameLogic(eDirection direction, int& x, int& y, int& fruitX, int& fruitY, size_t& score, int* tailX, int* tailY, size_t& tailCounter, bool& gameOver);
void inGameUserInput(eDirection& direction);
void gameVisualization(int x, int y, int fruitX, int fruitY, size_t score, int* tailX, int* tailY, size_t tailCounter);
void runSnakeGameEngine();


// Consts:
const int width{ 20 }; // Arena width
const int height{ 20 }; // Arena height


// Program:
int main()
{
	runSnakeGameEngine();
	return 0;
}


void gameLogic(eDirection direction, int& x, int& y, int& fruitX, int& fruitY, size_t& score, int* tailX, int* tailY, size_t& tailCounter, bool& gameOver)
{
	int prevX{ tailX[0] };
	int prevY{ tailY[0] };
	tailX[0] = x;
	tailY[0] = y;
	int prevPrevX{ 0 }, prevPrevY{ 0 };

	for (size_t i{ 1 }; i < tailCounter; i++)
	{
		// Getting the location of the tail
		prevPrevX = tailX[i];
		prevPrevY = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prevPrevX;
		prevY = prevPrevY;
	}


	switch (direction)
	{
	case LEFT:
	{
		x--;
		break;
	}
	case RIGHT:
	{
		x++;
		break;
	}
	case UP:
	{
		y--;
		break;
	}
	case DOWN:
	{
		y++;
		break;
	}
	default:
		break;
	}


	if (x >= width - 1) // Snake reachs to the right wall
	{
		x = 1;
	}
	else if (x <= 0) // Snake reachs to the left wall
	{
		x = width - 2;
	}

	if (y > height - 1) // Snake reachs to the bottom wall
	{
		y = 0;
	}
	else if (y < 0) // Snake reachs to the top wall
	{
		y = height - 1;
	}
	

	for (size_t i{ 0 }; i < tailCounter; i++)
	{
		if (tailX[i] == x && tailY[i] == y) // Snake eats its tail -> GAME IS OVER
		{
			gameOver = true;
			std::cout << "\nGAME OVER..." << std::endl;
		}
	}


	if (x == fruitX && y == fruitY) // Snake eats the fruit
	{
		score++;
		tailCounter++; // The tail is growing

		// New location to the fruit
		srand(time(NULL)); // Seed for random function
		fruitX = rand() % width;
		fruitY = rand() % height;

		if (fruitX == 0 || fruitY == 0) // Fruit is "inside" the walls (left or top) -> get new coordinates
		{
			fruitX = rand() % width;
			fruitY = rand() % height;
		}
	}
}


void inGameUserInput(eDirection& direction)
{
	if (_kbhit()) // Keyboard hit for directions of the Snake
	{
		switch (_getch())
		{
		case 'a':
		{
			direction = LEFT;
			break;
		}
		case 'd':
		{
			direction = RIGHT;
			break;
		}
		case 'w':
		{
			direction = UP;
			break;
		}
		case 's':
		{
			direction = DOWN;
			break;
		}
		}
	}
}


void gameVisualization(int x, int y, int fruitX, int fruitY, size_t score, int* tailX, int* tailY, size_t tailCounter)
{
	system("cls");

	// Display the Arena:
	for (size_t i{ 0 }; i < width; i++)
	{
		std::cout << "#";
	}
	std::cout << std::endl;

	for (size_t j{ 0 }; j < height; j++)
	{
		for (size_t k{ 0 }; k < width; k++)
		{
			if (k == 0 || k == width - 1)
			{
				std::cout << "#";
			}
			else
			{
				if (k == x && j == y) // Starting position of the Snake in the beginning of the game
				{
					std::cout << "O"; // Head of the Snake
				}
				else if (k == fruitX && j == fruitY)
				{
					std::cout << "*"; // The Fruit
				}
				else // Default -> blank or tail
				{
					bool printTail{ false };

					for (size_t l{ 0 }; l < tailCounter; l++)
					{
						if (tailX[l] == k && tailY[l] == j) // Need to print the tail
						{
							std::cout << "o";
							printTail = true;
						}
					}

					if (!printTail) // If the printTail flag is false, so we display blank in this place
					{
						std::cout << " ";
					}
				}
			}
		}
		std::cout << std::endl;
	}

	for (size_t i{ 0 }; i < width; i++)
	{
		std::cout << "#";
	}
	std::cout << std::endl;
	std::cout << "Score: " << score << std::endl;
}


void runSnakeGameEngine()
{
	// First game settings:
	srand(time(NULL)); // Seed for random function
	bool gameOver{ false };
	int x{ width / 2 }, y{ height / 2 }; // x and y axis -> Snake starts in the middle of the Arena
	int fruitX{ rand() % width }, fruitY{ rand() % height }; // Random x and y axis for the fruit
	size_t score{ 0 };
	eDirection direction{ STOP }; // Snake is not moving
	int tailX[width * height]{ 0 }, tailY[width * height]{ 0 }; // Array - is an address
	size_t tailCounter{ 0 };

	while (!gameOver)
	{
		gameVisualization(x, y, fruitX, fruitY, score, tailX, tailY, tailCounter);
		inGameUserInput(direction);
		gameLogic(direction, x, y, fruitX, fruitY, score, tailX, tailY, tailCounter, gameOver);
		Sleep(40);
	}

}