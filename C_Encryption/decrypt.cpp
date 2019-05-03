#include <iostream>
#include <fstream>
#include <string>
#include<conio.h>
#include<stdio.h>

using namespace std;

int main()
{
char name[30],target[30],ch,mod,modmult,marker;                             //Declare Variables
int num[100],i,option,flag;

////////////////////// DECRYPTION PROCESS //////////////////////

	cin>>option;

	cout<<"Enter The Path Of A File Name Which Is To Be Decrypted : ";
	cin.get();
	gets(name);

	ifstream fin(name,ios::binary);
	if(!fin) {                                                    //Open The Encryped File In A Binary Mode
		cout<<"Error In Opening Of A File : ";
		return 1;                                                    //Show Error If File Does Not Exist
	}                                                            //Or Any Occurs In Opening Of A File

	cout<<"Enter The New Decrypted File Name : ";
	gets(target);
	
	ofstream fout;
	fout.open(target,ios::binary);                              //Opens The Output File In An Binary Mode
	if(!fout) {	                                             //Show Error If Any Error Occurs In Opening Of A File
  		cout<<"Error In Opening Of A Target File : ";
  		return 1;
 	}

	for(i=0;i<9;i++) {                                         //Same Multiple For Loops For Storing The Numbers
  		num[i]=i;                                                 //In An Array
 	}

	for(i=14;i<31;i++) {
  		num[i-5]=i;                                               //Loops Will Store 100 Numbers
 	}

	for(i=33;i<=68;i++) {                                         //Which Encrypts The Document Also Decrypt It
  		num[i-7]=i;
 	}

	while(fin) {	                                            //Opens The Encryped File
		fin.get(ch);
		flag=0;                                                        //Turn Off Flag
	
	if(ch==EOF)break;

////////////////////// START DECRYPTING CHARACTERS //////////////////////

	for(i=0;i<26;i++) {                                     //Loop For Match The Lowercase Letters
  		if(ch==num[i]) {                                   //If Match Then Put Appropriate Letter
			mod=i+97;                                               //In A OutPut File
			fout<<mod;
			flag=1;break;                                              //Turn On Flag And Exit From This Loop
  		}
 	}

	if (flag==1) continue ;                                        //If Flag Is On Then Continue Outer Loop

	for(i=26;i<52;i++) {
  		if(ch==num[i]) {                                            //Loop For Match The Capital Letters Letters
			mod=i+39;                                                //If Match Then Put Appropriate Letter
			fout<<mod;                                               //In A OutPut File
			flag=1; break ;                                             //Turn On Flag And Exit The Loop
  		}
 	}

	if (flag==1) continue ;                                       //If Flag Is On Then Continue Outer Loop

	for(i=52;i<62;i++) {                                   //Loop For Numerical Numbers
  		if(ch==num[i]) {
			mod=i-4;
			fout<<mod;
			flag=1; break ;
  		}
	}
	
	if (flag==1) continue ;

	if((ch==10)||(ch==13)) {
  		mod=ch;                                             //Condition For Enter Key
  		fout<<mod;
 	}

	if(ch==32)
		fout<<ch;                                             //Condition For Space Key

	if(ch==9)
		fout<<ch;                                             //Condition For Tab Key

	if((ch>=97)&&(ch<=111)) {
  		mod=ch-64;                                          //For Special Symbols
  		fout<<mod;
 	}

	if((ch>=112)&&(ch<=118)) {
  		mod=ch-54;                                         //For Special Symbols
  		fout<<mod;
 	}

	if((ch>=119)&&(ch<=124)) {
  		mod=ch-28;                                         //For Special Symbols
  		fout<<mod;
 	}

	if((ch>=83)&&(ch<=86)) {                                      //For Special Symbols
  		mod=ch+40;
  		fout<<mod;
 	}

////////////////////// STOP ENCRYPTING CHARACTERS //////////////////////

}

fin.close();                                        //Close The Encrypted File
fout.close();                                       //Close Your Original Decrypted File

cout<<"The File Is Being Decrypted............ ";
getch();
return 0;
}

