#ifndef EFFECT_HPP
#define EFFECT_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics.hpp>
#include <cassert>
#include <string>


////////////////////////////////////////////////////////////
// Base class for effects
////////////////////////////////////////////////////////////
namespace game
{
	class Effect : public sf::Drawable
	{
		public :
			Effect() {m_isLoaded = false;};

			void load()
			{
				m_isLoaded = sf::Shader::isAvailable() && onLoad();
			}

			void update(float time, float x, float y)
			{
				if (m_isLoaded) onUpdate(time, x, y);
			}

			void draw(sf::RenderTarget& target, sf::RenderStates states) const
			{
				if (m_isLoaded)
				{
					onDraw(target, states);
				}
				else
				{
				
				}
			}

		private :
			// Virtual functions to be implemented in derived effects
			virtual bool onLoad() = 0;
			virtual void onUpdate(float time, float x, float y) = 0;
			virtual void onDraw(sf::RenderTarget& target, sf::RenderStates states) const = 0;

			bool m_isLoaded;

	};
};

////////////////////////////////////////////////////////////
// "Storm" vertex shader + "blink" fragment shader
////////////////////////////////////////////////////////////
namespace game
{
	class StormBlink : public Effect
	{
		public :
			bool onLoad()
			{
				// Create the points
				m_points.setPrimitiveType(sf::Points);
				for (int i = 0; i < 40000; ++i)
				{
					float x = static_cast<float>(std::rand() % 800);
					float y = static_cast<float>(std::rand() % 600);
					sf::Uint8 r = std::rand() % 255;
					sf::Uint8 g = std::rand() % 255;
					sf::Uint8 b = std::rand() % 255;
					m_points.append(sf::Vertex(sf::Vector2f(x, y), sf::Color(r, g, b)));
				}

				// Load the shader
				if (!m_shader.loadFromFile("Res/Shaders/storm.vert", "Res/Shaders/blink.frag"))
					return false;

				return true;
			}

			void onUpdate(float time, float x, float y)
			{
				float radius = 200 + std::cos(time) * 150;
				m_shader.setParameter("storm_position", x, y);
				m_shader.setParameter("storm_inner_radius", radius / 3);
				m_shader.setParameter("storm_total_radius", radius);
				m_shader.setParameter("blink_alpha", 0.5f + std::cos(time * 3) * 0.25f);
			}

			void onDraw(sf::RenderTarget& target, sf::RenderStates states) const
			{
				states.shader = &m_shader;
				target.draw(m_points, states);
			}

		private:
			sf::VertexArray m_points;
			sf::Shader m_shader;
	};
};
#endif // EFFECT_HPP
