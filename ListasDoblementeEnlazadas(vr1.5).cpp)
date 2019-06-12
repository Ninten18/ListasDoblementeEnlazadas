#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


void tituloPrincipal()
{
   int i;

   cout<<"===============================================================================\n";
   cout<<"                      Listas Doblemente Enlazadas                  "<<endl;
   cout<<"===============================================================================\n"<<endl;
    cout<<"'1' Insertar al Inicio"<<endl;   
    cout<<"'2' Insertar al Final"<<endl;
    cout<<"'3' Insertar por Referencia"<<endl;
    cout<<"'4' Eliminar por Inicio"<<endl;
    cout<<"'5' Eliminar al Final"<<endl;
    cout<<"'6' Eliminar por Referencia"<<endl;
    cout<<"'7' Mostrar la Lista"<<endl;
    cout<<"'8' Desea salir del Programa"<<endl;
   i = 0;
   putchar('\n');
   for (; i < 80; i++) {
      putchar('_');
   }
   cout<<endl;
}

struct Nodo
{
	int dato;
	Nodo *siguiente;			//Definimos los punteros de la clase para indicar a que posicion de la memoria apuntara
	Nodo *anterior;
};


typedef class Nodo *TDlista;			//Definimos a la clase tipo Puntero como en el caso de los Struct

class ListaDE
{			
	private:
		TDlista Frente;					//Definimos el puntero Frente como variable propia de la clase tomando como referencia al struct Nodo
		TDlista Final;					//Definimos el puntero Final como variable propia de la clase tomando como referencia al struct Nodo
	public:		
		ListaDE();									//Constructor de la clase
		void Push_inicio(int nuevo_dato);
		void Push_final(int nuevo_dato);
		void Mostrar();
};


ListaDE::ListaDE()
{	
	Frente = NULL;		//Inicializa El puntero al Dato NULL
	Final = NULL;		//Inicializa El puntero al Dato NULL
}

void ListaDE::Push_inicio(int nuevo_dato)
{
	TDlista q;
	q = new (struct Nodo);
	q -> dato = nuevo_dato;
	if(Frente == NULL)
	{		
		q -> siguiente = NULL;
		q -> anterior = NULL;
		Frente = q;
		Final = q;
	}
	else
	{
		q -> siguiente = Frente;
		q -> anterior = NULL;
		Frente = q;
	}
}

void ListaDE::Push_final(int nuevo_dato)
{
	TDlista q;
	q = new (class Nodo);
	q -> dato = nuevo_dato;

	if(Final == NULL)			//En caso de que sea el primer dato a ingresar
	{
		q -> anterior = NULL;
		q -> siguiente = NULL;
		Final = q;
		Frente = q;
	}
	else
	{
		q -> siguiente = NULL;
		q -> anterior = Final;
		Final -> siguiente = q;				
		Final = q;
	}
}

void ListaDE::Mostrar()
{
	TDlista q;
	q = Frente;
	if(Frente == NULL)
		{
			cout<<"No hay datos en la lista";
		}
	else
	{
		while(q != NULL)
		{			
			cout<<"["<<q->dato<<"]"<<endl;
			q = q -> siguiente;
		}
	}	
}



void main()
{
	ListaDE Prueba;	
	int opcion;
	int dato;
		while(opcion != 8)
		{
			tituloPrincipal();
			cout<<"Opcion:";
			cin>>opcion;
			clrscr();
			switch(opcion)
			{
				case 1:
				{
					tituloPrincipal();
					cout<<"Digite su dato :";
					cin>>dato;
					Prueba.Push_inicio(dato);
					cout<<"\n\nPulse enter";
					getch();
					clrscr();
					break;
				}

				case 2 :
				{
					tituloPrincipal();
					cout<<"Digite su dato :";
					cin>>dato;
					Prueba.Push_final(dato);
					cout<<"\n\nPulse enter";
					getch();
					clrscr();
					break;
				}

				case 3:
				{
					break;
				}

				case 4:
				{
					break;
				}

				case 5:
				{
					break;
				}

				case 6:
				{
					break;
				}

				case 7:
				{
					Prueba.Mostrar();
					cout<<"\n\nPulse enter";
					getch();
					clrscr();
					break;
				}
			}
		}
		system("Pause");
}
