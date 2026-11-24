/* Q5: Cricket players - team wise list */
#include <stdio.h>
#include <string.h>

#define MAX_PLAYERS 50

typedef struct {
    char player_name[30];
    char team_name[30];
    float batting_avg;
} Cricket;

int main() {
    Cricket player[MAX_PLAYERS];
    int n, i, j, already_printed;

    do {
        printf("How many players (1 to %d)? ", MAX_PLAYERS);
        scanf("%d", &n);
    } while (n < 1 || n > MAX_PLAYERS);

    for (i = 0; i < n; i++) {
        printf("\nPlayer %d\n", i + 1);
        printf("Name: ");
        scanf(" %29[^\n]", player[i].player_name);
        printf("Team: ");
        scanf(" %29[^\n]", player[i].team_name);
        printf("Batting average: ");
        scanf("%f", &player[i].batting_avg);
    }

    printf("\n===== Team wise list =====\n");
    for (i = 0; i < n; i++) {
        /* skip this team if it was already printed for an earlier player */
        already_printed = 0;
        for (j = 0; j < i; j++) {
            if (strcmp(player[i].team_name, player[j].team_name) == 0) {
                already_printed = 1;
                break;
            }
        }
        if (already_printed)
            continue;

        printf("\nTeam: %s\n", player[i].team_name);
        for (j = i; j < n; j++) {
            if (strcmp(player[j].team_name, player[i].team_name) == 0)
                printf("  %-25s %.2f\n", player[j].player_name, player[j].batting_avg);
        }
    }
    return 0;
}
