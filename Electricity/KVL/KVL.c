#include <stdio.h>
#include <emscripten/emscripten.h>

double V0;
double V_s;
double totalV0;
double answer;
double branch;
double V_sT;
int unk;


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
branch = 0;
V_sT = 0;
unk = 90;


printf("   - Welcome to the KVL Calculator!\n");
printf("   - Remember that to find the Voltage at source, you will need to write 0 to calculate for an unknown Voltage from a source and a 1 to find the voltaage at an unkwnon voltage drop.\n");
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
    }else if( V_s != 0 && branch == 0){
    printf("Voltage at source: %lf V\n\n", V_s);
    V_sT = V_s;
    branch += 1;
    } else if ( V_s != 0 && branch > 0){
    printf("%lfV + %lfV =\n", V_s, V_sT);
    V_sT = (V_s + V_sT);
    printf("New Total voltage from sources = %lf V\n\n", V_sT);
    }

    fflush(stdout);
    

}

EMSCRIPTEN_KEEPALIVE

void V_0(){

    scanf("%lf", &V0);
    printf("%lfV + %lfV \n", totalV0, V0);
    totalV0 = (totalV0 + V0);
    printf("New total V drop: %lf V\n\n", totalV0);
    fflush(stdout);

}

EMSCRIPTEN_KEEPALIVE

void unknown(){

    scanf("%d", &unk);
    printf("%d --> ", unk);
    if(unk == 0){
    printf("Unknow V is a source\n\n");
    }else if(unk == 1){
    printf("Unknow V is a Voltage drop\n\n");
    } else{
    printf("Error, pls input 0 or 1 for the unknown, read the instructions to know which one to choose :)\n");
    }
    fflush(stdout);


}

EMSCRIPTEN_KEEPALIVE

void calculate(){
  

    if (unk == 0){
    answer = (totalV0 - V_sT);
    printf("The Voltage at unknown source is: %lf\n", answer);
    } else if (unk == 1){
    answer = (V_sT - totalV0);
    printf("The Voltage drop at V_n is: %lf V\n", answer);
    }
    fflush(stdout);



}






