
void teste()
{

   RooRealVar x("x", "x", -100, 100);
   RooRealVar cbmean("cbmean", "cbmean" , 0,  -9.0, 180.0) ;
   RooRealVar cbsigma("cbsigma", "cbsigma" , 6.0, 1.0, 40.0) ;
   RooRealVar cbsig("cbsig", "cbsignal", 10, 0, 1000000);
   RooRealVar n("n","", 5.1);
   RooRealVar alpha("alpha","", 1.3);

   RooCrystalBall cball("cball", "crystal ball", x, cbmean, cbsigma, alpha, n);

   RooDataSet* toyData = cball.generate(x,10000);

   cball.fitTo(*toyData) ;


   TCanvas* c1 = new TCanvas();
   RooPlot* frame = x.frame() ;
   toyData->plotOn(frame) ;
   cball.plotOn(frame) ;
   frame->Draw() ;
   c1->Draw() ;
}
