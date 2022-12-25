#include <iostream>
#include <string>

class Figure 
{
public:

    virtual void print_info()
    {
        if (bool_check())
        {
            std::cout << "\n" << name << "\n" << "Правильная" << "\n" << "Количество сторон: " << sides_count << std::endl;
        }
        else
        {
            std::cout << "\n" << name << "\n" << "Неправильная" << "\n" << "Количество сторон: " << sides_count << std::endl;
        }
    }

    Figure()
    {
        sides_count = 0;
        name = "Фигура";
    }

protected:

    virtual bool bool_check() //Не совсем понял зачем проверять условие Figure, ведь в конструкторе класса мы задаём количество сторон или всё же я неправильно понял ТЗ и количество сторон надо задавать при создании объекта ?
    {
        if (sides_count == 0)
        {
            return true;
        }
        else
        {
            return false;
        }// не правильнее ли просто вернуть true из метода bool_check , чтобы не городить конструкцию if else ? Естественно это при условии что нет необходимости вписывать количество сторон вручную.
    }

    int sides_count;
    std::string name;
};


class Triangle : public Figure //Треугольник
{
public:

    void print_info() override
    {
         if (bool_check())
         {
             Figure::print_info();
             std::cout << figure_info() << std::endl;
         }
         else
         {
             Figure::print_info();
             std::cout << figure_info() << std::endl;
         }
    }

    Triangle(int sides_A, int sides_B, int sides_C, int angle_A, int angle_B, int angle_C)
    {
        this->sides_A = sides_A;
        this->sides_B = sides_B;
        this->sides_C = sides_C;

        this->angle_A = angle_A;
        this->angle_B = angle_B;
        this->angle_C = angle_C;

        sides_count = 3;
        name = "Треугольник";
    }
protected:
    std::string figure_info()
    {
        return "Стороны: a = " + std::to_string(sides_A) + " b = " + std::to_string(sides_B) + " c = " + std::to_string(sides_C) + "\n" + "Углы: A = " + std::to_string(angle_A) + " B = " + std::to_string(angle_B) + " C = " + std::to_string(angle_C);
    }
    bool bool_check() override
    {
        if ( ((angle_A + angle_B + angle_C) == 180) &&(angle_A > 0 && angle_A < 180) && (angle_B > 0 && angle_B < 180) && (angle_C > 0 && angle_C < 180) && (sides_A > 0) && (sides_B > 0) && (sides_C > 0)) //проверка пограничных условий
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int sides_A;
    int sides_B;
    int sides_C;

    int angle_A;
    int angle_B;
    int angle_C;
};

class Rectangular_triangle : public Triangle //Прямоугольный треугольник
{
public:
    Rectangular_triangle(int sides_A, int sides_B, int sides_C, int angle_A, int angle_B, int angle_C) : Triangle(sides_A, sides_B, sides_C, angle_A, angle_B, angle_C)
    {
        name = "Прямоугольный треугольник";
    }
protected:
    bool bool_check() override
    {
        if (Triangle::bool_check())
        {
            if (angle_C == 90)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
};

class Isosceles_triangle : public Triangle //Равнобедренный треугольник
{
public:
    Isosceles_triangle(int sides_A, int sides_B, int sides_C, int angle_A, int angle_B, int angle_C) : Triangle(sides_A, sides_B, sides_C, angle_A, angle_B, angle_C)
    {
        name = "Равнобедренный треугольник";
    }
protected:
    bool bool_check() override
    {
        if (Triangle::bool_check())
        {
            if ((sides_A == sides_C) && (angle_A == angle_C))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
};

class Equilateral_triangle : public Triangle //Равносторонний треугольник
{
public:
    Equilateral_triangle(int sides_A, int sides_B, int sides_C, int angle_A, int angle_B, int angle_C) : Triangle(sides_A, sides_B, sides_C, angle_A, angle_B, angle_C)
    {
        name = "Равносторонний треугольник";
    }
protected:
    bool bool_check() override
    {
        if (Triangle::bool_check())
        {
            if ( (sides_A == sides_B) && (sides_A == sides_C) && (sides_B == sides_C) && (angle_A == angle_B) && (angle_A == angle_C) && (angle_B == angle_C)) //Проверка на равенство углов 60 не требуется, 180/3 == 60. 
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
};


class Quadrangle : public Figure //Четырёхугольник
{
public:

    void print_info() override
    {
        if (bool_check())
        {
            Figure::print_info();
            std::cout << figure_info() << std::endl;
        }
        else
        {
            Figure::print_info();
            std::cout << figure_info() << std::endl;
        }
    }

    Quadrangle(int sides_A, int sides_B, int sides_C, int sides_D, int angle_A, int angle_B, int angle_C, int angle_D)
    {
        this->sides_A = sides_A;
        this->sides_B = sides_B;
        this->sides_C = sides_C;
        this->sides_D = sides_D;

        this->angle_A = angle_A;
        this->angle_B = angle_B;
        this->angle_C = angle_C;
        this->angle_D = angle_D;

        sides_count = 4;
        name = "Четырёхугольник";
    }
protected:

    std::string figure_info()
    {
        return "Стороны: a = " + std::to_string(sides_A) + " b = " + std::to_string(sides_B) + " c = " + std::to_string(sides_C) + " d = " + std::to_string(sides_D) + "\n" + "Углы: A = " + std::to_string(angle_A) + " B = " + std::to_string(angle_B) + " C = " + std::to_string(angle_C) + " D = " + std::to_string(angle_D);
    }
    bool bool_check() override
    {
        if ( ((angle_A + angle_B + angle_C + angle_D) == 360) && (angle_A > 0 && angle_A < 180) && (angle_B > 0 && angle_B < 180) && (angle_C > 0 && angle_C < 180) && (angle_D > 0 && angle_D < 180) && (sides_A > 0) && (sides_B > 0) && (sides_C > 0) && (sides_D > 0)) //проверка пограничных условий
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int sides_A;
    int sides_B;
    int sides_C;
    int sides_D;

    int angle_A;
    int angle_B;
    int angle_C;
    int angle_D;
};

class Parallelogram : public Quadrangle //Параллелограмм
{
public:
    Parallelogram(int sides_A, int sides_B, int sides_C, int sides_D, int angle_A, int angle_B, int angle_C, int angle_D) : Quadrangle(sides_A, sides_B, sides_C, sides_D, angle_A, angle_B, angle_C, angle_D)
    {
        name = "Параллелограмм";
    }
protected:
    bool bool_check() override
    {
        if (Quadrangle::bool_check())
        {
            if ( (sides_A == sides_C) && (sides_B == sides_D) && (angle_A == angle_C) && (angle_B == angle_D))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
};

class Rectangle : public Parallelogram //Прямоугольник
{
public:
    Rectangle(int sides_A, int sides_B, int sides_C, int sides_D, int angle_A, int angle_B, int angle_C, int angle_D) : Parallelogram(sides_A, sides_B, sides_C, sides_D, angle_A, angle_B, angle_C, angle_D)
    {
        name = "Прямоугольник";
    }
protected:
    bool bool_check() override
    {
        if (Parallelogram::bool_check())
        {
            if ( (angle_A == 90) && (angle_B == 90) && (angle_C == 90) && (angle_D == 90))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
};

class Square : public Rectangle //Квадрат . В задании 2.5.2 был наследован от параллелограмма. Решение изменить наследование связано с методом bool_check --->
{
public:
    Square(int sides_A, int sides_B, int sides_C, int sides_D, int angle_A, int angle_B, int angle_C, int angle_D) : Rectangle(sides_A, sides_B, sides_C, sides_D, angle_A, angle_B, angle_C, angle_D)
    {
        name = "Квадрат";
    }
protected:
    bool bool_check() override // ---> убираем написание проверки для равенства всех углов 90 градусам так как она уже присутствует в "class Rectangle : public Parallelogram", остаётся проверить равенство пар (AC) && (BD).
    {
        if (Rectangle::bool_check())
        {
            if (sides_A == sides_B) // Этой проверки достаточно так как A уже равно С && B уже равно В. <--- эта проверка присутвует в "class Rectangle : public Parallelogram ---> bool_check" 
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
};

class Rhomb : public Parallelogram //Ромб
{
public:
    Rhomb(int sides_A, int sides_B, int sides_C, int sides_D, int angle_A, int angle_B, int angle_C, int angle_D) : Parallelogram(sides_A, sides_B, sides_C, sides_D, angle_A, angle_B, angle_C, angle_D)
    {
        name = "Ромб";
    }
protected:
    bool bool_check() override
    {
        if (Parallelogram::bool_check())
        {
            if (sides_A == sides_B) //Проверка равенства пар углов AC && BD присутствует в "class Parallelogram : public Quadrangle --> bool_check" там же присутсвует сравнение (A && C) && (B && D) остаётся проверить равенство пар (AC) && (BD).
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    Figure fig;
    Triangle tri(10, 20, 30, 50, 60, 70);
    Rectangular_triangle rec_tri(10, 20, 30, 40, 50, 90);
    Isosceles_triangle iso_tri(10, 20, 10, 50, 80, 50);
    Equilateral_triangle equ_tri(30, 30, 30, 60, 60, 60);

    Quadrangle quad(10, 20, 30, 40, 50, 60, 70, 80);
    Parallelogram par_quad(30, 40, 30, 40, 100, 80, 100, 80);
    Rectangle rec_quad(30, 40, 30, 40, 90, 90, 90, 90);
    Square squ_quad(20, 20, 20, 20, 90, 90, 90, 90);
    Rhomb rho_quad(40, 40, 40, 40, 100, 80, 100, 80);

    fig.print_info();
    tri.print_info();
    rec_tri.print_info();
    iso_tri.print_info();
    equ_tri.print_info();

    quad.print_info();
    par_quad.print_info();
    rec_quad.print_info();
    squ_quad.print_info();
    rho_quad.print_info();


    return 0;
}
