#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node{
    int data;
    struct node *right;
    struct node *left;
};
typedef struct node node;

//node *createnode(void);
void tambahAwal(node **head);
void tambahTengah (node **head);
void tambahAkhir (node **head); //fungsi 1
void hapusAwal (node **head); //fungsi 2
void hapusTengah (node **head); //fungsi 3
void hapusAkhir (node **head); //fungsi 4
void tranverse (node *head);
void cariData (node **head); //fungsi 5
void jumlahData (node **head); //fungsi 6
void jumlahNilaiData (node **head); //fungsi 7

//========================================================

int main(){
    node *head;
    int pilih;

    head = NULL;
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
            tambahAwal(&head);
        else if(pilih == 2)
            tambahTengah(&head);
        else if(pilih == 3)
             tambahAkhir(&head);
        else if(pilih == 4)
             hapusAwal(&head);
        else if(pilih == 5)
             hapusTengah(&head);
        else if(pilih == 6)
             hapusAkhir(&head);
        else if(pilih == 7){
             tranverse(head);
             getch();
             }
        else if(pilih == 8)
             cariData(&head);
        else if(pilih == 9)
             jumlahData(&head);
        else if(pilih == 10)
             jumlahNilaiData(&head);

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
void tambahAwal(node **head){
    int angka;
    node *pNew;

    system("cls");
    fflush(stdin);
    printf("Masukkan bilangan: ");
    fflush(stdin);
    scanf("%d", &angka);

    pNew = (node *)malloc(sizeof(node));

    if(pNew != NULL){
        pNew->data = angka;
        if(*head == NULL){
            *head = pNew;
            pNew->right = NULL;
            pNew->left = NULL;
        }
        else{
            pNew->right = *head;
            pNew->left = NULL;
            *head = pNew;
        }
    }
    else{
        printf("\nAlokasi memori gagal.");
        getch();
    }
}

//========================================================
/*2. Tambah data di tengah list*/
void tambahTengah(node **head){
    int pos, angka;
    node *pNew, *pCur;

    system("cls");
    tranverse(*head);
    printf("\nposisi penyisipan data setelah posisi: ");
    fflush(stdin);
    scanf("%d", &pos);
    printf("\nMasukkan bilangan yang disisipkan: ");
    fflush(stdin);
    scanf("%d", &angka);

    pNew = (node *)malloc(sizeof(node));

    if(pNew != NULL){
        if(pCur == NULL){
            printf("/nNode tidak ditemukan!");
            getch();
        }
        else{
            pCur = *head;
            while(pCur->right != NULL && pCur->data != pos){
                pCur = pCur->right;
            }
            pNew->data = angka;
            pNew->right = NULL;
            pNew->left = NULL;
            pNew->left = pCur;
            pNew->right = pCur->right;
            pCur->right->left = pNew;
            pCur->right = pNew;
        }
    }
    else{
        printf("\nAlokasi memori gagal.");
        getch();
    }

}
//========================================================
/*3. Tambah data di akhir list*/
void tambahAkhir(node **head){
    int angka;
    node *pNew, *pCur;

    system("cls");
    fflush(stdin);
    printf("Masukkan bilangan: ");
    fflush(stdin);
    scanf("%d", &angka);

    pNew = (node *)malloc(sizeof(node));

    if(pNew != NULL){
        pNew->data = angka;

        if(*head == NULL){
            pNew->right = NULL;
            *head = pNew;
        }
        else{
            pCur = *head;
            while(pCur->right != NULL){
                pCur = pCur->right;
            }
            pNew->left = pCur;
            pNew->right = NULL;
            pCur->right = pNew;
        }
    }
    else{
        printf("\nAlokasi memori gagal.");
        getch();
    }
}
//========================================================
/*4. Hapus data di awal list*/
void hapusAwal(node **head){
    node *pCur;

    if(*head != NULL){
        pCur = *head;
        *head = (*head)->right;
        (*head)->right->left = NULL;
        free(pCur);
        printf("\nData berhasil dihapus!");
        getch();
    }
    else{
        printf("\nList kosong.");
        getch();
    }

}
//========================================================
/*5. Hapus data di tengah list*/
void hapusTengah (node **head){
    int angka;
    node *pCur, *pPre;

    system("cls");
    tranverse(*head);
    fflush(stdin);
    printf("\nHapus nilai data: ");
    fflush(stdin);
    scanf("%d", &angka);

    if(*head != NULL){
        pCur = *head;
        pPre = NULL;

        while(pCur != NULL && pCur->data != angka){
            pPre = pCur;
            pCur = pCur->right;
        }

        if(pCur == NULL){
            printf("\nData tidak ditemukan!");
            getch();
            return;
        }

        if(pCur == *head){
            *head = pCur->right;
            if(*head != NULL){
                (*head)->left = NULL;
            }
        }
        else{
            if(pCur->right != NULL){
                pCur->right->left = pPre;
            }
            pPre->right = pCur->right;
        }
        free(pCur);
        printf("\nData berhasil dihapus!");
        getch();
    }
    else{
        printf("\nList kosong.");
        getch();
    }
}
//========================================================
/*6. Hapus data di akhir list*/
void hapusAkhir(node **head){
    node *pCur, *pPre;

    pCur = *head;
    pPre = NULL;

    if(*head != NULL){
        while(pCur->right != NULL){
            pPre = pCur;
            pCur = pCur->right;
        }
        if(pPre == NULL){
            *head = pCur->right;
        }
        else{
            pPre->right = NULL;
        }
        free(pCur);
        printf("\nData berhasil dihapus!");
        getch();
    }
    else{
        printf("\nList kosong.");
        getch();
    }
}
//========================================================
/*7. Cetak isi list*/
void tranverse(node *head){
    //traverse a linked list
    node *pWalker;

    system("cls");
    pWalker = head;
    while(pWalker != NULL){
        printf("%d", pWalker->data);
        pWalker = pWalker->right;
        printf(" <-> ");
    }
    printf("NULL");
}
//========================================================
/*8. Cari data pada list*/
void cariData(node **head){
    int target, simpul = 0;
    node *pCur, *pPre;

    system("cls");
    tranverse(*head);
    fflush(stdin);
    printf("\nMasukkan nilai yang dicari: ");
    fflush(stdin);
    scanf("%d", &target);

    pCur = *head;
    pPre = pCur;

    while(pCur != NULL){
        if(pCur->data == target){
            printf("\nData %d ditemukan pada simpul ke-%d", target, simpul+1);
        }
        else{
            printf("\nNilai yang dicari tidak ada, coba ulangi.");
            break;
        }
        pCur = pCur->right;
        simpul++;
    }

    if(*head == NULL){
        printf("\nData tidak ditemukan!");
        getch();
        return;
    }
    getch();
}
//========================================================
/*9. Jumlah data pada list*/
void jumlahData(node **head){
    int hitung = 0;
    node *pCur;

    pCur = *head;
    while(pCur != NULL){
        hitung ++;
        pCur = pCur->right;
    }
    printf("\nJumlah data pada list ada %d", hitung);

    if(*head == NULL){
        system("cls");
        fflush(stdin);
        printf("\nlist kosong.");
        getch();
        return;
    }
    getch();

}
//========================================================
/*10. Jumlah nilai data pada list*/
void jumlahNilaiData(node **head){
    int hasil;
    node *pCur;

    if(*head != NULL){
        pCur = *head;
        while(pCur != NULL){
            hasil += pCur->data;
            pCur = pCur->right;
        }
        printf("\nJumlah nilai data pada list adalah %d", hasil);
    }
    else{
        system("cls");
        fflush(stdin);
        printf("List kosong.");
        getch();
    }
    getch();
}
