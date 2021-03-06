
namespace tutorial
{
	struct Point
	{
		float x;
		float y;
		nocode Point();
		nocode Point(float a, float b);
		nocode Point(const Point& pt);

#{
		Point()
		{}
		Point(float a, float b)
		{
			x = a;
			y = b;
		}
#}
	};

	struct Shape
	{
		abstract float getArea();
		##		virtual ~Shape() {}
	};

	struct Triangle : Shape
	{
		Point m_vertices[#3];
		nocode static Triangle^ New();
#{
			virtual float getArea()
		{
			return fabs(m_vertices[0].x * m_vertices[1].y
				+ m_vertices[1].x * m_vertices[2].y
				+ m_vertices[2].x * m_vertices[0].y
				- m_vertices[0].x * m_vertices[2].y
				- m_vertices[1].x * m_vertices[0].y
				- m_vertices[2].x * m_vertices[1].y) * 0.5;
		}
		static Triangle* New()
		{
			return new Triangle;
		}
#}
	};

}
