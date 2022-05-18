#pragma once
#include "yeet_includes.h"













namespace yeet {
	class yeet_timer {
	public:
		inline yeet_timer() {}

		void tick();
		float get_elapsed_time();

	private:
		DWORD64 m_counts_per_sec = 0;
		DWORD64 m_prev = 0;
		float m_frame_count = 0;
	};
}