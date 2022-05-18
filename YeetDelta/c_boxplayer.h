#pragma once
#include "c_boxcanvas.h"
#include "c_gameobject.h"
#include "c_inputobject.h"











namespace delta {
	namespace game {
		class c_boxplayer : public objects::c_gameobject, public objects::c_inputobject {
		public:
			inline c_boxplayer(){}


			yeet::yeetvec2 m_position = yeet::yeetvec2(100,100);

			c_boxcanvas m_canvas;

			float m_jumpframe = 0;
			float m_downframe = 0;

			float m_playerjumpspeed = 10000;
			float m_playerwalkspeed = 5000;
			// Inherited via c_gameobject
			virtual void create() override;

			virtual void update() override;

			virtual void destroy() override;


			// Inherited via c_inputobject
			virtual void on_key_up(int key) override;

			virtual void on_key_down(int key) override;

		};
	}
}