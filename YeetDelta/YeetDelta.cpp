#include "base_window.h"
#include "c_gamemanager.h"



delta::c_gamemanager* m_gamemanager = nullptr;
int  main(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
    base_window* window = new base_window(hInstance, "YeetDelta", "Yeet_Window");

	if (!window->create()) {
		spdlog::error("failed to create window");
		system("pause");
		return -1;
	}

	D3DCOLOR clear_color = D3DCOLOR_RGBA(35, 35, 35, 125);

	auto device = window->get_d3dbase()->get_device();
	ImGui::CreateContext();
	ImGui_ImplWin32_Init(window->get_window());
	ImGui_ImplDX9_Init(device);


	m_gamemanager = new delta::c_gamemanager();
	m_gamemanager->on_create();
	m_gamemanager->m_basewindow = window->get_window();

	bool done = false;

	while (!done) {
		MSG msg;
		m_gamemanager->m_frametimer.tick();
		while (::PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
		{
			::TranslateMessage(&msg);
			::DispatchMessage(&msg);
			if (msg.message == WM_QUIT)
				done = true;
		}
		if (done)
			break;
		ImGui_ImplDX9_NewFrame();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();
		if (m_gamemanager->is_active)
			m_gamemanager->on_update();
		//drawings
		ImGui::EndFrame();
		device->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, clear_color, 1.0f, 0);
		if (device->BeginScene() >= 0) {
			ImGui::Render();
			ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
			device->EndScene();
		}
		HRESULT result = device->Present(NULL, NULL, NULL, NULL);

	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
