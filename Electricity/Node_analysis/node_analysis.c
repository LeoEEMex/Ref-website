#include <stdio.h>
#include <emscripten/emscripten.h>

double I_s;      // Current from source
double V_s;      // Voltage from source

double V_n;      // Input Voltage (known)
double R_n;      // Input Resistance (known)
// These must be calculated together before being added

double I_n;      // Total current total (previous calculated V_n / R_n all added together)

double V_x;      // Unknown Voltage drop at x resitor
double R_x;      // Unknown Resistance at x Voltage drop
double I_x;


double answer;   //Final answer;

int Rcount;      // Keeps count of how many resistors are used;
int Vcount;      // Keeps count of how many voltages are used;
int Icount;      // Keeps count of how many currents are used;

int sourceState;

double I;
double V;
double R;

double Vstat;
double Rstat;
double Istat;




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

I_n = 0;   

V_x = 0;
R_x = 0; 

answer = 0;

Rcount = 0;
Vcount = 0;

I = 0;



printf("   - Welcome to the Node Analysis Calculator!\n");
printf("   - Click each button to ublock the new inputs and/or insert the inputs\n");
printf("   - Also, make sure only numbers are entered (no units or SI units).\n");
printf("   - To add more voltage drops, just click the button and they will be added.\n");
printf("   - If you made a mistage click Reset, this will reset the whole calculators (THIS WILL ERASE ALL PREVIOUS INSTERTED VALUES)\n");
printf("   - Once everything has been fill up, click calculate to get the final answer.\n\n\n");


fflush(stdout);
 
}

EMSCRIPTEN_KEEPALIVE

void insertIs(){


    scanf("%lf", &I_s);
    printf("The Current from source is: %lf A\n\n", I_s);
    fflush(stdout);
}

EMSCRIPTEN_KEEPALIVE

void insertVs(){
    scanf("%lf", &V_s);
    printf("The Voltage from source is: %lf V\n\n", V_s);
    fflush(stdout);
}

EMSCRIPTEN_KEEPALIVE

void insertR(){

    scanf("%lf", &R_n);
    Rcount += Rcount;
    printf("The Resistance value at R%d is: %lf Ω\n\n", Rcount, R_n);


    fflush(stdout);

}

EMSCRIPTEN_KEEPALIVE

void insertV(){

    scanf("%lf", &V_n);
    Vcount += Vcount;
    printf("The Voltage at V%d is: %lf V\n\n", Vcount, V_n);


    fflush(stdout);
}

EMSCRIPTEN_KEEPALIVE

void insertI(){
    scanf("%lf", &I_n);
    Icount += Icount;
    printf("The current at I%d is: %lf A\n\n", Icount, I_n);
}

EMSCRIPTEN_KEEPALIVE

void insertRx(){
    scanf("%lf", &R_x);
    printf("Resistance at the unknown Voltage is: %lf Ω\n\n", R_x);


    fflush(stdout);

}

EMSCRIPTEN_KEEPALIVE

void insertVx(){
    scanf("%lf", &V_x);
    printf("Unknown Voltage at R_x is: %lf V\n\n", V_x);


    fflush(stdout);

}

EMSCRIPTEN_KEEPALIVE

void insertIx(){
    scanf("%lf", &I_x);
    printf("Unknown current at R_x is: %lf A\n\n", I_x);


    fflush(stdout);

}

EMSCRIPTEN_KEEPALIVE


void addMore(){

if(sourceState == 0){
if(Vstat == 1 && Rstat == 1){ 
    I_n = (V_n / R_n);
    I = I_n + I;
    I_n = 0;
    printf("Current at branch %d is: %lf\n\n\n",Icount, I);

}else if(Istat == 1 && Rstat == 1){
   // V_n = (I_n * R_n);
   // V = V_n + V;
   // V_n = 0;
   // printf("Voltage at branch %d is: %lf\n\n\n",Vcount, V);
   I = I + I_n;

}else if(Vstat == 1 && Istat == 1){
   // R_n = (V_n / I_n);
   // R = V_n + R;
   // R_n = 0;
   // printf("Resistance at branch %d is: %lf\n\n\n",Rcount, R);
   I = I + I_n;
}
    printf("Current at branch %d is: %lfA\n\n\n",Icount, I_n);
    printf("New Total Current is: %lfA\n", I);
    I_n = 0;

} else if(sourceState == 1){
if(Vstat == 1 && Rstat == 1){ 
    V = V_n + V;
}else if(Istat == 1 && Rstat == 1){
    V_n = (I_n * R_n);
    V = V_n + V;
}else if(Vstat == 1 && Istat == 1){
    V = V_n + V;
}
    printf("Voltage at branch %d is: %lfA\n\n\n",Vcount, V_n);
    printf("New Total Voltage is: %lfV\n", V);
    V_n = 0;
}

    

    fflush(stdout);

}

EMSCRIPTEN_KEEPALIVE

void sourceStatus(int source){
    sourceState = source;
    if (sourceState == 1){
        printf("Source is based on Voltage\n");
    } else if(sourceState == 0){
        printf("source is based on Current\n");
    }else{
        printf("not working?\n");
    }
fflush(stdout);
}

EMSCRIPTEN_KEEPALIVE

void VRIstatus(double Vstatus, double Rstatus, double Istatus){
    Vstatus = Vstat;
    Rstatus = Rstat;
    Istatus = Istat;
}

EMSCRIPTEN_KEEPALIVE

void calculate(){


    
    // I_s = (V_n / R_n) + (V_x / R_x)
    // I_s - (V_n / R_n) = V_x / R_x
    // (I_s - (V_n / R_n)) * R_x = V_x
    // V_x = (I_s - (V_n / R_n)) * R_x
    // V_x = (I_s - I_n) * R_x       <-----Formula to find unknown V.

if(sourceState == 1){
    // V_s = (V_n) + (V_x)
    // V_x = V_s - V
    V_x = V_s - V;
    printf("Answer: %lfV\n", V_x);

}else if (sourceState == 0){
    V_x = ((I_s - I) * R_x);
    printf("Answer: %lfV\n", V_x);
}

    fflush(stdout);
}

EMSCRIPTEN_KEEPALIVE

void calculateR_x (){
    
    // I_s = (I_n) + (V_x / R_x)
    // I_s - I_n = (V_x / R_x)
    // (I_s - I_n)/V_x = 1 / R_x
    // R_x = V_x / (I_s - I_n)     <-----Formula to find unknown V.
   if(sourceState == 0){
    R_x = V_x / (I_s - I);
    printf("Answer: %lf Ω\n", R_x);
   }
   if(sourceState == 1){
    // V_s = V_n = (V_x)
    // V_s = (I_x * R_x)
    // R_x = V_s / I_x
    R_x = V_s / I_x;
    printf("Answer: %lf Ω\n", R_x);

   }
    fflush(stdout);

}





//    I_s = (V_T / R_T) + (V_x / R_x);
