/* Q3: struct measure with metric and british sub-structures */
#include <stdio.h>

#define CM_PER_INCH 2.54f

/* metric system: meters and centimeters */
typedef struct {
    int meters;
    float cm;
} Metric;

/* british system: feet and inches */
typedef struct {
    int feet;
    float inches;
} British;

/* one measurement (length or breadth) holds both sub-structures */
typedef struct {
    Metric metric;
    British british;
} Measure;

/* ---------- conversion helpers (all work through a single unit) ---------- */
float metric_to_cm(Metric m) {
    return m.meters * 100 + m.cm;
}

Metric cm_to_metric(float total_cm) {
    Metric m;
    m.meters = (int)(total_cm / 100);
    m.cm = total_cm - m.meters * 100;
    return m;
}

float british_to_inches(British b) {
    return b.feet * 12 + b.inches;
}

British inches_to_british(float total_inches) {
    British b;
    b.feet = (int)(total_inches / 12);
    b.inches = total_inches - b.feet * 12;
    return b;
}

/* (b) British -> MKS and MKS -> British */
Metric british_to_metric(British b) {
    return cm_to_metric(british_to_inches(b) * CM_PER_INCH);
}

British metric_to_british(Metric m) {
    return inches_to_british(metric_to_cm(m) / CM_PER_INCH);
}

/* (a) read values from user (one value per prompt, so the program
   never sits waiting for a second number on the same line) */
void read_measure(Measure *m, const char *label) {
    printf("%s - metric, meters: ", label);
    scanf("%d", &m->metric.meters);
    printf("%s - metric, cm: ", label);
    scanf("%f", &m->metric.cm);
    printf("%s - british, feet: ", label);
    scanf("%d", &m->british.feet);
    printf("%s - british, inches: ", label);
    scanf("%f", &m->british.inches);
}

/* (c) adds metric part and british part (converted) -> total in cm */
float add_measure(Measure m) {
    return metric_to_cm(m.metric) + metric_to_cm(british_to_metric(m.british));
}

int main() {
    setbuf(stdout, NULL);   /* show prompts immediately, no output buffering */
    Measure length, breadth;
    float length_cm, breadth_cm, area_m2, area_sqft;
    Metric l_met, b_met;
    British l_br, b_br;
    int choice;

    read_measure(&length, "length");
    read_measure(&breadth, "breadth");

    length_cm = add_measure(length);
    breadth_cm = add_measure(breadth);

    /* area in both systems */
    area_m2 = (length_cm / 100) * (breadth_cm / 100);
    area_sqft = (length_cm / CM_PER_INCH / 12) * (breadth_cm / CM_PER_INCH / 12);

    l_met = cm_to_metric(length_cm);
    b_met = cm_to_metric(breadth_cm);
    l_br = metric_to_british(l_met);
    b_br = metric_to_british(b_met);

    /* (d) show result as the user wants */
    printf("\n1. British (feet, inches)\n2. MKS (meters, cm)\nChoice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Length  = %d ft %.2f in\n", l_br.feet, l_br.inches);
            printf("Breadth = %d ft %.2f in\n", b_br.feet, b_br.inches);
            printf("Area    = %.2f sq ft\n", area_sqft);
            break;
        case 2:
            printf("Length  = %d m %.2f cm\n", l_met.meters, l_met.cm);
            printf("Breadth = %d m %.2f cm\n", b_met.meters, b_met.cm);
            printf("Area    = %.2f sq m\n", area_m2);
            break;
        default:
            printf("Invalid choice\n");
    }

    /* (e) memory */
    printf("\nSize of struct Measure = %zu bytes\n", sizeof(Measure));
    printf("Total memory used (length + breadth) = %zu bytes\n",
           sizeof(length) + sizeof(breadth));
    return 0;
}
