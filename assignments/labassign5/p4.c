/* Q4: Hotel records (10 hotels) */
#include <stdio.h>

#define NUM_HOTELS 10

typedef struct {
    char name[30];
    char address[50];
    int grade;            /* e.g. 1 to 5 star */
    float room_charge;    /* average room charge */
    int num_rooms;
} Hotel;

/* (a) read details of all hotels */
void read_hotels(Hotel h[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("\nHotel %d\n", i + 1);
        printf("Name: ");
        scanf(" %29[^\n]", h[i].name);
        printf("Address: ");
        scanf(" %49[^\n]", h[i].address);
        printf("Grade: ");
        scanf("%d", &h[i].grade);
        printf("Average room charge: ");
        scanf("%f", &h[i].room_charge);
        printf("Number of rooms: ");
        scanf("%d", &h[i].num_rooms);
    }
}

void print_hotel(const Hotel *h) {
    printf("%-20s %-25s Grade:%d Charge:%.2f Rooms:%d\n",
           h->name, h->address, h->grade, h->room_charge, h->num_rooms);
}

/* (b) hotels of a given grade, sorted by charge (lowest first) */
void print_by_grade(const Hotel h[], int n, int grade) {
    Hotel temp[NUM_HOTELS], swap;
    int count = 0, i, j;

    /* copy matching hotels, so original order is not disturbed */
    for (i = 0; i < n; i++)
        if (h[i].grade == grade)
            temp[count++] = h[i];

    /* simple bubble sort on room charge */
    for (i = 0; i < count - 1; i++) {
        for (j = 0; j < count - i - 1; j++) {
            if (temp[j].room_charge > temp[j + 1].room_charge) {
                swap = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = swap;
            }
        }
    }

    if (count == 0)
        printf("No hotel of grade %d found.\n", grade);
    for (i = 0; i < count; i++)
        print_hotel(&temp[i]);
}

/* (c) hotels with charge less than the given value */
void print_below_charge(const Hotel h[], int n, float limit) {
    int i, found = 0;
    for (i = 0; i < n; i++) {
        if (h[i].room_charge < limit) {
            print_hotel(&h[i]);
            found = 1;
        }
    }
    if (!found)
        printf("No hotel with charge less than %.2f\n", limit);
}

int main() {
    Hotel hotels[NUM_HOTELS];
    int grade;
    float limit;

    read_hotels(hotels, NUM_HOTELS);

    printf("\nEnter grade to search: ");
    scanf("%d", &grade);
    print_by_grade(hotels, NUM_HOTELS, grade);

    printf("\nEnter maximum room charge: ");
    scanf("%f", &limit);
    print_below_charge(hotels, NUM_HOTELS, limit);
    return 0;
}
