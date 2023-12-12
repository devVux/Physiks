#pragma once

#include <cstdint>
#include <ostream>

struct Vec2 {

	float x;
	float y;

	Vec2() = default;
	Vec2(float _x, float _y): x(_x), y(_y) { }

	static Vec2 Zero;
	static Vec2 UnitX;
	static Vec2 UnitY;

	inline Vec2& operator=(const Vec2& other) {
		if (&other != this) {
			x = other.x;
			y = other.y;
		}
		return *this;
	}

	inline friend Vec2 operator+(const Vec2& lhs, const Vec2& rhs) {
		return Vec2(lhs.x + rhs.x, lhs.y + rhs.y);
	}
	inline friend Vec2 operator-(const Vec2& lhs, const Vec2& rhs) {
		return Vec2(lhs.x - rhs.x, lhs.y - rhs.y);
	}
	inline friend Vec2 operator*(const Vec2& v, float a) {
		return Vec2(v.x * a, v.y * a);
	}
	inline friend Vec2 operator*(float a, const Vec2& v) {
		return Vec2(v.x * a, v.y * a);
	}
	
	inline friend Vec2& operator+=(Vec2& lhs, const Vec2& rhs) {
		lhs.x += rhs.x;
		lhs.y += rhs.y;
		return lhs;
	}	
	inline friend Vec2& operator-=(Vec2& lhs, const Vec2& rhs) {
		lhs.x -= rhs.x;
		lhs.y -= rhs.y;
		return lhs;
	}
	inline friend Vec2& operator*=(Vec2& v, float a) {
		v.x *= a;
		v.y *= a;
		return v;
	}
	inline friend Vec2& operator*=(float a, Vec2& v) {
		v.x *= a;
		v.y *= a;
		return v;
	}

};

inline bool operator==(const Vec2& lhs, const Vec2& rhs) { return lhs.x == rhs.x && lhs.y == rhs.y; }
inline bool operator!=(const Vec2& lhs, const Vec2& rhs) { return !(lhs == rhs); }

inline std::ostream& operator<<(std::ostream& os, const Vec2& v) {
	return os << '(' << v.x << ','  << ' ' << v.y << ')';
}


inline float dot(const Vec2& a, const Vec2& b) {
	return a.x * b.x + a.y * b.y;
}

Vec2 Vec2::Zero = Vec2(0.0f, 0.0f);
Vec2 Vec2::UnitX = Vec2(1.0f, 0.0f);
Vec2 Vec2::UnitY = Vec2(0.0f, 1.0f);