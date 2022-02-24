// g++ GUI/graph.cpp GUI/Window.cpp GUI/GUI.cpp GUI/Simple_window.cpp drill12.cpp `fltk-config --ldflags --use-images` -o a2.out
#include "GUI/Simple_window.h"
#include "GUI/Graph.h"

#include <string>
#include <iostream>

using namespace Graph_lib;

int main(){

	try {
		Point t1{100,100};
		Simple_window win {t1, 600, 400, "My window #1"};
		win.wait_for_button(); //gomb nyomásra vár

		//12.7.3.
		Axis xa {Axis::x, Point{20, 300}, 280, 10, "x axis"}; //x tengelyre pontot rajozolok ki
		win.attach(xa);

		win.set_label("My window #2");
		win.wait_for_button();

		Axis ya {Axis::y, Point{20, 300}, 280, 10, "y axis"};
		ya.set_color(Color::cyan);
		ya.label.set_color(Color::dark_red);
		win.attach(ya);

		win.set_label("My window #3");
		win.wait_for_button();

		Function sine {sin, 0, 100, Point{20, 150}, 1000, 50, 50}; //12.7.4 
		win.attach(sine);

		win.set_label("My window #4");
		win.wait_for_button();

		sine.set_color(Color::blue);

		Polygon poly;
		poly.add(Point{300, 200});
		poly.add(Point{350, 100});
		poly.add(Point{400, 200}); // 3szog

		poly.set_color(Color::red);
		poly.set_style(Line_style::dash); 
		win.attach(poly);
		win.set_label("My Window #5");
		win.wait_for_button();  //12.7.5

		Rectangle r {Point{200, 200}, 100, 50};
		win.attach(r);

		Closed_polyline poly_rect;
		poly_rect.add(Point{100, 50});
		poly_rect.add(Point{200, 50});
		poly_rect.add(Point{200, 100});
		poly_rect.add(Point{100, 100});
		poly_rect.add(Point{50, 75});
		win.attach(poly_rect);

		win.set_label("My Window #6");
                win.wait_for_button();

		r.set_fill_color(Color::yellow);
		poly.set_style(Line_style(Line_style::dash,4));
		poly_rect.set_style(Line_style(Line_style::dash,2));
		poly_rect.set_fill_color(Color::green);

		win.set_label("My Window #7");
		win.wait_for_button(); //12.7.7

		Text t {Point{150,150}, "Hello, graphical world!4!4!"};
		win.attach(t);

		win.set_label("My Window 8#");
		win.wait_for_button();

		t.set_font(Font::times_bold);
		t.set_font_size(20); 
		win.set_label("My Window 9#");
		win.wait_for_button();

		Image ii {Point(100,50), "GUI/badge.jpg"};
		win.attach(ii);
		win.set_label("My Window #10");
		win.wait_for_button();

		ii.move(100,200);
		win.set_label("My Window #11");
		win.wait_for_button(); //12.7.9

		Circle c {Point{100,200}, 50}; 
		Ellipse e {Point{100,200}, 75,25};
		e.set_color(Color::dark_red);
		Mark m {Point{100,200},'x'};

		ostringstream oss;
		oss <<"screen size: " << x_max() << y_max()
			<<"; window size: " << win.x_max() << "*" <<win.y_max();
		Text sizes {Point{100,20},oss.str()};

		Image cal {Point{255,225},"GUI/pluszegykep.jpg"};
		cal.set_mask(Point{40,40},200,150);
		win.attach(c);
		win.attach(m);
		win.attach(e);

		win.attach(sizes);
		win.attach(cal);
		win.set_label("My Window 11#");
		win.wait_for_button();

	} catch (exception& e){
		cerr << "exception: " << e.what() << '\n';
		return 1;
	} catch (...){
		cerr << "error\n";
		return 2;
	}
}
