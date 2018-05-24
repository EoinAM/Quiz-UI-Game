#include "Animation.h"

Animation::Animation(sf::RectangleShape & t_shape, int t_noFrames, sf::Texture & t_texture, sf::IntRect & t_intRect) :
	m_body(t_shape),
	m_texture(t_texture),
	m_frames(t_noFrames),
	m_intrect(t_intRect)
{
}

Animation::~Animation()
{
}

void Animation::update()
{
	m_timer++;
	if (m_timer <= m_delay * m_currentFrame)
	{
		if (m_currentFrame < m_frames * .5)
		{
			m_body.setTextureRect(sf::IntRect(m_intrect.width * m_currentFrame, m_intrect.top, m_intrect.width, m_intrect.height));
		}

		if (m_currentFrame >= m_frames * .5)
		{
			m_intrect.top = m_intrect.height;
			m_body.setTextureRect(sf::IntRect(m_intrect.width * (m_currentFrame - (m_frames * .5)), m_intrect.top, m_intrect.width, m_intrect.height));
		}
	}
	
	std::cout << m_currentFrame << std::endl;
	if (m_currentFrame >= m_frames)
	{
		m_timer = 0;
		m_currentFrame = 0;
		m_intrect.top = 0;
	}
	if (m_timer >= m_delay * m_currentFrame)
	{
		m_currentFrame++;
	}
}

