// File Name: assign6_rtd25.cpp
//
// Author: Rex Davis
// Date: 4/2/2018
// Assignment Number: 6
// CS 1428.302 Spring 2018
// Instructor: Jill Seaman

/* Description: Program simulates a vending machine, displays Names of soda,
costs, and units in the machine. */

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct Soda
{
    string DrinkName;
    double DrinkCost;
    int NumberOfUnits;
};
/*machineInfo: defines the soda names, cost, and how many units of each Soda
are in the Soda machine. */
void machineInfo(Soda inventory[5])
{
  const int numberOfDrinks = 8;

    inventory[0].DrinkName = "Coke (can)";
    inventory[0].DrinkCost = 0.75;
    inventory[0].NumberOfUnits = numberOfDrinks;
    inventory[1].DrinkName = "Coke (bottle)";
    inventory[1].DrinkCost = 1.25;
    inventory[1].NumberOfUnits = numberOfDrinks;
    inventory[2].DrinkName = "Mountain Dew (can)";
    inventory[2].DrinkCost = 0.75;
    inventory[2].NumberOfUnits = numberOfDrinks;
    inventory[3].DrinkName = "Water";
    inventory[3].DrinkCost = 1.25;
    inventory[3].NumberOfUnits = numberOfDrinks;
    inventory[4].DrinkName = "Full Throttle";
    inventory[4].DrinkCost = 2.00;
    inventory[4].NumberOfUnits = numberOfDrinks;
}

/* screenOptions: contains the information that is displayed onto the screen
for the user to then select which soda they would like to purchase. */
void screenOptions(int &drinkChoice)
{
    cout << "1. Coke (can)" << endl;
    cout << "2. Coke (bottle)" << endl;
    cout << "3. Moutain Dew (can)" << endl;
    cout << "4. Water" << endl;
    cout << "5. Full Throttle" << endl;
    cout << "6. Quit the Program" << endl;
    cout << " " << endl;
    cout << "Enter your choice: ";
    cin >> drinkChoice;

}

/* costAndUnits: lets the user know if the soda they selected is out, OR
lets them know how much the soda is going to cost. */
void costAndUnits(Soda inventory[5], int & drinkChoice, double &total)
{
//Since arrays start at 0, this corrects that issue.
int arrayCorrect = 1;

// If statement that checks to make sure the selected soda is in stock.
if (inventory[drinkChoice - arrayCorrect].NumberOfUnits <= 0 && drinkChoice !=6)
  {
    cout << "That choice is sold out." << endl;
    cout << " " << endl;
  }

/* Else if statement that is executed IF the soda is in stock, then lets the
user know how much the soda selected is going to cost. */
else if (drinkChoice >= 1 && drinkChoice <=5)
{
  cout << "The cost is: $" << inventory[drinkChoice - arrayCorrect].DrinkCost
  << endl;
  cout << " " << endl;

  total+=inventory[drinkChoice - arrayCorrect].DrinkCost;
  inventory[drinkChoice - arrayCorrect].NumberOfUnits--;
}
}

/* programEnding: contains the program ending, as in, it is
the total amount of money the machine earned during so said transaction, and
also how many units of each soda are left in the machine. */
void programEnding(Soda inventory[5], int & drinkChoice, double &total)
{
int userChoice = 5;
if (drinkChoice == 6)
{
  cout << "Units Remainings: "  << endl;

      // Loop prints out each soda for the user to see.
      for (int i = 0; i < userChoice; i++)
  {
  cout << left << setw(20) << inventory[i].DrinkName<<" "
   << inventory[i].NumberOfUnits << endl;

  }

// displays the total amount of money that the machine accumliated.
  cout << "Amount earned: $" << fixed << setprecision(2) << total << endl;
  return ;
}
}

int main ()
{
  int drinkChoice;
  double total = 0;
  int userChoice = 41;
  Soda inventory[5];

//Calls the functions to display, calculate, and run whatever the user enters.
machineInfo(inventory);

// For loop allows for the the program to be executed as many times as the user
// would like, and or the machine runs out of units.
for (int i = 0; i < userChoice; i++)
{
  screenOptions(drinkChoice);
  costAndUnits(inventory,drinkChoice,total);

// if statement that ends the program when the user press's '6', then displays
// the units left and the total earnings while the program was run.
  if(drinkChoice == 6){
    programEnding(inventory, drinkChoice,total);
    break;
  }

}
}
