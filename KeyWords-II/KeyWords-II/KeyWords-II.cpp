// KeyWords-II.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <algorithm>
#include <iostream>
#include <ctime>
#include <vector>
#include <cctype>

using namespace std;

char again ='y';
string Name;
const int MaxWrong = 8;


int main()
{
	// Display Title of program to user
	cout << "Code Breaker Training Simulation Program for CIA Recruits"<< endl;
	// Ask the recruit to login using thier name
	cout << "Enter your name: ";
	// Hold the recruit's name in a var, and address them by it throughout the simulation.
	cin >> Name;
	// Display an overview of what Keywords II is to the recruit 

	// Display an directions to the recruit on how to use Keywords



	// Create a collection of 10 words you had wrote down manually
	vector<string> wordList;
	wordList.push_back("sworda");
	wordList.push_back("swordb");
	wordList.push_back("swordc");
	wordList.push_back("swordd");
	wordList.push_back("sworde");
	wordList.push_back("swordf");
	wordList.push_back("swordg");
	wordList.push_back("swordh");
	wordList.push_back("swordi");
	wordList.push_back("swordj");


	vector<string>::iterator myIterator;

	// Create an int var to count the number of simulations being run starting at 1
	int numSim = 1;

	do
	{
		
		
		// Display the simulation # is staring to the recruit. 
		cout << "you are on simulation # " << numSim;
		// Pick new 3 random words from your collection as the secret code word the recruit has to guess. 
		for (int i = 0; i < 3; i++)
		{

		}

		srand(static_cast<unsigned int>(time(0)));
		random_shuffle(wordList.begin(), wordList.end());

		const string TheWord = wordList[0];
		string soFar(TheWord.size(), '-');
		string used = "";
		int wrong = 0;

		// While recruit hasn’t made too many incorrect guesses and hasn’t guessed the secret word
		while ((wrong < MaxWrong) && (soFar != TheWord))
		{

			//Tell recruit how many incorrect guesses he or she has left

			cout << "\n\nYou have " << (MaxWrong - wrong) << " wrong guesses left" << endl;

			//     Show recruit the letters he or she has guessed
			cout << "\nYou have used the following letters: \n" << used << endl;
			//     Show player how much of the secret word he or she has guessed
			cout << "\nSo far you the word is:\n" << soFar << endl;
			//     Get recruit's next guess
			char guess;
			cout << "Enter your guess: ";
			cin >> guess;
			tolower(guess);

			//     While recruit has entered a letter that he or she has already guessed
			while (used.find(guess) != string::npos)
			{
				//          Get recruit ’s guess

				cout << "\nYou've already guessed" << guess << endl;
				cout << "Enter your guess: ";
				cin >> guess;
				tolower(guess);
			}

			//     Add the new guess to the group of used letters
			used += guess;
			//     If the guess is in the secret word
			if (TheWord.find(guess) != string::npos)
			{

				//          Tell the recruit the guess is correct
				cout << "Thats correct " << guess << " is in the word\n";

				//     Update the word guessed so far with the new letter
				for (int i = 0; i < TheWord.length(); ++i)
				{
					if (TheWord[i] == guess) {

						soFar[i] = toupper(guess);
					}
				}

			}
			//     Otherwise
			else
			{
				//Tell the recruit the guess is incorrect
				cout << "Sorry " << toupper(guess) << " isnt in the word.\n";
				//Increment the number of incorrect guesses the recruit has made
				++wrong;

			}

		}

		// If the recruit has made too many incorrect guesses
		if (wrong == MaxWrong)
		{
			//     Tell the recruit that he or she has failed the Keywords II course.
			cout << "\nYou have FAILED";

		}
		else// Otherwise
		{
			//     Congratulate the recruit on guessing the secret words
			cout << "\nYou guessed it";
		}
		// Ask the recruit if they would like to run the simulation again
		cout << "\nWould you like to run it again? (y/n)";
		cin >> again;
		// If the recruit wants to run the simulation again
		if ((again == 'y'))
		{
			//     Increment the number of simiulations ran counter
			numSim++;
		}
		//Move program execution back up to // Display the simulation # is staring to the recruit. 
	}while ((again == 'y'));

	// Otherwise 

	//     Display End of Simulations to the recruit
	cout << "You ran the simulation " << numSim << "times";
	//     Pause the Simulation with press any key to continue
	system("pause");
    return 0;
}

