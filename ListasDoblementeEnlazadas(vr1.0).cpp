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


typedef class Nodo *TDlista;
class Nodo
{
	private:
		int dato;		
		Nodo *siguiente;
		Nodo *anterior;		
		TDlista Frente;
		TDlista Final;
	public:
		Nodo();
		void Push_inicio(int nuevo_dato);
		void Mostrar();
};


Nodo::Nodo()
{	
	Frente = NULL;
	Final = NULL;
}

void Nodo::Push_inicio(int nuevo_dato)
{
	TDlista q;
	q = new (class Nodo);
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

void Nodo::Mostrar()
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
	TDlista Prueba;	
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
					Prueba -> Push_inicio(Comienzo,Termino,dato);
					cout<<"\n\nPulse enter";
					getch();
					clrscr();
					break;
				}

				/*case 2 :
				{
					tituloPrincipal();
					cout<<"Digite su dato :";
					cin>>dato;
					Prueba.Push_final(Prueba,dato);
					cout<<"\n\nPulse enter";
					getch();
					clrscr();
					break;
				}*/

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
					Prueba -> Mostrar(Comienzo,Termino);
					cout<<"\n\nPulse enter";
					getch();
					clrscr();
					break;
				}
			}
		}
		system("Pause");
}
