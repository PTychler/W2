#include <stdio.h>
#include <stdlib.h>

const char DetermineRating(int in) {
    switch (in)
    {
    case 0 ... 5:
        return 'D';
        break;
    case 6 ... 10:
        return 'C';
        break;
    case 11 ... 15:
        return 'B';
        break;
    case  16 ... INT_MAX:
        return 'A';
        break;
    default:
        break;
    }

    return 'E';
}

int main() {
    int numPlayers = 0;
    double average = 0;

    struct Player
    {
        char name[32];
        char team[32];
        int scores[3];
        int total;
        double average;
        char rating;
    };
    
	printf("How many players are being recorded? - ");
    scanf("%d", &numPlayers);

    struct Player players[numPlayers];

    for (int i = 0; i < numPlayers; i++)
    {
        printf("Enter the name of player ");
        scanf(" %s", &players[i].name);
        getchar();

        printf("Enter the name of team of player ");
        scanf(" %s", &players[i].team);
        getchar();
        players[i].total = 0;

        for (int z = 0; z < 3; z++)
        {
            printf("Enter the number of goals of game %d\n",z);
            scanf("%d", &players[i].scores[z]);
            players[i].total += players[i].scores[z]; 
        }

        players[i].average = players[i].total/3;
    }

    printf("\n");
    printf("Players:");
    printf("\n");

    for (int i = 0; i < numPlayers; i++)
    {
        printf(players[i].name);
        printf("\n");
        printf(players[i].team);
        
        for (int z = 0; z < 3; z++)
        {
            printf("\n");
            printf("Game scores: ");
            printf("%d", players[i].scores[z]);
        }
        printf("\n");
        printf("Total scored: ");
        printf("%d", players[i].total);
        printf("\n");
        printf("\n");
    }
    
    printf("\n");
    printf("\n");

    double sum = 0;

    for (int i = 0; i < numPlayers; i++)
    {
        sum += players[i].average;
    }
    
    average = sum/numPlayers;
    printf("Average total of goals is ");
    printf("%f",average);
    printf("\n");

    int fcount = 0;
    for (int i = 0; i < numPlayers; i++)
    {
        if (players[i].average >= average)
        {
            fcount ++;
        }
    }
    printf("\n");
    printf("Number of flagged players is %d\n",fcount);

    printf("\n");
    printf("Flagged players are: ");
    for (int i = 0; i < numPlayers; i++)
    {
        if (players[i].average >= average)
        {
            printf(players[i].name);
            printf(", ");
        }
    }

    printf("\n");
    for (int i = 0; i < numPlayers; i++)
    {
        if (players[i].average >= average)
        {
            printf("\n");
            printf("Rating of player ");
            printf(players[i].name);
            char a = DetermineRating(players[i].total);
            players[i].rating = a;
            printf(" %c", players[i].rating);
        }
    }

    printf("\n");
    int indexbest = 0;
    for (int i = 0; i < numPlayers; i++)
    {
        if (players[indexbest].average <= players[i].average)
        {
            indexbest = i;
        }
    }
    printf("\n");
    printf("Best player ");
    printf(players[indexbest].name);
    printf(" with average - ");
    printf("%f", players[indexbest].average);
    
	return 0;
}
