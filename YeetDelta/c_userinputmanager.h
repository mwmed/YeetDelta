#pragma once
#include "yeet_includes.h"


















namespace delta {
	class c_userinputmanager {
	public:
		inline c_userinputmanager() {}


		void on_update();

		POINT get_cs();
	private:
		POINT m_previouscs;
		POINT m_currentcs;

		BYTE kbkeys[256];
		std::map<std::int8_t, bool> down_keys;


	};
}