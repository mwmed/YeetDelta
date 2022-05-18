#pragma once
#include "imyeet.h"
#include "c_objectmanager.h"
#include "c_userinputmanager.h"
#include "c_playermanager.h"

#include "yeet_timer.h"





namespace delta {
	class c_gamemanager {
	public:
		inline c_gamemanager() {
	
		}



	

	public:
		yeet::imyeet* m_drawmanager = nullptr;
		delta::c_objectmanager* m_objectmanager = nullptr;
		delta::c_userinputmanager* m_inputmanager = nullptr;
		game::c_playermanager* m_playermanager = nullptr;

	public:
		HWND m_basewindow = 0;
		bool is_active = true;
		yeet::yeet_timer m_frametimer;

	public:
		void on_update();
		void on_create();
	public:
		double get_deltatime();
	};
}