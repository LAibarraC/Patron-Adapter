#include <iostream>
#include <math.h>

using namespace std;

class HoyoRodondo {
private:
	float radio;
public:
	HoyoRodondo(float _radio) {
		radio = _radio;
	}
	float getRadio() {
		return radio;
	}
};

class PiezaRedonda {
private:
	int radio;
public:
	PiezaRedonda(int _radio) {
		radio = _radio;	
	}
	int getRadio() {
		return radio;
	}
};

class PiezaCuadrada {
private:
	//anchura
	int ancho;
public:
	PiezaCuadrada(int _ancho) {
		ancho = _ancho;
	}
	int getAncho() {
		return ancho;
	}
};

class AdaptadorCuadrado :public PiezaRedonda{
private:
	PiezaCuadrada* pieza;

public:
	AdaptadorCuadrado(PiezaCuadrada* _pieza):PiezaRedonda(0) {
		pieza = _pieza;
		
	}
	int getRadio() {
		return pieza->getAncho()* sqrt(2) / 2;
	}
};

class PiezaTriangulo {
private:
	int a;
	int b;
	int c;
public:
	PiezaTriangulo(int _a, int _b, int _c) {
		a = _a;
		b = _b;
		c = _c;
	}
	int getancho() {
		return (a + b + c) / 3;
	}
};
class AdaptadorTriangulo :public PiezaRedonda {
private:
	PiezaTriangulo* triangulo;
public:
	AdaptadorTriangulo(PiezaTriangulo* _triangulo) :PiezaRedonda(0) {
		triangulo = _triangulo;
	}
	float getRadio() {
		return triangulo->getancho() / sqrt(3);
	}
};
int main(){
	PiezaCuadrada a1(3);
	AdaptadorCuadrado a(&a1);
	cout << "El radio del circulo y dentro hay un cuadrado de " << 3 << "x" << 3 << "x" << 3 <<"es:" << a.getRadio() << endl;
	PiezaTriangulo t(3, 3, 3);
	AdaptadorTriangulo t1(&t);
	cout << "el radio del circulo dentro hay un triangulo de " << 3 << "x" << 3 << "x" << 3 << " es:" << t1.getRadio()<<endl;
}
