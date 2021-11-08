// Author - Andrius Šukys. Originally written on 2021-10-11. Last patched on 2021-10-24.

// The program determines if the number entered is prime. If it is not, two prime numbers closest to the given are found.

// Needed libraries
#include <stdio.h>
#include <ctype.h>
#include <math.h>

int main()
{
    // Variables for calculations
    int number, divisors; // Entered number, amount of divisors
    int number_bigger, number_smaller; // A number that's bigger/smaller than number
    int number_bigger_divisors, number_smaller_divisors; // The amount of divisors that bigger/smaller number has
    int number_bigger_distance, number_smaller_distance; // The distance between the given and closest prime number, it being either bigger or smaller

    // Output when the program starts. Says what the program does, when it ends and how the input should be given
    printf("The program determines if the number entered is prime.\n");
    printf("If it is not, two prime numbers closest to the given are found.\n");
    printf("---------------------------------------------------------------\n");
    printf("The program ends when 0 is entered.\n");
    printf("------------------------------------------------------------------------------------------------\n");
    printf("Enter integer non-negative numbers separated by whitespace. ");
    printf("A number can be up to 9 digits long.\n\n");

    // Starting an infinite loop that lets user input infinite amount of numbers until 0 is entered
    while (1)
    {
        // Input validation
        int scan_number = scanf("%9d", &number);
        char char_after_number = getchar();
        while((scan_number == 0) || (!isspace(char_after_number)) || (number < 0))
        {
            printf("Invalid input.\n");

            while(!isspace(char_after_number))
                char_after_number = getchar();

            scan_number = scanf("%9d", &number);
            char_after_number = getchar();
        }

        // If the entered number is 0, the infinite loop ends
        if(number == 0)
            break;

        // If the number is equal to 1, an appropriate output is given
        if(number == 1)
        {
            printf("%d is neither a prime nor a composite number.\n", number);
            continue;
        }

        // Calculating the amount of divisors of the given number
        // Every positive integer (excluding 1 that was addressed before) has at least 2 divisors  - the number itself and 1

        divisors = 2;

        // Counting the amount of divisors of the number (starting from 2 because 1 is skipped and going up to sqrt(number))
        for(int i = 2; i <= sqrt(number); ++i)
        {
            // If the given number can be divided by i without remainder, the amount of divisors increases by one
            if(number % i == 0)
            {
                divisors++;
            }
        }

        // If the number has 2 divisors, it's a prime number, the message gets printed
        if(divisors == 2)
        {
            printf("%d is a prime number.\n", number);
        }

        // If the number has more than 2 divisors, it's a composite number, so the program has to search for closest prime numbers
        if(divisors > 2)
        {
            // Smaller number is a number decreased by 1, bigger number is a number increased by 1
            number_bigger = number + 1;
            number_smaller = number - 1;

            // Divisors for bigger and smaller numbers are set to 2, distances from the given number are set to 1
            number_bigger_divisors = 2;
            number_smaller_divisors = 2;
            number_bigger_distance = 1;
            number_smaller_distance = 1;

            // Checking how many divisors does the bigger number have, counting the distance from original given number. It goes on until a prime number is found
            for(int i = 2; i <= sqrt(number_bigger); ++i)
            {
                if(number_bigger % i == 0)
                    number_bigger_divisors++;
                // If the amount of divisors is bigger than two, the bigger number is increased, the amount of divisors is set to 2, distance is increased by one
                if(number_bigger_divisors > 2)
                {
                    number_bigger++;
                    number_bigger_divisors = 2;
                    number_bigger_distance++;
                    i = 1;
                    continue;
                }
            }

            // Checking how many divisors does the smaller number have, counting the distance from original given number. It goes on until a prime number is found
            for(int i = 2; i <= sqrt(number_smaller); ++i)
            {
                if(number_smaller % i == 0)
                    number_smaller_divisors++;
                // If the amount of divisors is bigger than two, the smaller number is decreased, the amount of divisors is set to 2, distance is increased by one
                if(number_smaller_divisors > 2)
                {
                    number_smaller--;
                    number_smaller_divisors = 2;
                    number_smaller_distance++;
                    i = 1;
                    continue;
                }
            }

            // If the program does not have to terminate (user doesn't input 0), an appropriate output is given depending on the distance from the original given number
            if(number != 0)
            {
                if(number_smaller_distance == number_bigger_distance)
                    printf("%d is a composite number. The closest prime numbers are %d and %d.\n", number, number_smaller, number_bigger);
                if(number_smaller_distance > number_bigger_distance)
                    printf("%d is a composite number. The closest prime number is %d.\n", number, number_bigger);
                if(number_smaller_distance < number_bigger_distance)
                    printf("%d is a composite number. The closest prime number is %d.\n", number, number_smaller);
            }
        }
    }

    // When the program ends (user inputs 0), program notifies the user of termination.
    printf("----------------------------------------------------\n");
    printf("0 has been entered. The program has been terminated.\n");

    return 0;
}
