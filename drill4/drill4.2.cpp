#include <iostream>
#include <string>
#include <vector> 
#include <stdexcept>

using namespace std;

class Person{
public:
	vector<char> v {';', ':', '"', '[', ']', '@', '&', '$', '\'', '!', '%', '*', '^', '#'};
	Person() {}
	//Person(string name, int age) : n{name}, a{age}
	Person(string first, string last, int age) : f{first}, l{last}, a{age} {	//konstruktor
		if (age < 0 || age >= 150) {
			throw runtime_error ("Invalid age!");
		}
		
		string name = first + last;
		
		for(int i = 0; i < name.length(); ++i){
			for(int j = 0; j < v.size(); ++j){
				if (v[j] == name[i]) {throw runtime_error ("Invalid name!");}
			}
		}
	};  
	int age() const {return a;} //getter      -> szükség van rá, hiszen az 'a' private lett
	string first() const {return f;} //getter
	string last() const {return l;}
private:
	//string n; 
	string f;
	string l;
	int a;
};

ostream& operator<<(ostream& os, const Person& p){	//operátor túlterhelés   (bináris)
	return os << p.first() << ' ' << p.last() << ' ' << p.age();
}

istream& operator>>(istream& is, Person& p){
	string f;
	string l; 
	int a;
	
	is >> f >> l >> a;
	p = Person(f, l, a);
	return is;
}

int main(){

	Person p;
	/*p.name = "Goofy";
	p.age = 63;*/
	
	p = Person("Goofy", "Goober", 63);
	
	cout << p.first() << ' ' << p.last() << ' ' << p.age() << endl;
	
	Person p2;
	
	cin >> p2;
	cout << p2 << endl;
	
	vector<Person> vec;
	
	for(Person p; cin >> p;){
		if(p.first() == "end") break;
		vec.push_back(p);
	}
	
	for(Person p : vec){	//foreach
		cout << p << endl;
	}

}
