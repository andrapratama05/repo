#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct Mahasiswa{
    char nama[50];
    char jenisKelamin;
    struct Mahasiswa *next;
    struct Mahasiswa *prev;
};
typedef struct Mahasiswa Mhs;

//========================================================
void tambahMhs(Mhs **pList);
void MhsKeluar (Mhs **List);
void TampilkanAnggota (Mhs *pList);
void bagiLingkaran (Mhs **pList);
//========================================================

int main(){
    Mhs *pList;
    char pilihan;
    int isipList = 0;

    pList = NULL;
    do{
        isipList++;
    }while(pList != NULL);

    if(isipList > 20){
        printf("isi Lingkaran maksimal adalah 20 mahasiswa/i");
        return;
    }

    do{
       system("cls");
       printf("masukkan pilihan\n");
       printf("1. Tambah data Mahasiswa/i\n");
       printf("2. Mahasiswa/i keluar lingkaran\n");
       printf("3. Tampilkan isi lingkaran\n");
       printf("4. pisahkan menjadi 2 lingkaran \n");
       printf("MASUKKAN PILIHAN (tekan q untuk keluar) : ");
       fflush(stdin);
       fgets(pilihan, sizeof(pilihan), stdin);

       if (pilih == "1")
     	tambahMhs(&pList);
      else if (pilih == "2")
         MhsKeluar(&pList);
      else if (pilih == "3"){
      TampilkanAnggota(pList);
      getch();
      }
      else if (pilih == "4")
         pisahLingkaran(&pList);
  } while (pilih != "q");

    return 0;
}

//========================================================
void tambahMhs(Mhs **pList){
    char namaMhs[50];
    char jenisK;
    Mhs *pNew, *pCur;

    system("cls");
    fflush(stdin);
    printf("Masukkan nama mahasiswa/i: ");
    fflush(stdin);
    fgets(namaMhs, sizeof(namaMhs), stdin);

    printf("Masukkan jenis kelamin (P/L): ");
    fflush(stdin);
    scanf(" %c", &jenisK);

    pNew = (Mhs *)malloc(sizeof(Mhs));
    pCur = *pList;

    if(pNew != NULL){
       pNew->nama = namaMhs;
       pNew->jenisKelamin = jenisK;

       if(*pList == NULL){
        *pList = pNew
       }
       else{
        while(pCur->next != *pList){
            pCur = pCur->next;
        }
        pCur->next = pNew;
        pNew->next = *pList;
       }
    }else{
      printf("Alokasi memori gagal");
      getch();
    }

    if(strcmp(namaMhs, "Cindy") == 0){
        pCur = *pList;
        int wanita = 0;
        if(*pList != NULL){
            do{
                if(pCur->jenisKelamin == 'P'){
                    wanita++;
                }
                pCur = pCur->next;
            }
            while(pCur != *pList);
        }
    }
    pCur = *pList;
    pNew->nama = strcmp(namaMhs,"Cindy");

    while(pCur->next->jenisKelamin =='P' && pCur->prev->jenisKelamin !='P'){
            pCur=pCur->next
            break;
            pNew->next = pCur->prev;
            p
        }
    }

    if(wanita < 2){
        printf("Cindy tidak dapat bergabung karena harus ada minimal 2 mahasiswi lain.\n");
        getch();
        return;
    }


    if(strstr(namaMhs, ))
}
//========================================================
void MhsKeluar(Mhs **pList){
    char namaMhs[50];
    node *pCur, *pPre;

    system("cls");
    tranverse(*pList);
    printf("\nMahasiswa yang ingin keluar: ");
    fflush(stdin);
    fgets(namaMhs, sizeof(namaMhs), stdin);

    if (*pList == NULL) {
        printf("\nList kosong!");
        getch();
        return;
    }

    pCur = *pList;
    pPre = NULL;

    if ((*pList)->nama == namaMhs) {
        if ((*pList)->next == *pList) {
            free(*pList);
            *pList = NULL;
        } else {
            pCur = *pList;
            while (pCur->next != *pList) {
                pCur = pCur->next;
            }
            pCur->next = (*pList)->next;
            free(*pList);
            *pList = pCur->next;
        }
        printf("\nData berhasil dihapus.");
        getch();
        return;
    }

    pCur = *pList;
    do {
        pPre = pCur;
        pCur = pCur->next;
    } while (pCur != *pList && pCur->nama!= namaMhs);

    if (pCur == *pList) {
        printf("\nData tidak ditemukan.");
        getch();
        return;
    }

    pPre->next = pCur->next;
    free(pCur);
    printf("\nData berhasil dihapus.");
    getch();
}
//========================================================
void tampilkanAnggota(Mhs *pList){
    node *pWalker;

    system("cls");
    pWalker = pList;
    do{
        printf("%s ->\n", pWalker->nama);
        pWalker = pWalker->next;
    }while(pWalker != pList);
    printf("Kembali ke mahasiswa/i: %s", pWalker->data);
}
//========================================================
void bagiLingkaran(Mhs **pList){

}
