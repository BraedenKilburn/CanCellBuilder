/****************************************************
* Author: Braeden Kilburn
* Section: 1005
*
* Date Created: 4 March 2020
*
* Description: Play the "Can-Cell" game against a
* computer opponent.
*
****************************************************/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

enum CAN_CELL_PARTS { UNUSED, BODY, HEAD, WING, LEG, EYE, TAIL };

int main(int argc, char* argv[])
{
	// Determine the game mode desired
	string option;
	bool debugMode = false;
	bool silentMode = false;

	if (argc > 1)
		option = argv[1];

	if (option == "debug")
		debugMode = true;

	if (option == "silent")
		silentMode = true;

	// Welcoming Screen
	cout << setw(26) << setfill('*') << "" << endl;
	cout << setw(23) << setfill(' ') << "Welcome to Can-cell" << setw(3) << "" << endl;
	cout << "To win, you must collect:" << endl;
	cout << "(1) Body" << endl;
	cout << "(1) Head" << endl;
	cout << "(4) Wings" << endl;
	cout << "(6) Legs" << endl;
	cout << "(2) Eyes" << endl;
	cout << "(1) Tail" << endl << endl;
	cout << "Special Rules: " << endl;
	cout << "1. The body must be acquired first." << endl;
	cout << "2. The head must be acquired before the eyes." << endl;
	cout << "3. Legs, tail and wings can be acquired anytime after the body." << endl;
	cout << setw(26) << setfill('*') << "" << endl;

	// Declare a variable set for each players body parts and initialize to the number required to complete the can-cell
	int body, head, wing, leg, eye, tail;
	body = 1;
	head = 1;
	wing = 4;
	leg = 6;
	eye = 2;
	tail = 1;

	int computerBody, computerHead, computerWing, computerLeg, computerEye, computerTail;
	computerBody = 1;
	computerHead = 1;
	computerWing = 4;
	computerLeg = 6;
	computerEye = 2;
	computerTail = 1;

	// Used to keep track of the player's inventory
	int playerOneBodyCount{ 0 };
	int playerOneHeadCount{ 0 };
	int playerOneWingCount{ 0 };
	int playerOneLegCount{ 0 };
	int playerOneEyeCount{ 0 };
	int playerOneTailCount{ 0 };

	// Used to keep track of the computer's inventory
	int computerBodyCount{ 0 };
	int computerHeadCount{ 0 };
	int computerWingCount{ 0 };
	int computerLegCount{ 0 };
	int computerEyeCount{ 0 };
	int computerTailCount{ 0 };

	// Initialize a random seed
	srand((unsigned int)time(NULL));

	// Used to capture the white space of the enter key
	string answer;

	int roll{ 0 };                    // Player One's roll
	int computerRoll{ 0 };   // Computer's roll
	int roundCount = 1;    // Round counter

	// Used to hold which rolled part the participant got in the switch statements
	string rolledPart;

	if (argc == 1) // NORMAL GAME MODE
	{
		// Initialize a random seed
		srand((unsigned int)time(NULL));

		// Forever loop only broken when all the Can-Cell parts have been collected
		while (true)
		{
			// Round header
			cout << setw(16) << setfill('#') << "" << endl;
			cout << "Round # " << roundCount << endl << endl;

			cout << "Hit enter to roll die: ";
			getline(cin, answer);
			roll = rand() % 6 + 1; // Player's Roll (Keeps our roll integers between 1 and 6, inclusive.)
			computerRoll = rand() % 6 + 1; // Computer's roll

			if (body != 0) // DON'T HAVE A BODY YET
			{
				switch (roll)
				{
				case BODY:
					rolledPart = "BODY";
					body--;
					playerOneBodyCount++;
					cout << "Player one roll is " << rolledPart << endl;
					break;
				case HEAD:
					rolledPart = "HEAD";
					cout << "Player one roll is " << rolledPart << ", must have BODY first" << endl;
					break;
				case WING:
					rolledPart = "WING";
					cout << "Player one roll is " << rolledPart << ", must have BODY first" << endl;
					break;
				case LEG:
					rolledPart = "LEG";
					cout << "Player one roll is " << rolledPart << ", must have BODY first" << endl;
					break;
				case EYE:
					rolledPart = "EYE";
					cout << "Player one roll is " << rolledPart << ", must have BODY first" << endl;
					break;
				case TAIL:
					rolledPart = "TAIL";
					cout << "Player one roll is " << rolledPart << ", must have BODY first" << endl;
				}
			}
			else if (head != 0) // DON'T HAVE A HEAD YET
			{
				switch (roll)
				{
				case BODY:
					rolledPart = "BODY";
					cout << "Player one roll is duplicate " << rolledPart << endl;
					break;
				case HEAD:
					rolledPart = "HEAD";
					head--;
					playerOneHeadCount++;
					cout << "Player one roll is " << rolledPart << endl;
					break;
				case WING:
					rolledPart = "WING";
					if (wing == 0)
					{
						cout << "Player one roll is duplicate " << rolledPart << endl;
					}
					else
					{
						wing--;
						playerOneWingCount++;
						cout << "Player one roll is " << rolledPart << endl;
					}
					break;
				case LEG:
					rolledPart = "LEG";
					if (leg == 0)
					{
						cout << "Player one roll is duplicate " << rolledPart << endl;
					}
					else
					{
						leg--;
						playerOneLegCount++;
						cout << "Player one roll is " << rolledPart << endl;
					}
					break;
				case EYE:
					rolledPart = "EYE";
					cout << "Player one roll is " << rolledPart << ", must have HEAD first" << endl;
					break;
				case TAIL:
					rolledPart = "TAIL";
					if (tail == 0)
					{
						cout << "Player one roll is duplicate " << rolledPart << endl;
					}
					else
					{
						tail--;
						playerOneTailCount++;
						cout << "Player one roll is " << rolledPart << endl;
					}
				}
			}
			else // HAS A BODY AND A HEAD
			{
				switch (roll)
				{
				case BODY:
					rolledPart = "BODY";
					cout << "Player one roll is duplicate " << rolledPart << endl;
					break;
				case HEAD:
					rolledPart = "HEAD";
					cout << "Player one roll is duplicate " << rolledPart << endl;
					break;
				case WING:
					rolledPart = "WING";
					if (wing == 0)
					{
						cout << "Player one roll is duplicate " << rolledPart << endl;
					}
					else
					{
						wing--;
						playerOneWingCount++;
						cout << "Player one roll is " << rolledPart << endl;
					}
					break;
				case LEG:
					rolledPart = "LEG";
					if (leg == 0)
					{
						cout << "Player one roll is duplicate " << rolledPart << endl;
					}
					else
					{
						leg--;
						playerOneLegCount++;
						cout << "Player one roll is " << rolledPart << endl;
					}
					break;
				case EYE:
					rolledPart = "EYE";
					if (eye == 0)
					{
						cout << "Player one roll is duplicate " << rolledPart << endl;
					}
					else
					{
						eye--;
						playerOneEyeCount++;
						cout << "Player one roll is " << rolledPart << endl;
					}
					break;
				case TAIL:
					rolledPart = "TAIL";
					if (tail == 0)
					{
						cout << "Player one roll is duplicate " << rolledPart << endl;
					}
					else
					{
						tail--;
						playerOneTailCount++;
						cout << "Player one roll is " << rolledPart << endl;
					}
				}
			}

			// Check if the player has completed their Can-Cell (if completed, sum == 0)
			int playerCanCell = body + head + wing + leg + eye + tail;

			if (playerCanCell == 0) // Completed Can-Cell!
			{
				cout << setw(19) << setfill('*') << "" << endl;
				cout << "Player one has won!" << endl;
				cout << right << setw(27) << setfill(' ') << "Game Results" << endl;
				cout << setw(42) << setfill('-') << "" << endl;
				cout << left << setw(23) << setfill(' ') << "Player 1 Inventory";
				cout << "Player 2 Inventory" << endl;
				cout << setw(12) << "Body:" << setw(11) << playerOneBodyCount << setw(12) << "Body:" << computerBodyCount << endl;
				cout << setw(12) << "Head:" << setw(11) << playerOneHeadCount << setw(12) << "Head:" << computerHeadCount << endl;
				cout << setw(12) << "Eye:" << setw(11) << playerOneEyeCount << setw(12) << "Eye:" << computerEyeCount << endl;
				cout << setw(12) << "Wing:" << setw(11) << playerOneWingCount << setw(12) << "Wing:" << computerWingCount << endl;
				cout << setw(12) << "Leg:" << setw(11) << playerOneLegCount << setw(12) << "Leg:" << computerLegCount << endl;
				cout << setw(12) << "Tail:" << setw(11) << playerOneTailCount << setw(12) << "Tail:" << computerTailCount << endl;
				break;
			}

			// Report the player's inventory (uncompleted Can-Cell)
			cout << setw(21) << setfill('-') << "" << endl;
			cout << "Player 1 Inventory" << endl;
			cout << left << setw(12) << setfill(' ') << "Body:" << playerOneBodyCount << endl;
			cout << setw(12) << "Head:" << playerOneHeadCount << endl;
			cout << setw(12) << "Eye:" << playerOneEyeCount << endl;
			cout << setw(12) << "Wing:" << playerOneWingCount << endl;
			cout << setw(12) << "Leg:" << playerOneLegCount << endl;
			cout << setw(12) << "Tail:" << playerOneTailCount << endl << endl;

			// COMPUTER'S TURN (Player Two)
			if (computerBody != 0) // DON'T HAVE A BODY YET
			{
				switch (computerRoll)
				{
				case BODY:
					rolledPart = "BODY";
					computerBody--;
					computerBodyCount++;
					cout << "Player two roll is " << rolledPart << endl;
					break;
				case HEAD:
					rolledPart = "HEAD";
					cout << "Player two roll is " << rolledPart << ", must have BODY first" << endl;
					break;
				case WING:
					rolledPart = "WING";
					cout << "Player two roll is " << rolledPart << ", must have BODY first" << endl;
					break;
				case LEG:
					rolledPart = "LEG";
					cout << "Player two roll is " << rolledPart << ", must have BODY first" << endl;
					break;
				case EYE:
					rolledPart = "EYE";
					cout << "Player two roll is " << rolledPart << ", must have BODY first" << endl;
					break;
				case TAIL:
					rolledPart = "TAIL";
					cout << "Player two roll is " << rolledPart << ", must have BODY first" << endl;
				}
			}
			else if (computerHead != 0) // DON'T HAVE A HEAD YET
			{
				switch (computerRoll)
				{
				case BODY:
					rolledPart = "BODY";
					cout << "Player two roll is duplicate " << rolledPart << endl;
					break;
				case HEAD:
					rolledPart = "HEAD";
					computerHead--;
					computerHeadCount++;
					cout << "Player two roll is " << rolledPart << endl;
					break;
				case WING:
					rolledPart = "WING";
					if (computerWing == 0)
					{
						cout << "Player two roll is duplicate " << rolledPart << endl;
					}
					else
					{
						computerWing--;
						computerWingCount++;
						cout << "Player two roll is " << rolledPart << endl;
					}
					break;
				case LEG:
					rolledPart = "LEG";
					if (computerLeg == 0)
					{
						cout << "Player two roll is duplicate " << rolledPart << endl;
					}
					else
					{
						computerLeg--;
						computerLegCount++;
						cout << "Player two roll is " << rolledPart << endl;
					}
					break;
				case EYE:
					rolledPart = "EYE";
					cout << "Player two roll is " << rolledPart << ", must have HEAD first" << endl;
					break;
				case TAIL:
					rolledPart = "TAIL";
					if (computerTail == 0)
					{
						cout << "Player two roll is duplicate " << rolledPart << endl;
					}
					else
					{
						computerTail--;
						computerTailCount++;
						cout << "Player two roll is " << rolledPart << endl;
					}
				}
			}
			else // HAVE A BODY AND A HEAD
			{
				switch (computerRoll)
				{
				case BODY:
					rolledPart = "BODY";
					cout << "Player two roll is duplicate " << rolledPart << endl;
					break;
				case HEAD:
					rolledPart = "HEAD";
					cout << "Player two roll is duplicate " << rolledPart << endl;
					break;
				case WING:
					rolledPart = "WING";
					if (computerWing == 0)
					{
						cout << "Player two roll is duplicate " << rolledPart << endl;
					}
					else
					{
						computerWing--;
						computerWingCount++;
						cout << "Player two roll is " << rolledPart << endl;
					}
					break;
				case LEG:
					rolledPart = "LEG";
					if (computerLeg == 0)
					{
						cout << "Player two roll is duplicate " << rolledPart << endl;
					}
					else
					{
						computerLeg--;
						computerLegCount++;
						cout << "Player two roll is " << rolledPart << endl;
					}
					break;
				case EYE:
					rolledPart = "EYE";
					if (computerEye == 0)
					{
						cout << "Player two roll is duplicate " << rolledPart << endl;
					}
					else
					{
						computerEye--;
						computerEyeCount++;
						cout << "Player two roll is " << rolledPart << endl;
					}
					break;
				case TAIL:
					rolledPart = "TAIL";
					if (computerTail == 0)
					{
						cout << "Player two roll is duplicate " << rolledPart << endl;
					}
					else
					{
						computerTail--;
						computerTailCount++;
						cout << "Player two roll is " << rolledPart << endl;
					}
				}
			}

			// Check if the computer has completed its Can-Cell (if completed, sum == 0)
			int computerCanCell = computerBody + computerHead + computerWing + computerLeg + computerEye + computerTail;

			if (computerCanCell == 0) // Completed Can-Cell!
			{
				cout << setw(19) << setfill('*') << "" << endl;
				cout << "Player two has won!" << endl;
				cout << right << setw(27) << setfill(' ') << "Game Results" << endl;
				cout << setw(42) << setfill('-') << "" << endl;
				cout << left << setw(23) << setfill(' ') << "Player 1 Inventory";
				cout << "Player 2 Inventory" << endl;
				cout << setw(12) << "Body:" << setw(11) << playerOneBodyCount << setw(12) << "Body:" << computerBodyCount << endl;
				cout << setw(12) << "Head:" << setw(11) << playerOneHeadCount << setw(12) << "Head:" << computerHeadCount << endl;
				cout << setw(12) << "Eye:" << setw(11) << playerOneEyeCount << setw(12) << "Eye:" << computerEyeCount << endl;
				cout << setw(12) << "Wing:" << setw(11) << playerOneWingCount << setw(12) << "Wing:" << computerWingCount << endl;
				cout << setw(12) << "Leg:" << setw(11) << playerOneLegCount << setw(12) << "Leg:" << computerLegCount << endl;
				cout << setw(12) << "Tail:" << setw(11) << playerOneTailCount << setw(12) << "Tail:" << computerTailCount << endl;
				break;
			}

			// Report the computer's inventory (Uncompleted Can-Cell)
			cout << setw(21) << setfill('-') << "" << endl;
			cout << "Player 2 Inventory" << endl;
			cout << left << setw(12) << setfill(' ') << "Body:" << computerBodyCount << endl;
			cout << setw(12) << "Head:" << computerHeadCount << endl;
			cout << setw(12) << "Eye:" << computerEyeCount << endl;
			cout << setw(12) << "Wing:" << computerWingCount << endl;
			cout << setw(12) << "Leg:" << computerLegCount << endl;
			cout << setw(12) << "Tail:" << computerTailCount << endl << endl;

			roundCount++; // Keep track of which round we're going into
		}
	}
	else if (debugMode) // DEBUG MODE
	{
		// Initialize the random number generator with zero (thus the same die roll every game)
		srand(0);

		// Debug mode header
		cout << endl;
		cout << right << setw(29) << setfill('<') << " Debug Mode Active " << setw(11) << setfill('>') << "" << endl;

		while (true)
		{
			// Round header
			cout << setw(16) << setfill('#') << "" << endl;
			cout << "Round # " << roundCount << endl << endl;

			cout << "Hit enter to roll die: ";
			getline(cin, answer);
			roll = rand() % 6 + 1; // Player's Roll (Keeps our roll integers between 1 and 6, inclusive.)
			computerRoll = rand() % 6 + 1; // Computer's roll

			if (body != 0) // DON'T HAVE A BODY YET
			{
				switch (roll)
				{
				case BODY:
					rolledPart = "BODY";
					body--;
					playerOneBodyCount++;
					cout << "Player one roll is " << roll << " " << rolledPart << endl;
					break;
				case HEAD:
					rolledPart = "HEAD";
					cout << "Player one roll is " << roll << " " << rolledPart << ", must have BODY first" << endl;
					break;
				case WING:
					rolledPart = "WING";
					cout << "Player one roll is " << roll << " " << rolledPart << ", must have BODY first" << endl;
					break;
				case LEG:
					rolledPart = "LEG";
					cout << "Player one roll is " << roll << " " << rolledPart << ", must have BODY first" << endl;
					break;
				case EYE:
					rolledPart = "EYE";
					cout << "Player one roll is " << roll << " " << rolledPart << ", must have BODY first" << endl;
					break;
				case TAIL:
					rolledPart = "TAIL";
					cout << "Player one roll is " << roll << " " << rolledPart << ", must have BODY first" << endl;
				}
			}
			else if (head != 0) // DON'T HAVE A HEAD YET
			{
				switch (roll)
				{
				case BODY:
					rolledPart = "BODY";
					cout << "Player one roll is " << roll << " duplicate " << rolledPart << endl;
					break;
				case HEAD:
					rolledPart = "HEAD";
					head--;
					playerOneHeadCount++;
					cout << "Player one roll is " << roll << " " << rolledPart << endl;
					break;
				case WING:
					rolledPart = "WING";
					if (wing == 0)
					{
						cout << "Player one roll is " << roll << " duplicate " << rolledPart << endl;
					}
					else
					{
						wing--;
						playerOneWingCount++;
						cout << "Player one roll is " << roll << " " << rolledPart << endl;
					}
					break;
				case LEG:
					rolledPart = "LEG";
					if (leg == 0)
					{
						cout << "Player one roll is " << roll << " duplicate " << rolledPart << endl;
					}
					else
					{
						leg--;
						playerOneLegCount++;
						cout << "Player one roll is " << roll << " " << rolledPart << endl;
					}
					break;
				case EYE:
					rolledPart = "EYE";
					cout << "Player one roll is " << roll << " " << rolledPart << ", must have HEAD first" << endl;
					break;
				case TAIL:
					rolledPart = "TAIL";
					if (tail == 0)
					{
						cout << "Player one roll is " << " duplicate " << rolledPart << endl;
					}
					else
					{
						tail--;
						playerOneTailCount++;
						cout << "Player one roll is " << roll << " " << rolledPart << endl;
					}
				}
			}
			else // HAS A BODY AND A HEAD
			{
				switch (roll)
				{
				case BODY:
					rolledPart = "BODY";
					cout << "Player one roll is " << roll << " duplicate " << rolledPart << endl;
					break;
				case HEAD:
					rolledPart = "HEAD";
					cout << "Player one roll is " << roll << " duplicate " << rolledPart << endl;
					break;
				case WING:
					rolledPart = "WING";
					if (wing == 0)
					{
						cout << "Player one roll is " << roll << " duplicate " << rolledPart << endl;
					}
					else
					{
						wing--;
						playerOneWingCount++;
						cout << "Player one roll is " << roll << " " << rolledPart << endl;
					}
					break;
				case LEG:
					rolledPart = "LEG";
					if (leg == 0)
					{
						cout << "Player one roll is " << roll << " duplicate " << rolledPart << endl;
					}
					else
					{
						leg--;
						playerOneLegCount++;
						cout << "Player one roll is " << roll << " " << rolledPart << endl;
					}
					break;
				case EYE:
					rolledPart = "EYE";
					if (eye == 0)
					{
						cout << "Player one roll is " << roll << " duplicate " << rolledPart << endl;
					}
					else
					{
						eye--;
						playerOneEyeCount++;
						cout << "Player one roll is " << roll << " " << rolledPart << endl;
					}
					break;
				case TAIL:
					rolledPart = "TAIL";
					if (tail == 0)
					{
						cout << "Player one roll is " << roll << " duplicate " << rolledPart << endl;
					}
					else
					{
						tail--;
						playerOneTailCount++;
						cout << "Player one roll is " << roll << " " << rolledPart << endl;
					}
				}
			}

			// Check if the player has completed their Can-Cell (if completed, sum == 0)
			int playerCanCell = body + head + wing + leg + eye + tail;

			if (playerCanCell == 0) // Completed Can-Cell!
			{
				cout << setw(19) << setfill('*') << "" << endl;
				cout << "Player one has won!" << endl;
				cout << right << setw(27) << setfill(' ') << "Game Results" << endl;
				cout << setw(42) << setfill('-') << "" << endl;
				cout << left << setw(23) << setfill(' ') << "Player 1 Inventory";
				cout << "Player 2 Inventory" << endl;
				cout << setw(12) << "Body:" << setw(11) << playerOneBodyCount << setw(12) << "Body:" << computerBodyCount << endl;
				cout << setw(12) << "Head:" << setw(11) << playerOneHeadCount << setw(12) << "Head:" << computerHeadCount << endl;
				cout << setw(12) << "Eye:" << setw(11) << playerOneEyeCount << setw(12) << "Eye:" << computerEyeCount << endl;
				cout << setw(12) << "Wing:" << setw(11) << playerOneWingCount << setw(12) << "Wing:" << computerWingCount << endl;
				cout << setw(12) << "Leg:" << setw(11) << playerOneLegCount << setw(12) << "Leg:" << computerLegCount << endl;
				cout << setw(12) << "Tail:" << setw(11) << playerOneTailCount << setw(12) << "Tail:" << computerTailCount << endl;
				break;
			}

			// Report the player's inventory (uncompleted Can-Cell)
			cout << setw(21) << setfill('-') << "" << endl;
			cout << "Player 1 Inventory" << endl;
			cout << left << setw(12) << setfill(' ') << "Body:" << playerOneBodyCount << endl;
			cout << setw(12) << "Head:" << playerOneHeadCount << endl;
			cout << setw(12) << "Eye:" << playerOneEyeCount << endl;
			cout << setw(12) << "Wing:" << playerOneWingCount << endl;
			cout << setw(12) << "Leg:" << playerOneLegCount << endl;
			cout << setw(12) << "Tail:" << playerOneTailCount << endl << endl;

			// COMPUTER'S TURN (Player Two)
			if (computerBody != 0) // DON'T HAVE A BODY YET
			{
				switch (computerRoll)
				{
				case BODY:
					rolledPart = "BODY";
					computerBody--;
					computerBodyCount++;
					cout << "Player two roll is " << computerRoll << " " << rolledPart << endl;
					break;
				case HEAD:
					rolledPart = "HEAD";
					cout << "Player two roll is " << computerRoll << " " << rolledPart << ", must have BODY first" << endl;
					break;
				case WING:
					rolledPart = "WING";
					cout << "Player two roll is " << computerRoll << " " << rolledPart << ", must have BODY first" << endl;
					break;
				case LEG:
					rolledPart = "LEG";
					cout << "Player two roll is " << computerRoll << " " << rolledPart << ", must have BODY first" << endl;
					break;
				case EYE:
					rolledPart = "EYE";
					cout << "Player two roll is " << computerRoll << " " << rolledPart << ", must have BODY first" << endl;
					break;
				case TAIL:
					rolledPart = "TAIL";
					cout << "Player two roll is " << computerRoll << " " << rolledPart << ", must have BODY first" << endl;
				}
			}
			else if (computerHead != 0) // DON'T HAVE A HEAD YET
			{
				switch (computerRoll)
				{
				case BODY:
					rolledPart = "BODY";
					cout << "Player two roll is " << computerRoll << " duplicate " << rolledPart << endl;
					break;
				case HEAD:
					rolledPart = "HEAD";
					computerHead--;
					computerHeadCount++;
					cout << "Player two roll is " << computerRoll << " " << rolledPart << endl;
					break;
				case WING:
					rolledPart = "WING";
					if (computerWing == 0)
					{
						cout << "Player two roll is " << computerRoll << " duplicate " << rolledPart << endl;
					}
					else
					{
						computerWing--;
						computerWingCount++;
						cout << "Player two roll is " << computerRoll << " " << rolledPart << endl;
					}
					break;
				case LEG:
					rolledPart = "LEG";
					if (computerLeg == 0)
					{
						cout << "Player two roll is " << computerRoll << " duplicate " << rolledPart << endl;
					}
					else
					{
						computerLeg--;
						computerLegCount++;
						cout << "Player two roll is " << computerRoll << " " << rolledPart << endl;
					}
					break;
				case EYE:
					rolledPart = "EYE";
					cout << "Player two roll is " << computerRoll << " " << rolledPart << ", must have HEAD first" << endl;
					break;
				case TAIL:
					rolledPart = "TAIL";
					if (computerTail == 0)
					{
						cout << "Player two roll is " << computerRoll << " duplicate " << rolledPart << endl;
					}
					else
					{
						computerTail--;
						computerTailCount++;
						cout << "Player two roll is " << computerRoll << " " << rolledPart << endl;
					}
				}
			}
			else // HAVE A BODY AND A HEAD
			{
				switch (computerRoll)
				{
				case BODY:
					rolledPart = "BODY";
					cout << "Player two roll is " << computerRoll << " duplicate " << rolledPart << endl;
					break;
				case HEAD:
					rolledPart = "HEAD";
					cout << "Player two roll is " << computerRoll << " duplicate " << rolledPart << endl;
					break;
				case WING:
					rolledPart = "WING";
					if (computerWing == 0)
					{
						cout << "Player two roll is " << computerRoll << " duplicate " << rolledPart << endl;
					}
					else
					{
						computerWing--;
						computerWingCount++;
						cout << "Player two roll is " << computerRoll << " " << rolledPart << endl;
					}
					break;
				case LEG:
					rolledPart = "LEG";
					if (computerLeg == 0)
					{
						cout << "Player two roll is " << computerRoll << " duplicate " << rolledPart << endl;
					}
					else
					{
						computerLeg--;
						computerLegCount++;
						cout << "Player two roll is " << computerRoll << " " << rolledPart << endl;
					}
					break;
				case EYE:
					rolledPart = "EYE";
					if (computerEye == 0)
					{
						cout << "Player two roll is " << computerRoll << " duplicate " << rolledPart << endl;
					}
					else
					{
						computerEye--;
						computerEyeCount++;
						cout << "Player two roll is " << computerRoll << " " << rolledPart << endl;
					}
					break;
				case TAIL:
					rolledPart = "TAIL";
					if (computerTail == 0)
					{
						cout << "Player two roll is " << computerRoll << " duplicate " << rolledPart << endl;
					}
					else
					{
						computerTail--;
						computerTailCount++;
						cout << "Player two roll is " << computerRoll << " " << rolledPart << endl;
					}
				}
			}

			// Check if the computer has completed its Can-Cell (if completed, sum == 0)
			int computerCanCell = computerBody + computerHead + computerWing + computerLeg + computerEye + computerTail;

			if (computerCanCell == 0) // Completed Can-Cell!
			{
				cout << setw(19) << setfill('*') << "" << endl;
				cout << "Player two has won!" << endl;
				cout << right << setw(27) << setfill(' ') << "Game Results" << endl;
				cout << setw(42) << setfill('-') << "" << endl;
				cout << left << setw(23) << setfill(' ') << "Player 1 Inventory";
				cout << "Player 2 Inventory" << endl;
				cout << setw(12) << "Body:" << setw(11) << playerOneBodyCount << setw(12) << "Body:" << computerBodyCount << endl;
				cout << setw(12) << "Head:" << setw(11) << playerOneHeadCount << setw(12) << "Head:" << computerHeadCount << endl;
				cout << setw(12) << "Eye:" << setw(11) << playerOneEyeCount << setw(12) << "Eye:" << computerEyeCount << endl;
				cout << setw(12) << "Wing:" << setw(11) << playerOneWingCount << setw(12) << "Wing:" << computerWingCount << endl;
				cout << setw(12) << "Leg:" << setw(11) << playerOneLegCount << setw(12) << "Leg:" << computerLegCount << endl;
				cout << setw(12) << "Tail:" << setw(11) << playerOneTailCount << setw(12) << "Tail:" << computerTailCount << endl;
				break;
			}

			// Report the computer's inventory (Uncompleted Can-Cell)
			cout << setw(21) << setfill('-') << "" << endl;
			cout << "Player 2 Inventory" << endl;
			cout << left << setw(12) << setfill(' ') << "Body:" << computerBodyCount << endl;
			cout << setw(12) << "Head:" << computerHeadCount << endl;
			cout << setw(12) << "Eye:" << computerEyeCount << endl;
			cout << setw(12) << "Wing:" << computerWingCount << endl;
			cout << setw(12) << "Leg:" << computerLegCount << endl;
			cout << setw(12) << "Tail:" << computerTailCount << endl << endl;

			roundCount++; // Keep track of which round we're going into
		}

	}
	else if (silentMode) // SILENT MODE
	{
		// Initialize a random seed
		srand((unsigned int)time(NULL));

		// Silent mode header
		cout << endl;
		cout << right << setw(30) << setfill('<') << " Silent Mode Active " << setw(13) << setfill('>') << "" << endl;

		// Forever loop only broken when all the Can-Cell parts have been collected
		while (true)
		{
			// Round header
			cout << setw(16) << setfill('#') << "" << endl;
			cout << "Round # " << roundCount << endl << endl;

			roll = rand() % 6 + 1; // Player's Roll (Keeps our roll integers between 1 and 6, inclusive.)
			computerRoll = rand() % 6 + 1; // Computer's roll

			if (body != 0) // DON'T HAVE A BODY YET
			{
				switch (roll)
				{
				case BODY:
					rolledPart = "BODY";
					body--;
					playerOneBodyCount++;
					cout << "Player one roll is " << rolledPart << endl;
					break;
				case HEAD:
					rolledPart = "HEAD";
					cout << "Player one roll is " << rolledPart << ", must have BODY first" << endl;
					break;
				case WING:
					rolledPart = "WING";
					cout << "Player one roll is " << rolledPart << ", must have BODY first" << endl;
					break;
				case LEG:
					rolledPart = "LEG";
					cout << "Player one roll is " << rolledPart << ", must have BODY first" << endl;
					break;
				case EYE:
					rolledPart = "EYE";
					cout << "Player one roll is " << rolledPart << ", must have BODY first" << endl;
					break;
				case TAIL:
					rolledPart = "TAIL";
					cout << "Player one roll is " << rolledPart << ", must have BODY first" << endl;
				}
			}
			else if (head != 0) // DON'T HAVE A HEAD YET
			{
				switch (roll)
				{
				case BODY:
					rolledPart = "BODY";
					cout << "Player one roll is duplicate " << rolledPart << endl;
					break;
				case HEAD:
					rolledPart = "HEAD";
					head--;
					playerOneHeadCount++;
					cout << "Player one roll is " << rolledPart << endl;
					break;
				case WING:
					rolledPart = "WING";
					if (wing == 0)
					{
						cout << "Player one roll is duplicate " << rolledPart << endl;
					}
					else
					{
						wing--;
						playerOneWingCount++;
						cout << "Player one roll is " << rolledPart << endl;
					}
					break;
				case LEG:
					rolledPart = "LEG";
					if (leg == 0)
					{
						cout << "Player one roll is duplicate " << rolledPart << endl;
					}
					else
					{
						leg--;
						playerOneLegCount++;
						cout << "Player one roll is " << rolledPart << endl;
					}
					break;
				case EYE:
					rolledPart = "EYE";
					cout << "Player one roll is " << rolledPart << ", must have HEAD first" << endl;
					break;
				case TAIL:
					rolledPart = "TAIL";
					if (tail == 0)
					{
						cout << "Player one roll is duplicate " << rolledPart << endl;
					}
					else
					{
						tail--;
						playerOneTailCount++;
						cout << "Player one roll is " << rolledPart << endl;
					}
				}
			}
			else // HAS A BODY AND A HEAD
			{
				switch (roll)
				{
				case BODY:
					rolledPart = "BODY";
					cout << "Player one roll is duplicate " << rolledPart << endl;
					break;
				case HEAD:
					rolledPart = "HEAD";
					cout << "Player one roll is duplicate " << rolledPart << endl;
					break;
				case WING:
					rolledPart = "WING";
					if (wing == 0)
					{
						cout << "Player one roll is duplicate " << rolledPart << endl;
					}
					else
					{
						wing--;
						playerOneWingCount++;
						cout << "Player one roll is " << rolledPart << endl;
					}
					break;
				case LEG:
					rolledPart = "LEG";
					if (leg == 0)
					{
						cout << "Player one roll is duplicate " << rolledPart << endl;
					}
					else
					{
						leg--;
						playerOneLegCount++;
						cout << "Player one roll is " << rolledPart << endl;
					}
					break;
				case EYE:
					rolledPart = "EYE";
					if (eye == 0)
					{
						cout << "Player one roll is duplicate " << rolledPart << endl;
					}
					else
					{
						eye--;
						playerOneEyeCount++;
						cout << "Player one roll is " << rolledPart << endl;
					}
					break;
				case TAIL:
					rolledPart = "TAIL";
					if (tail == 0)
					{
						cout << "Player one roll is duplicate " << rolledPart << endl;
					}
					else
					{
						tail--;
						playerOneTailCount++;
						cout << "Player one roll is " << rolledPart << endl;
					}
				}
			}

			// Check if the player has completed their Can-Cell (if completed, sum == 0)
			int playerCanCell = body + head + wing + leg + eye + tail;

			if (playerCanCell == 0) // Completed Can-Cell!
			{
				cout << setw(19) << setfill('*') << "" << endl;
				cout << "Player one has won!" << endl;
				cout << right << setw(27) << setfill(' ') << "Game Results" << endl;
				cout << setw(42) << setfill('-') << "" << endl;
				cout << left << setw(23) << setfill(' ') << "Player 1 Inventory";
				cout << "Player 2 Inventory" << endl;
				cout << setw(12) << "Body:" << setw(11) << playerOneBodyCount << setw(12) << "Body:" << computerBodyCount << endl;
				cout << setw(12) << "Head:" << setw(11) << playerOneHeadCount << setw(12) << "Head:" << computerHeadCount << endl;
				cout << setw(12) << "Eye:" << setw(11) << playerOneEyeCount << setw(12) << "Eye:" << computerEyeCount << endl;
				cout << setw(12) << "Wing:" << setw(11) << playerOneWingCount << setw(12) << "Wing:" << computerWingCount << endl;
				cout << setw(12) << "Leg:" << setw(11) << playerOneLegCount << setw(12) << "Leg:" << computerLegCount << endl;
				cout << setw(12) << "Tail:" << setw(11) << playerOneTailCount << setw(12) << "Tail:" << computerTailCount << endl;
				break;
			}

			// COMPUTER'S TURN (Player Two)
			if (computerBody != 0) // DON'T HAVE A BODY YET
			{
				switch (computerRoll)
				{
				case BODY:
					rolledPart = "BODY";
					computerBody--;
					computerBodyCount++;
					cout << "Player two roll is " << rolledPart << endl;
					break;
				case HEAD:
					rolledPart = "HEAD";
					cout << "Player two roll is " << rolledPart << ", must have BODY first" << endl;
					break;
				case WING:
					rolledPart = "WING";
					cout << "Player two roll is " << rolledPart << ", must have BODY first" << endl;
					break;
				case LEG:
					rolledPart = "LEG";
					cout << "Player two roll is " << rolledPart << ", must have BODY first" << endl;
					break;
				case EYE:
					rolledPart = "EYE";
					cout << "Player two roll is " << rolledPart << ", must have BODY first" << endl;
					break;
				case TAIL:
					rolledPart = "TAIL";
					cout << "Player two roll is " << rolledPart << ", must have BODY first" << endl;
				}
			}
			else if (computerHead != 0) // DON'T HAVE A HEAD YET
			{
				switch (computerRoll)
				{
				case BODY:
					rolledPart = "BODY";
					cout << "Player two roll is duplicate " << rolledPart << endl;
					break;
				case HEAD:
					rolledPart = "HEAD";
					computerHead--;
					computerHeadCount++;
					cout << "Player two roll is " << rolledPart << endl;
					break;
				case WING:
					rolledPart = "WING";
					if (computerWing == 0)
					{
						cout << "Player two roll is duplicate " << rolledPart << endl;
					}
					else
					{
						computerWing--;
						computerWingCount++;
						cout << "Player two roll is " << rolledPart << endl;
					}
					break;
				case LEG:
					rolledPart = "LEG";
					if (computerLeg == 0)
					{
						cout << "Player two roll is duplicate " << rolledPart << endl;
					}
					else
					{
						computerLeg--;
						computerLegCount++;
						cout << "Player two roll is " << rolledPart << endl;
					}
					break;
				case EYE:
					rolledPart = "EYE";
					cout << "Player two roll is " << rolledPart << ", must have HEAD first" << endl;
					break;
				case TAIL:
					rolledPart = "TAIL";
					if (computerTail == 0)
					{
						cout << "Player two roll is duplicate " << rolledPart << endl;
					}
					else
					{
						computerTail--;
						computerTailCount++;
						cout << "Player two roll is " << rolledPart << endl;
					}
				}
			}
			else // HAVE A BODY AND A HEAD
			{
				switch (computerRoll)
				{
				case BODY:
					rolledPart = "BODY";
					cout << "Player two roll is duplicate " << rolledPart << endl;
					break;
				case HEAD:
					rolledPart = "HEAD";
					cout << "Player two roll is duplicate " << rolledPart << endl;
					break;
				case WING:
					rolledPart = "WING";
					if (computerWing == 0)
					{
						cout << "Player two roll is duplicate " << rolledPart << endl;
					}
					else
					{
						computerWing--;
						computerWingCount++;
						cout << "Player two roll is " << rolledPart << endl;
					}
					break;
				case LEG:
					rolledPart = "LEG";
					if (computerLeg == 0)
					{
						cout << "Player two roll is duplicate " << rolledPart << endl;
					}
					else
					{
						computerLeg--;
						computerLegCount++;
						cout << "Player two roll is " << rolledPart << endl;
					}
					break;
				case EYE:
					rolledPart = "EYE";
					if (computerEye == 0)
					{
						cout << "Player two roll is duplicate " << rolledPart << endl;
					}
					else
					{
						computerEye--;
						computerEyeCount++;
						cout << "Player two roll is " << rolledPart << endl;
					}
					break;
				case TAIL:
					rolledPart = "TAIL";
					if (computerTail == 0)
					{
						cout << "Player two roll is duplicate " << rolledPart << endl;
					}
					else
					{
						computerTail--;
						computerTailCount++;
						cout << "Player two roll is " << rolledPart << endl;
					}
				}
			}

			// Check if the computer has completed its Can-Cell (if completed, sum == 0)
			int computerCanCell = computerBody + computerHead + computerWing + computerLeg + computerEye + computerTail;

			if (computerCanCell == 0) // Completed Can-Cell!
			{
				cout << setw(19) << setfill('*') << "" << endl;
				cout << "Player two has won!" << endl;
				cout << right << setw(27) << setfill(' ') << "Game Results" << endl;
				cout << setw(42) << setfill('-') << "" << endl;
				cout << left << setw(23) << setfill(' ') << "Player 1 Inventory";
				cout << "Player 2 Inventory" << endl;
				cout << setw(12) << "Body:" << setw(11) << playerOneBodyCount << setw(12) << "Body:" << computerBodyCount << endl;
				cout << setw(12) << "Head:" << setw(11) << playerOneHeadCount << setw(12) << "Head:" << computerHeadCount << endl;
				cout << setw(12) << "Eye:" << setw(11) << playerOneEyeCount << setw(12) << "Eye:" << computerEyeCount << endl;
				cout << setw(12) << "Wing:" << setw(11) << playerOneWingCount << setw(12) << "Wing:" << computerWingCount << endl;
				cout << setw(12) << "Leg:" << setw(11) << playerOneLegCount << setw(12) << "Leg:" << computerLegCount << endl;
				cout << setw(12) << "Tail:" << setw(11) << playerOneTailCount << setw(12) << "Tail:" << computerTailCount << endl;
				break;
			}

			roundCount++; // Keep track of which round we're going into
		}
	}
	else // INVALID GAME MODE
	{
		cout << "\nThat's not a valid game mode!\nUse \"debug\" or \"silent\" to change your game mode." << endl;
		return 0;
	}

	return 0;
}