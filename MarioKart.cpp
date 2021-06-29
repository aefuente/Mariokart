/******************************************************************************
Spring 2021 Programming Foundations I
Author: Andre Fuentes
Date: March 1, 2021
Purpose: For this programming assignment, the objective is to become comfortable 
making functions in C++. You will be modifying an existing program: homework4b.cpp. 
Your task is to implement the seven functions:
1. getName
2. getVehicle
3. setVehicle
4. CheckWinnning
5. RandomBox
6. RacerStatus
7. ResetSpeed

The main function has already been implemented. As you begin to implement each
function, uncomment the respective function call in main.
*******************************************************************************/

#include <iostream>
#include <stdlib.h>
#include <string>
#include <iomanip>
#include <chrono>
#include <thread>

using namespace std;

//-------------------------------------------------------------------------------------------------
// Title:       Function 1
// Name:        getName.
// Parameters:  None 
// Returns:     string: the user's input
// Purpose:     This function welcomes the user, and promts the user to enter in their name.
//              after the user has entered their name reutrn their answer.
//-------------------------------------------------------------------------------------------------

string getName()
{
    string name;
    cout << "----------Welcome Racer----------" << endl << endl;
    cout << "What is your name?" << endl;
    cin >> name;
    cout << endl << "Welcome " << name << " to the race!" << endl << endl;
    return name;
}



//-------------------------------------------------------------------------------------------------
// Title:       Function 2
// Name:        getVehicle
// Parameters:  TRUCK_SPEED: integer, pass by value, a trucks speed.
//              TRUCK_CRASH: integer, pass by value, a trucks crash time when hit.
//              KART_SPEED:  integer, pass by value, a karts speed.
//              KART_CRASH:  integer, pass by value, a karts crash time when hit.
//              BIKE_SPEED:  integer, pass by value, a bikes speed.
//              BIKE_CRASH:  integer, pass by value, a bikes crash time when hit

// Returns:     integer: the choice of vehicle with integer options. 1: for truck 2: for Kart 3: for bike
// Purpose:     This function prompts the user with a menu that shows what the names of the vehicles and
//              the vehicles specifications. The function gets the users selection of vehicle
//              and performs error checking to ensure it returns integers: 1, 2, or 3.
//              
//-------------------------------------------------------------------------------------------------
int getVehicle(const int TRUCK_SPEED, const int TRUCK_CRASH, 
                 const int KART_SPEED, const int KART_CRASH, 
                 const int BIKE_SPEED, const int BIKE_CRASH)
{
    /*
     * Display a menu page and clearly specify specs
     */

    cout << "----------Welcome to the cart selection----------" << endl << endl;

    cout << "| Truck    |   Speed: " << TRUCK_SPEED << "    |   Crash time: " << TRUCK_CRASH << " |" << endl;
    cout << "| Kart     |   Speed: " << KART_SPEED  << "    |   Crash time: " << KART_CRASH  << " |" << endl;
    cout << "| Bike     |   Speed: " << BIKE_SPEED  << "    |   Crash time: " << BIKE_CRASH  << " |" << endl;
    cout << endl;
    cout << "Choose your cart wisely because they each have different stats" << endl;

    cout << "1. Truck" << endl;

    cout << "2. Kart" << endl;

    cout << "3. Bike" << endl << endl;

    string answer;
    cin >> answer;
    cout << endl;
    /*
     * Students must do error checking on menu selection
     */    
    int choice = stoi(answer);
    while (choice > 3 || choice < 1)
    {
        cout << "----------Welcome to the cart selection----------" << endl << endl;
        cout << "| Truck    |   Speed: " << TRUCK_SPEED << "    |   Crash time: " << TRUCK_CRASH << " |" << endl;
        cout << "| Kart     |   Speed: " << KART_SPEED  << "    |   Crash time: " << KART_CRASH  << " |" << endl;
        cout << "| Bike     |   Speed: " << BIKE_SPEED  << "    |   Crash time: " << BIKE_CRASH  << " |" << endl;

        cout << "Choose your cart wisely because they each have different stats" << endl;

        cout << "1. Truck" << endl;

        cout << "2. Kart" << endl;

        cout << "3. Bike" << endl;
        cin >> answer;
        choice = stoi(answer);
    }
    cout << endl;
    return choice;
}



//-------------------------------------------------------------------------------------------------
// Title:       Function 3
// Name:        setVehicle
// Parameters:  playerSpeed: integer, pass by reference, the players speed.
//              playerCrash: integer, pass by reference, the players time spent crashing when hit.
//              choice:      integer, pass by value, the users vehicle choice from previous function range (1-3).
//              TRUCK_SPEED: integer, pass by value, a trucks speed.
//              TRUCK_CRASH: integer, pass by value, a trucks crash time when hit.
//              KART_SPEED:  integer, pass by value, a karts speed.
//              KART_CRASH:  integer, pass by value, a karts crash time when hit.
//              BIKE_SPEED:  integer, pass by value, a bikes speed.               
//              BIKE_CRASH:  integer, pass by value, a bikes crash time when hit. 
// Returns:     void
// Purpose:     This function will utilize the choice returned by getVehicle and will set the 
//              specification of the playerSpeed and playerCrash to the vehical stats asssiciated
//              with the vehicle the user selected.
// If this is done correctly you will see when "Player Stats" is printed to console the
// numbers should not be 0.
//-------------------------------------------------------------------------------------------------
void setVehicle(int & playerSpeed, int & playerCrash, const int choice,
                   const int TRUCK_SPEED, const int TRUCK_CRASH,
                   const int KART_SPEED,  const int KART_CRASH,
                   const int BIKE_SPEED,  const int BIKE_CRASH )
{
    /*
     * This can be a switch or if statement.
     */
    switch(choice)
    {
        case 1:
            cout << "You have selected the truck with the stats..." << endl;
            cout << "Speed: " << TRUCK_SPEED << " Crashtime: " << TRUCK_CRASH << endl;
            playerSpeed = TRUCK_SPEED; 
            playerCrash = TRUCK_CRASH;
            break;
        case 2:
            cout << "You have selected the cart with the stats..." << endl;
            cout << "Speed: " << KART_SPEED << " Crashtime: " << KART_CRASH << endl;
            playerSpeed = KART_SPEED; 
            playerCrash = KART_CRASH;
            break;
        case 3:
            cout << "You have selected the bike with the stats..." << endl;
            cout << "Speed: " << BIKE_SPEED << " Crashtime: " << BIKE_CRASH << endl;
            playerSpeed = BIKE_SPEED; 
            playerCrash = BIKE_CRASH;
            break;
        default:
            cout << "You requested a selection that doesn't exist..." << endl;
            break;
    }

    cout << endl << endl;

}

//-------------------------------------------------------------------------------------------------
// Title:       Function 4
// Name:        CheckWinning
// Parameters:  racerProgres:  integer, pass by value, the players position on the race track range (0, 100) 
//              bowserProgres: integer, pass by value, bowsers position on the race track range (0, 100)
//              luigiProgres:  integer, pass by value, luigis position on the race track range (0, 100)
// Returns:     boolean: If any user has passed the finish line (the finsih line is when progress >= 100)
//                       return True
//                       If no user has passed the finish line return false.
// Purpose:     This function checks to see if a racer has passed the finsih line. 
//-------------------------------------------------------------------------------------------------

bool CheckWinning(const int racerProgress, const int bowserProgress, const int luigiProgress)
{
    return (racerProgress >= 100 || bowserProgress >= 100 || luigiProgress >= 100);
}




//-------------------------------------------------------------------------------------------------
// Title:       Function 5
// Name:        RandomBox
// Parameters:  None 
// Returns:     string: "shell", "banana", "mushroom", "nothing" 
// Purpose:     This function gives the user an item on the racecourse.This function has 
//              equal probability to randomly select any of the four items listed
//              above. Once an item is randomly picked return it.
//-------------------------------------------------------------------------------------------------

string RandomBox()
{
   int selection = (random() % 4) + 1;
   string item;
   /*
    * This can be a switch or an if statement
    */
   switch(selection)
   {
        case 1:
            item = "shell";
            break;
        case 2:
            item = "banana";
            break;
        case 3:
            item = "mushroom";
            break;
        default:
            item = "nothing";
            break;
    }

   return item;
}



//-------------------------------------------------------------------------------------------------
// Title:       Function 6
// Name:        RacerStatus
// Parameters:  name:  string,  pass by value, holds the racers name. 
//              speed: integer, pass by value, the speed the racer is currently going.
// Returns:     void
// Purpose:     This function prints a statement to console of the user's name, current speed,
//              and a "yes" or "no" if the user is stunned. 
//
// Note**       A users speed will be 0 if they are stunned.
//-------------------------------------------------------------------------------------------------
void RacerStatus(const string name, const int speed)
{
    string stun;
   if (speed == 0)
       stun = "yes";
   else
       stun = "no";

   cout << "---------- " << name << " status ----------" << endl;
   cout << "Speed: " << speed << " Stunned: " << stun << endl;

}


//-------------------------------------------------------------------------------------------------
// Title:       Function 7
// Name:        ResetSpeed
// Parameters:  racerSpeed:    integer, pass by reference, is the racers current speed.
//              bowserSpeed:   integer, pass by reference, is bowsers current speed.
//              luiguiSpeed:   integer, pass by reference, is luigi's current speed.
//              racerCarSpeed: integer, pass by value, the racers vehicle speed. 
//              TRUCK_SPEED:   integer, pass by value, the speed of a truck.
//              BIKE_SPEED:    integer, pass by value, the speed of a bike.
//
// Returns:     void
// Purpose:     This function fixes the bug when a user eats a mushroom, the speed is
//              changed for the entire game.The function checks to see if a racer is 
//              going faster than their vehicles speed. If they are going faster than
//              their vehicles speed set the racers speed to their vehicle speed.
//
// Note** racerSpeed has a normal speed of racerCarSpeed
// Note** bowserSpeed has a normal speed of TRUCK_SPEED
// Note** luigiSpeed has a normal speed of luigiSpeed
//-------------------------------------------------------------------------------------------------
void ResetSpeed(int & racerSpeed,  int & bowserSpeed,  int & luigiSpeed, 
                const int  racerCarSpeed, const int TRUCK_SPEED, const int BIKE_SPEED)
{

    if (racerSpeed > racerCarSpeed)
        racerSpeed = racerCarSpeed;

    if (bowserSpeed > TRUCK_SPEED)
        bowserSpeed = TRUCK_SPEED;

    if (luigiSpeed > BIKE_SPEED)
        luigiSpeed = BIKE_SPEED;

}





















/*
 * THIS IS SUPPLIED CODE DO NOT MODIFY AttemptDodge
 * Characters try to dodge abilities
 */
bool AttemptDodge(int & speed)
{
   bool dodge = false;
   if (speed != 0)
   {
      float myLuck = (1 / (speed/5.0)) * 100;
      float enemyLuck = random() % 100 + 50;
      dodge = (myLuck >= enemyLuck);
  }

  if (!dodge)
      speed = 0;
  return dodge;
}

/*
 * THIS IS SUPPLIED CODE DO NOT MODIFY StatusBar
 * Prints the progress of a racer with their
 * initial
 *
 */
void StatusBar(int & progress, const int speed, const char character)
{
    int barWidth = 100;

        cout << "[";
        int pos1 = progress;

        for (int i = 0; i < barWidth; ++i) 
        {
            if (i < pos1) cout << "=";
            else if (i == pos1) cout << character;
            else cout << " ";
        }

        if (progress < 100)
            cout << "] " << int(progress) << " %\n";
        else 
            cout << "] " << 100 << " %\n";
        // Increases the users progress as well 
        progress += speed;
}


/*
 * THIS IS SUPPLIED CODE DO NOT MODIFY GrabBox
 * Checks box locations to see if racer has passed one
 */
bool GrabBox(const int progress, const int speed)
{ 

    const int BOX_LOCATIONS[] = { 15, 25, 60, 75 };
    for (int i = 0; i < 4; i++)
    {

        if (progress >= BOX_LOCATIONS[i] && progress - speed < BOX_LOCATIONS[i])
        {
            return true;
        }

    }
    return false;
}


/*
 * THIS IS SUPPLIED CODE DO NOT MODIFY CheckCrash
 * Resets speed after spinout is done
 */

void CheckCrash(int & racerSpeed, int &  racerCrash, const int racerCarSpeed, const int racerCarCrash,
                  int & BOWSER_SPEED,  int & BOWSER_CRASH, const int TRUCK_SPEED, const int TRUCK_CRASH,
                  int & LUIGI_SPEED, int & LUIGI_CRASH, const int BIKE_SPEED, const int BIKE_CRASH)
{
    // If racers are spinning out
    // Decrease their counters
    if (racerSpeed == 0)
        racerCrash--;

    if (LUIGI_SPEED == 0)
        LUIGI_CRASH--;

    if (BOWSER_SPEED == 0)
        BOWSER_CRASH--;
    
    // If the racers spinout counter is 0
    // increase racers speed
    if (racerCrash <= 0)
    {
        racerSpeed = racerCarSpeed;
        racerCrash = racerCarCrash;
    }
    if (LUIGI_CRASH <= 0)
    {
        LUIGI_SPEED = BIKE_SPEED;
        LUIGI_CRASH = BIKE_CRASH;
    }
    if (BOWSER_CRASH <=0)
    {
        BOWSER_SPEED = TRUCK_SPEED;
        BOWSER_CRASH =  TRUCK_CRASH;
    }

}

/*
 * THIS IS SUPPLIED CODE DO NOT MODIFY WasHit
 * Notifies the user if a player was hit.
 */
void WasHit(const string name, const int racerSpeed, const int racerCrash, const int racerCarCrash)
{
    if (racerSpeed == 0 && racerCrash == racerCarCrash)
    {
        cout << name << " was hit!" << endl << endl;
    }
}


/*
 * THIS IS SUPPLIED CODE DO NOT MODIFY Ability
 * Racer uses its ability as soon as it is available
 */
void Ability(const int racerProgress, const int enemyOneProgress, const int enemyTwoProgress, 
            int & racerSpeed, int & enemyOneSpeed, int & enemyTwoSpeed, const string item)
{

    // Increases speed by ten on shell use
    if (item == "mushroom")
    {
        racerSpeed +=10;
    }

    // Tries to hit enemies with shell only if they are infront
    if (item == "shell")
    {
        if (enemyOneProgress > racerProgress)
        {
            if (AttemptDodge(enemyOneSpeed))
            {
                if (enemyTwoProgress > racerProgress)
                {
                    AttemptDodge(enemyTwoSpeed);
                }
            }
        }

        else if (enemyTwoProgress > racerProgress)
        {
            AttemptDodge(enemyTwoSpeed);
        }
        else
            cout << "No enemies in front to throw shell at" << endl << endl;

    }

    // Tries to hit enemies with banana only if they are behind
    if (item == "banana")
    {
        if (enemyOneProgress < racerProgress)
        {
            if (AttemptDodge(enemyOneSpeed))
            {
                if (enemyTwoProgress < racerProgress)
                {
                    AttemptDodge(enemyTwoSpeed);
                }
            }
        }
        else if (enemyTwoProgress < racerProgress)
        {
            AttemptDodge(enemyTwoSpeed);
        }
        else
            cout << "No enemies behind to throw banana at." << endl << endl;
    }
}



//-------------------------------------------------------------------------------------------------
// Title:       Main
//              The only editing that is necessary in the main function is to uncomment
//              code that is specified in the report. You should NOT need to make any
//              new variables or logic.
//-------------------------------------------------------------------------------------------------

int main()
{
    /*
     *  All of the variables before the "Function 1" comment
     *  are given and should NOT be modified
     */         
    const int BIKE_SPEED = 8;
    const int BIKE_CRASH = 3;

    const int KART_SPEED = 7;
    const int KART_CRASH = 2;

    const int TRUCK_SPEED = 6;
    const int TRUCK_CRASH = 1;



    int BOWSER_SPEED = TRUCK_SPEED;
    int BOWSER_CRASH  = TRUCK_CRASH;


    int LUIGI_SPEED = BIKE_SPEED;
    int LUIGI_CRASH = BIKE_CRASH;


    string racer = "p";

    int racerSpeed = 0; 
    int racerCrash = 0;


    // Function 1
    racer = getName();

    srandom(time(NULL));

    // Function 2
    int choice = getVehicle(TRUCK_SPEED, TRUCK_CRASH, KART_SPEED, KART_CRASH, BIKE_SPEED, BIKE_CRASH);
    
    // Function 3
    setVehicle(racerSpeed, racerCrash, choice, TRUCK_SPEED, TRUCK_CRASH, KART_SPEED, KART_CRASH, BIKE_SPEED, BIKE_CRASH);
    

    cout << endl; 
    cout << "|------------------------------|" << endl;
    cout << "|        Player Stats          |" << endl;
    cout << "|                              |" << endl;
    cout << "|   Speed: " << racerSpeed << "   Crash time: " << racerCrash << "   |" << endl;
    cout << "|------------------------------|" << endl << endl;


    
    const int racerCarSpeed = racerSpeed;
    const int racerCarCrash =  racerCrash;


    int racerProgress = 0;
    int bowserProgress = 0;
    int luigiProgress = 0;

    // Function 4
      
    while (!CheckWinning(racerProgress, bowserProgress, luigiProgress)) 
    {


        // Funtion 5
  
        if(GrabBox(racerProgress, racerSpeed))
        {
            string item = RandomBox();
            cout << racer << " has picked up a " << item << endl;
            Ability(racerProgress, bowserProgress, luigiProgress, racerSpeed, BOWSER_SPEED, LUIGI_SPEED, item);
        }

        if(GrabBox(bowserProgress, BOWSER_SPEED))
        {
            string item = RandomBox();
            cout << "Bowser " << "has picked up a " << item << endl;
            Ability(bowserProgress, racerProgress, luigiProgress, BOWSER_SPEED, racerSpeed, LUIGI_SPEED, item);

        }

        if(GrabBox(luigiProgress, LUIGI_SPEED))
        {
            string item = RandomBox();
            cout << "Luigi " << "has picked up a " << item << endl;
            Ability(luigiProgress, racerProgress, bowserProgress,  LUIGI_SPEED, racerSpeed,  BOWSER_SPEED, item);
        }

        cout << endl;
        WasHit(racer, racerSpeed, racerCrash, racerCarCrash);
        WasHit("Bowser", BOWSER_SPEED, BOWSER_CRASH, TRUCK_CRASH);
        WasHit("Luigi", LUIGI_SPEED, LUIGI_CRASH, BIKE_CRASH);
        


        // Function 6
        RacerStatus(racer, racerSpeed);
        RacerStatus("Bowser", BOWSER_SPEED);
        RacerStatus("Luigi", LUIGI_SPEED);

        cout << endl;
        
        StatusBar(racerProgress, racerSpeed, racer[0]);
        StatusBar(bowserProgress, BOWSER_SPEED, 'B');
        StatusBar(luigiProgress, LUIGI_SPEED, 'L');
        
        cout << endl << endl;
        
        // Function 7
        ResetSpeed(racerSpeed, BOWSER_SPEED, LUIGI_SPEED,  racerCarSpeed, TRUCK_SPEED, BIKE_SPEED);


        CheckCrash(racerSpeed, racerCrash, racerCarSpeed, racerCarCrash,
                     BOWSER_SPEED, BOWSER_CRASH, TRUCK_SPEED, TRUCK_CRASH,
                     LUIGI_SPEED, LUIGI_CRASH, BIKE_SPEED, BIKE_CRASH);

        this_thread::sleep_for(chrono::milliseconds(750));
    }
    

    StatusBar(racerProgress, 0, racer[0]);
    StatusBar(bowserProgress, 0, 'B');
    StatusBar(luigiProgress, 0, 'L'); 

    cout << endl << endl;
    cout << "--------------- The Winner is... ---------------" << endl << endl;
    if (racerProgress >= 100)
    {
        cout << racer;
    }
    else if (luigiProgress >= 100)
    {
        cout << "Luigi";
    }
    else if (bowserProgress >= 100)
    {
        cout << "Bowser";
    }
    else
        cout << "looks like we need to implement some tasks!" << endl;
}

