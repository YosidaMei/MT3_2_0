#pragma once
#include "Vector3.h"
#include "Matrix4x4.h"
#define _USE_MATH_DEFINES
#include <cmath>

class Matrix {};
Vector3 Multiply(const Vector3& v1,const Vector3& v2);
Vector3 Add(const Vector3& v1, const Vector3& v2);
Vector3 Subtract(const Vector3& v1, const Vector3& v2);
Matrix4x4 Add(Matrix4x4 matrix1, Matrix4x4 matrix2);
Matrix4x4 Subtract(Matrix4x4 matrix1, Matrix4x4 matrix2);
Matrix4x4 MakeTranslateMatrix(Vector3 translate);
Matrix4x4 MakeScaleMatrix(Vector3 scale);
Vector3 Transform(Vector3 vector, Matrix4x4 matrix);
Matrix4x4 MakeRotateXMatrix(float radian);
Matrix4x4 MakeRotateYMatrix(float radian);
Matrix4x4 MakeRotateZMatrix(float radian);
Matrix4x4 Multiply(Matrix4x4 matrix1, Matrix4x4 matrix2);
Matrix4x4 MakeAffineMatrix(Vector3 scale, Vector3 theta, Vector3 translate);
Matrix4x4 MakeOrthographicMatrix(float left, float top, float right, float bottom, float nearClip, float farClip);
Matrix4x4 MakeViewportMatrix(float left, float top, float width, float height, float minDepth, float maxDepth);
Matrix4x4 MakePerspectiveFovMatrix(float fovY, float aspectRatio, float nearClip, float farClip);
Matrix4x4 Inverse(Matrix4x4 matrix);
Vector3 Normalize(const Vector3& pos);
Vector3 Scaler(float scalar, const Vector3& v2);


