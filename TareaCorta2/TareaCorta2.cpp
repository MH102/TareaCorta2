// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "ListaSimple.h"
#include "ListB.h"
int main() {
	int n;
	List<int> lm("Lista1");
	
	lm.push_front(30);
	lm.push_front(20);
	lm.push_front(10);
	lm.push_back(40);
	lm.insertarR(5, 0);
	lm.insertarR(8, 1);
	lm.insertarR(15, 5);
	lm.insertarR(50, 99);
	lm.insertarR(999, 1);
	lm.print();
	List<string> la("Personas");
	la.push_back("ana");
	la.push_back("juan");
	la.print();
	lm.get(3, n);
	cout << "Get Pos 3: " << n << endl;
	lm.get_front(n);
	cout << "Get Front: " << n << endl;
	lm.get_back(n);
	cout << "Get Back: " << n << endl;
	lm.pop(n);
	cout << "Pop: " << n << endl;
	lm.print();
	lm.pop_back(n);
	cout << "Pop Back: " << n << endl;
	lm.print();
	lm.remove(5, n);
	cout << "Remove Pos 5: " << n << endl;
	lm.print();
	/*
	ListB<int,3> lm2("Lista1");

	lm2.push_back(2);
	lm2.push_back(3);
	lm2.push_back(4);
	lm2.push_back(5);
	lm2.push_back(7);
	lm2.push_back(8);
	lm2.push_front(1);
	lm2.insertar(5, 6);
	lm2.insertar(99, 9);
	lm2.insertar(4, 15);
	lm2.print();
	int m;
	lm2.remove(4, m);
	cout << "Remove Pos 4: " << m << endl;
	lm2.print();
	lm2.pop(m);
	cout << "Pop: " << m << endl;
	lm2.print();
	lm2.pop(m);
	cout << "Pop: " << m << endl;
	lm2.print();
	lm2.pop_back(m);
	cout << "Pop Back: " << m << endl;
	lm2.print();
	lm2.pop_back(m);
	cout << "Pop Back: " << m << endl;
	lm2.print();
	lm2.get(2, m);
	cout << "Get Pos 2: " << m << endl;
	lm2.get_back(m);
	cout << "Get Back: " << m << endl;
	lm2.get_front(m);
	cout << "Get Front: " << m << endl;
	*/
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
