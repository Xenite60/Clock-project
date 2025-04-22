/*
Trinity Spangler
March 23, 2025
*/

#include <iostream>
// Includes formatting functions like setw() and setfill()
#include <iomanip>

using namespace std;

// Define Clock class to handle the time operations
class Clock
{
private:
    // Stores the time in a 24 hour format
    int hour24, minute, second;

public:
    // Constructor to initialize the clock with the user entered time
    Clock(int h, int m, int s)
    {
        hour24 = h;
        minute = m;
        second = s;
    }

    // Function to add an hour and make sure that it wraps correctly in the 24 hour format
    void addHour()
    {
        hour24 = (hour24 + 1) % 24;
    }

    // Function to add a minute, resetting to 0 and adding an hour if needed
    void addMinute()
    {
        minute = (minute + 1) % 60; // keeps minutes within a range of 0-59
        // if minutes resets to 0, add an hour
        if (minute == 0)
        {
            addMinute();
        }
    }

    // Function to add a second, resetting to 0 and adding a minute if needed
    void addSecond()
    {
        second = (second + 1) % 60; // keeps seconds in a range of 0-59
        // if seconds resets to 0, add a minute
        if (second == 0)
        {
            addMinute();
        }
    }

    //  Function to display both clocks in 12 and 24 hour formats
    void displayClocks()
    {
        int hour12;      // stores the 12 hour format value
        string meridiem; // stores AM/PM indicator

        // Convert 24 hour to 12 hour format with AM/PM
        if (hour24 == 0)
        {
            hour12 = 12;
            meridiem = "AM";
        }
        else if (hour24 < 12)
        {
            hour12 = hour24;
            meridiem = "AM";
        }
        else if (hour24 == 12)
        {
            hour12 = 12;
            meridiem = "PM";
        }
        else
        {
            hour12 = hour24 - 12;
            meridiem = "PM";
        }

        // Print out both clocks side by side
        cout << "**************************   ***************************" << endl;
        cout << "*      12-Hour Clock     *   *      24-Hour Clock      *" << endl;
        cout << "*        " << setw(2) << setfill('0') << hour12 << ":"
             << setw(2) << minute << ":" << setw(2) << second << " " << meridiem
             << "     *     *       " << setw(2) << hour24 << ":"
             << setw(2) << minute << ":" << setw(2) << second << "      *" << endl;
        cout << "**************************   ***************************" << endl;
    }
};

// Function to display a user menu with 4 options
void displayMenu()
{
    cout << "***************************" << endl;
    cout << "* 1 - Add One Hour        *" << endl;
    cout << "* 2 - Add One Minute      *" << endl;
    cout << "* 3 - Add One Second      *" << endl;
    cout << "* 4 - Exit Program        *" << endl;
    cout << "***************************" << endl;
}

int main()
{
    Clock clock(15, 22, 1); // Create a Clock object initialized at 15:22:01
    int choice = 0;         // Variable to store the users input

    // While loop continues until user selects option 4
    while (choice != 4)
    {
        clock.displayClocks(); // Display current time on both clocks
        displayMenu();         // Show the menu options

        // Prompt the user for their choice
        cout << "Enter your choice: ";
        cin >> choice;

        // Execute the right action based on the user's choice
        if (choice == 1)
        {
            clock.addHour(); // adds an hour to both clocks
        }
        else if (choice == 2)
        {
            clock.addMinute(); // adds a minute to both clocks
        }
        else if (choice == 3)
        {
            clock.addSecond(); // adds a second to both clocks
        }
        else if (choice == 4)
        {
            cout << "Exiting the program..." << endl; // Displays an exit message
        }
        else
        {
            cout << "Invalid choice. Please enter a number from 1 to 4." << endl; // Error message for invalid input
        }
    }

    return 0;
}