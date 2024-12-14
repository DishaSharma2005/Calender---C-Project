#include <stdio.h>

int main() {
    int year, month, days, startday;

    printf("Enter the year: ");
    scanf("%d", &year);

    printf("Enter the month (1-12): ");
    scanf("%d", &month);

    // Days in each month
    int Month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Check if the year is a leap year and adjust February accordingly
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        Month[1] = 29;  // February has 29 days in a leap year
    }

    // Validate the month input
    if (month < 1 || month > 12) {
        printf("Invalid Month Entered !!!!\n");
        return 0;  // Exit the program if month is invalid
    }

    days = Month[month - 1];  // Get the number of days for the given month

    // Calculate the starting day of the month using Zeller's Congruence formula for the 1st day of the given month
    int d = 1, m = month, y = year;

    // Adjust months and year for Zeller's formula (January and February treated as 13 and 14 of the previous year)
    if (m <= 2) {
        m += 12;
        y -= 1;
    }

    // Zeller's Congruence formula to calculate the day of the week (0=Saturday, 1=Sunday, etc.)
    startday = (d + (13 * (m + 1)) / 5 + y + (y / 4) - (y / 100) + (y / 400)) % 7;

    // Adjust for the fact that Zeller's formula considers Saturday as 0, Sunday as 1, ..., Friday as 6
    startday = (startday + 6) % 7;  // Adjust so 0=Sunday, 1=Monday, ..., 6=Friday

    // Printing the calendar
    printf("\n\n      Month: %d  Year: %d\n", month, year);
    printf("Sun Mon Tue  Wed Thu Fri Sat\n");

    // Printing spaces before the first day of the month
    for (int i = 0; i < startday; i++) {
        printf("    ");  // Four spaces for alignment
    }

    // Print all the days of the month
    for (int day = 1; day <= days; day++) {
        printf("%3d ", day);  // Print the day with 3 characters width

        // Move to the next line after 7 days in a week
        if ((day + startday) % 7 == 0) {
            printf("\n");
        }
    }

    printf("\n"); // Add a final newline for neatness
    return 0;
}
