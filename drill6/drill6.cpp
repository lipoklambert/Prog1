#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename T>
/*A template kulcsszóval kell jeleznünk, hogy itt egy generikus valami fog következni, nem sima függvény/osztály (jelen esetben osztály).
typename T: template paraméterként ennek az osztálynak egy típust (typename) adunk, amit az osztályban T-nek hívunk. Ennek a T-nek a helyére fog a fordító igény szerint int-et, double-t vagy string-et helyettesíteni.
(vector is template-s osztály)*/
struct S{
	S(T vv = 0) : val{vv}{} //konstruktor
	T& get(); // így az S struktúra tudja, hogy lesz egy get függvénye, melyet később definiálunk
	void set(T new_t) {val = new_t;} //setter
	void operator=(const T& s);
	const T& get() const;
private:
	T val;
};

template<typename T>
T& S<T>::get() {return val;} //az S osztály, melynek van T típusú paraméter, annak a gettere

template<typename T>
const T& S<T>::get() const {return val;}

template<typename T>
void S<T>::operator=(const T& s){  //itt az egyenlőség unáris
	val = s;
}

template<typename T>
void read_val(T& v){	//fordítási időben derül ki a típus
	cin >> v;
}

template<typename T>
ostream& operator<<(ostream& os, vector<T>& v){
	os << "{ ";
	for(int i = 0; i < v.size(); ++i){
		os << v[i] << (i < v.size()-1 ? ", " : " ");
	}
	os << "}\n";
	return os;
}

template<typename T>
istream& operator>>(istream& is, vector<T>& v){
	char ch = 0;
	is >> ch;
	if(ch != '{'){
		is.unget();
		return is;
	}
	for(T val; is >> val;){
		v.push_back(val);
		is >> ch;
		if(ch != ',') break;
	}
	return is;
}

int main(){
	S<int> s; //S típusú objektum, mely int értéket vesz fel
	S<int> si {37};
	S<char> sc {'c'};
	S<double> sd {5.2};
	S<string> ss {"Hello"};
	S<vector<int>> svi {vector<int> {1, 1, 3, 5}};
	
	cout << "S<int> : " << s.get() << endl;
	cout << "S<int> : " << si.get() << endl;
	cout << "S<char> : " << sc.get() << endl;
	cout << "S<double> : " << sd.get() << endl;
	cout << "S<string> : " << ss.get() << endl;
	//cout << "S<vector<int>> : " << svi.val << endl;
	
	cout << "S<vector<int>> : ";
	for(auto& a : svi.get()){   //a az auto, tehát típusa futási időben derül ki
		cout << a << ' ';
	}
	cout << endl;
	
	sc.set('s');
	cout << "S<char> : " << sc.get() << endl;
	
	sd = 42.1;
	cout << "S<double> : " << sd.get() << endl;
	
	int ii;
	read_val(ii);
	S<int> si2 {ii};
	
	double dd;
	read_val(dd);
	S<double> sd2 {dd};
	
	string ss2;
	read_val(ss2);
	S<string> str {ss2};
	
	cout << "S<int> : " << si2.get() << endl;
	cout << "S<double> : " << sd2.get() << endl;
	cout << "S<string> : " << str.get() << endl;
	
	cout << "S<vector<int>> : (format: {val, val, val})  ";
	vector<int> vint;
	read_val(vint);
	S<vector<int>> svi2 {vint};
	cout << "S<vector<int>> : " << svi2.get();
}

