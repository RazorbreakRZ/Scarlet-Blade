#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main(int argc, char** argv){
	string s1="",s2="";
	if(argc==1){
		s1=argv[0];
		system("ren SB.exe SB_bak.exe 0>nul 1>nul 2>nul"); //Hacemos backup del SB.exe original
		s2="copy /Y \""+s1+"\" SB.exe 0>nul 1>nul 2>nul";
		system(s2.c_str()); //Hacemos una copia de este ejecutable para darle la funcion de captura de datos
		system("SBLauncher.exe"); //Ejecutamos SBLauncher.exe para capturar los datos del login
		//Leemos el fichero SBconfig.txt
		ifstream f("SBconfig.txt", ifstream::in);
		if (!f){return 1;} //No se ha podido abrir el fichero, retornar errorlevel 1
		s2="SB_bak.exe";
		for(int i=0;i<4;i++){
			f >> s1;
			s2+=" "+s1;
		}
		f.close();
		system(s2.c_str()); //Ejecutar SB_bak.exe+SBconfig.txt
	}else{
		//Se crea una linea (s1) con los parametros de conexion
		for(int i=1;i<argc;i++){
			s2 = argv[i];
			s1+=" "+s2;
		}
		s1="echo "+s1+">SBconfig.txt";
		system(s1.c_str()); //Se guardan los parametros en el fichero "SBconfig.txt"
	}
	return 0;
}


