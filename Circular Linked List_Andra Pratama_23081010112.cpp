#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
/*
Nama : Andra Pratama
NPM : 23081010112
*/
struct node{
    int data;
    struct node *next;
};
typedef struct node node;

//node *createNode(void);
void tambahAwal(node **pList);
void tambahTengah (node **pList);
void tambahAkhir (node **pList); //fungsi 1
void hapusAwal (node **pList); //fungsi 2
void hapusTengah (node **pList); //fungsi 3
void hapusAkhir (node **pList); //fungsi 4
void tranverse (node *pList);
void cariData (node **pList); //fungsi 5
void jumlahData (node **pList); //fungsi 6
void jumlahNilaiData (node **pList); //fungsi 7

//========================================================

int main(){
    node *pList;
    int pilih;

    pList = NULL;
    do{
        system("cls");
        printf("Daftar Program: \n");
        printf("1. Tambah data di awal list\n");
        printf("2. Tambah data di tengah list\n");
        printf("3. Tambah data di akhir list\n");
        printf("4. Hapus data di awal list\n");
        printf("5. Hapus data di tengah list\n");
        printf("6. Hapus data di akhir list\n");
        printf("7. Cetak isi list\n");
        printf("8. Cari data pada list\n");
        printf("9. Jumlah data pada list\n");
        printf("10. Jumlah nilai data pada list\n");
        printf("MASUKKAN PILIHAN (tekan 0 untuk keluar): ");
        fflush(stdin);
        scanf("%d",&pilih);
        if (pilih == 1)
            tambahAwal(&pList);
        else if(pilih == 2)
            tambahTengah(&pList);
        else if(pilih == 3)
             tambahAkhir(&pList);
        else if(pilih == 4)
             hapusAwal(&pList);
        else if(pilih == 5)
             hapusTengah(&pList);
        else if(pilih == 6)
             hapusAkhir(&pList);
        else if(pilih == 7){
             tranverse(pList);
             getch();
             }
        else if(pilih == 8)
             cariData(&pList);
        else if(pilih == 9)
             jumlahData(&pList);
        else if(pilih == 10)
             jumlahNilaiData(&pList);

    } while (pilih != 0);

    return 0;
}

//========================================================

/*node *createNode(void){
  node *ptr;

  ptr = (node *)malloc(sizeof(node));
  return(ptr);
}*/

//========================================================
/*1. Tambah data di awal list*/
void tambahAwal(node **pList){
    int angka;
    node *pNew, *pCur;

    system("cls");
    fflush(stdin);
    printf("Masukkan bilangan: ");
    scanf("%d", &angka);

    pNew = (node *)malloc(sizeof(node));

    if(pNew != NULL){
        pNew->data = angka;
        if(*pList == NULL){
            *pList = pNew;
            pNew->next = *pList;
        }
        else{
            pCur = *pList;
            while(pCur->next != *pList){
                pCur = pCur->next;
            }
            pCur->next = pNew;
            pNew->next = *pList;
            *pList = pNew;
            }
        }
        else{
            printf("Alokasi memori gagal!");
            getch();
    }
}
//========================================================
/*2. Tambah data di tengah list*/
void tambahTengah(node **pList){
    int pos, angka;
    node *pNew, *pCur;

    system("cls");
    tranverse(*pList);
    printf("\nMasukkan data pada posisi ke: ");
    fflush(stdin);
    scanf("%d", &pos);
    printf("\nMasukkan bilangan yang disisipkan: ");
    fflush(stdin);
    scanf("%d", &angka);

    pCur = *pList;
    pNew = (node *)malloc(sizeof(node));
    //transversing
    int nomor = 1;
    while(nomor < pos-1){
        pCur->next;
        nomor++;
    }

    if(pNew == NULL){
        printf("\nAlokasi memori gagal!");
        getch();
    }
    else{
        pNew->data = angka;
        pNew->next = pCur->next;
        pCur->next = pNew;
        }

}
//========================================================
/*3. Tambah data di akhir list*/
void tambahAkhir (node **pList){
    int angka;
    node *pNew, *pCur;

    system("cls");
    fflush(stdin);
    printf("Masukkan bilangan: ");
    fflush(stdin);
    scanf("%d", &angka);

    pNew = (node *)malloc(sizeof(node));

    if (pNew != NULL){
        pNew->data = angka;
        pNew->next = pNew;

        if(*pList == NULL){
            *pList = pNew;
        }
        else{
            pCur= *pList;
        while (pCur->next != *pList ){
                pCur = pCur->next;
            }
        pCur->next = pNew;
        pNew->next = *pList;
        }
    }
    else{
    printf("\nAlokasi memori gagal!");
    getch();
    }
}
//========================================================
/*4. Hapus data di awal list*/
void hapusAwal(node **pList){
    node *pCur, *pPre;

    if(*pList != NULL){
       pCur = *pList;

       if(pCur->next == *pList){
        *pList = NULL;
       }
       else{
        pPre = *pList;
        while(pPre->next != *pList){
            pPre = pPre->next;
        }
        pPre->next = pCur->next;
        *pList = pCur->next;
       }
       free(pCur);
       printf("\nData awal telah dihapus!");
       getch();
    }
    else{
        printf("\nList kosong!");
        getch();
    }
}
//========================================================
/*5. Hapus data di tengah list*/
void hapusTengah(node **pList){
    int angka;
    node *pCur, *pPre;

    system("cls");
    tranverse(*pList);
    printf("\nHapus nilai data: ");
    fflush(stdin);
    scanf("%d", &angka);

    if (*pList == NULL) {
        printf("\nList kosong!");
        getch();
        return;
    }

    pCur = *pList;
    pPre = NULL;

    if ((*pList)->data == angka) {
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
    } while (pCur != *pList && pCur->data != angka);

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
/*6. Hapus data di akhir list*/
void hapusAkhir(node **pList){
    node *pCur, *pPre;

    if (*pList != NULL) {
        pCur = *pList;

        if (pCur->next == *pList) {
            free(*pList);
            *pList = NULL;
        } else {
            pPre = NULL;
            while (pCur->next != *pList) {
                pPre = pCur;
                pCur = pCur->next;
            }
            pPre->next = *pList;
            free(pCur);
        }

        printf("\nData berhasil dihapus!");
        getch();
    } else {
        printf("\nList kosong!");
        getch();
    }
}
//========================================================
/*7. Cetak isi list*/
void tranverse(node *pList){
    //traverse a linked list
    node *pWalker;

    system("cls");
    pWalker = pList;
    do{
        printf("%d\t", pWalker->data);
        pWalker = pWalker->next;
        printf("->");
    }while(pWalker != pList);
    printf(" <%d>", pWalker->data);
}
//========================================================
/*8. Cari data pada list*/
void cariData(node **pList){
    int target, simpul = 0;
    node *pCur, *pPre;

    system("cls");
    fflush(stdin);
    printf("Masukkan nilai yang dicari: ");
    fflush(stdin);
    scanf("%d", &target);

    if (*pList == NULL) {
        printf("\nList kosong.");
        getch();
        return;
    }

    pCur = *pList;
    do {
        if (pCur->data == target) {
            printf("\nData %d ditemukan pada simpul ke-%d", target, simpul + 1);
            getch();
            return;
        }
        pCur = pCur->next;
        simpul++;
    } while (pCur != *pList);

    printf("\nData tidak ditemukan.");
    getch();
}
//========================================================
/*9. Jumlah data pada list*/
void jumlahData(node **pList){
    int hitung = 0;
    node *pCur;

    if (*pList == NULL) {
        system("cls");
        printf("List kosong");
        getch();
        return;
    }

    pCur = *pList;
    do {
        hitung++;
        pCur = pCur->next;
    } while (pCur != *pList);

    printf("\nJumlah data pada list ada %d", hitung);
    getch();
}
//========================================================
/*10. Jumlah nilai data pada list*/
void jumlahNilaiData(node **pList){
    int hasil;
    node *pCur;

    if (*pList == NULL) {
        system("cls");
        printf("List kosong.");
        getch();
        return;
    }

    pCur = *pList;
    do {
        hasil += pCur->data;
        pCur = pCur->next;
    } while (pCur != *pList);

    printf("\nJumlah nilai data pada list: %d", hasil);
    getch();
}
