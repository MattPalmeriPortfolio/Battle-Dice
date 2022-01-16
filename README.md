# Battle-Dice

Contents
---------------------
* File Contents
* Introduction
* Algorithm
* Requirements

## File Contents
	
	Battle_Dice.cpp  (program file containing code)

## Introduction
Created a Battle Dice game to practice top-down design.
Program creates a dice battle program, using top-down design. Demonstrates ability to use multiple functions and create a program using top-down design in c++.
Written using Microsoft Visual Studio. 

## Algorithm

	1. greet user and receive input for monster's name
	2. roll for player's three hearts and enemy's three hearts
	3. begin player turn
		3a. prompt user to pick one of the enemy's hearts to roll against
		3b. roll and compare numbers
			3ba. if roll > heart, heart is destroyed; if roll < heart, nothing happens
			3bb. if roll = heart, prompt user to pick odds or evens; roll again - if matches guess, heart destroyed
		3c. end turn
	4. begin enemy turn
		4a. pick heart at random and roll against
		4b. roll and compare numbers
			4ba. if roll = heart, randomly pick odds or evens and roll again
		4c. end turn
	5. loop until all hearts of player or enemy are destroyed
	6. prompt user to continue

## Requirements
No requirements or modules needed for running this program.
