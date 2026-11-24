#include <stdio.h>
#include <string.h>

#define NUM_CITIES 5

typedef struct {
    char city[30];
    long population;
    float literacy;
} Census;

/* mode 1 = name (A to Z), mode 2 = literacy (high to low),
   mode 3 = population (high to low).
   Returns 1 if a and b are in the wrong order and must be swapped */
int should_swap(Census a, Census b, int mode) {
    if (mode == 1)
        return strcmp(a.city, b.city) > 0;
    if (mode == 2)
        return a.literacy < b.literacy;
    return a.population < b.population;
}

/* bubble sort, works for any mode */
void sort_list(Census list[], int n, int mode) {
    Census temp;
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (should_swap(list[j], list[j + 1], mode)) {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}

void display_list(const Census list[], int n, const char *title) {
    int i;
    printf("\n%s\n%-20s %-12s %s\n", title, "City", "Population", "Literacy %");
    for (i = 0; i < n; i++)
        printf("%-20s %-12ld %.2f\n", list[i].city, list[i].population,
               list[i].literacy);
}

int main() {
    Census original[NUM_CITIES], sorted[NUM_CITIES];
    int i, mode;
    const char *title[] = {"", "Sorted alphabetically", "Sorted by literacy level",
                           "Sorted by population"};

    /* (i) read details of 5 cities */
    for (i = 0; i < NUM_CITIES; i++) {
        printf("\nCity %d name: ", i + 1);
        scanf(" %29[^\n]", original[i].city);
        printf("Population: ");
        scanf("%ld", &original[i].population);
        printf("Literacy level: ");
        scanf("%f", &original[i].literacy);
    }

    /* (ii) to (v) sort a copy each time so the original list stays safe */
    for (mode = 1; mode <= 3; mode++) {
        for (i = 0; i < NUM_CITIES; i++)
            sorted[i] = original[i];
        sort_list(sorted, NUM_CITIES, mode);
        display_list(sorted, NUM_CITIES, title[mode]);
    }

    /* (vi) size of structure */
    printf("\nSize of structure Census = %zu bytes\n", sizeof(Census));
    return 0;
}
