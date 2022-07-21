#include "vector3.h"

namespace newengine {namespace maths {

	//Constructors

	Vector3::Vector3() {
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}

	Vector3::Vector3(const float& x, const float& y, const float& z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	//Methods

	Vector3& Vector3::add(const Vector3& other) {
		x += other.x;
		y += other.y;
		z += other.z;

		return *this;
	}

	Vector3& Vector3::subtract(const Vector3& other) {
		x -= other.x;
		y -= other.y;
		z -= other.z;

		return *this;
	}

	Vector3& Vector3::multiply(const Vector3& other) {
		x *= other.x;
		y *= other.y;
		z *= other.z;

		return *this;
	}

	Vector3& Vector3::divide(const Vector3& other) {
		x /= other.x;
		y /= other.y;
		z /= other.z;

		return *this;
	}

	bool Vector3::equals(const Vector3& other) {
		return (x == other.x) && (y == other.y) && (z == other.z);
	}

	//Operators

	Vector3 operator+(Vector3 left, const Vector3& right) {
		return left.add(right);
	}

	Vector3 operator-(Vector3 left, const Vector3& right) {
		return left.subtract(right);
	}

	Vector3 operator*(Vector3 left, const Vector3& right) {
		return left.multiply(right);
	}

	Vector3 operator/(Vector3 left, const Vector3& right) {
		return left.divide(right);
	}

	Vector3& Vector3::operator+=(const Vector3& other) {
		return add(other);
	}

	Vector3& Vector3::operator-=(const Vector3& other) {
		return subtract(other);
	}

	Vector3& Vector3::operator*=(const Vector3& other) {
		return multiply(other);
	}

	Vector3& Vector3::operator/=(const Vector3& other) {
		return divide(other);
	}

	bool Vector3::operator==(const Vector3& other) {
		return equals(other);
	}

	bool Vector3::operator!=(const Vector3& other) {
		return !(equals(other));
	}

	std::ostream& operator<<(std::ostream& stream, const Vector3& vector) {
		stream << "Vector3: (" << vector.x << ", " << vector.y << ", " << vector.z << ")";
		return stream;
	}

}}