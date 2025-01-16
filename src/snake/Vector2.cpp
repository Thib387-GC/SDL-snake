#include "Vector2.h"
#include <math.h>

Vector2::Vector2(float v_x, float v_y) {
	x = v_x;
	y = v_y;
}

float Vector2::GetX() const {
	return x;
}

float Vector2::GetY() const {
	return y;
}

void Vector2::SetX(float v_x) {
	x = v_x;
}

void Vector2::SetY(float v_y) {
	y = v_y;
}

float Vector2::CalculeNorme()const{
	return sqrt(pow(x, 2) + pow(y, 2));
}

Vector2 Vector2::operator+=(Vector2 v_vector) {
	x += v_vector.GetX();
	y += v_vector.GetY();
	return *this;
}

Vector2 Vector2::operator-=(Vector2 v_vector) {
	x -= v_vector.GetX();
	y -= v_vector.GetY();
	return *this;
}

Vector2 Vector2::operator/=(float v_value) {
	x /= v_value;
	y /= v_value;
	return *this;
}

Vector2 Vector2::operator*=(float v_value) {
	x *= v_value;
	y *= v_value;
	return *this;
}

Vector2 Vector2::operator+(const Vector2& v_vector) const {
	return Vector2(x + v_vector.GetX(), y + v_vector.GetY());
}

Vector2 Vector2::operator-(Vector2 v_vector) {
	x = x - v_vector.GetX();
	y = x - v_vector.GetY();
	return *this;
}

Vector2 Vector2::operator/(float v_value) {
	x = x / v_value;
	y = y / v_value;
	return *this;
}

Vector2 Vector2::operator*(float v_value) {
	x = x * v_value;
	y = y * v_value;
	return *this;
}

bool Vector2::operator<(Vector2 v_vector) {
	if (CalculeNorme() < v_vector.CalculeNorme()) {
		return true;
	}
}

bool Vector2::operator>(Vector2 v_vector) {
	if (CalculeNorme() > v_vector.CalculeNorme()) {
		return true;
	}
}

bool Vector2::operator<=(Vector2 v_vector) {
	if (CalculeNorme() <= v_vector.CalculeNorme()) {
		return true;
	}
}

bool Vector2::operator>=(Vector2 v_vector) {
	if (CalculeNorme() >= v_vector.CalculeNorme()) {
		return true;
	}
}

bool Vector2::operator==(const Vector2& v_vector) const {
	return x == v_vector.x && y == v_vector.y;
}