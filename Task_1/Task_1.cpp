// Homework 5. Task 1.

#include <iostream>
#include <string>
#include <clocale>

class Figure 
{
private:
    std::string name;
    int sidesCount = 0;

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
};

class Triangle : public Figure 
{
public:
    Triangle(std::string name, int sidesCount) : Figure(name, sidesCount){}
};

class Quadrangle : public Figure 
{
public:
    Quadrangle(std::string name, int sidesCount) : Figure(name, sidesCount) {}
};

void outputResults(Figure* fig) 
{
    std::cout << fig->getName() << ": " << fig->getSidesCount() << std::endl;
}

void printTitle()
{
    std::cout << "Количество сторон:" << std::endl;
}

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russian");
    
    Figure figure("Фигура", 0);
    Triangle triangle("Треугольник", 3);
    Quadrangle quadrangle("Четырёхугольник", 4);
     
    printTitle();
    outputResults(&figure);
    outputResults(&triangle);
    outputResults(&quadrangle);
    
    return 0;
}