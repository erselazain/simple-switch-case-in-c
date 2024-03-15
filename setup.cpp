#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

	//deklarasi variabel
	int pilih, jumlah[100], sub_total[100], total_bayar, i=1, j=1;
	string unik[100], menu[100], num[100], bill[100];
	int no[100],kode[100], harga[100], pesan[100], index=1;
	char cont = 'y'; bool selesai=false;

//fungsi menampilkan semua menu
void allmenu()
{
	cout << left << setw(10) << "No";
	cout << left << setw(50) << "Menu";
	cout << left << setw(20) << "Harga" << endl;

	for (int i = 1 ; i <= index ; i++)
	{
		cout << left << setw(10) << no[i];
		cout << left << setw(50) << menu[i];
		cout << left << setw(1) << "Rp " << harga[i] << endl;
	}	
}		

//fungsi menampilkan kelompok menu
void submenu()
{
	bool found = 0;
	cout << left << setw(10) << "No";
	cout << left << setw(50) << "Menu";
	cout << left << setw(20) << "Harga" << endl;
	for (int i = 1 ; i <= index ; i++)
	{
		if ( pilih == kode[i] )
		{
			cout << left << setw(10) << no[i];
			cout << left << setw(50) << menu[i];
			cout << left << setw(1) << "Rp " << harga[i] << endl;
			found = 1;
		}
	}
	if ( found == 0 )
	{
		cout<<endl;
		cout<< "Masukan Tidak Sesuai" << endl;
	}
}

//fungsi daftar menu
void listmenu()
{
	while ( cont == 'y' )
	{   cout<<endl;
		cout<<"*********DAFTAR MENU RICHEESE FACTORY***********"<<endl;
    	cout<<"-------------------------------------------------"<<endl;
    	cout<<"Pilihan (1) Menu Ala Carte"<<endl;
    	cout<<"Pilihan (2) Menu Truffle Madness"<<endl;
    	cout<<"Pilihan (3) Menu Combo Special"<<endl;
    	cout<<"Pilihan (4) Menu Combo Favorit"<<endl;
    	cout<<"Pilihan (5) Menu Combo Kids Meal"<<endl;
    	cout<<"Pilihan (6) Menu Rich Burger"<<endl;
    	cout<<"Pilihan (7) Menu Side Dish & Dessert"<<endl;
    	cout<<"Pilihan (8) Menu Minuman"<<endl;
    	cout<<"Pilihan (9) Lihat semua menu"<<endl<<endl;
    	cout<<"Lihat Menu : "; cin>>pilih; cout<<endl;
    	
   		if (pilih==0)
		{
   			selesai=true;
		}
		else if (pilih<=9)
		{
			switch (pilih)
			{
		   		case 1 : submenu(); break;
		  		case 2 : submenu(); break;
		  		case 3 : submenu(); break;
		   		case 4 : submenu(); break;
		   		case 5 : submenu(); break;
		   		case 6 : submenu(); break;
		   		case 7 : submenu(); break;
		    	case 8 : submenu(); break;
		   		case 9 : allmenu(); break;
			}		
		}
		else
		{	
			cout<<endl;
			cout<<"Menu yang dipilih tidak sesuai"<<endl;
		}
		cout<<endl;
		cout << "Lihat Menu Lainnya ? (y/n) :"; cin >> cont;
	}
}

//fungsi pembelian
void purchase()
{
	while(cont=='y')
	{
	cout<<endl;
   	cout<<"Pesan Nomor Berapa : ";
   	cin>>pesan[j];
   		for (int i = 1 ; i <= index ; i++)
		{
   		 	if (pesan[j]==no[i])
			{
				cout<<endl;
				cout<<"Untuk Berapa Orang ("<<menu[i]<<") : ";
	    		cin>>jumlah[j]; 
					    	
			   	sub_total[j]=jumlah[j]*harga[i];  	
			   	total_bayar+=sub_total[j];
			   	
			   	cout<<endl;
				cout<<" Menu   : "   << menu[i] <<endl;
				cout<<" Harga  : Rp "<<harga[i]<<endl;
				cout<<" Jumlah : "   <<jumlah[j]<<endl;
				cout<<" Total  : Rp "<<sub_total[j]<<endl;
			}
		}
		cout<<endl;
		cout<< "Lanjutkan Pesanan ? (y/n) :"; cin >> cont;
	}
	cout<<endl;
	cout<<"Total Bayar Anda Adalah = Rp."<<total_bayar<<endl;
}

int main()
{
	//input data
	ifstream infile; infile.open ("daftar-menu.csv");

	while(!infile.eof())
	{
		//mengambil data dari csv
	    getline(infile, num[index], ',');
	    getline(infile, unik[index], ',' );
	    getline(infile, menu[index], ',' );
	    getline(infile, bill[index]);
	    
	    //konversi data string no, kode, harga ke int no, kode, harga
		istringstream(num[index]) >> no[index];
		istringstream(unik[index]) >> kode[index];
		istringstream(bill[index]) >> harga[index];
	    index++;
	}
	index--; infile.close();
	
	while ( cont == 'y' )
	{
		//tampilan awal program
		cout<<endl;
		cout<<"*********SELAMAT DATANG DI RICHEESE FACTORY***********"<<endl;
    	cout<<"------------------------------------------------------"<<endl;
    	cout<<"Pilihan (1) Daftar Menu Kami"<<endl;
    	cout<<"Pilihan (2) Ajukan Pesanan Anda"<<endl;
    	
    	cout<<endl;
		cout<<"Silahkan Masukkan Pilihan Anda : "; cin>>pilih;
    	
   		if (pilih==0)
		{
   			selesai=true;
		}
		else if (pilih<=2)
		{
			switch (pilih)
			{
		   		case 1 : listmenu(); break;
		  		case 2 : purchase(); break;
			}		
		}
		else
		{
			cout<<endl;
			cout<<"Perintah yang dipilih tidak sesuai"<<endl;
		}
		cout<<endl;
		cout << "Kembali Ke Awal ? (y/n) :"; cin >> cont;
	}
}
