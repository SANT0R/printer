#include <iostream>
#include <fstream>
#include <windows.h>


using namespace std;
struct date{
    int yil=1997,gun=17,ay=6,saat=00,dakika=01,saniye=35;
};

struct kisi{
    string ad="Mehmet",soyad="Santor",kullanici_adi="Sant0r",eposta="santorm555@gmail.com";
    date dogum_tarihi;
};

struct node{
    string name;
    long boyut=1;
    int copyy=1,sayfa=(boyut/4234)+1;
    kisi sahip;
};


int main(){
    int m_kapasite=20,kapasite=0,basma_hizi=6,toplam=-1,islem;
    node liste[m_kapasite+1];
    do{
        cout<< "1.Belge ekle(max kapasite:" <<m_kapasite<<")"<<endl
            << "2.Belge yazdir" <<endl
            << "3.Belge sil" <<endl
            << "4.Kuyrugu goster"<<endl
            << "0.Programi sonlandir" <<endl<<endl;
        cout<<"Isleminiz: ";  cin>>islem; cout<<endl;

        switch(islem){
            case 1:{
                system("cls");
                kapasite++;
                if(kapasite>m_kapasite){
                    cout<<"Bellek dolu."<<endl;     kapasite--;     break;
                }
                else{
                    toplam++;
                    cout<<"Belge adi(uzantisi ile): ";    cin>>liste[toplam].name;   cout<<endl;
                    fstream read_f;     read_f.open(liste[toplam].name.c_str(),ios::in|ios::binary);
                    if(read_f.is_open()){
                        cout<<"Kopya sayisi: ";    cin>>liste[toplam].copyy;     cout<<endl;
                        int sec=0;  string str;
                        while(!read_f.eof()){
                            read_f>>str;
                            liste[toplam].boyut+=(str.size()+1);
                        }
                        do{
                            system("cls");
                            cout<<"Kisi bilgisi girilecek mi?(1.EVET/2.HAYIR) :";    cin>>sec; cout<<endl;
                            if(sec==1){
                                cout<<"Ad :";                    cin>>liste[toplam].sahip.ad;                    cout<<endl;
                                cout<<"Soyad :";                 cin>>liste[toplam].sahip.soyad;                 cout<<endl;
                                cout<<"Kullanici adi :";         cin>>liste[toplam].sahip.kullanici_adi;         cout<<endl;
                                cout<<"Eposta :";                cin>>liste[toplam].sahip.eposta;                cout<<endl;
                                cout<<"Dogum tarihi::Yil :";     cin>>liste[toplam].sahip.dogum_tarihi.yil;      cout<<"/";
                                cout<<"Ay :";                    cin>>liste[toplam].sahip.dogum_tarihi.ay;       cout<<"/";
                                cout<<"Gun :";                   cin>>liste[toplam].sahip.dogum_tarihi.gun;      cout<<"     ";
                                cout<<"Saat :";                  cin>>liste[toplam].sahip.dogum_tarihi.saat;     cout<<".";
                                cout<<"Dakika :";                cin>>liste[toplam].sahip.dogum_tarihi.dakika;   cout<<".";
                                cout<<"Saniye :";                cin>>liste[toplam].sahip.dogum_tarihi.saniye;   cout<<endl;
                                break;

                            }
                            else if((sec!=1)&&(sec!=2)){
                                cout<<"Hatali seçim"<<endl;
                            }
                        }while(sec!=2);
                        do{
                            system("cls");
                            cout<<"Oncelik taninsin mi?(1.EVET/2.HAYIR) :";    cin>>sec; cout<<endl;
                            if(sec==1){
                                for(int i=toplam;i>=0;i--){
                                    liste[i+1]=liste[i];
                                }
                                liste[0]=liste[toplam+1];
                                break;
                            }
                            else if((sec!=1)&&(sec!=2)){
                                cout<<"Hatali seçim"<<endl;
                            }
                        }while(sec!=2);
                    }
                    else
                        {cout<<"Dosya bulunamadi."<<endl;    toplam--;}

                    read_f.close();
                }
            }
            break;

            case 2:{
                system("cls");
                if(toplam==-1){
                    cout<<"Liste bos"<<endl<<endl;
                }
                else{
                    fstream read_f;     read_f.open(liste[0].name.c_str(),ios::in);
                    if(read_f.is_open()){
                        string line;
                        for(int i=0;i<liste[0].copyy;i++){
                            Sleep(liste[0].sayfa*basma_hizi*1000);
                            while (getline(read_f,line)){
                                cout << line << endl;
                            }
                                read_f.close();
                                read_f.open(liste[0].name.c_str(),ios::in);
                        }
                        for(int i=0;i<toplam;i++){
                        liste[i]=liste[i+1];
                        }
                        toplam--;
                        read_f.close();
                    }
                    else    {cout<<"Dosya bulunamadi."<<endl;}
                }
            }
            break;

            case 3:{
                system("cls");
                string dlt;
                cout<<"Belge adi(uzantisi ile): ";    cin>>dlt;       cout<<endl;
                for(int i=0;i<=toplam;i++){
                    if(liste[i].name==dlt){
                        for(int j=1;(i+j)<=toplam;j++){
                            liste[i]=liste[i+j];
                        }
                    }
                }
                toplam--;
            }
            break;

            case 4:{
                system("cls");
                if(toplam!=-1){
                    for(int i=0;i<=toplam;i++){
                        cout<<liste[i].name<<"      "<<liste[i].copyy<<"      "<<liste[i].boyut<<"      "<<liste[i].sayfa
                            <<"      "<<liste[i].sahip.ad<<"      "<<liste[i].sahip.soyad<<"      "<<liste[i].sahip.kullanici_adi
                            <<"      "<<liste[i].sahip.eposta<<"      "<<liste[i].sahip.dogum_tarihi.gun
                            <<"/"<<liste[i].sahip.dogum_tarihi.ay<<"/"<<liste[i].sahip.dogum_tarihi.yil
                            <<"   "<<liste[i].sahip.dogum_tarihi.saat<<"."<<liste[i].sahip.dogum_tarihi.dakika
                            <<"."<<liste[i].sahip.dogum_tarihi.saniye<<endl;
                    }
                }
                else    cout<<"Liste bos"<<endl<<endl;
            }
            break;

            case 0:
                system("cls");
            break;

            default:{
                system("cls");
                cout<<"Hatali islem, tekrar deneyiniz."<<endl;
                }
            break;

        }
    }while(islem!=0);
    return 0;
}
