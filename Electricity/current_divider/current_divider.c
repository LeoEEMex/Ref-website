#include <stdio.h>
#include <emscripten/emscripten.h>

double I_x = 0;
double I_T = 0;
double R_T = 0;
double R_x = 0;

EMSCRIPTEN_KEEPALIVE

int main(){

    return 0;
}

EMSCRIPTEN_KEEPALIVE


int start() {

EM_ASM(
        document.getElementById('output').value = '';
    );

I_x = 0;
I_T = 0;
R_T = 0;
R_x = 0;



printf("Welcome to the Current Divider Calculator!\n");
printf("Remember that to find the unknown quantity, you need write 0 on the popup.\n");
printf("Also, make sure only numbers are entered (no units or SI units).\n");
printf("For the total Resistance remember to NOT include the resistance Rₓ otherwise the ouput value will be wrong\n");


printf("Enter the value of Iₓ (A): \n");

printf("Enter Current from source (A): \n");

printf("Enter the value of the Rₓ (Ω): \n");

printf("Enter Total Resistance (Ω): \n");



fflush(stdout);

}



EMSCRIPTEN_KEEPALIVE

int InsertIx() {
scanf("%lf", &I_x);

EM_ASM(
        document.getElementById('output').value = '';
    );
printf("Welcome to the Current Divider Calculator!\n");
printf("Remember that to find the unknown quantity, you need write 0 on the popup.\n");
printf("Also, make sure only numbers are entered (no units or SI units).\n");
printf("For the total Resistance remember to NOT include the resistance Rₓ otherwise the ouput value will be wrong\n");


printf("Enter the value of Iₓ (A): %lfA\n", I_x);

printf("Enter Current from source (A): %lfA\n", I_T);

printf("Enter the value of the Rₓ (Ω): %lfΩ\n", R_x);

printf("Enter Total Resistance (Ω): %lfΩ\n", R_T);

fflush(stdout);
}

EMSCRIPTEN_KEEPALIVE

int InsertIT() {
scanf("%lf", &I_T);

EM_ASM(
        document.getElementById('output').value = '';
    );

printf("Welcome to the Current Divider Calculator!\n");
printf("Remember that to find the unknown quantity, you need write 0 on the popup.\n");
printf("Also, make sure only numbers are entered (no units or SI units).\n");
printf("For the total Resistance remember to NOT include the resistance Rₓ otherwise the ouput value will be wrong\n");


printf("Enter the value of Iₓ (A): %lfA\n", I_x);

printf("Enter Current from source (A): %lfA\n", I_T);

printf("Enter the value of the Rₓ (Ω): %lfΩ\n", R_x);

printf("Enter Total Resistance (Ω): %lfΩ\n", R_T);

fflush(stdout);
}

EMSCRIPTEN_KEEPALIVE

int InsertR_x() {
scanf("%lf", &R_x);

EM_ASM(
        document.getElementById('output').value = '';
    );

printf("Welcome to the Current Divider Calculator!\n");
printf("Remember that to find the unknown quantity, you need write 0 on the popup.\n");
printf("Also, make sure only numbers are entered (no units or SI units).\n");
printf("For the total Resistance remember to NOT include the resistance Rₓ otherwise the ouput value will be wrong\n");


printf("Enter the value of Iₓ (A): %lfA\n", I_x);

printf("Enter Current from source (A): %lfA\n", I_T);

printf("Enter the value of the Rₓ (Ω): %lfΩ\n", R_x);

printf("Enter Total Resistance (Ω): %lfΩ\n", R_T);

fflush(stdout);
}

EMSCRIPTEN_KEEPALIVE

int InsertR_T() {
scanf("%lf", &R_T);

EM_ASM(
        document.getElementById('output').value = '';
    );

printf("Welcome to the Current Divider Calculator!\n");
printf("Remember that to find the unknown quantity, you need write 0 on the popup.\n");
printf("Also, make sure only numbers are entered (no units or SI units).\n");
printf("For the total Resistance remember to NOT include the resistance Rₓ otherwise the ouput value will be wrong\n");


printf("Enter the value of Iₓ (A): %lfA\n", I_x);

printf("Enter Current from source (A): %lfA\n", I_T);

printf("Enter the value of the Rₓ (Ω): %lfΩ\n", R_x);

printf("Enter Total Resistance (Ω): %lfΩ\n", R_T);

fflush(stdout);
}

EMSCRIPTEN_KEEPALIVE

int calculation(){

double answer;

if(I_x == 0) {
    answer = (I_T * R_T) / (R_x + R_T);
    printf("\nIₓ = %lfA\n", answer);
}else if(I_T == 0) {
    answer = ((R_x + R_T) * I_x) / R_T ;
    printf("\nI_T = %lfA\n", answer);
}else if(R_x == 0) {
    answer = ((R_T) * (I_T - I_x)) / I_x ;
    printf("\nRₓ = %lfΩ\n", answer);
}else if(R_T == 0) {
    answer = (R_x * I_x) / (I_T - I_x);
    printf("\nR_T = %lfΩ\n", answer);
}

}







