#include<iostream>
#include<string>
#include<conio.h>
#include<istream>
#include<fstream>
#include<iomanip>
#include<Windows.h>
using namespace std;
string name, admin, password, choice, phone, address, email;
string choicem;
double chart;
int medchoice, medquantity;
void login()
{
	cout << "                    =======================================================================" << endl;
	cout << "                                                WELCOME TO LOGIN PAGE                      " << endl;
	cout << "                    =======================================================================" << endl;
	int choice;
	cout << "                                                || ENTER 1 TO LOGIN  ||           " << endl;
	cin >> choice;
	if (choice == 1)
	{
		int count = 0;
		string na;
		string pass;
		cout << "ENTER USER NAME : ";
		cin >> na;
		cout << "Enter PASSWORD : ";
		cin >> pass;
		system("cls");
		ifstream f1("records.txt");
		while (f1 >> name >> password)
		{
			if (name == na && password == pass)
			{
				count = 1;
			}
		}
		if (count == 1)
		{
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << "            =======================================================================" << endl;
			cout << "                                         LOGIN SUCCESSFUL                          " << endl;
			cout << "            =======================================================================" << endl;
			Sleep(1000);
			system("cls");
		}
		f1.close();
	}
}
void Signup()
{
	cout << "                    =======================================================================" << endl;
	cout << "                                                WELCOME TO SIGNUP PAGE                      " << endl;
	cout << "                    =======================================================================" << endl;
	Sleep(1000);
	string user, passw, ur, pw, email, phone, address;
	cout << "ENTER USER NAME : ";
	cin >> user;
	cout << "Enter PASSWORD : ";
	cin >> passw;
	cout << "ENTER EMAIL : ";
	cin >> email;
	cout << "ENTER PHONE NUMBER : ";
	cin >> phone;
	cout << "ENTER ADDRESS :  ";
	cin >> address;
	ofstream f1("records.txt", ios::app);
	f1 << user << "      " << passw << "    " << email << "    " << phone << "    " << address << endl;
	cout << "                    =======================================================================" << endl;
	cout << "                                               SIGNUP SUCCESSFUL                           " << endl;
	cout << "                    =======================================================================" << endl;
	f1.close();
	Sleep(1000);
	system("cls");
	login();
}
void LOGINM()
{
	cout << "                    =======================================================================" << endl;
	cout << "                                                WELCOME TO LOGIN MENU                      " << endl;
	cout << "                    =======================================================================" << endl;
	cout << endl;
	cout << "                                                || ENTER 1 TO LOGIN  ||           " << endl;
	cout << "                                                || ENTER 2 TO SIGNUP ||           " << endl;
	cout << "                                                || ENTER YOUR CHOICE ||           " << endl;

	cin >> choice;
	system("cls");
	if (choice == "1")
	{
		login();
	}
	else if (choice == "2")
	{
		Signup();
	}
	else
	{
		LOGINM();
	}
}
void MENU1()
{
	cout << "1. FOR CONSULTATION ENTER CONSULT " << endl;
	cout << "2. FOR CHECKUP ENTER CHECKUP " << endl;
	cout << "3. FOR LAB REPORTS ENTER LAB " << endl;
	cout << "4. FOR PHARMACY ENTER PHARMACY " << endl;
	cout << "5. FOR CART ENTER CART " << endl;
	cout << "6. FOR INVOICE ENTER INVOICE " << endl;
	cout << "ENTER < NULL > FOR EXIT " << endl;
	cout << "ENTER CHOICE :";
	cin >> choicem;
	if (choicem == "Q")
	{
		std::system("cls");
		MENU1();
	}
}
void processing()
{
	cout << " ENTER QUANTITY ";
	cin >> medquantity;
	chart += medquantity;
	cout << medquantity << " ADDED TO CART SUESSFULLY " << endl;
	chart += 1;
}
void card()
{
	string debitinfo = "", confrmation;
	cout << "ENTER 8 DIGIT ACCOUNT NUMBER " << endl;
	cin >> debitinfo;
	cout << " --------------- ENTER -> CONFIRM <- TO CONFIRM YOUR ORDER --------------- " << endl;
	cin >> confrmation;
	if (confrmation == "confirm" || confrmation == "CONFIRM" || confrmation == "Confirm" || confrmation == "1")
	{
		cout << endl;
		cout << " --------------- YOUR ORDER IS PLACED SUCCESSFULLY --------------- " << endl;
		cout << " --------------- ORDER WILL BE DELIVER IN 2-3 HOURS --------------- " << endl;
		cout << endl;
		cout << endl;
		cout << " ------------------------- THANK YOU FOR USING DAWAI APP ------------------------- " << endl;
	}
	else
	{
		cout << "TRY AGAIN " << endl;
		card();
	}
}
void cash()
{
	string confrmation = "";
	cout << "CASH ON DELIVERY " << endl;
	cout << " --------------- ENTER -> CONFIRM <- TO CONFIRM YOUR ORDER --------------- " << endl;
	cin >> confrmation;
	if (confrmation == "confirm" || confrmation == "CONFIRM" || confrmation == "Confirm" || confrmation == "1")
	{
		cout << endl;
		cout << " --------------- YOUR ORDER IS PLACED SUCCESSFULLY --------------- " << endl;
		cout << " --------------- ORDER WILL BE DELIVER IN 2-3 HOURS --------------- " << endl;
		cout << endl;
		cout << endl;
		cout << " ------------------------- THANK YOU FOR USING DAWAI APP ------------------------- " << endl;
	}
	else
	{
		cout << "TRY AGAIN " << endl;
		cash();
	}
}
class Dawai_App
{
public:
	virtual void Menu() = 0;
};
class Catagorize
{
	static string cuopt, condition, con;
public:
	void process()
	{
		MENU1();
	}
};
string Catagorize::condition;
string Catagorize::cuopt;
string Catagorize::con;
class Doctor :public Catagorize
{
public:
	void MENU()
	{
		cout << "ENTER TYPE OF DISEASE " << endl;
		cout << "1.DIABETESE " << endl;
		cout << "2.FEVER " << endl;
		cout << "3.LUNGS " << endl;
		cout << "4.JOINTS " << endl;
		cout << "5.LIVER " << endl;
		cout << "ENTER < Q > TO RETURN TO MAIN MENU " << endl;
	}

};
class Consultation :public Catagorize
{
protected:
	string slot, cs;
public:
	void MENU()
	{
		cout << "1.CONSULTATION SLOT WITH MBBS DOCTOR " << endl;
		cout << "2.CONSULTATION SLOT WITH PHYSIOTHERAPIST DOCTOR " << endl;
		cout << "3.CONSULTATION SLOT WITH NEUROLOGIST DOCTOR " << endl;
		cout << "4.CONSULTATION SLOT WITH SKIN DOCTOR " << endl;
		cout << "5.CONSULTATION SLOT WITH LUNGS DOCTOR " << endl;
	}
};
class Lab_Reports :public Catagorize
{
public:
	void MENU()
	{
		cout << " 1.DO YOU WANT TO GIVE BLOOD TESTS ?" << endl;
		cout << " 2.DO YOU WANT TO RECEIVE BLOOD TESTS REPORTS ?" << endl;
		cout << "ENTER < Q > TO RETURN TO MAIN MENU" << endl;
	}
};
class Medicine
{
	string catchoice;
public:
	Medicine() {}
	void arry()
	{
		ofstream f1("MENU.txt", ios::app);
		string a[15] = { "BLOOD PRESSURE","SKIN DISEASE", "PAIN KILLERS", "DIABETES", "HEPATITIS", "JAUNDICE","VITAMINS", "CALCIUM", "CANCER","LUNGS", "FLU", "SHAMPOOS","FACE WASH","CONDITIONERS " };
		for (int i = 0; i < 12; ++i)
		{
			f1 << a[i] << "  " << endl;
		}
		f1.close();
	}
	void MENU()
	{
		string condition;
		arry();
		do {
			cout << " --------------- WE HAVE ALL THESE CATAGORIES OF MEDICANES --------------- " << endl;
			cout << endl;
			cout << " --------------- ENTER SERIAL NUMBER OF MEDICANE CATAGORY WHICH YOU WANT --------------- " << endl;
			cout << endl;
			cout << "       Sr.    NAME       " << endl;
			cout << endl;
			cout << " -----> 1- BLOOD PRESSURE   ----- " << endl;
			cout << " -----> 2- SKIN DISEASE    --- " << endl;
			cout << " -----> 3- PAIN KILLERS     ----- " << endl;
			cout << " -----> 4- DIABETES        ----- " << endl;
			cout << " -----> 5- HEPATITIS        ----- " << endl;
			cout << " -----> 6- JAUNDICE         ----- " << endl;
			cout << " -----> 7- VITAMINS         ----- " << endl;
			cout << " -----> 8- CALCIUM          ----- " << endl;
			cout << " -----> 9- CANCER           ----- " << endl;
			cout << " ----> 10- LUNGS            ----- " << endl;
			cout << " ----> 11- FLU              ----- " << endl;
			cout << " ----> 12- OILS             ----- " << endl;
			cout << " ----> 13- SHAMPOOS         ----- " << endl;
			cout << " ----> 14- FACE WASH        ----- " << endl;
			cout << " ----> 15- CONDITIONERS     ----- " << endl;
			cout << "ENTER < Q > TO RETURN TO MAIN MENU" << endl;
			cout << "ENTER CHOICE" << endl;
			cin >> this->catchoice;
			std::system("cls");
			if (catchoice == "Q")
			{
				std::system("cls");
				MENU1();
			}
			else if (catchoice == "1")
			{
				ofstream f1("blood.txt", ios::app);
				string a[5] = { "TENORMIN (500 mg)", " PLENDIL (500 mg)", "ADALAT CC (500 mg)", "CALAN SR (500 mg)", "SULAR (500 mg)" };
				int  b[5] = { 300, 1200,880, 570, 1800 };
				for (int i = 0; i < 5; ++i)
				{
					f1 << a[i] << "  " << b[i] << endl;
				}
				cout << " --------------- BLOOD PRESSURE  --------------- " << endl;
				cout << endl;
				string Name[5] = { "TENORMIN (500 mg)", " PLENDIL (500 mg)", "ADALAT CC (500 mg)", "CALAN SR (500 mg)", "SULAR (500 mg)" };
				int  cost[5] = { 300, 1200,880, 570, 1800 };
				int Quantity[5] = { 100,70,80,50,40 };
				for (int i = 0; i < 5; i++)
				{
					cout << "Medicine Name: " << Name[i] << "----- Cost: " << cost[i] << "----- Quantitiy in stock: " << Quantity[i] << endl;
					cout << "ENTER q TO RETURN TO MENU AGAIN " << endl;
					string q1;
					if (q1 == "q")
					{
						MENU();
					}
				}
				f1.close();
				cin >> medchoice;
				if (medchoice == 1)
				{
					processing();
				}
				else if (medchoice == 2)
				{
					processing();
				}
				else if (medchoice == 3)
				{
					processing();
				}
				else if (medchoice == 4)
				{
					processing();
				}
				else if (medchoice == 5)
				{
					processing();
				}
			}
			else if (catchoice == "2")
			{
				ofstream f1("skin.txt", ios::app);
				string a[5] = { "ALLANTOIN", " AMOROLFINE", "BENZYL BENZOATE", "BIAFINE", "CEFDIIR" };
				int  b[5] = { 350, 450,500, 550, 600 };
				for (int i = 0; i < 5; i++)
				{
					f1 << a[i] << "  " << b[i] << endl;
				}
				cout << " --------------- SKIN DISEASES  --------------- " << endl;
				cout << endl;
				string Name[5] = { "ALLANTOIN", " AMOROLFINE", "BENZYL BENZOATE", "BIAFINE", "CEFDIIR" };
				int cost[5] = { 350, 450, 500, 550, 600 };
				int Quantity[5] = { 100,70,80,50,40 };
				for (int i = 0; i < 5; i++) {
					cout << "Medicine Name: " << Name[i] << "----- Cost: " << cost[i] << "----- Quantitiy in stock: " << Quantity[i] << endl;
					cout << "ENTER q TO RETURN TO MENU AGAIN " << endl;
					string q1;
					if (q1 == "q")
					{
						MENU();
					}
				}
				f1.close();
				cin >> medchoice;
				if (medchoice == 1)
				{
					processing();
				}
				else if (medchoice == 2)
				{
					processing();
				}
				else if (medchoice == 3)
				{
					processing();
				}
				else if (medchoice == 4)
				{
					processing();
				}
				else if (medchoice == 5)
				{
					processing();
				}
			}
			else if (catchoice == "3")
			{
				ofstream f1("pain.txt", ios::app);
				string a[5] = { "PANADOL (500 mg)", " OXYCONTIN (500 mg)", "MORPHINE (500 mg)", "OPANA (500 mg)", "TRAMADOL (500 mg)" };
				int  b[5] = { 30, 450,500, 550, 600 };
				for (int i = 0; i < 5; ++i)
				{
					f1 << a[i] << "  " << b[i] << endl;
				}
				cout << " --------------- PAIN KILLERS  --------------- " << endl;
				cout << endl;
				string Name[5] = { "PANADOL (500 mg)", " OXYCONTIN (500 mg)", "MORPHINE (500 mg)", "OPANA (500 mg)", "TRAMADOL (500 mg)" };
				int cost[5] = { 30, 450,500, 550, 600 };
				int Quantity[5] = { 100,70,80,50,40 };
				for (int i = 0; i < 5; i++)
				{
					cout << "Medicine Name: " << Name[i] << "----- Cost: " << cost[i] << "----- Quantitiy in stock: " << Quantity[i] << endl;
					cout << "ENTER q TO RETURN TO MENU AGAIN " << endl;
					string q1;
					if (q1 == "q")
					{
						MENU();
					}
				}
				f1.close();
				cin >> medchoice;
				if (medchoice == 1)
				{
					processing();
				}
				else if (medchoice == 2)
				{
					processing();
				}
				else if (medchoice == 3)
				{
					processing();
				}
				else if (medchoice == 4)
				{
					processing();
				}
				else if (medchoice == 5)
				{
					processing();
				}
			}
			else if (catchoice == "4")
			{
				ofstream f1("diabetes.txt", ios::app);
				string a[5] = { "INSULIN (500 mg)", " METFORMIN (500 mg)", "GLIPIZIDE (500 mg)", "GLIMEPIRIDE (500 mg)", "INVOKANA (500 mg)" };
				int  b[5] = { 340, 1450,600, 750, 600 };
				for (int i = 0; i < 5; ++i)
				{
					f1 << a[i] << "  " << b[i] << endl;
				}
				cout << " --------------- DIABETES  --------------- " << endl;
				cout << endl;
				string Name[5] = { "INSULIN (500 mg)", " METFORMIN (500 mg)", "GLIPIZIDE (500 mg)", "GLIMEPIRIDE (500 mg)", "INVOKANA (500 mg)" };
				int cost[5] = { 340, 1450,600, 750, 600 };
				int Quantity[5] = { 100,70,80,50,40 };
				for (int i = 0; i < 5; i++)
				{
					cout << "Medicine Name: " << Name[i] << "----- Cost: " << cost[i] << "----- Quantitiy in stock: " << Quantity[i] << endl;
					cout << "ENTER q TO RETURN TO MENU AGAIN " << endl;
					string q1;
					if (q1 == "q")
					{
						MENU();
					}
				}
				f1.close();
				cout << " ENTER CHOICE ";
				cin >> medchoice;
				if (medchoice == 1)
				{
					processing();
				}
				else if (medchoice == 2)
				{
					processing();
				}
				else if (medchoice == 3)
				{
					processing();
				}
				else if (medchoice == 4)
				{
					processing();
				}
				else if (medchoice == 5)
				{
					processing();
				}
			}
			else if (catchoice == "5")
			{
				ofstream f1("hapatitus.txt", ios::app);
				string a[5] = { "DECLATASVIR (500 mg)", " SIMEPREVIR (500 mg)", "INTERFERON ALFA-2B (500 mg)", "INTERFERON ALFACON-1 (500 mg)", "INTERFERON ALFA-TWO B (500 mg)" };
				int  b[5] = { 550, 800,970, 890, 1600 };
				for (int i = 0; i < 5; ++i)
				{
					f1 << a[i] << "  " << b[i] << endl;
				}
				cout << " --------------- HEPATITIS --------------- " << endl;
				cout << endl;
				string Name[5] = { "DECLATASVIR (500 mg)", " SIMEPREVIR (500 mg)", "INTERFERON ALFA-2B (500 mg)", "INTERFERON ALFACON-1 (500 mg)", "INTERFERON ALFA-TWO B (500 mg)" };
				int cost[5] = { 550, 800,970, 890, 1600 };
				int Quantity[5] = { 100,70,80,50,40 };
				for (int i = 0; i < 5; i++)
				{
					cout << "Medicine Name: " << Name[i] << "----- Cost: " << cost[i] << "----- Quantitiy in stock: " << Quantity[i] << endl;
					cout << "ENTER q TO RETURN TO MENU AGAIN " << endl;
					string q1;
					if (q1 == "q")
					{
						MENU();
					}
				}
				f1.close();
				cout << " ENTER CHOICE ";
				cin >> medchoice;
				if (medchoice == 1)
				{

					processing();
				}
				else if (medchoice == 2)
				{
					processing();
				}
				else if (medchoice == 3)
				{
					processing();
				}
				else if (medchoice == 4)
				{
					processing();
				}
				else if (medchoice == 5)
				{
					processing();
				}
			}
			else if (catchoice == "6")
			{
				ofstream f1("jaundice.txt", ios::app);
				string a[5] = { "COLESTIPOL (500 mg)", " QUESTRAN (500 mg)", "HEPA MARZ (500 mg)", "CEFTRIAXONE (500 mg)", " URSODEC (500 mg)" };
				int  b[5] = { 5980, 850,940, 690, 2200 };
				for (int i = 0; i < 5; ++i)
				{
					f1 << a[i] << "  " << b[i] << endl;
				}
				cout << " --------------- JAUNDICE --------------- " << endl;
				cout << endl;
				string Name[5] = { "COLESTIPOL (500 mg)", " QUESTRAN (500 mg)", "HEPA MARZ (500 mg)", "CEFTRIAXONE (500 mg)", " URSODEC (500 mg)" };
				int cost[5] = { 5980, 850,940, 690, 2200 };
				int Quantity[5] = { 100,70,80,50,40 };
				for (int i = 0; i < 5; i++)
				{
					cout << "Medicine Name: " << Name[i] << "----- Cost: " << cost[i] << "----- Quantitiy in stock: " << Quantity[i] << endl;
					cout << "ENTER q TO RETURN TO MENU AGAIN " << endl;
					string q1;
					if (q1 == "q")
					{
						MENU();
					}
				}
				f1.close();
				cout << " ENTER CHOICE ";
				cin >> medchoice;
				if (medchoice == 1)
				{
					processing();
				}
				else if (medchoice == 2)
				{
					processing();
				}
				else if (medchoice == 3)
				{
					processing();
				}
				else if (medchoice == 4)
				{
					processing();
				}
				else if (medchoice == 5)
				{
					processing();
				}
			}
			else if (catchoice == "7")
			{
				ofstream f1("vitamins.txt", ios::app);
				string a[5] = { "FOLIC ACID TABLETS (500 mg)", " B - COMPLEX (500 mg)", "EXEN - D (500 mg)", "DRISDOL (500 mg)", " CALCIFEROL (500 mg)" };
				int  b[5] = { 900, 850,550, 550, 800 };
				for (int i = 0; i < 5; ++i)
				{
					f1 << a[i] << "  " << b[i] << endl;
				}
				cout << " --------------- VITAMINS --------------- " << endl;
				cout << endl;
				string Name[5] = { "FOLIC ACID TABLETS (500 mg)", " B - COMPLEX (500 mg)", "EXEN - D (500 mg)", "DRISDOL (500 mg)", " CALCIFEROL (500 mg)" };
				int cost[5] = { 900, 850,550, 550, 800 };
				int Quantity[5] = { 100,70,80,50,40 };
				for (int i = 0; i < 5; i++)
				{
					cout << "Medicine Name: " << Name[i] << "----- Cost: " << cost[i] << "----- Quantitiy in stock: " << Quantity[i] << endl;
					cout << "ENTER q TO RETURN TO MENU AGAIN " << endl;
					string q1;
					if (q1 == "q")
					{
						MENU();
					}
				}
				f1.close();
				cout << " ENTER CHOICE ";
				cin >> medchoice;
				if (medchoice == 1)
				{
					processing();
				}
				else  if (medchoice == 2)
				{
					processing();
				}
				else if (medchoice == 3)
				{
					processing();
				}
				else if (medchoice == 4)
				{
					processing();
				}
				else if (medchoice == 5)
				{
					processing();
				}
			}
			else if (catchoice == "8")
			{
				ofstream f1("calcium.txt", ios::app);
				string a[5] = { "CARBAMIDE FORTE CALCIUM TABLETS (500 mg)", "NATURYZ CALCIUM PLUS (500 mg)", "NUTRI CAL-D (500 mg)", "CaC 1000 PLUS (500 mg)", "OSTEOCARE (500 mg)" };
				int  b[5] = { 660, 900,590, 430, 800 };
				for (int i = 0; i < 5; ++i)
				{
					f1 << a[i] << "  " << b[i] << endl;
				}
				cout << " --------------- CALCIUM --------------- " << endl;
				cout << endl;
				string Name[5] = { "CARBAMIDE FORTE CALCIUM TABLETS (500 mg)", "NATURYZ CALCIUM PLUS (500 mg)", "NUTRI CAL-D (500 mg)", "CaC 1000 PLUS (500 mg)", "OSTEOCARE (500 mg)" };
				int cost[5] = { 660, 900,590, 430, 800 };
				int Quantity[5] = { 100,70,80,50,40 };
				for (int i = 0; i < 5; i++)
				{
					cout << "Medicine Name: " << Name[i] << "----- Cost: " << cost[i] << "----- Quantitiy in stock: " << Quantity[i] << endl;
					string q1;
					if (q1 == "q")
					{
						MENU();
					}
				}
				f1.close();
				cout << " ENTER CHOICE ";
				cin >> medchoice;
				if (medchoice == 1)
				{
					processing();
				}
				else if (medchoice == 2)
				{
					processing();
				}
				else if (medchoice == 3)
				{
					processing();
				}
				else if (medchoice == 4)
				{
					processing();
				}
				else if (medchoice == 5)
				{
					processing();
				}
			}
			else if (catchoice == "9")
			{
				ofstream f1("cancer.txt", ios::app);
				string a[5] = { "LEVACT (500 mg)", "AVASTIN (500 mg)", "TARGRETIN (500 mg)", "CASODEX (500 mg)", "IBRANCE (500 mg)" };
				int  b[5] = { 6160, 9100,1590, 3430, 6800 };
				for (int i = 0; i < 5; ++i)
				{
					f1 << a[i] << "  " << b[i] << endl;
				}
				cout << " --------------- CANCER --------------- " << endl;
				cout << endl;
				string Name[5] = { "LEVACT (500 mg)", "AVASTIN (500 mg)", "TARGRETIN (500 mg)", "CASODEX (500 mg)", "IBRANCE (500 mg)" };
				int cost[5] = { 6160, 9100,1590, 3430, 6800 };
				int Quantity[5] = { 100,70,80,50,40 };
				for (int i = 0; i < 5; i++)
				{
					cout << "Medicine Name: " << Name[i] << "----- Cost: " << cost[i] << "----- Quantitiy in stock: " << Quantity[i] << endl;
					string q1;
					if (q1 == "q")
					{
						MENU();
					}
				}
				f1.close();
				cout << " ENTER CHOICE ";
				cin >> medchoice;
				if (medchoice == 1)
				{
					processing();
				}
				else if (medchoice == 2)
				{
					processing();
				}
				else if (medchoice == 3)
				{
					processing();
				}
				else if (medchoice == 4)
				{
					processing();
				}
				else if (medchoice == 5)
				{
					processing();
				}
			}
			else if (catchoice == "10")
			{
				ofstream f1("lungs.txt", ios::app);
				string a[5] = { "ZITHROMAX (500 mg)", "ALTHROCIN (500 mg)", "NIZORAL (500 mg)", "ALVESCO (500 mg)", "PULMICORT FLEXHALER (500 mg)" };
				int  b[5] = { 10000, 9500,690, 3930, 800 };
				for (int i = 0; i < 5; ++i)
				{
					f1 << a[i] << "  " << b[i] << endl;
				}
				cout << " --------------- LUNGS ---------------- " << endl;
				cout << endl;
				string Name[5] = { "ZITHROMAX (500 mg)", "ALTHROCIN (500 mg)", "NIZORAL (500 mg)", "ALVESCO (500 mg)", "PULMICORT FLEXHALER (500 mg)" };
				int cost[5] = { 10000, 9500,690, 3930, 800 };
				int Quantity[5] = { 100,70,80,50,40 };
				for (int i = 0; i < 5; i++)
				{
					cout << "Medicine Name: " << Name[i] << "----- Cost: " << cost[i] << "----- Quantitiy in stock: " << Quantity[i] << endl;
					string q1;
					if (q1 == "q")
					{
						MENU();
					}
				}
				f1.close();
				cout << " ENTER CHOICE ";
				cin >> medchoice;
				if (medchoice == 1)
				{
					processing();
				}
				else if (medchoice == 2)
				{
					processing();
				}
				else if (medchoice == 3)
				{
					processing();
				}
				else if (medchoice == 4)
				{
					processing();
				}
				else if (medchoice == 5)
				{
					processing();
				}
			}
			else if (catchoice == "11")
			{
				ofstream f1("flu.txt", ios::app);
				string a[5] = { "RALENZA (500 mg)", "RAPIVAB (500 mg)", "RIGIX (500 mg)", "XOFLUZA (500 mg)", "TAMIFLU (500 mg)" };
				int  b[5] = { 300, 500,190, 830, 500 };
				for (int i = 0; i < 5; ++i)
				{
					f1 << a[i] << "  " << b[i] << endl;
				}
				cout << " --------------- FLU --------------- " << endl;
				cout << endl;
				string Name[5] = { "RALENZA (500 mg)", "RAPIVAB (500 mg)", "RIGIX (500 mg)", "XOFLUZA (500 mg)", "TAMIFLU (500 mg)" };
				int cost[5] = { 300, 500,190, 830, 500 };
				int Quantity[5] = { 100,70,80,50,40 };
				for (int i = 0; i < 5; i++)
				{
					cout << "Medicine Name: " << Name[i] << "----- Cost: " << cost[i] << "----- Quantitiy in stock: " << Quantity[i] << endl;
					string q1;
					if (q1 == "q")
					{
						MENU();
					}
				}
				f1.close();
				cout << " ENTER CHOICE ";
				cin >> medchoice;
				if (medchoice == 1)
				{
					processing();
				}
				else if (medchoice == 2)
				{
					processing();
				}
				else if (medchoice == 3)
				{
					processing();
				}
				else if (medchoice == 4)
				{
					processing();
				}
				else if (medchoice == 5)
				{
					processing();
				}
			}
			else if (catchoice == "12")
			{
				ofstream f1("oils.txt", ios::app);
				string a[5] = { "KESHIA HAIR OIL (500 mg)", "DABUR AMLA HAIR OIL (500 mg)", "BIO AMLA HAIR OIL (500 mg)", "VATIKA HAIR OIL (500 mg)", "CASTOR OIL (500 mg)" };
				int  b[5] = { 300, 450,190, 280, 100 };
				for (int i = 0; i < 5; ++i)
				{
					f1 << a[i] << "  " << b[i] << endl;
				}
				cout << " --------------- OILS --------------- " << endl;
				cout << endl;
				string Name[5] = { "KESHIA HAIR OIL (500 mg)", "DABUR AMLA HAIR OIL (500 mg)", "BIO AMLA HAIR OIL (500 mg)", "VATIKA HAIR OIL (500 mg)", "CASTOR OIL (500 mg)" };
				int cost[5] = { 300, 450,190, 280, 100 };
				int Quantity[5] = { 100,70,80,50,40 };
				for (int i = 0; i < 5; i++)
				{
					cout << "Medicine Name: " << Name[i] << "----- Cost: " << cost[i] << "----- Quantitiy in stock: " << Quantity[i] << endl;
					string q1;
					if (q1 == "q")
					{
						MENU();
					}
				}
				f1.close();
				cout << " ENTER CHOICE ";
				cin >> medchoice;
				if (medchoice == 1)
				{
					processing();
				}
				else if (medchoice == 2)
				{
					processing();
				}
				else if (medchoice == 3)
				{
					processing();
				}
				else if (medchoice == 4)
				{
					processing();
				}
				else if (medchoice == 5)
				{
					processing();
				}
			}
			else if (catchoice == "13")
			{
				ofstream f1("shampoo.txt", ios::app);
				string a[5] = { "DOVE (500 mg)", "SUNSILK (500 mg)", "PANTENE (500 mg)", "CLEAR (500 mg)", "HEAD N SHOULDER (500 mg)" };
				int  b[5] = { 1300, 450,490, 1280, 500 };
				for (int i = 0; i < 5; ++i)
				{
					f1 << a[i] << "  " << b[i] << endl;
				}
				cout << " --------------- SHAMPOOS --------------- " << endl;
				cout << endl;
				string Name[5] = { "DOVE (500 mg)", "SUNSILK (500 mg)", "PANTENE (500 mg)", "CLEAR (500 mg)", "HEAD N SHOULDER (500 mg)" };
				int cost[5] = { 1300, 450,490, 1280, 500 };
				int Quantity[5] = { 100,70,80,50,40 };
				for (int i = 0; i < 5; i++)
				{
					cout << "Medicine Name: " << Name[i] << "----- Cost: " << cost[i] << "----- Quantitiy in stock: " << Quantity[i] << endl;
					string q1;
					if (q1 == "q")
					{
						MENU();
					}
				}
				f1.close();
				cout << " ENTER CHOICE ";
				cin >> medchoice;
				if (medchoice == 1)
				{
					processing();
				}
				else if (medchoice == 2)
				{
					processing();
				}
				else if (medchoice == 3)
				{
					processing();
				}
				else if (medchoice == 4)
				{
					processing();
				}
				else if (medchoice == 5)
				{
					processing();
				}
			}
			else if (catchoice == "14")
			{
				ofstream f1("facewash.txt", ios::app);
				string a[5] = { "PONDS (500 mg)", "DOVE (500 mg)", "GARNIER (500 mg)", "FAIR N LOVELY (500 mg)", "HIMALIYA (500 mg)" };
				int  b[5] = { 500, 450,490, 280, 500 };
				for (int i = 0; i < 5; ++i)
				{
					f1 << a[i] << "  " << b[i] << endl;
				}
				cout << " --------------- FACE WASH --------------- " << endl;
				cout << endl;
				string Name[5] = { "PONDS (500 mg)", "DOVE (500 mg)", "GARNIER (500 mg)", "FAIR N LOVELY (500 mg)", "HIMALIYA (500 mg)" };
				int cost[5] = { 500, 450,490, 280, 500 };
				int Quantity[5] = { 100,70,80,50,40 };
				for (int i = 0; i < 5; i++)
				{
					cout << "Medicine Name: " << Name[i] << "----- Cost: " << cost[i] << "----- Quantitiy in stock: " << Quantity[i] << endl;
					string q1;
					if (q1 == "q")
					{
						MENU();
					}
				}
				f1.close();
				cout << " ENTER CHOICE ";
				cin >> medchoice;
				if (medchoice == 1)
				{
					processing();
				}
				else if (medchoice == 2)
				{
					processing();
				}
				else if (medchoice == 3)
				{
					processing();
				}
				else if (medchoice == 4)
				{
					processing();
				}
				else if (medchoice == 5)
				{
					processing();
				}
			}
			else if (catchoice == "15")
			{
				ofstream f1("conditioners.txt", ios::app);
				string a[5] = { "DOVE (500 mg)", "SUNSILK (500 mg)", "PANTENE (500 mg)", "CLEAR (500 mg)", "HEAD N SHOULDER (500 mg)" };
				int  b[5] = { 1300, 450,490, 1280, 500 };
				for (int i = 0; i < 5; ++i)
				{
					f1 << a[i] << "  " << b[i] << endl;
				}
				cout << " --------------- CONDITIONERS --------------- " << endl;
				cout << endl;
				string Name[5] = { "DOVE (500 mg)", "SUNSILK (500 mg)", "PANTENE (500 mg)", "CLEAR (500 mg)", "HEAD N SHOULDER (500 mg)" };
				int cost[5] = { 1300, 450,490, 1280, 500 };
				int Quantity[5] = { 100,70,80,50,40 };
				for (int i = 0; i < 5; i++)
				{
					cout << "Medicine Name: " << Name[i] << "----- Cost: " << cost[i] << "----- Quantitiy in stock: " << Quantity[i] << endl;
					string q1;
					if (q1 == "q")
					{
						MENU();
					}
				}
				f1.close();
				cout << " ENTER CHOICE ";
				cin >> medchoice;
				if (medchoice == 1)
				{
					processing();
				}
				else if (medchoice == 2)
				{
					processing();
				}
				else if (medchoice == 3)
				{
					processing();
				}
				else if (medchoice == 4)
				{
					processing();
				}
				else if (medchoice == 5)
				{
					processing();
				}
			}
			cout << "DO YOU WANT TO PURCHASE MORE ?" << endl;
			cin >> condition;
		} while (condition == "yes");
		std::system("cls");
	}
	void showData()
	{

		/*cout << endl << "YOU HAVE " << carto2 << " ITEMS IN THE CART  " << endl << "QUANTITY : " << cart << endl;*/
	}
	void showmedicanes()
	{

	}
};
class Pharmacy :public Catagorize
{
	Medicine medicine;
public:
	Pharmacy()
	{

	}
	Pharmacy(Medicine& m) :medicine(m)
	{
		medicine.MENU();
	}
	void showData()
	{
		medicine.showData();
	}
};
class Lab_Tests :public Lab_Reports
{
	string condition, cart2;
	int currentdate = 25, days = 0, date = 0, topt = 0, bill = 1, pt1 = 1200, pt2 = 900, pt3 = 1350, pt4 = 1500, pt5 = 700;
	string lopt = "", pgender = "", pname = "", pid = "", test1 = "", test2 = "", test3 = "", test4 = "", test5 = "";
public:
	Lab_Tests() {}
	void giving()
	{
		cin >> lopt;

		do {
			if (lopt == "1")
			{
				cout << "HOW MANY TESTS YOU WANT TO DO ?" << endl;
				cin >> topt;
				if (topt == 5)
				{
					std::system("cls");
					cout << "ENTER NAME OF BLOOD TESTS" << endl;
					cin >> test1;
					cin >> test2;
					cin >> test3;
					cin >> test4;
					cin >> test5;
					cout << "5 TESTS ADDED IN RECORD " << endl;
					bill = pt1 + pt2 + pt3 + pt4 + pt5;
					cart2 += 5;
					cout << "YOUR TOTAL PAYABLE BILL FOR BLOOD TESTS = " << bill;
				}
				else if (topt == 4)
				{
					std::system("cls");
					cout << "ENTER NAME OF BLOOD TESTS" << endl;
					cin >> test1;
					cin >> test2;
					cin >> test3;
					cin >> test4;
					cout << "4 TESTS ADDED IN RECORD " << endl;
					bill = pt1 + pt2 + pt3 + pt4;
					cart2 += 4;
					cout << "YOUR TOTAL PAYABLE BILL FOR BLOOD TESTS = " << bill;
				}
				else if (topt == 3)
				{
					std::system("cls");
					cout << "ENTER NAME OF BLOOD TESTS" << endl;
					cin >> test1;
					cin >> test2;
					cin >> test3;
					cout << "3 TESTS ADDED IN RECORD " << endl;
					bill = pt1 + pt2 + pt3;
					cart2 += 3;
					cout << "YOUR TOTAL PAYABLE BILL FOR BLOOD TESTS = " << bill;
				}
				else if (topt == 2)
				{
					std::system("cls");
					cout << "ENTER NAME OF BLOOD TESTS" << endl;
					cin >> test1;
					cin >> test2;
					cout << "2 TESTS ADDED IN RECORD " << endl;
					bill = pt1 + pt2;
					cart2 += 2;
					cout << "YOUR TOTAL PAYABLE BILL FOR BLOOD TESTS = " << bill;
				}
				else if (topt == 5)
				{
					std::system("cls");
					cout << "ENTER NAME OF BLOOD TEST" << endl;
					cin >> test1;
					cout << "1 TEST ADDED IN RECORD " << endl;
					bill = pt1;
					cart2 += 1;
					cout << "YOUR TOTAL PAYABLE BILL FOR BLOOD TEST = " << bill << endl;
				}
				else
				{
					cout << "ENTER BETWEEN 1 AND 5" << endl;
					giving();
				}
			}
			std::system("cls");
			cout << "DO YOU WANT TO CONTINUE ?" << endl;
			cout << "ENTER < Q > TO RETURN TO MAIN MENU" << endl;
			cout << "ENTER < q > TO RETURN TO MENU" << endl;
			cin >> condition;
			if (condition == "q")
			{
				std::system("cls");
				MENU();
			}
			else if (condition == "Q")
			{
				std::system("cls");
				MENU1();
			}
		} while (condition == "yes");
		std::system("cls");
	}
	void receve()
	{
		string choce;
		do {
			string array[1];
			cout << "WHEN YOU GIVE YOUR BLOOD TESTS ENTER DATE ?" << endl;
			cin >> date;
			days = currentdate - date;
			if (days >= 5)
			{
				std::system("cls");
				cout << "--------------- YOUR REPORTS ARE READY ---------------" << endl;
				for (int i = 0; i < 1; i++)
				{
					cout << "ENTER PATIENT NAME" << endl;
					cin >> array[i];
					cout << "ENTER PATIENT GENDER" << endl;
					cin >> array[i];
					cout << "ENTER PATIENT AGE" << endl;
					cin >> array[i];
					cout << "ENTER PATIENT TEST ID" << endl;
					cin >> array[i];

				}
				for (int i = 0; i < 1; i++)
				{
					std::system("cls");
					cout << "NAME : " << array[i] << endl;
					cout << "AGE : " << array[i] << endl;
					cout << "GENDER : " << array[i] << endl;
					cout << "ID : " << array[i] << endl;
				}
				std::system("cls");
				cout << "--------------- COVID TEST ---------------" << endl;
				cout << endl;
				cout << "YOUR COVID TEST IS NEGATIVE " << endl;
				cout << "DO YOU WANT TO CONTINUE ?" << endl;
				cout << "ENTER < Q > TO RETURN TO MAIN MENU " << endl;
				cout << "ENTER < q > TO RETURN TO MENU " << endl;
				cin >> choce;
				if (choce == "q")
				{
					std::system("cls");
					MENU();
				}
				else if (choce == "Q")
				{
					std::system("cls");
					MENU1();
				}
			}
		} while (condition == "yes");
		std::system("cls");
	}
	void showlabtests()
	{
		cout << cart2;
	}
};
class Consultation_time :public Consultation
{
	string cart1;
	string cod2;
public:
	Consultation_time() {}
	void mbbs()
	{
		do {
			cout << " ----- DR.AHMAD KHAN -----" << endl;
			cout << " 1.CONSULTATION SLOT AVAILABLE IN MORNING FROM (8:00-12:00)" << endl;
			cout << " 2.CONSULTATION SLOT AVAILABLE IN EVENING FROM (5:00-6:30)" << endl;
			cout << "CONSULTATION FEE : 1200" << endl;
			cout << "DO YOU WANT TO BOOK ANY SLOT FOR CONSULTATION ?";
			cin >> slot;
			if (slot == "1" || slot == "Morning" || slot == "morning" || slot == "MORNING")
			{
				cout << " YOU HAVE SUCCESSFULY BOOKED MORNING SLOT FOR CONSULTATION " << endl;
				cout << "ENTER YES FOR FURTHER APPOINTMENTS" << endl;
				cout << "ENTER < Q > MAIN TO RETURN TO MAIN MENU" << endl;
				cin >> cs;
				if (cs == "yes" || cs == "YES" || cs == "Yes")
				{
					cart1 += 1;
					std::system("cls");
					MENU();

				}
				else
				{
					std::system("cls");
					MENU1();
				}
			}
			else if (slot == "2" || slot == "Evening" || slot == "evening" || slot == "EVENING")
			{
				cout << " YOU HAVE SUCCESSFULY BOOKED EVENING SLOT FOR CONSULTATION " << endl;
				if (cs == "yes" || cs == "YES" || cs == "Yes")
				{
					cart1 += 1;
					std::system("cls");
					MENU();
				}
				else
				{
					std::system("cls");
					MENU1();
				}
			}
			cout << "DO YOU WANT TO CONITUNE ?" << endl;
			cout << endl;
			cout << "ENTER < Q > MAIN TO RETURN TO MAIN MENU " << endl;
			cin >> cod2;
			if (cod2 == "Q")
			{
				std::system("cls");
				MENU1();
			}
			std::system("cls");
		} while (cod2 == "yes");
	}
	void physio()
	{
		do {
			cout << " ----- DR.SYED FURQAN -----" << endl;
			cout << " 1.CONSULTATION SLOT AVAILABLE IN MORNING FROM (9:00-11:00)" << endl;
			cout << " 2.CONSULTATION SLOT AVAILABLE IN EVENING FROM (6:00-7:00)" << endl;
			cout << "CONSULTATION FEE : 1000" << endl;
			cout << "DO YOU WANT TO BOOK ANY SLOT FOR CONSULTATION ?";
			cin >> slot;
			if (slot == "1" || slot == "Morning" || slot == "morning" || slot == "MORNING")
			{
				cout << " YOU HAVE SUCCESSFULY BOOKED MORNING SLOT FOR CONSULTATION " << endl;
				cout << "ENTER YES FOR FURTHER APPOINTMENTS" << endl;
				cout << "ENTER < Q > MAIN TO RETURN TO MAIN MENU" << endl;
				cin >> cs;
				if (cs == "yes" || cs == "YES" || cs == "Yes")
				{
					cart1 += 1;
					std::system("cls");
					MENU();
				}
				else
				{
					std::system("cls");
					MENU1();
				}
			}
			else if (slot == "2" || slot == "Evening" || slot == "evening" || slot == "EVENING")
			{
				cout << " YOU HAVE SUCCESSFULY BOOKED EVENING SLOT FOR CONSULTATION " << endl;
				cout << "ENTER YES FOR FURTHER APPOINTMENTS" << endl;
				cout << "ENTER MAIN TO RETURN TO MAIN MENU" << endl;
				cin >> cs;
				cout << "DO YOU WANT TO CONITUNE ?" << endl;
				cout << endl;
				cout << "ENTER < Q > MAIN TO RETURN TO MAIN MENU " << endl;
				cin >> cod2;
				if (cod2 == "Q")
				{
					std::system("cls");
					MENU1();
				}
			}
			std::system("cls");
		} while (cod2 == "yes");
	}
	void neuro()
	{
		do {
			cout << " ----- DR.KAMRAN -----" << endl;
			cout << " 1.CONSULTATION SLOT AVAILABLE IN MORNING FROM (10:00-12:00)" << endl;
			cout << " 2.CONSULTATION SLOT AVAILABLE IN EVENING FROM (5:30-7:30)" << endl;
			cout << "CONSULTATION FEE : 2000" << endl;
			cout << "DO YOU WANT TO BOOK ANY SLOT FOR CONSULTATION ?";
			cin >> slot;
			if (slot == "1" || slot == "Morning" || slot == "morning" || slot == "MORNING")
			{
				cout << " YOU HAVE SUCCESSFULY BOOKED MORNING SLOT FOR CONSULTATION " << endl;
				cout << "ENTER YES FOR FURTHER APPOINTMENTS" << endl;
				cout << "ENTER < Q > MAIN TO RETURN TO MAIN MENU" << endl;
				cin >> cs;
				if (cs == "yes" || cs == "YES" || cs == "Yes")
				{
					cart1 += 1;
					std::system("cls");
					MENU();
				}
				else
				{
					std::system("cls");
					MENU1();
				}
			}
			else if (slot == "2" || slot == "Evening" || slot == "evening" || slot == "EVENING")
			{
				cout << " YOU HAVE SUCCESSFULY BOOKED EVENING SLOT FOR CONSULTATION " << endl;
				cout << "ENTER YES FOR FURTHER APPOINTMENTS" << endl;
				cout << "ENTER < Q > MAIN TO RETURN TO MAIN MENU" << endl;
				cin >> cs;
				if (cs == "yes" || cs == "YES" || cs == "Yes")
				{
					cart1 += 1;
					std::system("cls");
					MENU();
				}
				else
				{
					std::system("cls");
					MENU1();
				}
			}
		} while (cod2 == "yes");
		std::system("cls");
	}
	void skin()
	{
		do {
			cout << " ----- DR.GHULAM RASOOL -----" << endl;
			cout << " 1.CONSULTATION SLOT AVAILABLE IN MORNING FROM (9:00-12:00)" << endl;
			cout << " 2.CONSULTATION SLOT AVAILABLE IN EVENING FROM (5:00-7:00)" << endl;
			cout << "CONSULTATION FEE : 800" << endl;
			cout << "DO YOU WANT TO BOOK ANY SLOT FOR CONSULTATION ?";
			cin >> slot;
			if (slot == "1" || slot == "Morning" || slot == "morning" || slot == "MORNING")
			{
				cout << " YOU HAVE SUCCESSFULY BOOKED MORNING SLOT FOR CONSULTATION " << endl;
				cout << "ENTER YES FOR FURTHER APPOINTMENTS" << endl;
				cout << "ENTER < Q > MAIN TO RETURN TO MAIN MENU" << endl;
				cin >> cs;
				if (cs == "yes" || cs == "YES" || cs == "Yes")
				{
					cart1 += 1;
					std::system("cls");
					MENU();
				}
				else
				{
					std::system("cls");
					MENU1();
				}
			}
			else if (slot == "2" || slot == "Evening" || slot == "evening" || slot == "EVENING")
			{
				cout << " YOU HAVE SUCCESSFULY BOOKED EVENING SLOT FOR CONSULTATION " << endl;
				cout << "ENTER YES FOR FURTHER APPOINTMENTS" << endl;
				cout << "ENTER < Q > MAIN TO RETURN TO MAIN MENU" << endl;
				cin >> cs;
				if (cs == "yes" || cs == "YES" || cs == "Yes")
				{
					cart1 += 1;
					std::system("cls");
					MENU();
				}
				else
				{
					std::system("cls");
					MENU1();
				}
			}cout << "DO YOU WANT TO CONTINUE ?" << endl;
			std::system("cls");
		} while (cod2 == "yes");
	}
	void lungs1()
	{
		do {
			cout << " ----- DR.IMTIAZ AHMAD KHAN -----" << endl;
			cout << " 1.CONSULTATION SLOT AVAILABLE IN MORNING FROM (9:30-12:30)" << endl;
			cout << " 2.CONSULTATION SLOT AVAILABLE IN EVENING FROM (6:00-8:00)" << endl;
			cout << "CONSULTATION FEE : 1500" << endl;
			cout << "DO YOU WANT TO BOOK ANY SLOT FOR CONSULTATION ?";
			cin >> slot;
			if (slot == "1" || slot == "Morning" || slot == "morning" || slot == "MORNING")
			{
				cout << " YOU HAVE SUCCESSFULY BOOKED MORNING SLOT FOR CONSULTATION " << endl;
				cout << "ENTER YES FOR FURTHER APPOINTMENTS" << endl;
				cout << "ENTER < Q > MAIN TO RETURN TO MAIN MENU" << endl;
				cin >> cs;
				if (cs == "yes" || cs == "YES" || cs == "Yes")
				{
					cart1 += 1;
					std::system("cls");
					MENU();
				}
				else
				{
					std::system("cls");
					MENU1();
				}
			}
			else if (slot == "2" || slot == "Evening" || slot == "evening" || slot == "EVENING")
			{
				cout << " YOU HAVE SUCCESSFULY BOOKED EVENING SLOT FOR CONSULTATION " << endl;
				cout << "ENTER YES FOR FURTHER APPOINTMENTS" << endl;
				cout << "ENTER < Q > MAIN TO RETURN TO MAIN MENU" << endl;
				cin >> cs;
				if (cs == "yes" || cs == "YES" || cs == "Yes")
				{
					cart1 += 1;
					std::system("cls");
					MENU();
				}
				else
				{
					MENU1();
				}
			}cout << "DO YOU WANT TO CONTINUE ?" << endl;
		} while (cod2 == "yes");
		std::system("cls");
	};
	void showconsulttime()
	{
		cout << cart1 << endl;
	}
};
class Doctor_Type :public Doctor
{
public:
	string con, con1, carto = "";
	Doctor_Type() {}

	void Ddib()
	{
		do {
			{
				cout << "CHECK UP FEE OF DR.RAZIA AHMAD : 1000 " << endl;
				cout << "DOCTOR CAN VISIT TO YOU BETWEEN 10:00-12:00 IN MORNING " << endl;
				cout << "YOU WANT TO CONFIRM ?" << endl;
				cin >> con;
				if (con == "yes")
				{
					carto += 1;
					cout << "DO YOU WANT TO CONTINUE ?" << endl;
					cin >> con1;
					if (con1 == "yes");
					{
						cout << "Enter q for menu" << endl;
						cout << "Enter Q for Main menu" << endl;
						cin >> con1;
						if (con1 == "q")
						{
							std::system("cls");
							MENU();
						}
						else
						{
							std::system("cls");
							MENU1();
						}
					}

				}
			}
			cout << "DO YOU WANT TO CONTINUE ?" << endl;
			cin >> con1;
			std::system("cls");
		} while (con1 == "yes");
	}
	void fever()
	{
		do {
			cout << "CHECK UP FEE OF DR.SAKINA AHMAD : 1000 " << endl;
			cout << "DOCTOR CAN VISIT TO YOU BETWEEN 10:00-12:00 IN MORNING " << endl;
			cout << "YOU WANT TO CONFIRM ?" << endl;
			cin >> con;
			if (con == "yes")
			{
				carto += 1;
				cout << "Enter q for menu" << endl;
				cout << "Enter Q for Main menu" << endl;
				cin >> con1;
				if (con1 == "q")
				{
					std::system("cls");
					MENU();
				}
				else
				{
					std::system("cls");
					MENU1();
				}

			}
			cout << "DO YOU WANT TO CONTINUE ?" << endl;
			cin >> con1;
		} while (con1 == "yes");
	}
	void lungs()
	{
		do {
			cout << "CHECK UP FEE OF DR.SAFIA AHMAD : 1500 " << endl;
			cout << "DOCTOR CAN VISIT TO YOU BETWEEN 10:00-12:00 IN MORNING " << endl;
			cout << "YOU WANT TO CONFIRM ?" << endl;
			cin >> con;
			if (con == "yes")
			{
				carto += 1;
				cout << "Enter q for menu" << endl;
				cout << "Enter Q for Main menu" << endl;
				cin >> con1;
				if (con1 == "q")
				{
					std::system("cls");
					MENU();
				}
				else
				{
					std::system("cls");
					MENU1();
				}

			}
			cout << "DO YOU WANT TO CONTINUE ?" << endl;
			cin >> con1;
		} while (con1 == "yes");
	}
	void joints()
	{
		do {
			cout << "CHECK UP FEE OF DR.FARKHANDA AHMAD : 1200 " << endl;
			cout << "DOCTOR CAN VISIT TO YOU BETWEEN 10:00-12:00 IN MORNING " << endl;
			cout << "YOU WANT TO CONFIRM ?" << endl;
			cin >> con;
			if (con == "yes")
			{
				carto += 1;
				cout << "Enter q for menu" << endl;
				cout << "Enter Q for Main menu" << endl;
				cin >> con1;
				if (con1 == "q")
				{
					std::system("cls");
					MENU();
				}
				else
				{
					std::system("cls");
					MENU1();
				}

			}
			cout << "DO YOU WANT TO CONTINUE ?" << endl;
			cin >> con1;
		} while (con1 == "yes");
	}
	void lver()
	{
		do {
			cout << "CHECK UP FEE OF DR.SHAKUNTALA AHMAD : 2000 " << endl;
			cout << "DOCTOR CAN VISIT TO YOU BETWEEN 10:00-12:00 IN MORNING " << endl;
			cout << "YOU WANT TO CONFIRM ?" << endl;
			cin >> con;
			if (con == "yes")
			{
				carto += 1;
				cout << "Enter q for menu" << endl;
				cout << "Enter Q for Main menu" << endl;
				cin >> con1;
				if (con1 == "q")
				{
					std::system("cls");
					MENU();
				}
				else
				{
					std::system("cls");
					MENU1();
				}

			}
			cout << "DO YOU WANT TO CONTINUE ?" << endl;
			cin >> con1;
		} while (con1 == "yes");
	}
	void showcdrtype()
	{
		cout << carto << endl;
	}
};
class Order
{
	Medicine* med1;
	Lab_Tests* labt;
	Consultation_time* consultt;
	Doctor_Type* drt;
	string name = "", city = "", society = "", block = "", email = "", confrmation = "";
	int housenum = 0, streetnum = 0;
	long int phonenum;
public:
	Order() {}
	Order(Medicine* m, Lab_Tests* L, Consultation_time* c, Doctor_Type* d1)
	{
		med1 = m;
		labt = L;
		consultt = c;
		drt = d1;
	}
	void purchase()
	{
		cout << "YOU HAVE ";
		drt->showcdrtype();
		cout << "BOOKED SLOTS" << endl;
		cout << endl;
		cout << endl;
		cout << "YOU HAVE ";
		consultt->showconsulttime();
		cout << "BOOKED SLOTS" << endl;
		cout << endl;
		cout << endl;
		cout << "YOU HAVE ";
		labt->showlabtests();
		cout << "BOOKED SLOTS" << endl;
		cout << endl;
		cout << endl;
		cout << "YOU HAVE ";
		med1->showmedicanes();
		cout << "MEDICANES IN THE CART " << endl;
	}
	void Customer_data()
	{
		cout << " --------------- ENTER YOUR NAME --------------- " << endl;
		cin >> name;
		cout << " --------------- ENTER YOUR CITY NAME --------------- " << endl;
		cin >> city;
		cout << " --------------- ENTER YOUR BLOCK NAME --------------- " << endl;
		cin >> block;
		cout << " --------------- ENTER YOUR SOCIETY NAME --------------- " << endl;
		cin >> society;
		cout << " --------------- ENTER YOUR STREET NUMBER --------------- " << endl;
		cin >> streetnum;
		cout << " --------------- ENTER YOUR HOUSE NUMBER --------------- " << endl;
		cin >> housenum;
		cout << " --------------- ENTER YOUR PHONE NUMBER --------------- " << endl;
		cin >> phonenum;
		cout << " --------------- ENTER YOUR EMAIL ADDRESS --------------- " << endl;
		cin >> email;
	}
	const void displayDATA()
	{
		string pay;
		med1->MENU();
		cout << " NAME - " << name << endl;
		cout << " CITY NAME - " << city << endl;
		cout << " BLOCK NAME - " << block << endl;
		cout << " SOCIETY NAME - " << society << endl;
		cout << " STREET NUMBER - " << streetnum << endl;
		cout << " HOUSE NUMBER - " << housenum << endl;
		cout << " PHONE NUMBER - " << phonenum << endl;
		cout << " EMAIL ADDRESS - " << email << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "DO YOU WANT TO PAY PAY VIA -> CASH OR CARD <- " << endl;
		cin >> pay;
		if (pay == "cash")
		{
			cash();
		}
		else if (pay == "card" || pay == "2")
		{
			card();
		}
		else
		{
			cout << "SOME THING WENT WRONG TRY AGAIN LATER" << endl;
			MENU1();
		}
	}
};
class Invoice
{
	Order o;
public:
	Invoice(Order d)
	{
		o = d;

	}
	void Final()
	{
		o.purchase();
	}
};
/*lass Order : public Medicine
{
	string name;
	int id, price, quantity, totalprice;
public:

	void purchaseitem()
	{

		cout << "product id" << "\t\t" << "product name" << "\t\t" << "product price" << "\t\t" << "product quantity" << "\t\t" << "Total price\n";
		for (int i = 0; i < count; i++)
		{
			cout << c[i].id << "\t\t\t" << c[i].name << "\t\t\t" << c[i].price << "\t\t\t" << c[i].quantity << "\t\t\t\t" << c[i].totalPrice << endl;
		}

	}
	void removeitem()
	{

		cout << "Eneter name of product You want to remove :";
		cin >> name;
		for (int i = 0; i < count; i++)
		{
			if (c[i].name == name)
			{

				for (int j = i; j < count - 1; j++)
				{
					c[j].id = c[j + 1].id;
					c[j].name = c[j + 1].name;
					c[j].price = c[j + 1].price;
					c[j].quantity = c[j + 1].quantity;
					c[j].totalPrice = c[j + 1].totalPrice;
				}
			}
		}
		count -= 1;
		cout << "\n------------------------------------------ Purchase Item --------------------------------------------------\n\n";
		purchaseitem();
	}
	void Decquantity()
	{

		cout << "Enter the name of product : ";
		cin >> name;
		for (int i = 0; i < count; i++)
		{
			if (c[i].name == name)
			{

				cout << "Enter the quantity : ";
				cin >> c[i].quantity;
				c[i].totalPrice = c[i].price * c[i].quantity;
				cout << "\nTotal : " << c[i].totalPrice << " RS\n";
			}
		}

	}


	void invoice()const
	{

		cout << "\n\n\n=================================================================================================================\n";
		cout << "product id" << "\t\t" << "product name" << "\t\t" << "product price" << "\t\t" << "product quantity" << "\t\t" << "Total price\n";
		cout << "==================================================================================================================\n";
		for (int i = 0; i < count; i++)
		{
			cout << c[i].id << "\t\t\t" << c[i].name << "\t\t\t" << c[i].price << "\t\t\t" << c[i].quantity << "\t\t\t\t" << c[i].totalPrice << endl;
		}

		cout << "==================================================================================================================\n";
		cout << "                                                                                              Total bill " << c->total;
		exit(0);
	}

};*/
int main()
{
	std::system("color 80");
	LOGINM();
	std::system("cls");
	string confrm;
	Catagorize cz;
	Consultation c;
	Doctor d;
	Lab_Reports l;
	Pharmacy p;
	Medicine m;
	Lab_Tests lt;
	Doctor_Type dt;
	Consultation_time ct;
	string fchoice;
	Order o(&m, &lt, &ct, &dt);
	Invoice Inv(o);
	cz.process();
	if (choicem == "NULL" || choicem == "Null" || choicem == "null")
	{
		cout << "THANK YOU FOR USING DAWAI APP " << endl;
		std::system("pause");
	}
	else if (choicem == "CONSULT" || choicem == "Consult" || choicem == "consult" || choicem == "1")
	{
		std::system("pause");
		c.MENU();
		cout << "ENTER CHOICE" << endl;
		cin >> confrm;
		if (confrm == "Q")
		{
			std::system("cls");
			MENU1();
		}
		else if (confrm == "1" || confrm == "Mbbs" || confrm == "MBBS" || confrm == "mbbs")
		{
			std::system("pause");
			ct.mbbs();
		}
		else if (confrm == "2" || confrm == "physiotherapist" || confrm == "PHYSIOTHERAPIST" || confrm == "Physiotherapist")
		{
			std::system("pause");
			ct.physio();
		}
		else if (confrm == "3" || confrm == "NEUROLOGIST" || confrm == "neurologist" || confrm == "Neurologist")
		{
			std::system("pause");
			ct.neuro();
		}
		else if (confrm == "4" || confrm == "SKIN" || confrm == "skin" || confrm == "Skin")
		{
			std::system("pause");
			ct.skin();
		}
		else if (confrm == "5" || confrm == "LUNGS" || confrm == "Lungs" || confrm == "lungs")
		{
			std::system("pause");
			ct.lungs1();
		}
		std::system("pause");
	}
	else if (choicem == "DOCTOR" || choicem == "Doctor" || choicem == "doctor" || choicem == "2")
	{
		std::system("pause");
		d.MENU();
		cout << "ENTER CHOICE" << endl;
		cin >> confrm;
		if (confrm == "Q")
		{
			std::system("cls");
			MENU1();
		}
		else if (confrm == "1" || confrm == "diabetese" || confrm == "DIABETESE" || confrm == "Diabetese")
		{
			std::system("pause");
			dt.Ddib();
		}
		else if (confrm == "2" || confrm == "FEVER" || confrm == "Fever" || confrm == "fever")
		{
			std::system("pause");
			dt.fever();
		}
		else if (confrm == "3" || confrm == "LUNGS" || confrm == "Lungs" || confrm == "lungs")
		{
			std::system("pause");
			dt.lungs();
		}
		else if (confrm == "4" || confrm == "JOINTS" || confrm == "joints" || confrm == "Joints")
		{
			std::system("pause");
			dt.joints();
		}
		else if (confrm == "5" || confrm == "liver" || confrm == "Liver" || confrm == "LIVER")
		{
			std::system("pause");
			dt.lver();
		}std::system("pause");
	}
	else if (choicem == "LAB" || choicem == "Lab" || choicem == "lab" || choicem == "3")
	{
		std::system("pause");
		l.MENU();
		cout << "ENTER CHOICE" << endl;
		cin >> confrm;
		if (confrm == "Q")
		{
			std::system("cls");
			MENU1();
		}
		else if (confrm == "1")
		{
			std::system("pause");
			lt.giving();
		}
		else if (confrm == "2")
		{
			std::system("pause");
			lt.receve();
		}std::system("pause");
	}
	else if (choicem == "PHARMACY" || choicem == "Pharmacy" || choicem == "pharmacy" || choicem == "4")
	{
		m.MENU();
		std::system("pause");
		Medicine med;
		std::system("pause");
		Pharmacy p1(med);
		std::system("pause");
	}
	else if (choicem == "cart" || choicem == "5" || choicem == "CART" || choicem == "Cart")
	{

		std::system("pause");
		o.Customer_data();
		std::system("pause");
		o.displayDATA();
		std::system("pause");
		o.purchase();
		std::system("pause");
	}
	else if (choicem == "INVOICE" || choicem == "Invoice" || choicem == "invoice" || choicem == "6")
	{
		Invoice invo(o);
		invo.Final();
		std::system("pause");
	}
	else
	{
	//std::system("pause");
		MENU1();
	}
	return 0;
}
