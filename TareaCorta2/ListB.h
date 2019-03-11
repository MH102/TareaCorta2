#pragma once
#include <iostream>
#include <string>
using namespace std;

template <class T,int N>
class ListB {
private:
	struct Nodo {
		T elemento[N];
		int maxSize = N;
		int tamano = 0;
		struct Nodo * siguiente;
		Nodo(T x) :elemento{ elemento[0] = x }, siguiente{ 0 }, tamano{ 1 } {}
		Nodo(T x, struct Nodo* sig) :elemento{ elemento[0] = x }, siguiente{ sig }, tamano{ 1 } {}
	};

	typedef struct Nodo * link;

	link primero;		// Puntero al primer elemento de la lista
	int tam;			// Cantidad de elementos de la lista
	string nombreLista;	// Nombre de la lista


public:

	ListB(string nombre);
	int len();
	void push_front(T x);
	void push_back(T x);
	void insertar(T x);
	bool remove(int pos, T& x);
	bool pop(T& x);
	bool pop_back(T& x);
	bool get(int pos, T& element);
	bool get_front(T& element);
	bool get_back(T& element);
	void print();
	~ListB();

};

template<class T, int N>
ListB<T,N>::ListB(string nombre) {
	nombreLista = nombre;
	primero = NULL;
	tam = 0;
}

template<class T, int N>
void ListB<T, N>::push_front(T x) {
	if (!primero) {
		primero = new Nodo(x, primero);
	}
	else {
		link p = primero;
		T elem = p->elemento[0];
		T elem2;
		p->elemento[0] = x;
		for (int i = 1; i < p->tamano;i++) {
			elem2 = p->elemento[i];
			p->elemento[i] = elem;
			elem = elem2;
		}
		p = p->siguiente;
		while (p) {
			for (int i = 0; i < p->tamano;i++) {
				elem2 = p->elemento[i];
				p->elemento[i] = elem;
				elem = elem2;
			}
			p = p->siguiente;
		}
		push_back(elem);
	}
}

template<class T, int N>
void ListB<T, N>::push_back(T x) {
	if (!primero)
		primero = new Nodo(x, primero);
	else {
		link p;
		for (p = primero; p->siguiente; p = p->siguiente) {}
		if (p->tamano < p->maxSize) {
			p->elemento[p->tamano]=x;
			p->tamano++;
		}
		else {
			p->siguiente = new Nodo(x);
		}
	}
}

template<class T, int N>
void ListB<T, N>::insertar(T x) {
	if (!primero) {
		primero = new Nodo(x);
		tam++;
	}
	else {
		if (primero->tamano < primero->maxSize) {
				primero->elemento[primero->tamano] = x;
				primero->tamano++;
		}
		else {
			link p = primero;
			while (p->siguiente) {
				p = p->siguiente;
			}
			if (p->tamano < p->maxSize) {
				p->elemento[p->tamano] = x;
				p->tamano++;
			}
			else {
				p->siguiente = new Nodo(x);
				tam++;
			}
		}
	}
}
template<class T, int N>
bool ListB<T, N>::remove(int pos, T & x)
{
	if (tam == 0) {
		return false;
	}
	else {
		link p;
		if (pos == 0) {
			p = primero;
			primero = primero->siguiente;
			delete(p);
			tam--;
			return true;
		}
		else {
			p = primero;
			while (p->siguiente && pos > 1) {
				p = p->siguiente;
				pos--;
			}
			link aux = p->siguiente;
			p->siguiente = p->siguiente->siguiente;
			delete(aux);
			tam--;
			return true;
		}
	}
	return false;
}

template<class T, int N>
bool ListB<T, N>::pop(T & x)
{
	link aux = primero;
	while (aux->siguiente) {
		aux = aux->siguiente;
	}
	aux->tamano--;
	x = aux->elemento[aux->tamano];
	return true;
}

template<class T, int N>
bool ListB<T, N>::pop_back(T & x)
{
	return false;
}

template<class T, int N>
bool ListB<T, N>::get(int pos, T & element)
{
	if (!primero) {
		return false;
	}
	link aux = primero;
	while (aux && pos > 0) {
		aux = aux->siguiente;
	}
	element = aux->elemento;
	return false;
}

template<class T, int N>
bool ListB<T, N>::get_front(T & element)
{
	element = primero->elemento;
	return false;
}

template<class T, int N>
bool ListB<T, N>::get_back(T & element)
{
	link aux = primero;
	while (aux) {
		aux = aux->siguiente;
	}
	element = aux->elemento;
	return false;
}

template<class T, int N>
void ListB<T,N>::print() {
	cout << nombreLista << endl;
	if (primero) {
		link p = primero;
		while (p) {
			if (p->tamano == 0) {
				break;
			}
			cout << "[";
			for (int i = 0; i < p->tamano;i++) {
				if (i == p->tamano - 1) {
					cout << p->elemento[i];
					break;
				}
				cout << p->elemento[i] << " - ";
			}
			cout << "]" << endl;

			p = p->siguiente;
		}
	}
}

template<class T, int N>
int ListB<T,N>::len() {
	return tam;
}

template<class T, int N>
ListB<T,N>::~ListB() {
	link p;
	while (primero) {
		// Borrra todos los elementos en la
		// lista.
		p = primero->siguiente;
		delete primero;
		primero = p;
	}
}


