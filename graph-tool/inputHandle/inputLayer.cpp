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

void InputLayer::onRender(std::shared_ptr<sf::RenderWindow> window, sf::View& view)
{
	sf::RectangleShape zoneRect(view.getSize());
	zoneRect.setFillColor(sf::Color::Black);

	window->draw(zoneRect);
}

void InputLayer::onEvent(const sf::Event& event)
{

}
