#include <stdio.h>
#include <stdint.h>

// Doomsday Algorithm 
struct DoomsDays {
    int day;    //Member Day variable
    int month;  //Member Month variable
};

// Find anchor function
int find_anchor(int year, int anchor_day[])
{
    int divided = year % 100;
    // How many times 12 fits in last 2 digits of year
    int step1 = divided / 12;
    // Difference between the two last digits of the year number and the product of the multiples of 12 from step 1
    int step2 = divided - (12 * step1);
    // How many times 4 fit into result of step 2
    int step3 = step2 / 4;
    // Anchor day of century
    int anchor = year / 100;
    // For loop to check anchor day of century
    for(int i = 0; i < 9; i++)
    {
        if(anchor == anchor_day[4])
        {
            anchor = 2;
        }
        else if(anchor == anchor_day[3])
        {
            anchor = 3;
        }
        else if(anchor == anchor_day[2])
        {
            anchor = 5;
        }
    }
    // Sum of all steps
    int final = step1 + step2 + step3 + anchor;
    // Return final result
    return final;
}

int main()
{
    int day;
    int month;
    int year;
    int doom;
    char user_input;
    // Anchor days - array 
    int century_anchor_days[9] = {16,17,18,19,20,21,22,23,24};
    // Struct days
    struct DoomsDays arrayDates[12] = {
        {3, 1},
        {28, 2},
        {7, 3},
        {4, 4},
        {9, 5},
        {6, 6},
        {11, 7},
        {8, 8},
        {5, 9},
        {10, 10},
        {7, 11},
        {12, 12}
    };

    const char *daysofweek[] = {
        "Sunday", "Monday", "Tuesday", "Wednesday", "Thurday", "Friday", "Saturday"
    };
    
    do
    {
        // Enter a day - input
        printf("Enter a date (DD/MM/YYYY): ");
        scanf("%d/%d/%d", &day, &month, &year);
        // find anchor function
        int anchor_day = find_anchor(year, century_anchor_days);
        // loop to substract 7 from result 
        while(anchor_day >= 7)
        {
            anchor_day -= 7;
        }

        for(int i = 0; i < 12; i++)
        {
            struct DoomsDays currentArray = arrayDates[i];
            intptr_t firstElement = currentArray.day;
            firstElement = (intptr_t)daysofweek[anchor_day];
        }

        int doomsday;
        int secondElement;

        for (int j = 0; j < 12; j++)
        {
            struct DoomsDays currentArray = arrayDates[j];
            secondElement = currentArray.month;

            if(month == secondElement)
            {
                doomsday = currentArray.day;
            }
        }

        int final_result = (anchor_day + (day - doomsday) + 35) % 7;
        printf("The day of the week is %s\n", daysofweek[final_result]);

        printf("Press -y- if you want to repeat: ");
        scanf(" %c", &user_input);

    } while (user_input == 'y');

    return 0;
}