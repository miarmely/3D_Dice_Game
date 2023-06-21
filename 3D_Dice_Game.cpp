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
// MAÝN

int main()
{
	setlocale(LC_ALL,"");
	
	Welcome w1;
	
	

	return 0;
}

////////////////////////////
// DÝCE CLASS

#define mH ptr->mHeight 
#define mW ptr->mWidth 
#define mD ptr->mDepth
#define mC ptr->mCritic

Dice::Dice(): head('\0'), size(0), tempSize(0), backDepth(1), downDepth(0), startSize(0), totalSize(0), whichMenu(9)// DEFAULT CONSTRUCTOR
{	
	gameStart:
	cout<<"\t\t3D ZAR OYUNUNA HOÞGELDÝN!...\n\n";
	cout<<"1) OYUNA GÝRÝÞ \n";
	cout<<"0) OYUNDAN ÇIKIÞ \n\n"; 
	cout<<"Lütfen istediðiniz iþlemin baþýndaki numarayý giriniz: ";
	string decide;
	cin>>decide;
	
	if(decide == "1") // OYUNA GÝRÝÞ
		gameMenu();
	
	
	else if(decide == "0") // OYUNDAN ÇIKIÞ
	{
		cout<<"Ýyi günler efendim!...";  exit(0);
	}
			
	else
	{
		cls();  cout<<"Hatalý giriþ Lütfen tekrar deneyiniz!... \n\n";  goto gameStart;
	} 
} 

Dice::Dice(float fake) {} // FAKE CONSTRUCTOR

int *Dice::harbour() // ZAR LÝMANI
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
			cout<<"\tZAR SAHÝBÝ = "<<ptr->mNickName<<"\n\n";	//STRÝNG ÝSMÝNÝ YAZDIRMA
		
		else
			cout<<"\tZAR SAHÝBÝ = "<<ptr->mNickName2<<". oyuncu \n\n"; //ÝNT ÝSMÝNÝ YAZDIRMA
				
				
		topBody(ptr);
		
		randomNum = 1 + rand()%6;
		reverseShape = 1+rand()%2;
		
		ptr->diceNum = randomNum;
			
		for(int a = 1 ; a <= 2*mH-1 ; a++) // ANA GÖVDENÝN TOPLAM SATIR SAYISI 
		{
			if(a == 1) // ilk satýr
				middleStarLines(ptr);
						    
						    
			else if(a != 2*mH-1) // SON SATIR DEÐÝLSE VE YILDIZ ATILACAK SATIRLARA DENK GELMÝYORSA 
			{
				if( (a == mH/3+2 && randomNum == 1) || (a == mH && (randomNum == 2 || randomNum == 4 || (randomNum == 6 && reverseShape == 2))) || (a == (2*mH-1)-(mH/3+1) && randomNum == 1) ) // ÝLK SATIRSA, ORTANCA SATIRSA VE SON SATIRSA
				{
				    if(a%2 == 0) // ÇÝFT SATIRLARDA !!!!!!!!!! 
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
					if(a%2 == 0) // ÇÝFT SATIRLARDA !!!!!!!!!! 
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
					
					  
			if(randomNum != 1 && a == mH/3+2) // ÝLK YILDIZ SATIRI ÝSE VE ZAR 1 DEÐÝLSE 
			{	
				if(randomNum == 2 || randomNum == 3) // ZAR 2 VEYA 3 ÝSE
				{
					if(reverseShape == 1) // NORMAL HALÝNÝ ÇÝZDÝRME
						L1WantStar1(1, a, ptr);
									
					else //TERS HALÝ
						L3WantStar1(1, a, ptr);				
				}
							
				else if(randomNum == 4 || randomNum == 5 || randomNum == 6) // ZAR 4, 5 VEYA 6  ÝSE
				{
					if(randomNum == 4 || randomNum ==5) // ZAR 4 VEYA 5 ÝSE
						wantStar2(2, a, ptr);
									
					else // ZAR 6 ÝSE
					{
						if(reverseShape == 1) // NORMAL HALÝNÝ ÇÝZDÝRME
							wantStar2(2, a, ptr);
								
						else //TERS HALÝ
							wantStar3(3, a, ptr);	
					}
				}	
			}
				
			else if(a == mH) // ORTANCA YILDIZ SATIRI
			{
				if(randomNum == 1 || randomNum == 3 || randomNum == 5)
					L2WantStar1(a, ptr);
					
				else if(randomNum == 6 && reverseShape == 1)// ZAR 6 ÝSE VE NORMAL HALÝ ÇÝZDÝRÝLÝCEKSE
					wantStar2(2, a, ptr);		
			}
					
			
			else if(a == (2*mH-1)-(mH/3+1) && randomNum != 1) // SON YILDIZ SATIRI ÝSE VE ZAR 1 DEÐÝLSE (FORMULÜ SADELEÞTÝRÝRSEN SIKINTI ÇIKIYOR SADELEÞTÝRME)
			{
				if(randomNum == 2 || randomNum == 3) // ZAR 2 VEYA 3 ÝSE
				{
					if(reverseShape == 1) // NORMAL HALÝNÝ ÇÝZDÝRME
						L3WantStar1(1, a, ptr);
							
					else //TERS HALÝ
						L1WantStar1(1, a, ptr);				
				}
					
				else if(randomNum == 4 || randomNum == 5 || randomNum == 6) // ZAR 4, 5 VEYA 6  ÝSE
				{
					if(randomNum == 4 || randomNum ==5) // ZAR 4 VEYA 5 ÝSE
						wantStar2(2, a, ptr);
							
					else // ZAR 6 ÝSE
					{
						if(reverseShape == 1) // NORMAL HALÝNÝ ÇÝZDÝRME
							wantStar2(2, a, ptr);
								
						else //TERS HALÝ
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

void Dice::downDepthFunc(Node *ptr)// TABAN DERÝNLÝK YILDIZI ATTIRMA
{
	if(backDepth >= mH)
	{
		space(mC-(2+downDepth));
		cout<<"*";
		downDepth++;
	}
}

bool Dice::backDepthFunc(Node *ptr)// ARKA DERÝNLÝK YILDIZI ATTIRMA
{
	if(backDepth < mH)// ARKA DERÝNLÝK SAYISI YÜKSEKLÝK DEÐERÝNE EÞÝT DEÐÝLSE
	{
		space(mC-1);
		cout<<"*";
		backDepth++;
		return true;
	}
	
	return false;
}

void Dice::starLines(Node *ptr) const// ÝLK SATIR YILDIZLARI
{
	for(int a = 0 ; a < mW ; a++) 
	{
		if(a < mW-1)
			cout<<"*  ";
			
		else // SON YILDIZI BOÞLUKSUZ YAPMA
			cout<<"*";				
	}	
}

void Dice::middleStarLines(Node *ptr)// ORTADAKÝ KOMPLE YILDIZLI SATIR
{
	   starLines(ptr);
	   singleLinesCritic(ptr);
}

void Dice::space(int amount) const // BOÞLUK ATTIRMA 
{
	for(int a = 0 ; a < amount ; a++)
		cout<<" ";
}

void Dice::LSpace(int amount) const // SATIR BOÞLUK ATTIRMA
{
	for(int a = 1 ; a <= amount ; a++)
		cout<<"\n";
}

void Dice::otherLines(Node *member) const // 2 YILDIZ VE BOÞLUKLU OLAN SATIRLAR 
{
	cout<<"*";
			
	for(int a = 0 ; a < 3*member->mWidth-4 ; a++)
		cout<<" ";
				
	cout<<"*";
}

void Dice::topBody(Node *ptr)  // ÜST GÖVDE
{
	for(int b = 1 ; b <= mD-1 ; b++)
	{
		space(mD-b);
			
		if(b == 1)// ÝLK SATIR YILDIZLARIný ÇAÐIRMA
			starLines(ptr);
			
		else
		{
			otherLines(ptr);
			
			if(b%2 != 0 && backDepth < mH)// SATIR SAYISI TEKSE ARKA DERÝNLÝK ATTIRMA 
			{
				space(b-2);
				cout<<"*";
				backDepth++;
			}
			
			else if(backDepth == mH)// TABAN DERÝNLÝK YILDIZLARI
			{
				space(2*mH-3);
				cout<<"*";
				downDepth++;
			}
		}			
		cout<<"\n";
	}		
}

void Dice::mainBody(Node *ptr) // 3D PRÝZMANIN ANA GÖVDESÝ
{
	for(int a = 1 ; a <= 2*mH-1 ; a++) // ANA GÖVDE SATIRLARI
	{		
		if(mC%2 == 0) // KRÝTÝK ÇÝFTSE
		{
			if(a == 1)// ÝLK SATIRDA
			{
				starLines(ptr);
				backDown(ptr);
			}
			
			else if(a < 2*mH-1) //ARADAKÝ SATIRLAR
			{
				if(a%2 == 0)//SATIR SAYILARI ÇÝFTSE 
				{
					space(3*mW-2);// 1 YILDIZ + BOÞLUK + 1 YILDIZ KOMBÝNASYONUNDA YILDIZ SAYILARINI DA BOÞLUKLARA DAHÝ EDÝP BOÞLUK ATTIRTIYORUM 		 	
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
		
		else if(mC%2 != 0) // KRÝTÝK TEKSE
		{
			if(a == 1)// ÝLK SATIRDA
			{
				starLines(ptr);
				
				if(backDepth == mH)
				{
					space(2*mH-3);
					cout<<"*";
					downDepth++;
				}	
			}
				
			else if(a < 2*mH-1) // ARADAKÝ SATIRLAR 
			{
				if(a%2 == 0)//SATIR SAYILARI ÇÝFTSE 
				{
					space(3*mW-2);// 1 YILDIZ + BOÞLUK + 1 YILDIZ KOMBÝNASYONUNDA YILDIZ SAYILARINI DA BOÞLUKLARA DAHÝ EDÝP BOÞLUK ATTIRTIYORUM 	
					
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

void Dice::diceShape()// ZAR ÞEKÝLÝ ÇÝZDÝRME
{	
	Node *ptr = head;
	int memberCounter=0;
	cls();
	
	while(ptr)
	{
		if(ptr->mNickName2 == 0)
			cout<<"\t\tZAR SAHÝBÝ: "<<ptr->mNickName<<"\n\n"; 
		
		else
			cout<<"\t\tZAR SAHÝBÝ: "<<ptr->mNickName2<<". oyuncu \n\n"; 
		
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

void Dice::gameMenu()// OYUN MENÜSÜ
{	
	decide2Repeat:
	cls();
	cout<<"\t\tANA MENÜ\n\n";
	cout<<"1) ÖZEL ZAR EKLE\n";
	cout<<"2) ÇOKLU ZAR EKLE\n";
	cout<<"3) SEÇÝLEN ZARLARI GÖRÜNTÜLE \n";
	cout<<"4) MANUEL ZAR AT \n";
	cout<<"5) OTOMATÝK ZAR AT \n";
	cout<<"0) OYUNDAN ÇIKIÞ\n\n";
	cout<<"Lütfen istediðiniz iþlemin baþýndaki numarayý giriniz: ";
	string decide2;
	cin>>decide2;
		
	cls();
		
	if(decide2 == "1") // ÖZEL ZAR EKLEME
	{
		repeatNickName:
		fflush(stdin);
		cout<<"Lütfen bir nick name giriniz: ";
		string nickName;
		getline(cin,nickName);
		cout<<"\n";
			
			
		if(nickName.size() > 20 || nickName.size() <= 0)
		{
			cout<<"Geçersiz nickName! Lütfen 1 ile 20 karakter arasýnda bir nickName seç!\n\n";
			goto repeatNickName;
		}
			
		startSize++;
			
		if(startSize >= 1000000) 
		{
			cls();	cout<<"Üzgünüm, Max 999bin zar ekleyebilirsin!...\n\n";  startSize-=1; 	goto amountDiceRepeat;
		}
			
			
		User(nickName,0,0,0,0);
			
		LSpace(2);
		resBackDown();
	}
		
		
	else if(decide2 == "2") // ÇOKLU ZAR EKLEME
	{
		amountDiceRepeat:
		cout<<"Kaç tane zar eklemek istersin? : ";
		int amountDice;
		cin>>amountDice;
		LSpace(1);
			
			
		if(amountDice <= 0 || amountDice >= 1000000) //0 ile 1 milyon zar arasýnda
		{
			cls();	cout<<"HEY, ORDA DUR!..."; Sleep(1500);  cls();  cout<<"EN AZ = 1, EN FAZLA = 999BÝN ZAR EKLEYEBÝLÝRSÝN!...\n\n\n";	 goto amountDiceRepeat;
		}
						
		startSize+=amountDice;
			
		if(startSize >= 1000000) 
		{
			cls();	cout<<"HEY, ORDA DUR!..."; Sleep(1500);  cls();  cout<<"EN FAZLA 999BÝN ZAR EKLEYEBÝLÝRSÝN!...\n\n\n";  startSize-=amountDice; 	goto amountDiceRepeat;
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
		
		
	else if(decide2 == "3") // SEÇÝLEN ZARLARI GÖRÜNTÜLE 
	{
		if(size > 0)
		{
			diceShape(); LSpace(2); returnMenu();	
		}
					
		else
			cout<<"Görüntülenecek herhangi bir zar bulunamadý. Lütfen Tekrar dene!...\n"; Sleep(2000);
	}
		
		
	else if(decide2 == "4") // ZARLARI MANUEL AT 
	{
	    int *temp4 = new int;	int *counter4 = new int(0);  string *decide2_4 = new string;  string *decide2_4_1 = new string;
		
		#define D1 decide2_4
		#define D2 decide2_4_1
		
		decide2_4:
		cls();
		cout<<"\t\t MANUEL ZAR MENÜSÜ\n\n";
		cout<<"1) ZAR GÖRÜNTÜLE\n";
		cout<<"2) ZAR AT \n";
		cout<<"0) GERÝ GEL\n\n";
		cout<<"lütfen gerçekleþtirmek istediðiniz iþlemin baþýndaki numarayý giriniz: ";
		cin>>*D1;
		cls();
		
		
		if(*D1 == "1") // ZARLARI GÖRÜNTÜLE
		{
			if(size > 0)
			{
				diceShape();  LSpace(2);  resume();  cls();  goto decide2_4;	
			}
						
			else
				cout<<"Görüntülenecek herhangi bir zar bulunamadý. Lütfen Zar ekle!...\n";  Sleep(2000);  gameMenu();
		}
		
		
		else if(*D1 == "2") // ZARLARI AT
		{
			if(size > 0) // ZAR EKLENMÝÞ ÝSE
			{
				temp4 = harbour();  
				(*counter4)++;  
				resume();  
				
				decide2_4_1:
				cls();	
				cout<<"\t\t TUR MENÜSÜ\n\n";
				cout<<"1) ÝSTATÝSTÝKLERÝ GÖRÜNTÜLE \n";
				cout<<"0) ANA MENÜYE DÖN \n\n";
				cout<<"lütfen gerçekleþtirmek istediðiniz iþlemin baþýndaki numarayý giriniz: ";
				cin>>*D2;
				cls();
				
				if(*D2 == "1") // TURUN ÝSTATÝSTÝKLERÝ
				{
					whichMenu=44;
					
					if(*counter4 > 0) // ZARLAR ATILMIÞSA
					{
						winLoseTable();  
						 
						if(size > 1) // 1 DEN FAZLA OYUNCU VARSA
						{
							graphic(temp4); resume();
						}
						
						goto decide2_4; 	
					}
						
					else // ATILMAMIÞSA
					{
						 cout<<"ÖNCE ZAR ATMALISIN!\n\n";  Sleep(2000);  goto decide2_4;
					}	
				}
				
				
				else if(*D2 == "0") // ANA MENÜ
				{
					decide3:
					cout<<"EÐER ANA MENÜYE DÖNERSENÝZ BU TURUN GRAFÝÐÝNÝ VE TABLOSUNU GÖREMEYECEKSÝNÝZ DEVAM ETMEK ÝÇÝN 1'e, VAZGEÇMEK ÝÇÝN 0'a BASINIZ: ";
					string *decide = new string;
					cin>>*decide;
					delete decide; 
				
					
					if(*decide == "1") // DEVAM EDÝLDÝYSE
					{
						delete counter4;  delete temp4;  delete D1;  delete D2;  
						gameMenu();
					}
						
							
					else if(*decide == "0") // VAZGEÇÝLDÝYSE
						goto decide2_4_1;
						
						
					else // GEÇERSÝZ HARF GÝRÝÞÝ OLURSA
					{
						cls();  cout<<"GEÇERSÝZ ÝÞLEM! LÜTFEN TEKRAR DENE...\n\n";  goto decide3;
					} 	
				}
			}
			
			
			else // ZAR EKLENMEMÝÞ ÝSE
			{
				cout<<"ATILACAK HERHANGÝ BÝR ZAR BULUNMAMAKTADIR, LÜTFEN ÖNCE ZAR EKLEYÝNÝZ!!\n\n";  Sleep(2000);  delete counter4;  delete temp4;  delete decide2_4;  gameMenu();
			}		
		}
		

		else if(*D1 == "0") // GERÝ GEL
		{
			delete counter4;  delete temp4;  delete D1;  delete D2;  
			gameMenu();
		}
			
		whichMenu=0;  *counter4=0;  goto decide2_4;	
	}
			
		
	else if(decide2 == "5") // ZARLARI OTOMATÝK AT
	{
		if(size > 1)//1 DEN FAZLA OYUNCU VAR ÝSE 
		{
			int *tempCounter1 = new int(0);
			int *round = new int(1);
			whichMenu=55;
				
			cout<<"\t\tSEÇÝLEN ZARLAR GETÝRÝLÝYOR!";  Sleep(600); cout<<"."; Sleep(450);  cout<<".";  Sleep(450);  cout<<".";  Sleep(750);  LSpace(2);
			diceShape();  LSpace(2); Sleep(2000);
				
			cout<<"\t\tHAZIR MISIN? OYUN BAÞLIYOR!";  Sleep(600); cout<<"."; Sleep(450);  cout<<".";  Sleep(450);  cout<<".";  Sleep(1500);  cls(); Sleep(100);		
			while(size != 0) // OYUNCU VARSA
			{
				if(size > 1) // OYUNCU SAYISI 1'DEN BÜYÜKSE 
				{		
					int *temp = new int;
											
					cout<<"\t\t"<<*round<<". TURUN ZARLARI ATILIYOR... BOL ÞANS!!\n\n\n\n\n"; Sleep(1600);
						
					temp = harbour(); Sleep(2500); LSpace(3);
					winLoseTable(); Sleep(4000); 
					graphic(temp);  Sleep(3500); LSpace(4);  
						
					(*round)++;
					delete[] temp;		
				}
				
				(*tempCounter1)++;	
				
			}
				
			if(size == 0 && *tempCounter1 == 0)
				cout<<"Görüntülenecek herhangi bir zar bulunamadý. Lütfen Tekrar dene!..."; Sleep(2000);
				
			whichMenu=0;  tempSize = 0;  head = '\0';  delete tempCounter1;  delete round; 	fflush(stdin); 	 totalSize = 0;
			returnMenu();
		}
		
		else if(size==1) // ZAR SAYISI 1 DEN AZ ÝSE
		{
			cls();	cout<<"Üzgünüm, Otamatik zar atmak için en az 2 oyuncu olmasý gerekiyor!\n\n";  Sleep(2000);
		}
		
		else
		{
			cls(); 	cout<<"Otamatik atýlacak herhangi bir zar bulunamadý. Lütfen Tekrar dene!..."; Sleep(2000); 
		}
		
		gameMenu();
	}
				
			
	else if(decide2 == "0") // OYUNDAN ÇIKIÞ
	{
		cout<<"Ýyi günler efendim!...\n\n\n";  exit(0);
	}
	
		
	else
		cout<<"Hatalý giriþ Lütfen tekrar deneyiniz!... \n\n"; 
			
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

void Dice::cls() const // EKRANI SÝLME
{
	system("cls");
}

void Dice::resBackDown() // ARKA VE TABAN DERÝNLÝK YILDIZ DEÐÝÞKENLERÝNÝN DEÐERLERÝNÝ RESETLEME
{
	backDepth=1;
	downDepth=0;
}

void Dice::L1WantStar1(int amountStar, int line, Node *ptr) // 1. SATIRDA ÝSTENEN YILDIZ SAYISI 1 ÝSE 
{
	if(line%2 == 0) // 1. YILDIZ SATIRI ÇÝFTSE
	{
		space((3*mW-5)/3); // ÝLK YILDIZ BOÞLUÐU
		cout<<"#";
		
		if(amountStar == 1) // 1 TANE YILDIZ ÝSTENMÝÞSE
		{
			space((6*mW-4)/3+1); // SATIRIN SONUNA KADAR BOÞLUK 
			coupleLinesCritic(ptr);	
		}			
	}
	
	else  // 1. YILDIZ SATIRI TEKSE 
	{
		cout<<"*";
		space((3*mW-8)/3);
		cout<<"#";
		
		if(amountStar == 1) // ÝSTENEN 1 YILDIZ ÝSE
		{
			space((6*mW-6)/3); // SATIR SONUNA KADAR BOÞLUK
			cout<<"*";
			singleLinesCritic(ptr);		
		}
	}
}

void Dice::wantStar2(int amountStar, int line, Node *ptr) // 1. SATIRDA ÝSTENEN YILDIZ SAYISI 2 ÝSE 
{
	L1WantStar1(2, line, ptr);
	
	if(amountStar == 2) // ORTANCA YILDIZSIZ
	{
		space((3*mW+1)/3); // ÝLK YILDIZLA SON YILDIZ ARASI BOÞLUK (çift satýr veya tek satýr farketmez)
		cout<<"#";
	}
	
	else if(amountStar == 3)// ORTANCA YILDIZ ÝLE
	{
		if(mW%2 == 0)// TABAN ÇÝFTSE
		{
			space((3*mW-5)/6); //ÝLK YILDIZ ÝLE 2 TANE ORTANCA YILDIZ ARASI BOÞLUK
			cout<<"##"; // ORTANCA ÇÝFT YILDIZ
			space((3*mW-5)/6); //2 TANE ORTANCA YILDIZ ÝLE SON YILDIZ ARASI BOÞLUK
			cout<<"#"; // SON YILDIZ
		}
		
		else // TABAN TEKSE
		{
			space((3*mW+1)/6); //ilk yýldýzla ortanca yýldýz arasýndaki boþluk
			cout<<"#"; // ORTANCA TEK YILDIZ
			space((3*mW+1)/6);	//ortanca yýldýzla son yýldýz arasýndaki boþluk
			cout<<"#"; // SON YILDIZ
		}
		
	}
	
	if(amountStar == 2 || amountStar == 3) // SADECE 2 TANE YILDIZ OLMASINI ÝSTEMÝÞSE 
	{
		if(line%2 == 0) // 1. SATIR ÇÝFTSE
		{
			space((3*mW-5)/3); // SON YILDIZDAN SATIR SONUNA KADARKÝ OLAN BOÞLUKLAR
			coupleLinesCritic(ptr);			
		}
					
		else// 1. SATIR TEKSE 
		{
			space((3*mW-8)/3); //SON YILDIZDAN SATIR SONUNA KADARKÝ OLAN BOÞLUKLAR
			cout<<"*";
			singleLinesCritic(ptr);		
		}									
	}	
}

void Dice::wantStar3(int amount, int line, Node *ptr) // 1. SATIRDA ÝSTENEN YILDIZ SAYISI 3 ÝSE 
{
	wantStar2(3, line, ptr);	
}

void Dice::L2WantStar1(int line, Node *ptr) // ORTANCA SATIR YILDIZI
{
	if(mH%2 == 0) // YÜKSEKLÝK ÇÝFTSE
	{
		if(mW%2 == 0) // TABAN ÇÝFTSE
		{
			space((3*mW-4)/2); // ORTANCA YILDIZI KADAR KÝ BOÞLUK
			cout<<"##";
			space((3*mW-4)/2); // ORTANCA YILDIZDAN SONRA KÝ BOÞLUK	
		}
		
		else if(mW%2 != 0) // TABAN TEKSE
		{
			space((3*mW-2)/2); // ORTANCA YILDIZI KADAR KÝ BOÞLUK
			cout<<"#";
			space((3*mW-2)/2); // ORTANCA YILDIZDAN SONRA KÝ BOÞLUK
		}
		
		coupleLinesCritic(ptr);
	}
	
	else // YÜKSEKLÝK TEKSE
	{
		cout<<"*";	
		if(mW%2 == 0) // TABAN ÇÝFTSE
		{
			space((3*mW-6)/2); // ORTANCA YILDIZI KADAR KÝ BOÞLUK
			cout<<"##";
			space((3*mW-6)/2); // ORTANCA YILDIZDAN SONRA KÝ BOÞLUK	
		}
		
		else if(mW%2 != 0) // TABAN TEKSE
		{
			space((3*mW-4)/2); // ORTANCA YILDIZI KADAR KÝ BOÞLUK
			cout<<"#";
			space((3*mW-4)/2); // ORTANCA YILDIZDAN SONRA KÝ BOÞLUK
		}
		cout<<"*";
		
		singleLinesCritic(ptr);
	}
}

void Dice::L3WantStar1(int amount, int line, Node *ptr) // SON SATIRDA ÝSTENEN YILDIZ SAYISI 1 ÝSE
{
	if( ((2*mH-1)-(mH/3+1) )%2 == 0) //YÜKSEKLÝK ÇÝFTSE (BU FORMULÜ SADELEÞTÝRME HATALI SONUÇ VERÝR)
	{
		space((6*mW-1)/3);//ZAR YILDIZINA KADAR OLAN BOÞLUK
		cout<<"#";
		space((3*mW-5)/3);//ZAR YILDIZIYLA SATIR SONUNA KADAR OLAN BOÞLUK
			
		coupleLinesCritic(ptr);
	}
	
	else // YÜKSEKLÝK TEKSE
	{
		cout<<"*";
		space((6*mW-4)/3);//ZAR YILDIZINA KADAR OLAN BOÞLUK
		cout<<"#";
		space((3*mW-8)/3);//ZAR YILDIZIYLA SATIR SONUNA KADAR OLAN BOÞLUK
		cout<<"*";
		
		singleLinesCritic(ptr);
	}
}

void Dice::backDown(Node *ptr)// ARKA DERÝNLÝK YILDIZI ÝLE TABAN DERÝNLÝK YILDIZINDAN HANGÝNÝNÝN ATILACAÐINA KARAR VERDÝRME
{
	if(backDepthFunc(ptr)) ; 
				
	else
		downDepthFunc(ptr);
}

void Dice::singleLinesCritic(Node *ptr) // TEK SATIRLARDA KRÝTÝK DEÐERLERÝNE GÖRE ARKA YADA TABAN YILDIZINI ATTIRMA
{
	if(mC%2 == 0)// KRÝTÝK ÇÝFTSE	
		backDown(ptr); 
				
	else// KRÝTÝK TEKSE 
		downDepthFunc(ptr);
}

void Dice::coupleLinesCritic(Node *ptr) // ÇÝFT SATIRLARDA KRÝTÝK DEÐERLERÝNE GÖRE ARKA YADA TABAN YILDIZINI ATTIRMA
{
	if(mC%2 == 0)// KRÝTÝK ÇÝFTSE
		downDepthFunc(ptr);
		
	else// KRÝTÝK TEKSE 
		backDown(ptr);	
}

int Dice::setHeight() // YÜKSEKLÝK ALDIRMA
{
	repeat_height:
	cout<<"Yükseklik deðeri giriniz: ";
	int height;
	cin>>height;
		
	if(height < 5)
	{
		cls();
		cout<<"Lütfen 5 ve 5 ten büyük rakamlar giriniz!...\n\n";
		goto repeat_height;
	}
	
	return height;
}

int Dice::setWidth() // GENÝÞLÝK ALDIRMA
{
	repeat_width:
	cout<<"Geniþlik deðeri giriniz: ";
	int width;
	cin>>width;
		
	if(width < 5)
	{
		cls();
		cout<<"Lütfen 5 ve 5 ten büyük rakamlar giriniz!...\n\n";
		goto repeat_width;
	}
	
	return width;
}

int Dice::setDepth() // DERÝNLÝK ALDIRTMA
{
	repeat_depth:
	cout<<"Derinlik deðeri giriniz: ";
	int depth;
	cin>>depth;
		
	if(depth < 5)
	{
		system("cls");
		cout<<"Lütfen 5 ve 5 ten büyük rakamlar giriniz!...\n\n";
		goto repeat_depth;
	}
	
	return depth;
}

void Dice::forFunc(string wanting, int amount) const // FOR ÝLE YAN YANA ÝSTENEN HERHANGÝ BÝR ÞEYÝ YAZDIRMA 
{
	for(int a=0 ; a<amount ; a++)
		cout<<wanting;
}

void Dice::graphic(int *array)  // OYUNCULARIN ZAR DEÐERLERÝNÝN GRAFÝÐÝNÝ ÇÝZDÝRMA
{
	space(24);	forFunc("-", 22); LSpace(1); cout<<"\t\t\t| MÝKTAR-ZAR GRAFÝÐÝ |"; LSpace(1); 	space(24);   forFunc("-", 22); 
	
	int *six = new int(0);  
	int *five = new int(0);   
	int *four = new int(0);   
	int *three = new int(0);   
	int *two = new int(0);   
	int *one = new int(0);   
	int *column = new int(0);
	int *diceCompare = new int[6]; 
	int *tempArray = new int[6];
	
	
	for(int a = 0 ; a < totalSize ; a++) // ZAR DEÐERLERÝNÝ DEÐÝÞKENE AKTARMA
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
	
	for(int a = 0 ; a < 6 ; a++) // KAÇ TANE SUTÜN KOYMAM GEREKTÝÐÝNÝ SAYACAK
	{
		if(diceCompare[a] != 0)
			(*column)++;
		
		tempArray[a] = diceCompare[a]; //Zar deðerlerini sýralamadan önce geçici bir diziye aktarýyorum. Buunu yapmamýn sebebi grafiði çizdikten sonra x ekseninin altýnda hangi sutünün hangi zara ait olduðunu buldurup onun adýný yazdýrmak için
	}
		
	
	for(int a = 0 ; a < 6 ; a++)// DÝZÝDEKÝ SAYILARI KÜÇÜKTEN BÜYÜÐE SIRALAMA
		for(int b = 0 ; b < 5 ; b++)
		{
			if(diceCompare[b] > diceCompare[b+1])
				swap(diceCompare[b],diceCompare[b+1]);
		}
						
	space(3); cout<<"MÝKTAR \n"; //G GRAFÝÐÝN Y EKSENÝNÝN ANAHTAR SÖZCÜÐÜ
	
	for(int a = 0 ; a < diceCompare[5]+3 ; a++) // Y EKSENÝ
	{		
		if(a < 3)//DEÐÝÞMEZ SABÝT
		{
			space(5);
			
			if(a==0)
				cout<<"^";
					
			else if(a==1)
				cout<<"|";
						
			else if(a==2) //3. SATIRA SUTÜN ÇATILARINI ATTIRMA(EN BÜYÜK SÜTUN YA DA SÜTUNLARIN ÇATISI)
			{
				cout<<"|";
				for(int b = 5 ; b >= 0 ; b--)
				{
					if(diceCompare[5] == diceCompare[b])
					{	
						space(3);	cout<<" _____ ";
					}
					
					else break; //EÐER 1 TANE EÞLEÞMEYEN OLURSA DÝREK DÖNGÜDEN ÇIKARICAM BÜYÜKTEN KÜÇÜÐE DOÐRU SIRALANIYOR(BOÞUNA DÝÐERLERÝNE DAHA BAKMASIN DÝYE)	
				}	
			}							
		}
			
			
		else if(a>=3)// OLAY BURDA
		{	
			if((diceCompare[5]+3-a)/10 < 1) //EÐER GRAFÝÐÝN Y EKSENÝNDEKÝ SAYI TEK BASAMAKLI ÝSE SAYIDAN ÖNCE 3 BOÞLUK ATAR
				space(3);
				
			else // 2 BASAMAKLI ÝSE SAYI YAZDIRMADAN ÖNCE 2 BOÞLUK ATAR
				space(2);
			
			for(int b = 0 ; b < 6 ; b++) // SADECE SUTÜNLARIN EN ÜST NOKTASI HÝZASINDAKÝ SATIRA Y EKSENÝNDE SAYI YAZDIRMA
			{
				if(diceCompare[b] == diceCompare[5]+3-a)
				{
					cout<<diceCompare[5]+3-a<<" "<<"|"; // O SATIRDAKÝ SUTÜNÜN BOYUTUNU YAZAR
					break;
				}		
				
				else if(b==5)// SON SATIRSA
				{
					if((diceCompare[5]+3-a)/10 >= 1) // O SATIR ÇÝFT BASAMAKLI BÝR SATIRSA 3 BOÞLUK ATAR
						cout<<"   ";
									
					else // TEK BASAMAKLIYSA 2 BOÞLUK ATAR
						cout<<"  ";
						
					cout<<"|";
				}				
			}
	
	
			for(int b = 5 ; b >= 0 ; b--) //O SATIRDAKÝ SUTÜNLARIN KENARLARINI ÇÝZDÝRME
			{
				if(diceCompare[b] >= diceCompare[5]+3-a) //ZAR DEÐERLERÝNE BAKIP ÝÇÝN O SATIRDAKÝ Y DEÐERÝNE EÞÝT YA DA BÜYÜKSE ONUN ÝÇÝN SUTÜN KENARI EKLER
				{
					space(3);	cout<<"|";	space(5);	cout<<"|"; // 3 BOÞLUK + 1 SUTÜN (SUTÜN KENARLARINI ÇÝZDÝRME)	
				}
					
					
				else if(diceCompare[b] != 0) // EÐER O ZAR VARSA
				{
					if(diceCompare[b] == diceCompare[5]+2-a) // Y EKSENÝNDE BÝR ALT SATIRDAKÝ SAYI DEÐERÝNE EÞÝTSE ÇATI KOYAR.
					{
						space(3);	cout<<" _____ ";
					}			
				}	
			}	
		}
		
		LSpace(1);	
	}
	
	
	space(5);
	
	for(int a = 0 ; a < *column*10+4 ; a++)//X EKSENÝ ÇÝZDÝRTME
	{
		if(a != *column*10+3)
			cout<<"-";
		
		else
			cout<<"> ZAR";	 // X EKSENÝNÝN ANAHTAR SÖZCÜÐÜ
	}
	
	LSpace(1);	space(5);
	
	
	for(int a=5 ; a>=0 ; a--) // HANGÝ SUTÜNÜN HANGÝ ZARA AÝT OLDUÐUNU BULUP SUTÜNÜN ÝSMÝNÝ YAZDIRMA
		for(int b=0; b<6 ; b++) // GEÇÝÇÝ ZARA ATANMIÞ ZAR NUMARALARINA BAKTIRMA
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

bool Dice::winLoseTable() //KAZANAN KAYBEDEN TABLOSUNU ÇÝZDÝRME  (BOOL YAPMAMIN SEBEBÝ HERHANGÝ BÝR YERDE DÝREK FONKSÝYONU RETURN ÝLE KAPATABÝLMEK ÝÇÝN YANÝ FAKE BOOL DÝYEBÝLÝRÝZ)
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
		

		while(ptr1) // KAYBEDEN VE KAZANAN ÜYELERÝN ADRESLERÝNÝ DÝZÝLERE AKTARMA
		{
			tempAML[*allMember] = ptr1;
			(*allMember)++;	
			
			if(ptr1->diceNum <= 3)	// ZAR DEÐERÝ 3 TEN KÜÇÜKSE
			{
				LL[*losers] = ptr1;
				(*losers)++;	
	    	}
			
			else if(ptr1->diceNum > 3) // ZAR DEÐERÝ 3 TEN BÜYÜKSE
			{
				WL[*winners] = ptr1;	
				(*winners)++;
			}	
			
			if(ptr1->back == NULL)
				break;
				
			ptr1 = ptr1->back;
		}
		
		for(int a = 0 ; a < *allMember ; a++) // DÝZÝDEKÝ VERÝLERÝ ESKÝDEN YENÝYE GÖRE SIRALAMAK ÝÇÝN YAPTIM
			AML[a] = tempAML[*allMember-(a+1)];
			
		
				
		space(43);	forFunc("-", 17);	LSpace(1);
		space(43);  cout<<"| TUR SONUÇLARI |\n";
		space(43);	forFunc("-", 17);	LSpace(1);
		
		space(51);  cout<<"|";	LSpace(1); //1. DÜÐÜM 		
		space(22); 	forFunc("-", 59);	LSpace(1);
		space(22);  cout<<"|";	space(57); 	cout<<"|"; LSpace(1);//2. DÜÐÜMLER
		
		space(1);   forFunc("-", 43); 	space(15); 	forFunc("-", 43);	LSpace(1);
		space(1); 	cout<<"| KAYBEDENLER = "<<*losers; 	digit(6, losers);	cout<<"/    ZAR DEÐERLERÝ |";	space(15);	  cout<<"| KAZANANLAR = "<<*winners;   digit(7, winners);   cout<<"/    ZAR DEÐERLERÝ |";	LSpace(1);
		space(1);   forFunc("-", 43); 	space(15); 	forFunc("-", 43);	LSpace(1);
		
			
		int big;
		
		if(*losers >= *winners)	//DÝZÝDEKÝLERÝN ADLARINI YAZDIRMA	
			big = *losers;
		else
			big = *winners;
		
			
		for(int a=0 ; a < big ; a++) //KAYBEDENLERÝN
		{
			space(3);
			
			if(a < *losers) //KAYBADEN VARSA
			{	
				if(LL[a]->mNickName2 == 0) // ÖZEL OLARAK  GÝRÝLEN ZARLAR ÝÇÝN
				{
			 		cout<<LL[a]->mNickName;	space(21 - LL[a]->mNickName.size());		
				}
						
				else// ÇOKLU GÝRÝLEN ZARLAR ÝÇÝN
				{
					cout<<LL[a]->mNickName2<<". oyuncu";
						 	
					if(LL[a]->mNickName2/10 < 1)//OYUNCUNUN SIRA NUMARASI 1 BASAMAKLI ÝSE
						space(12);
						
					else if(LL[a]->mNickName2/10 >= 1 && LL[a]->mNickName2/10 < 10) // 2 BASAMAKLI ÝSE
						space(11);
						
					else if(LL[a]->mNickName2/10 >= 10 && LL[a]->mNickName2/10 < 100) // 3 BASAMAKLI ÝSE
						space(10);		
				}
				
				cout<<"/";	space(9); 	cout<<LL[a]->diceNum;	space(9);		
			} 	
			
			else // KAYBEDEN YOKSA
				space(41);
				
				
			space(17);
			
			if(a < *winners) // KAZANAN VARSA
			{
				if(WL[a]->mNickName2 == 0) // ÖZEL OLARAK  GÝRÝLEN ZARLAR ÝÇÝN
				{
					cout<<WL[a]->mNickName;	space(21 - WL[a]->mNickName.size());		
				}
						
				else// ÇOKLU GÝRÝLEN ZARLAR ÝÇÝN
				{
					cout<<WL[a]->mNickName2<<". oyuncu";
						 	
					if(WL[a]->mNickName2/10 < 1)//OYUNCUNUN SIRA NUMARASI 1 BASAMAKLI ÝSE
						space(12);
						
					else if(WL[a]->mNickName2/10 >= 1 && WL[a]->mNickName2/10 < 10) // 2 BASAMAKLI ÝSE
						space(11);
						
					else if(WL[a]->mNickName2/10 >= 10 && WL[a]->mNickName2/10 < 100) // 3 BASAMAKLI ÝSE
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

		if(size == 0) // TÜM OYUNCULAR KAYBETTÝYSE
		{
			cout<<"\t\t\t\tÜzgünüm kazanan olmamýþtýr! \n\n\n\n"; Sleep(2000);
			head = '\0';
			(*tempCounter)++;		
		}
		
		
		else if(size == 1) // 1 KÝÞÝ KALDIYSA
		{
			cout<<"\t\t\t\t TEBRÝKLER ";
			
			if(ptr1->mNickName2 == 0)// ÖZEL ZAR ÝSE
				cout<<ptr1->mNickName;
			else // ÇOKLU ZAR ÝSE
				cout<<ptr1->mNickName2<<". OYUNCU,";
		
			cout<<" OYUNUN KAZANANI SENSÝN!!\n\n\n\n"; Sleep(2000);
			
			head = '\0';
			(*tempCounter)++;
		}
					
		
		delete losers;	 delete winners;	delete allMember;	delete[] tempAML; 	delete[] LL;	delete[] WL; 	delete[] AML;	
		
		
		if(*tempCounter == 1) // SÝZE DEÐERÝ 1 YADA 0 ÝSE
		{
			delete tempCounter;  tempSize=0;  size = 0;  
			
			if(whichMenu == 55) // OTOMATÝK ZAR ATMADAN GELÝNDÝYSE
				returnMenu();
			
			else if(whichMenu == 44) // MANUEL ZAR ATMADAN GELÝNDÝYSE
			{
				whichMenu=0;
				resume(); return true;
			}
				
		}
		
		if(whichMenu == 44) // MANUEL ZAR ATMADAN GELÝNDÝYSE
			resume();
		
		delete tempCounter;
	}	
}

void Dice::delUser(Node **allMemberList, Node **loserList, Node **winnerList, int *losers, int *winners) // KULLANICI SÝLME
{	
	LSpace(5); 
	
	#define AML allMemberList
	#define LL loserList
	#define WL winnerList
	
	size = 0;	head = '\0';
	
	if(*losers > 0) // KAYBEDEN VARSA
	{
		for(int a = 0  ; a < *losers ; a++) // KAYBEDENLERÝ LÝNKED LÝSTLERDEN SÝLME
			LL[a] = '\0';
	}
	
		
	if(*winners > 0) // KAZANAN VARSA
	{
		for(int a =  0 ; a < *winners ; a++) // SADECE ÇOKLU ZARLARDAN YENENLERE TEKRARDAN BÝR LÝNKED LÝST OLUÞTURMA
		{	
			Node *n2;
			
			if(WL[a]->mNickName2 == 0) // ÖZEL ZAR ÝSE 
				n2 = new Node(WL[a]->mNickName, 0, WL[a]->mHeight, WL[a]->mWidth, WL[a]-> mDepth);
			
			else // ÇOKLU GÝRÝLMÝÞ ZAR ÝSE
				n2 = new Node("404", WL[a]->mNickName2 , WL[a]->mHeight, WL[a]->mWidth, WL[a]-> mDepth);

			n2->back = head;
			head = n2;
			size++;		
		}	
	}		
}

void Dice::digit(size_t startStep, int *loserWinner) const // BASAMAK DEÐERÝ KADAR BOÞLUK ATTIRTMA
{
	#define LW loserWinner
	#define SS startStep

	if(*LW/10 < 1) // TEK BASAMAKLI ÝSE
		space(SS);
	else if(*LW/10 >= 1 && *LW/10 < 10)	 // 2 basamaklý ise
		space(SS-1); 
	else if(*LW/10 >= 10 && *LW/10 < 100) // 3 basamaklý ise
		space(SS-2);
	else if(*LW/10 >= 100 && *LW/10 < 1000) // 4 basamaklý ise
		space(SS-3);
	else if(*LW/10 >= 1000 && *LW/10 < 10000) // 5 basamaklý ise
		space(SS-4);
	else if(*LW/10 >= 10000 && *LW/10 < 100000) // 6 basamaklý ise
		space(SS-5);
	else if(*LW/10 >= 100000 && *LW/10 < 1000000) // 7 basamaklý ise
		space(SS-6);
}

void Dice::successfulProcess() const // BAÞARILI ÝÞLEM MESAJI GÖNDERME
{
	#define S Sleep
	#define C cout<<
	
	cls();
	if(size >= 10)
	{
		C"ÝÞLEMÝNÝZ BAÞARIYLA GERÇEKLEÞTÝ! ANA SAYFAYA YÖNLENDÝRÝLÝYORSUNUZ";	S(300); C"."; S(250);  C".";  S(250);  C".";  S(550);
	}	
}

void Dice::returnMenu() // ZAR ÝÞLEMLERÝ MENÜSÜNE DÖNME
{
	cout<<"ANA MENÜYE DÖNMEK ÝÇÝN HERHANGÝ BÝR HARF GÝRÝNÝZ: ";
	string *temp = new string;
	cin>>*temp;
	
	delete temp; 	cls(); 	gameMenu();
}

void Dice::resume() // DEVAM ETTÝRMEK ÝÇÝN 1 TUÞ GÝRDÝRTME
{
	cout<<"DEVAM ETMEK ÝÇÝN  HERHANGÝ BÝR HARF GÝRÝNÝZ: ";
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
		Dice *t = new Dice(9.99); //SADECE DEÐÝÞKENÝ KULLANABÝLMEK ÝÇÝN BUNU BÖYLE TANIMLADIM
		
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
// ÝNHERÝT CLASSES


