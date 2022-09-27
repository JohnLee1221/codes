#include <iostream>
using namespace std;
#if 0
class Tom;
using Honey = Tom;
class Jack
{
    //friend class Tom;   // c++98标准
    friend Tom; // c++11标准
private:
    string name = "jack";
    void print()
    {
        cout << "my name is " << name << endl;
    }
};

class Lucy
{
    friend Honey;
protected:
    string name = "lucy";
    void print()
    {
        cout << "my name is " << name << endl;
    }
};

class Tom
{
public:
    void print()
    {
        cout << j.name << endl << l.name << endl;
        j.print();
        l.print();
    }
private:
    Jack j;
    Lucy l;
};

template<typename T>
class Rectangle
{
public:
    friend T;
    Rectangle(int w, int h) : width(w), height(h) {}
private:
    int width;
    int height;
};

template<typename T>
class Circle
{
public:
    friend T;
    Circle(int r) : radius(r) {}
private:
    int radius;
};

class Verify
{
public:
    Verify(int w, int h, Rectangle<Verify>& r)
    {
        if (r.width > w && r.height > h)
        {
            cout << "矩形的宽度和高度满足要求" << endl;
        }
        else
        {
            cout << "矩形的宽度和高度不满足要求......" << endl;
        }
    }

    Verify(int r, Circle<Verify>& c)
    {
        if (c.radius < r)
        {
            cout << "yuan的半径满足要求" << endl;
        }
        else
        {
            cout << "yuan的半径bu满足要求" << endl;
        }
    }
};


int main()
{
    Tom t;
    t.print();

    Rectangle<Verify> rect(100, 100);
    Circle<Verify> circle(90);
    Verify(100, 200, rect);
    Verify(50, circle);

    return 0;
}
#endif
