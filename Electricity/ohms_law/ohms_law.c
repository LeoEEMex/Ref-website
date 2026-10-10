#include <stdio.h>
#include <emscripten/emscripten.h>

double V = 0;
double I = 0;
double R = 0;

EMSCRIPTEN_KEEPALIVE

int main(){

    return 0;
}

EMSCRIPTEN_KEEPALIVE


int start() {
printf("Welcome to the Ohm's Law Calculator!\n");
printf("Remember that to find the unknown quantity, you need write 0 on the popup.\n");
printf("Also, make sure only numbers are entered (no units or SI units).\n");


printf("Enter Voltage (V): \n");

printf("Enter Current (A): \n");

printf("Enter Resistance (Ω): \n");

fflush(stdout);

}



EMSCRIPTEN_KEEPALIVE

int InsertV() {
scanf("%lf", &V);

EM_ASM(
        document.getElementById('output').value = '';
    );

printf("Enter Voltage (V): %lf\n", V);

printf("Enter Current (A): %lf\n", I);

printf("Enter Resistance (Ω): %lf\n", R);

fflush(stdout);
}

EMSCRIPTEN_KEEPALIVE

int InsertI() {
scanf("%lf", &I);

EM_ASM(
        document.getElementById('output').value = '';
    );

printf("Enter Voltage (V): %lf\n", V);

printf("Enter Current (A): %lf\n", I);

printf("Enter Resistance (Ω): %lf\n", R);

fflush(stdout);
}

EMSCRIPTEN_KEEPALIVE

int InsertR() {
scanf("%lf", &R);

EM_ASM(
        document.getElementById('output').value = '';
    );

printf("Enter Voltage (V): %lf\n", V);

printf("Enter Current (A): %lf\n", I);

printf("Enter Resistance (Ω): %lf\n", R);

fflush(stdout);
}

EMSCRIPTEN_KEEPALIVE

int calculation(){

double answer;

if(V == 0) {
    answer = I * R;
    printf("\nV = %lfV\n", answer);
}else if(I == 0) {
    answer = V / R;
    printf("\nI = %lfA\n", answer);
}else if(R == 0) {
    answer = V / I;
    printf("\nR = %lfΩ\n", answer);
}

}

int restart() {

    V = 0;
    I = 0;
    R = 0;

printf("Enter Voltage (V): \n");

printf("Enter Current (A): \n");

printf("Enter Resistance (Ω): \n");

}






