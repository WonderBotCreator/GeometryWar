#include "Assets.h"
#include <cassert>

void Assets::loadFromFile(const std::string& path)
{
	std::ifstream file(path);
	std::string str;
	while (file.good())
	{
		file >> str;
		if (str == "Texture")
		{
			std::string name, path;
			file >> name >> path;
			addTexture(name, path);
		}
		else if (str == "Animation")
		{
			std::string name, texture;
			size_t frames, speed;
			file >> name >> texture >> frames >> speed;
			addAnimation(name, texture, frames, speed);
		}
		else if (str == "Font")
		{
			std::string name, path;
			file >> name >> path;
			addFont(name, path);
		}
		else
		{
			std::cerr << "Unknown Asset Type: " << str << std::endl;
		}
	}
}

void Assets::addTexture(const std::string& textureName, const std::string path)
{
	m_textureMap[textureName] = sf::Texture();

	if (!m_textureMap[textureName].loadFromFile(path))
	{
		std::cerr << "Could not load texture file: " << path;
		m_textureMap.erase(textureName);
	}
	else
	{
		//m_textureMap[textureName].setSmooth(smoo)
		std::cout << "Loaded texture: " << path << std::endl;
	}
}

const std::map<std::string, Animation>& Assets::getAnimations() const
{
	return m_animationMap;
}

const std::map<std::string, sf::Texture>& Assets::getTextures() const
{
	return m_textureMap;
}

const sf::Font& Assets::getFont(const std::string& fontName) const
{
	// TODO: insert return statement here
	assert(m_fontMap.find(fontName) != m_fontMap.end());
	return m_fontMap.at(fontName);
}

const Animation& Assets::getAnimation(const std::string& animationName) const
{
	// TODO: insert return statement here
	assert(m_animationMap.find(animationName) != m_animationMap.end());
	return m_animationMap.at(animationName);
}

const sf::Texture& Assets::getTexture(const std::string& textureName) const
{
	// TODO: insert return statement here
	assert(m_textureMap.find(textureName) != m_textureMap.end());
	return m_textureMap.at(textureName);
}

void Assets::addAnimation(const std::string& animationName, const std::string& texture, size_t frames, size_t speed)
{
}

void Assets::addFont(const std::string& fontName, const std::string& fontPath)
{
	m_fontMap[fontName] = sf::Font();
	if (!m_fontMap[fontName].loadFromFile(fontPath))
	{
		std::cerr << "Could not load font file: " << fontPath << std::endl;
		m_fontMap.erase(fontName);
	}
	else
	{
		std::cout << "Loaded Font: " << fontPath << std::endl;
	}
}


