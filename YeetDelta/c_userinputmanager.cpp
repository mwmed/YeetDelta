#include "c_userinputmanager.h"
#include "delta_globals.h"

void delta::c_userinputmanager::on_update()
{
    if (GetKeyboardState(kbkeys)) {
        for (int i = 0; i < 256; i++) {
            if (kbkeys[i] & 0x80) {
                down_keys[i] = true;

                m_gamemanager->m_objectmanager->on_input_broadcast(i, input_type::down);
            }
            else if (down_keys[i]) {
                down_keys[i] = false;
                m_gamemanager->m_objectmanager->on_input_broadcast(i, input_type::up);
            }
        }
    }
}

POINT delta::c_userinputmanager::get_cs()
{
    return m_currentcs;
}
