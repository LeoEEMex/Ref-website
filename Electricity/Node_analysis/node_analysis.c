#include <stdio.h>
#include <emscripten/emscripten.h>

double I_s;      // Current from source

double V_n;      // Input Voltage (known)
double R_n;      // Input Resistance (known)
// These must be calculated together before being added

double I_T;      // Total current total (previous calculated V_n / R_n all added together)

double V_x;      // Unknown Voltage drop at x resitor
double R_x;      // Unknown Resistance at x Voltage drop

double answer;   //Final answer;


EMSCRIPTEN_KEEPALIVE

int main(){

    return 0;
}

EMSCRIPTEN_KEEPALIVE

void node() {

EM_ASM(
        document.getElementById('output').value = '';
    );

I_s = 0;

V_n = 0;   
R_n = 0;   

I_T = 0;   

V_x = 0;
R_x = 0; 


printf("   - Welcome to the KVL Calculator!\n");
printf("   - Remember that to find the Voltage at source, you will need to write 0 to calculate for an unknown Voltage from a source and a 1 to find the voltaage at an unkwnon voltage drop.\n");
printf("   - To find the Voltage drop at V_n, you don't have to do anything as long as the value of V_source is not 0\n");
printf("   - Also, make sure only numbers are entered (no units or SI units).\n");
printf("   - To add more voltage drops, just click the button and they will be added.\n");
printf("   - Once everything has been fill up, click calculate to get the final answer.\n\n\n");


fflush(stdout);
 
}

EMSCRIPTEN_KEEPALIVE

void insertIs(){


    scanf("%lf", &I_s);
    printf("%lf A\n", I_s);


    fflush(stdout);
}

EMSCRIPTEN_KEEPALIVE

void insertR(){

    scanf("%lf", &R_n);
    printf("%lf\n", R_n);


    fflush(stdout);

}

EMSCRIPTEN_KEEPALIVE

void insertV(){

    scanf("%lf", &V_n);
    printf("%lf\n", V_n);


    fflush(stdout);
}

EMSCRIPTEN_KEEPALIVE

void calculate(){

    if (V_x == 0){
    // I_s = (V_n / R_n) + (V_x / R_x)
    // I_s - (V_n / R_n) = V_x / R_x
    // (I_s - (V_n / R_n)) * R_x = V_x
    // V_x = (I_s - (V_n / R_n)) * R_x       <-----Formula to find unknown V.
    V_x = (I_s - I_T) * R_x;
    printf("%lf V", V_x);
    }

    fflush(stdout);
}




//    I_s = (V_T / R_T) + (V_x / R_x);
