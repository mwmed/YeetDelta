#include "c_objectmanager.h"

void delta::c_objectmanager::on_input_broadcast(int m_key, input_type type)
{
	for (auto object : m_inputobjects) {
		switch (type) {
		case input_type::down:
			object->on_key_down(m_key);
			break;
		case input_type::up:
			object->on_key_up(m_key);
			break;
		}
	}
}
