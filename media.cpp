
#include "media.h"

void Media::initSDL()
{
	if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0 ){
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
    }
    else{
        window = SDL_CreateWindow("Caro 1.0",
                                    SDL_WINDOWPOS_UNDEFINED,
                                    SDL_WINDOWPOS_UNDEFINED,
                                    SCREEN_WIDTH, SCREEN_HEIGHT,
                                    SDL_WINDOW_SHOWN);
        if( NULL == window ){
        std::cout << "Window could not be created!" << std::endl;
        }
		else{
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        SDL_Texture *texture = loadTexture("image/mainmenu.PNG", renderer);
        renderTexture(texture, renderer);
		}
	}
	if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
    }
    else
    {
        music = Mix_LoadMUS("sound_effects/theme2.mp3");
        if( music == NULL )
        {
        printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
        }
        Mix_PlayMusic(music, -1);
    }
}

SDL_Texture* Media::loadTexture(std::string path, SDL_Renderer* renderer)
{
    texture = nullptr;
    SDL_Surface* loadedIMG = IMG_Load(path.c_str());
    if(loadedIMG == nullptr) std::cout << 1;
    texture = SDL_CreateTextureFromSurface(renderer, loadedIMG);
    SDL_FreeSurface(loadedIMG);
    return texture;
}

void Media::renderTexture(SDL_Texture* texture,SDL_Renderer* renderer)
{
        SDL_RenderCopy(renderer, texture, nullptr, nullptr );
        SDL_RenderPresent(renderer);
        texture = nullptr;
        SDL_free(texture);
}

void Media::renderTexture(SDL_Texture *texture, SDL_Renderer *renderer, int x, int y, int w, int h){
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

void Media::standardCoordinate(int &x, int &y)
{
	x = (x - 63)/34;
	y = (y - 50)/34;
}

void Media::quitSDL()
{
    Mix_FreeMusic( music );
    Mix_FreeChunk( audio );
    audio = nullptr;
    music = nullptr;

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    renderer = nullptr;
    window = nullptr;

    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
}

int Media::clickInMenu(int &x, int &y)
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

int Media::clickInResult(int &x, int &y)
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

int Media::clickInPlay(int &x, int &y)
{
	if( 1085 <= x && x <= 1165 && 25 <= y && y <= 70 )
	{
		return 1;
	}
}

void Media::renderMenu(SDL_Texture* texture, SDL_Renderer* renderer, int &x, int &y)
{
	int tmp = clickInMenu(x, y);
	switch(tmp)
	{
	case 1:
		texture = loadTexture("image/mainmenu1player.PNG", renderer);
		renderTexture(texture, renderer);
		break;
	case 2:
		texture = loadTexture("image/mainmenu2player.PNG", renderer);
		renderTexture(texture, renderer);
		break;
	case 3:
		texture = loadTexture("image/mainmenuexit.PNG", renderer);
		renderTexture(texture, renderer);
		break;
	case 4:
		texture = loadTexture("image/mainmenugamecaro.PNG", renderer);
		renderTexture(texture, renderer);
		break;
	default:
		texture = loadTexture("image/mainmenu.PNG", renderer);
		renderTexture(texture, renderer);
		break;
	}
}

void Media::renderXWon(SDL_Texture* texture, SDL_Renderer* renderer, int &x, int &y)
{
	//SDL_GetMouseState(&x, &y);
	int tmp = clickInResult(x, y);

	switch(tmp)
	{
	case 1:
		texture = loadTexture("image/xwonplayagain.PNG", renderer);
		renderTexture(texture, renderer);
		break;
	case 2:
		texture = loadTexture("image/xwonmainmenu.PNG", renderer);
		renderTexture(texture, renderer);
		break;
	default:
		texture = loadTexture("image/xwon0.PNG", renderer);
		renderTexture(texture, renderer);
		break;
	}

}

void Media::renderOWon(SDL_Texture* texture, SDL_Renderer* renderer, int &x, int &y)
{

}

void Media::renderDraw(SDL_Texture* texture, SDL_Renderer* renderer, int &x, int &y)
{

}

void Media::renderResult(SDL_Texture* texture, SDL_Renderer* renderer, int &x, int &y)
{
	//SDL_GetMouseState(&x, &y);
	int tmp = clickInResult(x, y);

	switch(tmp)
	{
	case 1:
		//std::cout << "tmp: " << tmp << std::endl;
		texture = loadTexture("image/resultplayagain.PNG", renderer);
		renderTexture(texture, renderer, 0, 340, 1200, 300);
		break;
	case 2:
		//std::cout << "tmp: " << tmp << std::endl;
		texture = loadTexture("image/resultmenu.PNG", renderer);
		renderTexture(texture, renderer, 0, 340, 1200, 300);
		break;
	default:
		texture = loadTexture("image/result0.PNG", renderer);
		renderTexture(texture, renderer, 0, 340, 1200, 300);
		break;
	}
}

void Media::playMusic(std::string path ,Mix_Chunk *audio)
{
    audio = Mix_LoadWAV(path.c_str());
    if(audio == nullptr)
    {
        printf( "Failed to load sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
    }
    Mix_PlayChannel(-1, audio, 0);
}
