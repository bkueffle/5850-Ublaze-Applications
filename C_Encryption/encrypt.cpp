#include <iostream>
#include <fstream>
#include <string>
#include<conio.h>
#include<stdio.h>

using namespace std;

int main()
{
char name[30],target[30],ch,mod,modmult;                             //Declare Variables
int num[100],i,option;

////////////////////// ENCRYPTION PROCESS //////////////////////

cin>>option; //type "1" then the original file name, "test.txt"

cout<<"Enter The Path Of A File Which Is To Be Encrypted : ";
cin.get();
gets(name);

ifstream fin(name,ios::binary);                              //Open The Input File In A Binary Mode
if(!fin)
 {                                                          //Show Error Occur If File Does Not Exist
  cout<<"Error In Openinig Of A File : ";                 //Or Any Error Occurs
  return 1;
 }

cout<<"Enter The New Encrypted File Name : ";
gets(target);

ofstream fout(target,ios::binary);                         //Open The OutPut File In A Binary Mode
if(!fout)
 {
  cout<<"Error In Opening Of Target File : ";            //Show Error If Any Error Occrs In Opening Of A File
  return 1;
 }

for(i=0;i<9;i++)
 {                                                         //Multiple For Loops For Storing The Numbers
  num[i]=i;                                                //In An Array
 }

for(i=9;i<26;i++)                                         //Loops Will Store 100 Numbers
 {
  num[i]=i+5;                                              //Which Will Encrypt The Contents Of A File
 }

for(i=26;i<=61;i++)                                        //To Avoid The Error Ocuur Caused By The
 {                                                         //Enter Key ,Tab Key & Space Key
  num[i]=i+7;                                              //These Variations In Loops Is Made
 }

for(i=62;i<=87;i++)
 {
  num[i]=i+35;
 }

while(fin)
{                                                       //Open The Input File
fin.get(ch);

if(ch==EOF)break;                                       //Exit To Loop When End Of File


////////////////////// START ENCRYPTING CHARACTERS //////////////////////

if(ch==9)
fout<<ch;                                             //For Tab Key

if((ch==10)||(ch==13))
 {
  mod=ch;                                             //For Enter Key
  fout<<mod;
 }

if(ch==32)
	fout<<ch;                                             //For Space Key

if((ch>=33)&&(ch<=47))
 {                                                    //For Special Symbols
  mod=ch+64;
  	modmult = mod * 20;
	if(modmult>500) {
		fout<<modmult; }
	else{
		fout<<mod; }
 }
 
 if((ch>=48) && (ch<=57))
 {
  	i=4;                                                //Encrypt The Numbers
  	mod=num[ch+i];
	modmult = mod * 20;
	if(modmult>500) {
		fout<<modmult; }
	else{
		fout<<mod; }
 }
 
 if((ch>=58)&&(ch<=64))
 {                                                    //For Special Symbols
  mod=ch+54;
  	modmult = mod * 20;
	if(modmult>500) {
		fout<<modmult; }
	else{
		fout<<mod; }
 }

if((ch>=65) && (ch<=90))
 {
  i=39;                                                 //Encrypt The Capital Letters
  mod=num[ch-i];                                        //And Store In An Output File
  	modmult = mod * 20;
	if(modmult>500) {
		fout<<modmult; }
	else{
		fout<<mod; }
 }

if((ch>=91)&&(ch<=96))
 {
  mod=ch+28;                                          //For Special Symbols
  	modmult = mod * 20;
	if(modmult>500) {
		fout<<modmult; }
	else{
		fout<<mod; }
 }

if((ch>=97) && (ch<=122))
 {                                                     //Encrypt The  Small Letters
  i=97;
  mod=num[ch-i];
  	modmult = mod * 20;
	if(modmult>500) {
		fout<<modmult; }
	else{
		fout<<mod; }
 }

if((ch>=123)&&(ch<=126))
 {
  mod=ch-40;                                          //For Special Symbols
  	modmult = mod * 20;
	if(modmult>500) {
		fout<<modmult; }
	else{
		fout<<mod; }
 }
}

////////////////////// STOP ENCRYPTING CHARACTERS //////////////////////

fin.close();                                          //Close The Input File
fout.close();                                         //Close The Output File

cout<<"Your File Is Encrypted Now........... ";
getch();
return 0;
}


