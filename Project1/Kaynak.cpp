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
		cout << "1 - S�PAR�� EKLEME\n" << "2 - S�PAR�� S�LME\n" << "3 - S�PAR��LER� L�STELE\n" << "0 - �IKI�\n";
		cout << "L�tfen se�im yap�n�z:";
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
	cout << "L�tfen se�im yap�n�z:";
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
		cin.ignore(); // �stenilen verileri almadan �nce gelen "\n" karakterini atlamak i�in kullan�l�r.
		cout << "L�tfen sipari� sahibinin ad� giriniz:";
		getline(cin, ad);
		cout << "L�tfen sipari� sahibinin soyad� giriniz:";
		getline(cin, soyad);
		cout << "L�tfen sipari�i giriniz:";
		getline(cin, siparis);
		cout << "L�tfen bedeni 1 ile 10 aras�nda de�erlendirerek giriniz:";
		cin >> beden;

		dosyaYaz << siparisNo << "#" << ad << "#" << soyad << "#" << siparis << "#" << beden << "#" << endl;
		cout << "Sipari� ba�ar�yla eklendi." << endl;
	}
	else
	{
		cout << "Dosya a��lam�yor! L�tfen kodu kontrol edip tekrar deneyiniz." << endl;
	}

	dosyaYaz.close();
}

void SiparisSil()
{
	const int siparisKolon = 5;
	vector<string> siparisBilgileri;
	vector<vector<string>> siparisListesi;
	string satir, sutun, siparisNo;

	cout << "L�tfen silmek istedi�iniz sipari�in sipari� numaras�n� giriniz:";
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
		cout << "Dosya a��lam�yor! L�tfen kodu kontrol edip tekrar deneyiniz." << endl;
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
		cout << "Sipari� ba�ar�yla silindi." << endl;
	}
	else
	{
		cout << "Dosya a��lam�yor! L�tfen kodu kontrol edip tekrar deneyiniz." << endl;
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
		cout << "Dosya a��lam�yor! L�tfen kodu kontrol edip tekrar deneyiniz." << endl;
	}

	dosyaOku.close();
}

void Kadin()
{
	cout << "Kad�n se�ildi." << endl;
	// Kad�n sipari�lerine �zg� i�lemleri burada ger�ekle�tirin
}

void Erkek()
{
	cout << "Erkek se�ildi." << endl;
	// Erkek sipari�lerine �zg� i�lemleri burada ger�ekle�tirin
}

void Cocuk()
{
	cout << "�ocuk se�ildi." << endl;
	// �ocuk sipari�lerine �zg� i�lemleri burada ger�ekle�tirin
}
