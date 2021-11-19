#include "library.h"
#include <string>
#include<stdlib.h>
void Buat_data(linked_list *Data){
    Data->mulai=NULL;
}

void Tampilkan_data(linked_list l){
    if(l.mulai ==NULL){
        cout<<"Data Kosong !!!\n";
        return;
    }
    int i=1;
    memori a=new elemen;
    a=l.mulai;
    while(a!=NULL){
        cout<<"=====Data Mahasiswa Ke-"<<i<<"====="<<endl;
        cout<<"NIM     = "<<a->info.NIM<<endl;
        cout<<"Nama    = "<<a->info.nama<<endl;
        cout<<"Jurusan = "<<a->info.jurusan<<endl;
        cout<<"Prodi   = "<<a->info.prodi<<endl;
        cout<<"Semester= "<<a->info.semester<<endl;
        cout<<"IPK     = "<<a->info.IPK<<endl;
        a=a->next;
        i++;
    }
}
int Pilihan(){
    int pilih;
    cout<<"1.Tanpilkan Data\n2.Tambah Data Di Awal\n3.Tambah ";
    cout<<"Data Di Akhir\n4.Delete Data\n5.Cari Data\n6.Hitung ";
    cout<<"Jumlah Data\n7.Tambah Data Setelah\n8.Update Data\n9.Keluar Program\n";
    cout<<"  Pilih : ";
    cin>>pilih;
    return pilih;
}
string InputNIM(linked_list l){
    bool cek;
    do{
        cout<<"NIM      : ";
        cin>>dataMhs;
        cek=CekNim(l);
    }while(cek==false);
    return dataMhs;
}
string InputNama(){
    cout<<"Nama     : ";
    cin>>dataMhs;
    return dataMhs;
}
string InputJurusan(){
    cout<<"Jurusan  : ";
    cin>>dataMhs;
    return dataMhs;
}
string InputProdi(){
    cout<<"Prodi    : ";
    cin>>dataMhs;
    return dataMhs;
}
string InputAlamat(){
    cout<<"Alamat   : ";
    cin>>dataMhs;
    return dataMhs;
}
int InputSemester(){
    int sm;
    do{
        cout<<"Semester : ";
        cin>>sm;
    }while(sm>8 || sm<1);
    return sm;
}
float InputIps(int sms){
    float Ips;
    do{
        cout<<"IPS "<<sms+1<<"    : ";
        cin>>Ips;
    }while(Ips<0 || Ips>40.0);
    return Ips;
}
bool CekNim(linked_list l){
    memori a=l.mulai;
    int b;
    while(a!=NULL){
        b=dataMhs.compare(a->info.NIM);
        if(b==0){
            break;
        }
        a=a->next;
    }
    if(b==0){
        return false;
    }
    else{
        return true;
    }
}
bool TestNim(linked_list l, string Nim1){
    memori a=l.mulai;
    int b;
    while(a!=NULL){
        b=Nim1.compare(a->info.NIM);
            if(b==0){
                break;
            }
        a=a->next;
    }
    if(b==0){
        return false;
    }
    else{
        return true;
    }
}
memori Alokasi(string Nim, 
               string Nama, string Jurusan, string Prodi, 
               string Alamat, int Semester, float ipk){

    memori a=new elemen;
    a->info.NIM=Nim;
    a->info.nama=Nama;
    a->info.jurusan=Jurusan;
    a->info.prodi=Prodi;
    a->info.semester=Semester;
    a->info.IPK=ipk;
    a->next=NULL;
    return a;
}
void Tambah_awal(linked_list *l, memori data_list){
    data_list->next=l->mulai;
    l->mulai=data_list;
    data_list=NULL;
}
void Tambah_akhir(linked_list *l, memori data_list){
    memori a=l->mulai;
    while(a->next!=NULL){
        a=a->next;
    }
    a->next=data_list;
    data_list=NULL;
}
void Delete_data(string Nim){
    if(Data.mulai==NULL){
        cout<<"Data Kosong !!!\n";
        return;
    }
    memori wadah;
    if(Data.mulai->info.NIM.compare(Nim)==0){
        wadah=Data.mulai;
        Data.mulai=Data.mulai->next;
        return;
    }
    memori a=Data.mulai;
    while(a->next!=NULL){
        if(a->next->info.NIM.compare(Nim)==0){
            wadah=a->next;
            a->next=wadah->next;
            return;
        }
        a=a->next;
    }
}
void Cari_data(string Nim){
    system("clear");
    if(Data.mulai==NULL){
        cout<<"Data Kosong !!!\n";
        return;
    }
    memori a=Data.mulai;
    while(a!=NULL){
        if(a->info.NIM.compare(Nim)==0){
            cout<<"=====Data Mahasiswa=====\n";
            cout<<"NIM     = "<<a->info.NIM<<endl;
            cout<<"Nama    = "<<a->info.nama<<endl;
            cout<<"Jurusan = "<<a->info.jurusan<<endl;
            cout<<"Prodi   = "<<a->info.prodi<<endl;
            cout<<"Alamat  = "<<a->info.alamat<<endl;
            cout<<"Semester= "<<a->info.semester<<endl;
            cout<<"IPK     = "<<a->info.IPK<<endl;
            return;
        }
        a=a->next;
    }
    cin.get();
    cout<<"Data Tidak Ditemukan !!!\n";
}
void Hitung_data(){
    int jml=0;
    memori a=Data.mulai;
    while(a!=NULL){
        a=a->next;
        jml++;
    }
    cout<<"Jumlah Data Mahasiswa : "<<jml<<endl;
}
void Tambah_setelah(linked_list *l, memori data_list, string Nim1){
    if(l->mulai!=NULL){
        memori a=l->mulai;
        while(a!=NULL){
            if(a->info.NIM.compare(Nim1)==0){
                data_list->next=a->next;
                a->next=data_list;
                return;
            }
            a=a->next;
        }
    }
}
void Update_data(linked_list *l, memori data_list, string Nim1){
    memori a=l->mulai;
    while(a!=NULL){
        if(a->info.NIM.compare(Nim1)==0){
            a->info.nama=data_list->info.nama;
            a->info.jurusan=data_list->info.jurusan;
            a->info.prodi=data_list->info.prodi;
            a->info.alamat=data_list->info.alamat;
            a->info.IPK=data_list->info.IPK;
            return;
        }
        a=a->next;
    }
}