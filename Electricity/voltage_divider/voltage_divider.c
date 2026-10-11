#include <stdio.h>
#include <emscripten/emscripten.h>

double V_source = 0;
double V_out = 0;
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

V_source = 0;
V_out = 0;
R_T = 0;
R_x = 0;



printf("Welcome to the Voltage Divider Calculator!\n");
printf("Remember that to find the unknown quantity, you need write 0 on the popup.\n");
printf("Also, make sure only numbers are entered (no units or SI units).\n");
printf("For the total Resistance remember to include the resistance Rₓ otherwise the ouput value will be wrong\n");


printf("Enter the value of V_out (V): \n");

printf("Enter Voltage from source (V): \n");

printf("Enter the value of the Rₓ (Ω): \n");

printf("Enter Total Resistance (Ω): \n");



fflush(stdout);

}



EMSCRIPTEN_KEEPALIVE

int InsertVout() {
scanf("%lf", &V_out);

EM_ASM(
        document.getElementById('output').value = '';
    );
printf("Welcome to the Voltage Divider Calculator!\n");
printf("Remember that to find the unknown quantity, you need write 0 on the popup.\n");
printf("Also, make sure only numbers are entered (no units or SI units).\n");
printf("For the total Resistance remember to include the resistance R_x otherwise the ouput value will be wrong\n");


printf("Enter the value of V_out (V): %lfV\n", V_out);

printf("Enter Voltage from source (V): %lfV\n", V_source);

printf("Enter the value of the Rₓ (Ω): %lfΩ\n", R_x);

printf("Enter Total Resistance (Ω): %lfΩ\n", R_T);

fflush(stdout);
}

EMSCRIPTEN_KEEPALIVE

int InsertVsource() {
scanf("%lf", &V_source);

EM_ASM(
        document.getElementById('output').value = '';
    );

printf("Welcome to the Voltage Divider Calculator!\n");
printf("Remember that to find the unknown quantity, you need write 0 on the popup.\n");
printf("Also, make sure only numbers are entered (no units or SI units).\n");
printf("For the total Resistance remember to include the resistance R_x otherwise the ouput value will be wrong\n");


printf("Enter the value of V_out (V): %lfV\n", V_out);

printf("Enter Voltage from source (V): %lfV\n", V_source);

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

printf("Welcome to the Voltage Divider Calculator!\n");
printf("Remember that to find the unknown quantity, you need write 0 on the popup.\n");
printf("Also, make sure only numbers are entered (no units or SI units).\n");
printf("For the total Resistance remember to include the resistance R_x otherwise the ouput value will be wrong\n");


printf("Enter the value of V_out (V): %lfV\n", V_out);

printf("Enter Voltage from source (V): %lfV\n", V_source);

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

printf("Welcome to the Voltage Divider Calculator!\n");
printf("Remember that to find the unknown quantity, you need write 0 on the popup.\n");
printf("Also, make sure only numbers are entered (no units or SI units).\n");
printf("For the total Resistance remember to include the resistance R_x otherwise the ouput value will be wrong\n");


printf("Enter the value of V_out (V): %lfV\n", V_out);

printf("Enter Voltage from source (V): %lfV\n", V_source);

printf("Enter the value of the Rₓ (Ω): %lfΩ\n", R_x);

printf("Enter Total Resistance (Ω): %lfΩ\n", R_T);

fflush(stdout);
}

EMSCRIPTEN_KEEPALIVE

int calculation(){

double answer;

if(V_out == 0) {
    answer = V_source * (R_x / R_T);
    printf("\nV_out = %lfV\n", answer);
}else if(V_source == 0) {
    answer = V_out * (R_T / R_x);
    printf("\nV_source = %lfV\n", answer);
}else if(R_x == 0) {
    answer = (V_out * R_T) / V_source;
    printf("\nR_x = %lfΩ\n", answer);
}else if(R_T == 0) {
    answer = (V_source * R_x) / V_out;
    printf("\nR_T = %lfΩ\n", answer);
}

}







