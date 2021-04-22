#ifndef ENGINE_EEFFECT_HPP
#define ENGINE_EEFFECT_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics.hpp>


#include <cassert>
#include <string>


#ifdef _WIN32
#include "include/debug.h"
#endif


////////////////////////////////////////////////////////////
// Base class for effects
////////////////////////////////////////////////////////////
class EEffect : public sf::Drawable
{
public:

    virtual ~EEffect()
    {
    }

    static void setFont(const sf::Font& font)
    {
        s_font = &font;
    }

    const std::string& getName() const
    {
        return m_name;
    }

    void load()
    {
        m_isLoaded = sf::Shader::isAvailable() && onLoad();
    }

    void update(float delta_t)
    {
        if (m_isLoaded)
            onUpdate(delta_t);
    }

    void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        if (m_isLoaded)
        {
            onDraw(target, states);
        }
        else
        {
			DEBUG->Log("EEffect", "Shader not supported, or effect no loaded yet!");
        }
    }

	void handleInput(sf::Event& e, sf::RenderWindow& window) 
	{
		if (m_isLoaded)
		{
			onHandleInput(e, window);
		}
	}

protected:

    EEffect(const std::string& name) :
    m_name(name),
    m_isLoaded(false)
    {
    }

    static const sf::Font& getFont()
    {
        assert(s_font != NULL);
        return *s_font;
    }

	bool m_isLoaded;

protected:

    // Virtual functions to be implemented in derived effects
    virtual bool onLoad() = 0;
    virtual void onUpdate(float delta_t) = 0;
    virtual void onDraw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
	virtual void onHandleInput(sf::Event& event, sf::RenderWindow& window) = 0;

private:

    std::string m_name;

    static const sf::Font* s_font;
};

#endif // EFFECT_HPP
