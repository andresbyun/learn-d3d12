#include "HelloWindow.h"

HelloWindow::HelloWindow(UINT width, UINT height, LPCWSTR name) :
	w_width(width), w_height(height), w_title(name)
{
	
}

void HelloWindow::OnInit() {
	
}

void HelloWindow::OnUpdate() {}

void HelloWindow::OnRender() {}

void HelloWindow::OnDestroy() {
	// Ensure that the GPU is no longer referencing resources that are about to be cleaned up by the destructor.
	WaitForPreviousFrame();
	CloseHandle(m_fenceEvent);
}

void HelloWindow::LoadPipeline() {

}

void HelloWindow::LoadAssets() {

}

void HelloWindow::PopulateCommandList() {

}

void HelloWindow::WaitForPreviousFrame() {

}
