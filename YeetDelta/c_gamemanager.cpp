#include "c_gamemanager.h"

void delta::c_gamemanager::on_update()
{
	m_inputmanager->on_update();

	m_playermanager->update();

	m_drawmanager->on_update();
}

void delta::c_gamemanager::on_create()
{
	m_drawmanager = new yeet::imyeet();
	m_objectmanager = new delta::c_objectmanager();
	m_inputmanager = new delta::c_userinputmanager();
	m_playermanager = new game::c_playermanager();
	m_playermanager->create();
}

double delta::c_gamemanager::get_deltatime()
{
	return m_frametimer.get_elapsed_time();
}
