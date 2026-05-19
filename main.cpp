#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <fstream>
#include "Vec2.cpp"
#include <SFML/Window.hpp>
#include "imgui.h"
#include "imgui-SFML.h"

int main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;

	// std::cout << "Hello world!" << std::endl;
	const int wWidth = 640;
	const int wHeight = 480;
	sf::RenderWindow window(sf::VideoMode({wWidth, wHeight}), "SFML works!");
	window.setFramerateLimit(60);

	if (!ImGui::SFML::Init(window))
	{
		std::cerr << "Failed to initialize ImGui-SFML\n";
		return 1;
	}
	sf::Clock deltaClock;

	sf::CircleShape circle(50);
	circle.setFillColor(sf::Color::Green);
	circle.setPosition({300.0f, 300.0f});
	int circleMoveSpeed = 0.1f;

	float rx = 300;
	float ry = 200;
	sf::Vector2f rSize(rx, ry);
	sf::RectangleShape rect(rSize);
	rect.setPosition({100, 20});
	rect.setFillColor(sf::Color(255, 0, 0));
	rect.setOutlineColor(sf::Color::Yellow);
	rect.setOutlineThickness(20.0f);

	sf::Font myFont;

	if (!myFont.openFromFile("fonts/tuffy.ttf"))
	{
		std::cerr << "Could not load the font!!\n";
		exit(-1);
	}

	sf::Text text(myFont);
	text.setString("My Font is here!!!");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Red);

	while (window.isOpen())
	{
		while (const std::optional event = window.pollEvent())
		{
			ImGui::SFML::ProcessEvent(window, *event);

			if (event->is<sf::Event::Closed>())
			{
				window.close();
			}

			if (const auto *keyPressed = event->getIf<sf::Event::KeyPressed>())
			{
				std::cout << "key pressed with code = " << sf::Keyboard::KeyCount << "\n";

				if (keyPressed->scancode == sf::Keyboard::Scan::X)
				{
					circleMoveSpeed *= -1.0f;
				}
			}
		}

		ImGui::SFML::Update(window, deltaClock.restart());

		ImGui::Begin("Debug");
		ImGui::Text("Circle position: (%.1f, %.1f)", circle.getPosition().x, circle.getPosition().y);
		ImGui::SliderInt("Circle move speed", &circleMoveSpeed, -10, 10);
		ImGui::End();

		float sx = static_cast<float>(circleMoveSpeed) * 0.05f;
		float sy = static_cast<float>(circleMoveSpeed) * 0.05f;
		circle.setPosition({circle.getPosition().x + sx, circle.getPosition().y + sy});
		rect.rotate(sf::radians(0.1));

		window.clear();
		window.draw(circle);
		window.draw(rect);
		window.draw(text);
		ImGui::SFML::Render(window);
		window.display();
	}

	ImGui::SFML::Shutdown();

	// Vec2 v1(5.0, 6.5);
	// Vec2 v2(10.1, 20.1);

	// Vec2 v3 = (v1 + v2) * 2;
	// v3.scale(3);

	// Vec2 v4 = v1.add(v2).add(v2);

	// std::cout << "Here's your vector v3" << v3.x << " " << v3.y << "\n";
	// std::cout << "Here's your vector v4 " << v4.x << " " << v4.y << "\n";

	// sf::Window window(sf::VideoMode({800, 600}), "New Vindow");
	// window.setVerticalSyncEnabled(true);

	// while (window.isOpen())
	// {
	// 	while (const std::optional event = window.pollEvent())
	// 	{
	// 		if (event->is<sf::Event::Closed>())
	// 		{
	// 			window.close();
	// 		}
	// 	}
	// }

	return 0;
}