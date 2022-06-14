#include<iostream>
#include<conio.h>
#include<string.h>
#include<cstdlib>
#include<fstream>
#include<windows.h>
using namespace std;
//menu usuarios
int users();

//1.elementos para un dise�o electoral
//registro votantes
struct votantes{
	char cedula[11];
	char nombre[40];
	char apellido[40];
	int contrasena[10];
	char region[40];
	bool votoSino;
}votante[100];
//registros candidatos
struct candidatos{
	char nombre[40];
	char partidoPolitico[40];
	char cedula[11];
	char region[40];
	int numeroVotos;

}candidato[100];

//contrasena
char CONTRA[20]  = "000";
//variables
char si[4]="si";
char no[4]="no";
char siNo[10];
bool bandera=false;
int voto=0;
int num=1;
int i=0;
int num1=1;
int j=0;
int x=0;
int num2=1;
//funciones: 2. operaciones materiales del proceso
bool repetidoCedula(int numero, int numer);
bool bienvenida();
int menu();
void registroVotante(ofstream &es);
int registrarCandidato();
int mostar(ifstream &lec);
int contadorCandidatos=0;
int contadorVotantes=0;
char nombre[100];
void modificar();
void eliminar();
void votar();
char validarCedula;
void leerPasw(char frase[]);

int main(){
	//declarando candidatos por defecto
/*	strcpy(candidato[0].nombre,"petro");
	strcpy(candidato[1].nombre,"fico");
*/
	cout<<"SISTEMA DE VOTACIONES ELECTRONICO PRESIDENCIALES EN COLOMBIA"<<endl;
//	bienvenida();
	users();
//	menu();
	cout<<"_______________________________________________________________________________________________"<<endl;
	cout<<"Gracias por votar por Rodolfito";

	getch();
	return 0;
}
int users(){
	int op;
	cout<<endl;
	cout<<"\t1.Usuario Votante"<<endl;
	cout<<"\t2.Usuario Admi"<<endl;
	cout<<"\t3.Visualizar Resultados"<<endl;
	cin>>op;
	switch(op){
		case 1:
			votar();
			users();
			break;
		case 2:
			char contrase[15];
			fflush(stdin);	
			cout<<"digite la contrase�a: "; gets(contrase);
			if(strcmp(CONTRA,contrase)==0){
				menu();
			}
			else{
				cout<<"contrasena incorrecta, vuelva a ingresarla ";
				cout<<"tienes 3 intentos"<<endl;
				for(int x=0; x<3; x++){
					cout<<"intento No."<<x+1<<endl;					
					gets(contrase);
					if(strcmp(CONTRA,contrase)==0){
					menu();
					}
				}
				exit( 3 );
   				return 3;
			}
		break;
	}
}
void eliminar(ifstream &lec){
	int nu;
	cout<<"Quiere eliminar votantes o candidatos?  "<<endl;
	cout<<"\t1. Votante"<<endl;
	cout<<"\t2. Candidato"<<endl;
	cin>>nu;
	switch(nu){
		case 1:{
			string ced;
			string nom;
			lec.open("votantes.txt",ios::in);
			ofstream aux("auxiliar.txt",ios::out);
			if(lec.is_open()){
				cout<<"Cedula ";
				cin>>ced;
				lec>>votante[40].cedula;
				while(!lec.eof()){
					lec>>votante[40].nombre;
					lec>>votante[40].apellido;
					if(votante[40].cedula==ced){
						cout<<"eliminando... ";
						Sleep(1500);
						system("cls");
						cout<<"eliminado.";
					}else{
						aux<<votante[40].cedula<<" "<<votante[40].nombre<<" "<<votante[40].apellido<<'\n';
					}
						
					lec>>votante[40].cedula;
				}
				lec.close();
				aux.close();
				
			}else 
				cout<<"Error"<<endl;
			remove("votantes.txt");
			rename("auxiliar.txt","votantes.txt");
		break;
		}
		case 2:{
			string ced1;
			string nom1;
			lec.open("candidatos.txt",ios::in);
			ofstream aux1("auxiliar1.txt",ios::out);
			if(lec.is_open()){
				cout<<"Cedula ";
				cin>>ced1;
				lec>>candidato[40].cedula;
				while(!lec.eof()){
					lec>>candidato[40].nombre;
					lec>>candidato[40].partidoPolitico;
					if(candidato[40].cedula==ced1){
						cout<<"Eliminando...";
						Sleep(1500);
						system("cls");
						system("pause");
						cout<<"Eliminado.";
					}else{
						aux1<<candidato[40].cedula<<" "<<candidato[40].nombre<<" "<<candidato[40].partidoPolitico<<'\n';
					}
						
					lec>>candidato[40].cedula;
				}
				lec.close();
				aux1.close();
				
			}else 
				cout<<"Error"<<endl;
			remove("candidatos.txt");
			rename("auxiliar1.txt","candidatos.txt");
		break;
		}
			
	}
}
void modificar(ifstream &lec){
	int nu;
	cout<<"Quiere modificar votantes o candidatos?  "<<endl;
	cout<<"\t1. Votante"<<endl;
	cout<<"\t2. Candidato"<<endl;
	cin>>nu;
	switch(nu){
		case 1:{
				
			string ced;
			string nom;
			lec.open("votantes.txt",ios::in);
			ofstream aux("auxiliar.txt",ios::out);
			if(lec.is_open()){
				cout<<"Cedula ";
				cin>>ced;
				lec>>votante[40].cedula;
				while(!lec.eof()){
					lec>>votante[40].nombre;
					lec>>votante[40].apellido;
					if(votante[40].cedula==ced){
						cout<<"Nuevo nombre: ";
						cin>>nom;
						aux<<votante[40].cedula<<" "<<nom<<" "<<votante[40].apellido<<'\n';
					}else{
						aux<<votante[40].cedula<<" "<<votante[40].nombre<<" "<<votante[40].apellido<<'\n';
					}
						
					lec>>votante[40].cedula;
				}
				lec.close();
				aux.close();
				
			}else 
				cout<<"Error"<<endl;
			remove("votantes.txt");
			rename("auxiliar.txt","votantes.txt");
		break;
		}
		case 2: {
			string ced1;
			string nom1;
			lec.open("candidatos.txt",ios::in);
			ofstream aux1("auxiliar1.txt",ios::out);
			if(lec.is_open()){
				cout<<"Cedula ";
				cin>>ced1;
				lec>>candidato[40].cedula;
				while(!lec.eof()){
					lec>>candidato[40].nombre;
					lec>>candidato[40].partidoPolitico;
					if(candidato[40].cedula==ced1){
						cout<<"Nuevo nombre: ";
						cin>>nom1;
						aux1<<candidato[40].cedula<<" "<<nom1<<" "<<candidato[40].partidoPolitico<<'\n';
					}else{
						aux1<<candidato[40].cedula<<" "<<candidato[40].nombre<<" "<<candidato[40].partidoPolitico<<'\n';
					}
						
					lec>>candidato[40].cedula;
				}
				lec.close();
				aux1.close();
				
			}else 
				cout<<"Error"<<endl;
			remove("candidatos.txt");
			rename("auxiliar1.txt","candidatos.txt");
		break;
		}

	}
}
int menu(){
	ofstream Esc;
	ifstream lec;
	int opcion;
	system("cls");
	cout<<"\t1. Registro Votante"<<endl;
	cout<<"\t2. Registro Candidato"<<endl;
	cout<<"\t3. Modificar Registros"<<endl;
	cout<<"\t4. Eliminar Registro "<<endl;
	cout<<"\t5. Mostrar candidatos y votantes"<<endl;
	cout<<"\t6. Volver a menu de usuarios"<<endl;
	cin>>opcion;
	switch (opcion){
		case 1: 
			fflush(stdin);
			registroVotante(Esc);
			menu();
		break;
		case 2:	
			fflush(stdin);	
			registrarCandidato();
			menu();
		break;
		case 3:
			modificar(lec);
			menu();
		break;
		case 4:
			eliminar(lec);
			menu();
		break;		
		case 5: 
			mostar(lec);
			menu();
			break;
		case 6:
			users();
			break;
	
		}
	
	}


void votar(){
	char valida[40]="";
	fflush(stdin);
	int opc;
	
	cout<<"1.Votante General\n2.Votante Candidato"<<endl;
	
	switch(opc){
		case 1:
			
	}
	cout<<"Ingrese su cedula "; //validarCedula="2344442";
	gets(valida);
		for(int i=0; i<contadorVotantes; i++){
			if((strcmp(votante[i].cedula,valida)==0) && votante[i].votoSino==true){
				votante[i].votoSino==false; //desabilita al votante para que no vuelva a votar
				for(int j=0; j<contadorCandidatos; j++){
					cout<<"Candidato #"<<j+1<<" "<<candidato[j].nombre<<" - "<<candidato[j].partidoPolitico<<endl;
					cout<<"_______________________________________________________________________"<<endl;
				}
				fflush(stdin);	
				cout<<"Digite el numero del candidato por el cual desea votar: "<<endl; cin>>nuu;
				if(nuu-1==i){
					candidato[i].numeroVotos++;
				}
			}	
		}
}
bool verifica(string ced){

	ifstream leer("votantes.txt", ios::in);

	leer>>votante[40].cedula;

	while(!leer.eof()){
		leer>>votante[40].nombre;
		leer>>votante[40].apellido;
		if(votante[40].cedula==ced){
			cout<<"Usuario registrado\n";
			leer.close();
			return false;
		}
		leer>>votante[40].cedula;
	}
	leer.close();
	return true;
}

void leerPasw(char frase[])
{
    int i=0;
    cout.flush();

    do
    {
        frase[i] = (unsigned char)getch();
        if(frase[i]!=8)  // no es retroceso
        {
            cout << '�';  // muestra por pantalla
            i++;
        }
        else if(i>0)    // es retroceso y hay caracteres
        {
            cout << (char)8 << (char)32 << (char)8;
            i--;  //el caracter a borrar e el backspace
        }
        cout.flush();

    }while(frase[i-1]!=13);  // si presiona ENTER
	    frase[i-1] = NULL;
	    cout << endl;
}

void registroVotante(ofstream &es){
	system("cls");
	int op;
	char pasw[20];

	do
	{
		cout<<"1. Nuevo registro\n2. Salir"<<endl;
		cin>>op;
		cin.ignore();
		
		if(op==1)
		{
			es.open("votantes.txt", ios::out | ios::app);
			
			cout<<"Digita cedula: "; cin>>votante[11].cedula; 
			if (verifica(votante[11].cedula)){	
					
				fflush(stdin);		
				cout<<"\nDigita Nombre: ";
				gets(votante[40].nombre);
				cout<<"\nDigita Apellido: ";
				gets(votante[40].apellido);
				system("cls");
				cout <<"\nIngrese Contrase�a: ";
			    leerPasw(pasw);
			    cout << endl;
			    cout <<"\nMostrando password: "<< pasw << endl << endl;
			    es<<votante[11].cedula<<" "<<votante[40].nombre<<" "<<votante[40].apellido<<"\n";
		
				cout<<"registro guardado con exito...";
					system("pause");
					system("cls");
				
				es.close();	
		 }
			
		
	}
}while(op!=2);
}

bool verificar(string ced){

	ifstream leer("candidatos.txt", ios::in);

	leer>>candidato[40].cedula;

	while(!leer.eof()){
		leer>>candidato[40].nombre;
		leer>>candidato[40].partidoPolitico;
		if(candidato[40].cedula==ced){
			cout<<"Usuario registrado\n";
			leer.close();
			return false;
		}
		leer>>candidato[40].cedula;
	}
	leer.close();
	return true;
}

int registrarCandidato(){
	ofstream as;
		system("cls");
	int op;
	char pasw[20];

	do
	{
		cout<<"1. Nuevo registro\n2. Salir"<<endl;
		cin>>op;
		cin.ignore();
		
		if(op==1)
		{
			as.open("candidatos.txt", ios::out | ios::app);
			
			cout<<"Digita cedula: "; cin>>candidato[11].cedula; 
			if (verificar(candidato[11].cedula)){		
			fflush(stdin);		
			cout<<"\nDigita Nombre: ";
			gets(candidato[40].nombre);
			cout<<"\nDigita Partido politico: ";
			gets(candidato[40].partidoPolitico);
			system("cls");
			cout <<"\nIngrese Contrase�a: ";
		    leerPasw(pasw);
		    cout << endl;
		    cout <<"\nMostrando password: "<< pasw << endl << endl;
			
			as<<candidato[11].cedula<<" "<<candidato[40].nombre<<" "<<candidato[40].partidoPolitico<<"\n";
			
			cout<<"registro guardado con exito...";
				system("pause");
				system("cls");
			
			as.close();	
		}
	}
}while(op!=2);
}


int mostar(ifstream &lec){
	int most;
	cout<<"\t1.Mostrar Votantes Registados"<<endl;
	cout<<"\t2.Mostrar Candidatos Registrados"<<endl;
	cout<<"\t3.Mostrar Numero de votos por candidato"<<endl;
	cin>>most;
	system("cls");
	switch(most){
		case 1:	
			
			lec.open("votantes.txt", ios::in);
			lec>>votante[11].cedula;
			while(!lec.eof()){
				lec>>votante[40].nombre;
				lec>>votante[40].apellido;
				cout<<"Cedula: "<<votante[11].cedula<<endl;
				cout<<"Nombre: "<<votante[40].nombre<<endl;
				cout<<"apellido: "<<votante[40].apellido<<endl;
				cout<<"-----------------"<<endl;
				lec>>votante[11].cedula;
			}
			lec.close();
			system("pause");
		break;
		case 2:
			lec.open("candidatos.txt", ios::in);
			lec>>candidato[11].cedula;
			while(!lec.eof()){
				lec>>candidato[40].nombre;
				lec>>candidato[40].partidoPolitico;
				cout<<"Cedula: "<<candidato[11].cedula<<endl;
				cout<<"Nombre: "<<candidato[40].nombre<<endl;
				cout<<"Partido Politico: "<<candidato[40].partidoPolitico<<endl;
				cout<<"-----------------"<<endl;
				lec>>candidato[11].cedula;
			}
			lec.close();
			system("pause");
		break;	
	}
}
	
	
	

