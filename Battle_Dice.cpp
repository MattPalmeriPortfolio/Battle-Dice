#include <iostream>
#include <ctime>
#include <string>
//declare constants
const int DICE_SIZE = 6;
//declare functions
int rollDice();
//randomly rolls a dice and returns the result
void getHearts(int& heart1, int& heart2, int& heart3);
//precondition: provided a set of three heart variables
//postcondition: randomly determines the value of each heart variable
void playerTurn(int enemy1, int enemy2, int enemy3, bool& enemy1alive, bool& enemy2alive, bool& enemy3alive);
//precondition: params correspond to enemy hearts 1, 2, and 3; at least one enemy heart is alive
//postcondition: prompts player to attack a living heart and checks the result of the attack,
//changing enemyalive params as necessary
void enemyTurn(int player1, int player2, int player3, bool& player1alive, bool& player2alive, bool& player3alive);
//precondition: params correspond to player hearts 1, 2, and 3; at least one player heart is alive
//postcondition: runs the enemy's turn in a round of dice battle, attacking the first heart still alive
//and changing playeralive params as necessary
bool heartAttack(int attack, int heart);
//computes whether an enemy attack kills a heart; if it does, returns true, else returns false
bool playerAttack(int attack, int heart);
//computes whether a player attack kills a heart, and prompts them to choose odds or evens if the attack and heart ties.
bool promptContinue();
//precondition: program is intended to end or continue based on user decision
//postcondition: prompts user whether to continue the program; returns true if they do, false if they don't

//main
int main()
{
	using namespace std;
	//seed random
	srand(time(0));
	//initialize variables
	string playerMonster, enemyMonster = "DOMINITATOR";
	//greet user and receive initial input
	cout << "Welcome to the Monstrous Monster R-R-R-R-RUUUUUMMMMBBBBLLLLLEEEEEEEEEEE\nEnter the name of your monster: ";
	cin >> playerMonster;
	cout << "Today's fight: " << playerMonster << " versus the mighty " << enemyMonster << "!!!\n";
	//begin main program loop
	do
	{
		cout << "LET THE FIGHT BEGIN\n";
		//initialize variables for single fight
		int player1, player2, player3, enemy1, enemy2, enemy3;
		bool player1alive(true), player2alive(true), player3alive(true), enemy1alive(true), enemy2alive(true), enemy3alive(true);
		bool playerwin = false, enemywin = false;
		getHearts(player1, player2, player3);
		getHearts(enemy1, enemy2, enemy3);
		//begin deathmatch
		while (playerwin == false && enemywin == false)
		{
			cout << "Your hearts: \n";
			if (player1alive)
				cout << "Heart 1: " << player1 << " ";
			if (player2alive)
				cout << "Heart 2: " << player2 << " ";
			if (player3alive)
				cout << "Heart 3: " << player3 << " ";
			cout << endl;
			playerTurn(enemy1, enemy2, enemy3, enemy1alive, enemy2alive, enemy3alive);
			if (enemy1alive == false && enemy2alive == false && enemy3alive == false) //if player wins
				playerwin = true;
			else
				enemyTurn(player1, player2, player3, player1alive, player2alive, player3alive);
			if (player1alive == false && player2alive == false && player3alive == false) //if enemy wins
				enemywin = true;
		}
		if (playerwin)
			cout << "And the winner is... " << playerMonster << "!!!!!\n";
		else //if enemy won
			cout << "And the winner is... " << enemyMonster << "!!!!!!\n";
	} while (promptContinue());

	return 0;
}

//define functions
int rollDice()
{
	return (rand() % DICE_SIZE) + 1;
}
void getHearts(int& heart1, int& heart2, int& heart3)
{
	heart1 = rollDice(); heart2 = rollDice(); heart3 = rollDice();
	return;
}
//uses iostream
void playerTurn(int enemy1, int enemy2, int enemy3, bool& enemy1alive, bool& enemy2alive, bool& enemy3alive)
{
	using namespace std;
	int whichHeart, attack = rollDice();
	if (enemy1alive)
		cout << "Enemy heart 1: " << enemy1 << " ";
	if (enemy2alive)
		cout << "Enemy heart 2: " << enemy2 << " ";
	if (enemy3alive)
		cout << "Enemy heart 3: " << enemy3 << " ";
	cout << "\n Choose a heart to attack:\n";
	cin >> whichHeart;
	switch (whichHeart)
	{
	case 1:
		cout << "Attacking heart 1. You rolled: " << attack << endl;
		enemy1alive = playerAttack(attack, enemy1);
		if (enemy1alive)
			cout << "The attack missed!\n";
		else
			cout << "The attack hit!\n";
		break;
	case 2:
		cout << "Attacking heart 2. You rolled: " << attack << endl;
		enemy2alive = playerAttack(attack, enemy2);
		if (enemy2alive)
			cout << "The attack missed!\n";
		else
			cout << "The attack hit!\n";
		break;
	case 3:
		cout << "Attacking heart 3. You rolled: " << attack << endl;
		enemy3alive = playerAttack(attack, enemy3);
		if (enemy3alive)
			cout << "The attack missed!\n";
		else
			cout << "The attack hit!\n";
		break;
	default:
		cout << "incorrect pick. turn skipped\n";
		break;
	}

	return;
}
//uses iostream
void enemyTurn(int player1, int player2, int player3, bool& player1alive, bool& player2alive, bool& player3alive)
{
	using namespace std;
	int whichHeart, attack;
	if (player1alive)
		whichHeart = 1;
	else if (player2alive)
		whichHeart = 2;
	else if (player3alive)
		whichHeart = 3;
	else
		whichHeart = 4;

	switch (whichHeart)
	{
	case 1:
		cout << "The enemy attacks heart 1!\n";
		attack = rollDice();
		player1alive = heartAttack(attack, player1);
		if (player1alive)
			cout << "The attack missed!\n";
		else
			cout << "The attack struck true!\n";
		break;
	case 2:
		cout << "The enemy attacks heart 2!\n";
		attack = rollDice();
		player2alive = heartAttack(attack, player2);
		if (player2alive)
			cout << "The attack missed!\n";
		else
			cout << "The attack struck true!\n";
		break;
	case 3:
		cout << "The enemy attacks heart 3!\n";
		attack = rollDice();
		player3alive = heartAttack(attack, player3);
		if (player3alive)
			cout << "The attack missed!\n";
		else
			cout << "The attack struck true!\n";
		break;
	default:
		cout << "incorrect pick. turn skipped\n";
		break;
	}

	return;
}
//uses iostream
bool heartAttack(int attack, int heart)
{
	if (attack == heart)
	{
		std::cout << "It's a tie!\n";
		int oddOrEven = (rand() % 2) + 1;
		if (oddOrEven == 1)
		{
			std::cout << "The enemy chooses odds!\n";
			if (rollDice() % 2 == 0)
				return true;
			else
				return false;
		}
		else //if evens
		{
			std::cout << "The enemy chooses evens!\n";
			if (rollDice() % 2 == 0)
				return false;
			else
				return true;
		}
	}
	else if (attack < heart)
		return true;
	else
		return false;
}
//uses iostream
bool playerAttack(int attack, int heart)
{
	using namespace std;
	if (attack == heart)
	{
		char oddOrEven;
		cout << "It's a tie!\n Odds or evens? O for odd, E for even\n";
		cin >> oddOrEven;
		if (oddOrEven == 'o' || oddOrEven == 'O')
		{
			cout << "Odds!\n";
			if (rollDice() % 2 == 0)
				return true;
			else
				return false;
		}
		else //if (oddOrEven == 'e' || oddOrEven == 'E')
		{
			std::cout << "Evens!\n";
			if (rollDice() % 2 != 0)
				return true;
			else
				return false;
		}
	}
	else if (attack < heart)
		return true;
	else
		return false;
}
//uses iostream
bool promptContinue()
{
	using namespace std;
	char prompt;
	cout << "Would you like to continue? Y to continue, N to end\n";
	cin >> prompt;
	if (prompt == 'Y' || prompt == 'y')
		return true;
	else
		return false;
}