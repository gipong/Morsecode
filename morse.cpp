#include<stdio.h>
#include<conio.h>
#include<string.h>
#define SIZE 100

void encode(const char *enmorse[], const char *enAph[], const char *enaph[]);
void decode(const char *enmorse[], const char *enAph[], const char *enaph[]);


int main()
{
    const char *morse[27]={"._","_...","___.","_..",".",".._.","__.","....","..",".___","_._","._..","____","_.","___",".__.","__._","._.","...","_",".._","..._",".__","_.._","_.__","__..","..__"};
    const char *Aph[27]={"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"," "};
    const char *aph[27]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"," "};
    char string[SIZE];
	int s;
	/*先設立三個陣列分別是摩斯密碼陣列、英文字母大寫陣列、英文字母小寫陣列*/

    printf("1. Morse Code Encoding\n2. Morse Code Decoding\nSelect 1 or 2:");			/*兩選項之說明並供使用者選擇*/
	scanf("%d",&s);			/*輸入數字以選擇解碼或加密*/
	gets(string);
	if(s==1)
	    encode(morse, Aph, aph); /*輸入並執行加密*/
	else if(s==2)
		decode(morse, Aph, aph); /*輸入並進行解密*/
	else 
		printf("please key in 1 or 2 , try it again\n");


	printf("程式結束請按任意鍵繼續\n");
    getch();

}


void encode(const char *enmorse[], const char *enAph[], const char *enaph[])
{
    char string[SIZE];
    char c;
	int i;
    int j;
	int s=0;

    printf("Enter the messages then convert to the Morse codes\n"); /*說明這項函式的功能*/
	
	gets(string);
	 /*請使用者輸入出訊息*/

    for(i=0; i<SIZE; i++) {
        for(j=0; j<27; j++) {
	        if((string[i]==*enAph[j])||(string[i]==*enaph[j])) /*做比較以判別是哪個字母*/
		    printf("%s ",enmorse[j]); /*印出摩斯密碼*/
        }
    }

}


void decode(const char *enmorse[],const char *enAph[],const char *enaph[] )
{
    char string[SIZE];
    char *tokenPtr; 
    char s[SIZE];
    int i;

    printf("Enter the Morse codes then convert to the messages\n"); /*說明這項函式的功能*/
    
	gets(string);
    tokenPtr=strtok(string," "); /*利用空白來分段找出各個字串*/
 
    while (tokenPtr!= NULL) {

        for(i=0;i<27;i++) {
            strcmp(tokenPtr,enmorse[i]);
	        if(strcmp(tokenPtr,enmorse[i])==0) /*逐字比較兩字串是否相等若相等則傳回0*/
 	            printf("%s",enaph[i]);
        }
        tokenPtr=strtok(NULL," "); /*利用對strtok的連續呼叫來繼續對string做字符的分割*/
    }

}