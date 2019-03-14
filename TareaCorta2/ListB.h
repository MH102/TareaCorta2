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

	void shiftRight(link p, int pos) {
		T elem = p->elemento[pos];
		T elem2;
		for (int i = pos+1; i < p->tamano;i++) {
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
	int contarElementos() {
		link p = primero;
		int resultado = 0;
		while (p) {
			resultado += p->tamano;
			p = p->siguiente;
		}
		return resultado;
	}
	void shiftLeft(link p, int pos) {
		link aux = p;
		while (p->siguiente) {
			if (pos + 1 == p->tamano) {
				p->elemento[pos] = p->siguiente->elemento[0];
				p = p->siguiente;
				pos = 0;
			}
			else {
				p->elemento[pos] = p->elemento[pos + 1];
				pos++;
			}
		}
		for (int i = 0; i < p->tamano; i++) {
			p->elemento[i] = p->elemento[i + 1];
		}
		while (aux->siguiente != p) {
			aux = aux->siguiente;
		}
		p->tamano--;
		if (aux->siguiente->tamano == 0) {
			aux->siguiente = nullptr;
			delete(p);
		}
	}

public:

	ListB(string nombre);
	int len();
	void push_front(T x);
	void push_back(T x);
	void insertar(int pos, T x);
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
	if (!primero) {
		primero = new Nodo(x, primero);
		tam++;
	}
	else {
		link p;
		for (p = primero; p->siguiente; p = p->siguiente) {}
		if (p->tamano < p->maxSize) {
			p->elemento[p->tamano]=x;
			p->tamano++;
		}
		else {
			p->siguiente = new Nodo(x);
			tam++;
		}
	}
}

template<class T, int N>
void ListB<T, N>::insertar(int pos, T x) {
	if (!primero) {
		primero = new Nodo(x);
		tam++;
	}
	else {
		if (pos==0) {
			push_front(x);
		}
		else {
			if (pos > contarElementos() - 1) {
				push_back(x);
			}
			else {
				link p = primero;
				while (p->tamano < pos + 1) {
					pos -= p->tamano;
					p = p->siguiente;
				}
				shiftRight(p, pos);
				p->elemento[pos] = x;
			}
		}
	}
}
template<class T, int N>
bool ListB<T, N>::remove(int pos, T & x)
{
	if (!primero) {
		return false;
	}
	else {
		if (pos > contarElementos() - 1) {
			int m;
			pop_back(m);
		}
		else {
			link p = primero;
			while (p->tamano < pos + 1) {
				pos -= p->tamano;
				p = p->siguiente;
			}
			x = p->elemento[pos];
			shiftLeft(p, pos);
			return true;
		}
	}
}

template<class T, int N>
bool ListB<T, N>::pop(T & x)
{
	if (!primero) {
		return false;
	}
	link p = primero;
	x = p->elemento[0];
	shiftLeft(p, 0);
	return true;
}

template<class T, int N>
bool ListB<T, N>::pop_back(T & x)
{
	if (!primero) {
		return false;
	}
	link aux = primero;
	link p = primero;
	while (aux->siguiente) {
		aux = aux->siguiente;
	}
	while (p->siguiente != aux) {
		p = p->siguiente;
	}
	aux->tamano--;
	x = aux->elemento[aux->tamano];
	if (aux->tamano == 0) {
		delete(aux);
		p->siguiente = nullptr;
	}
	return true;
}

template<class T, int N>
bool ListB<T, N>::get(int pos, T & element)
{
	if (!primero) {
		return false;
	}
	link aux = primero;
	if (pos > contarElementos() - 1) {
		get_back(element);
		return true;
	}
	if (pos == 0) {
		get_front(element);
		return true;
	}
	while (pos + 1 > aux->tamano) {
		pos -= aux->tamano;
		aux = aux->siguiente;
	}
	element = aux->elemento[pos];
	return true;
}

template<class T, int N>
bool ListB<T, N>::get_front(T & element)
{
	if (!primero) {
		return false;
	}
	element = primero->elemento[0];
	return true;
}

template<class T, int N>
bool ListB<T, N>::get_back(T & element)
{
	if (!primero) {
		return false;
	}
	link aux = primero;
	while (aux->siguiente) {
		aux = aux->siguiente;
	}
	element = aux->elemento[aux->tamano-1];
	return true;
}

template<class T, int N>
void ListB<T,N>::print() {
	cout << "--------" << nombreLista << "--------" << endl;
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
	cout << "-----Fin de Lista-----" << endl;
}

template<class T, int N>
int ListB<T,N>::len() {
	return contarElementos();
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


