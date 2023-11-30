#pragma once
#include "Canvas.h"
#include <string>
#include <stdio.h>
#include <SDL.h>

class Renderer
{
public:
	Renderer() = default;

	bool Initialize();
	void Shutdown();
	bool CreateWindow(const std::string& title, int width, int height);

	void PresentCanvas(const Canvas& canvas);

	friend class Canvas;
private:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
};