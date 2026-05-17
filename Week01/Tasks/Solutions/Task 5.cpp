#include <iostream>

double myPower(double a, int exp) {
    double power = 1;
    while (exp)
    {
        power *= a;
        exp--;
    }
    return power;
}


struct Point {
    double x;
    double y;
    void read() {
        std::cin >> x >> y;
    }
    void print() const {
        std::cout << "This point has the following coordinates: (" << x << " ," << y << " )" << std::endl;
    }
    double distanceToCentre() const {
        double sum = myPower(x, 2) + myPower(y, 2);
        return sqrt(sum);
    }
    double distanceBetweenPoints(Point other) const {
        double distanceX = x - other.x;
        double distanceY = y - other.y;
        double sum = myPower(distanceX, 2) + myPower(distanceY, 2);
        return sqrt(sum);
    }
    int findQuadrant() {
        if (x == 0 || y == 0)
        {
            return 0;
        }
        if (x > 0)
        {
            return (y > 0) ? 1 : 4;
        }
        else
        {
            return (y > 0) ? 2 : 3;
        }
    }
};

int main()
{
    Point p1, p2;
    p1.read();
    std::cout << p1.distanceToCentre() << std::endl;

    std::cout << p1.findQuadrant() << std::endl;

    p2.read();
   std::cout << p1.distanceBetweenPoints(p2);
}
