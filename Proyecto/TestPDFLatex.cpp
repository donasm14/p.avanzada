// TEST PDFLATEX.cpp
#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

#define TEST_PDFLATEX
#ifdef TEST_PDFLATEX
int main(void){
	
	string dest_file="Asignaciones.tex";
	ofstream out(dest_file.c_str()); 			//objeto out tipo flujo hacia archivo de salida
	
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	
	if(out){
		out<<"\\documentclass{article}"<<endl;
		out<<"\\begin{document}"<<endl;
		out<<"\\begin{center}"<<endl;
		out<<"\\begin{tabular}{|p{2.0in}|p{2.0in}|}"<<endl;
		out<<"\\hline"<<endl;
		out<<"{\\bf Asignaci\'on} & {\\bf Fecha l\'imite} \
		\\\\ \\hline"<<endl;
		out<<"Interprete de \\ 'ordenes para hacer operaciones\
		con polinomios &"<<endl;
		out<<"27 de octubre de 20017\\\\ \\hline"<<endl;
		out<<"\\end{tabular}"<<endl;
		out<<"\\end{center}"<<endl;
		out<<"\\end{document}"<<endl;
		ZeroMemory(&si,sizeof(si));
		si.cb=sizeof(si);
		ZeroMemory(&pi,sizeof(pi));
		}
  
/*	if(!CreateProcess("C:/Windows/notepad.exe",
			"notepad.exe D:/readme.txt",0,0,0,0,0,0,&si,&pi)){
			//Could not start process;
			//Now 'pi.hProcess' contains the process HANDLE, which you can use to wait for it like this:
			printf("There are some problem(s)\n");
			WaitForSingleObject(pi.hProcess,INFINITE);
		}
*/
		else{
		cout<<"Khastapasando, no fue posible crear el flujo de salida"<<endl;
	}	

   
	return 0;
	//system("pause");
}

#endif   //TEST_PDFLATEX

