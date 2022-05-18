#pragma once
#include "yeet_includes.h"
#include "yeet_math.h"












namespace delta {
	namespace game {
		class c_boxcanvas {
		public:
			inline c_boxcanvas(){}


			ImVec4 m_rectangle;
			ImU32 m_color = 0xFFFFFFFF;

			void update();
		};
	}
}