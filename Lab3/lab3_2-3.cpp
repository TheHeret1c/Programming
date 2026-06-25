#include <stdio.h>

typedef enum Weekday {
    MONDAY,    
    TUESDAY,   
    WEDNESDAY,
    THURSDAY,  
    FRIDAY,   
    SATURDAY, 
    SUNDAY   
} Weekday;

int main() {
    printf("--- Weekday Enum Values ---\n");

    for (int day = MONDAY; day <= SUNDAY; day++) {
        printf("Day %d value: %d\n", day + 1, day);
    }

    return 0;
}