#include "Graphics/Rectangle.h"


namespace O{
namespace graphics {
	Rectangle::Rectangle()
	{

	}

	Rectangle::Rectangle(sf::RenderWindow* window, float x, float y, float sizeX, float sizeY, float posRx, float posRy, bool centered) : 
		m_fen(window),
		m_rectangle(sf::Vector2f(sizeX,sizeY)),
		m_x(x), m_y(y),
		m_posRx(posRx), m_posRy(posRy),
		m_isOrigineAsCenter(false)
	{

		


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

	Rectangle::Rectangle(sf::RenderWindow* window, float x, float y, float sizeX, float sizeY, bool centered) :
		Rectangle(window, x, y, sizeX, sizeY, 0, 0, centered)
	{
	}

	

	void Rectangle::event(sf::Event& e)
	{
		if (e.type == sf::Event::Resized)
		{
			update();
		}	
	}

	void Rectangle::update()
	{
		float factorX = (float)m_fen->getSize().x / STATIC::SYS::WIDTH;
		float factorY = (float)m_fen->getSize().y / STATIC::SYS::HIGHT;

		m_rectangle.setPosition(m_x + (factorX - 1) * m_posRx, m_y + (factorY - 1) * m_posRy);
	}


	void Rectangle::draw()
	{
		m_fen->draw(m_rectangle);
	}



	sf::RectangleShape& Rectangle::gR()
	{
		return m_rectangle;
	}

	void Rectangle::setPosition(float x, float y)
	{
		m_x = x;
		m_y = y;
	}
	void Rectangle::setPosition(float x, float y, bool update)
	{
		m_x = x;
		m_y = y;
		if (update) Rectangle::update();
	}
	sf::Vector2f Rectangle::getPosition()
	{
		return sf::Vector2f(m_x, m_y);
	}

	void Rectangle::setFillColor(sf::Color c)
	{
		m_baseColor = c;
		m_rectangle.setFillColor(c);
	}
	void Rectangle::setOutlineColor(sf::Color c)
	{
		m_outlineBaseColor = c;
		m_rectangle.setOutlineColor(c);
	}
	void Rectangle::setFillColor(sf::Color c, bool noUpdateBaseColor)
	{
		if(!noUpdateBaseColor) m_baseColor = c;
		m_rectangle.setFillColor(c);
	}
	void Rectangle::setOutlineColor(sf::Color c, bool noUpdateOutlineBaseColor)
	{
		if(!noUpdateOutlineBaseColor) m_outlineBaseColor = c;
		m_rectangle.setOutlineColor(c);
	}
	void Rectangle::setOutlineThickness(float v)
	{
		m_rectangle.setOutlineThickness(v);
		if (m_isOrigineAsCenter) setOrigineAsCenter();
	}
	sf::Color Rectangle::getFillColor()
	{
		return m_rectangle.getFillColor();
	}
	sf::Color Rectangle::getOutlineColor()
	{
		return m_rectangle.getOutlineColor();
	}
	float Rectangle::getOutlineThickness()
	{
		return m_rectangle.getOutlineThickness();
	}

	void Rectangle::move(float x, float y)
	{
		setPosition(getPosition().x + x, getPosition().y + y);
	}
	void Rectangle::setScale(float x, float y)
	{
		m_rectangle.setScale(x, y);
	}

	void Rectangle::setSize(float x, float y)
	{
		setSize(sf::Vector2f(x,y));
	}
	void Rectangle::setSize(sf::Vector2f size)
	{
		m_rectangle.setSize(size);
		if (m_isOrigineAsCenter) setOrigineAsCenter();
	}
	sf::Vector2f Rectangle::getSize()
	{
		return m_rectangle.getSize();
	}

	bool Rectangle::hover()
	{
		auto p = m_fen->mapPixelToCoords(sf::Mouse::getPosition(*m_fen));
		bool isIn = m_rectangle.getGlobalBounds().contains(p.x, p.y);
		if (isIn)
		{
			setFillColor(m_hoverColor, true);
			setOutlineColor(m_outlinehoverColor, true);
		}
		else
		{
			setFillColor(m_baseColor, true);
			setOutlineColor(m_outlineBaseColor, true);
		}

		return isIn;
	}

	bool Rectangle::clicked(sf::Event& e)
	{
		if (hover())
		{
			if (e.type == sf::Event::MouseButtonReleased)
			{
				if (e.mouseButton.button == sf::Mouse::Left)
				{
					return true;
				}
			}
		}
		return false;
	}

	void Rectangle::setColorOnHover(sf::Color couleur)
	{
		setColorOnHover(getFillColor(), couleur);
	}

	void Rectangle::setColorOnHover(sf::Color base, sf::Color hover)
	{
		setFillColor(base);
		m_baseColor = base;
		m_hoverColor = hover;
	}
	void Rectangle::setOutlineColorOnHover(sf::Color couleur)
	{
		setColorOnHover(getOutlineColor(), couleur);
	}
	void Rectangle::setOutlineColorOnHover(sf::Color base, sf::Color hover)
	{
		setOutlineColor(base);
		m_outlineBaseColor = base;
		m_outlinehoverColor = hover;
	}

	void Rectangle::setPointRedi(float x, float y)
	{
		m_posRx = x;
		m_posRy = y;

		update();
	}

	sf::Vector2f Rectangle::getPointRedi()
	{
		return sf::Vector2f(m_posRx, m_posRy);
	}

	void Rectangle::setOrigineAsCenter()
	{
		sf::FloatRect r = m_rectangle.getGlobalBounds();
		m_rectangle.setOrigin(r.width / (2.0 * m_rectangle.getScale().x), r.height / (2.0 * m_rectangle.getScale().y));
		m_isOrigineAsCenter = true;

		update();
	}

}}