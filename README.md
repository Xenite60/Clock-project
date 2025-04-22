# Clock-project
A program that allows a user to change and display time in both 12-hour and 24-hour formats. The main problem this program solves is simulating real-time clock behavior and wrapping values like the hours resetting after 23, and giving users a simple way to understand time representation and class design in C++.

The time formatting and double display logic were handled particularly well. The displayClocks() function cleanly seperates the 12-hour and 24-hour formatting, including the AM/PM conversion logic and formatted output using setw() and setfill() that makes it more user-friendly and easy-to-read.

Improving the input validation in main() would make the program more secure like checking for a non-integer or out-of-range input. Also, seoerating the UI more clearly from the logic would improve its maintainability.

Handling the time wrap around and properly converting 24-hour to 12-hour format with the correct AM/PM indicators was pretty tricky to do. I eventually solved this by breaking down the problem into if-else conditions and manually testing some time inputs like 00:00:00 and 12:00:00. 

I learned more about object oriented design by using classes and encapsulating related data and functions. I also learned about input handling and controling the flow. Thinking through the program's logic step-by-step ehlped me to learn more about debugging and logical reasoning. 

I used descriptive variable and function names, and grouped related logic into functions like displayMenu() and addHour(), and also followed consistent formatting and indentations. I added comments throughout the code that explains each part, making it easier for others to understand and modify. 
