////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  Copyright   (c) 2024 Inovation In Tech Limited . All rights reserved.     //
//  Author:                Abhay Soni                                         //
//  Project Discription :  Colored Squares Game Programming                   //
//  Project Category :     Mini Project                                       //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <algorithm>

using namespace std;

// Define an enum for different colours
enum Colour
{
    RED,
    GREEN,
    BLUE,
    YELLOW,
    PURPLE
};

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  Copyright   (c) 2024 Inovation In Tech Limited . All rights reserved.     //
//  Author:        Abhay Soni                                                 //
//  Function Name: generateRandomColor                                        //                                                                          //
//  Description:   Generate a random colour                                   //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

Colour generateRandomColor()
{
    return static_cast<Colour>(rand() % 5);
}

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  Copyright   (c) 2024 Inovation In Tech Limited . All rights reserved.     //
//  Author:        Abhay Soni                                                 //
//  Function Name: getColourName                                              //                                                                          //
//  Description:   this function returns string name of color                 //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////

string getColourName(Colour colour)
{
    switch (colour)
    {
    case RED:
        return "Red";
    case GREEN:
        return "Green";
    case BLUE:
        return "Blue";
    case YELLOW:
        return "Yellow";
    case PURPLE:
        return "Purple";
    default:
        return "Unknown colour";
    }
}

int main()
{
    srand(time(nullptr));

    Colour targetColour = generateRandomColor();
    Colour userColour;
    string guess;
    char choice;

    while (true)
    {
        // system("clear");
        cout << "************************************************************" << endl;
        cout << "Welcome to the Colored Squares Game!" << endl;
    here:
        cout << "Guess any colour from {Red, Green, Blue ,Yellow ,Purple}:  ";
        cin >> guess;

        // Convert input to uppercase
        transform(guess.begin(), guess.end(), guess.begin(), ::toupper);

        // convert colour string to enum
        if (guess == "RED")
            userColour = RED;
        else if (guess == "GREEN")
            userColour = GREEN;
        else if (guess == "BLUE")
            userColour = BLUE;
        else if (guess == "YELLOW")
            userColour = YELLOW;
        else if (guess == "PURPLE")
            userColour = PURPLE;
        else
        {
            cout << "Invalid colour : Do you again guess color(Y) or Exit(N) " << endl;
            cin >> choice;
            if (choice == 'Y' || choice == 'y')
                goto here;
            else
                break;
        }

        if (userColour == targetColour)
        {
            cout << "Congratulations! You guessed the right color." << endl;
            break;
        }
        else
        {
            cout << "Sorry, that's not the right color. Better luck Next Time" << endl;
            break;
        }
    }
    return 0;
}
