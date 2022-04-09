#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <fstream>
#include <numeric>
#include <algorithm>
#include <list>
#include <iterator>

using namespace std;

struct Item{
	string name;
	int iid;
	double value;
	
	Item(string n, int iid2 = 0, double v = 0.0) : name{n}, iid{iid2}, value{v} {}
};

//funktor az összehasonlításra
struct  comp_by_name {
	bool operator()(const Item& a, const Item& b) const
	{
        	return a.name < b.name;
	}
};

struct comp_by_iid {
	bool operator()(const Item& a, const Item& b) const
	{
	        return a.iid < b.iid;
	}
};

struct comp_by_value{
	bool operator()(const Item& a, const Item& b) const
	{
    		return a.value < b.value;
	}
};

class Find_by_name {
    string name;
public:
    Find_by_name(const string& s) :name(s) { }
    bool operator()(const Item& it) const
    {
        return it.name == name;
    }
};

class Find_by_iid {
    int iid;
public:
    Find_by_iid(int i) :iid(i) { }
    bool operator()(const Item& it) const
    {
        return it.iid == iid;
    }
};

void print(vector<Item> v){
	for(const auto& i : v){
    		cout << i.name << ' ' << i.iid << ' ' << i.value << endl;
    	}
}

void print_list(list<Item> l){
	for(const auto& i : l){
    		cout << i.name << ' ' << i.iid << ' ' << i.value << endl;
    	}
}

int main(){
try{
	const string iname {"input.txt"};
	ifstream ifs {iname};
	if(!ifs) throw runtime_error("Could not read file: " + iname);
	
	//vector rész
	cout << "Vector rész" << endl << endl;
	
	vector<Item> vi;
	for (int i = 0; i < 10; ++i) {
        	string a;
        	int b;
        	double c;
        	ifs >> a >> b >> c;
        	vi.push_back({a,b,c});
    	}
    	print(vi);
    	
    	sort(vi.begin(), vi.end(), comp_by_name());
    	cout << "Name szerinti rendezés után: " << endl;
    	print(vi);
    	
    	sort(vi.begin(), vi.end(), comp_by_iid());
    	cout << "Iid szerinti rendezés után: " << endl;
    	print(vi);
    	
    	sort(vi.begin(), vi.end(), comp_by_value());
    	reverse(vi.begin(), vi.end());
    	cout << "Value szerinti csökkenő rendezés után: " << endl;
    	print(vi);
    	
    	cout << endl;
    	vi.push_back({"horse shoe",99,12.34});
	vi.push_back({"Canon S400", 9988,499.95});
	
	print(vi);
	
	cout << endl;
	double cup_place = 0;
	double road_place = 0; 
	int a = 0;
	for(const auto& i : vi){
		if(i.name == "cup") {cup_place = a;}
		if(i.name == "road") {road_place = a;}
		++a;
	}
	vi.erase(vi.begin()+cup_place);
	vi.erase(vi.begin()+road_place);
	cout << "Road és cup törlése után:" << endl;
	print(vi);
	
	cout << endl;
	double twelve_place = 0;
	double twenty_one_place = 0; 
	int b = 0;
	for(const auto& i : vi){
		if(i.iid == 12) {twelve_place = b;}
		if(i.iid == 21) {twenty_one_place = b;}
		++b;
	}
	vi.erase(vi.begin()+twelve_place);
	vi.erase(vi.begin()+twenty_one_place);
	cout << "12 és 21 iid törlése után:" << endl;
	print(vi);
	
	//list rész
	
	cout << "List rész" << endl << endl;
	
	const string iname2 {"input.txt"};
	ifstream ifst {iname2};
	if(!ifst) throw runtime_error("Could not read file: " + iname2);
	
	list<Item> li;
	for (int i = 0; i < 10; ++i) {
        	string a;
        	int b;
        	double c;
        	ifst >> a >> b >> c;
        	li.push_back({a,b,c});
    	}
    	print_list(li);
    	
    	li.sort(comp_by_name());
    	cout << "Name szerinti rendezés után: " << endl;
    	print_list(li);
    	
    	li.sort(comp_by_iid());
    	cout << "Iid szerinti rendezés után: " << endl;
    	print_list(li);
    	
    	li.sort(comp_by_value());
    	reverse(li.begin(), li.end());
    	cout << "Value szerinti csökkenő rendezés után: " << endl;
    	print_list(li);
    	
    	cout << endl;
    	li.insert(li.end(),Item("Horsesh",99,12.34));
	li.insert(li.end(),Item("C S400",9988,499.95));
	
	print_list(li);
	
	cout << "Net és rose törlése után:" << endl;
	list<Item>::iterator li_it =
		find_if(li.begin(),li.end(),Find_by_name("net"));
	li.erase(li_it);
	li_it = find_if(li.begin(),li.end(),Find_by_name("rose"));
	li.erase(li_it);
	print_list(li);

	cout << "22 és 54 iid törlése után:" << endl;
	li_it = find_if(li.begin(),li.end(),Find_by_iid(22));
	li.erase(li_it);
	li_it = find_if(li.begin(),li.end(),Find_by_iid(54));
	li.erase(li_it);
	print_list(li);
	
}
catch(exception& e){
	cerr << e.what() << '\n';
	return 1;
}
catch(...){
	cerr << "Unknown exception!" << '\n';
	return 2;
}
}
