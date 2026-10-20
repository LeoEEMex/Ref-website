#include <stdio.h>
#include <emscripten/emscripten.h>

int unk;
double insertIn;
double insertOut;
double totalIn;
double totalOut;
double answer;
double verif;



EMSCRIPTEN_KEEPALIVE

int main(){

    return 0;
}

EMSCRIPTEN_KEEPALIVE


void KCL() {

EM_ASM(
        document.getElementById('output').value = '';
    );

unk = 9; // Random number so in case the user forgets to write a 0 or a 1, the terminal doesnt outputs anything.
insertIn = 0;
insertOut = 0;
totalIn = 0;
totalOut = 0;
answer = 0;
verif = 0;


printf("   - Welcome to the KCL Calculator!\n");
printf("   - Remember that to find the unknown quantity, you need to let the calculator know at what side is the unknown at, if the unkown is coming into the node, write a 0, if it is coming out of the node, write a 1.\n");
printf("   - Also, make sure only numbers are entered (no units or SI units).\n");
printf("   - To add more values for either in or out, just click the button and they will be added.\n");
printf("   - Once everything has been fill up, click calculate to get the final answer.\n\n\n");


fflush(stdout);
 
}



EMSCRIPTEN_KEEPALIVE

void unknown(){
    scanf("%d", &unk);
    printf("%d --> ", unk);
    if(unk == 0){
    printf("Unknow branch is coming into the node\n\n");
    }else if(unk == 1){
    printf("Unknow bransh is coming out the node\n\n");
    } else{
    printf("Error :/, pls input 0 or 1, read the instructions to know which one to choose :)\n");
    }
    fflush(stdout);
    

}

EMSCRIPTEN_KEEPALIVE

void InsertIn(){

    scanf("%lf", &insertIn);
    printf("%lf + %lf \n", totalIn, insertIn);
    totalIn = (totalIn + insertIn);
    printf("New total I going in: %lf A\n\n", totalIn);
    fflush(stdout);

}

EMSCRIPTEN_KEEPALIVE

void InsertOut(){

    scanf("%lf", &insertOut);
    printf("%lf + %lf\n", totalOut, insertOut);
    totalOut = totalOut + insertOut;
    printf("New total I coming out: %lf A\n\n", totalOut);
    fflush(stdout);

}

EMSCRIPTEN_KEEPALIVE

void calculate(){


   
  
    if (unk == 0){
    answer = (totalOut - totalIn);
    printf("The unknown branch value is: %lf\n", answer);
    } else if (unk == 1){
    answer = (totalIn - totalOut);
    printf("The unknown branch value is: %lf\n", answer);
    }

    if(unk == 0){
        verif = (answer + totalIn);
    }else if(unk == 1){
        verif = (answer + totalOut);
    }


    if(verif == totalOut || verif == totalIn){
        printf("KCL is respected and the answer is correct!!\n");
    } else{
        printf("Something went wrong, please try again, make sure the values are entered correctly :)\n");
    }
    fflush(stdout);


}






/*
int I3(){


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








int InsertR() {
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


