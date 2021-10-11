Float_t PI(){
   
   Float_t n = 10000;
   Float_t c = 0;
   Double_t w = 2;
   Double_t h = 2;

   TCanvas *c1 = new TCanvas("c1","c1",600,600);
   c1->SetGrid();
   TGraph * gr = new TGraph(n);
   TGraph * gr1 = new TGraph(n);
   c1->DrawFrame(-1,-1,1,1);
   gr->Draw("p");
   gr1->Draw("p");

   if (n> 999) gr->SetMarkerStyle(1);
   else        gr->SetMarkerStyle(3);

   TRandom r;
   Double_t x,y;

   for (Int_t i=1;i<=n;i++) {
      r.Circle(x,y, r.Gaus(0,2));
      gr->SetPoint(i,x,y);
      Double_t l = 1.0;
      Int_t a = (Int_t) x;
      Int_t b = (Int_t) y;
      if(floor(a^2+b^2 )<=1){
      c+=1;
      }
   }
      for (Int_t i=1;i<=n;i++) {
      r.Circle(x,y, r.Poisson(1));
      gr1->SetPoint(i,x,y);
      }

   Float_t pi;
   pi = 4*(c/n); 
   return pi;
   printf("%.3f", pi);

}