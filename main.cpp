#include<SFML/Graphics.hpp>
#include<iostream>
#include<memory>
#include<fstream>
#include "Vec2.cpp"


int main()
{
	//std::cout << "Hello world!" << std::endl;
	const int wWidth = 640;
	const int wHeight = 480;
	sf::RenderWindow window(sf::VideoMode(wWidth, wHeight), "SFML works!");
	window.setFramerateLimit(60);

	//ImGui

	sf::CircleShape circle(50);
	circle.setFillColor(sf::Color::Green);
	circle.setPosition(300.0f, 300.0f);
	int circleMoveSpeed = 0.1f;

	float rx = 300;
	float ry = 200;
	sf::Vector2f rSize(rx, ry);
	sf::RectangleShape rect(rSize);
	rect.setPosition(100, 20);
	rect.setFillColor(sf::Color(255, 0, 0));
	rect.setOutlineColor(sf::Color::Yellow);
	rect.setOutlineThickness(20.0f);

	sf::Font myFont;

	/*if (!myFont.loadFromFile("fonts/tuffy.ttf"))
	{
		std::cerr << "Could not load the font!!\n";
		exit(-1);
	}*/

	/*sf::text text("sample text", myfont, 24);
	text.setposition(0, wheight - (float)text.getcharactersize());

	while (window.isopen())
	{
		sf::event event;
		while (window.pollevent(event))
		{
			if (event.type == sf::event::closed)
			{
				window.close();
			}

			if(event.type == sf::event::keypressed)
			{
				std::cout << "key pressed with code = " << event.key.code << "\n";
			}

			if (event.key.code == sf::keyboard::x)
			{
				circlemovespeed *= -1.0f;
			}
		}

		float sx = 0.5;
		float sy = 0.5;
		circle.setposition(circle.getposition().x + sx, circle.getposition().y + sy);
		rect.rotate(0.1);

		window.clear();
		window.draw(circle);
		window.draw(rect);
		window.draw(text);
		window.display();
	}*/


	Vec2 v1(5.0, 6.5);
	Vec2 v2(10.1, 20.1);

	Vec2 v3 = (v1 + v2) * 2;
	//v3.scale(3);

	Vec2 v4 = v1.add(v2).add(v2);

	std::cout << "Here's your vector v3" << v3.x << " " << v3.y << "\n";
	std::cout << "Here's your vector v4 " << v4.x << " " << v4.y << "\n";

	return 0;
}