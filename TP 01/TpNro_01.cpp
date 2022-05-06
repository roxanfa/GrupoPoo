#include <iostream>
#include<time.h>
#include <iomanip>
#include <windows.h>
using namespace std;

int Menu(){
	int o;
	system("CLS");
	cout << "               M E N U" << endl
		 << "     1.- MATRIZ DE NUMEROS ENTEROS ALEATORIOS" << endl
		 << "     2.- SUMA DE 2 MATRICES" << endl
		 << "     3.- MATRIZ CON NUMERO PASADO POR PARAMETRO" << endl
		 << "     4.- ROTAR MATRIZ" << endl
		 << "     5.- MATRIZ CON DOS NUMEROS DE FORMA ALEATORIA" << endl
		 << "     6.- EJE 6" << endl
		 << "     7.- EJE 7" << endl
		 << "     8.- SALIR" << endl
		 << endl << "     INGRESE OPCION: ";
	cin >> o;
	return o;
}

void LiberarMemoria(int f, int c, int **m){
	for (int i=0;i<f;i++){
		delete[]m[i];
	}
	delete []m;	
}
void GenerarMatrizDinamica(int f, int c, int **m){
	for (int i=0; i<f; i++)	{
		m[i]=new int [c];
	}
}
bool SePuedeSumar(int f1, int c1, int f2, int c2){ // Controla que ambas matrices tengan la misma dimension para ver si se pueden sumar
	bool sp= false;
	if (f1==f2){
		if (c1==c2){
			sp=true;
		}
	}
	return sp;
}

int **LlenarMatriz(int f, int c, int ** m,int dato=-1){
	
	if (dato==-1){
		for (int i=0; i<f; i++)	{
			for (int j=0; j<c; j++){
				
				m[i][j]=rand()%100;
			}
		}
	}
	else{
		for (int i=0; i<f; i++)	{
			for (int j=0; j<c; j++){
				m[i][j]=dato;
			}
		}	
	}
	return m;
}
	
int **CargaMatriz2nros(int f, int c, int **m, int n1=0, int n2=1){
	int aux;
	
	
	for (int i=0; i<f; i++)	{
		for (int j=0; j<c; j++)		{
			aux=rand()%2;
			if (aux==0)	m[i][j]= n1;
			else m[i][j] = n2;
		}
	}
	return m;
}	
int **SumaMatriz (int f, int c, int **m1, int **m2, int **matAux){
	
	for (int i=0; i<f; i++)	{
		for (int j=0; j<c; j++)		{
			matAux[i][j]=m1[i][j]+m2[i][j];
		}
	}
	return matAux;
}
void InformarMatriz(int f, int c, int **m){
	for (int i=0; i<f; i++)	{
		cout << "          ";
		for (int j=0; j<c; j++){
			cout << setw(5) << m[i][j];
		}
		cout <<endl;
	}
}
void RotarMatriz(int f, int c, int **m, int **matAux){
	for (int i=0; i<f; i++)	{
		for (int j=0; j<c; j++)		{
			matAux[j][i]=m[i][j];
		}
	}
}	
int **CambiarFila(int f, int c, int **m, int fc, int cc, int d1, int d2){
	int dato = m[fc][cc];
	if (dato==d1) dato = d2;
	else dato = d1;
	m[fc][cc]=dato;
	if ((fc>0) and (fc<f-1)){
		m[fc-1][cc]=dato;
		m[fc+1][cc]=dato;
	}
	if ((cc>0) and (cc<c-1)){
		m[fc][cc-1]=dato;
		m[fc][cc+1]=dato;
	}
	if (fc==0) m[fc+1][cc]=dato;
	if (fc==f-1) m[fc-1][cc]=dato;
	if (cc==0) m[fc][cc+1]=dato;
	if (cc==c-1) m[fc][cc-1]=dato;
	return m;
}
int main(){
	int filas, columnas;
	int opcion, nro1, nro2;
	srand(time(NULL));
	do{
		opcion = Menu();
		switch (opcion) {
		case 1:{ 
			cout << "     ingrese cant de filas: ";
			cin >> filas;
			cout << "     ingrese cant de columnas: ";
			cin >> columnas;
			int **matriz = new int *[filas];
			GenerarMatrizDinamica(filas, columnas, matriz);
			
			
			matriz = LlenarMatriz(filas, columnas, matriz);
			cout <<endl << "     EJERCICIO 1 - MATRIZ CON NUMEROS ALEATORIOS" << endl;
			InformarMatriz(filas, columnas, matriz);
			LiberarMemoria(filas, columnas, matriz);
			system("pause");
		}	
		break;
		case 2:{ 
			int filas1, columnas1, filas2, columnas2;
			bool sepuede = false;
			cout << "     ingrese cant de filas de matriz 1: "; cin >> filas1;
			cout << "     ingrese cant de columnas de matriz 1: "; cin >> columnas1;
			cout << "     ingrese cant de filas de matriz 2: "; cin >> filas2;
			cout << "     ingrese cant de columnas de matriz 2: "; cin >> columnas2;
			int **matriz1 = new int *[filas1];
			GenerarMatrizDinamica(filas1,columnas1, matriz1);
			int **matriz2 = new int *[filas2];
			GenerarMatrizDinamica(filas2,columnas2, matriz2);
			matriz1 = LlenarMatriz(filas1, columnas1, matriz1);
			matriz2 = LlenarMatriz(filas2, columnas2, matriz2);
			cout << endl << "     EJERCICIO 2 - SUMA DE MATRICES" << endl;
			cout << endl << "     PRIMER MATRIZ" << endl;
			InformarMatriz(filas1, columnas1, matriz1);
			cout << endl << "     SEGUNDA MATRIZ" << endl;
			InformarMatriz(filas2, columnas2, matriz2);
			sepuede=SePuedeSumar(filas1,columnas1,filas2, columnas2);
			if (sepuede){
				int **matriz3 = new int *[filas1];
				GenerarMatrizDinamica(filas1,columnas1, matriz3);
				matriz3 = SumaMatriz(filas1,columnas1, matriz1,matriz2, matriz3);
				cout << endl << "     MATRIZ1 + MATRIZ2" << endl;
				InformarMatriz(filas1,columnas1, matriz3);
				//cout <<"hola" << endl;
				LiberarMemoria(filas1, columnas1, matriz3);
				//cout <<"mundo" <<endl;
			}
			else cout << endl << "     las matrices no se pueden sumar ya que no coinciden el numero de filas o de columnas" << endl;
			LiberarMemoria(filas1, columnas1, matriz1);
			LiberarMemoria(filas2, columnas2, matriz2);
			
			system("pause");
		}
		break;
		case 3:{
			int dato;
			cout << "     ingrese cant de filas: ";
			cin >> filas;
			cout << "     ingrese cant de columnas: ";
			cin >> columnas;
			cout << "     Ingrese el dato con el cual rellenar la matriz: ";
			cin >> dato;
			int **matriz = new int *[filas];
			GenerarMatrizDinamica(filas, columnas, matriz);
			matriz = LlenarMatriz(filas, columnas, matriz, dato);
			cout << endl << "     EJERCICIO 3 - MATRIZ CARGADA CON UN DATO PASADO POR PARAMETRO" << endl;
			InformarMatriz(filas, columnas, matriz);
			LiberarMemoria(filas, columnas, matriz);
			system("pause");
		}	
		break;
		case 4: {
			cout << "     ingrese cant de filas: ";
			cin >> filas;
			cout << "     ingrese cant de columnas: ";
			cin >> columnas;
			int **matriz = new int *[filas];
			GenerarMatrizDinamica(filas, columnas, matriz);
			int **matAux = new int *[columnas];
			GenerarMatrizDinamica(columnas,filas, matAux);
			matriz = LlenarMatriz(filas, columnas, matriz);
			cout << endl << "     EJERCICIO 4 - ROTAR MATRIZ" << endl;
			cout << endl << "     matriz original" <<endl;
			InformarMatriz(filas, columnas, matriz);
			RotarMatriz(filas,columnas,matriz, matAux);
			
			cout << endl << "     matriz rotada" <<endl;
			InformarMatriz(columnas, filas, matAux);
			LiberarMemoria(filas, columnas, matriz);
			LiberarMemoria(filas, columnas, matAux);
			system("pause");
		}
		
		break;
		case 5:{ 
			
			char d;
			cout << "     ingrese cant de filas: ";
			cin >> filas;
			cout << "     ingrese cant de columnas: ";
			cin >> columnas;
			cout << "     Quiere ingresar los numeros para llenar la matriz (s/S o n/N): ";
			cin >> d;
			int **matriz = new int *[filas];
			GenerarMatrizDinamica(filas, columnas, matriz);
			if ((d=='s') or (d=='S')){ 
				cout << "     Ingrese el primer nro: ";
				cin >> nro1;
				cout << "     Ingrese el segundo nro: ";
				cin >> nro2;
				matriz = CargaMatriz2nros(filas, columnas, matriz, nro1, nro2);
				
			}
			else matriz = CargaMatriz2nros(filas, columnas, matriz);
			cout << endl << "     EJERCICIO 5 - MATRIZ CARGADA CON DOS DATOS" << endl;
			InformarMatriz(filas, columnas, matriz);
			LiberarMemoria(filas, columnas, matriz);
			system("pause");
		}
		break;
		/*case 6: 
		
		break;*/
		case 7: {
			int fila,columna;
			cout << "     ingrese cant de filas: ";
			cin >> filas;
			cout << "     ingrese cant de columnas: ";
			cin >> columnas;
			int **matriz= new int *[filas];
			GenerarMatrizDinamica(filas,columnas,matriz);
			cout << "     Ingrese el primer nro: ";
			cin >> nro1;
			cout << "     Ingrese el segundo nro: ";
			cin >> nro2;
			matriz = CargaMatriz2nros(filas,columnas, matriz, nro1, nro2);
			cout <<"matriz original" << endl;
			InformarMatriz(filas, columnas, matriz);
			cout << "     Ingrese la fila donde se encuentra el dato: ";
			cin >> fila;
			cout << "     Ingrese la columna donde se encuentra el dato: ";
			cin >> columna;
			matriz = CambiarFila(filas, columnas, matriz, fila,columna, nro1, nro2);
			cout <<"matriz con cambio" << endl;
			InformarMatriz(filas, columnas, matriz);
			LiberarMemoria(filas, columnas, matriz);
			system("pause");
		}
			break;
	
		};
	}while(opcion<8);
		
	system("pause");	
	return 0;
}
		
