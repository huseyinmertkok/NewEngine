#include "matrix4.h"


namespace newengine {namespace maths {
	
	Matrix4::Matrix4() {
		for (int i = 0; i < 4 * 4; i++) {
			elements[i] = 0.0f;
		}
	}

	Matrix4::Matrix4(float diagonal) {
		for (int i = 0; i < 4 * 4; i++) {
			elements[i] = 0.0f;
		}

		elements[0 + 0 * 4] = diagonal; 
		elements[1 + 1 * 4] = diagonal;
		elements[2 + 2 * 4] = diagonal;
		elements[3 + 3 * 4] = diagonal;
	}

	Matrix4 Matrix4::identity() {
		return Matrix4(1.0f);
	}

	Matrix4& Matrix4::multiply(const Matrix4& other) {
		for (int y = 0; y < 4; y++) {
			for (int x = 0; x < 4; x++) {
				float sum = 0.0f;
				for (int i = 0; i < 4; i++) {
					sum += elements[x + i * 4] * other.elements[i + y * 4];
				}
				elements[x + y * 4] = sum;
			}
		}
		return *this;
	}

	Matrix4 operator*(Matrix4 left, const Matrix4& right) {
		return left.multiply(right);
	}

	Matrix4 Matrix4::operator*=(const Matrix4& other) {
		return multiply(other);
	}

	Matrix4 Matrix4::orthographic(float left, float right, float bottom, float top, float near, float far) {
		Matrix4 result(1.0f);
		result.elements[0 + 0 * 4] = 2.0f / (right - left);
		result.elements[1 + 1 * 4] = 2.0f / (top - bottom);
		result.elements[2 + 2 * 4] = 2.0f / (near - far);
		
		result.elements[0 + 3 * 4] = (left + right) / (left - right);
		result.elements[1 + 3 * 4] = (bottom + top) / (bottom - top);
		result.elements[2 + 3 * 4] = (far + near) / (far - near);
		
		return result;
	}


	Matrix4 Matrix4::perspective(float fov, float aspectRatio, float near, float far) {
		Matrix4 result;

		float q = 1.0f / tan(toRadians(0.5f * fov));

		result.elements[0 + 0 * 4] = q / aspectRatio;
		result.elements[1 + 1 * 4] = q;
		result.elements[2 + 2 * 4] = (far + near) / (near - far);
		result.elements[2 + 3 * 4] = (2.0f * far * near) / (near - far);
		result.elements[3 + 2 * 4] = -1.0f;

		return result;
	}

	Matrix4 Matrix4::translation(const Vector3& translation) {
		Matrix4 result(1.0f);

		result.elements[0 + 3 * 4] = translation.x;
		result.elements[1 + 3 * 4] = translation.y;
		result.elements[2 + 3 * 4] = translation.z;

		return result;
	}

	Matrix4 Matrix4::rotation(float angle, const Vector3& axis) {
		Matrix4 result(1.0f);

		float r = toRadians(angle);
		float c = cos(r);
		float s = sin(r);
		float omc = 1.0f - c;

		float x = axis.x;
		float y = axis.y;
		float z = axis.z;

		result.elements[0 + 0 * 4] = x * x * omc + c;
		result.elements[1 + 0 * 4] = x * y * omc + s * z;
		result.elements[2 + 0 * 4] = x * z * omc - s * y;

		result.elements[0 + 1 * 4] = y * x * omc - s * z;
		result.elements[1 + 1 * 4] = y * y * omc + c;
		result.elements[2 + 1 * 4] = y * z * omc + s * x;

		result.elements[0 + 2 * 4] = z * x * omc + s * y;
		result.elements[1 + 2 * 4] = z * y * omc - s * x;
		result.elements[2 + 2 * 4] = z * z * omc + c;

		return result;
	}

	Matrix4 Matrix4::scale(const Vector3& scale) {
		Matrix4 result(1.0f);

		result.elements[0 + 0 * 4] = scale.x;
		result.elements[1 + 1 * 4] = scale.y;
		result.elements[2 + 2 * 4] = scale.z;

		return result;
	}

}}
