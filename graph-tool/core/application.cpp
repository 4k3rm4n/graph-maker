#include "application.h"

#include "inputHandle/inputLayer.h"
#include "graph/graphLayer.h"

#include <iostream>


Application::Application(const ApplicationDescription& desc)
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 4;

	_window = std::make_shared<sf::RenderWindow>(sf::VideoMode(desc.windowWidth, desc.windowHeight), desc.name, sf::Style::Default, settings);
	_window->setFramerateLimit(desc.FPS);

    _clearColor = desc.clearColor;

    auto windowSize = _window->getSize();

    sf::View view1(sf::FloatRect(0, 0, windowSize.x, windowSize.y));
    view1.setViewport({ 0.f, 0.f, _windowDivider, 1.f });
    _layerStack.push_back({ new InputLayer("InputLayer"), view1 });

    sf::View view2(sf::FloatRect(0, 0, windowSize.x, windowSize.y));
    view2.setViewport({ _windowDivider, 0.f, 1.f, 1.f });
    _layerStack.push_back({ new GraphLayer("GraphLayer"), view2 });

    for (auto layerDesc : _layerStack)
        layerDesc.layer->onAttach();
}

void Application::run()
{
    sf::Clock clock;
    sf::Time start, end, frameTime;

    bool render = true;

    while (_window->isOpen())
    {
        clock.restart();
        start = clock.getElapsedTime();
       
        sf::Event event;

        while (_window->pollEvent(event))
        {
            onEvent(event);

            if (_closed)
                break;

            for (auto layerDesc : _layerStack)
                layerDesc.layer->onEvent(event);

            render = true;
        }

        if (_closed)
            break;

        end = clock.getElapsedTime();
        frameTime = end - start;

        for (auto layerDesc : _layerStack)
            layerDesc.layer->onUpdate(frameTime);

        if (render)
            onRender();

        _window->display();

        render = false;
    }
}

void Application::onEvent(const sf::Event& event)
{
    if (event.type == sf::Event::Closed)
    {
        exit();
    }
}

void Application::onRender()
{
    _window->clear(_clearColor);

    for (auto layerDesc : _layerStack)
    {
        _window->setView(layerDesc.view);
        layerDesc.layer->onRender(_window, layerDesc.view);
    }
}

void Application::exit()
{
    for (auto layerDesc : _layerStack)
        layerDesc.layer->onDetach();

    for (auto layerDesc : _layerStack)
        delete layerDesc.layer;

    _window->close();

    _closed = true;
}
