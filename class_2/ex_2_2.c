#include <stdio.h>

void modifyFloat(float *ptr) {
    *ptr *= 2; 
}

int main() {
    float number = 5.0;
    printf("Przed modyfikacja: %.2f\n", number);
    
    modifyFloat(&number);
    
    printf("Po modyfikacji: %.2f\n", number);
    
    return 0;
}