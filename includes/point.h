#ifndef POINT_H
#define POINT_H

struct Point {

    double x, y, z;

    Point();
    Point(double _x, double _y, double _z);

    bool operator>(const Point &other) const;
    bool operator<(const Point &other) const;
    bool operator==(const Point &other) const;
    bool operator!=(const Point &other) const;

    double distance(const Point &other) const;

};

#endif