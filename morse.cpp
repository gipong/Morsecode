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
	/*���]�ߤT�Ӱ}�C���O�O�����K�X�}�C�B�^��r���j�g�}�C�B�^��r���p�g�}�C*/

    printf("1. Morse Code Encoding\n2. Morse Code Decoding\nSelect 1 or 2:");			/*��ﶵ�������èѨϥΪ̿��*/
	scanf("%d",&s);			/*��J�Ʀr�H��ܸѽX�Υ[�K*/
	gets(string);
	if(s==1)
	    encode(morse, Aph, aph); /*��J�ð���[�K*/
	else if(s==2)
		decode(morse, Aph, aph); /*��J�öi��ѱK*/
	else 
		printf("please key in 1 or 2 , try it again\n");


	printf("�{�������Ы����N���~��\n");
    getch();

}


void encode(const char *enmorse[], const char *enAph[], const char *enaph[])
{
    char string[SIZE];
    char c;
	int i;
    int j;
	int s=0;

    printf("Enter the messages then convert to the Morse codes\n"); /*�����o���禡���\��*/
	
	gets(string);
	 /*�ШϥΪ̿�J�X�T��*/

    for(i=0; i<SIZE; i++) {
        for(j=0; j<27; j++) {
	        if((string[i]==*enAph[j])||(string[i]==*enaph[j])) /*������H�P�O�O���Ӧr��*/
		    printf("%s ",enmorse[j]); /*�L�X�����K�X*/
        }
    }

}


void decode(const char *enmorse[],const char *enAph[],const char *enaph[] )
{
    char string[SIZE];
    char *tokenPtr; 
    char s[SIZE];
    int i;

    printf("Enter the Morse codes then convert to the messages\n"); /*�����o���禡���\��*/
    
	gets(string);
    tokenPtr=strtok(string," "); /*�Q�ΪťըӤ��q��X�U�Ӧr��*/
 
    while (tokenPtr!= NULL) {

        for(i=0;i<27;i++) {
            strcmp(tokenPtr,enmorse[i]);
	        if(strcmp(tokenPtr,enmorse[i])==0) /*�v�r�����r��O�_�۵��Y�۵��h�Ǧ^0*/
 	            printf("%s",enaph[i]);
        }
        tokenPtr=strtok(NULL," "); /*�Q�ι�strtok���s��I�s���~���string���r�Ū�����*/
    }

}