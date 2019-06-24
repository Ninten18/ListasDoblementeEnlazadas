#include <iostream>
#include <stdio.h>
#include <stdlib.h>          w
#include <conio.h>


void tituloPrincipal()
{
   int i;

   cout<<"===============================================================================\n";
   cout<<"                      Listas Doblemente Enlazadas                  "<<endl;
   cout<<"===============================================================================\n"<<endl;
   	cout<<"'1' Insertar"<<endl;   
    cout<<"'2' Eliminar"<<endl;
    cout<<"'3' Mostrar"<<endl;
    cout<<"'4' Desea salir del Programa"<<endl;    
   i = 0;
   putchar('\n');
   for (; i < 80; i++) {
      putchar('_');
   }
   cout<<endl;
}

void Menu_Pop()
{
   int i;

   cout<<"===============================================================================\n";
   cout<<"                      Eliminar                  "<<endl;
   cout<<"===============================================================================\n"<<endl;
   	cout<<"'1' Eliminar por Inicio"<<endl;
    cout<<"'2' Eliminar al Final"<<endl;
    cout<<"'3' Eliminar por Referencia"<<endl;
    cout<<"'4' Eliminar antes de la Referencia"<<endl;
    cout<<"'5' Eliminar despues de la Referencia"<<endl;
    cout<<"'6' Desea salir del Programa"<<endl;
   i = 0;
   putchar('\n');
   for (; i < 80; i++) {
      putchar('_');
   }
   cout<<endl;
}

void Menu_Insertar()
{
   int i;

   cout<<"===============================================================================\n";
   cout<<"                      Insertar                  "<<endl;
   cout<<"===============================================================================\n"<<endl;
   	cout<<"'1' Insertar al Inicio"<<endl;   
    cout<<"'2' Insertar al Final"<<endl;
    cout<<"'3' Insertar antes de una Referencia"<<endl;
    cout<<"'4' Insertar despues de una Referencia"<<endl;    
    cout<<"'5' Desea salir del Programa"<<endl;
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
		void Push_referencia_anterior(int nuevo_dato,int referencia);
		void Push_referencia_posterior(int nuevo_dato,int referencia);
		void Pop_inicio();
		void Pop_final();
		void Pop_referencia(int referencia);
		void Pop_referencia_anterior(int referencia);
		void Pop_referencia_posterior(int referencia);
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
		Frente -> anterior = q;
		Frente = q;
	}
}

void ListaDE::Push_final(int nuevo_dato)
{
	TDlista q;
	q = new (struct Nodo);
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

void ListaDE::Push_referencia_anterior(int nuevo_dato,int referencia)
{
	int bandera = 1;
	if(Frente == NULL)
	{
		cout<<"\nLa lista esta vacia"<<endl;
	}
	else
	{
		TDlista q,r;
		q = Frente;

		while(q -> dato != referencia && bandera == 1)
		{
			if(q -> siguiente == NULL)
			{
				bandera = 0;
			}
			else
			{
				r = q;
				q = q -> siguiente;
			}
		}

		if(bandera != 0)
		{
			TDlista x;
			x = new (struct Nodo);
			x -> dato = nuevo_dato;
			if(Frente == q)
			{
				x -> siguiente = q;
				x -> anterior = NULL;
				q -> anterior = x;				
				Frente = x;
			}
			else
			{
				r -> siguiente = x;
				x -> siguiente = q;
				q -> anterior = x;
				x -> anterior = r;
				
			}			
		}
		else
		{
			cout<<"\nNo se encontro el Nodo"<<endl;
		}
	}
}

void ListaDE::Push_referencia_posterior(int nuevo_dato,int referencia)
{
	int bandera = 1;
	if(Final == NULL)
	{
		cout<<"\nLa lista esta vacia"<<endl;
	}
	else
	{
		TDlista q,r;
		q = Frente;		
		while(q -> dato != referencia && bandera == 1)
		{
			if(q -> siguiente == NULL)
			{
				bandera = 0;
			}
			else
			{
				q = q -> siguiente;
				r = q -> siguiente;
			}
		}

		if(bandera != 0)
		{
			TDlista x;
			x = new (struct Nodo);
			x -> dato = nuevo_dato;
			if(q == Final)
			{
				q -> siguiente = x;
				x -> siguiente = NULL;
				x -> anterior = q;
				Final = x;
			}
			else
			{
				q -> siguiente = x;
				x -> siguiente = r;
				x -> anterior = q;
				r -> anterior = x;
			}			
		}
	}
}

void ListaDE::Pop_inicio()
{
	if(Frente != NULL)
	{
		TDlista q,r;
		q = Frente;
		if(q -> siguiente == NULL)
		{
			Frente = NULL;
			Final = NULL;
		}
		else
		{
			r = q -> siguiente;
			r -> anterior = NULL;
			Frente = r;
		}		
		delete q;
		cout<<"\n!!!DATO ELIMINADO!!!"<<endl;
	}
	else
	{
		cout<<"\nNo hay elementos en la Lista";
	}
}

void ListaDE::Pop_final()
{
	if(Final != NULL)
	{
		TDlista q,r;
		q = Final;
		if(q -> anterior == NULL)
		{
			Frente = NULL;
			Final = NULL;
		}
		else
		{
			r = q -> anterior;
			r -> siguiente = NULL;
			Final = r;
		}		
		delete q;
		cout<<"\n!!!DATO ELIMINADO!!!"<<endl;
	}
	else
	{
		cout<<"No hay elementos en la lista"<<endl;
	}
}

void ListaDE::Pop_referencia(int referencia)
{
	int bandera = 1;
	TDlista q,r,t;
	q = Frente;
	if(Frente != NULL)
	{
		while(q -> dato != referencia && bandera == 1)
		{
			if(q -> siguiente == NULL)
			{
				bandera = 0;
			}
			else
			{
				r = q;
				q = q -> siguiente;
				t = q -> siguiente;
			}
		}

		if(bandera != 0)
		{
			if(q == Frente && q == Final)
			{
				Frente = NULL;
				Final = NULL;
			}			
			else
			{
				if(q == Frente)
				{
					r = q -> siguiente;
					r -> anterior = NULL;
					Frente = r;
				}
				else
				{
					if(q == Final)
					{
						r = q -> anterior;
						r -> siguiente = NULL;
						Final = r;				
					}
					else
					{
						r -> siguiente = t;
						t -> anterior = r;
					}					
				}
			}
			delete q;
			cout<<"\n!!!DATO ELIMINADO!!!"<<endl;
		}
		else
		{
			cout<<"\nNo se encontro el Nodo"<<endl;
		}
	}
	else
	{
		cout<<"\nNo hay elementos en la lista"<<endl;
	}	
}

void ListaDE::Pop_referencia_anterior(int referencia)
{
	int bandera = 1;
	if(Frente != NULL)
	{
		TDlista q,r,t;
		q = Frente;
		while(q -> dato != referencia && bandera == 1)
		{
			if(q -> siguiente == NULL)
			{
				bandera = 0;
			}
			else
			{
				r = q;
				q = q -> siguiente;				
			}
		}

		if(bandera != 0)
		{
			if(q == Frente)
			{
				cout<<"\nEs el nodo Cabecera"<<endl;
			}
			else
			{
				if(q -> anterior == Frente)
				{
					q -> anterior = NULL;
					Frente = q;
				}
				else
				{
					t = r -> anterior;
					t -> siguiente = q;
					q -> anterior = t;
				}				
				delete r;
				cout<<"\n!!!DATO ELIMINADO!!!"<<endl;
			}
		}
		else
		{
			cout<<"\nNo se encontro el Nodo"<<endl;
		}
	}
	else
	{
		cout<<"No hay elementos en la Lista"<<endl;
	}
}

void ListaDE::Pop_referencia_posterior(int referencia)
{
	int bandera = 1;
	if(Final != NULL)
	{
		TDlista q,r,t;
		q = Final;
		while(q -> dato != referencia && bandera == 1)
		{
			if(q -> anterior == NULL)
			{
				bandera = 0;
			}
			else
			{
				r = q;
				q = q -> anterior;
			}
		}

		if(bandera != 0)
		{
			if(q == Final)
			{
				cout<<"\nEs el nodo Final"<<endl;
			}
			else
			{
				if(q -> siguiente == Final)
				{					
					q -> siguiente = NULL;
					Final = q;
				}
				else
				{
					t = r -> siguiente;
					q -> siguiente = t;
					t -> anterior = q;
				}
				delete r;
				cout<<"\n!!!DATO ELIMINADO!!!"<<endl;
			}			
		}
		else
		{
			cout<<"\nNo se encontro el nodo"<<endl;
		}
	}
	else
	{
		cout<<"\nNo hay elementos en la lista"<<endl;
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
			cout<<"  ["<<q->dato<<"]\t";
			q = q -> siguiente;
		}
	}	
}



void main()
{
	system("COLOR 0A");
	ListaDE Prueba;	
	int opcion;
	int referencia;
	int dato;
	int salida = 1;
		while(salida == 1)
		{
			tituloPrincipal();
			cout<<"Opcion:";
			cin>>opcion;
			clrscr();
			switch(opcion)
			{
				case 1:
				{
					Menu_Insertar();
					cout<<"Opcion:";
					cin>>opcion;
					clrscr();
					switch(opcion)
					{
						case 1:
						{
							Menu_Insertar();
							cout<<"Digite su dato :";
							cin>>dato;
							Prueba.Push_inicio(dato);
							cout<<"\n\nPulse enter";
							getch();
							clrscr();
							break;
						}
						case 2:
						{
							Menu_Insertar();
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
							Menu_Insertar();
							cout<<"Digite la referencia :";
							cin>>referencia;
							cout<<"Digite su dato :";
							cin>>dato;					
							Prueba.Push_referencia_anterior(dato,referencia);
							cout<<"\n\nPulse enter";
							getch();
							clrscr();
							break;
						}
						case 4:
						{
							Menu_Insertar();
							cout<<"Digite la referencia :";
							cin>>referencia;
							cout<<"Digite su dato :";
							cin>>dato;					
							Prueba.Push_referencia_posterior(dato,referencia);
							cout<<"\n\nPulse enter";
							getch();
							clrscr();
							break;
						}
						case 5:
						{
							salida = 0;
							break;
						}
					}					
					break;
				}
				case 2 :
				{
					Menu_Pop();
					cout<<"Opcion:";
					cin>>opcion;
					clrscr();
					switch(opcion)
					{
						case 1:
						{
							Menu_Pop();
							Prueba.Pop_inicio();
							cout<<"\n\nPulse enter";
							getch();
							clrscr();
							break;
						}
						case 2:
						{
							Menu_Pop();
							Prueba.Pop_final();
							cout<<"\n\nPulse enter";
							getch();
							clrscr();
							break;
						}
						case 3:
						{
							Menu_Pop();
							cout<<"Digite la referencia :";
							cin>>referencia;
							Prueba.Pop_referencia(referencia);
							cout<<"\n\nPulse enter";
							getch();
							clrscr();
							break;
						}
						case 4:
						{
							Menu_Pop();
							cout<<"Digite la referencia :";
							cin>>referencia;
							Prueba.Pop_referencia_anterior(referencia);
							cout<<"\n\nPulse enter";
							getch();
							clrscr();
							break;
						}
						case 5:
						{
							Menu_Pop();
							cout<<"Digite la referencia :";
							cin>>referencia;
							Prueba.Pop_referencia_posterior(referencia);
							cout<<"\n\nPulse enter";
							getch();
							clrscr();
							break;
						}
						case 6:
						{
							salida = 0;
							break;
						}
					}					
					break;
				}

				case 3:
				{
					Prueba.Mostrar();
					cout<<"\n\nPulse enter";
					getch();
					clrscr();					
					break;
				}
				case 4:
				{
					salida = 0;
					break;
				}							
			}
		}
		system("Pause");
}
