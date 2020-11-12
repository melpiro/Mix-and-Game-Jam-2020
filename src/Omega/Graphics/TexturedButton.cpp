#include "Graphics/TexturedButton.h"


namespace O{
namespace graphics {
	TexturedButton::TexturedButton()
	{
		graphics::Text::setOrigineAsCenter();
	}

	TexturedButton::TexturedButton(sf::RenderWindow* fen, std::string textureName, std::string fontName, float x, float y, float posRx, float posRy, bool centered) :
		m_fen(fen),
		Sprite(fen, textureName, x, y, posRx, posRy, centered),
		Text(fen, fontName, x, y, 0, 0, true)// le texte est toujour centr� !
	{
		m_rectB = sf::IntRect(-1, -1, -1, -1);
		m_rectHover = sf::IntRect(-1, -1, -1, -1);

		if (centered) setOrigineAsCenter();
		else update();
	}

	TexturedButton::TexturedButton(sf::RenderWindow* fen, std::string textureName, std::string fontName, float x, float y, bool centered):
		TexturedButton(fen, textureName, fontName, x, y, 0, 0, centered)
	{

	}

	void TexturedButton::loadRessources()
	{
		Sprite::loadTexture();
		Text::loadFont();

		if (m_rectB.height == -1 && m_rectB.width == -1)
			calcNoRectHover();

	}
	void TexturedButton::loadRessources(sf::Texture& tex)
	{
		Sprite::loadTexture(tex);
		Text::loadFont();

		if (m_rectB.height == -1 && m_rectB.width == -1) 
			calcNoRectHover();
	}
	
	void TexturedButton::loadRessources(sf::Font &font)
	{
		Sprite::loadTexture();
		Text::loadFont(font);

		if (m_rectB.height == -1 && m_rectB.width == -1) 
			calcNoRectHover();
	}
	void TexturedButton::loadRessources(sf::Texture &tex, sf::Font &font)
	{
		Sprite::loadTexture(tex);
		Text::loadFont(font);

		if (m_rectB.height == -1 && m_rectB.width == -1) 
			calcNoRectHover();
	}


	bool TexturedButton::hover()
	{
		bool isIn = Sprite::hover();
		if (isIn)
		{
			gS().setTextureRect(m_rectHover);
			update();
		}
		else
		{
			gS().setTextureRect(m_rectB);
			update();
		}
		return isIn;
	}

	bool TexturedButton::clicked(sf::Event& e)
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
	
	void TexturedButton::event(sf::Event e)
	{
		if (e.type==sf::Event::Resized)
		{
			TexturedButton::update();
		}
	}

	void TexturedButton::update()
	{
		Sprite::update();
		updatePosText();
	}



	void TexturedButton::draw()
	{
		Sprite::draw();
		Text::draw();
	}

	void TexturedButton::setRectButton(sf::IntRect rectB, sf::IntRect rectHover)
	{
		m_rectB = rectB;
		m_rectHover = rectHover;
		gS().setTextureRect(rectB);
		if (Sprite::m_isOrigineAsCenter) Sprite::setOrigineAsCenter();
	}

	void TexturedButton::setPosition(float x, float y)
	{
		Sprite::setPosition(x, y);
		update();
	}

	void TexturedButton::move(float x, float y)
	{
		TexturedButton::setPosition(Sprite::getPosition().x + x, Sprite::getPosition().y + y);
	}

	void TexturedButton::setPointRedi(float x, float y)
	{
		Sprite::m_posRx = x;
		Sprite::m_posRy = y;
		Text::m_posRx = x;
		Text::m_posRy = y;
	}

	void TexturedButton::setOrigineAsCenter()
	{
		Sprite::setOrigineAsCenter();
		update();
	}

	void TexturedButton::updatePosText()
	{
		sf::FloatRect rect = m_sprite.getGlobalBounds();
		Text::setPosition(rect.left + rect.width / 2.0, rect.top + rect.height / 2.0);
		Text::update();
	}

	void TexturedButton::setTextColor(sf::Color c)
	{
		m_text.setFillColor(c);
	}

	void TexturedButton::calcAutoRectHover()
	{
		auto b = m_sprite.getGlobalBounds();
		sf::Vector2u size(b.width, b.height);
		m_rectB = sf::IntRect(0, 0, size.x, size.y / 2.0);
		m_rectHover = sf::IntRect(0, size.y / 2.0, size.x, size.y / 2.0);
	}

	void TexturedButton::calcNoRectHover()
	{
		auto b = m_sprite.getGlobalBounds();
		sf::Vector2u size(b.width, b.height);
		m_rectB = sf::IntRect(0, 0, size.x, size.y);
		m_rectHover = sf::IntRect(0, 0, size.x, size.y);
	}


}
}