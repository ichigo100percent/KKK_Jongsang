#pragma once
#include "Std.h"


struct Vertex
{
	Vec3 position;
	Color color;
};

struct TransformData
{
	Matrix matWorld = Matrix::Identity;
	Matrix matView = Matrix::Identity;
	Matrix matProjection = Matrix::Identity;
};