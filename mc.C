
void mc()
{

	//ponto de máximo x = 3 e valor máximo H = (1-(3^2)) ^ 2 = 64
	Int_t H = 64;

	//área do retângulo
	Int_t a = 0;
	Int_t b = 3;
	Int_t A = (b - a) * H;

	//declarando o gerador de números pseudo-aleatórios
	TRandom * r = new TRandom3();

	//definindo contador
	Int_t count = 0;

	Int_t N = 100000;
	Int_t f = 0;
	for (unsigned int i = 0; i < 4; ++i) {


		//gera x uniforme entre 0 e 3
		Int_t x = i;


		//gera y uniforme entre 0 e 64
		Int_t y = r->Rndm(64);

		//calculando z = f(x) = (1-x^2)^2 para cada x gerado
		f = (b - a) - ((2 * pow(b, 3) / 3) - (2 * pow(a, 3)) / 3) + ((pow(b, 5) / 5) - (pow(a, 5)) / 5);

	}
	
	cout << "O valor da integral de f(x)= (1-x^2)^2 = " << f << endl;

}
