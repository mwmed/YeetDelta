#include "c_boxplayer.h"
#include "delta_globals.h"
void delta::game::c_boxplayer::create()
{
	m_canvas.m_rectangle = ImVec4(m_position.x, m_position.y, m_position.x + 50, m_position.y + 50);
}

void delta::game::c_boxplayer::update()
{
	float delta = m_gamemanager->get_deltatime();

	if (m_jumpframe > 0.0) {
		float frame = m_jumpframe * delta + m_playerjumpspeed * delta;
		m_position.y -= frame;
		
		m_jumpframe -= frame;
		m_downframe += frame;
		if (m_jumpframe < 0.0f)
			m_jumpframe = 0.0f;

	}
	else if (m_downframe > 0.0) {
		float frame = m_downframe * delta + m_playerjumpspeed * delta;
		m_position.y += frame;
		m_downframe -= frame;
		if (m_downframe < 0.0f)
			m_downframe = 0.0f;
	}


	m_canvas.m_rectangle = ImVec4(m_position.x, m_position.y, m_position.x + 50, m_position.y + 50);
	m_canvas.update();
}

void delta::game::c_boxplayer::destroy()
{
}

void delta::game::c_boxplayer::on_key_up(int key)
{
}

void delta::game::c_boxplayer::on_key_down(int key)
{
	float walk_frame = m_gamemanager->get_deltatime() * m_playerwalkspeed;
	switch (key) {
	case 'W':

		m_position.y -= walk_frame;
		break;
	case 'S':
	{
		m_position.y += walk_frame;
		break;
	}
	case 'D':
	{
		m_position.x += walk_frame;
		break;
	}
	case 'A':
	{
		m_position.x -= walk_frame;
		break;
	}
	case VK_SPACE:
		if(m_jumpframe == 0 && m_downframe == 0)
			m_jumpframe = 150;
		break;
	default:
		//spdlog::info("{}", key);
		break;

	}
}
