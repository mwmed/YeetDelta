#pragma once
#include "c_boxplayer.h"
















namespace delta {
	namespace game {
		class c_playermanager : public objects::c_gameobject {
		public:
			inline c_playermanager(){}
			c_boxplayer* m_localplayer = nullptr;

			
			// Inherited via c_gameobject
			virtual void create() override;
			virtual void update() override;
			virtual void destroy() override;
		};
	}
}