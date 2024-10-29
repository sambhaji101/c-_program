// ProtoType.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Shape 
{
public :
    virtual Shape* Clone() = 0;
    virtual void draw() = 0;
    virtual ~Shape() {};
};
class Circle : public Shape
{
    int radious;
public:
    Circle(int rad) : radious(rad) {}
    Shape* Clone()
    {
        return new Circle(*this);

    }
    void draw()
    {
        cout << "Creating Circle" << endl;
    }
};

class Rectangle : public Shape
{
    int length,breadth;
public:
    Rectangle(int len, int brdth) : length(len), breadth(brdth) {}
    Shape* Clone()
    {
        return new Rectangle(*this);

    }
    void draw()
    {
        cout << "Creating Rectangle" << endl;
    }
};

int main()
{
    Circle circlePrototype(5);
    Rectangle rectanglePrototype(4, 6);
    Shape* ShapeCicle = circlePrototype.Clone();
    ShapeCicle->draw();

    Shape* ShapeRect = rectanglePrototype.Clone();
    ShapeRect->draw();

    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
