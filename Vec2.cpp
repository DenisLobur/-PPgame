class Vec2
{
public:
	float x = 0;
	float y = 0;

	Vec2() {};

	Vec2(float xin, float yin)
		: x(xin), y(yin)
	{

	}

	Vec2& add(Vec2 v)
	{
		x += v.x;
		y += v.y;

		return *this;
	}

	Vec2 operator + (Vec2 v)
	{
		return Vec2(x + v.x, y + v.y);
	}

	Vec2 operator * (float s)
	{
		return Vec2(x *= s, y *= s);
	}

	void scale(float s)
	{
		x *= s;
		y *= s;
	}
};