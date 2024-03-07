#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <iostream>

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 640;
const int SCREEN_BPP = 32;
//const string WINDOW_TITLE = "trinh duong";

SDL_Window* window = nullptr;
SDL_Surface* surface = nullptr;
SDL_Renderer* renderer = nullptr;
SDL_Texture* texture = nullptr;


void initSDL(SDL_Window* &window, SDL_Renderer* &renderer); // khoi tao cua so va but ve
void quitSDL(SDL_Window* window, SDL_Renderer* renderer); // giai phong
void waitUntilKeyPressed(); // cho su kien ban phim
SDL_Texture* loadTexture(std::string path, SDL_Renderer* renderer);
void renderTexture(SDL_Texture* texture); // tai anh toan man hinh
void renderTexture(SDL_Texture *texture, SDL_Renderer *renderer, int x, int y, int w, int h); // tai anh theo toa do
void chuanhoatoado(int &x, int &y);

int main( int argc, char* args[])
{
    initSDL(window, renderer); // khoi tao


	texture = loadTexture("menu.PNG", renderer); // tai menu
	renderTexture(texture);

	// SDL_Event event;
	// SDL_Rect rect;

	//if (SDL_PollEvent(&event) == 0) continue;
	//if (event.type == SDL_QUIT) break;
	// if (SDL_MOUSEBUTTONDOWN == event.type){
	// 		if(SDL_BUTTON_LEFT == event.button.button){
	// 			int x, y;
	// 			SDL_GetMouseState(&x, &y);
	// 			std::cout << x << " : " << y << std::endl;
	// 			//rect.x = event.button.x;
	// 			//rect.y = event.button.y;
	// 			if( 545 <= x && x <= 655 && 300 <= y && y <= 335){
	// 			std::cout << 1;
	// 			texture = loadTexture("play.PNG", renderer);
	// 			renderTexture(texture);
	// 			}
	// 		}


	// }


	SDL_RenderPresent(renderer);
    bool quit = false;
        SDL_Event e;
		int count = 0;
        while(!quit){
            while(SDL_PollEvent(&e)){
                if(e.type == SDL_QUIT){
                    quit = true;
                }
                else if(SDL_MOUSEBUTTONDOWN == e.type){
                        if(SDL_BUTTON_LEFT == e.button.button){
							//if(count%2 == 0){
								int x, y;
								SDL_GetMouseState(&x, &y);
								std::cout << "Toa do goc " << x << " : " << y << std::endl;
								// chuanhoatoado(x, y);
								// std::cout << "Toa do chuan hoa " << x << " : " << y << std::endl;
								// SDL_Texture* tx1 = loadTexture("cell_x.png", renderer);
								// renderTexture(tx1, renderer, x*63+25, y*63+25, 30, 30);
								// SDL_RenderPresent(renderer);
								// count++;
                                if( 545 <= x && x <= 655 && 300 <= y && y <= 335){
									std::cout << 1 << std::endl;
                                    //SDL_RenderClear(renderer);

                                    SDL_Texture* tx1 = loadTexture("play.PNG", renderer);
                                    renderTexture(tx1);
                                    SDL_RenderPresent(renderer);
                                }
							//}
							// else{
							// 	int x, y;
							// 	SDL_GetMouseState(&x, &y);
							// 	std::cout << "Toa do goc " << x << " : " << y << std::endl;
							// 	chuanhoatoado(x, y);
							// 	std::cout << "Toa do chuan hoa " << x << " : " << y << std::endl;
							// 	SDL_Texture* tx1 = loadTexture("cell_o.png", renderer);
							// 	renderTexture(tx1, renderer, x*63+25, y*63+25, 25, 25);
							// 	SDL_RenderPresent(renderer);
							// 	count++;
							// }

                        }
                }
            }
        }




    waitUntilKeyPressed();
    quitSDL(window, renderer);
    return 0;
}

void initSDL(SDL_Window* &window, SDL_Renderer* &renderer){
    if(SDL_Init(SDL_Init(SDL_INIT_VIDEO)) < 0 ){
        std::cout << "SDL khong the khoi tao" << std::endl;
    }
    else{
        window = SDL_CreateWindow("trinh duong",
                                    SDL_WINDOWPOS_UNDEFINED,
                                    SDL_WINDOWPOS_UNDEFINED,
                                    SCREEN_WIDTH, SCREEN_HEIGHT,
                                    SDL_WINDOW_SHOWN);
        if( NULL == window ){
        std::cout << "Window could not be created!" << std::endl;
        }
		else{
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		}
	}
}

void quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void waitUntilKeyPressed()
{
    SDL_Event e;
    while (true) {
    if ( SDL_WaitEvent(&e) != 0 && (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
    return;
    SDL_Delay(100);
    }
}

SDL_Texture* loadTexture(std::string path, SDL_Renderer* renderer)
{
    SDL_Texture* tx = nullptr;
    SDL_Surface* loadedIMG = IMG_Load(path.c_str());
    tx = SDL_CreateTextureFromSurface(renderer, loadedIMG);
    SDL_FreeSurface(loadedIMG);
    return tx;
}

void renderTexture(SDL_Texture* texture)
{
    if(nullptr == texture){
        std::cout << "Khong the tai texture!";
    }
    else{
        SDL_RenderCopy(renderer, texture, nullptr, nullptr );
        SDL_RenderPresent(renderer);
        texture = nullptr;
        SDL_free(texture);
    }
}
void renderTexture(SDL_Texture *texture, SDL_Renderer *renderer, int x, int y, int w, int h){
    // Thiet lap hinh vuong ma chung ta muon ve anh vao trong
    SDL_Rect dst;
    dst.x = x;
    dst.y = y;
    dst.w = w;
    dst.h = h;
    // Dua toan bo anh trong texture vao hinh chu nhat dich
    SDL_RenderCopy(renderer, texture, NULL, &dst);
}

void chuanhoatoado(int &x, int &y)
{
	x = (x - 0)/60;
	y = (y - 0)/60;
}
