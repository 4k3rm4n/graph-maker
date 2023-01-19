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

void GraphLayer::onRender(std::shared_ptr<sf::RenderWindow> window, const RenderZone& zone)
{
	auto windowSize = window->getSize();
	sf::RectangleShape zoneRect({ zone.width, zone.height });
	zoneRect.move({ window->getSize().x - zone.width, 0 });

	window->draw(zoneRect);
}

void GraphLayer::onEvent(const sf::Event& event)
{

}
