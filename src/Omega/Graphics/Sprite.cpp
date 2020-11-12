#include "Graphics/Sprite.h"


namespace O{
namespace graphics {
	Sprite::Sprite()
	{

	}

	Sprite::Sprite(sf::RenderWindow* window, std::string textureName, float x, float y, float posRx, float posRy, bool centered) :
		m_fen(window),
		m_x(x), m_y(y), m_textureName(textureName),
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

	Sprite::Sprite(sf::RenderWindow* window, std::string textureName, float x, float y, bool centered) :
		Sprite(window, textureName, x, y, 0, 0, centered)
	{

	}



	void Sprite::loadTexture()
	{
		m_sprite.setTexture(ressourceManager.getTexture(m_textureName));

		if (m_isOrigineAsCenter)
		{
			setOrigineAsCenter();
		}
		else
		{
			update();
		}
		
	}

	void Sprite::loadTexture(sf::Texture& tex)
	{

		m_sprite.setTexture(tex);

		if (m_isOrigineAsCenter)
		{
			setOrigineAsCenter();
		}
		else
		{
			update();
		}
	}

	void Sprite::event(sf::Event e)
	{
		if (e.type == sf::Event::Resized)
		{
			update();
		}	
	}

	void Sprite::update()
	{
		//facteur de redimentionnement
		float factorX = (float)m_fen->getSize().x / STATIC::SYS::WIDTH;
		float factorY = (float)m_fen->getSize().y / STATIC::SYS::HIGHT;

		
		m_sprite.setPosition(m_x + (factorX - 1) * m_posRx, m_y + (factorY - 1) * m_posRy);
	}

	// void Sprite::update(float viewZoom)
	// {
	// 	setScale(viewZoom, viewZoom);
		
	// 	//facteur de redimentionnement
	// 	float factorX = (float)m_fen->getSize().x / STATIC::SYS::WIDTH;
	// 	float factorY = (float)m_fen->getSize().y / STATIC::SYS::HIGHT;

	// 	m_sprite.setPosition(m_x + (factorX - 1) * m_posRx * viewZoom, m_y + (factorY - 1) * m_posRy * viewZoom);
	// }

	void Sprite::draw()
	{
		m_fen->draw(m_sprite);
	}

	void Sprite::draw(sf::FloatRect bound)
	{
		if (bound.intersects(m_sprite.getGlobalBounds()))
		{
			m_fen->draw(m_sprite);
		}
	}

	void Sprite::setColor(sf::Color c)
	{
		m_sprite.setColor(c);
	}

	sf::Sprite& Sprite::gS()
	{
		return m_sprite;
	}

	void Sprite::setPosition(float x, float y)
	{
		m_x = x;
		m_y = y;
		update();
	}
	sf::Vector2f Sprite::getPosition()
	{
		return sf::Vector2f(m_x, m_y);
	}

	void Sprite::move(float x, float y)
	{
		setPosition(getPosition().x + x, getPosition().y + y);
	}
	void Sprite::setScale(float x, float y)
	{
		m_sprite.setScale(x, y);
	}

	bool Sprite::hover()
	{
		auto p = sf::Mouse::getPosition(*m_fen);
		return (m_sprite.getGlobalBounds().contains(p.x, p.y));
	}

	bool Sprite::clicked(sf::Event e)
	{
		if (e.type == sf::Event::MouseButtonPressed)
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

	void Sprite::setPointRedi(float x, float y)
	{
		m_posRx = x;
		m_posRy = y;
	}

	void Sprite::setOrigineAsCenter()
	{
		sf::FloatRect r = m_sprite.getGlobalBounds();
		m_sprite.setOrigin(r.width / (2.0 * m_sprite.getScale().x), r.height / (2.0 * m_sprite.getScale().y));
		m_isOrigineAsCenter = true;

		update();
	}

}
}