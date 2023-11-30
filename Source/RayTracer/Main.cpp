#include "Renderer.h"
#include "Random.h"
#include <iostream>

int main(int argc, char* argv[]) {
	std::cout << "Hello World\n";

	Renderer renderer = Renderer();
	renderer.Initialize();
	renderer.CreateWindow("RayTracing", 400, 300);
	Canvas canvas(400, 300, renderer);

	bool quit = false;
	while (!quit)
	{
		SDL_Event event;
		SDL_PollEvent(&event);
		switch (event.type)
		{
		case SDL_QUIT:
			quit = true;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				quit = true;
				break;
			}
			break;
		}

		canvas.Clear({ 0, 0, 0, 1 });
		for (int i = 0; i < 1000; i++) canvas.DrawPoint({ random01() * 400, random01() * 300 }, { random01(),random01(),random01(), 1 });
		canvas.Update();

		renderer.PresentCanvas(canvas);
	}

	renderer.Shutdown();
	return 0;
}