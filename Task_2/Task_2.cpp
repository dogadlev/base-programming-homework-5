// Homework 5. Task 2.

#include <iostream>
#include <string>
#include <clocale>

class Figure
{
protected:
    int sidesCount = 0;
    std::string name;

public:
    Figure(std::string name, int sidesCount)
    {
        this->name = name;
        this->sidesCount = sidesCount;
    }
    int getSidesCount()
    {
        return sidesCount;
    }
    std::string getName()
    {
        return name;
    }
    virtual void print() 
    {
        std::cout << "Количество сторон: " << getSidesCount();
    }
};

class Triangle : public Figure
{
private:
    int sideA = 0;
    int sideB = 0;
    int sideC = 0;
    int angleA = 0;
    int angleB = 0;
    int angleC = 0;

public:
    Triangle(std::string name, int sidesCount) : Figure(name, sidesCount) {}
    Triangle(int sideA, int sideB, int sideC, int angleA, int angleB, int angleC) : Triangle("Треугольник", 3)
    {
        this->sideA = sideA;
        this->sideB = sideB;
        this->sideC = sideC;
        this->angleA = angleA;
        this->angleB = angleB;
        this->angleC = angleC;
    }  
    void print() override 
    {
        std::cout << name << ":" << std::endl;
        std::cout << "Стороны: a=" << sideA << " b=" << sideB << " c=" << sideC << std::endl;
        std::cout << "Углы: A=" << angleA << " B=" << angleB << " C=" << angleC << "\n\n";
    }
};

class RightTriangle : public Triangle
{
public:
    RightTriangle(int sideA, int sideB, int sideC, int angleA, int angleB) : Triangle(sideA, sideB, sideC, angleA, angleB, 90) 
    {
        name = "Прямоугольный треугольник";
    }
};

class IsoscelesTriangle : public Triangle
{
public:
    IsoscelesTriangle(int sideA, int sideB, int angleA, int angleB) : Triangle(sideA, sideB, sideA, angleA, angleB, angleA) 
    {
        name = "Равнобедренный треугольник";
    }
};

class EquilateralTriangle : public Triangle
{
public:
    EquilateralTriangle(int sideA) : Triangle(sideA, sideA, sideA, 60, 60, 60)
    {
        name = "Равносторонний треугольник";
    }
};

class Quadrangle : public Figure
{
private:
    int sideA = 0;
    int sideB = 0;
    int sideC = 0;
    int sideD = 0;
    int angleA = 0;
    int angleB = 0;
    int angleC = 0;
    int angleD = 0;

public:
    Quadrangle(std::string name, int sidesCount) : Figure(name, sidesCount) {}
    Quadrangle(int sideA, int sideB, int sideC, int sideD, int angleA, int angleB, int angleC, int angleD) : Quadrangle("Четырёхугольник", 4)
    {
        this->sideA = sideA;
        this->sideB = sideB;
        this->sideC = sideC;
        this->sideD = sideD;
        this->angleA = angleA;
        this->angleB = angleB;
        this->angleC = angleC;
        this->angleD = angleD;
    }
    void print() override
    {
        std::cout << name << ":" << std::endl;
        std::cout << "Стороны: a=" << sideA << " b=" << sideB << " c=" << sideC << " d=" << sideD << std::endl;
        std::cout << "Углы: A=" << angleA << " B=" << angleB << " C=" << angleC << " D=" << angleD << "\n\n";
    }
};

class Parallelogram : public Quadrangle 
{
public:
    Parallelogram(int sideA, int sideB, int angleA, int angleB) : Quadrangle(sideA, sideB, sideA, sideB, angleA, angleB, angleA, angleB) 
    {
        name = "Параллелограмм";
    }
};

class Rectangle : public Parallelogram
{
public:
    Rectangle(int sideA, int sideB) : Parallelogram(sideA, sideB, 90, 90) 
    {
        name = "Прямоугольник";
    }
};

class Square : public Rectangle 
{
public:
    Square(int sideA) : Rectangle(sideA, sideA) 
    {
        name = "Квадрат";
    }
};

class Rhombus : public Parallelogram 
{
public:
    Rhombus(int sideA, int angleA, int angleB) : Parallelogram(sideA, sideA, angleA, angleB)
    {
        name = "Ромб";
    }
};

void print_info(Figure* fig)
{
    fig->print();
}


int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russian");

    Triangle triangle(10, 20, 30, 50, 60, 70);
    print_info(&triangle);

    RightTriangle rightTriangle(10, 20, 30, 50, 60);
    print_info(&rightTriangle);

    IsoscelesTriangle isoscelesTriangle(10, 20, 50, 60);
    print_info(&isoscelesTriangle);

    EquilateralTriangle equilateralTriangle(30);
    print_info(&equilateralTriangle);

    Quadrangle quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
    print_info(&quadrangle);

    Rectangle rectangle(10, 20);
    print_info(&rectangle);

    Square square(20);
    print_info(&square);

    Parallelogram parallelogram(20, 30, 30, 40);
    print_info(&parallelogram);

    Rhombus rhombus(30, 30, 40);
    print_info(&rhombus);

    return 0;
}