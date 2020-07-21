#include <iostream>
#include <vector>
#include <cctype>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

/*Prototypes:*/
void startSystem();
void displayMenu();
char getUserSelectionInput();
void printDataCollection(const vector<double>& data);
void addNewDataItemToCollection(vector<double>& data);
void deleteAllCollectionItems(vector<double>& data);
double calculateMeanValue(const vector<double>& data, string& errorMsg);
double findLargestDataItem(const vector<double>& data, string& errorMsg);
double findSmallestDataItem(const vector<double>& data, string& errorMsg);
void resultDisplayer(double result, const string& typeOfResult, const string& errorMsg);
void displayBye();

/*Program Main:*/
int main()
{
	startSystem();

	return 0;
}

void startSystem()
{
	vector<double> dataCollection{};
	char userSelection{};
	double resultToPrint{};
	string errorMsg = "";

	while (userSelection != 'Q')
	{
		displayMenu();
		userSelection = getUserSelectionInput();

		if (userSelection == 'P')
		{
			printDataCollection(dataCollection);
		}
		else if (userSelection == 'A')
		{
			addNewDataItemToCollection(dataCollection);
		}
		else if (userSelection == 'D')
		{
			deleteAllCollectionItems(dataCollection);
		}
		else if (userSelection == 'M')
		{
			resultToPrint = calculateMeanValue(dataCollection, errorMsg);
			resultDisplayer(resultToPrint, "Mean", errorMsg);
		}
		else if (userSelection == 'L')
		{
			resultToPrint = findLargestDataItem(dataCollection, errorMsg);
			resultDisplayer(resultToPrint, "Largest", errorMsg);
		}
		else if (userSelection == 'S')
		{
			resultToPrint = findSmallestDataItem(dataCollection, errorMsg);
			resultDisplayer(resultToPrint, "Smallest", errorMsg);
		}
		else if (userSelection == 'Q')
		{
			displayBye();
		}

		errorMsg = ""; // Set again to empty
	}
}

void displayMenu()
{
	cout << endl;
	cout << "------------------------------" << endl;
	cout << "Menu options: " << endl;
	cout << "P - Print the data collection" << endl;
	cout << "A - Add a data item to the collection" << endl;
	cout << "D - Delete all data item in the collection" << endl;
	cout << "M - Calculate and display the Mean value of the data collection" << endl;
	cout << "L - Find and display the Largest data item in the collection" << endl;
	cout << "S - Find and display the Smallest data item in the collection" << endl;
	cout << "Q - To Quit" << endl;
	cout << "------------------------------" << endl;
	cout << endl;
}

char getUserSelectionInput()
{
	char inputFromUser{};
	bool validInput{ false };


	while (!validInput)
	{
		cout << "Please enter your selection: ";
		cin >> inputFromUser;
		
		if (isalpha(inputFromUser))
		{
			inputFromUser = toupper(inputFromUser);
			
			if (inputFromUser == 'Q' || inputFromUser == 'P' || inputFromUser == 'A'
				|| inputFromUser == 'M' || inputFromUser == 'L' || inputFromUser == 'S'
				|| inputFromUser == 'D')
			{
				validInput = true;
			}

		} // else - validInput is false
		
		if (!validInput)
		{
			cout << "Wrong input, please try again..." << endl << endl;
		}
	}

	return inputFromUser;
}

void printDataCollection(const vector<double>& data)
{
	
	cout << "[ ";
	if (data.size()) // If the collection isn't empty (size != 0)
	{
		for (auto& dataItem : data)
		{
			cout << dataItem << " ";
		}
	}
	cout << "]" << endl;
}

void addNewDataItemToCollection(vector<double>& data)
{
	double dataItemToAdd{ 0.0 };
	cout << "Enter data item number " << data.size() + 1  << " to the collection: ";
	cin >> dataItemToAdd;
	data.push_back(dataItemToAdd);
	cout << dataItemToAdd << " added to the data collection." << endl;
}

void deleteAllCollectionItems(vector<double>& data)
{
	data.clear();
	cout << "The list is empty now..." << endl;
}

double calculateMeanValue(const vector<double>& data, string& errorMsg)
{
	double sum{ 0.0 };
	double avg{ 0.0 };

	if (data.size())
	{
		for (auto& value : data)
		{
			sum += value;
		}

		avg =  sum / data.size();
	}
	else
	{
		errorMsg = "The data collection is empty...";
	}

	return avg;
}

double findLargestDataItem(const vector<double>& data, string& errorMsg)
{
	double largestNumberInCollection{ data.at(0) };

	if (data.size())
	{
		for (auto& value : data)
		{
			if (largestNumberInCollection < value)
			{
				largestNumberInCollection = value;
			}
		}
	}
	else
	{
		errorMsg = "The data collection is empty...";
	}

	return largestNumberInCollection;

}

double findSmallestDataItem(const vector<double>& data, string& errorMsg)
{
	double smallestNumberInCollection{ data.at(0) };

	if (data.size())
	{
		for (auto& value : data)
		{
			if (smallestNumberInCollection > value)
			{
				smallestNumberInCollection = value;
			}
		}
	}
	else
	{
		errorMsg = "The data collection is empty...";
	}

	return smallestNumberInCollection;

}

void resultDisplayer(double result, const string& typeOfResult, const string& errorMsg)
{
	if (errorMsg == "") // No error
	{
		cout << typeOfResult << ": " << result << endl;
	}
	else
	{
		cout << "Error: " << errorMsg << endl;
	}
}

void displayBye()
{
	cout << "Thank you for using the system..." << endl;
}
