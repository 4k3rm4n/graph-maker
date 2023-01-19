#pragma once

#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include <string>


class Layer
{
public:
	Layer(const std::string& name = "")
		: _name(name) {}

	virtual void onAttach() {};
	virtual void onDetach() {};

	virtual void onUpdate(sf::Time frameTime) {};
	virtual void onRender(std::shared_ptr<sf::RenderWindow> window, sf::View& view) {};
	virtual void onEvent(const sf::Event& event) {};

	const std::string& getName() { return _name; };

protected:
	std::string _name;
};
