#ifndef SHAPES_H
#define SHAPES_H
#include <iostream>
#include <cmath>
#include <string>


class Point
{
    double x, y;

public:

    Point(void);
    Point(double new_x, double new_y);
    Point midpoint(const Point & other) const;

    void Output(void);
    void Input(void);

    double distance(const Point& other) const;
    

    double get_x(void) const {return x;}
    double get_y(void) const {return y;}

    void set_x(double new_x);
    void set_y(double new_y);


};

class Shape
{  
    protected:

    std::string name;

    public:

    Shape() : name("Unknown") {}
    Shape(const std::string& shape_name) : name(shape_name) {}
    virtual ~Shape() {}
    Shape & operator = (const Shape & shape)
    {
        if (this != &shape)
        {
            name = shape.name;
        }
        return *this;
    }

    Shape(const Shape& shape) : name(shape.name) {}
  
    virtual void print(std::ostream & out) const
    {
        out << "Shape: " << name;
    }
    virtual double area() const = 0;
    virtual double perimeter() const = 0;

    std::string get_name() const
    {
        return name;
    }

};

class One_D_Shape: public Shape
{
    protected:

    Point start_point;
    Point end_point;

    public:

    One_D_Shape() : Shape("Unknown") {}

    One_D_Shape(const std::string& shape_name, const Point& start, const
    Point& end) : Shape(shape_name), start_point(start),
    end_point(end) {}

    virtual ~One_D_Shape() {}
};

class Line : public One_D_Shape
{
    public:

    Line(const Point& start, const Point& end) : One_D_Shape("Line",start, 
    end){}
    Line(const Line& line) : One_D_Shape(line) {}
    
    virtual ~Line() {}

    double area() const override
    {
        return 0.0;
    }
    double perimeter() const override
    {
        return start_point.distance(end_point);
    }
    virtual void print(std::ostream & out) const override
    {
        out << "Line";
    }
};

class Curve : public One_D_Shape
{
    Point midpoint_point;

    public:
    
    Curve(const Point& start, const Point& midpoint, const Point& end) 
    : One_D_Shape("Curve", start, end), midpoint_point(midpoint) {}
    
    Curve(const Curve& curve) : One_D_Shape("Curve", curve.start_point,
    curve.end_point), midpoint_point(curve.midpoint_point) {}
  

    double area() const override
    {
        return 0.0;
    }

    double perimeter() const override
    {
        return 0.0;
    }

    virtual void print(std::ostream & out) const override
    {
        out << "Curve";
    }

};

class Two_D_Shape: public Shape
{
    public:

    virtual double area() const = 0;
    virtual double perimeter() const = 0;

     Two_D_Shape() : Shape("Unknown") {}

    Two_D_Shape(const std::string& shape_name) : Shape(shape_name) {}

    virtual ~Two_D_Shape() {}

};

class Circle : public Two_D_Shape
{
    double radius;
    Point center;

    public:

    Circle(double r) : Two_D_Shape("Circle"), radius(r), center() {}
    Circle(const Circle& circle) : Two_D_Shape(circle), 
    radius(circle.radius), center(circle.center) {}

    double area()const override
    {
        return M_PI * radius * radius;
    }
    double perimeter() const override
    {
        return 2 * M_PI * radius;
    }
    virtual ~Circle() {}

    virtual void print(std::ostream & out) const override
    {
        out << "Circle";
    }


};

class Rectangle : public Two_D_Shape
{
    double length, width;

    public:

    Rectangle(double len, double wid) : Two_D_Shape("Rectangle"), 
    length(len), width(wid) {}
    Rectangle(const Rectangle& rectangle) : Two_D_Shape(rectangle),
     length(rectangle.length), width(rectangle.width) {}

    double area() const override
    {
        return length * width;
    }
    double perimeter() const override
    {
        return 2 * (length + width);
    }

    virtual ~Rectangle() {}

    virtual void print(std::ostream & out) const override
    {
        out << "Rectangle";
    }


};

class Three_D_Shape: public Shape
{
    public:

    Three_D_Shape() : Shape("Unknown") {}

    Three_D_Shape(const std::string& shape_name) : Shape(shape_name) {}


};

class Sphere : public Three_D_Shape
{
    double radius;

    public:

    Sphere(double r) : radius(r) {}
    Sphere(const Sphere& sphere) : Three_D_Shape(sphere), 
    radius(sphere.radius) {}


    double area() const override
    {
        return 4 * M_PI * pow(radius, 2);
    }
    double perimeter() const override
    {
        return 0.0;
    }
    virtual ~Sphere() {}

    virtual void print(std::ostream & out) const override
    {
        out << "Sphere";
    }


};

class Cube : public Three_D_Shape
{
    double len_side;

    public:

    Cube(double side) : Three_D_Shape("Cube"), len_side(side) {}
    Cube(const Cube& cube) : Three_D_Shape(cube), len_side(cube.len_side) 
    {}
    virtual ~Cube() {}

    double area() const override
    {
        return 6 * len_side * len_side;
    }
    double perimeter() const override
    {
        return 4 * len_side;
    }

    virtual void print(std::ostream & out) const override
    {
        out << "Cube";
    }


};

class Cone : public Three_D_Shape
{
    double radius, height;

    public:

    Cone(double r, double h) : Three_D_Shape("Cone"), radius(r), 
    height(h) {}
    Cone(const Cone& cone) : Three_D_Shape(cone), radius(cone.radius),
    height(cone.height) {}
    virtual ~Cone() {}
    double area() const override
    {
        return M_PI * radius * (radius + sqrt(pow(height, 2)+ pow(radius,
        2)));
    }

    double perimeter() const override
    {
        return 2 * M_PI * radius;
    }

    virtual void print(std::ostream & out) const override
    {
        out << "Cone";
    }


};



#endif
