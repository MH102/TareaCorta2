#pragma once
#include <iostream>
#include <string>
using namespace std;

template <class T>
class List {
private:
	struct Nodo {
		T elemento;
		struct Nodo * siguiente;
		Nodo(T x) :elemento{ x }, siguiente{ 0 } {}
		Nodo(T x, struct Nodo* sig) :elemento{ x }, siguiente{ sig } {}
	};

	typedef struct Nodo * link;

	link primero;		// Puntero al primer elemento de la lista
	int tam;			// Cantidad de elementos de la lista
	string nombreLista;	// Nombre de la lista

	// M�todo de clase 
	static void insertR(link &p, T x, int pos);

public:

	List(string nombre);
	int len();
	void push_front(T x);
	void push_back(T x);
	void insertar(T x, int pos);
	void insertarR(T x, int pos);
	bool remove(int pos, T& x);
	bool pop(T& x);
	bool pop_back(T& x);
	bool get(int pos, T& element);
	bool get_front(T& element);
	bool get_back(T& element);
	void print();
	~List();

};

template<class T>
void List<T>::insertR(link & p, T x, int pos) {
	if (p == NULL)
		p = new Nodo(x);
	else {
		if (pos == 0)
			p = new Nodo(x, p);
		else
			insertR(p->siguiente, x, pos - 1);
	}
}

template<class T>
List<T>::List(string nombre) {
	nombreLista = nombre;
	primero = NULL;
	tam = 0;
}

template <class T>
void List<T>::push_front(T x) {
	primero = new Nodo(x, primero);
	tam++;
}

template<class T>
void List<T>::push_back(T x) {
	if (!primero)
		primero = new Nodo(x, primero);
	else {
		link p;
		for (p = primero; p->siguiente; p = p->siguiente) {}
		p->siguiente = new Nodo(x);
	}
	tam++;
}

template<class T>
void List<T>::insertar(T x, int pos) {
	if (!primero) {
		primero = new Nodo(x);
	}
	else {
		if (pos == 0)
			primero = new Nodo(x, primero);
		else {
			link p = primero;
			while (p->siguiente && pos > 1) {
				p = p->siguiente;
				pos--;
			}
			p->siguiente = new Nodo(x, p->siguiente);
		}
	}
	tam++;
}

template<class T>
void List<T>::insertarR(T x, int pos) {
	insertR(primero, x, pos);
	tam++;
}

template<class T>
bool List<T>::remove(int pos, T & x)
{
	if (tam==0) {
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
			x = p->siguiente->elemento;
			p->siguiente = p->siguiente->siguiente;
			delete(aux);
			tam--;
			return true;
		}
	}
	return false;
}

template<class T>
bool List<T>::pop(T & x)
{
	if (!primero)
		return false;
	link aux = primero;
	primero = aux->siguiente;
	x = aux->elemento;
	tam--;
	delete(aux);
	return true;
}

template<class T>
bool List<T>::pop_back(T & x)
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
	x = aux->elemento;
	delete(aux);
	p->siguiente = nullptr;
	tam--;
	return true;
}

template<class T>
bool List<T>::get(int pos, T & element)
{
	if (!primero) {
		return false;
	}
	link aux = primero;
	while (aux->siguiente && pos > 0) {
		aux = aux->siguiente;
		pos--;
	}
	element = aux->elemento;
	return false;
}

template<class T>
bool List<T>::get_front(T & element)
{
	element = primero->elemento;
	return false;
}

template<class T>
bool List<T>::get_back(T & element)
{
	link aux = primero;
	while (aux->siguiente) {
		aux = aux->siguiente;
	}
	element = aux->elemento;
	return false;
}

template<class T>
void List<T>::print() {
	cout << nombreLista << " = [";
	if (primero) {
		link p = primero;
		cout << p->elemento;
		p = p->siguiente;
		while (p) {
			cout << ", " << p->elemento;
			p = p->siguiente;
		}
	}
	cout << "]" << endl;
}

template<class T>
int List<T>::len() {
	return tam;
}

template<class T>
List<T>::~List() {
	link p;
	while (primero) {
		// Borrra todos los elementos en la
		// lista.
		p = primero->siguiente;
		delete primero;
		primero = p;
	}
}


