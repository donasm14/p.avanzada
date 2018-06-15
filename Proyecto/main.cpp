/** main.cpp - driver de prueba para la clase struct fecha y 
 *  de las clases Expresion, Box, BoxStringEqual, 
  * ..., ExpresionASimplificar.
 */
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <string.h>
using namespace std;	/* string, cout, endl */

#include <windows.h>
//#include "comandos.h""
#include "myfecha.h"
#include "Expresion.h"
#include "Polinomio.h"

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <windows.h> 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
char *get_dia(int intNumDia);
/**
 * Devuelve un apuntador a Fecha.
 * @param intFecha: debe representar una fecha de acuerdo con el formato 
 *                  yyyymmdd, por ejemplo, 20170819 representa 19 de agosto 
 *                  de 2017.
 */
Fecha *get_Fecha(int intFecha);
void ImpPol(Polinomio &);

//FUNCIONES MÍAS 
Rac terminos();
void prompt();

//comandos a;
Rac torac();
int decimales(float);


struct variable{ //ESTRUCTURA PARA GUARDAR LAS VARIABLES			//PARA LA SUMA, RESTA Y MULT E CREAN LOS POL A PARTIR DE ESTA MADRE :VV
	char nombre[41];
	//Rac *apu;
	//int grado;
	Polinomio *car;		//Creo que ya la hicimos xD
	variable(){
		car = new Polinomio();
	}
};

int comparar(char[],variable[]);

char nombreprov[41]="\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";

//variable rescata[51];

//Polinomio a;		//LUGAR DONDE SE GUARDARÁN VARIABLES
//int varpos=0;						//pos de supervariables

//FUNCIONES TOMADAS DE SHELL.CPP
struct cmd {
  int type;          //  ' ' (exec), | (pipe), '<' or '>' for redirection
};

int getcmd(char *buf, int nbuf)
{
  
  if (isatty(fileno(stdin)))
    fprintf(stdout, "$ ");
  memset(buf, 0, nbuf);
  fgets(buf, nbuf, stdin);
  if(buf[0] == 0) // EOF
    return -1;
  return 0;
}//end getcmd()

void echo_(char[]);


int main(int argc, char** argv) {
	
	printf("%s 23 de agosto de 2017\n",get_dia(2));
	Fecha *F=get_Fecha(20170823);
	F->set_dia();
	F->to_string_Pt();
	cout<<" ("<<F->dia<<")"<<endl;

	Rac rac1;rac1.n=30;rac1.d=60;rac1.mcd=30;
	cout<<"rac1="<<endl<<rac1;
	cout<<"rac1 simplificado="<<endl;
	ExpresionASimplificar EAS1(new BoxRac(&rac1));
	EAS1.print();cout<<endl;
	
	Rac rac2;rac2.n=96;rac2.d=128;
	cout<<"rac2="<<endl<<rac2;
	rac2.set_mcd();
	cout<<"rac2 simplificado="<<endl;
	ExpresionASimplificar EAS2(new BoxRac(&rac2));
	EAS2.print();cout<<endl;
	
	Rac rac3=rac1*rac2;
//	cout<<"rac3="<<endl<<rac3;
	
//	Expresion E(new BoxRac(&rac1),new BoxStringOperator('*'),new BoxRac(&rac2),new BoxRac(&rac3));
//	E.print();
	Rac rac4(64,256);
	cout<<"rac4="<<endl;
	ExpresionASimplificar EAS4(new BoxRac(&rac4));
	EAS4.print();
	void driverPolinomio(void);
	cout<<"\n";
	driverPolinomio();

	cout<<"AQUI EMPIEZA LO NUEVO "<<endl;



 //	prompt();

	cout<<"AQUI EMPIEZA LO SUPERCHIDO:"<<endl;
	static char buf[101];
  	int fd, r;
  	int varpos = 0;
	variable variables[51];
	Polinomio *caro=0;
	int numprov;
	int denprov;
	int index=0;
	int comasbuf;
	
    int ncomas=0;
    int comasreal=0;
    int comas[31];
    int igualpos,db,real;
	int maspos;
	
	int numero;
	char hello[101];													//HELLO CONTIENE LOS CHARS numeros.
	int x[31];															//TIENE LOS ENTEROS DE LOS NÚMEROS
	int p=0;						
	int indexa=0;						
	int saltos[31];
	saltos[0]=0;														//SALTOS GUARDARÁ LA DIFERENCIA DE LAS POSICIONES ENTRE LAS COMAS o diag
	int sal=0;
	
	const char *apun=&hello[sal];  					 				//APUNTADOR A HELLO 	//COMAS[] CONTIENE LA POS DE LAS COMAS EN EL BUF
	
	Rac arrac[comasreal];																//CREAR LOS RADICALES 1,2 X =1 RAC;  3,4=2 RAC
	Rac *RacPtprov=arrac;
	
	//Rac *RacPtprov = new Rac[comasreal]; 
	caro = new Polinomio((comasreal-2),RacPtprov);
	
//	STARTUPINFO si;
//	PROCESS_INFORMATION pi;
  // Read and run input commands.
  while(getcmd(buf, sizeof(buf)) >= 0){
  	cout<<"Varpos inicio"<<varpos<<endl;
	echo_(buf);
	
	
  //cout<<"SO FAR, SO GOOD\n";
//	Rac *unRacPt=new Rac[3];
//  *(unRacPt+0)=Rac(5,20);	/* a_{2} */
//  *(unRacPt+1)=Rac(7,2);	/* a_{1} */
//  *(unRacPt+2)=Rac(18,5);	/* a_{0} */
//  /*usamos constructor Polinomio(int,Rac*)*/
//  Polinomio Polinomio1(2,unRacPt); 
//  
//	
//	variables[1].nombre = 'pepe';
//	variables[1].car = Polinomio1;
	
		
	
	if(buf[0] == 'n' && buf[1] == 'u' && buf[2] == 'e'&& buf[3] == 'v'&& buf[4] == 'o'){    //ENTRA AL COMANDO NUEVO
	
	cout<< "ya la hicimos" << endl;
	for(db=0;db<=100;db++){  	//ESTE FOR BUSCA UN IGUAL
		if(buf[db]=='='){
		igualpos=db;
		}
	}
	cout<<"El igual se encuentra en pos:"<<igualpos<<endl;			
	for(db=6;db<igualpos;db++){	//ESTE FOR TE DA EL NOMBRE DE LA VARIABLE CREADA GUARDANDOLO PROVISIONALMENTE
		nombreprov[db-6]=buf[db];
	}
	
	char nulo='\0';												//RELLENA EL NOMBRE DE LAS VARIABLES CON CARATER NULO
	int realmismo=0;
	for(realmismo = 0; realmismo<=50; realmismo++){
	
		variables[varpos].nombre[realmismo]=nulo;
	}
	cout<<"Se asiganará el nombre"<<endl;						//AQUI SE ASIGNA EL NOMBRE A LA VAR PRINCIPAL
	for(real=0;real<=40;real++){						
    variables[varpos].nombre[real]=nombreprov[real];
	}
	for(real=0;real<=40;real++){						
    nombreprov[real]=' ';
	}
	
	//Rac *RacPtprov=new Rac[5];
	//Rac polprov;
	comasbuf=igualpos;		
													//SE RELLENARÁ CON 9999
	for(index=0;index<=30;index++){
	comas[index]=999;
	};
	
    ncomas=0;
    comasreal=0;
    index=0;
	for(comasbuf=igualpos;comasbuf<=100;comasbuf++){			//VER SI ES COMA "," O DIAGONAL "/"COMENZANDO UNO DESPUÉS DEL IGUAL Y GUARDARLOS EN LAS VARIABLES
	if(buf[comasbuf] ==','){
		cout<<"Posiciones en las que hay comas o diagonal en el buffer"<<endl;			//Deberia decir algo
		comas[index]=comasbuf;
		cout<<comas[index]<<endl;
		index++;
		ncomas++;
		comasreal++;
	}
	if(buf[comasbuf] =='/'){												///ESTO DEBERIA FUNCIONAR
		cout<<"Posiciones en las que hay coas o diagonal en el buffer"<<endl;
		comas[index]=comasbuf;
		cout<<comas[index]<<endl;
		index++;
		ncomas++;
	}
	}													
																//DEBE CONTAR EL NÚMERO DE COMAS Y DIAGONALES PARA VER CUANTAS VECES LO TIENE QUE HACER
																//Y SABER DESDE DONDE CONVERTIR EL NÚMERO
	for(index=0;index<=30;index++){
	if(comas[index]!=999){												
	cout<<"index:"<<index<<endl;
	cout<<"Posición de la coma en buffer"<<comas[index]<<endl;
	}
	};
	
	//varpos++;
																		//HELLO CONTIENE LOS CHARS numeros.
																	   //TIENE LOS ENTEROS DE LOS NÚMEROS   																	//SALTOS GUARDARÁ LA DIFERENCIA DE LAS POSICIONES ENTRE LAS COMAS o diag
	cout<<"El número de comas y diagonales es"<<ncomas<<endl;
	
	p=0;
	sal=0;
	saltos[0]=0;
	
	for(index=0;index<(ncomas-1);index++){
	saltos[index+1]=comas[index+1]-comas[index]-1;
	cout<<"Los saltos serian:"<<saltos[index+1]<<endl;
	}

	
	for(indexa=0;indexa<(ncomas-1);indexa++){
	for(index=comas[indexa]+1;index<comas[indexa+1];index++){  			//HARA LAS DIF E IMPRIIRA LOS VALORES EN ENTERO O ESO TRATARÁ
	hello[p]=buf[index];
	cout<<"Los números son :"<<hello[p]<<endl;
	p++;
	}

	sal=sal+saltos[indexa];
    
	apun=&hello[sal];  					 				//APUNTADOR A HELLO 	//COMAS[] CONTIENE LA POS DE LAS COMAS EN EL BUF
	x[indexa]=atoi(apun);
	cout<<"Este es el entero x"<<x[indexa]<<endl;								
   }
	
//	Rac arrac[comasreal];																//CREAR LOS RADICALES 1,2 X =1 RAC;  3,4=2 RAC
//Rac *RacPtprov=arrac;
	
	
	for(index=0;index<(comasreal-1);index++){
    arrac[index].n=x[2*index];
    arrac[index].d=x[2*index+1];
	}
	
	for(index=0;index<(comasreal-1);index++){
    cout<<"El numerador es:"<<arrac[index].n<<endl;
    cout<<"El denominador es:"<<arrac[index].d<<endl;
	}
	
	
	
	caro->A=RacPtprov;
	caro->grado=(comasreal-2);
	variables[varpos].car= caro;
	cout<<"ESTE ES CARO"<<endl;
	ImpPol(*caro);
	cout<<"Este es el chido"<<endl;
	ImpPol(*variables[varpos].car);
	//Polinomio caro(variables[varpos].grado,variables[varpos].apu);
	//variables[varpos].apu=RacPtprov;    //arrac
	//variables[varpos].grado=comasreal-2;
	
//	delete arrac;
//	delete RacPtprov;	
		
    cout<<endl<<"ESTE SERÍA EL POLINOMIO REAL"<<variables[varpos].car<<endl;
    ImpPol(*(variables[varpos].car));
	
	int despliega;
	for(despliega=0;despliega<=30;despliega++){	  //DESPLIEGA EL NOMBRE DE LA VARIABLES CREADAS HASTA EL MOMENTO
    for(real=0;real<=30;real++){
    cout<<variables[despliega].nombre[real];
	}
	}
	
	for(index=0;index<=varpos;index++){
	cout<<endl<<"Polinomios creados"<<endl;
	ImpPol(*(variables[index].car));
	}
	
	cout<<"Dirección variables: "<<&variables<<endl;
	
	/*if(varpos==1){
		cout<<endl<<"Polinomios creados"<<endl;
		ImpPol(*(variables[0].car));
		ImpPol(*(variables[1].car));
	}*/
	
	variables[30].car=&(*variables[0].car+*variables[0].car);
	cout<<"Rsultado suma improvisada"<<endl;
	ImpPol(*(variables[30].car));
										
	for(index=0;index<101;index++){
		hello[index]='a';}
	varpos=varpos+1;
	cout<<"Numero varpos"<<varpos<<endl	;
	//rescata[0].car=variables[0].car;
	cout<<"Linea antes de salir de nuevo"<<endl;
	ImpPol(*(variables[0].car));
	cout << endl << "Direccion" << endl;
	cout << &variables[0].car << endl;
	
	
}   //END COMANDO NUEVO

	cout<<"Varpos saliendo"<<varpos<<endl;
	cout<<"Linea después de salir de nuevo"<<endl;
	variable v=variables[0];
	Polinomio x=*(v.car);
	cout << "Este es el grado: " << x.grado << endl;
	Rac rac1 = *x.A;
	cout << "Este es el racional:" << endl<< rac1 << endl;
	cout << "Este es el numerador: " << rac1.n << endl;
	cout << "Este es el denominador: " << rac1.d << endl;
	
	ImpPol(x);
	cout << endl << "Direccion" << endl;
	cout << &variables[0].car << endl;
	if(buf[0]== 's'&& buf[1]=='u'&&buf[2]=='m'&&buf[3]=='a'){ 							//ENTRA AL COMANDO SUMA
	
	for(db=0;db<=100;db++){  	//ESTE FOR BUSCA UN MÁS
		if(buf[db]=='+'){
		maspos=db;
		}
	}
	//string t,fea;
	char var1[40];									//SON RELLENADAS CON CARACTER NULO.
	char var2[40];
	char nulo='\0';
	int realmismo=0;
	for (realmismo=0;realmismo<41;realmismo++){
	var1[realmismo]=nulo;
	var2[realmismo]=nulo;
	}

	
	for(db=5;db<maspos;db++){  	//ESTE IDENTIFICA LA VARIABLE	
	var1[db-5]=buf[db];
	}
	cout<<"La variable uno seria"<<endl;
	for(db=5;db<maspos;db++){  	//MUESTRA EL var1
	cout<<var1[db-5];}				
	cout<<endl;
	int comapos;
	for(db=0;db<=100;db++){  	//ESTE FOR BUSCA UNA , CON LA CUAL DEBE FINALIZAR LA SITAXIS DE LA SUMA 
		if(buf[db]==','){
		comapos=db;
		}; 
		}
	cout<<"Pos de la coma"<<comapos<<endl;
	cout<<"La variable dos sería"<<endl;
	for(db=(maspos+1);db<comapos;db++){  	//MUESTRA EL var2
	var2[db-(maspos+1)]=buf[db];
	cout<<var2[db-(maspos+1)];}
	cout<<endl;

 Rac *unRacPt5=new Rac[5];
  *(unRacPt5+0)=Rac(5,20);	/* a_{4} */
  *(unRacPt5+1)=Rac(7,2);	/* a_{3} */
  *(unRacPt5+2)=Rac(18,5);	// a_{2}
  *(unRacPt5+3)=Rac(4,3);	// a_{1}
  *(unRacPt5+4)=Rac(5,8);	// a_{0}
  
  Polinomio Polinomio3(4,unRacPt5);
  Polinomio Polinomio4(4,unRacPt5);
  //ImpPol(Polinomio3);
  
  //ImpPol(variables[4].car);
  
	int count=0;
	int varpos1;
	int varpos2;
	varpos2=0;
	bool compara;
	/*for(varpos2=0;varpos2<100;varpos2++){
    count=0;
    cout<<"Número de variable:"<<varpos2<<endl;
	for(carro=0;carro<41;carro++){
	compara=(var1[carro]==variables[varpos2].nombre[carro]);
	//compara=strcmp(var1,variables[varpos].nombre);
	if(compara==1){
	count++;
}
}
cout<<"Cueenta count= "<<count<<endl;
}*/
varpos1=comparar(var1,variables);
cout<<"Var1pos es "<<varpos1<<endl;

varpos2=comparar(var2,variables);
cout<<"Var2pos es"<<varpos2<<endl;

cout<<"Poinomios antes de sumarlos"<<endl;
cout<<"El valor del polinomiovar1 es"<<variables[varpos1].car<<endl;
cout<<"El valor del polinomiovar2 es"<<variables[varpos2].car<<endl;



variables[30].car=&(*variables[varpos1].car+*variables[varpos2].car);											//SE TIENE QUE SUMAR LAS VARIABLES
ImpPol(*(variables[30].car));


	
}																						//FIN COMANDO SUMA 

}// END WHILE 
	system("pause");
	return 0;
}//end main()

	

void driverPolinomio(void){
  Rac *unRacPt=new Rac[3];
  //cout<<"SO FAR, SO GOOD\n";
  *(unRacPt+0)=Rac(5,20);	/* a_{2} */
  *(unRacPt+1)=Rac(7,2);	/* a_{1} */
  *(unRacPt+2)=Rac(18,5);	/* a_{0} */
  /*usamos constructor Polinomio(int,Rac*)*/
  Polinomio Polinomio1(2,unRacPt); 
  /*Polinomio1 es de grado 2 con coeficientes Rac a_{0} a_{1} a_{2}*/
  cout<<"Polinomio1 ="<<endl;
  //cout<<Polinomio1<<endl;
  ImpPol(Polinomio1);
  Polinomio Polinomio2=Polinomio1+Polinomio1;
  cout<<"Polinomio1 + Polinomio1 ="<<endl;
  //cout<<Polinomio2<<endl;
  ImpPol(Polinomio2);
  
  Rac *unRacPt2=new Rac[5];
  *(unRacPt2+0)=Rac(5,20);	/* a_{4} */
  *(unRacPt2+1)=Rac(7,2);	/* a_{3} */
  *(unRacPt2+2)=Rac(18,5);	// a_{2}
  *(unRacPt2+3)=Rac(4,3);	// a_{1}
  *(unRacPt2+4)=Rac(5,8);	// a_{0}
  
  Polinomio Polinomio3(4,unRacPt2);
  Polinomio Polinomio4(4,unRacPt2);

	cout<<"Polinomio1 * Polinomio 2"<<endl;
  Polinomio4= Polinomio1*Polinomio2;	
  ImpPol(Polinomio4);
}


void ImpPol(Polinomio &a){
	int noarg;
	int num[noarg];
	int den[noarg];	
	int i;
	noarg=a.grado+1;
	for(i=0;i<noarg;i++){		//Obtener numeradores de los rac del pol
	num[i]=(a.A+i)->n;
    std::cout.width(6); std::cout << std::left <<num[i];
   }
   cout<<endl;
	for(i=0;i<noarg;i++){
	std::cout.width(6); std::cout << std::left <<"---";
   }
   cout<<endl;
	for(i=0;i<noarg;i++){		//Obtener denumeradores de los rac del pol
	den[i]=(a.A+i)->d;
	std::cout.width(6); std::cout << std::left <<den[i];
	};
	cout<<endl;
};


//void prompt(){
//	int b;
//	cout<<"(-__-)"<<endl;
//	char eleccion[7];
//	cin>>eleccion;
//	//b=comparar(eleccion);
//	cout<<"El valor de b es: "<<b<<endl;  //switch case con b por cada valro de comando
//	//terminos();
//	cout<<"Ya lo hice"<<endl;
//
//}




/*Rac terminos(){
	Rac *RacPtprov=new Rac[5];
	Rac polprov;
	int numprov;
	int denprov;
					//VER SI ES ESPACIO COMENZANDO UNO DESPUÉS DEL IGUAL
	int espaciobuf=igualpos;
	
	for(espaciobuf=igualpos;espaciobuf<=40;espaciobuf++){
	if(buf[espaciobuf] == ' '){
		cout<<"Posiciones en las que hay espacio en el buffer"<<endl;
		cout<<espaciobuf;
	}
	}
	
	*(RacPtprov+0)=Rac(5,20);	
	torac();
};*/


Rac torac(){
};


int decimales(float dec){			//OBTENER EL NUMERO DE DECIMALES.
	float num;
	num=dec;
	int count=0;
    while(num!=0){
    num = num * 10;
    count = count + 1;
    num = num-(int)num;}
	return count;
}


void echo_(char buf[]){
	int count=0;
	while(buf[count++]!=0);count--;
	count--;
	while((buf[count]==' ')||(buf[count]=='\n')){
		count--;
	}/*al salir de este while puede suceder que buf[count] sea ';' en cuyo caso no se hace echo*/
	
	if(buf[count]!=';'){
	  printf("%s",buf);
	}
}//end echo_

int comparar(char name[],variable a[]){   //esta funcion indica en qué posición del arreglo variables se encuentra la variable con atributo nombre = name.
	int i = 0;
	int n = 0;
	int count = 0;
	for(i = 0; i<=50; i++){
		cout<<"				";
		for(n=0; n <= 40; n++){
			//cout<<"variables [i][n]"<<a[i].nombre[n]<<endl;
			//cout<<"name [n]"<<name[n]<<"				";
			if (a[i].nombre[n] == name[n]){
				count++;
			}
			if(count == 40){
				return i;
			}
		}
	}
	cout << name << " no se encuentra en la memoria." << endl;
	return -1;
	
}//end comparar


