#include <iostream>
#include <string>

class Figure 
{
public:

	virtual std::string   get_name() = 0;
	virtual std::string   get_side_length() = 0; //int sides_A, int sides_B, int sides_C
	virtual std::string   get_angle_values() = 0; //int angle_A, int angle_B, int angle_C

};


class Triangle: public Figure //Треугольник
{
public:

	std::string get_side_length() override
	{
		std::string out_string = "Стороны: a = " + std::to_string(sides_A) + " b = " + std::to_string(sides_B) + " c = " + std::to_string(sides_C)+ "\n";
		return out_string;
	}

	std::string get_angle_values() override
	{
		std::string out_string = "Углы: A = " + std::to_string(angle_A) + " B = " + std::to_string(angle_B)+ " C = " + std::to_string(angle_C)+ "\n";
		return out_string;
	}

	std::string get_name() override
	{
		return name;
	}

	Triangle()
	{
		sides_A = 10;
		sides_B = 20;
		sides_C = 30;

		angle_A = 50;
		angle_B = 60;
		angle_C = 70;

		name = "Треугольник";
	}
protected:

	//int sides_count = 3;
	//int angle_count = 3;

	int sides_A;
	int sides_B;
	int sides_C;

	int angle_A;
	int angle_B;
	int angle_C;

	std::string name;
};

class Rectangular_triangle: public Triangle //Прямоугольный треугольник
{
public:

	Rectangular_triangle()
	{
		sides_A = 10;
		sides_B = 20;
		sides_C = 30;

		angle_A = 50;
		angle_B = 60;
		angle_C = 90;
		name = "Прямоугольный треугольник";
	}
};

class Isosceles_triangle: public Triangle //Равнобедренный треугольник
{
public:
	Isosceles_triangle()
	{
		sides_A = 10;
		sides_B = 20;
		sides_C = 10;

		angle_A = 50;
		angle_B = 60;
		angle_C = 50;

		name = "Равнобедренный треугольник";
	}
};

class Equilateral_triangle: public Triangle //Равносторонний треугольник
{
public:
	Equilateral_triangle()
	{
		sides_A = 30;
		sides_B = 30;
		sides_C = 30;

		angle_A = 60;
		angle_B = 60;
		angle_C = 60;

		name = "Равносторонний треугольник";
	}
};


class Quadrangle : public Figure //Четырёхугольник
{
public:

	std::string get_side_length() override
	{
		std::string out_string = "Стороны: a = " + std::to_string(sides_A) + " b = " + std::to_string(sides_B) + " c = " + std::to_string(sides_C) + " d = " + std::to_string(sides_D) + "\n";
		return out_string;
	}

	std::string get_angle_values() override
	{
		std::string out_string = "Углы: A = " + std::to_string(angle_A) + " B = " + std::to_string(angle_B) + " C = " + std::to_string(angle_C) + " D = " + std::to_string(angle_D) + "\n";
		return out_string;
	}

	std::string get_name() override
	{
		return name;
	}

	Quadrangle()
	{
		sides_A = 10;
		sides_B = 20;
		sides_C = 30;
		sides_D = 40;

		angle_A = 50;
		angle_B = 60;
		angle_C = 70; 
		angle_D = 80;

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

class Rectangle: public Parallelogram //Прямоугольник
{
public:
	Rectangle()
	{
		sides_A = 10;
		sides_B = 20;
		sides_C = 10;
		sides_D = 20;

		angle_A = 90;
		angle_B = 90;
		angle_C = 90;
		angle_D = 90;
		name = "Прямоугольник";
	}
};

class Square: public Parallelogram //Квадрат
{
public:
	Square()
	{
		sides_A = 20;
		sides_B = 20;
		sides_C = 20;
		sides_D = 20;

		angle_A = 90;
		angle_B = 90;
		angle_C = 90;
		angle_D = 90;

		name = "Квадрат";
	}
};

class Parallelogram: public Quadrangle //Параллелограмм
{
public:
	Parallelogram()
	{
		sides_A = 20;
		sides_B = 30;
		sides_C = 20;
		sides_D = 30;

		angle_A = 30;
		angle_B = 40;
		angle_C = 30;
		angle_D = 40;

		name = "Параллелограмм";
	}
};

class Rhomb: public Parallelogram // Ромб
{
public:
	Rhomb()
	{
		sides_A = 30;
		sides_B = 30;
		sides_C = 30;
		sides_D = 30;

		angle_A = 30;
		angle_B = 40;
		angle_C = 30;
		angle_D = 40;

		name = "Ромб";
	}
};


int main()
{
	setlocale(LC_ALL, "Russian");


	return 0;
}