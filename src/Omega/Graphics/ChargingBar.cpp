#include "Graphics/ChargingBar.h"

namespace O{
namespace graphics{



ChargingBar::ChargingBar()
{

}

ChargingBar::ChargingBar(sf::RenderWindow* window, float x, float y, float sizeX, float sizeY, float posRx, float posRy, bool centered):
	m_fen(window),
	m_backgroundRect(window, x,y,sizeX,sizeY, posRx, posRy, centered),
	m_foregroundRect(window, 0, 0, 0, sizeY, 0, 0)
{
	m_backgroundRect.setFillColor(sf::Color(25, 25, 25));
	m_foregroundRect.setFillColor(sf::Color(255, 110, 110));

	if (centered)
	{
		setOrigineAsCenter();
	}
	else
		update();
}

ChargingBar::ChargingBar(sf::RenderWindow* window, float x, float y, float sizeX, float sizeY, bool centered) :
	ChargingBar(window, x, y, sizeX, sizeY, -1,-1, centered)
{

}

void ChargingBar::setChargingValue(float value)
{
	if (value >= m_minCharge && value <= m_maxCharge)
	{
		m_chargeValue = value;
		m_chargingPercent = (m_chargeValue - m_minCharge) / (m_maxCharge - m_minCharge);

		update();
	}
}

float ChargingBar::getChargingValue()
{
	return 0.0f;
}

void ChargingBar::setMinChargingValue(double value)
{
	m_minCharge = value;
	update();
}

void ChargingBar::setMaxChargingValue(double value)
{
	m_maxCharge = value;
	update();
}

bool ChargingBar::hover()
{
	return m_backgroundRect.hover();
}

bool ChargingBar::clicked(sf::Event& e)
{
	return m_backgroundRect.clicked(e);
}

void ChargingBar::event(sf::Event& e)
{
	if (e.type == sf::Event::Resized)
	{
		update();
	}
}

void ChargingBar::update()
{
	m_backgroundRect.update();
	updatePosForeground();
	m_foregroundRect.update();
}


void ChargingBar::setPosition(float x, float y)
{
	m_backgroundRect.setPosition(x, y);
}


void ChargingBar::setPosition(float x, float y, bool update)
{
	m_backgroundRect.setPosition(x, y);
	if (update) this->update();
}

void ChargingBar::move(float x, float y)
{
	m_backgroundRect.move(x,y);
	update();
}


void ChargingBar::setBackgroundColor(sf::Color c)
{
	m_backgroundRect.setFillColor(c);
}

void ChargingBar::setForgroundColor(sf::Color c)
{
	m_foregroundRect.setFillColor(c);
}

void ChargingBar::setOutlineThickness(double size)
{
	m_backgroundRect.setOutlineThickness(size);
	update();
}

void ChargingBar::setSize(float x, float y)
{
	m_backgroundRect.setSize(x, y);
	update();
}

double ChargingBar::getOutlineThickness()
{
	return m_backgroundRect.getOutlineThickness();
}

void ChargingBar::setOutlineColor(sf::Color c)
{
	m_backgroundRect.setOutlineColor(c);
}

void ChargingBar::draw()
{
	m_backgroundRect.draw();
	m_foregroundRect.draw();
}

void ChargingBar::updatePosForeground(double viewZoom)
{
	sf::FloatRect bounds = m_backgroundRect.gR().getGlobalBounds();

	m_foregroundRect.setPosition(bounds.left + getOutlineThickness(), bounds.top + getOutlineThickness());
	m_foregroundRect.setSize(m_backgroundRect.getSize().x * m_chargingPercent, m_backgroundRect.getSize().y);
}

void ChargingBar::setOrigineAsCenter()
{
	m_isOrigineAsCenter = true;
	m_backgroundRect.setOrigineAsCenter();

	update();
}


}}