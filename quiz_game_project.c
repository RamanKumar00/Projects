#include <stdio.h>

int main() {
    int ans1, ans2, ans3, ans4, ans5, ans6, ans7, ans8, ans9, ans10;
    int point1 = 0, point2 = 0, point3 = 0, point4 = 0, point5 = 0, point6 = 0, point7 = 0, point8 = 0, point9 = 0, point10 = 0;
    int total = 0;

    printf("Welcome to the C Programming Quiz!\n");
    printf("Press 7 to start the quiz or 'q' to quit: ");
    
    char choice;
    scanf(" %c", &choice);

    if (choice == '7') {
        printf("\nThe quiz has started.\n");

        // Question 1
        printf("\n1. Who is the father of C?\n");
        printf("1) Dennis Ritchie\n2) JJ Thomson\n3) Ada Lovelace\n4) Mark Zuckerberg\n");
        printf("Enter your answer: ");
        scanf("%d", &ans1);

        if (ans1 == 1) {
            printf("Correct answer!\n");
            point1 = 5;
        } else {
            printf("Wrong answer.\n");
        }

        // Question 2
        printf("\n2. Which one is not a variable name in C?\n");
        printf("1) int float\n2) int$ char\n3) int number\n4) int count\n");
        printf("Enter your answer: ");
        scanf("%d", &ans2);

        if (ans2 == 2) {
            printf("Correct answer!\n");
            point2 = 5;
        } else {
            printf("Wrong answer.\n");
        }

        // Question 3
        printf("\n3. What is #include<stdio.h>?\n");
        printf("1) Preprocessor directives\n2) Inclusion directives\n3) File directives\n4) File directives inclusion\n");
        printf("Enter your answer: ");
        scanf("%d", &ans3);

        if (ans3 == 1) {
            printf("Correct answer!\n");
            point3 = 5;
        } else {
            printf("Wrong answer.\n");
        }

        // Question 4
        printf("\n4. scanf() is a predefined function in ______ header file?\n");
        printf("1) stdlib.h\n2) ctype.h\n3) stdarg.h\n4) stdio.h\n");
        printf("Enter your answer: ");
        scanf("%d", &ans4);

        if (ans4 == 4) {
            printf("Correct answer!\n");
            point4 = 5;
        } else {
            printf("Wrong answer.\n");
        }

        // Question 5
        printf("\n5. Which of the following return-type cannot be used for a function in C?\n");
        printf("1) char*\n2) struct\n3) void\n4) None of mentioned\n");
        printf("Enter your answer: ");
        scanf("%d", &ans5);

        if (ans5 == 4) {
            printf("Correct answer!\n");
            point5 = 5;
        } else {
            printf("Wrong answer.\n");
        }

       
        total = point1 + point2 + point3 + point4 + point5 + point6 + point7 + point8 + point9 + point10;
        printf("\nYour total score: %d out of 50\n", total);

        
        if (total >= 40) {
            printf("Congratulations! You scored excellently. Thank you for taking the quiz!\n");
        } else if (total >= 30) {
            printf("Great job! You did well. Thank you for participating!\n");
        } else if (total >= 20) {
            printf("Good effort! You passed the quiz. Thank you for your participation!\n");
        } else {
            printf("Better luck next time. Thank you for taking the quiz!\n");
        }
    } else if (choice == 'q') {
        printf("\nThe quiz has been cancelled.\n");
    } else {
        printf("\nInvalid choice.\n");
    }

    return 0;
}