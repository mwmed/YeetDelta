#pragma once
#include "c_inputobject.h"

#include "deltaconstants.h"













namespace delta {
	class c_objectmanager {
	public:

		std::vector<objects::c_inputobject*> m_inputobjects;


		void on_input_broadcast(int m_key, input_type type);

	};
}