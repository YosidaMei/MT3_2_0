#include "Matrix.h"
#include <assert.h>

//1.行列の加法
Vector3 Add(const Vector3& v1, const Vector3& v2) {
	Vector3 Add;
	Add.x = v1.x + v2.x;
	Add.y = v1.y + v2.y;
	Add.z = v1.z + v2.z;
	return Add;
}

//2.減法
Vector3 Subtract(const Vector3& v1, const Vector3& v2) {
	Vector3 Subtract;
	Subtract.x = v1.x - v2.x;
	Subtract.y = v1.y - v2.y;
	Subtract.z = v1.z - v2.z;
	return Subtract;
}

//積
Vector3 Multiply(const Vector3& v1, const Vector3& v2) {
	Vector3 Multiply;
	Multiply.x = v1.x * v2.x;
	Multiply.y = v1.y * v2.y;
	Multiply.z = v1.z * v2.z;
	return Multiply;
}

//加算
Matrix4x4 Add(Matrix4x4 matrix1, Matrix4x4 matrix2) {
	Matrix4x4 Add;
	Add.m[0][0] = matrix1.m[0][0] + matrix2.m[0][0];
	Add.m[0][1] = matrix1.m[0][1] + matrix2.m[0][1];
	Add.m[0][2] = matrix1.m[0][2] + matrix2.m[0][2];
	Add.m[0][3] = matrix1.m[0][3] + matrix2.m[0][3];
	Add.m[1][0] = matrix1.m[1][0] + matrix2.m[1][0];
	Add.m[1][1] = matrix1.m[1][1] + matrix2.m[1][1];
	Add.m[1][2] = matrix1.m[1][2] + matrix2.m[1][2];
	Add.m[1][3] = matrix1.m[1][3] + matrix2.m[1][3];
	Add.m[2][0] = matrix1.m[2][0] + matrix2.m[2][0];
	Add.m[2][1] = matrix1.m[2][1] + matrix2.m[2][1];
	Add.m[2][2] = matrix1.m[2][2] + matrix2.m[2][2];
	Add.m[2][3] = matrix1.m[2][3] + matrix2.m[2][3];
	Add.m[3][0] = matrix1.m[3][0] + matrix2.m[3][0];
	Add.m[3][1] = matrix1.m[3][1] + matrix2.m[3][1];
	Add.m[3][2] = matrix1.m[3][2] + matrix2.m[3][2];
	Add.m[3][3] = matrix1.m[3][3] + matrix2.m[3][3];
	return Add;
}

//減算
Matrix4x4 Subtract(Matrix4x4 matrix1, Matrix4x4 matrix2) {
	Matrix4x4 Subtract;
	Subtract.m[0][0] = matrix1.m[0][0] - matrix2.m[0][0];
	Subtract.m[0][1] = matrix1.m[0][1] - matrix2.m[0][1];
	Subtract.m[0][2] = matrix1.m[0][2] - matrix2.m[0][2];
	Subtract.m[0][3] = matrix1.m[0][3] - matrix2.m[0][3];
	Subtract.m[1][0] = matrix1.m[1][0] - matrix2.m[1][0];
	Subtract.m[1][1] = matrix1.m[1][1] - matrix2.m[1][1];
	Subtract.m[1][2] = matrix1.m[1][2] - matrix2.m[1][2];
	Subtract.m[1][3] = matrix1.m[1][3] - matrix2.m[1][3];
	Subtract.m[2][0] = matrix1.m[2][0] - matrix2.m[2][0];
	Subtract.m[2][1] = matrix1.m[2][1] - matrix2.m[2][1];
	Subtract.m[2][2] = matrix1.m[2][2] - matrix2.m[2][2];
	Subtract.m[2][3] = matrix1.m[2][3] - matrix2.m[2][3];
	Subtract.m[3][0] = matrix1.m[3][0] - matrix2.m[3][0];
	Subtract.m[3][1] = matrix1.m[3][1] - matrix2.m[3][1];
	Subtract.m[3][2] = matrix1.m[3][2] - matrix2.m[3][2];
	Subtract.m[3][3] = matrix1.m[3][3] - matrix2.m[3][3];

	return Subtract;
}

// ２次元ベクトルを同次座標に変換
Vector3 Transform(Vector3 vector, Matrix4x4 matrix) {
	Vector3 result;
	result.x = vector.x * matrix.m[0][0] + vector.y * matrix.m[1][0] + vector.z * matrix.m[2][0] +
		1.0f * matrix.m[3][0];
	result.y = vector.x * matrix.m[0][1] + vector.y * matrix.m[1][1] + vector.z * matrix.m[2][1] +
		1.0f * matrix.m[3][1];
	result.z = vector.x * matrix.m[0][2] + vector.y * matrix.m[1][2] + vector.z * matrix.m[2][2] +
		1.0f * matrix.m[3][2];
	float w = vector.x * matrix.m[0][3] + vector.y * matrix.m[1][3] + vector.z * matrix.m[2][3] +
		1.0f * matrix.m[3][3];
	assert(w != 0.0f);
	result.x /= w;
	result.y /= w;
	result.z /= w;
	return result;
}

// 平行移動行列
Matrix4x4 MakeTranslateMatrix(Vector3 translate) { // translateに入る値は移動量
	Matrix4x4 mul;
	mul.m[0][0] = 1;
	mul.m[0][1] = 0;
	mul.m[0][2] = 0;
	mul.m[0][3] = 0;
	mul.m[1][0] = 0;
	mul.m[1][1] = 1;
	mul.m[1][2] = 0;
	mul.m[1][3] = 0;
	mul.m[2][0] = 0;
	mul.m[2][1] = 0;
	mul.m[2][2] = 1;
	mul.m[2][3] = 0;
	mul.m[3][0] = translate.x;
	mul.m[3][1] = translate.y;
	mul.m[3][2] = translate.z;
	mul.m[3][3] = 1;

	return mul;
}

// 拡大縮小行列
Matrix4x4 MakeScaleMatrix(Vector3 scale) {
	Matrix4x4 mul;
	mul.m[0][0] = scale.x;
	mul.m[0][1] = 0;
	mul.m[0][2] = 0;
	mul.m[0][3] = 0;
	mul.m[1][0] = 0;
	mul.m[1][1] = scale.y;
	mul.m[1][2] = 0;
	mul.m[1][3] = 0;
	mul.m[2][0] = 0;
	mul.m[2][1] = 0;
	mul.m[2][2] = scale.z;
	mul.m[2][3] = 0;
	mul.m[3][0] = 0;
	mul.m[3][1] = 0;
	mul.m[3][2] = 0;
	mul.m[3][3] = 1;

	return mul;
}

// 回転行列
// Z
Matrix4x4 MakeRotateZMatrix(float radian) {
	Matrix4x4 rotate;

	rotate.m[0][0] = std::cos(radian);
	rotate.m[0][1] = std::sin(radian);
	rotate.m[0][2] = 0;
	rotate.m[0][3] = 0;
	rotate.m[1][0] = -std::sin(radian);
	rotate.m[1][1] = std::cos(radian);
	rotate.m[1][2] = 0;
	rotate.m[1][3] = 0;
	rotate.m[2][0] = 0;
	rotate.m[2][1] = 0;
	rotate.m[2][2] = 1;
	rotate.m[2][3] = 0;
	rotate.m[3][0] = 0;
	rotate.m[3][1] = 0;
	rotate.m[3][2] = 0;
	rotate.m[3][3] = 1;

	return rotate;
}
// X
Matrix4x4 MakeRotateXMatrix(float radian) {
	Matrix4x4 rotate;

	rotate.m[0][0] = 1;
	rotate.m[0][1] = 0;
	rotate.m[0][2] = 0;
	rotate.m[0][3] = 0;
	rotate.m[1][0] = 0;
	rotate.m[1][1] = std::cos(radian);
	rotate.m[1][2] = std::sin(radian);
	rotate.m[1][3] = 0;
	rotate.m[2][0] = 0;
	rotate.m[2][1] = -std::sin(radian);
	rotate.m[2][2] = std::cos(radian);
	rotate.m[2][3] = 0;
	rotate.m[3][0] = 0;
	rotate.m[3][1] = 0;
	rotate.m[3][2] = 0;
	rotate.m[3][3] = 1;

	return rotate;
}
// Y
Matrix4x4 MakeRotateYMatrix(float radian) {
	Matrix4x4 rotate;

	rotate.m[0][0] = std::cos(radian);
	rotate.m[0][1] = 0;
	rotate.m[0][2] = -std::sin(radian);
	rotate.m[0][3] = 0;
	rotate.m[1][0] = 0;
	rotate.m[1][1] = 1;
	rotate.m[1][2] = 0;
	rotate.m[1][3] = 0;
	rotate.m[2][0] = std::sin(radian);
	rotate.m[2][1] = 0;
	rotate.m[2][2] = std::cos(radian);
	rotate.m[2][3] = 0;
	rotate.m[3][0] = 0;
	rotate.m[3][1] = 0;
	rotate.m[3][2] = 0;
	rotate.m[3][3] = 1;

	return rotate;
}

// 積
Matrix4x4 Multiply(Matrix4x4 matrix1, Matrix4x4 matrix2) {
	Matrix4x4 Multiply;
	Multiply.m[0][0] = (matrix1.m[0][0] * matrix2.m[0][0]) + (matrix1.m[0][1] * matrix2.m[1][0]) +
		(matrix1.m[0][2] * matrix2.m[2][0]) + (matrix1.m[0][3] * matrix2.m[3][0]);
	Multiply.m[0][1] = (matrix1.m[0][0] * matrix2.m[0][1]) + (matrix1.m[0][1] * matrix2.m[1][1]) +
		(matrix1.m[0][2] * matrix2.m[2][1]) + (matrix1.m[0][3] * matrix2.m[3][1]);
	Multiply.m[0][2] = (matrix1.m[0][0] * matrix2.m[0][2]) + (matrix1.m[0][1] * matrix2.m[1][2]) +
		(matrix1.m[0][2] * matrix2.m[2][2]) + (matrix1.m[0][3] * matrix2.m[3][2]);
	Multiply.m[0][3] = (matrix1.m[0][0] * matrix2.m[0][3]) + (matrix1.m[0][1] * matrix2.m[1][3]) +
		(matrix1.m[0][2] * matrix2.m[2][3]) + (matrix1.m[0][3] * matrix2.m[3][3]);

	Multiply.m[1][0] = (matrix1.m[1][0] * matrix2.m[0][0]) + (matrix1.m[1][1] * matrix2.m[1][0]) +
		(matrix1.m[1][2] * matrix2.m[2][0]) + (matrix1.m[1][3] * matrix2.m[3][0]);
	Multiply.m[1][1] = (matrix1.m[1][0] * matrix2.m[0][1]) + (matrix1.m[1][1] * matrix2.m[1][1]) +
		(matrix1.m[1][2] * matrix2.m[2][1]) + (matrix1.m[1][3] * matrix2.m[3][1]);
	Multiply.m[1][2] = (matrix1.m[1][0] * matrix2.m[0][2]) + (matrix1.m[1][1] * matrix2.m[1][2]) +
		(matrix1.m[1][2] * matrix2.m[2][2]) + (matrix1.m[1][3] * matrix2.m[3][2]);
	Multiply.m[1][3] = (matrix1.m[1][0] * matrix2.m[0][3]) + (matrix1.m[1][1] * matrix2.m[1][3]) +
		(matrix1.m[1][2] * matrix2.m[2][3]) + (matrix1.m[1][3] * matrix2.m[3][3]);

	Multiply.m[2][0] = (matrix1.m[2][0] * matrix2.m[0][0]) + (matrix1.m[2][1] * matrix2.m[1][0]) +
		(matrix1.m[2][2] * matrix2.m[2][0]) + (matrix1.m[2][3] * matrix2.m[3][0]);
	Multiply.m[2][1] = (matrix1.m[2][0] * matrix2.m[0][1]) + (matrix1.m[2][1] * matrix2.m[1][1]) +
		(matrix1.m[2][2] * matrix2.m[2][1]) + (matrix1.m[2][3] * matrix2.m[3][1]);
	Multiply.m[2][2] = (matrix1.m[2][0] * matrix2.m[0][2]) + (matrix1.m[2][1] * matrix2.m[1][2]) +
		(matrix1.m[2][2] * matrix2.m[2][2]) + (matrix1.m[2][3] * matrix2.m[3][2]);
	Multiply.m[2][3] = (matrix1.m[2][0] * matrix2.m[0][3]) + (matrix1.m[2][1] * matrix2.m[1][3]) +
		(matrix1.m[2][2] * matrix2.m[2][3]) + (matrix1.m[2][3] * matrix2.m[3][3]);

	Multiply.m[3][0] = (matrix1.m[3][0] * matrix2.m[0][0]) + (matrix1.m[3][1] * matrix2.m[1][0]) +
		(matrix1.m[3][2] * matrix2.m[2][0]) + (matrix1.m[3][3] * matrix2.m[3][0]);
	Multiply.m[3][1] = (matrix1.m[3][0] * matrix2.m[0][1]) + (matrix1.m[3][1] * matrix2.m[1][1]) +
		(matrix1.m[3][2] * matrix2.m[2][1]) + (matrix1.m[3][3] * matrix2.m[3][1]);
	Multiply.m[3][2] = (matrix1.m[3][0] * matrix2.m[0][2]) + (matrix1.m[3][1] * matrix2.m[1][2]) +
		(matrix1.m[3][2] * matrix2.m[2][2]) + (matrix1.m[3][3] * matrix2.m[3][2]);
	Multiply.m[3][3] = (matrix1.m[3][0] * matrix2.m[0][3]) + (matrix1.m[3][1] * matrix2.m[1][3]) +
		(matrix1.m[3][2] * matrix2.m[2][3]) + (matrix1.m[3][3] * matrix2.m[3][3]);

	return Multiply;
}

//逆行列4x4

Matrix4x4 Inverse(Matrix4x4 matrix) {
	Matrix4x4 Inverse;
	float A =
		matrix.m[0][0] * matrix.m[1][1] * matrix.m[2][2] * matrix.m[3][3] + matrix.m[0][0] * matrix.m[1][2] * matrix.m[2][3] * matrix.m[3][1] + matrix.m[0][0] * matrix.m[1][3] * matrix.m[2][1] * matrix.m[3][2] -
		matrix.m[0][0] * matrix.m[1][3] * matrix.m[2][2] * matrix.m[3][1] - matrix.m[0][0] * matrix.m[1][2] * matrix.m[2][1] * matrix.m[3][3] - matrix.m[0][0] * matrix.m[1][1] * matrix.m[2][3] * matrix.m[3][2] -
		matrix.m[0][1] * matrix.m[1][0] * matrix.m[2][2] * matrix.m[3][3] - matrix.m[0][2] * matrix.m[1][0] * matrix.m[2][3] * matrix.m[3][1] - matrix.m[0][3] * matrix.m[1][0] * matrix.m[2][1] * matrix.m[3][2] +
		matrix.m[0][3] * matrix.m[1][0] * matrix.m[2][2] * matrix.m[3][1] + matrix.m[0][2] * matrix.m[1][0] * matrix.m[2][1] * matrix.m[3][3] + matrix.m[0][1] * matrix.m[1][0] * matrix.m[2][3] * matrix.m[3][2] +
		matrix.m[0][1] * matrix.m[1][2] * matrix.m[2][0] * matrix.m[3][3] + matrix.m[0][2] * matrix.m[1][3] * matrix.m[2][0] * matrix.m[3][1] + matrix.m[0][3] * matrix.m[1][1] * matrix.m[2][0] * matrix.m[3][2] -
		matrix.m[0][3] * matrix.m[1][2] * matrix.m[2][0] * matrix.m[3][1] - matrix.m[0][2] * matrix.m[1][1] * matrix.m[2][0] * matrix.m[3][3] - matrix.m[0][1] * matrix.m[1][3] * matrix.m[2][0] * matrix.m[3][2] -
		matrix.m[0][1] * matrix.m[1][2] * matrix.m[2][3] * matrix.m[3][0] - matrix.m[0][2] * matrix.m[1][3] * matrix.m[2][1] * matrix.m[3][0] - matrix.m[0][3] * matrix.m[1][1] * matrix.m[2][2] * matrix.m[3][0] +
		matrix.m[0][3] * matrix.m[1][2] * matrix.m[2][1] * matrix.m[3][0] + matrix.m[0][2] * matrix.m[1][1] * matrix.m[2][3] * matrix.m[3][0] + matrix.m[0][1] * matrix.m[1][3] * matrix.m[2][2] * matrix.m[3][0];

	Inverse.m[0][0] = 1 / A * (
		matrix.m[1][1] * matrix.m[2][2] * matrix.m[3][3] + matrix.m[1][2] * matrix.m[2][3] * matrix.m[3][1] + matrix.m[1][3] * matrix.m[2][1] * matrix.m[3][2] -
		matrix.m[1][3] * matrix.m[2][2] * matrix.m[3][1] - matrix.m[1][2] * matrix.m[2][1] * matrix.m[3][3] - matrix.m[1][1] * matrix.m[2][3] * matrix.m[3][2]);
	Inverse.m[0][1] = 1 / A * (
		-matrix.m[0][1] * matrix.m[2][2] * matrix.m[3][3] - matrix.m[0][2] * matrix.m[2][3] * matrix.m[3][1] - matrix.m[0][3] * matrix.m[2][1] * matrix.m[3][2] +
		matrix.m[0][3] * matrix.m[2][2] * matrix.m[3][1] + matrix.m[0][2] * matrix.m[2][1] * matrix.m[3][3] + matrix.m[0][1] * matrix.m[2][3] * matrix.m[3][2]);
	Inverse.m[0][2] = 1 / A * (
		matrix.m[0][1] * matrix.m[1][2] * matrix.m[3][3] + matrix.m[0][2] * matrix.m[1][3] * matrix.m[3][1] + matrix.m[0][3] * matrix.m[1][1] * matrix.m[3][2] -
		matrix.m[0][3] * matrix.m[1][2] * matrix.m[3][1] - matrix.m[0][2] * matrix.m[1][1] * matrix.m[3][3] - matrix.m[0][1] * matrix.m[1][3] * matrix.m[3][2]);
	Inverse.m[0][3] = 1 / A * (
		-matrix.m[0][1] * matrix.m[1][2] * matrix.m[2][3] - matrix.m[0][2] * matrix.m[1][3] * matrix.m[2][1] - matrix.m[0][3] * matrix.m[1][1] * matrix.m[2][2] +
		matrix.m[0][3] * matrix.m[1][2] * matrix.m[2][1] + matrix.m[0][2] * matrix.m[1][1] * matrix.m[2][3] + matrix.m[0][1] * matrix.m[1][3] * matrix.m[2][2]);

	Inverse.m[1][0] = 1 / A * (
		-matrix.m[1][0] * matrix.m[2][2] * matrix.m[3][3] - matrix.m[1][2] * matrix.m[2][3] * matrix.m[3][0] - matrix.m[1][3] * matrix.m[2][0] * matrix.m[3][2] +
		matrix.m[1][3] * matrix.m[2][2] * matrix.m[3][0] + matrix.m[1][2] * matrix.m[2][0] * matrix.m[3][3] + matrix.m[1][0] * matrix.m[2][3] * matrix.m[3][2]);
	Inverse.m[1][1] = 1 / A * (
		matrix.m[0][0] * matrix.m[2][2] * matrix.m[3][3] + matrix.m[0][2] * matrix.m[2][3] * matrix.m[3][0] + matrix.m[0][3] * matrix.m[2][0] * matrix.m[3][2] -
		matrix.m[0][3] * matrix.m[2][2] * matrix.m[3][0] - matrix.m[0][2] * matrix.m[2][0] * matrix.m[3][3] - matrix.m[0][0] * matrix.m[2][3] * matrix.m[3][2]);
	Inverse.m[1][2] = 1 / A * (
		-matrix.m[0][0] * matrix.m[1][2] * matrix.m[3][3] - matrix.m[0][2] * matrix.m[1][3] * matrix.m[3][0] - matrix.m[0][3] * matrix.m[1][0] * matrix.m[3][2] +
		matrix.m[0][3] * matrix.m[1][2] * matrix.m[3][0] + matrix.m[0][2] * matrix.m[1][0] * matrix.m[3][3] + matrix.m[0][0] * matrix.m[1][3] * matrix.m[3][2]);
	Inverse.m[1][3] = 1 / A * (
		matrix.m[0][0] * matrix.m[1][2] * matrix.m[2][3] + matrix.m[0][2] * matrix.m[1][3] * matrix.m[2][0] + matrix.m[0][3] * matrix.m[1][0] * matrix.m[2][2] -
		matrix.m[0][3] * matrix.m[1][2] * matrix.m[2][0] - matrix.m[0][2] * matrix.m[1][0] * matrix.m[2][3] - matrix.m[0][0] * matrix.m[1][3] * matrix.m[2][2]);

	Inverse.m[2][0] = 1 / A * (
		matrix.m[1][0] * matrix.m[2][1] * matrix.m[3][3] + matrix.m[1][1] * matrix.m[2][3] * matrix.m[3][0] + matrix.m[1][3] * matrix.m[2][0] * matrix.m[3][1] -
		matrix.m[1][3] * matrix.m[2][1] * matrix.m[3][0] - matrix.m[1][1] * matrix.m[2][0] * matrix.m[3][3] - matrix.m[1][0] * matrix.m[2][3] * matrix.m[3][1]);
	Inverse.m[2][1] = 1 / A * (
		-matrix.m[0][0] * matrix.m[2][1] * matrix.m[3][3] - matrix.m[0][1] * matrix.m[2][3] * matrix.m[3][0] - matrix.m[0][3] * matrix.m[2][0] * matrix.m[3][1] +
		matrix.m[0][3] * matrix.m[2][1] * matrix.m[3][0] + matrix.m[0][1] * matrix.m[2][0] * matrix.m[3][3] + matrix.m[0][0] * matrix.m[2][3] * matrix.m[3][1]);
	Inverse.m[2][2] = 1 / A * (
		matrix.m[0][0] * matrix.m[1][1] * matrix.m[3][3] + matrix.m[0][1] * matrix.m[1][3] * matrix.m[3][0] + matrix.m[0][3] * matrix.m[1][0] * matrix.m[3][1] -
		matrix.m[0][3] * matrix.m[1][1] * matrix.m[3][0] - matrix.m[0][1] * matrix.m[1][0] * matrix.m[3][3] - matrix.m[0][0] * matrix.m[1][3] * matrix.m[3][1]);
	Inverse.m[2][3] = 1 / A * (
		-matrix.m[0][0] * matrix.m[1][1] * matrix.m[2][3] - matrix.m[0][1] * matrix.m[1][3] * matrix.m[2][0] - matrix.m[0][3] * matrix.m[1][0] * matrix.m[2][1] +
		matrix.m[0][3] * matrix.m[1][1] * matrix.m[2][0] + matrix.m[0][1] * matrix.m[1][0] * matrix.m[2][3] + matrix.m[0][0] * matrix.m[1][3] * matrix.m[2][1]);

	Inverse.m[3][0] = 1 / A * (
		-matrix.m[1][0] * matrix.m[2][1] * matrix.m[3][2] - matrix.m[1][1] * matrix.m[2][2] * matrix.m[3][0] - matrix.m[1][2] * matrix.m[2][0] * matrix.m[3][1] +
		matrix.m[1][2] * matrix.m[2][1] * matrix.m[3][0] + matrix.m[1][1] * matrix.m[2][0] * matrix.m[3][2] + matrix.m[1][0] * matrix.m[2][2] * matrix.m[3][1]);
	Inverse.m[3][1] = 1 / A * (
		matrix.m[0][0] * matrix.m[2][1] * matrix.m[3][2] + matrix.m[0][1] * matrix.m[2][2] * matrix.m[3][0] + matrix.m[0][2] * matrix.m[2][0] * matrix.m[3][1] -
		matrix.m[0][2] * matrix.m[2][1] * matrix.m[3][0] - matrix.m[0][1] * matrix.m[2][0] * matrix.m[3][2] - matrix.m[0][0] * matrix.m[2][2] * matrix.m[3][1]);
	Inverse.m[3][2] = 1 / A * (
		-matrix.m[0][0] * matrix.m[1][1] * matrix.m[3][2] - matrix.m[0][1] * matrix.m[1][2] * matrix.m[3][0] - matrix.m[0][2] * matrix.m[1][0] * matrix.m[3][1] +
		matrix.m[0][2] * matrix.m[1][1] * matrix.m[3][0] + matrix.m[0][1] * matrix.m[1][0] * matrix.m[3][2] + matrix.m[0][0] * matrix.m[1][2] * matrix.m[3][1]);
	Inverse.m[3][3] = 1 / A * (
		matrix.m[0][0] * matrix.m[1][1] * matrix.m[2][2] + matrix.m[0][1] * matrix.m[1][2] * matrix.m[2][0] + matrix.m[0][2] * matrix.m[1][0] * matrix.m[2][1] -
		matrix.m[0][2] * matrix.m[1][1] * matrix.m[2][0] - matrix.m[0][1] * matrix.m[1][0] * matrix.m[2][2] - matrix.m[0][0] * matrix.m[1][2] * matrix.m[2][1]);


	return Inverse;
}

Matrix4x4 MakeAffineMatrix(Vector3 scale, Vector3 theta, Vector3 translate) {
	Matrix4x4 ScaleMatrix = MakeScaleMatrix(scale);
	Matrix4x4 RxMatrix = MakeRotateXMatrix(theta.x);
	Matrix4x4 RyMatrix = MakeRotateYMatrix(theta.y);
	Matrix4x4 RzMatrix = MakeRotateZMatrix(theta.z);
	Matrix4x4 RotateMatrix = Multiply(RxMatrix, Multiply(RyMatrix, RzMatrix));
	Matrix4x4 TranslateMatrix = MakeTranslateMatrix(translate);

	Matrix4x4 SR_Matrix = Multiply(ScaleMatrix, RotateMatrix);
	Matrix4x4 SRT_Matrix = Multiply(SR_Matrix, TranslateMatrix);

	return SRT_Matrix;
}

Matrix4x4 MakeOrthographicMatrix(float left, float top, float right, float bottom, float nearClip, float farClip) {
	Matrix4x4 ortho;
	ortho.m[0][0] = 2.0f / (right - left);
	ortho.m[0][1] = 0;
	ortho.m[0][2] = 0;
	ortho.m[0][3] = 0;
	ortho.m[1][0] = 0;
	ortho.m[1][1] = 2.0f / (top - bottom);
	ortho.m[1][2] = 0;
	ortho.m[1][3] = 0;
	ortho.m[2][0] = 0;
	ortho.m[2][1] = 0;
	ortho.m[2][2] = 1.0f / farClip - nearClip;
	ortho.m[2][3] = 0;
	ortho.m[3][0] = (left + right) / (left - right);
	ortho.m[3][1] = (top + bottom) / (bottom - top);
	ortho.m[3][2] = nearClip / (nearClip - farClip);
	ortho.m[3][3] = 1;

	return ortho;
}
Matrix4x4 MakeViewportMatrix(float left, float top, float width, float height, float minDepth, float maxDepth) {
	Matrix4x4 view;
	view.m[0][0] = width / 2;
	view.m[0][1] = 0;
	view.m[0][2] = 0;
	view.m[0][3] = 0;
	view.m[1][0] = 0;
	view.m[1][1] = -height / 2.0f;
	view.m[1][2] = 0;
	view.m[1][3] = 0;
	view.m[2][0] = 0;
	view.m[2][1] = 0;
	view.m[2][2] = maxDepth - minDepth;
	view.m[2][3] = 0;
	view.m[3][0] = left + width / 2;
	view.m[3][1] = top + height / 2;
	view.m[3][2] = minDepth;
	view.m[3][3] = 1;
	return view;
}
Matrix4x4 MakePerspectiveFovMatrix(float fovY, float aspectRatio, float nearClip, float farClip) {
	Matrix4x4 Pers;
	Pers.m[0][0] = (1 / aspectRatio) * (1 / tan(fovY / 2));
	Pers.m[0][1] = 0;
	Pers.m[0][2] = 0;
	Pers.m[0][3] = 0;
	Pers.m[1][0] = 0;
	Pers.m[1][1] = 1 / tan(fovY / 2);
	Pers.m[1][2] = 0;
	Pers.m[1][3] = 0;
	Pers.m[2][0] = 0;
	Pers.m[2][1] = 0;
	Pers.m[2][2] = farClip / (farClip - nearClip);
	Pers.m[2][3] = 1;
	Pers.m[3][0] = 0;
	Pers.m[3][1] = 0;
	Pers.m[3][2] = (-nearClip * farClip) / (farClip - nearClip);
	Pers.m[3][3] = 0;
	return Pers;
}

//正規化
Vector3 Normalize(const Vector3& pos) {
	Vector3 newPos;
	float length = sqrt((pos.x * pos.x) + (pos.y * pos.y) + (pos.z * pos.z));
	if (length != 0.0f) {
		newPos.x = pos.x / length;
		newPos.y = pos.y / length;
		newPos.z = pos.z / length;
	}
	return newPos;
}

//スカラー倍
Vector3 Scaler(float scalar, const Vector3& v2) {
	Vector3 Multiply;
	Multiply.x = scalar * v2.x;
	Multiply.y = scalar * v2.y;
	Multiply.z = scalar * v2.z;
	return Multiply;
}
