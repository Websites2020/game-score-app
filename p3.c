//
//  main.c
//  assignment3
//
//  Created by Daniel on 10/8/18.
//  Copyright © 2018 Daniel. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[]) {
    
    int gamePoints = 0, i, gpAmount = 0, gpTotal = 0;
    float gpAvg;
    char c;
    
    printf("Welcome to the Patriot’s Game points Analyzer.\n\n");
    
    printf("This program calculates the average of as many game points you wish to enter.\n");
    
    while (gamePoints <= 0) {
        printf("\nFirst, enter the number of game points to process: ");
        scanf("%i", &gamePoints);
        while ( (c = getchar() != '\n') && c != EOF);
        if (gamePoints <= 0) {
            printf("\nInput error.  Please enter a number above 0.\n");
        }
    }
    
    printf("\nNow enter the %i game points to be processed.\n\n", gamePoints);
    
    for (i = 1; i <= gamePoints; i++) {
        printf("Enter game points amount #%i ", i);
        scanf("%i", &gpAmount);
        while ( (c = getchar() != '\n') && c != EOF);
        
        if (gpAmount < 0) {
            while (gpAmount < 0){
                gpTotal = gpTotal - gpAmount;
                printf("*** Entry error! The game points amount must be positive.\n");
                printf("Enter game points amount #%i ", i);
                scanf("%i", &gpAmount);
                while ( (c = getchar() != '\n') && c != EOF);
            }
        } else {
            gpTotal = gpTotal + gpAmount;
        }
    }
    
    printf("\nThe Total points of the %i games entered is %i\n\n", gamePoints, gpTotal);
    
    gpAvg = (float)gpTotal / gamePoints;
    
    printf("The Average points of the %i games points entered is %.1f\n\n", gamePoints, roundf(gpAvg*10)/10);
    
    if (gpAvg < 10) {
        printf("Your game points average needs improvement.");
    } else if (gpAvg >= 10 && gpAvg < 20) {
        printf("Your game points average is adequate.");
    } else if (gpAvg >= 20 && gpAvg < 30) {
        printf("Congratulations your team made the Silver Status");
    } else {
        printf("Congratulations your team made the Hall of Fame Status.");
    }
    
    return 0;
}
