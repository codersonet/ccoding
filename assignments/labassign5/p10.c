/* Q10: Self-referential structure

   A self-referential structure is a structure that has a member which
   points to a structure of its own type (used in linked lists, trees).

   The given definition:
       struct srs { int num; struct srs next; };
   is NOT valid. Here 'next' is a whole structure of type srs inside srs
   itself, so the compiler would need infinite size (srs contains srs
   which contains srs ...). Also srs is incomplete at that point.

   Valid way: the member must be a POINTER to the structure,
   because a pointer has a fixed size.
       struct srs { int num; struct srs *next; };
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct srs {
    int num;
    struct srs *next;     /* pointer to next structure of same type */
} Srs;

int main() {
    Srs *head = NULL, *tail = NULL, *node;
    int count, i;

    printf("How many nodes? ");
    scanf("%d", &count);

    /* create nodes and link them one after another */
    for (i = 0; i < count; i++) {
        node = (Srs *)malloc(sizeof(Srs));
        if (node == NULL) {
            printf("Memory error\n");
            break;
        }
        printf("Enter num for node %d: ", i + 1);
        scanf("%d", &node->num);
        node->next = NULL;

        if (head == NULL)
            head = node;          /* first node */
        else
            tail->next = node;    /* attach at end */
        tail = node;
    }

    /* print by following the next pointers */
    printf("\nOutput: ");
    for (node = head; node != NULL; node = node->next)
        printf("%d -> ", node->num);
    printf("NULL\n");

    /* free all nodes */
    while (head != NULL) {
        node = head;
        head = head->next;
        free(node);
    }
    return 0;
}
