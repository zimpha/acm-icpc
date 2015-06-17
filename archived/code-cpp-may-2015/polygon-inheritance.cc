class Rectangle : public Polygon {
public:
    Rectangle(double _width, double _height): Polygon(_width, _height) {}
    double area() {
        return width * height;
    }
};

class Triangle : public Polygon {
public:
    Triangle(double _width, double _height): Polygon(_width, _height) {}
    double area() {
        return width * height * 0.5;
    }
};
