
namespace O{
	namespace math {
		template<typename T>
		double getCoefDir(const sf::Vector2<T>& p1,const sf::Vector2<T>& p2)
		{
			return (p1.y - p2.y) / (p1.x - p2.x);
		}
		template<typename T>
		double getDistance(const sf::Vector2<T>& origine, const sf::Vector2<T>& destination)
		{
			return getDistance(origine.x,origine.y,destination.x,destination.y);
		}
		template<typename T>
		double getDistance(const sf::Vector2<T>& origine)
		{
			return getDistance(origine.x,origine.y);
		}
		template<typename T>
		double getDistanceCarre(const sf::Vector2<T>& origine, const sf::Vector2<T>& destination)
		{
			return getDistanceCarre(origine.x,origine.y,destination.x,destination.y);
		}
		template<typename T>
		double getDistance(const T& ax, const T& ay, const T& bx, const T& by)
		{
			return sqrt(getDistanceCarre(ax,ay,bx,by));
		}
		template<typename T>
		double getDistance(const T& ax, const T& ay)
		{
			return sqrt(std::pow(ax,2.0)+std::pow(ay,2.0));
		}
		template<typename T>
		double getDistanceCarre(const T& ax, const T& ay, const T& bx, const T& by)
		{
			return std::pow(ax - bx, 2) + std::pow(	ay - by, 2);
		}
		template<typename T>
		double getDirection(const sf::Vector2<T>& A, const sf::Vector2<T>& B)
		{
			if (A.x == B.x) return STATIC::MATH::PI_2;
			return std::atan(getCoefDir(A, B));
		}
		template<typename T>
		double getAngle(const sf::Vector2<T>& origine, const sf::Vector2<T>& destination)
		{
			if (origine.x == destination.x)
			{
				if (origine.y > destination.y) return -STATIC::MATH::PI_2;
				else return STATIC::MATH::PI_2;
			}
			double direction = getDirection(origine, destination);
			if (origine.x > destination.x) direction += STATIC::MATH::PI;
			if (direction < 0) direction += STATIC::MATH::PI_x2;
			return direction;
		}
		template<typename T>
		bool isAtLeft(const sf::Vector2<T>& p, double rotation, const sf::Vector2<T>& target)
		{
			sf::Vector2<T> Dv(target - p);
			sf::Vector2<T> Tv(cos(rotation) * 100.0 - p.x, sin(rotation) * 100.0 - p.y);

			return ((Dv.x * Tv.y - Dv.y * Tv.x) < 0);
		}
		template<typename T>
		bool isAtLeft(const sf::Vector2<T>& V1, const sf::Vector2<T>& V2)
		{
			return (V1.x*-V2.y + V1.y*V2.x < 0);
		}
		template<typename T>
		double getDirectionDeg(const sf::Vector2<T>& A, const sf::Vector2<T>& B)
		{
			return ToDeg(getDirection(A, B));
		}
		template<typename T>
		double getAngleDeg(const sf::Vector2<T>& origine, const sf::Vector2<T>& destination)
		{
			return ToDeg(getAngle(origine, destination));
		}
		template<typename T>
		T PGCD(const T& a, const T& b)
		{
			return b ? PGCD(b, a % b) : a;
		}
		template<typename T,typename J>
		T mod(const T& a, const J& b)
		{
			return (a % b + b) % b;
			
		}

		template<typename T>
		bool isDivisibleBy(const T& num, const T& diviseur)
		{
			return (num%diviseur == 0);
		}
		template<typename T>
		bool isMultiple(const T& num, const T& multiple)
		{
			return isDivisibleBy(num, multiple);
		}
	}
}