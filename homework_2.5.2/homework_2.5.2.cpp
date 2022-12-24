#include <iostream>
#include <string>

class Figure
{
public:
	virtual std::string   get_name() = 0;
	virtual std::string   get_side_length() = 0;  // Решил не создавать get_ методы для каждого поля. 
	virtual std::string   get_angle_values() = 0; // Виртуальные методы собирают информацию и формируют её в строку для вывода на экран 
};


class Triangle : public Figure //Треугольник
{
public:

	std::string get_side_length() override
	{
		return "Стороны: a = " + std::to_string(sides_A) + " b = " + std::to_string(sides_B) + " c = " + std::to_string(sides_C) + "\n";
	}

	std::string get_angle_values() override
	{
		return "Углы: A = " + std::to_string(angle_A) + " B = " + std::to_string(angle_B) + " C = " + std::to_string(angle_C) + "\n";
	}

	std::string get_name() override
	{
		return name + "\n";
	}

	Triangle(int sides_A, int sides_B, int sides_C, int angle_A, int angle_B, int angle_C)
	{
		this->sides_A = sides_A;
		this->sides_B = sides_B;
		this->sides_C = sides_C;

		this->angle_A = angle_A;
		this->angle_B = angle_B;
		this->angle_C = angle_C;

		name = "Треугольник";
	}
protected:
	int sides_A;
	int sides_B;
	int sides_C;

	int angle_A;
	int angle_B;
	int angle_C;

	std::string name;

};

class Rectangular_triangle : public Triangle //Прямоугольный треугольник
{
public:

	Rectangular_triangle(int sides_A, int sides_B, int sides_C, int angle_A, int angle_B) : Triangle(sides_A, sides_B, sides_C, angle_A, angle_B, 90)
	{
		name = "Прямоугольный треугольник";
	}
};

class Isosceles_triangle : public Triangle //Равнобедренный треугольник
{
public:
	Isosceles_triangle(int sides_A, int sides_B, int angle_A, int angle_B) : Triangle(sides_A, sides_B, sides_A, angle_A, angle_B, angle_A)
	{
		name = "Равнобедренный треугольник";
	}
};

class Equilateral_triangle : public Triangle //Равносторонний треугольник
{
public:
	Equilateral_triangle(int sides_A, int angle_A) : Triangle(sides_A, sides_A, sides_A, angle_A, angle_A, angle_A)
	{
		name = "Равносторонний треугольник";
	}
};

class Quadrangle : public Figure //Четырёхугольник
{
public:

	std::string get_side_length() override
	{
		return "Стороны: a = " + std::to_string(sides_A) + " b = " + std::to_string(sides_B) + " c = " + std::to_string(sides_C) + " d = " + std::to_string(sides_D) + "\n";
	}

	std::string get_angle_values() override
	{
		return "Углы: A = " + std::to_string(angle_A) + " B = " + std::to_string(angle_B) + " C = " + std::to_string(angle_C) + " D = " + std::to_string(angle_D) + "\n";
	}

	std::string get_name() override
	{
		return name + "\n";
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

		name = "Четырёхугольник";
	}

protected:
	int sides_A;
	int sides_B;
	int sides_C;
	int sides_D;

	int angle_A;
	int angle_B;
	int angle_C;
	int angle_D;

	std::string name;
};

class Parallelogram : public Quadrangle //Параллелограмм
{
public:
	Parallelogram(int sides_A, int sides_B, int angle_A, int angle_B) : Quadrangle(sides_A, sides_B, sides_A, sides_B, angle_A, angle_B, angle_A, angle_B)
	{
		name = "Параллелограмм";
	}
};

class Rectangle : Parallelogram //Прямоугольник
{
public:
	Rectangle(int sides_A, int sides_B) : Parallelogram(sides_A, sides_B, 90, 90)
	{
		name = "Прямоугольник";
	}
};

class Square : public Parallelogram //Квадрат
{
public:
	Square(int sides_A) : Parallelogram(sides_A, sides_A, 90, 90)
	{
		name = "Квадрат";
	}
};

class Rhomb : public Parallelogram //Ромб
{
public:
	Rhomb(int sides_A, int angle_A, int angle_B) : Parallelogram(sides_A, sides_A, angle_A, angle_B)
	{
		name = "Ромб";
	}
};

void print_info(Figure& figure)
{
	std::cout << figure.get_name() << figure.get_side_length() << figure.get_angle_values() << std::endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	Triangle tri(10, 20, 30, 50, 60, 70);
	Rectangular_triangle rec_tri(10, 20, 30, 50, 60);
	Isosceles_triangle iso_tri(10, 20, 50, 60);
	Equilateral_triangle equ_tri(30, 60);

	Quadrangle quad(10, 20, 30, 40, 50, 60, 70, 80);
	Parallelogram par_quad(20, 30, 30, 40);
	Rectangle rec_quad(10, 20);
	Square squ_quad(20);
	Rhomb rho_quad(30, 30, 40);


	print_info(tri);
	print_info(rec_tri);
	print_info(iso_tri);
	print_info(equ_tri);

	print_info(quad);
	print_info(par_quad);
	print_info(squ_quad);
	print_info(rho_quad);

	return 0;
}