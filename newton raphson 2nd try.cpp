#include <iostream>
#include <cmath>
#include <iomanip>
#define MAX 10

using namespace std;

int main(){
    cout<<"Newton-Raphson calculator."<<endl
    <<"I made this to familiarize myself with iteration and problem-solving in general."<<endl
    <<"In short, this is only for practice, not for assignment or whatnot."<<endl
    <<"Absolutely not to avoid studying discrete math."<<endl;

    int i,j, amountCoef,amountLoop;
    double coef[MAX], coefDiff[MAX-1], x, functionResult, diffResult, finalResult;

    do {
    cout<<"\nThe highest power: ";
    cin>>amountCoef;
    amountCoef+=1;
    if(amountCoef<2 || amountCoef > MAX)
    cout<<"Invalid input. Try again."<<endl;
    else if(amountCoef > MAX)
    cout<<"Too large. Try again";
    }
    while(amountCoef < 2 || amountCoef > MAX);

    

    for(i=amountCoef-1;i>0;i--){
        cout<<"\nInsert the coefficient of x^"<<i<<": ";
        cin>>coef[i];
    }
    cout<<"\ninsert the constant: ";
    cin>>coef[0];

    cout<<"\nf(x) = ";
    for(i=amountCoef-1;i>=0;i--){
        cout<<coef[i]<<"x^"<<i;
        if(i>0)
        cout<<" + ";
        else
        cout<<endl;
    }

    cout<<"f'(x) = ";
    for(i=amountCoef-1;i>0;i--){
        coefDiff[i-1] = coef[i] * i;
        cout<<coefDiff[i-1]<<"x^"<<i-1;
        if(i>1)
        cout<<" + ";
        else
        cout<<endl;
    }

    cout<<"\nInsert the starting point x:"<<endl;
    cin>>x;
    cout<<"\nInsert the amount of iteration: "<<endl;
    cin>>amountLoop;

    finalResult=x;
    for(i=0;i<amountLoop;i++){
        functionResult = 0;
        for(j=amountCoef-1;j>=0;j--){
            functionResult += coef[j] * pow(x,j);
        }
        diffResult = 0;
        for(j=amountCoef-2;j>=0;j--){
            diffResult += coefDiff[j] * pow(x,j);
        }
        finalResult -= functionResult / diffResult;
        x = finalResult;
        cout<<"Iteration "<<i+1<<": "<<fixed<<setprecision(20)<<finalResult<<endl;
    }

    return 0;
}