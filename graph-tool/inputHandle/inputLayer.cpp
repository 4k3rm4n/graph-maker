#include "inputLayer.h"

#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/RectangleShape.hpp>


InputLayer::InputLayer(const std::string& name)
	: Layer(name)
{

}

void InputLayer::onAttach()
{

}

void InputLayer::onDetach()
{

}

void InputLayer::onUpdate(sf::Time frameTime)
{

}

void InputLayer::onRender(std::shared_ptr<sf::RenderWindow> window, const RenderZone& zone)
{
	sf::RectangleShape zoneRect({ zone.width, zone.height });
	zoneRect.setFillColor(sf::Color::Black);

	window->draw(zoneRect);
}

void InputLayer::onEvent(const sf::Event& event)
{

}
