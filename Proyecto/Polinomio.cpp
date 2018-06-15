/** Polinomio.cpp - Implementación de la clase Polinomio
 */
#include <iostream>
using namespace std;	/* cout, ostream */
#include "Polinomio.h"
#include "myfecha.h"
#define maximo(a,b)	((a>b)?a:b)

Polinomio::Polinomio(int intGrado,Rac *RacPt):
grado(intGrado),A(RacPt){ }

Polinomio::Polinomio(){
};
Polinomio& Polinomio::operator+(Polinomio& PolObj){
	int grad=maximo(grado,PolObj.grado);
	Polinomio ResPol(grad,new Rac[grad+1]);
	if(grado==grad){/*si el obj implicito es el de mayor grado*/
		for(int i=0;i<grado+1;i++){
			(ResPol.A+i)->n=(A+i)->n;
			(ResPol.A+i)->d=(A+i)->d;
		}
	}else{/*si el segundo operando es el de mayor grado*/
		for(int i=0;i<PolObj.grado+1;i++){
			(ResPol.A+i)->n=(PolObj.A+i)->n;
			(ResPol.A+i)->d=(PolObj.A+i)->d;
		}
	}
	if(grado<=grad){/*objeto implicito es el polinomio de menor grado*/
		for(int i=0;i<grado+1;i++){
			*(ResPol.A+i)=*(ResPol.A+i)+*(A+i);
		}
	}else{
		for(int i=0;i<ResPol.grado+1;i++){
			*(ResPol.A+i)=*(ResPol.A+i)+*(PolObj.A+i);
		}
	}
	return ResPol;
}
Polinomio& Polinomio::operator-(Polinomio& PolObj){//Stub
	return PolObj;
}


//   Polinomio& Polinomio::operator*(Polinomio& PolObj){		//Sobrecarga operador *
//	int grad1=grado;
//	int grad2=PolObj.grado;
//	int gradr=grad1+grad2;
//	int gradmax=maximo(grado,PolObj.grado);				
//	int i,a,b,c;
//	c=2;					
//	Rac pol1(a,b);
//	Rac pol2(a,b);
//	Polinomio ResPol1(gradr,new Rac[gradr+1]);			//Obtener coeficientes de los dif polinomios  
//
//	Rac M[10][10];									//Matriz gigante de Racs  los constructor: Rac(int intNum,int intDen);
//    												//Rellenar con ceros
//	int renglon,columna;
//	columna=0;
//	while(columna<10)
//	{ renglon=0;
//	while(renglon<10)
//	{ 
//	a=0;
//	b=1;
//	pol1.n=a;
//	pol1.d=b;
//	M[renglon][columna]=pol1;
//	renglon++;
//	}
//	columna++;
//    };	
//	
//	
//	for(i=0;i<=grad1;i++){								//Obtención radicales pol1
//	a=(A+i)->n;
//	b=(A+i)->d;
//	pol1.n=a;
//	pol1.d=b;
//	M[i][0]=pol1;
//	//cout<<M[i][0]<<"AQUi"<<endl;
//	}
//	
//	for(i=0;i<=grad2;i++){								//Obtención radicales pol2
//	//cout<<grad2<<"aqui"<<endl;
//	a=(PolObj.A+i)->n;
//	b=(PolObj.A+i)->d;
//	pol2.n=a;
//	pol2.d=b;
//	M[i][1]=pol2;
//	}	
///*	for(i=0;i<=grad1;i++){								//Mostrar radicales 1
//	cout<<M[i][0]<<"--";
//	}
//
//   for(i=0;i<=grad2;i++){								//Mostrar radicales 2
//	cout<<M[i][1]<<"..";
//	}
//*/
//	a=0;
//	while(a<=grad2){
//	for(i=0;i<=grad1;i++){
//	M[i][a+2]=M[i][0]*M[a][1];
//	}
//	a++;
//    };
//														//Para wachar matriz
///*   	columna=0;
//	while(columna<10)
//	{ renglon=0;
//	while(renglon<10)
//	{ 
//		cout<<M[renglon][columna]<<"hola";
//	renglon++;
//	}
//	columna++;
//		cout<<"columna:"<<columna+1<<endl;
//    };	
//*/
//
//					              //Agregar 1 renglon y restar una columna. 	Dependiendo la columna= no.veces que lo harás.
//    renglon=1;
//	int recorrido=10;
//	i=0;
//	
//	while(recorrido>2){
//	M[renglon][2]=M[renglon][2]+M[renglon][recorrido];
//	cout<<"AQUI"<<M[renglon][2];
//	renglon++;
//	recorrido=recorrido-1;
//};
//	cout<<"Ya salí"<<endl;
//	return ResPol1;
//
//}


Polinomio& Polinomio::operator*(Polinomio& PolObj){
	int grad;
	grad=grado+PolObj.grado;
	Polinomio ResPol(grad,new Rac[grad+1]);
	Rac factor1,factor2,factor1porfactor2,sumaparcial;
	for(int i=0;i<ResPol.grado+1;i++){
		*(ResPol.A+i)=Rac(0,1);
	}
	for(int k=0;k<grad+1;k++){
		for(int i=0;i<grado+1;i++){
			for(int j=0;j<PolObj.grado+1;j++){
				if((grado-i+PolObj.grado-j)==grad-k){
					factor1=*(A+i);
					factor2=*(new Rac((PolObj.A+j)->n,(PolObj.A+j)->d));
					factor1porfactor2=factor1*factor2;
					sumaparcial=*(ResPol.A+k)+factor1porfactor2;
					*(ResPol.A+k)=sumaparcial;
				}
			}
		}
	}
	return ResPol;
}


Polinomio& Polinomio::operator/(Polinomio& PolObj){//Stub
	return PolObj;
}


ostream& operator<<(ostream& ostreamOut,Polinomio& Polinomio1){
  for(int i=0;i<Polinomio1.grado+1;i++){
  	ostreamOut<<"\t"<<(Polinomio1.A+i)->n<<"/"<<(Polinomio1.A+i)->d;
  }
  return ostreamOut;
}
