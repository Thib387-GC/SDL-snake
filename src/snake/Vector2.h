#pragma once

class Vector2
{
	

public:
	float x;
	float y;
	Vector2(float v_x, float v_y);

	float GetX() const;
	float GetY() const;
	void SetX(float v_x);
	void SetY(float v_y);

	float CalculeNorme() const;

	Vector2 operator+=(Vector2 v_vector);
	Vector2 operator-=(Vector2 v_vector);
	Vector2 operator/=(float v_value);
	Vector2 operator*=(float v_value);

	Vector2 operator+(const Vector2& v_vector) const;
	Vector2 operator-(Vector2 v_vector);
	Vector2 operator/(float v_value);
	Vector2 operator*(float v_value);

	bool operator<(Vector2 v_vector);
	bool operator>(Vector2 v_vector);
	bool operator<=(Vector2 v_vector);
	bool operator>=(Vector2 v_vector);
	bool operator==(const Vector2& v_vector) const;
};
