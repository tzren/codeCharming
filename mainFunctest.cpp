/*
	author:tianzhi ren
	date:2012/4/21
	description:The main function of this program is to solve the polynomial inverse about mod2 mutiply.
This program also offers some interface for solve polynomial input,print,and polynomial basical operation on Mod2.

*/
#include<iostream>
#include"operatePolynomial.h"
using namespace std;
int main(){
	Type32 pDividend(0x11b);
	Type32 pDivisor(0x83);
	Type32 pInverse;

	//pDividend=recordPoly();
	//pDivisor=recordPoly();
	

	cout<<"polynomial dividend is:"<<endl;
	printPoly(pDividend);
	cout<<"\npolynomial division is:"<<endl;
	printPoly(pDivisor);
	cout<<"\npolynomial multiply inverse is:"<<endl;
	pInverse=polyMultInver(pDividend,pDivisor);
	printPoly(pInverse);
	cout<<endl;
	system("pause");

	
	return 0;
}