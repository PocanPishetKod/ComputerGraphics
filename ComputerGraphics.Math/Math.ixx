export module Math;

export struct Vector2
{
private:
	const float m_x;
	const float m_y;

public:
	Vector2(float x, float y);
	float GetX() const;
	float GetY() const;
	Vector2 operator + (Vector2 &other) const;
	Vector2 operator - (Vector2 &other) const;
	float operator * (Vector2 &other) const;
	Vector2 operator * (float number) const;
	float GetMagnitude() const;

	static float Scalar(Vector2 left, Vector2 right);
};

export struct Matrix2
{
private:
	float *m_data;
	const int m_rowCount;
	const int m_columnCount;

	int CalculateValueIndex(int row, int column) const;

public:
	Matrix2(int rowCount, int columnCount);
	~Matrix2();
	float& GetValue(int row, int column) const;
	void SetValue(float value, int row, int column);
	Matrix2 Transpose() const;

	Matrix2 operator + (Matrix2 &other) const;
	Matrix2 operator - (Matrix2 &other) const;
	Matrix2 operator * (float value) const;
};