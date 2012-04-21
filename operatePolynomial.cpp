/*
	author:tianzhi ren
	date:2012/4/21
	description:The main function of this program is to solve the polynomial inverse about mod2 mutiply.
This program also offers some interface for solve polynomial input,print,and polynomial basical operation on Mod2.

*/
#include"operatePolynomial.h"
#include<iostream>
#include<iomanip>
#include<bitset>
#include<vector>
#include<string>
using namespace std;

Type32 recordPoly(){
	Type32 coeffPoly;
	cout<<"please input the coefficient of polynomial:"<<endl;
	int inCoeff;
	int count=0;
	size_t pos=0;//pos is unsigned number¡£
	bool flag=true;
	while(pos<coeffPoly.size()){
		if(flag)
			cout<<"input coeff of X^"<<count<<endl;
		else
			break;

		count++;

		if(cin>>inCoeff){		
			if(inCoeff)
			coeffPoly.set(pos);
		}
		else
			flag=false;
	
		pos++;
	}

	
	return coeffPoly;
}

void printPoly(Type32 poly){
	int counter=1;
	size_t pos=0;
	size_t upBord=polyDegree(poly);
	for(;pos<=upBord;pos++){
		if(poly[pos]==1&&counter==1){
			cout<<"1";
			counter++;
		}
		else if(poly[pos]){
			if(poly[pos+1])
				cout<<"+";
			cout<<"x^"<<pos;
			counter++;
		}
		else
			counter++;
	}
}

int polyDegree(Type32 poly){
	int degree;
	int counter=0;
	if(poly.none())
		return -1;

	int index=poly.size()-1;
	
	while(poly[index]^1){
		counter++;
		poly<<=1;
	}

	
	degree=poly.size()-counter-1;//bitsize<32>::size() return the number of bits in b
	return degree;
}

Type32 polyDivM2(Type32 pDividend,Type32 pDivisor,Type32 &pRemainder){
	Type32 quotient;
	int diviDegree;
	int quotientDegree;

	quotientDegree=polyDegree(pDividend);
	diviDegree=polyDegree(pDivisor);

	pRemainder=pDividend;
	if(quotientDegree<diviDegree)
		return quotient;

	while(quotientDegree>=diviDegree){
			size_t pos;
			pos=quotientDegree-diviDegree;
			quotient.set(pos);
			
			Type32 tempDivisor=pDivisor<<(quotientDegree-diviDegree);
		
			pDividend=polyMinusM2(pDividend,tempDivisor);
			quotientDegree=polyDegree(pDividend);
	}
	
	pRemainder=pDividend;
	return quotient;
}

Type32 polyAddM2(Type32 polyX,Type32 polyY){
	 Type32 polySum;
	 polySum=polyX^polyY;
	return polySum;
}

Type32 polyMinusM2(Type32 polyX,Type32 polyY){
	Type32 polyMinus;
	polyMinus=polyX^polyY;
	return polyMinus;
}

Type32 polyMultiplyM2(Type32 polyX,Type32 polyY){
	Type32 polyMult;
	Type32 regTemp;
	size_t pos=0;
	
	while(pos<polyY.size()-1){
		if(polyDegree(polyY)==0){
			polyMult=polyX;
		}
		else if(polyDegree(polyY)>=1){
				if(polyY.test(pos)){
				regTemp=polyX<<pos;
				polyMult=polyAddM2(regTemp,polyMult);
				}
		}		
		pos++;
	}

	return polyMult;
}


Type32 extendEulidPoly(Type32 polyA,Type32 polyB,Type32& prePolyV,Type32& currentPolyV,Type32& prePolyW,Type32& currentPolyW){
	static int counter=0;
	counter++;
	if(polyB.none())
		return polyA;
	else{
		Type32 remainderPoly;
		Type32 quotientPoly;
		Type32 tempPreV;
		Type32 tempPreW;
		quotientPoly=polyDivM2(polyA,polyB,remainderPoly);//produce quotient and remainder at the same time.
		
		if(remainderPoly.any()){
			tempPreV=currentPolyV;
			tempPreW=currentPolyW;
			currentPolyV=polyMinusM2(prePolyV,polyMultiplyM2(quotientPoly,currentPolyV));
			currentPolyW=polyMinusM2(prePolyW,polyMultiplyM2(quotientPoly,currentPolyW));
		}
		return extendEulidPoly(polyB,remainderPoly,tempPreV,currentPolyV,tempPreW,currentPolyW);


	}
}

Type32 polyMultInver(Type32 pDividend,Type32 pDivisor){
	Type32 polyInver;
	Type32 polyV_s1(0x00000001),polyW_s1;
	Type32 polyV_s2,polyW_s2(0x00000001);
	Type32 gcdPoly=extendEulidPoly(pDividend,pDivisor,polyV_s1,polyV_s2,polyW_s1,polyW_s2);
	if(gcdPoly.to_ulong()==1)
		polyInver=polyW_s2;
	return polyInver;
}