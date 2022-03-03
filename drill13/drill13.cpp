#include "./GUI/Simple_window.h"
#include "./GUI/Graph.h"

#include <iostream>
#include <string>


using namespace Graph_lib;


int main() {

    try {

            Point t1 {300,50};
            Simple_window win {t1, 1000, 800, "My Window"};
            win.wait_for_button();

            int x_size=800;
            int y_size=800;
            Lines grid;

            for (int i=0; i<=800; i+=100)
            {
                grid.add(Point(i,0), Point(i, y_size));
                grid.add(Point(0,i), Point(x_size, i));
            }

            win.attach(grid);
            win.wait_for_button();

            Graph_lib::Rectangle r1 {Point{0,0}, 100, 100};
            r1.set_fill_color(Color::red);
            win.attach(r1);
            Graph_lib::Rectangle r2 {Point{100,100}, 100, 100};
            r2.set_fill_color(Color::red);
            win.attach(r2);
            Graph_lib::Rectangle r3 {Point{200,200}, 100, 100};
            r3.set_fill_color(Color::red);
            win.attach(r3);
            Graph_lib::Rectangle r4 {Point{300,300}, 100, 100};
            r4.set_fill_color(Color::red);
            win.attach(r4);
            Graph_lib::Rectangle r5 {Point{400,400}, 100, 100};
            r5.set_fill_color(Color::red);
            win.attach(r5);
            Graph_lib::Rectangle r6 {Point{500,500}, 100, 100};
            r6.set_fill_color(Color::red);
            win.attach(r6);
            Graph_lib::Rectangle r7 {Point{600,600}, 100, 100};
            r7.set_fill_color(Color::red);
            win.attach(r7);
            Graph_lib::Rectangle r8 {Point{700,700}, 100, 100};
            r8.set_fill_color(Color::red);
            win.attach(r8);

            win.wait_for_button();

            Image kep1 (Point{0, 200}, "GUI/foka.jpg");
            Image kep2 (Point{200, 400}, "GUI/foka.jpg");
            Image kep3 (Point{400, 600}, "GUI/foka.jpg");
            win.attach(kep1);
            win.attach(kep2);  
            win.attach(kep3);

            win.wait_for_button();


            Image mozogakep (Point{0, 0}, "GUI/logo.jpg");
            mozogakep.set_mask(Point{0, 0}, 100, 100);
            win.attach(mozogakep);
            win.wait_for_button();
            for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 7; j++) {
            mozogakep.move(100, 0);
                win.attach(mozogakep);
                win.wait_for_button();
                if (i>=1 && j==6){
                    mozogakep.move(100, 0);
                    win.attach(mozogakep);
                    win.wait_for_button();
                }
            }
            mozogakep.move(-800, 100);
            win.attach(mozogakep);
        }


    }   catch (exception& e){
            cerr <<"exception: "<< e.what() <<'\n';
            return 1;
    }   catch (...){
            cerr <<"error\n";
            return 2;
    }

}
