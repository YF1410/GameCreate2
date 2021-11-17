#include "Vector3.h"

Vector3::Vector3() :Vector3(0, 0, 0) {}

Vector3::Vector3(float x, float y, float z) : XMFLOAT3{ x,y,z } {}

const float Vector3::length() {
	return sqrt(x * x + y * y + z * z);
}

Vector3& Vector3::normalize() {
	float len = length();
	if (len != 0) {
		return *this /= len;
	}
	return *this;
}

const float Vector3::dot(const Vector3& v) {
	return x * v.x + y * v.y + z * v.z;
}

const Vector3 Vector3::cross(const Vector3& v) {
	Vector3 temp;
	temp.x = this->y * v.z - this->z * v.y;
	temp.y = this->z * v.x - this->x * v.z;
	temp.z = this->x * v.y - this->y * v.x;
	return temp;
}

const Vector3 Vector3::operator+() {
	return *this;
}

const Vector3 Vector3::operator-() {
	return Vector3(-x, -y, -z);
}

Vector3& Vector3::operator+=(const Vector3& v) {
	x += v.x;
	y += v.y;
	z += v.z;
	return *this;
}

Vector3& Vector3::operator-=(const Vector3& v) {
	x -= v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}

Vector3& Vector3::operator*=(float s) {
	x *= s;
	y *= s;
	z *= s;
	return *this;
}

Vector3& Vector3::operator/=(float s) {
	x /= s;
	y /= s;
	z /= s;
	return *this;
}

const Vector3 operator+(const Vector3& v1, const Vector3& v2) {
	Vector3 w;
	w.x = v1.x + v2.x;
	w.y = v1.y + v2.y;
	w.z = v1.z + v2.z;
	return w;
}

const Vector3 operator-(const Vector3& v1, const Vector3& v2) {
	Vector3 w;
	w.x = v1.x - v2.x;
	w.y = v1.y - v2.y;
	w.z = v1.z - v2.z;
	return w;
}

const Vector3 operator*(const Vector3& v, float s) {
	Vector3 w;
	w.x = v.x * s;
	w.y = v.y * s;
	w.z = v.z * s;
	return w;
}

const Vector3 operator*(float s, const Vector3& v) {
	Vector3 w;
	w.x = v.x * s;
	w.y = v.y * s;
	w.z = v.z * s;
	return w;
}

const Vector3 operator/(const Vector3& v, float s) {
	Vector3 w;
	w.x = v.x / s;
	w.y = v.y / s;
	w.z = v.z / s;
	return w;
}

//���`���
const Vector3 lerp(const Vector3& start, const Vector3& end, const float t) {
	return start * (1.0 - t) + end * t;
}

const Vector3 easeInQuad(const Vector3& start, const Vector3& end, const float t) {
	return start + (end - start) * (t * t);
}

const Vector3 easeOutQuad(const Vector3& start, const Vector3& end, const float t) {
	return start + (end - start) * (1 - (1 - t) * (1 - t));
}

const Vector3 easeInOutQuad(const Vector3& start, const Vector3& end, const float t) {
	return start + (end - start) * (t < 0.5 ? 2 * t * t : 1 - pow(-2 * t + 2, 2) / 2);
}

const Vector3 easeInQuint(const Vector3& start, const Vector3& end, const float t) {
	return start + (end - start) * pow(t, 5);
}

const Vector3 easeOutQuint(const Vector3& start, const Vector3& end, const float t) {
	return start + (end - start) * (1 - pow(1 - t, 5));
}

const Vector3 easeInOutQuint(const Vector3& start, const Vector3& end, const float t) {
	return start + (end - start) * (t < 0.5 ? 16 * pow(t, 5) : 1 - pow(-2 * t + 2, 5) / 2);
}