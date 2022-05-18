#include "c_playermanager.h"
#include "delta_globals.h"


void delta::game::c_playermanager::create()
{
	m_localplayer = new c_boxplayer();

	m_gamemanager->m_objectmanager->m_inputobjects.push_back(m_localplayer);
}

void delta::game::c_playermanager::update()
{
	m_localplayer->update();

}

void delta::game::c_playermanager::destroy()
{
}
