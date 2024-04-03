#include "Function.h"

SDL_Renderer* renderer;
SDL_Texture* texture;
//int x, y;


void initSDL(SDL_Window* &window, SDL_Renderer* &renderer)
{
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

SDL_Texture* loadTexture(std::string path, SDL_Renderer* renderer)
{
    texture = nullptr;
    SDL_Surface* loadedIMG = IMG_Load(path.c_str());
    if(loadedIMG == nullptr) std::cout << 1;
    texture = SDL_CreateTextureFromSurface(renderer, loadedIMG);
    SDL_FreeSurface(loadedIMG);
    return texture;
}

void renderTexture(SDL_Texture* texture,SDL_Renderer* renderer)
{
        SDL_RenderCopy(renderer, texture, nullptr, nullptr );
        SDL_RenderPresent(renderer);
        texture = nullptr;
        SDL_free(texture);
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
    SDL_RenderPresent(renderer);
    texture = nullptr;
	SDL_free(texture);
}

void standardCoordinate(int &x, int &y)
{
	x = (x - 63)/34;
	y = (y - 50)/34;
}

void quitSDL(SDL_Window* window, SDL_Renderer* renderer)
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int clickInMenu(int &x, int &y)
{
	//std::cout << "Toa do chuot " << x << " : " << y << std::endl;
	if( 495 <= x && x <= 705 && 345 <= y && y <= 405 )
	{
		//std::cout << "click 1 player" << std::endl;
		return 1;
	}
	if( 495 <= x && x <= 705 && 430 <= y && y <= 490 )
	{
		//std::cout << "click 2 player" << std::endl;
		return 2;
	}
	if( 495 <= x && x <= 705 && 515 <= y && y <= 575 )
	{
		//std::cout << "click exit" << std::endl;
		return 3;
	}
	if( 300<= x && x <= 900 && 120 <= y && y <= 205 )
	{
		//std::cout << "title" << std::endl;
		return 4;
	}
}

int clickInResult(int &x, int &y)
{
	if( 480 <= x && x <= 715 && 365 <= y && y <= 435 )
	{
	//std::cout << "click play again" << std::endl;
	return 1;
	}
	if( 480 <= x && x <= 715 && 475 <= y && y <= 545 )
	{
	//std::cout << "click mainmenu" << std::endl;
	return 2;
	}

}

int clickInPlay(int &x, int &y)
{
	if( 1085 <= x && x <= 1165 && 25 <= y && y <= 70 )
	{
		return 1;
	}
}

void renderMenu(SDL_Texture* texture, SDL_Renderer* renderer, int &x, int &y)
{
	int tmp = clickInMenu(x, y);
	switch(tmp)
	{
	case 1:
		texture = loadTexture("mainmenu1player.PNG", renderer);
		renderTexture(texture, renderer);
		break;
	case 2:
		texture = loadTexture("mainmenu2player.PNG", renderer);
		renderTexture(texture, renderer);
		break;
	case 3:
		texture = loadTexture("mainmenuexit.PNG", renderer);
		renderTexture(texture, renderer);
		break;
	case 4:
		texture = loadTexture("mainmenugamecaro.PNG", renderer);
		renderTexture(texture, renderer);
		break;
	default:
		texture = loadTexture("mainmenu.PNG", renderer);
		renderTexture(texture, renderer);
		break;
	}
}

void renderXWon(SDL_Texture* texture, SDL_Renderer* renderer, int &x, int &y)
{
	//SDL_GetMouseState(&x, &y);
	int tmp = clickInResult(x, y);

	switch(tmp)
	{
	case 1:
		texture = loadTexture("xwonplayagain.PNG", renderer);
		renderTexture(texture, renderer);
		break;
	case 2:
		texture = loadTexture("xwonmainmenu.PNG", renderer);
		renderTexture(texture, renderer);
		break;
	default:
		texture = loadTexture("xwon0.PNG", renderer);
		renderTexture(texture, renderer);
		break;
	}

}

void renderOWon(SDL_Texture* texture, SDL_Renderer* renderer, int &x, int &y);

void renderDraw(SDL_Texture* texture, SDL_Renderer* renderer, int &x, int &y);

void renderResult(SDL_Texture* texture, SDL_Renderer* renderer, int &x, int &y)
{
	//SDL_GetMouseState(&x, &y);
	int tmp = clickInResult(x, y);

	switch(tmp)
	{
	case 1:
		//std::cout << "tmp: " << tmp << std::endl;
		texture = loadTexture("resultplayagain.PNG", renderer);
		renderTexture(texture, renderer, 0, 340, 1200, 300);
		break;
	case 2:
		//std::cout << "tmp: " << tmp << std::endl;
		texture = loadTexture("resultmenu.PNG", renderer);
		renderTexture(texture, renderer, 0, 340, 1200, 300);
		break;
	default:
		texture = loadTexture("result0.PNG", renderer);
		renderTexture(texture, renderer, 0, 340, 1200, 300);
		break;
	}
}
