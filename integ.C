#include <math.h>
#include <TMath.h>
void integ()
{
    //Seja l = 1 e d = 1 = H, ponto de máximo x = pi e valor máximo da altura = 0.5 (d/2) para n = 10.
    Float_t N = 10;
    Float_t f = 0;
    Float_t H = 1;
    Float_t a = 0;
    Float_t b = TMath::Pi();

    //área do retângulo
    Float_t A = (b - a) * (H/2);

    //definindo contador
    Float_t c = 0 ;

   TRandom * r = new TRandom3();
       Double_t x,y;

       for (Int_t i=1;i<=N;i++) {
         Float_t x = r->Rndm()* 47 / 15;
         Float_t y = r->Rndm()* 9/10;

          if(   (   (     0.5 *  sin(x)    )<=y  ) && (  0.5 *  sin(x)  ) >= 0 ){
                   c+=1;
          }
    }

    // Definindo a integral 
    Float_t Integral ;
    Integral = A*(c/N);


    cout << "O valor da integral de f(x)= (1/2)(sen(x)) = " <<  floor(Integral) << endl;



}