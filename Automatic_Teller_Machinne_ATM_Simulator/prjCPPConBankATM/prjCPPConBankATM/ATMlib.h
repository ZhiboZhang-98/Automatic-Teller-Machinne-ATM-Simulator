#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


struct client
{
	string name;
	char compte[6];
	char nip[10];
	int solde;

};
client file;



void DisplayFirstTitle(string Title)
{
	cout << "\t\t";
	for (int I = 0; I<Title.length(); I++)
	{
		cout << char(toupper(Title[I]));

	}
	cout << "\n\t\t";
	for (int I = 1; I <= Title.length(); I++)
	{
		cout << "-";
	}
	cout << "\n";
}

void DisplaySecondTitle(string Title)
{
	cout << "\t";
	cout << Title;
	cout << "\n\t";
	for (int I = 1; I <= Title.length(); I++)
	{
		cout << "-";
	}
	cout << "\n";
}

client ReadCompte(client file)
{

	client Onefile;

	do {
		cout << "\n";
		cout << "Entrez votre numero de compte: ";
		cin >> Onefile.compte;

		if (strcmp(Onefile.compte, file.compte) == 0)

		{
			cout << "\n\t\tBienvenue " << file.name << endl;
		}

		else cout << "\n\t\tCompte n'est pas dans la base de donnees";


	} while (strcmp(Onefile.compte, file.compte) != 0);
	return Onefile;
}

client ReadNIP(client file)
{
	client Onefile;
	do {
		cout << "\n";
		cout << "Entrez votre Nip: ";
		cin >> Onefile.nip;

		if (strcmp(file.nip, Onefile.nip) != 0)

		{
			cout << "\n\t\tNip n'est pas dans la base de données";
		}


	} while (strcmp(file.nip, Onefile.nip) != 0);
	return Onefile;
}


void DisplayTransaction()
{
	cout << "Choisir votre Transacton" << endl;
	cout << "\t1 - Pour Deposer" << endl;
	cout << "\t2 - Pour Retirer" << endl;
	cout << "\t3 - Pour Consulter" << endl;
}
int DisplayVotreChoix()
{
	int choix;
	do {
		cout << "Entrez votre choix (1-3) : ";
		cin >> choix;
		cout << "\n";
	} while (choix <= 0 || choix >= 4);


	return choix;
}
client CalculateDeposite(client file)
{
	int deposer;
	client Onefile;
	do {
		cout << "Entrez le montant a deposer $ : ";
		cin >> deposer;
	} while (deposer <= 1 || deposer >= 20001);
	Onefile.solde = file.solde + deposer;
	Onefile.solde;
	return Onefile;
}
client CalcualteRetirer(client file)
{
	int retirer;
	int rem;
	client Onefile;

	do {
		cout << "Entrez le montant a retirer $ : ";

		cin >> retirer;
		Onefile.solde = file.solde - retirer;
		rem = retirer % 20;

	} while (retirer <= 19 || retirer >= 501 || rem != 0 || retirer>file.solde);

	return Onefile;
}
void DisplayInform(client file)
{
	cout << "--- la transaction a reussi ---\n" << endl;
	cout << "\n";
	cout << "Les infos du compte" << endl;
	cout << "\tNumero : " << file.compte << endl;
	cout << "\tClient :" << file.name << endl;
	cout << "\tNip : " << file.nip << endl;
	cout << "\tSolde $ : " << file.solde << endl;

}

void DisplayMSG(string msg)
{
	cout << "\n" << msg << endl;
}

void Save(client file) {
	ofstream myfile("C:\\Users\\zhangzhibo\\Desktop\\Project #3(ZhiboZhang)\\Clients.txt");


	if (myfile.is_open())
	{
		myfile << file.compte << "\n";
		myfile << file.name << "\n";;
		myfile << file.nip << "\n";
		myfile << file.solde;


		myfile.close();


	}
	else cout << "Unable to open file";


}

client Pull()
{
	ifstream in;
	in.open("C:\\Users\\zhangzhibo\\Desktop\\Project #3(ZhiboZhang)\\Clients.txt", ios::in);
	client file;

	in.getline(file.compte, 6);
	getline(in, file.name);
	in.getline(file.nip, 10);
	in >> file.solde;

	//cout << file.compte << "\n";
	//cout << file.name << "\n";
	//cout << file.nip << "\n";
	//cout << file.solde << "\n";
	

	return file;

}
