module;

#include <stdexcept>

module Math;

Matrix2::Matrix2(int rowCount, int columnCount)
	: m_data(new float[rowCount * columnCount]), m_rowCount(rowCount), m_columnCount(columnCount)
{

}

Matrix2::~Matrix2()
{
	delete[] m_data;
}

int Matrix2::CalculateValueIndex(int row, int column) const
{
	return (row - 1) * m_columnCount + column - 1;
}

void Matrix2::SetValue(float value, int row, int column)
{
	m_data[CalculateValueIndex(row, column)] = value;
}

float& Matrix2::GetValue(int row, int column) const
{
	return m_data[CalculateValueIndex(row, column)];
}

Matrix2 Matrix2::operator * (float value) const
{
	auto resultMatrix = Matrix2(m_rowCount, m_columnCount);

	for (int row = 1; row < resultMatrix.m_rowCount; row++)
	{
		for (int column = 1; column < resultMatrix.m_columnCount; column++)
		{
			resultMatrix.SetValue(GetValue(row, column) * value, row, column);
		}
	}

	return resultMatrix;
}

Matrix2 Matrix2::operator + (Matrix2 &other) const
{
	if (m_rowCount != other.m_rowCount || m_columnCount != other.m_columnCount)
		throw std::invalid_argument("The number of rows and columns of the terms of the matrices must match.");

	auto resultMatrix = Matrix2(m_rowCount, m_columnCount);

	for (int row = 1; row < resultMatrix.m_rowCount; row++)
	{
		for (int column = 1; column < resultMatrix.m_columnCount; column++)
		{
			resultMatrix.SetValue(GetValue(row, column) + other.GetValue(row, column), row, column);
		}
	}

	return resultMatrix;
}

Matrix2 Matrix2::operator - (Matrix2 &other) const
{
	if (m_rowCount != other.m_rowCount || m_columnCount != other.m_columnCount)
		throw std::invalid_argument("The number of rows and columns of the terms of the matrices must match.");

	auto resultMatrix = Matrix2(m_rowCount, m_columnCount);

	for (int row = 1; row < resultMatrix.m_rowCount; row++)
	{
		for (int column = 1; column < resultMatrix.m_columnCount; column++)
		{
			resultMatrix.SetValue(GetValue(row, column) - other.GetValue(row, column), row, column);
		}
	}

	return resultMatrix;
}