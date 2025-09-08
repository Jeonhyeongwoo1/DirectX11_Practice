#pragma once


class Game
{
public:
	Game();
	~Game();

public:
	void Init(HWND hwnd);
	void Update();
	void Render();

private:
	void RenderBegin();
	void RenderEnd();


private:
	void CreateDeviceAndSwapChain();
	void CreateRenderTargetView();

	void SetViewport();
private:
	HWND _hwnd;
	uint32 _width = 0;
	uint32 _height = 0;

private:
	// Device & SwapChain
	//ComPtr -> 스마트 포인터 역할(메모리 관리를 하지않아도됨)
	ComPtr<ID3D11Device> _device = nullptr; // 장치 연결
	ComPtr<ID3D11DeviceContext> _deviceContext = nullptr;
	ComPtr<IDXGISwapChain> _swapChain = nullptr;

	// RTV(렌더 타겟 뷰)
	ComPtr<ID3D11RenderTargetView> _renderTargetView;
	
	// Misc (뷰 포트)
	D3D11_VIEWPORT _viewport = { 0 };
	float _clearColor[4] = { 0.5f, 0.5f, 0.5f, 0.5f };

};

