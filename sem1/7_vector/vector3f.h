#include <cmath>
#include <iostream>

struct Vector3f {
    float x;
    float y;
    float z;
};

Vector3f operator+(const Vector3f& a, const Vector3f& b) { // сложение векторов
    Vector3f result = {a.x + b.x, a.y + b.y, a.z + b.z};
    return result;
}

Vector3f operator-(const Vector3f& a, const Vector3f& b) { // вычитание векторов
    Vector3f result = {a.x - b.x, a.y - b.y, a.z - b.z};
    return result;
}

Vector3f operator*(float a, const Vector3f& b) { // умножение число * вектор
    Vector3f result = {a * b.x, a * b.y, a * b.z};
    return result;
}

Vector3f operator*(const Vector3f& a, float b) { // умножение вектор * число
    Vector3f result = {b * a.x, b * a.y, b * a.z};
    return result;
}

Vector3f operator/(const Vector3f& a, float b) { // деление вектор / число
    Vector3f result = {a.x / b, a.y / b, a.z / b};
    return result;
}

float operator*(const Vector3f& a, const Vector3f& b) { // скалярное произведение
    int result = a.x * b.x + a.y * b.y + a.z * b.z;
    return result;
}

Vector3f operator+(const Vector3f& a) { // унарный +
    Vector3f result = a;
    return result;
}

Vector3f operator-(const Vector3f& a) { // унарный -
    Vector3f result;
    result.x = -a.x;
    result.y = -a.y;
    result.z = -a.z;
    return result;
}

bool operator==(const Vector3f& a, const Vector3f& b) { // проверка на равенство
    if (a.x == b.x && a.y == b.y && a.z == b.z)
        return true;
    else
        return false;
}

bool operator!=(const Vector3f& a, const Vector3f& b) { // проверка на неравенство
    if (a.x == b.x && a.y == b.y && a.z == b.z)
        return false;
    else
        return true;
}

Vector3f& operator+=(Vector3f &a, const Vector3f &b) { // оператор +=
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    return a;
}

Vector3f& operator-=(Vector3f &a, const Vector3f &b) { // оператор -=
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;
    return a;
}

Vector3f& operator*=(Vector3f &a, float b) { // оператор *=
    a.x *= b;
    a.y *= b;
    a.z *= b;
    return a;
}

Vector3f& operator/=(Vector3f &a, float b) { // оператор /=
    a.x /= b;
    a.y /= b;
    a.z /= b;
    return a;
}

std::istream& operator>>(std::istream& in, Vector3f& a) { // ввод вектора
    in >> a.x >> a.y >> a.z;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Vector3f& a) { // вывод вектора
    out << "(" << a.x << ", " << a.y << ", " << a.z << ")";
    return out;
}

float squaredNorm(const Vector3f& a) {
    return a * a;
}

float norm(const Vector3f& a) {
    return sqrt(squaredNorm(a));
}

void normalize(Vector3f& a) {
    a /= norm(a);
}