/*
	author:tianzhi ren
	date:2012/4/21
	description:The main function of this program is to solve the polynomial inverse about mod2 mutiply.
This program also offers some interface for solve polynomial input,print,and polynomial basical operation on Mod2.

*/
#include<bitset>
#pragma once
using std::bitset;// bitset declaration is made in namespace std,so must using std::bitset
typedef bitset<16> Type32;

//input polynomial and store it 
Type32 recordPoly();

//print the polynomial that you have inputed
void printPoly(Type32 poly);

//return the polynomial's degree
int polyDegree(Type32 poly);

//polynomial A multiply B 
Type32 polyMultiplyM2(Type32 polyX,Type32 polyY);

//polynomial1 pDividend is divided by pDivisor ,return the remainder
Type32 polyDivM2(Type32 pDividend,Type32 pDivisor,Type32 &pRemainder);

//polynomiall add operation
Type32 polyAddM2(Type32 polyX,Type32 polyY);

//polynomial minus operation
Type32 polyMinusM2(Type32 polyX,Type32 polyY);

//produce the polynomial multiply inverse 
Type32 polyMultInver(Type32 pDividend,Type32 pDivisor);

//extend Eulid algrithm for polynomial to solve inverse polynomial when gcd(polyA,polyB)=1
Type32 extendEulidPoly(Type32 polyA,Type32 polyB,Type32& prePolyV,Type32& currentPolyV,Type32& prePolyW,Type32& currentPolyW);