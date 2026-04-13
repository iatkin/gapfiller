#pragma once

#include <cstddef>
#include <iostream>
#include <boost/functional/hash.hpp>

struct Point{
    double x;
    double y;

    Point(double x, double y) : x(x), y(y) {}

    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }

    std::istream& operator>>(std::istream& is) {
        is >> x >> y;
        return is;
    }

    friend bool operator==(const Point& lhs, const Point& rhs) {
        return lhs.x == rhs.x && lhs.y == rhs.y;
    }

    friend std::size_t hash_value(const Point& p) {
        std::size_t seed = 0;
        boost::hash_combine(seed, p.x);
        boost::hash_combine(seed, p.y);
        return seed;
    }

    friend double distance(const Point& lhs, const Point& rhs) {
        return std::sqrt(std::pow(lhs.x - rhs.x, 2) + std::pow(lhs.y - rhs.y, 2));
    }
};

struct PointHash {
    std::size_t operator()(const Point& p) const {
        return hash_value(p);
    }
};

