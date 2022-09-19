#pragma once

// Common include headers for Window creation
#include <common.h>

using Microsoft::WRL::ComPtr;
using std::wstring;

class HelloWindow {
public:
	HelloWindow(UINT width, UINT height, LPCSTR name);
	~HelloWindow() {};

	void OnInit();
	void OnUpdate();
	void OnRender();
	void OnDestroy();

    // Window properties.
    UINT w_width;
    UINT w_height;
    LPCSTR w_title;

private:
	//static const UINT FrameCount = 2;

    //// Pipeline objects.
    //ComPtr<IDXGISwapChain4> m_swapChain;
    //ComPtr<ID3D12Device2> m_device;
    //ComPtr<ID3D12Resource> m_renderTargets[FrameCount];
    //ComPtr<ID3D12CommandAllocator> m_commandAllocator;
    //ComPtr<ID3D12CommandQueue> m_commandQueue;
    //ComPtr<ID3D12DescriptorHeap> m_rtvHeap;
    //ComPtr<ID3D12PipelineState> m_pipelineState;
    //ComPtr<ID3D12GraphicsCommandList> m_commandList;
    //UINT m_rtvDescriptorSize;

    //// Synchronization objects.
    //UINT m_frameIndex;
    //HANDLE m_fenceEvent;
    //ComPtr<ID3D12Fence> m_fence;
    //UINT64 m_fenceValue;
};
