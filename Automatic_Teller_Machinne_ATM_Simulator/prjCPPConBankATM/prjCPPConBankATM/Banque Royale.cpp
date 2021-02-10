#include"ATMlib.h"

void main()

{
	int choix;
	client file;

	file = Pull();


	DisplayFirstTitle("banque royale");
	DisplaySecondTitle("Guichet Automatique Bancaire");
	ReadCompte(file);
	ReadNIP(file);
	DisplayTransaction();
	choix = DisplayVotreChoix();


	if (choix == 1)
	{
		file = CalculateDeposite(file);
		DisplayInform(file);

	}

	else if (choix == 2)
	{
		file = CalcualteRetirer(file);
		DisplayInform(file);
	}

	else if (choix == 3)
	{
		DisplayInform(file);

	}

	DisplayMSG("Merci d'avoir utiliser nos services");
	Save(file);
	system("pause");

}

