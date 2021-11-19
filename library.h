#include<iostream>
#include<curses.h>
#include <string>
#if !defined LIBRARY_LINKED_LIST
#define LIBRARY_LINKED_LIST
using namespace std;

struct mhs{
    string NIM, nama, jurusan, prodi, alamat;
    int semester;
    float IPK;
};
typedef struct elemen *memori;
struct elemen
{
    mhs info;
    memori next;
    /* data */
};
struct linked_list
{
    memori mulai;
    /* data */
};
string dataMhs;
linked_list Data;
string InputNIM(linked_list l);
string InputNama();
string InputJurusan();
string InputProdi();
string InputAlamat();
int InputSemester();
float InputIps(int sms);
void Buat_data(linked_list *Data);
int Pilihan();
void Tampilkan_data(linked_list l);
bool CekNim(linked_list l);
memori Alokasi(string Nim, 
               string Nama, string Jurusan, string Prodi, 
               string Alamat, int Semester, float ipk);
void Tambah_awal(linked_list *l, memori data_list);
void Tambah_akhir(linked_list *l, memori data_list);
void Tambah_data();
void Delete_data(string Nim);
void Cari_data(string Nim);
void Hitung_data();
void Tambah_setelah(linked_list *l, memori data_list, string Nim1);
bool TestNim(linked_list l, string Nim1);
void Update_data(linked_list *l, memori data_list, string Nim1);
#endif