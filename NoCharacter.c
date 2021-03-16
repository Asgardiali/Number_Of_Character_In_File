#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main(void) {
	FILE *input_ptr, *output_ptr;			//Giri� ve ��k�� dosya tan�mlay�c�lar�

	//Dosya adlar� ileride de�i�tirilebilir olmas� i�in a�a��daki gibi tan�mlanm��t�r.
	char input_Fname[]="girdi.txt";			//Giri� dosyas� ad�
	char output_Fname[]="count.dat";		//��k�� dosyas� ad�
	int harf_sayisi[26]={0};				//Dosya i�erisindeki harflerin say�s�n� tutmak i�in tan�mlanm�� dizi
	int i;									//For d�ng�s� i�ersinde d�ng�y� ilerletmek, harfleri ekrana basmak i�in
	int karakter;							//Dosyadan fgetc ile okunan degerler int tipinde karakter degiskeninde saklanir

	input_ptr = fopen(input_Fname,"r");		//Giris dosyas�n�n ac�lmas�
	if (input_ptr==NULL)					//Dosya acma basar�s�z olur ise, fopen() null pointer d�nd�r�r
	{
		printf("%s dosyas� a��lamad�.",input_Fname);
		return 0;
	}
	while (1)								//While icersinde dosyadan karakter okuma islemi yapilir
	{
	karakter=fgetc(input_ptr);				//fgetc ile al�nan karakterler int tipinde bir karaktere ascii decimal kar�iliklari ile yaz�l�r

	if (karakter == EOF)					//fgetc fonk. dosya sonuna gelinmisse EOF d�nd�r�r ve d�ng�den ��k�l�r.
	break;

	//printf("%c ve %d \n",karakter,karakter);//Text dosyas�ndan karakterler do�ru al�n�yor mu diye kontrol sat�r�
	if(karakter>64 && karakter<91)							//Karakterlerin decimal kar��l�klar� kontrol edilir
	{														//B�y�k harf kontol� A-Z --> 65-91 decimal kar�ili�i
		//printf("Karakter = %c\n",karakter);
		harf_sayisi[karakter-65]=harf_sayisi[karakter-65]+1;//Bulunan karakter alfabede ka��nc� harf ise dizinin o eleman�n� 1 art�r�r.
	}
	if(karakter>96 && karakter<123)							//Karakterlerin decimal kar��l�klar� kontrol edilir
	{														//K���k harf kontol� a-z --> 97-122 decimal kar�ili�i
		//printf("Karakter = %c\n",karakter);
		harf_sayisi[karakter-97]=harf_sayisi[karakter-97]+1;//Bulunan karakter alfabede ka��nc� harf ise dizinin o eleman�n� 1 art�r�r.
	}
	}
	output_ptr = fopen(output_Fname, "w");					// ��k�� dosyas� a��l�r
	if (output_ptr==NULL)									// ��k�� dosyas� hata kontrol�
	{
		printf("%s dosyas� a��lamad�.",input_Fname);
		return 0;
	}
	printf("Girdi dosya icerisindeki karakter sayilari asagidadir. \n\n");
	fprintf(output_ptr,"Girdi dosya icerisindeki karakter sayilari asagidadir. \n\n"); //��k�� dosyas�na yazma i�lemi yap�l�r
	printf(" Karakter  Sayisi\n");
	fprintf(output_ptr," Karakter  Sayisi\n");
	for (i=0; i<26; i++){									// For d�ng�s� ile ��k�� dosyas� i�erisine ve ekrana harfler ve say�lar� yaz�l�r
	printf(" %c %9d\n",(i+97), harf_sayisi[i]);				// Ekrana yazma
	fprintf(output_ptr," %c %9d\n",(i+97), harf_sayisi[i]);	// Dosyaya yazma
	}

	fclose(input_ptr);			//Acilan dosyalari kapatma
	fclose(output_ptr);
	getch();
	return EXIT_SUCCESS;
}
