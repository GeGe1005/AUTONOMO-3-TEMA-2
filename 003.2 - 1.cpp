//EJERCICIO
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
const int maxd=100; //Máximo de días para evitar crecimientos infinitos
int pasos [maxd];
int minutos [maxd];
int calorias [maxd];
int n=0;
int validarentero(string mensaje)
{
	int valor;
	while (true)
	{
	cout<< mensaje;
	if(cin>>valor&&valor>=0) return valor;
	cout<< " Entrada invalida. Debe ingresar un numero entero. ";
	cin.clear();
	cin.ignore(1000, '\n');
	}
}
void intercambiar(int &a, int &b)
{
	int aux=a;
	a=b;
	b=aux;
}
void ingresardatos()
{
int cant=validarentero(" Cuantos dias desea registrar inicialmente? : ");
for (int i=0; i<cant&&n<maxd; i++)
{
	cout<< " Dia "<<n+1<<"(⁠ㆁ⁠ω⁠ㆁ⁠)"<<endl;
	pasos[n]=validarentero(" Pasos diarios: ");
	minutos[n]=validarentero(" Minutos de actividad: ");
	calorias[n]=validarentero(" Calorias quemadas: ");
	n++;
}
}
void inserteregistro()
{
if(n>=maxd)
{
	cout<<" Error: Memoria llena. "<<endl;
	return;
}
int pos=validarentero(" Posicion de insercion (1 a " + to_string(n+1)+"): ")-1;
//recorrido inverso para abrir espacio [5], [6]
for (int i = n; i >pos; i--)
{
	pasos[i]=pasos[i-1];
	minutos[i]=minutos[i-1];
	calorias[i]=calorias[i-1];
}
pasos[pos]=validarentero(" Nuevos pasos: ");
minutos[pos]=validarentero(" Nuevos minutos: ");
calorias[pos]=validarentero(" Nuevas calorias: ");
n++;
cout<<" Registro insertado con exito. "<<endl;
}
void modificaregistro()
{
	int pos=validarentero(" Dias a modificar (1 a" + to_string(n)+"):")-1;
	if (pos>=0&&pos<n)
	{
	pasos[pos]=validarentero(" Actualizar pasos: ");
	minutos[pos]=validarentero(" Actualizar minutos: ");
	calorias[pos]=validarentero(" Actualizar calorias: ");
	}
	else
	{
	cout<<" Posicion no valida. "<<endl;
	}
}
void buscarregistro()
{
	int buscar=validarentero(" Ingrese valor de pasos a buscar: ");
	bool encontrado=false;
	for(int i=0; i<n; i++)
	{
	if(pasos[i]==buscar)
	{
	cout<<" Encontramos el dia: "<<i+1<<endl;
	cout<<" Minutos: "<<minutos[i]<<endl;
	cout<<" Calorias: "<<calorias[i]<<endl;
	encontrado=true;
	}
	}
	if(!encontrado)cout<<" Valor no encontrado."<<endl;
}
void ordenaregistros(bool ascendente)
{
	for(int i=0; i<n-1; i++)
	{
	for(int j=0; j<n-i-1; j++)
	{
	bool condicion=ascendente? (pasos[j]>pasos[j+1]):(pasos[j]<pasos[j+1]);
	if(condicion)
	{
	intercambiar(pasos[j], pasos[j+1]);
	intercambiar(minutos[j], minutos[j+1]);
	intercambiar(calorias[j], calorias[j+1]);
	}
	}
	}
	cout<<" Registro ordenado. "<<endl;
}
void mostrarregistro()
{
	if(n==0)
	{
	cout<<" No hay registros. ";
	return;
	}
	cout<<"\nDIA\tPASOS\tMINUTOS\tCALORIAS\n";
	for(int i=0; i<n; i++)
	{
		cout<<i+1<<"\t"
		<<pasos[i]<< "\t"
  		<<minutos[i]<< "\t"
    		<<calorias[i]<< endl;
	}
}
void eliminaregistro()
{
 	int pos=validarentero(" Dia a eliminar (1 a " +to_string(n)+"): ")-1;
	if(pos>=0&&pos<n)
	{//desplazamiento a la izquierda para borrar
	for(int i=pos; i<n-1; i++)
	{
	pasos[i]=pasos[i+1];
	minutos[i]=minutos[i+1];
	calorias[i]=calorias[i+1];
	}
	n--;
	cout<<" Dia eliminado. "<<endl;
	}
}//INICIAREMOS EL ANALISIS ESTADISTICO
void realizaranalisis()
{
	if(n==0) return;
	int sump=0, summ=0, sumc=0;
	for(int i=0; i<n; i++)
	{
	sump+=pasos[i];
	summ+=minutos[i];
	sumc+=calorias[i];
	}
	cout<<" ANALISIS ESTADISTICO "<<endl;
	cout<<" Media de pasos: "<<(float)sump/n<<endl;
	cout<<" Media de minutos: "<<(float)summ/n<<endl;
	cout<<" Media de calorias: "<<(float)sumc/n<<endl;
int diadescanso=0;
for(int i=0; i<n; i++) if(pasos[i]<5000)diadescanso++;
cout<<" Dias de descanso (5000 pasos): "<<diadescanso<<endl;
}
int main()
{
	int opcion;
	do
	{
	cout<<" 1. INGRESE DATOS"<<endl;
	cout<<" 2. INSERTAR DIA "<<endl;
	cout<<" 3. MODIFICAR "<<endl;
	cout<<" 4. BUSCAR"<<endl;
	cout<<" 5. ORDENAR ASCENDENTE"<<endl;
	cout<<" 6. ORDENAR DESCENDENCIA"<<endl;//registro ordenado
	cout<<" 7. ELIMINAR "<<endl;
	cout<<" 8. ANALISIS "<<endl;
	cout<<" 9. TERMINAR "<<endl;
	opcion=validarentero("Seleccionar: ");
	switch(opcion)
	{
	case 1: ingresardatos(); break;
	case 2: inserteregistro(); break;
	case 3: modificaregistro(); break;
	case 4: buscarregistro(); break;
	case 5: ordenaregistros(true); mostrarregistro(); break;
	case 6: ordenaregistros(false);mostrarregistro(); break;
	case 7: eliminaregistro(); break;
	case 8: realizaranalisis(); break;
	}
	}
	while(opcion!=9);
	return 0;
}