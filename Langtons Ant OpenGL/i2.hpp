#pragma once

class i2 {
public:
    int x, y;

    i2() {
        x = y = 0;
    }

    i2(const int x, const int y) {
        this->x = x;
        this->y = y;
    }

    i2(const float x, const float y) {
        this->x = (int)x;
        this->y = (int)y;
    }

    i2(const double x, const double y) {
        this->x = (int)x;
        this->y = (int)y;
    }

    i2 operator+(const int i) const {
        return i2{ x + i, y + i };
    }

    i2 operator-(const int i) const {
        return i2{ x - i, y - i };
    }

    i2 operator/(const int i) const {
        return i2{ x / i, y / i };
    }

    i2 operator*(const int i) const {
        return i2{ x * i, y * i };
    }

    i2 operator+(const i2& v) const {
        return i2{ x + v.x, y + v.y };
    }

    i2 operator-(const i2& v) const {
        return i2{ x - v.x, y - v.y };
    }

    i2 operator*(const i2& v) const {
        return i2{ x * v.x, y * v.y };
    }

    i2 operator/(const i2& v) const {
        return i2{ x / v.x, y / v.y };
    }

    i2& operator-=(const i2& v) {
        x -= v.x;
        y -= v.y;
        return *this;
    }

    i2& operator+=(const i2& v) {
        x += v.x;
        y += v.y;
        return *this;
    }

    i2& operator*=(const i2& v) {
        x *= v.x;
        y *= v.y;
        return *this;
    }

    i2& operator/=(const i2& v) {
        x /= v.x;
        y /= v.y;
        return *this;
    }

    i2& operator/=(const int i) {
        x /= i;
        y /= i;
        return *this;
    }

    i2& operator*=(const int i) {
        x *= i;
        y *= i;
        return *this;
    }

    i2& operator-=(const int i) {
        x -= i;
        y -= i;
        return *this;
    }

    i2& operator+=(const int i) {
        x += i;
        y += i;
        return *this;
    }

    bool operator==(const i2& v) const {
        return x == v.x && y == v.y;
    }

    bool operator!=(const i2& v) const {
        return !(*this == v);
    }

    std::string ToString() const {
        return "i2{" + std::to_string(x) + ", " + std::to_string(y) + "}";
    }
};