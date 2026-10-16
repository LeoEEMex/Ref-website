#include <stdio.h>
#include <emscripten/emscripten.h>

double I_1;
double I_2;
double I_3;
double answer;



EMSCRIPTEN_KEEPALIVE

int main(){

    return 0;
}

EMSCRIPTEN_KEEPALIVE


void KCL(double I1, double I2, double I3) {

EM_ASM(
        document.getElementById('output').value = '';
    );

I_1 = I1;
I_2 = I2;
I_3 = I3;

printf("Welcome to the KCL Calculator!\n");
printf("Remember that to find the unknown quantity, you need write 0 on the popup.\n");
printf("Also, make sure only numbers are entered (no units or SI units).\n");
printf("Enter the values on their corresponding boxes: \n");



fflush(stdout);

}



EMSCRIPTEN_KEEPALIVE



int Iadd(){


if(I_1 == 0){
 answer = I_2 + I_3;
printf("The current at I_1 = %lf A\n", answer);

} else if (I_2 == 0){
 answer = I_1 - I_3;
printf("The current at I_2 = %lf A\n", answer);

} else if (I_3 == 0){
 answer = I_1 - I_2;
printf("The current at I_3 = %lf A\n", answer);

}

fflush(stdout);
return(0);
}












/*int InsertR() {
EM_ASM(
        document.getElementById('output').value = '';
    );

printf("Welcome to the KCL Calculator!\n");
printf("Remember that to find the unknown quantity, you need write 0 on the popup.\n");
printf("Also, make sure only numbers are entered (no units or SI units).\n");


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
*/


