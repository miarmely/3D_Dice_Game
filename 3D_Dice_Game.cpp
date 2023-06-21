#include <iostream>
#include <windows.h>
#include <ctime>
using namespace std;


class Dice 
{
	private:
		class Node 
		{			
			public:		
				string mNickName;
				int mNickName2;
				int mHeight;
				int mWidth;
				int mDepth;
				int mCritic;
				int diceNum;
				Node *back;
				
				Node(string,int,int,int,int);
				Node();
		};
			
	Node *head;
	Node *first;
	int totalSize;
	size_t startSize;
	size_t size;
	size_t tempSize;
	size_t backDepth;
	size_t downDepth;
	size_t whichMenu;

		
	protected:
		Dice();	
		Dice(float);
		int *harbour();
		void User(string,int,int,int,int);
		void gameMenu();
		void starLines(Node *) const;
		void otherLines(Node *) const;
		void topBody(Node *);
		void mainBody(Node *);
		void space(int) const;
		void LSpace(int) const;
		bool backDepthFunc(Node *);
		void downDepthFunc(Node *);
		void diceShape();
		void cls() const;	
		void resBackDown();
		void middleStarLines(Node *);
		void backDown(Node *);
		void singleLinesCritic(Node *);
		void coupleLinesCritic(Node *);
		void L1WantStar1(int,int,Node *);
		void L2WantStar1(int,Node *);
		void L3WantStar1(int,int,Node *);
		void wantStar2(int,int,Node *);
		void wantStar3(int,int,Node *);	
		int setHeight();
		int setWidth();
		int setDepth();		
		void graphic(int *);
		bool winLoseTable();
		void forFunc(string, int) const;
		void delUser(Node **, Node **, Node **, int *, int *); 
		void digit(size_t, int *) const;	
		void successfulProcess() const;	
		void returnMenu();	
		void resume();	
};
	
class Welcome : protected Dice
{
	public:
	 	welcome(){}	
};

///////////////////////////
// MA�N

int main()
{
	setlocale(LC_ALL,"");
	
	Welcome w1;
	
	

	return 0;
}

////////////////////////////
// D�CE CLASS

#define mH ptr->mHeight 
#define mW ptr->mWidth 
#define mD ptr->mDepth
#define mC ptr->mCritic

Dice::Dice(): head('\0'), size(0), tempSize(0), backDepth(1), downDepth(0), startSize(0), totalSize(0), whichMenu(9)// DEFAULT CONSTRUCTOR
{	
	gameStart:
	cout<<"\t\t3D ZAR OYUNUNA HO�GELD�N!...\n\n";
	cout<<"1) OYUNA G�R�� \n";
	cout<<"0) OYUNDAN �IKI� \n\n"; 
	cout<<"L�tfen istedi�iniz i�lemin ba��ndaki numaray� giriniz: ";
	string decide;
	cin>>decide;
	
	if(decide == "1") // OYUNA G�R��
		gameMenu();
	
	
	else if(decide == "0") // OYUNDAN �IKI�
	{
		cout<<"�yi g�nler efendim!...";  exit(0);
	}
			
	else
	{
		cls();  cout<<"Hatal� giri� L�tfen tekrar deneyiniz!... \n\n";  goto gameStart;
	} 
} 

Dice::Dice(float fake) {} // FAKE CONSTRUCTOR

int *Dice::harbour() // ZAR L�MANI
{
	Node *ptr = head;
	int *diceNumbers = new int[size];
	int *counter = new int(0);
	int randomNum;
	int reverseShape;
 	
 	srand(time(0));
 	
	while(ptr)
	{
		if(ptr->mNickName2 == 0)
			cout<<"\tZAR SAH�B� = "<<ptr->mNickName<<"\n\n";	//STR�NG �SM�N� YAZDIRMA
		
		else
			cout<<"\tZAR SAH�B� = "<<ptr->mNickName2<<". oyuncu \n\n"; //�NT �SM�N� YAZDIRMA
				
				
		topBody(ptr);
		
		randomNum = 1 + rand()%6;
		reverseShape = 1+rand()%2;
		
		ptr->diceNum = randomNum;
			
		for(int a = 1 ; a <= 2*mH-1 ; a++) // ANA G�VDEN�N TOPLAM SATIR SAYISI 
		{
			if(a == 1) // ilk sat�r
				middleStarLines(ptr);
						    
						    
			else if(a != 2*mH-1) // SON SATIR DE��LSE VE YILDIZ ATILACAK SATIRLARA DENK GELM�YORSA 
			{
				if( (a == mH/3+2 && randomNum == 1) || (a == mH && (randomNum == 2 || randomNum == 4 || (randomNum == 6 && reverseShape == 2))) || (a == (2*mH-1)-(mH/3+1) && randomNum == 1) ) // �LK SATIRSA, ORTANCA SATIRSA VE SON SATIRSA
				{
				    if(a%2 == 0) // ��FT SATIRLARDA !!!!!!!!!! 
					{
						space(3*mW-2);
						coupleLinesCritic(ptr);
					}			
		
					else if(a%2 != 0) // TEK SATIRLARDA !!!!!!!!!!!!
					{			
						otherLines(ptr);
						singleLinesCritic(ptr);					
					}
				}	
				
				else if(a != mH/3+2 && a != mH && a != (2*mH-1)-(mH/3+1))
				{
					if(a%2 == 0) // ��FT SATIRLARDA !!!!!!!!!! 
					{
						space(3*mW-2);
						coupleLinesCritic(ptr);
					}			
		
					else if(a%2 != 0) // TEK SATIRLARDA !!!!!!!!!!!!
					{			
						otherLines(ptr);
						singleLinesCritic(ptr);					
					}	
				}
			}
					
					  
			if(randomNum != 1 && a == mH/3+2) // �LK YILDIZ SATIRI �SE VE ZAR 1 DE��LSE 
			{	
				if(randomNum == 2 || randomNum == 3) // ZAR 2 VEYA 3 �SE
				{
					if(reverseShape == 1) // NORMAL HAL�N� ��ZD�RME
						L1WantStar1(1, a, ptr);
									
					else //TERS HAL�
						L3WantStar1(1, a, ptr);				
				}
							
				else if(randomNum == 4 || randomNum == 5 || randomNum == 6) // ZAR 4, 5 VEYA 6  �SE
				{
					if(randomNum == 4 || randomNum ==5) // ZAR 4 VEYA 5 �SE
						wantStar2(2, a, ptr);
									
					else // ZAR 6 �SE
					{
						if(reverseShape == 1) // NORMAL HAL�N� ��ZD�RME
							wantStar2(2, a, ptr);
								
						else //TERS HAL�
							wantStar3(3, a, ptr);	
					}
				}	
			}
				
			else if(a == mH) // ORTANCA YILDIZ SATIRI
			{
				if(randomNum == 1 || randomNum == 3 || randomNum == 5)
					L2WantStar1(a, ptr);
					
				else if(randomNum == 6 && reverseShape == 1)// ZAR 6 �SE VE NORMAL HAL� ��ZD�R�L�CEKSE
					wantStar2(2, a, ptr);		
			}
					
			
			else if(a == (2*mH-1)-(mH/3+1) && randomNum != 1) // SON YILDIZ SATIRI �SE VE ZAR 1 DE��LSE (FORMUL� SADELE�T�R�RSEN SIKINTI �IKIYOR SADELE�T�RME)
			{
				if(randomNum == 2 || randomNum == 3) // ZAR 2 VEYA 3 �SE
				{
					if(reverseShape == 1) // NORMAL HAL�N� ��ZD�RME
						L3WantStar1(1, a, ptr);
							
					else //TERS HAL�
						L1WantStar1(1, a, ptr);				
				}
					
				else if(randomNum == 4 || randomNum == 5 || randomNum == 6) // ZAR 4, 5 VEYA 6  �SE
				{
					if(randomNum == 4 || randomNum ==5) // ZAR 4 VEYA 5 �SE
						wantStar2(2, a, ptr);
							
					else // ZAR 6 �SE
					{
						if(reverseShape == 1) // NORMAL HAL�N� ��ZD�RME
							wantStar2(2, a, ptr);
								
						else //TERS HAL�
							wantStar3(3, a, ptr);	
					}
				}
			}	
			    
																
			else if(a == 2*mH-1) // SON SATIRSA
				starLines(ptr);	
			
			LSpace(1);
		}	
		
		LSpace(3);
		resBackDown();
		
		diceNumbers[*counter] = ptr->diceNum;
		(*counter)++;
		ptr = ptr->back;				
	}	
	
	totalSize = *counter;
	
	delete counter;
	return diceNumbers;	
}	

void Dice::downDepthFunc(Node *ptr)// TABAN DER�NL�K YILDIZI ATTIRMA
{
	if(backDepth >= mH)
	{
		space(mC-(2+downDepth));
		cout<<"*";
		downDepth++;
	}
}

bool Dice::backDepthFunc(Node *ptr)// ARKA DER�NL�K YILDIZI ATTIRMA
{
	if(backDepth < mH)// ARKA DER�NL�K SAYISI Y�KSEKL�K DE�ER�NE E��T DE��LSE
	{
		space(mC-1);
		cout<<"*";
		backDepth++;
		return true;
	}
	
	return false;
}

void Dice::starLines(Node *ptr) const// �LK SATIR YILDIZLARI
{
	for(int a = 0 ; a < mW ; a++) 
	{
		if(a < mW-1)
			cout<<"*  ";
			
		else // SON YILDIZI BO�LUKSUZ YAPMA
			cout<<"*";				
	}	
}

void Dice::middleStarLines(Node *ptr)// ORTADAK� KOMPLE YILDIZLI SATIR
{
	   starLines(ptr);
	   singleLinesCritic(ptr);
}

void Dice::space(int amount) const // BO�LUK ATTIRMA 
{
	for(int a = 0 ; a < amount ; a++)
		cout<<" ";
}

void Dice::LSpace(int amount) const // SATIR BO�LUK ATTIRMA
{
	for(int a = 1 ; a <= amount ; a++)
		cout<<"\n";
}

void Dice::otherLines(Node *member) const // 2 YILDIZ VE BO�LUKLU OLAN SATIRLAR 
{
	cout<<"*";
			
	for(int a = 0 ; a < 3*member->mWidth-4 ; a++)
		cout<<" ";
				
	cout<<"*";
}

void Dice::topBody(Node *ptr)  // �ST G�VDE
{
	for(int b = 1 ; b <= mD-1 ; b++)
	{
		space(mD-b);
			
		if(b == 1)// �LK SATIR YILDIZLARIn� �A�IRMA
			starLines(ptr);
			
		else
		{
			otherLines(ptr);
			
			if(b%2 != 0 && backDepth < mH)// SATIR SAYISI TEKSE ARKA DER�NL�K ATTIRMA 
			{
				space(b-2);
				cout<<"*";
				backDepth++;
			}
			
			else if(backDepth == mH)// TABAN DER�NL�K YILDIZLARI
			{
				space(2*mH-3);
				cout<<"*";
				downDepth++;
			}
		}			
		cout<<"\n";
	}		
}

void Dice::mainBody(Node *ptr) // 3D PR�ZMANIN ANA G�VDES�
{
	for(int a = 1 ; a <= 2*mH-1 ; a++) // ANA G�VDE SATIRLARI
	{		
		if(mC%2 == 0) // KR�T�K ��FTSE
		{
			if(a == 1)// �LK SATIRDA
			{
				starLines(ptr);
				backDown(ptr);
			}
			
			else if(a < 2*mH-1) //ARADAK� SATIRLAR
			{
				if(a%2 == 0)//SATIR SAYILARI ��FTSE 
				{
					space(3*mW-2);// 1 YILDIZ + BO�LUK + 1 YILDIZ KOMB�NASYONUNDA YILDIZ SAYILARINI DA BO�LUKLARA DAH� ED�P BO�LUK ATTIRTIYORUM 		 	
					downDepthFunc(ptr);				
				}
				
				else if(a%2 != 0) // SATIR SAYILARI TEKSE 
				{
					otherLines(ptr);
					singleLinesCritic(ptr);
				}
			}
			
			else if(a == 2*mH-1)
				starLines(ptr);
			
		}
		
		else if(mC%2 != 0) // KR�T�K TEKSE
		{
			if(a == 1)// �LK SATIRDA
			{
				starLines(ptr);
				
				if(backDepth == mH)
				{
					space(2*mH-3);
					cout<<"*";
					downDepth++;
				}	
			}
				
			else if(a < 2*mH-1) // ARADAK� SATIRLAR 
			{
				if(a%2 == 0)//SATIR SAYILARI ��FTSE 
				{
					space(3*mW-2);// 1 YILDIZ + BO�LUK + 1 YILDIZ KOMB�NASYONUNDA YILDIZ SAYILARINI DA BO�LUKLARA DAH� ED�P BO�LUK ATTIRTIYORUM 	
					
					downDepthFunc(ptr);  
					backDepthFunc(ptr);	
				}
				
				else if(a%2 != 0) // SATIR SAYILARI TEKSE 
				{
					otherLines(ptr);
					downDepthFunc(ptr);
				}			
			}
				
			else if(a == 2*mH-1)// SON SATIR
				starLines(ptr);
		}
		
		cout<<"\n";
	}
}

void Dice::diceShape()// ZAR �EK�L� ��ZD�RME
{	
	Node *ptr = head;
	int memberCounter=0;
	cls();
	
	while(ptr)
	{
		if(ptr->mNickName2 == 0)
			cout<<"\t\tZAR SAH�B�: "<<ptr->mNickName<<"\n\n"; 
		
		else
			cout<<"\t\tZAR SAH�B�: "<<ptr->mNickName2<<". oyuncu \n\n"; 
		
		topBody(ptr);
		mainBody(ptr);
			
		cout<<"\n\n\n";
		resBackDown();
			
		memberCounter++;	
		ptr = ptr->back;
	}	
	
	memberCounter=0;
	resBackDown();
}

void Dice::gameMenu()// OYUN MEN�S�
{	
	decide2Repeat:
	cls();
	cout<<"\t\tANA MEN�\n\n";
	cout<<"1) �ZEL ZAR EKLE\n";
	cout<<"2) �OKLU ZAR EKLE\n";
	cout<<"3) SE��LEN ZARLARI G�R�NT�LE \n";
	cout<<"4) MANUEL ZAR AT \n";
	cout<<"5) OTOMAT�K ZAR AT \n";
	cout<<"0) OYUNDAN �IKI�\n\n";
	cout<<"L�tfen istedi�iniz i�lemin ba��ndaki numaray� giriniz: ";
	string decide2;
	cin>>decide2;
		
	cls();
		
	if(decide2 == "1") // �ZEL ZAR EKLEME
	{
		repeatNickName:
		fflush(stdin);
		cout<<"L�tfen bir nick name giriniz: ";
		string nickName;
		getline(cin,nickName);
		cout<<"\n";
			
			
		if(nickName.size() > 20 || nickName.size() <= 0)
		{
			cout<<"Ge�ersiz nickName! L�tfen 1 ile 20 karakter aras�nda bir nickName se�!\n\n";
			goto repeatNickName;
		}
			
		startSize++;
			
		if(startSize >= 1000000) 
		{
			cls();	cout<<"�zg�n�m, Max 999bin zar ekleyebilirsin!...\n\n";  startSize-=1; 	goto amountDiceRepeat;
		}
			
			
		User(nickName,0,0,0,0);
			
		LSpace(2);
		resBackDown();
	}
		
		
	else if(decide2 == "2") // �OKLU ZAR EKLEME
	{
		amountDiceRepeat:
		cout<<"Ka� tane zar eklemek istersin? : ";
		int amountDice;
		cin>>amountDice;
		LSpace(1);
			
			
		if(amountDice <= 0 || amountDice >= 1000000) //0 ile 1 milyon zar aras�nda
		{
			cls();	cout<<"HEY, ORDA DUR!..."; Sleep(1500);  cls();  cout<<"EN AZ = 1, EN FAZLA = 999B�N ZAR EKLEYEB�L�RS�N!...\n\n\n";	 goto amountDiceRepeat;
		}
						
		startSize+=amountDice;
			
		if(startSize >= 1000000) 
		{
			cls();	cout<<"HEY, ORDA DUR!..."; Sleep(1500);  cls();  cout<<"EN FAZLA 999B�N ZAR EKLEYEB�L�RS�N!...\n\n\n";  startSize-=amountDice; 	goto amountDiceRepeat;
		}
			
		cls();			
		int dHeight = setHeight();		int dWidht = setWidth();	int dDepth = setDepth();	successfulProcess();
						
									
		for(int d1 = 1 ; d1 <= amountDice ; d1++)
		{
			tempSize++;
			User("404",tempSize,dHeight,dWidht,dDepth);	
		}
				
		cls();
		resBackDown();
	}
		
		
	else if(decide2 == "3") // SE��LEN ZARLARI G�R�NT�LE 
	{
		if(size > 0)
		{
			diceShape(); LSpace(2); returnMenu();	
		}
					
		else
			cout<<"G�r�nt�lenecek herhangi bir zar bulunamad�. L�tfen Tekrar dene!...\n"; Sleep(2000);
	}
		
		
	else if(decide2 == "4") // ZARLARI MANUEL AT 
	{
	    int *temp4 = new int;	int *counter4 = new int(0);  string *decide2_4 = new string;  string *decide2_4_1 = new string;
		
		#define D1 decide2_4
		#define D2 decide2_4_1
		
		decide2_4:
		cls();
		cout<<"\t\t MANUEL ZAR MEN�S�\n\n";
		cout<<"1) ZAR G�R�NT�LE\n";
		cout<<"2) ZAR AT \n";
		cout<<"0) GER� GEL\n\n";
		cout<<"l�tfen ger�ekle�tirmek istedi�iniz i�lemin ba��ndaki numaray� giriniz: ";
		cin>>*D1;
		cls();
		
		
		if(*D1 == "1") // ZARLARI G�R�NT�LE
		{
			if(size > 0)
			{
				diceShape();  LSpace(2);  resume();  cls();  goto decide2_4;	
			}
						
			else
				cout<<"G�r�nt�lenecek herhangi bir zar bulunamad�. L�tfen Zar ekle!...\n";  Sleep(2000);  gameMenu();
		}
		
		
		else if(*D1 == "2") // ZARLARI AT
		{
			if(size > 0) // ZAR EKLENM�� �SE
			{
				temp4 = harbour();  
				(*counter4)++;  
				resume();  
				
				decide2_4_1:
				cls();	
				cout<<"\t\t TUR MEN�S�\n\n";
				cout<<"1) �STAT�ST�KLER� G�R�NT�LE \n";
				cout<<"0) ANA MEN�YE D�N \n\n";
				cout<<"l�tfen ger�ekle�tirmek istedi�iniz i�lemin ba��ndaki numaray� giriniz: ";
				cin>>*D2;
				cls();
				
				if(*D2 == "1") // TURUN �STAT�ST�KLER�
				{
					whichMenu=44;
					
					if(*counter4 > 0) // ZARLAR ATILMI�SA
					{
						winLoseTable();  
						 
						if(size > 1) // 1 DEN FAZLA OYUNCU VARSA
						{
							graphic(temp4); resume();
						}
						
						goto decide2_4; 	
					}
						
					else // ATILMAMI�SA
					{
						 cout<<"�NCE ZAR ATMALISIN!\n\n";  Sleep(2000);  goto decide2_4;
					}	
				}
				
				
				else if(*D2 == "0") // ANA MEN�
				{
					decide3:
					cout<<"E�ER ANA MEN�YE D�NERSEN�Z BU TURUN GRAF���N� VE TABLOSUNU G�REMEYECEKS�N�Z DEVAM ETMEK ���N 1'e, VAZGE�MEK ���N 0'a BASINIZ: ";
					string *decide = new string;
					cin>>*decide;
					delete decide; 
				
					
					if(*decide == "1") // DEVAM ED�LD�YSE
					{
						delete counter4;  delete temp4;  delete D1;  delete D2;  
						gameMenu();
					}
						
							
					else if(*decide == "0") // VAZGE��LD�YSE
						goto decide2_4_1;
						
						
					else // GE�ERS�Z HARF G�R��� OLURSA
					{
						cls();  cout<<"GE�ERS�Z ��LEM! L�TFEN TEKRAR DENE...\n\n";  goto decide3;
					} 	
				}
			}
			
			
			else // ZAR EKLENMEM�� �SE
			{
				cout<<"ATILACAK HERHANG� B�R ZAR BULUNMAMAKTADIR, L�TFEN �NCE ZAR EKLEY�N�Z!!\n\n";  Sleep(2000);  delete counter4;  delete temp4;  delete decide2_4;  gameMenu();
			}		
		}
		

		else if(*D1 == "0") // GER� GEL
		{
			delete counter4;  delete temp4;  delete D1;  delete D2;  
			gameMenu();
		}
			
		whichMenu=0;  *counter4=0;  goto decide2_4;	
	}
			
		
	else if(decide2 == "5") // ZARLARI OTOMAT�K AT
	{
		if(size > 1)//1 DEN FAZLA OYUNCU VAR �SE 
		{
			int *tempCounter1 = new int(0);
			int *round = new int(1);
			whichMenu=55;
				
			cout<<"\t\tSE��LEN ZARLAR GET�R�L�YOR!";  Sleep(600); cout<<"."; Sleep(450);  cout<<".";  Sleep(450);  cout<<".";  Sleep(750);  LSpace(2);
			diceShape();  LSpace(2); Sleep(2000);
				
			cout<<"\t\tHAZIR MISIN? OYUN BA�LIYOR!";  Sleep(600); cout<<"."; Sleep(450);  cout<<".";  Sleep(450);  cout<<".";  Sleep(1500);  cls(); Sleep(100);		
			while(size != 0) // OYUNCU VARSA
			{
				if(size > 1) // OYUNCU SAYISI 1'DEN B�Y�KSE 
				{		
					int *temp = new int;
											
					cout<<"\t\t"<<*round<<". TURUN ZARLARI ATILIYOR... BOL �ANS!!\n\n\n\n\n"; Sleep(1600);
						
					temp = harbour(); Sleep(2500); LSpace(3);
					winLoseTable(); Sleep(4000); 
					graphic(temp);  Sleep(3500); LSpace(4);  
						
					(*round)++;
					delete[] temp;		
				}
				
				(*tempCounter1)++;	
				
			}
				
			if(size == 0 && *tempCounter1 == 0)
				cout<<"G�r�nt�lenecek herhangi bir zar bulunamad�. L�tfen Tekrar dene!..."; Sleep(2000);
				
			whichMenu=0;  tempSize = 0;  head = '\0';  delete tempCounter1;  delete round; 	fflush(stdin); 	 totalSize = 0;
			returnMenu();
		}
		
		else if(size==1) // ZAR SAYISI 1 DEN AZ �SE
		{
			cls();	cout<<"�zg�n�m, Otamatik zar atmak i�in en az 2 oyuncu olmas� gerekiyor!\n\n";  Sleep(2000);
		}
		
		else
		{
			cls(); 	cout<<"Otamatik at�lacak herhangi bir zar bulunamad�. L�tfen Tekrar dene!..."; Sleep(2000); 
		}
		
		gameMenu();
	}
				
			
	else if(decide2 == "0") // OYUNDAN �IKI�
	{
		cout<<"�yi g�nler efendim!...\n\n\n";  exit(0);
	}
	
		
	else
		cout<<"Hatal� giri� L�tfen tekrar deneyiniz!... \n\n"; 
			
	goto decide2Repeat;
}
	
void Dice::User(string nickName,int tempSize ,int fHeight, int fWidth, int fDepth)// KULLANICIYI DATAYA KAYDETME
{ 
	Node *n1 = new Node(nickName,tempSize,fHeight,fWidth,fDepth);
	size++;
	
	n1->back = head;
	
	if(size == 1)
		first = n1;
	
	head = n1;		
}

void Dice::cls() const // EKRANI S�LME
{
	system("cls");
}

void Dice::resBackDown() // ARKA VE TABAN DER�NL�K YILDIZ DE���KENLER�N�N DE�ERLER�N� RESETLEME
{
	backDepth=1;
	downDepth=0;
}

void Dice::L1WantStar1(int amountStar, int line, Node *ptr) // 1. SATIRDA �STENEN YILDIZ SAYISI 1 �SE 
{
	if(line%2 == 0) // 1. YILDIZ SATIRI ��FTSE
	{
		space((3*mW-5)/3); // �LK YILDIZ BO�LU�U
		cout<<"#";
		
		if(amountStar == 1) // 1 TANE YILDIZ �STENM��SE
		{
			space((6*mW-4)/3+1); // SATIRIN SONUNA KADAR BO�LUK 
			coupleLinesCritic(ptr);	
		}			
	}
	
	else  // 1. YILDIZ SATIRI TEKSE 
	{
		cout<<"*";
		space((3*mW-8)/3);
		cout<<"#";
		
		if(amountStar == 1) // �STENEN 1 YILDIZ �SE
		{
			space((6*mW-6)/3); // SATIR SONUNA KADAR BO�LUK
			cout<<"*";
			singleLinesCritic(ptr);		
		}
	}
}

void Dice::wantStar2(int amountStar, int line, Node *ptr) // 1. SATIRDA �STENEN YILDIZ SAYISI 2 �SE 
{
	L1WantStar1(2, line, ptr);
	
	if(amountStar == 2) // ORTANCA YILDIZSIZ
	{
		space((3*mW+1)/3); // �LK YILDIZLA SON YILDIZ ARASI BO�LUK (�ift sat�r veya tek sat�r farketmez)
		cout<<"#";
	}
	
	else if(amountStar == 3)// ORTANCA YILDIZ �LE
	{
		if(mW%2 == 0)// TABAN ��FTSE
		{
			space((3*mW-5)/6); //�LK YILDIZ �LE 2 TANE ORTANCA YILDIZ ARASI BO�LUK
			cout<<"##"; // ORTANCA ��FT YILDIZ
			space((3*mW-5)/6); //2 TANE ORTANCA YILDIZ �LE SON YILDIZ ARASI BO�LUK
			cout<<"#"; // SON YILDIZ
		}
		
		else // TABAN TEKSE
		{
			space((3*mW+1)/6); //ilk y�ld�zla ortanca y�ld�z aras�ndaki bo�luk
			cout<<"#"; // ORTANCA TEK YILDIZ
			space((3*mW+1)/6);	//ortanca y�ld�zla son y�ld�z aras�ndaki bo�luk
			cout<<"#"; // SON YILDIZ
		}
		
	}
	
	if(amountStar == 2 || amountStar == 3) // SADECE 2 TANE YILDIZ OLMASINI �STEM��SE 
	{
		if(line%2 == 0) // 1. SATIR ��FTSE
		{
			space((3*mW-5)/3); // SON YILDIZDAN SATIR SONUNA KADARK� OLAN BO�LUKLAR
			coupleLinesCritic(ptr);			
		}
					
		else// 1. SATIR TEKSE 
		{
			space((3*mW-8)/3); //SON YILDIZDAN SATIR SONUNA KADARK� OLAN BO�LUKLAR
			cout<<"*";
			singleLinesCritic(ptr);		
		}									
	}	
}

void Dice::wantStar3(int amount, int line, Node *ptr) // 1. SATIRDA �STENEN YILDIZ SAYISI 3 �SE 
{
	wantStar2(3, line, ptr);	
}

void Dice::L2WantStar1(int line, Node *ptr) // ORTANCA SATIR YILDIZI
{
	if(mH%2 == 0) // Y�KSEKL�K ��FTSE
	{
		if(mW%2 == 0) // TABAN ��FTSE
		{
			space((3*mW-4)/2); // ORTANCA YILDIZI KADAR K� BO�LUK
			cout<<"##";
			space((3*mW-4)/2); // ORTANCA YILDIZDAN SONRA K� BO�LUK	
		}
		
		else if(mW%2 != 0) // TABAN TEKSE
		{
			space((3*mW-2)/2); // ORTANCA YILDIZI KADAR K� BO�LUK
			cout<<"#";
			space((3*mW-2)/2); // ORTANCA YILDIZDAN SONRA K� BO�LUK
		}
		
		coupleLinesCritic(ptr);
	}
	
	else // Y�KSEKL�K TEKSE
	{
		cout<<"*";	
		if(mW%2 == 0) // TABAN ��FTSE
		{
			space((3*mW-6)/2); // ORTANCA YILDIZI KADAR K� BO�LUK
			cout<<"##";
			space((3*mW-6)/2); // ORTANCA YILDIZDAN SONRA K� BO�LUK	
		}
		
		else if(mW%2 != 0) // TABAN TEKSE
		{
			space((3*mW-4)/2); // ORTANCA YILDIZI KADAR K� BO�LUK
			cout<<"#";
			space((3*mW-4)/2); // ORTANCA YILDIZDAN SONRA K� BO�LUK
		}
		cout<<"*";
		
		singleLinesCritic(ptr);
	}
}

void Dice::L3WantStar1(int amount, int line, Node *ptr) // SON SATIRDA �STENEN YILDIZ SAYISI 1 �SE
{
	if( ((2*mH-1)-(mH/3+1) )%2 == 0) //Y�KSEKL�K ��FTSE (BU FORMUL� SADELE�T�RME HATALI SONU� VER�R)
	{
		space((6*mW-1)/3);//ZAR YILDIZINA KADAR OLAN BO�LUK
		cout<<"#";
		space((3*mW-5)/3);//ZAR YILDIZIYLA SATIR SONUNA KADAR OLAN BO�LUK
			
		coupleLinesCritic(ptr);
	}
	
	else // Y�KSEKL�K TEKSE
	{
		cout<<"*";
		space((6*mW-4)/3);//ZAR YILDIZINA KADAR OLAN BO�LUK
		cout<<"#";
		space((3*mW-8)/3);//ZAR YILDIZIYLA SATIR SONUNA KADAR OLAN BO�LUK
		cout<<"*";
		
		singleLinesCritic(ptr);
	}
}

void Dice::backDown(Node *ptr)// ARKA DER�NL�K YILDIZI �LE TABAN DER�NL�K YILDIZINDAN HANG�N�N�N ATILACA�INA KARAR VERD�RME
{
	if(backDepthFunc(ptr)) ; 
				
	else
		downDepthFunc(ptr);
}

void Dice::singleLinesCritic(Node *ptr) // TEK SATIRLARDA KR�T�K DE�ERLER�NE G�RE ARKA YADA TABAN YILDIZINI ATTIRMA
{
	if(mC%2 == 0)// KR�T�K ��FTSE	
		backDown(ptr); 
				
	else// KR�T�K TEKSE 
		downDepthFunc(ptr);
}

void Dice::coupleLinesCritic(Node *ptr) // ��FT SATIRLARDA KR�T�K DE�ERLER�NE G�RE ARKA YADA TABAN YILDIZINI ATTIRMA
{
	if(mC%2 == 0)// KR�T�K ��FTSE
		downDepthFunc(ptr);
		
	else// KR�T�K TEKSE 
		backDown(ptr);	
}

int Dice::setHeight() // Y�KSEKL�K ALDIRMA
{
	repeat_height:
	cout<<"Y�kseklik de�eri giriniz: ";
	int height;
	cin>>height;
		
	if(height < 5)
	{
		cls();
		cout<<"L�tfen 5 ve 5 ten b�y�k rakamlar giriniz!...\n\n";
		goto repeat_height;
	}
	
	return height;
}

int Dice::setWidth() // GEN��L�K ALDIRMA
{
	repeat_width:
	cout<<"Geni�lik de�eri giriniz: ";
	int width;
	cin>>width;
		
	if(width < 5)
	{
		cls();
		cout<<"L�tfen 5 ve 5 ten b�y�k rakamlar giriniz!...\n\n";
		goto repeat_width;
	}
	
	return width;
}

int Dice::setDepth() // DER�NL�K ALDIRTMA
{
	repeat_depth:
	cout<<"Derinlik de�eri giriniz: ";
	int depth;
	cin>>depth;
		
	if(depth < 5)
	{
		system("cls");
		cout<<"L�tfen 5 ve 5 ten b�y�k rakamlar giriniz!...\n\n";
		goto repeat_depth;
	}
	
	return depth;
}

void Dice::forFunc(string wanting, int amount) const // FOR �LE YAN YANA �STENEN HERHANG� B�R �EY� YAZDIRMA 
{
	for(int a=0 ; a<amount ; a++)
		cout<<wanting;
}

void Dice::graphic(int *array)  // OYUNCULARIN ZAR DE�ERLER�N�N GRAF���N� ��ZD�RMA
{
	space(24);	forFunc("-", 22); LSpace(1); cout<<"\t\t\t| M�KTAR-ZAR GRAF��� |"; LSpace(1); 	space(24);   forFunc("-", 22); 
	
	int *six = new int(0);  
	int *five = new int(0);   
	int *four = new int(0);   
	int *three = new int(0);   
	int *two = new int(0);   
	int *one = new int(0);   
	int *column = new int(0);
	int *diceCompare = new int[6]; 
	int *tempArray = new int[6];
	
	
	for(int a = 0 ; a < totalSize ; a++) // ZAR DE�ERLER�N� DE���KENE AKTARMA
	{	
		if(array[a]==1)
			(*one)++;
		else if(array[a]==2)
			(*two)++; 
		else if(array[a]==3)
			(*three)++; 
		else if(array[a]==4)
			(*four)++; 
		else if(array[a]==5)
			(*five)++; 
		else
			(*six)++; 
	}
	
	LSpace(1);
	
	diceCompare[0] = *one;  diceCompare[1] = *two;  diceCompare[2] = *three;  diceCompare[3] = *four;  diceCompare[4] = *five;  diceCompare[5] = *six; 
			
	LSpace(2);
	
	for(int a = 0 ; a < 6 ; a++) // KA� TANE SUT�N KOYMAM GEREKT���N� SAYACAK
	{
		if(diceCompare[a] != 0)
			(*column)++;
		
		tempArray[a] = diceCompare[a]; //Zar de�erlerini s�ralamadan �nce ge�ici bir diziye aktar�yorum. Buunu yapmam�n sebebi grafi�i �izdikten sonra x ekseninin alt�nda hangi sut�n�n hangi zara ait oldu�unu buldurup onun ad�n� yazd�rmak i�in
	}
		
	
	for(int a = 0 ; a < 6 ; a++)// D�Z�DEK� SAYILARI K���KTEN B�Y��E SIRALAMA
		for(int b = 0 ; b < 5 ; b++)
		{
			if(diceCompare[b] > diceCompare[b+1])
				swap(diceCompare[b],diceCompare[b+1]);
		}
						
	space(3); cout<<"M�KTAR \n"; //G GRAF���N Y EKSEN�N�N ANAHTAR S�ZC���
	
	for(int a = 0 ; a < diceCompare[5]+3 ; a++) // Y EKSEN�
	{		
		if(a < 3)//DE���MEZ SAB�T
		{
			space(5);
			
			if(a==0)
				cout<<"^";
					
			else if(a==1)
				cout<<"|";
						
			else if(a==2) //3. SATIRA SUT�N �ATILARINI ATTIRMA(EN B�Y�K S�TUN YA DA S�TUNLARIN �ATISI)
			{
				cout<<"|";
				for(int b = 5 ; b >= 0 ; b--)
				{
					if(diceCompare[5] == diceCompare[b])
					{	
						space(3);	cout<<" _____ ";
					}
					
					else break; //E�ER 1 TANE E�LE�MEYEN OLURSA D�REK D�NG�DEN �IKARICAM B�Y�KTEN K����E DO�RU SIRALANIYOR(BO�UNA D��ERLER�NE DAHA BAKMASIN D�YE)	
				}	
			}							
		}
			
			
		else if(a>=3)// OLAY BURDA
		{	
			if((diceCompare[5]+3-a)/10 < 1) //E�ER GRAF���N Y EKSEN�NDEK� SAYI TEK BASAMAKLI �SE SAYIDAN �NCE 3 BO�LUK ATAR
				space(3);
				
			else // 2 BASAMAKLI �SE SAYI YAZDIRMADAN �NCE 2 BO�LUK ATAR
				space(2);
			
			for(int b = 0 ; b < 6 ; b++) // SADECE SUT�NLARIN EN �ST NOKTASI H�ZASINDAK� SATIRA Y EKSEN�NDE SAYI YAZDIRMA
			{
				if(diceCompare[b] == diceCompare[5]+3-a)
				{
					cout<<diceCompare[5]+3-a<<" "<<"|"; // O SATIRDAK� SUT�N�N BOYUTUNU YAZAR
					break;
				}		
				
				else if(b==5)// SON SATIRSA
				{
					if((diceCompare[5]+3-a)/10 >= 1) // O SATIR ��FT BASAMAKLI B�R SATIRSA 3 BO�LUK ATAR
						cout<<"   ";
									
					else // TEK BASAMAKLIYSA 2 BO�LUK ATAR
						cout<<"  ";
						
					cout<<"|";
				}				
			}
	
	
			for(int b = 5 ; b >= 0 ; b--) //O SATIRDAK� SUT�NLARIN KENARLARINI ��ZD�RME
			{
				if(diceCompare[b] >= diceCompare[5]+3-a) //ZAR DE�ERLER�NE BAKIP ���N O SATIRDAK� Y DE�ER�NE E��T YA DA B�Y�KSE ONUN ���N SUT�N KENARI EKLER
				{
					space(3);	cout<<"|";	space(5);	cout<<"|"; // 3 BO�LUK + 1 SUT�N (SUT�N KENARLARINI ��ZD�RME)	
				}
					
					
				else if(diceCompare[b] != 0) // E�ER O ZAR VARSA
				{
					if(diceCompare[b] == diceCompare[5]+2-a) // Y EKSEN�NDE B�R ALT SATIRDAK� SAYI DE�ER�NE E��TSE �ATI KOYAR.
					{
						space(3);	cout<<" _____ ";
					}			
				}	
			}	
		}
		
		LSpace(1);	
	}
	
	
	space(5);
	
	for(int a = 0 ; a < *column*10+4 ; a++)//X EKSEN� ��ZD�RTME
	{
		if(a != *column*10+3)
			cout<<"-";
		
		else
			cout<<"> ZAR";	 // X EKSEN�N�N ANAHTAR S�ZC���
	}
	
	LSpace(1);	space(5);
	
	
	for(int a=5 ; a>=0 ; a--) // HANG� SUT�N�N HANG� ZARA A�T OLDU�UNU BULUP SUT�N�N �SM�N� YAZDIRMA
		for(int b=0; b<6 ; b++) // GE���� ZARA ATANMI� ZAR NUMARALARINA BAKTIRMA
		{ 
			if(diceCompare[a] != 0 && diceCompare[a] == tempArray[b]) 
			{
				tempArray[b] = 0;
				space(5);	cout<<"ZAR "<<b+1;	
				break;	
			}			 
		}
	
	LSpace(4);

	delete one; delete two; delete three; delete four; delete five; delete six; delete[] diceCompare; delete column; delete[] tempArray;
}

bool Dice::winLoseTable() //KAZANAN KAYBEDEN TABLOSUNU ��ZD�RME  (BOOL YAPMAMIN SEBEB� HERHANG� B�R YERDE D�REK FONKS�YONU RETURN �LE KAPATAB�LMEK ���N YAN� FAKE BOOL D�YEB�L�R�Z)
{
	Node *ptr1 = head;
	
	if(size >= 0)
	{		
		Node **loserList = new Node* [size];
		Node **winnerList = new Node* [size];
		Node **allMemberList = new Node* [size];
		Node **tempAML = new Node* [size];		
		int *allMember = new int(0);
		int *losers = new int(0);
		int *winners = new int(0);
		
		#define LL loserList 
		#define WL winnerList
		#define AML allMemberList
		

		while(ptr1) // KAYBEDEN VE KAZANAN �YELER�N ADRESLER�N� D�Z�LERE AKTARMA
		{
			tempAML[*allMember] = ptr1;
			(*allMember)++;	
			
			if(ptr1->diceNum <= 3)	// ZAR DE�ER� 3 TEN K���KSE
			{
				LL[*losers] = ptr1;
				(*losers)++;	
	    	}
			
			else if(ptr1->diceNum > 3) // ZAR DE�ER� 3 TEN B�Y�KSE
			{
				WL[*winners] = ptr1;	
				(*winners)++;
			}	
			
			if(ptr1->back == NULL)
				break;
				
			ptr1 = ptr1->back;
		}
		
		for(int a = 0 ; a < *allMember ; a++) // D�Z�DEK� VER�LER� ESK�DEN YEN�YE G�RE SIRALAMAK ���N YAPTIM
			AML[a] = tempAML[*allMember-(a+1)];
			
		
				
		space(43);	forFunc("-", 17);	LSpace(1);
		space(43);  cout<<"| TUR SONU�LARI |\n";
		space(43);	forFunc("-", 17);	LSpace(1);
		
		space(51);  cout<<"|";	LSpace(1); //1. D���M 		
		space(22); 	forFunc("-", 59);	LSpace(1);
		space(22);  cout<<"|";	space(57); 	cout<<"|"; LSpace(1);//2. D���MLER
		
		space(1);   forFunc("-", 43); 	space(15); 	forFunc("-", 43);	LSpace(1);
		space(1); 	cout<<"| KAYBEDENLER = "<<*losers; 	digit(6, losers);	cout<<"/    ZAR DE�ERLER� |";	space(15);	  cout<<"| KAZANANLAR = "<<*winners;   digit(7, winners);   cout<<"/    ZAR DE�ERLER� |";	LSpace(1);
		space(1);   forFunc("-", 43); 	space(15); 	forFunc("-", 43);	LSpace(1);
		
			
		int big;
		
		if(*losers >= *winners)	//D�Z�DEK�LER�N ADLARINI YAZDIRMA	
			big = *losers;
		else
			big = *winners;
		
			
		for(int a=0 ; a < big ; a++) //KAYBEDENLER�N
		{
			space(3);
			
			if(a < *losers) //KAYBADEN VARSA
			{	
				if(LL[a]->mNickName2 == 0) // �ZEL OLARAK  G�R�LEN ZARLAR ���N
				{
			 		cout<<LL[a]->mNickName;	space(21 - LL[a]->mNickName.size());		
				}
						
				else// �OKLU G�R�LEN ZARLAR ���N
				{
					cout<<LL[a]->mNickName2<<". oyuncu";
						 	
					if(LL[a]->mNickName2/10 < 1)//OYUNCUNUN SIRA NUMARASI 1 BASAMAKLI �SE
						space(12);
						
					else if(LL[a]->mNickName2/10 >= 1 && LL[a]->mNickName2/10 < 10) // 2 BASAMAKLI �SE
						space(11);
						
					else if(LL[a]->mNickName2/10 >= 10 && LL[a]->mNickName2/10 < 100) // 3 BASAMAKLI �SE
						space(10);		
				}
				
				cout<<"/";	space(9); 	cout<<LL[a]->diceNum;	space(9);		
			} 	
			
			else // KAYBEDEN YOKSA
				space(41);
				
				
			space(17);
			
			if(a < *winners) // KAZANAN VARSA
			{
				if(WL[a]->mNickName2 == 0) // �ZEL OLARAK  G�R�LEN ZARLAR ���N
				{
					cout<<WL[a]->mNickName;	space(21 - WL[a]->mNickName.size());		
				}
						
				else// �OKLU G�R�LEN ZARLAR ���N
				{
					cout<<WL[a]->mNickName2<<". oyuncu";
						 	
					if(WL[a]->mNickName2/10 < 1)//OYUNCUNUN SIRA NUMARASI 1 BASAMAKLI �SE
						space(12);
						
					else if(WL[a]->mNickName2/10 >= 1 && WL[a]->mNickName2/10 < 10) // 2 BASAMAKLI �SE
						space(11);
						
					else if(WL[a]->mNickName2/10 >= 10 && WL[a]->mNickName2/10 < 100) // 3 BASAMAKLI �SE
						space(10);	
				}
					
				cout<<"/";	space(9); 	cout<<WL[a]->diceNum;	space(9);  LSpace(1);
			}	
			
			else // KAZANAN YOKSA
				LSpace(1);		
		}	
		
		int *tempCounter = new int(0);
		
	
		delUser(AML, LL, WL, losers, winners);		
		
		
		ptr1 = head;

		if(size == 0) // T�M OYUNCULAR KAYBETT�YSE
		{
			cout<<"\t\t\t\t�zg�n�m kazanan olmam��t�r! \n\n\n\n"; Sleep(2000);
			head = '\0';
			(*tempCounter)++;		
		}
		
		
		else if(size == 1) // 1 K��� KALDIYSA
		{
			cout<<"\t\t\t\t TEBR�KLER ";
			
			if(ptr1->mNickName2 == 0)// �ZEL ZAR �SE
				cout<<ptr1->mNickName;
			else // �OKLU ZAR �SE
				cout<<ptr1->mNickName2<<". OYUNCU,";
		
			cout<<" OYUNUN KAZANANI SENS�N!!\n\n\n\n"; Sleep(2000);
			
			head = '\0';
			(*tempCounter)++;
		}
					
		
		delete losers;	 delete winners;	delete allMember;	delete[] tempAML; 	delete[] LL;	delete[] WL; 	delete[] AML;	
		
		
		if(*tempCounter == 1) // S�ZE DE�ER� 1 YADA 0 �SE
		{
			delete tempCounter;  tempSize=0;  size = 0;  
			
			if(whichMenu == 55) // OTOMAT�K ZAR ATMADAN GEL�ND�YSE
				returnMenu();
			
			else if(whichMenu == 44) // MANUEL ZAR ATMADAN GEL�ND�YSE
			{
				whichMenu=0;
				resume(); return true;
			}
				
		}
		
		if(whichMenu == 44) // MANUEL ZAR ATMADAN GEL�ND�YSE
			resume();
		
		delete tempCounter;
	}	
}

void Dice::delUser(Node **allMemberList, Node **loserList, Node **winnerList, int *losers, int *winners) // KULLANICI S�LME
{	
	LSpace(5); 
	
	#define AML allMemberList
	#define LL loserList
	#define WL winnerList
	
	size = 0;	head = '\0';
	
	if(*losers > 0) // KAYBEDEN VARSA
	{
		for(int a = 0  ; a < *losers ; a++) // KAYBEDENLER� L�NKED L�STLERDEN S�LME
			LL[a] = '\0';
	}
	
		
	if(*winners > 0) // KAZANAN VARSA
	{
		for(int a =  0 ; a < *winners ; a++) // SADECE �OKLU ZARLARDAN YENENLERE TEKRARDAN B�R L�NKED L�ST OLU�TURMA
		{	
			Node *n2;
			
			if(WL[a]->mNickName2 == 0) // �ZEL ZAR �SE 
				n2 = new Node(WL[a]->mNickName, 0, WL[a]->mHeight, WL[a]->mWidth, WL[a]-> mDepth);
			
			else // �OKLU G�R�LM�� ZAR �SE
				n2 = new Node("404", WL[a]->mNickName2 , WL[a]->mHeight, WL[a]->mWidth, WL[a]-> mDepth);

			n2->back = head;
			head = n2;
			size++;		
		}	
	}		
}

void Dice::digit(size_t startStep, int *loserWinner) const // BASAMAK DE�ER� KADAR BO�LUK ATTIRTMA
{
	#define LW loserWinner
	#define SS startStep

	if(*LW/10 < 1) // TEK BASAMAKLI �SE
		space(SS);
	else if(*LW/10 >= 1 && *LW/10 < 10)	 // 2 basamakl� ise
		space(SS-1); 
	else if(*LW/10 >= 10 && *LW/10 < 100) // 3 basamakl� ise
		space(SS-2);
	else if(*LW/10 >= 100 && *LW/10 < 1000) // 4 basamakl� ise
		space(SS-3);
	else if(*LW/10 >= 1000 && *LW/10 < 10000) // 5 basamakl� ise
		space(SS-4);
	else if(*LW/10 >= 10000 && *LW/10 < 100000) // 6 basamakl� ise
		space(SS-5);
	else if(*LW/10 >= 100000 && *LW/10 < 1000000) // 7 basamakl� ise
		space(SS-6);
}

void Dice::successfulProcess() const // BA�ARILI ��LEM MESAJI G�NDERME
{
	#define S Sleep
	#define C cout<<
	
	cls();
	if(size >= 10)
	{
		C"��LEM�N�Z BA�ARIYLA GER�EKLE�T�! ANA SAYFAYA Y�NLEND�R�L�YORSUNUZ";	S(300); C"."; S(250);  C".";  S(250);  C".";  S(550);
	}	
}

void Dice::returnMenu() // ZAR ��LEMLER� MEN�S�NE D�NME
{
	cout<<"ANA MEN�YE D�NMEK ���N HERHANG� B�R HARF G�R�N�Z: ";
	string *temp = new string;
	cin>>*temp;
	
	delete temp; 	cls(); 	gameMenu();
}

void Dice::resume() // DEVAM ETT�RMEK ���N 1 TU� G�RD�RTME
{
	cout<<"DEVAM ETMEK ���N  HERHANG� B�R HARF G�R�N�Z: ";
	string *temp = new string;
	cin>>*temp;
	
	delete temp; 	cls();
}
/////////////////////////////
// NODE CLASS

Dice::Node::Node(string nickName, int tempSize, int height, int width, int depth) : mNickName(nickName), mHeight(height), mWidth(width), mDepth(depth), mCritic(depth-1), mNickName2(0), diceNum(0)//CONSTRUCTOR
{	
	if(mNickName != "404" && height == 0 && width == 0 && depth == 0)
	{	
		Dice *t = new Dice(9.99); //SADECE DE���KEN� KULLANAB�LMEK ���N BUNU B�YLE TANIMLADIM
		
		mHeight = t->setHeight();
		mWidth = t->setWidth();
		mDepth = t->setDepth();
		mCritic = mDepth-1;	
		
		delete t;
	}	
		
	else	
		mNickName2 = tempSize;
}

Dice::Node::Node() {} //DEFAULT CONSTRUCTOR

/////////////////////////////
// �NHER�T CLASSES


