#include "Graphics/Line.h"


namespace O{
namespace graphics {

	Line::Line()
	{

	}

	Line::Line(sf::RenderWindow* window, sf::Vector2f p1, sf::Vector2f p2, float width, float posRx, float posRy) :
		m_posRx(posRx), m_posRy(posRy)
	{
		m_fen = window;

		m_width = width;
		m_rectangle.setOrigin(0, width / 2.0);

		setPoints(p1, p2);
	}

	Line::Line(sf::RenderWindow* window, sf::Vector2f p, float angle, float length, float width, float posRx, float posRy) :
		m_posRx(posRx), m_posRy(posRy)
	{
		m_fen = window;


		m_width = width;
		m_rectangle.setOrigin(0, width / 2.0);
		update();
		setPoints(p, angle, length);
		
	}

	void Line::event(sf::Event& e)
	{
		if (e.type == sf::Event::Resized)
		{
			update();
		}
	}

	
	void Line::update()
	{
		//facteur de redimentionnement
		float factorX = (float)m_fen->getSize().x / STATIC::SYS::WIDTH;
		float factorY = (float)m_fen->getSize().y / STATIC::SYS::HIGHT;

		m_rectangle.setPosition(m_p1.x + (factorX - 1) * m_posRx, m_p1.y + (factorY - 1) * m_posRy);
	}


	void Line::updateScale()
	{
		//facteur de redimentionnement
		float factorX = (float)m_fen->getSize().x / STATIC::SYS::WIDTH;
		float factorY = (float)m_fen->getSize().y / STATIC::SYS::HIGHT;

		setPointsForScale(m_p1, m_p2, sf::Vector2f(factorX, factorY));
	}

	void Line::draw()
	{
		m_fen->draw(m_rectangle);
	}



	sf::RectangleShape& Line::gR()
	{
		return m_rectangle;
	}

	void Line::setPosition(float x, float y)
	{
		m_p2.x += (m_p1.x - x);
		m_p2.y += (m_p1.y - x);

		m_p1.x = x;
		m_p1.y = y;
	}
	void Line::setPosition(float x, float y, bool update)
	{
		setPosition(x, y);
		if (update) Line::update();
	}
	sf::Vector2f Line::getPosition()
	{
		return sf::Vector2f(m_p1.x, m_p1.y);
	}

	void Line::move(float x, float y)
	{
		setPosition(getPosition().x + x, getPosition().y + y);
	}

	void Line::setSize(float length, float width)
	{
		m_rectangle.setSize(sf::Vector2f(length, width));
	}
	void Line::setPoints(sf::Vector2f p1, sf::Vector2f p2)
	{
		m_p1 = p1;
		m_p2 = p2;
		m_length = math::getDistance((sf::Vector2f) p1, (sf::Vector2f) p2);

		m_rectangle.setSize(sf::Vector2f(m_length, m_width));
		m_rectangle.setRotation(math::getAngleDeg((sf::Vector2f) p1, (sf::Vector2f)p2));


		update();
	}

	void Line::setPoints(sf::Vector2f p, float angle, float length)
	{
		m_p1 = p;
		m_p2 = sf::Vector2f(
			std::cos(math::ToRad(angle)) * length,
			std::sin(math::ToRad(angle)) * length
			);

		m_length = length;
		m_rectangle.setSize(sf::Vector2f(m_length, m_width));
		m_rectangle.setRotation(angle);

		update();
	}
	void Line::setFillColor(sf::Color c)
	{
		m_rectangle.setFillColor(c);
	}
	void Line::setWidth(float w)
	{
		m_width = w;
		m_rectangle.setOrigin(0, m_width / 2.0);
		m_rectangle.setSize(sf::Vector2f(m_length, m_width));
		
	}
	sf::Color Line::getFilleColor()
	{
		return sf::Color();
	}
	sf::Vector2f Line::getSize()
	{
		return m_rectangle.getSize();
	}

	float Line::getWidth()
	{
		return m_width;
	}
	

	void Line::setPointRedi(float x, float y)
	{
		m_posRx = x;
		m_posRy = y;
	}

	void Line::setPointsForScale(sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f scale)
	{
		

		p1.x *= scale.x;
		p1.y *= scale.y;

		p2.x *= scale.x;
		p2.y *= scale.y;


		m_rectangle.setPosition(p1);
		m_rectangle.setSize(sf::Vector2f(math::getDistance((sf::Vector2f) p1, (sf::Vector2f)p2) , m_width));
		m_rectangle.setRotation(math::getAngleDeg((sf::Vector2f) p1, (sf::Vector2f)p2));

	}


}}