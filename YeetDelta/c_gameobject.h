#pragma once
#include "yeet_includes.h"














namespace delta {
	namespace objects {
		class c_gameobject {
		public:
			virtual void create() = 0;
			virtual void update() = 0;
			virtual void destroy() = 0;
		};
	}
}