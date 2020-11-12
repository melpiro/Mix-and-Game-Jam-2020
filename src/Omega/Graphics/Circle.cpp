#include "Graphics/Circle.h"

namespace O{
namespace graphics {

	Circle::Circle()
	{

	}

	Circle::Circle(sf::RenderWindow* window, float x, float y, float radius, float posRx, float posRy, bool centered) : 
		m_circle(radius),
		m_x(x), m_y(y)
	{
		m_fen = window;

		if (posRx == -1) m_posRx = x;
		else m_posRx = posRx;
		if (posRy == -1) m_posRy = y;
		else m_posRy = posRy;

		m_baseColor = sf::Color::White;
		m_hoverColor = sf::Color::White;
		m_outlineBaseColor = sf::Color::Transparent;
		m_outlinehoverColor = sf::Color::Transparent;

		m_isOrigineAsCenter = false;

		if (centered)
		{
			// si l'objet doit etre centr�, un appel � update n'est pas n�c�saire
			// car la fonction setOrigineAsCenter le fait deja !
			setOrigineAsCenter();
		}
		else
		{
			update();
		}
	}

	Circle::Circle(sf::RenderWindow* window, float x, float y, float radius, bool centered) :
		Circle(window, x, y, radius, 0, 0, centered)
	{
	}



	void Circle::event(sf::Event& e)
	{
		if (e.type == sf::Event::Resized)
		{
			update();
		}
	}

	void Circle::update()
	{
		//facteur de redimentionnement
		float factorX = (float)m_fen->getSize().x / STATIC::SYS::WIDTH;
		float factorY = (float)m_fen->getSize().y / STATIC::SYS::HIGHT;



		m_circle.setPosition(m_x + (factorX - 1) * m_posRx, m_y + (factorY - 1) * m_posRy);

	}



	void Circle::draw()
	{
		m_fen->draw(m_circle);
	}



	sf::CircleShape& Circle::gC()
	{
		return m_circle;
	}

	void Circle::setPosition(float x, float y)
	{
		m_x = x;
		m_y = y;
	}
	void Circle::setPosition(float x, float y, bool update)
	{
		m_x = x;
		m_y = y;
		if (update) Circle::update();
	}
	sf::Vector2f Circle::getPosition()
	{
		return sf::Vector2f(m_x, m_y);
	}

	void Circle::setFillColor(sf::Color c)
	{
		m_baseColor = c;
		m_circle.setFillColor(c);
	}
	void Circle::setOutlineColor(sf::Color c)
	{
		m_outlineBaseColor = c;
		m_circle.setOutlineColor(c);
	}
	void Circle::setFillColor(sf::Color c, bool noUpdateBaseColor)
	{
		if (!noUpdateBaseColor) m_baseColor = c;
		m_circle.setFillColor(c);
	}
	void Circle::setOutlineColor(sf::Color c, bool noUpdateOutlineBaseColor)
	{
		if (!noUpdateOutlineBaseColor) m_outlineBaseColor = c;
		m_circle.setOutlineColor(c);
	}
	void Circle::setOutlineThickness(float v)
	{
		m_circle.setOutlineThickness(v);
		if (m_isOrigineAsCenter) setOrigineAsCenter();
	}
	sf::Color Circle::getFillColor()
	{
		return m_circle.getFillColor();
	}
	sf::Color Circle::getOutlineColor()
	{
		return m_circle.getOutlineColor();
	}
	float Circle::getOutlineThickness()
	{
		return m_circle.getOutlineThickness();
	}

	void Circle::move(float x, float y)
	{
		setPosition(getPosition().x + x, getPosition().y + y);
	}
	void Circle::setScale(float x, float y)
	{
		m_circle.setScale(x, y);
	}

	void Circle::setRadius(float r)
	{
		m_circle.setRadius(r);
		if (m_isOrigineAsCenter) setOrigineAsCenter();
	}
	float Circle::getRadius()
	{
		return m_circle.getRadius();
	}

	bool Circle::hover()
	{
		auto p = sf::Mouse::getPosition(*m_fen);
		sf::FloatRect b = m_circle.getGlobalBounds();

		bool isIn = (getRadius() > math::getDistance(
			sf::Vector2f(b.left + b.width/2.0, b.top + b.height / 2.0),
			sf::Vector2f(p.x,p.y)));

		if (isIn)
		{
			setFillColor(m_hoverColor, true);
			setOutlineColor(m_outlineBaseColor, true);
		}
		else
		{
			setFillColor(m_baseColor, true);
			setOutlineColor(m_outlinehoverColor, true);
		}

		return isIn;
	}

	bool Circle::clicked(sf::Event& e)
	{
		if (e.type == sf::Event::MouseButtonReleased)
		{
			if (e.mouseButton.button == sf::Mouse::Left)
			{
				if (hover())
				{
					return true;
				}
			}
		}
		return false;
	}

	void Circle::setColorOnHover(sf::Color couleur)
	{
		setColorOnHover(getFillColor(), couleur);
	}

	void Circle::setColorOnHover(sf::Color base, sf::Color hover)
	{
		setFillColor(base);
		m_baseColor = base;
		m_hoverColor = hover;
	}
	void Circle::setOutlineColorOnHover(sf::Color couleur)
	{
		setColorOnHover(getOutlineColor(), couleur);
	}
	void Circle::setOutlineColorOnHover(sf::Color base, sf::Color hover)
	{
		setOutlineColor(base);
		m_outlineBaseColor = base;
		m_outlinehoverColor = hover;
	}

	void Circle::setPointRedi(float x, float y)
	{
		m_posRx = x;
		m_posRy = y;

		update();
	}

	void Circle::setOrigineAsCenter()
	{
		sf::FloatRect r = m_circle.getGlobalBounds();
		m_circle.setOrigin(r.width / (2.0 * m_circle.getScale().x), r.height / (2.0 * m_circle.getScale().y));
		m_isOrigineAsCenter = true;

		update();
	}

}
}