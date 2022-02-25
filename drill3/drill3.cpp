#include <iostream>
#include <string>

using namespace std;

class B1{
public:
	virtual void vf() {cout << "B1::vf()" << endl;}
	void f() {cout << "B1::f()" << endl;}
	virtual void pvf() = 0; /* teljesen virtuális, absztrakt függvény,
	 így az osztály is absztrakttá válik. Absztrakt osztály nem példányosítható.
	 A fordító hibát fog feldobni.*/
};

//Öröklődés, de vf() újból lesz definiálva (2. feladat)
class D1 : public B1 {
public:
	void vf() {cout << "D1::vf()" << endl;}
	void f() {cout << "D1::f()" << endl;}
};

class D2 : public D1{
public:
	void pvf() {cout << "D2::pvf()" << endl;}
};

class B2{
public:
	virtual void pvf() = 0;
};

class D21 : public B2 {
public:
	string s;
	void pvf() {cout << s << endl;}
};

class D22 : public B2 {
public:
	int n;
	void pvf() {cout << n << endl;}
};

//Függvény, melynek argumentuma egy B2 referencia és erre meghívja a pvf()-et
void f(B2& b2){
	b2.pvf();
}

int main(){

	/*B1 b1;
	b1.vf();
	b1.f();
	
	D1 d1;
	d1.vf();
	d1.f();
	
	B1& b1r = d1; -> B1 referencia, melyet a D1 objektumhoz inicializálunk
	b1r.vf();
	b1r.f();*/
	
	/*Amíg a D1-ben f() nics definiálva, output:
	B1::vf()
	B1::f()
	D1::vf()
	B1::f()
	D1::vf()
	B1::f()
	Miután D1-ben f() definiálva van, output:
	B1::vf()
	B1::f()
	D1::vf()
	D1::f()    -> ez a sor változott, mert f() újból lett definiálva D1-ben
	D1::vf()
	B1::f()*/
	
	D2 d2;
	d2.f();
	d2.vf();
	d2.pvf();
	
	/*B2 b2;
	b2.pvf();*/
	
	D21 d21;
	d21.s = "D21::pvf()";
	d21.pvf();
	
	D22 d22;
	d22.n = 1;
	d22.pvf();
	
	f(d21);
	f(d22);

}
