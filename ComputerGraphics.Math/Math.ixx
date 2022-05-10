export module Math;

export struct Vector2
{
private:
	const float m_x;
	const float m_y;

public:
	Vector2(float x, float y);
	float const GetX();
	float const GetY();
	Vector2 const operator + (Vector2 &other);
	Vector2 const operator - (Vector2 &other);
	float const operator * (Vector2 &other);
	Vector2 const operator * (float number);
	float const GetMagnitude();

	static float Scalar(Vector2 left, Vector2 right);
};

export struct Matrix2
{
private:
	float *m_data;
	int m_rowCount;
	int m_columnCount;

	int CalculateValueIndex(int row, int column);

public:
	Matrix2(int rowCount, int columnCount);
	~Matrix2();
	float& GetValue(int row, int column);
	void SetValue(float value, int row, int column);
	Matrix2 operator + (Matrix2 &other);
	Matrix2 operator - (Matrix2 &other);
	Matrix2 operator * (float value);
};