#include <iostream>
#include <vector>
#include <memory>


class Shape {
public:
    virtual double getArea() const = 0; 
    virtual ~Shape() = default;
};

class Rectangle : public Shape {
protected:
    double width, height;

public:
    Rectangle(double width, double height) : width(width), height(height) {}

    double getArea() const override {
        return width * height;
    }
};

class Square : public Shape {
private:
    double side;

public:
    Square(double side) : side(side) {}

    double getArea() const override {
        return side * side;
    }
};

void printAreas(const std::vector<std::shared_ptr<Shape>>& shapes) {
    for (const auto& shape : shapes) {
        std::cout << "Area: " << shape->getArea() << std::endl;
    }
}

int main() {
 
    std::vector<std::shared_ptr<Shape>> shapes;
    shapes.push_back(std::make_shared<Rectangle>(5.0, 10.0)); 
    shapes.push_back(std::make_shared<Square>(4.0));          

    
    printAreas(shapes);

    return 0;
}
