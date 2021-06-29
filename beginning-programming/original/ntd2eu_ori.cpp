#include<stdio.h>
#include<iostream>
#define Exchange_Rate 40.41        /*程式中"匯率"以Exchange_Rate表示*/
int main(int argc, char **argv)
{
	double NT_dollar;  /*輸入的新台幣幣值*/
	double Euros;      /*算出的歐元幣值*/
	
	/*1.從鍵盤得到新台幣幣值*/

	std::cout << "Please enter NT dollars" << std::endl;
    std::cin >> NT_dollar;
	
	/*2.依據匯率換算成歐元幣值*/

	Euros=NT_dollar/Exchange_Rate;

	/*3.將結果(歐元幣值)顯示在螢幕上*/

	std::cout.setf(std::ios::fixed, std::ios::floatfield);
    std::cout.precision(2);
    std::cout << "the amount in Euros=" << Euros << std::endl;

	/*程式結束*/

	return 0;    
}
