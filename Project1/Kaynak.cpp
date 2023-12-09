#include<iostream>
#include<locale>
#include<fstream>
#include <ctime>
#include<sstream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;

void SiparisEkle();
void SiparisSil();
void SiparisleriListele();
void Kadin();
void Erkek();
void Cocuk();

int main()
{
	setlocale(LC_ALL, "Turkish");

	int secim = 0;
	while (true)
	{
		cout << "1 - SÝPARÝÞ EKLEME\n" << "2 - SÝPARÝÞ SÝLME\n" << "3 - SÝPARÝÞLERÝ LÝSTELE\n" << "0 - ÇIKIÞ\n";
		cout << "Lütfen seçim yapýnýz:";
		cin >> secim;

		switch (secim)
		{
		case 0:
			exit(1);
		case 1:
			SiparisEkle();
			break;
		case 2:
			SiparisSil();
			break;
		case 3:
			SiparisleriListele();
			break;
		default:
			break;
		}
	}
	return 0;
}

void SiparisEkle()
{
	string ad, soyad, siparis;
	int siparisNo, beden, cinsiyet;

	cout << "1 - KADIN\n" << "2 - ERKEK\n" << "3 - COCUK\n";
	cout << "Lütfen seçim yapýnýz:";
	cin >> cinsiyet;

	switch (cinsiyet)
	{
	case 1:
		Kadin();
		break;
	case 2:
		Erkek();
		break;
	case 3:
		Cocuk();
		break;
	default:
		break;
	}

	ofstream dosyaYaz("Siparisler.txt", ios::app);
	if (dosyaYaz.is_open())
	{
		srand(time(0));
		siparisNo = rand();
		cin.ignore(); // Ýstenilen verileri almadan önce gelen "\n" karakterini atlamak için kullanýlýr.
		cout << "Lütfen sipariþ sahibinin adý giriniz:";
		getline(cin, ad);
		cout << "Lütfen sipariþ sahibinin soyadý giriniz:";
		getline(cin, soyad);
		cout << "Lütfen sipariþi giriniz:";
		getline(cin, siparis);
		cout << "Lütfen bedeni 1 ile 10 arasýnda deðerlendirerek giriniz:";
		cin >> beden;

		dosyaYaz << siparisNo << "#" << ad << "#" << soyad << "#" << siparis << "#" << beden << "#" << endl;
		cout << "Sipariþ baþarýyla eklendi." << endl;
	}
	else
	{
		cout << "Dosya açýlamýyor! Lütfen kodu kontrol edip tekrar deneyiniz." << endl;
	}

	dosyaYaz.close();
}

void SiparisSil()
{
	const int siparisKolon = 5;
	vector<string> siparisBilgileri;
	vector<vector<string>> siparisListesi;
	string satir, sutun, siparisNo;

	cout << "Lütfen silmek istediðiniz sipariþin sipariþ numarasýný giriniz:";
	cin >> siparisNo;

	ifstream dosyaOku("Siparisler.txt", ios::in);
	if (dosyaOku.is_open())
	{
		while (getline(dosyaOku, satir))
		{
			istringstream ss(satir);
			while (getline(ss, sutun, '#'))
			{
				siparisBilgileri.push_back(sutun);
			}

			if (siparisBilgileri[0] == siparisNo)
			{
				siparisBilgileri.clear();
				continue;
			}
			else
			{
				siparisListesi.push_back(siparisBilgileri);
			}

			siparisBilgileri.clear();
		}
	}
	else
	{
		cout << "Dosya açýlamýyor! Lütfen kodu kontrol edip tekrar deneyiniz." << endl;
	}

	dosyaOku.close();

	ofstream dosyaYaz("Siparisler.txt", ios::out);
	if (dosyaYaz.is_open())
	{
		for (int i = 0; i < siparisListesi.size(); i++)
		{
			for (int j = 0; j < siparisKolon; j++)
			{
				dosyaYaz << siparisListesi[i][j] << "#";
			}
			dosyaYaz << endl;
		}
		cout << "Sipariþ baþarýyla silindi." << endl;
	}
	else
	{
		cout << "Dosya açýlamýyor! Lütfen kodu kontrol edip tekrar deneyiniz." << endl;
	}

	dosyaYaz.close();
}

void SiparisleriListele()
{
	const int siparisKolon = 5;
	int dizi[siparisKolon] = { 20, 10, 10, 20, 5 };
	string satir, sutun;

	ifstream dosyaOku("Siparisler.txt", ios::in);
	if (dosyaOku.is_open())
	{
		cout << left << setw(dizi[0]) << setfill(' ') << "SIPARIS NUMARASI";
		cout << left << setw(dizi[1]) << setfill(' ') << "ADI";
		cout << left << setw(dizi[2]) << setfill(' ') << "SOYADI";
		cout << left << setw(dizi[3]) << setfill(' ') << "SIPARISI";
		cout << left << setw(dizi[4]) << setfill(' ') << "BEDEN" << endl;

		while (getline(dosyaOku, satir))
		{
			istringstream ss(satir);
			int i = 0;

			while (getline(ss, sutun, '#'))
			{
				cout << left << setw(dizi[i]) << setfill(' ') << sutun;
				i++;
			}

			cout << endl;
		}

		cout << endl;
	}
	else
	{
		cout << "Dosya açýlamýyor! Lütfen kodu kontrol edip tekrar deneyiniz." << endl;
	}

	dosyaOku.close();
}

void Kadin()
{
	cout << "Kadýn seçildi." << endl;
	// Kadýn sipariþlerine özgü iþlemleri burada gerçekleþtirin
}

void Erkek()
{
	cout << "Erkek seçildi." << endl;
	// Erkek sipariþlerine özgü iþlemleri burada gerçekleþtirin
}

void Cocuk()
{
	cout << "Çocuk seçildi." << endl;
	// Çocuk sipariþlerine özgü iþlemleri burada gerçekleþtirin
}
