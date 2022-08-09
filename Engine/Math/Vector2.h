#pragma once
#include <cmath>
#include <cstdio>
#include <sstream>
#include <string>

namespace towr {
	struct Vector2 {
		float x, y;

		Vector2() : x{ 0 }, y{ 0 } {}
		Vector2(float x, float y) : x{ x }, y{ y } {}
		Vector2(float v) : x{ v }, y{ v } {}
		Vector2(int x, int y) : x{ (float)x }, y{ (float)y } {}

		void Set(float x, float y) { this->x = x; this->y = y; }

		// artthmetic operators
		// Vector2 = Vectors2 + Vectors2
		Vector2 operator + (const Vector2 & v) const { return Vector2{ this->x + v.x , this->y + v.y }; }
		Vector2 operator - (const Vector2 & v) const { return Vector2{ this->x - v.x , this->y - v.y }; }
		Vector2 operator * (const Vector2 & v) const { return Vector2{ this->x * v.x , this->y * v.y }; }
		Vector2 operator / (const Vector2 & v) const { return Vector2{ this->x / v.x , this->y / v.y }; }

		//vector 2 = Vector2 + float
		Vector2 operator + (float s) const { return Vector2{ this->x + s , this->y + s }; }
		Vector2 operator - (float s) const { return Vector2{ this->x - s , this->y - s }; }
		Vector2 operator * (float s) const { return Vector2{ this->x * s , this->y * s }; }
		Vector2 operator / (float s) const { return Vector2{ this->x / s , this->y / s }; }

		//assignment operators
		Vector2& operator += (const Vector2& v) { this->x += v.x, this->y += v.y; return *this; }
		Vector2& operator -= (const Vector2& v) { this->x -= v.x, this->y -= v.y; return *this; }
		Vector2& operator *= (const Vector2& v) { this->x *= v.x, this->y *= v.y; return *this; }
		Vector2& operator /= (const Vector2& v) { this->x /= v.x, this->y /= v.y; return *this; }
	
		//assignment operators float
		Vector2& operator += (float s) { this->x += s, this->y += s; return *this; }
		Vector2& operator -= (float s) { this->x -= s, this->y -= s; return *this; }
		Vector2& operator *= (float s) { this->x *= s, this->y *= s; return *this; }
		Vector2& operator /= (float s) { this->x /= s, this->y /= s; return *this; }

		//unary
		// Vector2 = -Vector2
		Vector2 operator - () { return Vector2{ -x, -y }; }

		//comparison
		//Vector2 == Vector2
		bool operator == (const Vector2& v) const { return (this->x == v.x && this->y == v.y); }
		bool operator != (const Vector2& v) const { return (this->x != v.x || this->y != v.y); }

		// functions
		float LengthSqr();
		float Length();

		float DistanceSqr(const Vector2& v);
		float Distance(const Vector2& v);

		Vector2 Noralized();
		void Normalize();

		float GetAngle();

		static Vector2 Rotate(const Vector2& v,float angle);

		friend std::istream& operator >> (std::istream&, Vector2& v);

		static const Vector2 one;
		static const Vector2 zero;
		static const Vector2 up;
		static const Vector2 down;
		static const Vector2 left;
		static const Vector2 right;
		
	};

	std::istream& operator >> (std::istream& stream, Vector2& v);

	inline float Vector2::LengthSqr() { return x * x + y * y; }
	inline float Vector2::Length() { return std::sqrt(x * x + y * y); }

	inline float Vector2::DistanceSqr(const Vector2& v) { return ((*this) - v).LengthSqr(); }
	inline float Vector2::Distance(const Vector2& v) { return ((*this) - v).Length(); }

	inline Vector2 Vector2::Noralized(){
		float length = Length();
		return (length == 0) ? Vector2(0, 0) : Vector2(x / length, y / length);
	}

	inline void Vector2::Normalize() { (*this) /= Length(); }

	inline float Vector2::GetAngle() { return std::atan2(y, x); }

	inline Vector2 Vector2::Rotate(const Vector2& v, float angle)
	{
		float x = v.x * std::cos(angle) - v.y * std::sin(angle);
		float y = v.x * std::sin(angle) + v.y * std::cos(angle);

		return Vector2{ x, y };
	}
}