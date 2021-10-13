#include "TFile.h"
#include "TCanvas.h"
#include "RooPlot.h"
#include "RooDataSet.h"
#include "RooRealVar.h"
#include "RooCBShape.h"
#include "RooExponential.h"
#include "RooAddPdf.h"

void All(){

// Open the file, access the dataset and creat mass variable

TFile *f= new TFile("DataSet_lowstat.root");
RooDataSet * data = ( RooDataSet *)f->Get("data");
RooRealVar mass("mass","invariant mass (GeV/c2)",2,12);


//Crystal ball for the J/psi

RooRealVar mean_jpsi("mean_jpsi","mean_jpsi",3,2.9,3.2);
RooRealVar sigma_jpsi("sigma_jpsi","sigma_jpsi",0.07,0,0.1);
RooRealVar alpha("alpha","alpha",1);
RooRealVar n("n","n",5);
RooCBShape *jpsi = new RooCBShape("jpsi","crystal ball PDF",mass,mean_jpsi,sigma_jpsi,alpha,n);

//Crystal ball for the psi

RooRealVar mean_psi("mean_psi","mean_psi",3.6,3.4,3.8);
RooRealVar sigma_psi("sigma_psi","sigma_psi",0.07,0,0.1);
RooRealVar alpha_psi("alpha","alpha",1.5);
RooRealVar n_psi("n","n",1);
RooCBShape *psi = new RooCBShape("psi","crystal ball PDF",mass,mean_psi,sigma_psi,alpha_psi,n_psi);

//Exponential background

RooRealVar a("a","a",-0.9,-0.85,-0.8);
RooExponential bkg("exp","exp",mass,a);

RooRealVar fsig("fsig","signal",0.1,0.,1.);
RooRealVar fsig2("fsig2","signal2",0.1,0.,1.);

RooAddPdf sum("sum","sum",RooArgList(*jpsi,*psi,bkg),RooArgList(fsig,fsig2),kTRUE);

sum.fitTo(*data);

TCanvas* c1 = new TCanvas();
RooPlot* mframe = mass.frame();
data->plotOn(mframe);
sum.plotOn(mframe);
mframe->Draw();
c1->Draw() ;

}
