#include <SDL2/SDL.h>
#include <stdio.h>

#define nil	NULL
#define NUMCOL	(3)
#define VSYNC
#define ACCELERATED
//#define SOFTWARE

SDL_Color	col[NUMCOL] =
{
	{0xFF, 0x00, 0x00, 0x00},
	{0x00, 0xFF, 0x00, 0x00},
	{0x00, 0x00, 0xFF, 0x00}
};

int
main()
{
	int	e;
	int	i, n;
	Uint32	f;
	SDL_Window	*win = nil;
	SDL_Renderer	*ren = nil;

	e = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
	if(e){
		fprintf(stderr, "Init:	%d\n", e);
		goto	release;
	}


	win = SDL_CreateWindow("hw_test",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		800, 600,
		0);
	if(!win){
		fprintf(stderr, "Window: %s\n", SDL_GetError());
		goto	release;
	}

	printf("SDL_RENDERER_SOFTWARE %x\n", SDL_RENDERER_SOFTWARE);
	printf("SDL_RENDERER_ACCELERATED %x\n", SDL_RENDERER_ACCELERATED);
	printf("SDL_RENDERER_PRESENTVSYNC %x\n", SDL_RENDERER_PRESENTVSYNC);
	printf("SDL_RENDERER_TARGETTEXTURE %x\n", SDL_RENDERER_TARGETTEXTURE);

	n = SDL_GetNumRenderDrivers();
	printf("This system has %d render drivers\n", n);
	for(i = 0; i < n; i++){
		SDL_RendererInfo	info;

		SDL_GetRenderDriverInfo(i, &info);
		printf("Name: %s	flags: %x\n",
			info.name,
			info.flags);
	}

	f = 0
#ifdef VSYNC
		| SDL_RENDERER_PRESENTVSYNC
#endif
#ifdef ACCELERATED
		| SDL_RENDERER_ACCELERATED
#elif SOFTWARE
		| SDL_RENDERER_SOFTWARE
#endif
	;
	printf("Renderer flags: %x\n", f);
	ren = SDL_CreateRenderer(
		win,
		0, //-1,
		f);
	if(!ren){
		fprintf(stderr, "Renderer: %s\n", SDL_GetError());
		goto	release;
	}

	SDL_RendererInfo	info;

	SDL_GetRendererInfo(ren, &info);
	printf("Current renderer - Name: %s	flags: %x\n",
		info.name,
		info.flags);

	n = 0;
	for(i = 60; i > 0; i--){
		SDL_SetRenderDrawColor(ren, col[n].r, col[n].g, col[n].b, col[n].a);
		++n;
		n %= NUMCOL;
		SDL_RenderClear(ren);
#ifndef VSYNC
			SDL_Delay(10);
#endif
		SDL_RenderPresent(ren);
	}
	printf("Ok!\n");

release:
	if(ren)
		SDL_DestroyRenderer(ren);
	if(win)
		SDL_DestroyWindow(win);
	SDL_Quit();
	return	0;
}
