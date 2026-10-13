#include <stdio.h>
#include <emscripten/emscripten.h>

double R_amount [100];
double R_T = 0;
int R_count;
double R;


EMSCRIPTEN_KEEPALIVE

int main(){

    return 0;
}

EMSCRIPTEN_KEEPALIVE


int start() {

EM_ASM(
        document.getElementById('output').value = '';
    );

R = 0;
R_T = 0;
R_count = 0;





printf("Welcome to the Series Resistor Calculator!\n");
printf("Remember that to find the unknown quantity, you need write 0 on the popup.\n");
printf("Also, make sure only numbers are entered (no units or SI units).\n");


printf("Enter the first Resistance (Ω): \n");



fflush(stdout);

}



EMSCRIPTEN_KEEPALIVE

int InsertR() {
  

    // 1. Check the limit BEFORE asking the user to do anything
    if(R_count >= 100){
        printf("Max resistors amount reached!! (100 resistors maximum)\n");
        fflush(stdout);
        return 0; // Exit the function immediately so it doesn't try to calculate
    }

    // 2. Clear the screen and print instructions
    EM_ASM(
        document.getElementById('output').value = '';
    );
    printf("Welcome to the Series Resistor Calculator!\n");
    printf("Remember that to find the unknown quantity, you need write 0 on the popup.\n");
    printf("Also, make sure only numbers are entered.\n\n");
    printf("Enter the value for Resistor %d (Ω):\n", R_count + 1);
    fflush(stdout); 

    
    scanf("%lf", &R);

    
    R_amount[R_count] = R;
    R_count++; 
    R_T = 0;
    // 6. Calculate the total AND print the visual equation
    printf("Total Resistance: \n");
    for (int i = 0; i < R_count; i++) {
        R_T = R_T + R_amount[i];
        
        // Print the individual resistor value
        printf("%lf Ω\n", R_amount[i]);
        
        // If it is NOT the last resistor in the list, print a " + "
        if (i < R_count - 1) {
            printf(" + ");
        }
    }

    // 7. Print the final total at the end of the equation
    printf(" = %lf Ω\n", R_T);
    
    
    fflush(stdout);
    return 0;

}

