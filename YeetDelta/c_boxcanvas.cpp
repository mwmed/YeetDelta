#include "c_boxcanvas.h"
#include "delta_globals.h"


void delta::game::c_boxcanvas::update()
{
	m_gamemanager->m_drawmanager->add_rect(m_rectangle, m_color, true);

}
