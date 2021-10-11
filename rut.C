#include <iostream>
#include <math.h>

void rut(){

Float_t e = 2.71;
Float_t pi = 3.14;
Float_t h ;
Float_t m ; 
Float_t v ;
Float_t theta ; 

cout<<"Entre com o valor de Eo"<<endl;
cin>>h;
cout<<"Entre com o valor de m"<<endl;
cin>>m;
cout<<"Entre com o valor de Vo"<<endl;
cin>>v;
cout<<"Entre com o valor de theta"<<endl;
cin>>theta;

Float_t f1 = ((pow(e, 2))/(8*pi*h*m*(pow(v,2))));
Float_t f2 = 1/(pow(sin(theta/2),4));

Float_t f = f1*f2; 

printf("O valor da seção de choque diferencial do espalhamento de Rutherford é: %f", f);
}