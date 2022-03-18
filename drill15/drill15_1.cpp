#include "./GUI/Simple_window.h"
#include "./GUI/Graph.h"

struct Person {
    Person() : first_n(""), second_n(""), a(0) { }
    Person(string fn, string sn, int age) :first_n(fn), second_n(sn), a(age)
    {
        const string ill_chars = ";:\"'[]*&^%$#@!";
        for (int i = 0; i<fn.size(); ++i)
            for (int j = 0; j<ill_chars.size(); ++j)
                if (fn[i]==ill_chars[j]) error("nem jó a karakter: ",string(1,fn[i]));
        for (int i = 0; i<sn.size(); ++i)
            for (int j = 0; j<ill_chars.size(); ++j)
                if (sn[i]==ill_chars[j]) error("nem jó a karakter: ",string(1,sn[i]));
        if (a<0 || a>=150) error("kor 0 és 150 között");
    }
    string first_name() const { return first_n; }
    string second_name() const { return second_n; }
    int age() const { return a; }
private:
    string first_n;
    string second_n;
    int a;
};

istream& operator>>(istream& is, Person& p)
{
    string fname, sname;
    int age;
    is >> fname >> sname >> age;
    if (!is) return is;
    p = Person(fname,sname,age);
    return is;
}

ostream& operator<<(ostream& os, const Person& p)
{
    return os << "Név: " << p.first_name() << ' ' <<
        p.second_name() << ", Kor: " << p.age();
}

int main()
try {

    vector<Person> persons;
    Person p4;
    while (cin>>p4)
        persons.push_back(p4);
    for (int i = 0; i<persons.size(); ++i)
        cout << persons[i] << endl;

    keep_window_open("~");
}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
    keep_window_open();
}