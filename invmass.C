#include <Riostream.h>
#include <TLorentzVector.h>
#include <TCanvas.h>
#include <TH1.h>

void invmass(){
	cout << "Teste 0"<< endl;
	TLorentzVector mu_1;
	TLorentzVector mu_2;
	std::ifstream infile("myfile2.txt");

	float a, b, c, d, e, f ;
	TLorentzVector Jpsi;
	TH1F *h1 = new TH1F("h1","massa invariante",100,2.,4.);
		while (infile >> a >> b >> c >> d >> e >> f)
		        {
			mu_1.SetPtEtaPhiM(a, b ,c, 0.1057);
			mu_2.SetPtEtaPhiM(d, e, f, 0.1057);
			Jpsi = mu_1 + mu_2;
			float mass_inv = Jpsi.M();
			h1->Fill(mass_inv);
			}
	TCanvas *c1 = new TCanvas("c1","c1",600,600);
	h1->Draw();
	c1->Update();

}