#include <stdio.h>
#include <emscripten/emscripten.h>

double R_T = 0;
double R_new;


EMSCRIPTEN_KEEPALIVE

int main(){

    return 0;
}

EMSCRIPTEN_KEEPALIVE


int start() {

EM_ASM(
        document.getElementById('output').value = '';
    );


R_T = 0;
R_new = 0;




printf("Welcome to the Parallele Resistor Calculator!\n");
printf("Remember that to find the unknown quantity, you need write 0 on the popup.\n");
printf("Also, make sure only numbers are entered (no units or SI units).\n");
printf("It doesnt matter which resistor is the first for most cases, just make sure to only click this button once or the calculation will be messed up.\n");



printf("Enter the first Resistance (Ω): \n");



fflush(stdout);

}



EMSCRIPTEN_KEEPALIVE

int InsertR() {
EM_ASM(
        document.getElementById('output').value = '';
    );

printf("Welcome to the Parallele Resistor Calculator!\n");
printf("Remember that to find the unknown quantity, you need write 0 on the popup.\n");
printf("Also, make sure only numbers are entered (no units or SI units).\n");
printf("It doesnt matter which resistor is the first for most cases, just make sure to only click this button once or the calculation will be messed up.\n\n");


scanf("%lf", &R_T);
printf("First Resistance (Ω): %lfΩ\n", R_T);


fflush(stdout);

    }
EMSCRIPTEN_KEEPALIVE


int InsertNewR() {
scanf("%lf", &R_new);
printf("Total Resitance = 1/((1/%lf) + (1/%lf) (Ω))\n", R_T, R_new);
R_T = 1 / ((1 / R_T) + (1 / R_new));
printf("Total Resistance (Ω): %lfΩ\n\n", R_T);

fflush(stdout);

}