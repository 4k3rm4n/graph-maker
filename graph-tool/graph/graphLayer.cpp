#include "graphLayer.h"

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>


GraphLayer::GraphLayer(const std::string& name)
	: Layer(name)
{

}

void GraphLayer::onAttach()
{

}

void GraphLayer::onDetach()
{

}

void GraphLayer::onUpdate(sf::Time frameTime)
{

}

void GraphLayer::onRender(std::shared_ptr<sf::RenderWindow> window, sf::View& view)
{
	sf::RectangleShape zoneRect(view.getSize());

	window->draw(zoneRect);
}

void GraphLayer::onEvent(const sf::Event& event)
{

}
