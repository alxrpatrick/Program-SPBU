#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float pjl(int pil, int pilbbm, char pilihan);
float pbl(int pil, int pilbbm, char pilihan);

struct Pertalite
{
    float penjualan;
    float pembelian;
    struct Pertalite *next1;
};

struct Pertamax
{
    float penjualan;
    float pembelian;
    struct Pertamax *next2;
};

struct Dexlite
{
    float penjualan;
    float pembelian;
    struct Dexlite *next3;
};

struct Pertalite1 *head1 = NULL;
struct Pertalite1 *current1 = NULL;
struct Pertalite1 *head2 = NULL;
struct Pertalite1 *current2 = NULL;
struct Pertalite1 *head3 = NULL;
struct Pertalite1 *current3 = NULL;

int help()
{
	char pilih;
	printf("Tutorial penggunaan program data SPBU\n\nPilihan pertolongan:\na. Menjual\nb. Mengisi ulang\nc. Merekap data\nq. Kembali ke program\nPilihan Anda: ");
	scanf(" %c", &pilih);
	switch (pilih)
	{
		case 'a':
			printf ("Untuk memasukkan data jual, cukup memilih opsi 'jual' pada menu. \nOpsi ini berfungsi untuk memasukan data dalam sekali penjualan.");
			return help();
		case 'b':
			printf ("Untuk memasukkan data pengisian ulang, cukup memilih opsi 'isi ulang' pada menu.");
			return help();
		case 'c':
			printf ("Untuk merekap data, cukup memilih opsi 'rekap data'. Opsi ini menunjukkan hasil transaksi bahan bakar sementara.");
			return help();
		case 'q':
			return main();
	}
}

int main()
{
    int pil, pilbbm;
    char pilihan;
	
	printf("-----------------------------------------------------------------\n");
	printf("\t\t\tPROGRAM SPBU\n");
	printf("-----------------------------------------------------------------\n");
	printf("A. Jual \nB. Isi Ulang \nC. Rekap Data \nH. Bantuan \nQ. Keluar dan Mereset Data\nEntry : ");
    scanf(" %c", &pilihan);
    switch (pilihan)
    {
    	case 'a':
    		printf("Pilih input : \n1. Harga\n2. Liter\nEntry : ");
			scanf("%d", &pil);
			printf("Masukkan jenis BBM :\n1. Pertalite\n2. Pertamax\n3. Dexlite\nEntry : ");
			scanf("%d", &pilbbm);
			if (pilbbm == 1)
			{
			    jualjualptlt(pil, pilbbm, pilihan);
			}
			else if (pilbbm == 2)
			{
			    jualjualptm(pil, pilbbm, pilihan);
			}
			else if (pilbbm == 3)
			{
			    jualjualdex(pil, pilbbm, pilihan);
			}
			else
			{
			    printf("input anda invalid");
			}
			return main();
		case 'b':
			printf("Pilih input : \n1. Harga\n2. Liter\nEntry : ");
			scanf("%d", &pil);
			printf("Masukkan jenis BBM :\n1. Pertalite\n2. Pertamax\n3. Dexlite\nEntry : ");
			scanf("%d", &pilbbm);
			if (pilbbm == 1)
			{
			    belibeliptlt(pil, pilbbm, pilihan);
			}
			else if (pilbbm == 2)
			{
			    belibeliptm(pil, pilbbm, pilihan);
			}
			else if (pilbbm == 3)
			{
			    belibelidex(pil, pilbbm, pilihan);
			}
			else
			{
			    printf("input anda invalid\n");
			}
			return main();
		case 'c':
			printList();
			return main();
		case 'h':
            help();
        case 'q':
            printf("\nProgram telah dihentikan. Terima kasih telah menggunakan program ini.\n");
            return 0;
	}
}

void jualjualptlt(int pil, int pilbbm, char pilihan) 
{
    struct Pertalite *link1 = (struct Pertalite*) malloc(sizeof(struct Pertalite));

	link1->penjualan = pjl(pil, pilbbm, pilihan);

    link1->next1 = head1;
    head1 = link1;
}

void jualjualptm(int pil, int pilbbm, char pilihan) 
{
    struct Pertamax *link2 = (struct Pertamax*) malloc(sizeof(struct Pertamax));

	link2->penjualan = pjl(pil, pilbbm, pilihan);

    link2->next2 = head2;
    head2 = link2;
}

void jualjualdex(int pil, int pilbbm, char pilihan) 
{
    struct Dexlite *link3 = (struct Dexlite*) malloc(sizeof(struct Dexlite));

	link3->penjualan = pjl(pil, pilbbm, pilihan);

    link3->next3 = head3;
    head3 = link3;
}

void belibeliptlt(int pil, int pilbbm, char pilihan) 
{
    struct Pertalite *link1 = (struct Pertalite*) malloc(sizeof(struct Pertalite));

	link1->pembelian = pbl(pil, pilbbm, pilihan);
	
    link1->next1 = head1;
    head1 = link1;
}

void belibeliptm(int pil, int pilbbm, char pilihan) 
{
    struct Pertamax *link2 = (struct Pertamax*) malloc(sizeof(struct Pertamax));

	link2->pembelian = pbl(pil, pilbbm, pilihan);
	
    link2->next2 = head2;
    head2 = link2;
}

void belibelidex(int pil, int pilbbm, char pilihan) 
{
    struct Dexlite *link3 = (struct Dexlite*) malloc(sizeof(struct Dexlite));

	link3->pembelian = pbl(pil, pilbbm, pilihan);
	
    link3->next3 = head3;
    head3 = link3;
}

float pjl(int pil, int pilbbm, char pilihan)
{
	float harjl, litjl,  litjlptlt, litjlptm, litjldex, harjlptlt, harjlptm, harjldex;
	if (pil == 1 && pilbbm == 1 && pilihan == 'a')
	{
		printf("Masukkan harga penjualan : ");
		scanf("%f", &harjl);
		litjlptlt = harjl/7800;
		printf("Terjual %f liter dengan harga %f\n", litjlptlt, harjl);
		return litjlptlt;
	}
	else if (pil == 1 && pilbbm == 2 && pilihan == 'a')
	{
	    printf("Masukkan harga penjualan : ");
	    scanf("%f", &harjl);
	    litjlptm = harjl/9500;
		printf("Terjual %f liter dengan harga %f\n", litjlptm, harjl);
		return litjlptm;
	}
	else if (pil == 1 && pilbbm == 3 && pilihan == 'a')
	{
		printf("Masukkan harga penjualan : ");
		scanf("%f", &harjl);
		litjlptlt = harjl/9000;
		printf("Terjual %f liter dengan harga %f\n", litjldex, harjl);
		return litjldex;
	}
	else if (pil == 2 && pilbbm == 1 && pilihan == 'a')
	{
		printf("Masukkan jumlah liter terjual : ");
		scanf("%f", &litjl);
		harjlptlt = litjl*7800;
		printf("Terjual %f liter dengan harga %f\n", litjl, harjlptlt);
		return harjlptlt;
	}
	else if (pil == 2 && pilbbm == 2 && pilihan == 'a')
	{
		printf("Masukkan jumlah liter terjual : ");
		scanf("%f", &litjl);
		harjlptm = litjl*9500;
		printf("Terjual %f liter dengan harga %f\n", litjl, harjlptm);
		return harjlptm;
	}
	else if (pil == 2 && pilbbm == 1 && pilihan == 'a')
	{
		printf("Masukkan jumlah liter terjual : ");
		scanf("%f", &litjl);
		harjldex = litjl*9000;
		printf("Terjual %f liter dengan harga %f\n", litjl, harjldex);
		return harjldex;
	}
	else
	{
		printf("Input anda tidak valid\n");
	}
}

float pbl(int pil, int pilbbm, char pilihan)
{
	float harbl, litbl, litblptlt, litblptm, litbldex, harblptlt, harblptm, harbldex;
	if (pil == 1 && pilbbm == 1 && pilihan == 'b')
	{
		printf("Masukkan harga pembelian : ");
		scanf("%f", &harbl);
		litblptlt = harbl/7800;
		printf("Terbeli %f liter dengan harga %f\n", litblptlt, harbl);
		return litblptlt;
	}
	else if (pil == 1 && pilbbm == 2 && pilihan == 'b')
	{
		printf("Masukkan harga pembelian : ");
		scanf("%f", &harbl);
		litblptm = harbl/9500;
		printf("Terbeli %f liter dengan harga %f\n", litblptm, harbl);
		return litblptm;
	}
	else if (pil == 1 && pilbbm == 3 && pilihan == 'b')
	{
		printf("Masukkan harga pembelian : ");
		scanf("%f", &harbl);
		litbldex = harbl/9000;
		printf("Terbeli %f liter dengan harga %f\n", litbldex, harbl);
		return litbldex;
	}
	else if (pil == 2 && pilbbm == 1 && pilihan == 'b')
	{
		printf("Masukkan harga pembelian : ");
		scanf("%f", &litbl);
		harblptlt = litbl*7800;
		printf("Terbeli %f liter dengan harga %f\n", litbl, harblptlt);
		return harblptlt;
	}
	else if (pil == 2 && pilbbm == 2 && pilihan == 'b')
	{
		printf("Masukkan harga pembelian : ");
		scanf("%f", &litbl);
		harblptm = litbl*9500;
		printf("Terbeli %f liter dengan harga %f\n", litbl, harblptm);
		return harblptm;
	}
	else if (pil == 2 && pilbbm == 3 && pilihan == 'b')
	{
		printf("Masukkan harga pembelian : ");
		scanf("%f", &litbl);
		harbldex = litbl*9000;
		printf("Terbeli %f liter dengan harga %f\n", litbl, harbldex);
		return harbldex;
	}
	else
	{
		printf("Input anda tidak valid\n");
	}
}

void printList() 
{
    struct Pertalite *ptr1 = head1;
    struct Pertamax *ptr2 = head2;
    struct Dexlite *ptr3 = head3;
    while(ptr1 != NULL) {
        printf("\nTotal penjualan Pertalite : Rp%f\nTotal pembelian Pertalite : Rp%f\n--------------------------------------------------------\n", ptr1->penjualan, ptr1->pembelian);
        ptr1 = ptr1->next1;
    }
    while(ptr2 != NULL) {
        printf("\nTotal penjualan Pertamax : Rp%f\nTotal pembelian Pertamax : Rp%f\n--------------------------------------------------------\n", ptr2->penjualan, ptr2->pembelian);
        ptr2 = ptr2->next2;
    }
    while(ptr3 != NULL) {
        printf("\nTotal penjualan Dexlite : Rp%f\nTotal pembelian Dexlite : Rp%f\n--------------------------------------------------------\n", ptr3->penjualan, ptr3->pembelian);
        ptr3 = ptr3->next3;
    }
}
