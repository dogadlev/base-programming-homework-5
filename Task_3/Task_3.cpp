// Homework 5. Task 3.

#include <iostream>
#include <string>
#include <clocale>

class Figure
{
protected:
    int sidesCount = 0;
    std::string name;
    virtual bool check()
    {
        return sidesCount == 0 ? true : false;
    }
    
public:
    Figure(std::string name, int sidesCount)
    {
        this->name = name;
        this->sidesCount = sidesCount;
    }
    Figure() {}
    int getSidesCount()
    {
        return sidesCount;
    }
    std::string getName()
    {
        return name;
    }
    virtual int getSideA() { return 0; }
    virtual int getSideB() { return 0; }
    virtual int getSideC() { return 0; }
    virtual int getSideD() { return 0; }
    virtual int getAngleA() { return 0; }
    virtual int getAngleB() { return 0; }
    virtual int getAngleC() { return 0; }
    virtual int getAngleD() { return 0; }
    virtual void print_info() 
    {
        std::cout << name << ":" << std::endl;
        std::cout << (check() ? "Правильная" : "Неправильная") << std::endl;
        std::cout << "Количество сторон: " << sidesCount << "\n\n";
    }
};

class Triangle : public Figure
{
protected:
    int sideA = 0;
    int sideB = 0;
    int sideC = 0;
    int angleA = 0;
    int angleB = 0;
    int angleC = 0;
    bool check() override
    {
        if (sidesCount == 3 && (angleA + angleB + angleC) == 180) { return true; }
        else { return false; }
    }

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
    int getSideA() override { return sideA; }
    int getSideB() override { return sideB; }
    int getSideC() override { return sideC; }
    int getAngleA() override { return angleA; }
    int getAngleB() override { return angleB; }
    int getAngleC() override { return angleC; }
    void print_info() override
    {
        std::cout << name << ":" << std::endl;
        std::cout << (check() ? "Правильная" : "Неправильная") << std::endl;
        std::cout << "Количество сторон: " << sidesCount << std::endl;
        std::cout << "Стороны: a=" << getSideA() << " b=" << getSideB() << " c=" << getSideC() << std::endl;
        std::cout << "Углы: A=" << getAngleA() << " B=" << getAngleB() << " C=" << getAngleC() << "\n\n";
    }
};

class RightTriangle : public Triangle
{
protected:
    bool check() override
    {
        if (Triangle::check() && angleC == 90) { return true; }
        else { return false; }
    }

public:
    RightTriangle(int sideA, int sideB, int sideC, int angleA, int angleB) : Triangle(sideA, sideB, sideC, angleA, angleB, 90)
    {
        name = "Прямоугольный треугольник";
    }
};

class IsoscelesTriangle : public Triangle
{
protected:
    bool check() override
    {
        if (Triangle::check() && angleA == angleC && sideA == sideC) { return true; }
        else { return false; }
    }

public:
    IsoscelesTriangle(int sideA, int sideB, int angleA, int angleB) : Triangle(sideA, sideB, sideA, angleA, angleB, angleA)
    {
        name = "Равнобедренный треугольник";
    }
};

class EquilateralTriangle : public Triangle
{
protected:
    bool check() override
    {
        if (Triangle::check() && angleA == angleC && angleA == angleB && sideA == sideC && sideA == sideB) { return true; }
        else { return false; }
    }

public:
    EquilateralTriangle(int sideA) : Triangle(sideA, sideA, sideA, 60, 60, 60)
    {
        name = "Равносторонний треугольник";
    }
};

class Quadrangle : public Figure
{
protected:
    int sideA = 0;
    int sideB = 0;
    int sideC = 0;
    int sideD = 0;
    int angleA = 0;
    int angleB = 0;
    int angleC = 0;
    int angleD = 0;
    bool check() override
    {
        if (sidesCount == 4 && (angleA + angleB + angleC + angleD) == 360) { return true; }
        else { return false; }
    }

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
    int getSideA() override { return sideA; }
    int getSideB() override { return sideB; }
    int getSideC() override { return sideC; }
    int getSideD() override { return sideD; }
    int getAngleA() override { return angleA; }
    int getAngleB() override { return angleB; }
    int getAngleC() override { return angleC; }
    int getAngleD() override { return angleD; }
    void print_info() override
    {
        std::cout << name << ":" << std::endl;
        std::cout << (check() ? "Правильная" : "Неправильная") << std::endl;
        std::cout << "Количество сторон: " << sidesCount << std::endl;
        std::cout << "Стороны: a=" << getSideA() << " b=" << getSideB() << " c=" << getSideC() << " d=" << getSideD() << std::endl;
        std::cout << "Углы: A=" << getAngleA() << " B=" << getAngleB() << " C=" << getAngleC() << " D=" << getAngleD() << "\n\n";
    }
};

class Parallelogram : public Quadrangle
{
protected:
    bool check() override
    {
        if (Quadrangle::check() && sideA == sideC && sideB == sideD && angleA == angleC && angleB == angleD) { return true; }
        else { return false; }
    }

public:
    Parallelogram(int sideA, int sideB, int angleA, int angleB) : Quadrangle(sideA, sideB, sideA, sideB, angleA, angleB, angleA, angleB)
    {
        name = "Параллелограмм";
    }
};

class Rectangle : public Parallelogram
{
protected:
    bool check() override
    {
        if (Quadrangle::check() && sideA == sideC && sideB == sideD && angleA == 90 && angleB == 90 && angleC == 90 && angleD == 90) { return true; }
        else { return false; }
    }

public:
    Rectangle(int sideA, int sideB) : Parallelogram(sideA, sideB, 90, 90)
    {
        name = "Прямоугольник";
    }
};

class Square : public Rectangle
{
protected:
    bool check() override
    {
        if (Quadrangle::check() && sideA == sideC && sideB == sideD && sideA == sideB && angleA == 90 && angleB == 90 && angleC == 90 && angleD == 90) { return true; }
        else { return false; }
    }

public:
    Square(int sideA) : Rectangle(sideA, sideA)
    {
        name = "Квадрат";
    }
};

class Rhombus : public Parallelogram
{
protected:
    bool check() override
    {
        if (Quadrangle::check() && sideA == sideC && sideB == sideD && sideA == sideB && angleA == angleC && angleB == angleD) { return true; }
        else { return false; }
    }

public:
    Rhombus(int sideA, int angleA, int angleB) : Parallelogram(sideA, sideA, angleA, angleB)
    {
        name = "Ромб";
    }
};


int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russian");

    Figure figure("Фигура", 0);
    figure.print_info();

    Triangle triangle(10, 20, 30, 50, 60, 70);
    triangle.print_info();

    RightTriangle rightTriangle(10, 20, 30, 50, 40);
    rightTriangle.print_info();
    
    IsoscelesTriangle isoscelesTriangle(10, 20, 50, 60);
    isoscelesTriangle.print_info();
    
    EquilateralTriangle equilateralTriangle(30);
    equilateralTriangle.print_info();
    
    Quadrangle quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
    quadrangle.print_info();

    
    Rectangle rectangle(10, 20);
    rectangle.print_info();
    
    Square square(20);
    square.print_info();
    
    Parallelogram parallelogram(20, 30, 30, 40);
    parallelogram.print_info();
    
    Rhombus rhombus(30, 30, 40);
    rhombus.print_info();

    return 0;
}