#include <iostream>
#include <cmath>
using namespace std;

//-b+-(b^2-4*a*c)^(1/2)   / (2*a)

//Functions that ask for A, B , C.
void pedirValores(double &dA, double &dB, double &dC)
{
     cout << "A: ";
     cin >> dA;
     cout << "B: ";
     cin >> dB;
     cout << "C: ";
     cin >> dC;
}

//Function that gets the discriminant
void sacarDiscriminante(double dA, double dB, double dC, double &dDiscri)
{
     dDiscri = pow(dB,2) - 4 * dA * dC;
}

//Function that checks the discriminant sign
void checarSigno(double dDiscri)
{
     if (dDiscri > 0)
          cout << "The discriminant is positive, the function touches the x-axis twice." << endl;
     else
     if (dDiscri < 0)
          cout << "The discriminat is negative, the function does NOT touch the x-axis." << endl;
     else
          cout << "The discrminant is 0, the function touches the x-axis ONCE." << endl;
}

//Function gets sqrt of discriminant ADDS -b and divides it in 2a
void sumaDiscriminante(double &dSuma, double dA, double dB, double dDiscri)
{
     dSuma = (-dB + sqrt(dDiscri)) / (2 * dA);
}

//Function gets sqrt of discriminant SUBTRACTS -b and divides it in 2a
void restaDiscriminante(double &dResta, double dA, double dB, double dDiscri)
{
     dResta = (-dB - sqrt(dDiscri)) / (2 * dA);
}

//Function that shows the solutions
void showSolutions(double dSuma, double dResta)
{
     cout << "SOLUTIONS\n";
     if(dSuma > 0)
          cout << "(x - " << dSuma << ")" << endl;
     else
          cout << "(x + " << dSuma * -1 << ")" << endl;

     if(dResta > 0)
          cout << "(x - " << dResta << ")" << endl;
     else
          cout << "(x + " << dResta * -1 << ")" << endl;

}

//Function that asks if user wants tod o ti again
void otraVez(char &cAgain)
{
     do{
     cout << "Again? (y/n) ";
     cin >> cAgain;
     cAgain = tolower(cAgain);
}while(cAgain != 'y' && cAgain  != 'n');

}

int main()
{
     double dA, dB, dC, dDiscri, dSuma, dResta;
     char cOtraVez;

     do{
     pedirValores(dA, dB, dC);
     sacarDiscriminante(dA, dB, dC, dDiscri);
     checarSigno(dDiscri);
     if(dDiscri > 0)
     {
          sumaDiscriminante(dSuma, dA, dB, dDiscri);
          restaDiscriminante(dResta, dA, dB, dDiscri);
          showSolutions(dSuma, dResta);
     }
     otraVez(cOtraVez);
}while(cOtraVez == 'y');


     return 0;
}
