#include <stdio.h>

#define NUM_ITEMS 3

/* substructure for the item name */
typedef struct {
    char brand_name[20];
    char product_name[20];
} ItemName;

typedef struct {
    ItemName item_name;
    float price;
    int quantity;
} Stores;

/* brand_name and product_name are filled using the array StLocal */
void read_names(Stores arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("\nItem %d brand name: ", i + 1);
        scanf(" %19[^\n]", arr[i].item_name.brand_name);
        printf("Item %d product name: ", i + 1);
        scanf(" %19[^\n]", arr[i].item_name.product_name);
    }
}

/* price and quantity are filled using the pointer Ptr */
void read_price_quantity(Stores *Ptr, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("\nItem %d price: ", i + 1);
        scanf("%f", &(Ptr + i)->price);
        printf("Item %d quantity: ", i + 1);
        scanf("%d", &(Ptr + i)->quantity);
    }
}

void display_items(const Stores *Ptr, int n) {
    int i;
    printf("\n%-15s %-15s %-10s %s\n", "Brand", "Product", "Price", "Qty");
    for (i = 0; i < n; i++)
        printf("%-15s %-15s %-10.2f %d\n", (Ptr + i)->item_name.brand_name,
               (Ptr + i)->item_name.product_name,
               (Ptr + i)->price, (Ptr + i)->quantity);
}

int main() {
    Stores StLocal[NUM_ITEMS];   /* array variable */
    Stores *Ptr = StLocal;       /* pointer variable, points to first element */

    read_names(StLocal, NUM_ITEMS);
    read_price_quantity(Ptr, NUM_ITEMS);
    display_items(Ptr, NUM_ITEMS);
    return 0;
}
