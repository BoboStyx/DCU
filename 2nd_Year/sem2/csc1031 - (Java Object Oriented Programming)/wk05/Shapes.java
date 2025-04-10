import java.util.*;

abstract class Shape {
    protected String color;

    public Shape(String color) {
        this.color = color;
    }

    public abstract double getArea();

    public void displayColor() {
        System.out.println("Shape color: " + color);
    }
}

class Circle extends Shape {
    private double radius;

    public Circle(String color, double radius) {
        super(color);
        this.radius = radius >= 0 ? radius : 0;
    }

    @Override
    public double getArea() {
        return Math.PI * radius * radius;
    }
}

class Rectangle extends Shape {
    private double width;
    private double height;

    public Rectangle(String color, double width, double height) {
        super(color);
        this.width = width >= 0 ? width : 0;
        this.height = height >= 0 ? height : 0;
    }

    @Override
    public double getArea() {
        return width * height;
    }
}
