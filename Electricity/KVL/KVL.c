#include <stdio.h>
#include <emscripten/emscripten.h>

int unk;
double V0;
double V_s;
double totalV0;
double answer;


EMSCRIPTEN_KEEPALIVE

int main(){

    return 0;
}

EMSCRIPTEN_KEEPALIVE


void KVL() {

EM_ASM(
        document.getElementById('output').value = '';
    );

V0 = 0;
V_s = 0;
totalV0 = 0;
answer = 0;


printf("   - Welcome to the KVL Calculator!\n");
printf("   - Remember that to find the Voltage at source, you will need to write 0 for the voltage at source.\n");
printf("   - To find the Voltage drop at V_n, you don't have to do anything as long as the value of V_source is not 0\n");
printf("   - Also, make sure only numbers are entered (no units or SI units).\n");
printf("   - To add more voltage drops, just click the button and they will be added.\n");
printf("   - Once everything has been fill up, click calculate to get the final answer.\n\n\n");


fflush(stdout);
 
}



EMSCRIPTEN_KEEPALIVE

void Vs(){
    scanf("%lf", &V_s);
    if(V_s == 0){
    printf("Looking for V at source\n\n");
    }else if( V_s != 0){
    printf("Voltage at source: %lf V\n", V_s);
    printf("Looking for Voltage drop at V_n\n\n");
    }

    fflush(stdout);
    

}

EMSCRIPTEN_KEEPALIVE

void V_0(){

    scanf("%lf", &V0);
    printf("%lf + %lf \n", totalV0, V0);
    totalV0 = (totalV0 + V0);
    printf("New total V drop: %lf V\n\n", totalV0);
    fflush(stdout);

}

EMSCRIPTEN_KEEPALIVE

void calculate(){


   
  
    if (V_s == 0){
    answer = (totalV0);
    printf("The Voltage at source is: %lf\n", answer);
    } else if (V_s != 0){
    answer = (V_s - totalV0);
    printf("The Voltage drop at V_n is: %lf V\n", answer);
    }
    fflush(stdout);


}






