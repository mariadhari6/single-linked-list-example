#include "fungsi.cpp"
    string Nim, Nama, Jurusan, Prodi, Alamat, Nim1;
    int Semester, i;
    float ips[8], ipk=0;
    bool status;
void AmbilNIM(){
    cout<<"NIM      : ";
    cin>>Nim;
}
void Update(){
    ipk=0;
    Nama=InputNama();
    Jurusan=InputJurusan();
    Prodi=InputProdi();
    Alamat=InputAlamat();
    Semester=InputSemester();
    for(i=0; i<Semester; i++){
        ips[i]=InputIps(i);
    }
    for(i=0; i<Semester; i++){
        ipk=ipk+ips[i];
    }
    ipk=ipk/Semester;
    cout<<"IPK      : "<<ipk<<endl;
}
void Tambah_data(){
    ipk=0;
    Nim=InputNIM(Data);
    Nama=InputNama();
    Jurusan=InputJurusan();
    Prodi=InputProdi();
    Alamat=InputAlamat();
    Semester=InputSemester();
    for(i=0; i<Semester; i++){
        ips[i]=InputIps(i);
    }
    for(i=0; i<Semester; i++){
        ipk=ipk+ips[i];
    }
    ipk=ipk/Semester;
    cout<<"IPK      : "<<ipk<<endl;
}
int main(){   
    Buat_data(&Data);
    int dipilih;
    memori p;
    while(true){
        dipilih=Pilihan();
        if(dipilih==1){
            system("clear");
            Tampilkan_data(Data);
        }
        else if(dipilih==2){
            system("clear");
            Tambah_data(); 
            p=Alokasi(Nim, Nama, Jurusan, Prodi, Alamat, Semester, ipk);
            Tambah_awal(&Data, p);
        }
        else if(dipilih==3){
            system("clear");
            Tambah_data();
            p=Alokasi(Nim, Nama, Jurusan, Prodi, Alamat, Semester, ipk);
            if(Data.mulai==NULL){
                Tambah_awal(&Data, p);
                cin.get();
                system("clear");
                continue;
            }
            Tambah_akhir(&Data, p);
        }
        else if(dipilih==4){
            system("clear");
            AmbilNIM();
            Delete_data(Nim);
        }
        else if(dipilih==5){
            system("clear");
            AmbilNIM();
            Cari_data(Nim);
        }
        else if(dipilih==6){
            system("clear");
            Hitung_data();
        }
        else if(dipilih==7){
            system("clear");
            cout<<"NIM Tujuan  : ";
            cin>>Nim1;
            status=TestNim(Data, Nim1);
            if(status==true){
                cout<<"NIM Tidak Ditmukan !!!\n";
                continue;
            }
            Tambah_data(); 
            p=Alokasi(Nim, Nama, Jurusan, Prodi, Alamat, Semester, ipk);
            Tambah_setelah(&Data, p, Nim1);
        }
        else if(dipilih==8){
            system("clear");
            cout<<"NIM Tujuan  : ";
            cin>>Nim;
            status=TestNim(Data, Nim);
            if(status==true){
                cout<<"NIM Tidak Ditmukan !!!\n";
                continue;
            }
            Update();
            p=Alokasi(Nim, Nama, Jurusan, Prodi, Alamat, Semester, ipk);
            Update_data(&Data, p, Nim);
        }
        else if(dipilih==9){
            system("reset");
            return -1;
        }
        cin.get();
        cin.get();
        system("clear");
    }
    return 0;
}