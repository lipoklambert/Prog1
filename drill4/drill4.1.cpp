#include "Graph.h"
#include "Simple_window.h"
#include "Window.h"

using namespace Graph_lib;

/*g++ drill4.1.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o drill4.1 `fltk-config --ldflags --use-images`
*/

double one(double x) {return 1;}
double slope(double x) {return x/2;}
double square(double x) {return x*x;}
double sloping_cos(double x) {return cos(x)+slope(x);}

int main(){
try{
	Point p {100, 100};
	
	Simple_window win {p, 600, 600, "Function graphs"};
	win.wait_for_button();
	
	Axis xa {Axis::x, Point{100, 300}, 400, 20, "1 == 20 pixels"};
	
	xa.set_color(Color::red);
	win.attach(xa);
	
	Axis ya {Axis::y, Point{300, 500}, 400, 20, "1 == 20 pixels"};
	
	ya.set_color(Color::red);
	win.attach(ya);
	win.set_label("Axis");
	win.wait_for_button();
	
	Function f {one, -10, 11, Point{300, 300}, 400, 20, 20};
	
	win.attach(f);
	win.set_label("Function graphs");
	win.wait_for_button();
	
	Function f2 {slope, -10, 11, Point{300, 300}, 400, 20, 20};
	
	win.attach(f2);
	win.set_label("Function graphs");
	win.wait_for_button();
	
	Text f2_text {Point{100, 380}, "x/2"};
	
	win.attach(f2_text);
	win.set_label("Text");
	win.wait_for_button();
	
	Function f3 {square, -10, 11, Point{300, 300}, 400, 20, 20};
	
	win.attach(f3);
	win.set_label("Function graphs");
	win.wait_for_button();
	
	Function cosine {cos, -10, 11, Point{300, 300}, 400, 20, 20};
	
	cosine.set_color(Color::blue);
	win.attach(cosine);
	win.set_label("Function graphs");
	win.wait_for_button();
	
	Function f4 {sloping_cos, -10, 11, Point{300, 300}, 400, 20, 20};
	
	win.attach(f4);
	win.set_label("Function graphs");
	win.wait_for_button();
}

catch(exception& e){
	cerr << e.what() << '\n';
	return 1;
}

catch(...){
	cerr << "Error" << '\n';
	return 2;
}
}
