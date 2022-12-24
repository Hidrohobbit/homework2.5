#include <iostream>
#include <string>

class Figure
{
public:

    std::string get_name()
    {
        return name;
    }

    int get_sides_count()
    {
        return sides_count;
    }

    Figure()
    {

    }

protected:

    int sides_count = 0;
    std::string name = "Фигура";

};

class Triangle: public Figure 
{
public:

    Triangle()
    {
        sides_count = 3;
        name = "Треугольник";
    }
};

class Quadrangle : public Figure
{
public:

    Quadrangle()
    {
        sides_count = 4;
        name = "Четырёхугольник";
    }
};


void print_info(Figure &figure)
{
    std::cout << figure.get_name() << ": " << figure.get_sides_count() << std::endl;
}
int main()
{
    setlocale(LC_ALL, "Russian");

    Figure fig;
    Triangle tri;
    Quadrangle qua;

    std::cout << "Количество сторон: " << std::endl;
    
    print_info(fig);
    print_info(tri);
    print_info(qua);

    return 0;
}


