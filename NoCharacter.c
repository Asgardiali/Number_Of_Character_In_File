#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main(void) {
	FILE *input_ptr, *output_ptr;			//Giriþ ve çýkýþ dosya tanýmlayýcýlarý

	//Dosya adlarý ileride deðiþtirilebilir olmasý için aþaðýdaki gibi tanýmlanmýþtýr.
	char input_Fname[]="girdi.txt";			//Giriþ dosyasý adý
	char output_Fname[]="count.dat";		//Çýkýþ dosyasý adý
	int harf_sayisi[26]={0};				//Dosya içerisindeki harflerin sayýsýný tutmak için tanýmlanmýþ dizi
	int i;									//For döngüsü içersinde döngüyü ilerletmek, harfleri ekrana basmak için
	int karakter;							//Dosyadan fgetc ile okunan degerler int tipinde karakter degiskeninde saklanir

	input_ptr = fopen(input_Fname,"r");		//Giris dosyasýnýn acýlmasý
	if (input_ptr==NULL)					//Dosya acma basarýsýz olur ise, fopen() null pointer döndürür
	{
		printf("%s dosyasý açýlamadý.",input_Fname);
		return 0;
	}
	while (1)								//While icersinde dosyadan karakter okuma islemi yapilir
	{
	karakter=fgetc(input_ptr);				//fgetc ile alýnan karakterler int tipinde bir karaktere ascii decimal karþiliklari ile yazýlýr

	if (karakter == EOF)					//fgetc fonk. dosya sonuna gelinmisse EOF döndürür ve döngüden çýkýlýr.
	break;

	//printf("%c ve %d \n",karakter,karakter);//Text dosyasýndan karakterler doðru alýnýyor mu diye kontrol satýrý
	if(karakter>64 && karakter<91)							//Karakterlerin decimal karþýlýklarý kontrol edilir
	{														//Büyük harf kontolü A-Z --> 65-91 decimal karþiliði
		//printf("Karakter = %c\n",karakter);
		harf_sayisi[karakter-65]=harf_sayisi[karakter-65]+1;//Bulunan karakter alfabede kaçýncý harf ise dizinin o elemanýný 1 artýrýr.
	}
	if(karakter>96 && karakter<123)							//Karakterlerin decimal karþýlýklarý kontrol edilir
	{														//Küçük harf kontolü a-z --> 97-122 decimal karþiliði
		//printf("Karakter = %c\n",karakter);
		harf_sayisi[karakter-97]=harf_sayisi[karakter-97]+1;//Bulunan karakter alfabede kaçýncý harf ise dizinin o elemanýný 1 artýrýr.
	}
	}
	output_ptr = fopen(output_Fname, "w");					// Çýkýþ dosyasý açýlýr
	if (output_ptr==NULL)									// Çýkýþ dosyasý hata kontrolü
	{
		printf("%s dosyasý açýlamadý.",input_Fname);
		return 0;
	}
	printf("Girdi dosya icerisindeki karakter sayilari asagidadir. \n\n");
	fprintf(output_ptr,"Girdi dosya icerisindeki karakter sayilari asagidadir. \n\n"); //Çýkýþ dosyasýna yazma iþlemi yapýlýr
	printf(" Karakter  Sayisi\n");
	fprintf(output_ptr," Karakter  Sayisi\n");
	for (i=0; i<26; i++){									// For döngüsü ile çýkýþ dosyasý içerisine ve ekrana harfler ve sayýlarý yazýlýr
	printf(" %c %9d\n",(i+97), harf_sayisi[i]);				// Ekrana yazma
	fprintf(output_ptr," %c %9d\n",(i+97), harf_sayisi[i]);	// Dosyaya yazma
	}

	fclose(input_ptr);			//Acilan dosyalari kapatma
	fclose(output_ptr);
	getch();
	return EXIT_SUCCESS;
}
