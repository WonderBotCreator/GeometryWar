#pragma once

#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include <fstream>

class Assets
{
	std::map<std::string, sf::Texture> m_textureMap;
	std::map<std::string, Animation> m_animationMap;
	std::map<std::string, sf::Font> m_fontMap;

public:

	Assets() = default;

	void loadFromFile(const std::string& path);

	void addTexture(const std::string& textureName, const std::string path);
	const std::map<std::string, Animation>& getAnimations() const;
	const std::map<std::string, sf::Texture>& getTextures() const;
	const sf::Font& getFont(const std::string& fontName) const;
	const Animation& getAnimation(const std::string& animationName) const;
	const sf::Texture& getTexture(const std::string& textureName) const;
	void addAnimation(const std::string& animationName, const std::string& texture, size_t frames, size_t speed);
	void addFont(const std::string& fontName, const std::string& fontPath);
};

