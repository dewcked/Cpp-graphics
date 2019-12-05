/****** Initilization Header - Setup & Prepares Key Game Items ******/

#pragma comment (lib,"SDL2.lib")
#pragma comment (lib,"SDL2main")
#pragma comment (lib,"SDL2_image")
#pragma comment (lib,"opengl32")

#include "include/SDL.h"
#include "include/SDL_opengl.h"
#include "include/SDL_image.h"
#include <GL/glut.h>
#include <iostream>
#include <list>
#include <vector>


const int window_width = 1024;
const int window_height = 1024;
const int SCREEN_BPP = 32;

SDL_Event event;
SDL_Window* win = NULL;
SDL_Renderer* renderer = NULL;
GLuint texId[6];
SDL_GLContext context;
/****** Name Space for Game Variables ******/
namespace var
{
	int frame_start_time = 0;
	int frame_current_time = 0;
	int frame_count = 0;
}

/****** Initializes Core OpenGL Features ******/
bool opengl_init()
{
	glEnable(GL_DEPTH_TEST);
	//glDepthFunc(GL_LEQUAL);
	
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//glEnable(GL_BLEND);
	//glEnable(GL_ARB_texture_non_power_of_two);
	glEnable(GL_TEXTURE_2D);
	//glEnable(GL_TEXTURE_3D);
	std::cout << "Allowed extensions: " << glGetString(GL_EXTENSIONS) << std::endl;
	glClearColor(0, 0, 0, 0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (640.0 / 480.0), 0.1, 100.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//std::cout << "Error Code: " << glGetError() << std::endl;
	if (glGetError() != GL_NO_ERROR)
	{
		return false;
	}

	return true;
}


/****** Initializes SDL, OpenGL and Video and Window ******/
bool init()
{

	//if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		return false;
	}

	win = SDL_CreateWindow("20151179\xEA\xB0\x95\xEC\xB0\xAC\xEC\x9A\xB0", 100, 100, window_width, window_height, SDL_WINDOW_OPENGL);
	renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
	context = SDL_GL_CreateContext(win);

	if (opengl_init() == false)
	{
		return false;
	}
}

/* Removes objects before game closes */
void clean_up()
{
	SDL_Quit();
}

void errorcheck() {
	int errormsg;
	if ((errormsg = glGetError()) != GL_NO_ERROR)
	{
		std::cout << "glerror: " << errormsg << std::endl;
		exit(0);
	}
}
void RenewTexture(SDL_Surface* tmpimg, int index) {
	GLubyte* map = (GLubyte*)tmpimg->pixels;
	glBindTexture(GL_TEXTURE_2D, texId[index]); errorcheck();
	GLsizei w, h;
	w = tmpimg->w;
	h = tmpimg->h;
	//glPixelStorei(GL_UNPACK_ALIGNMENT, texId[index]); errorcheck();
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); errorcheck();
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_BASE_LEVEL, 0);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL, 6);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);//GL_CLAMP_TO_EDGE, GL_CLAMP
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	errorcheck();
	/*gluBuild2DMipmaps(
		GL_TEXTURE_2D, GL_RGBA8,
		w, h,
		GL_RGBA8, GL_UNSIGNED_BYTE,
		map
	);*/
	glTexImage2D(
		GL_TEXTURE_2D, 0, GL_RGB,
		w, h, 0,
		GL_RGB, GL_UNSIGNED_BYTE,
		(GLvoid *)map
	);
	errorcheck();
	//glBindTexture(GL_TEXTURE_2D, texId[index]);
}

int main(int argc, char* args[])
{
	std::vector<SDL_Surface*> image;
	GLfloat rotation = 0.0f;

	bool quit = false;

	if (init() == false)
	{
		return 1;
	}

	const char* ImageNames[6] = { "res/KGU-logo.jpg", "res/Me.jpeg", "res/beach-1838501.jpg", "res/bench-560435.jpg", "res/wolf-1341881_1920.jpg", "res/spring-bird-2295434.jpg" };
	for (int i = 0; i < 6; i++) {
		SDL_RWops* tmprwop = SDL_RWFromFile(ImageNames[i], "rb");
		SDL_Surface* tmpimg = IMG_LoadJPG_RW(tmprwop);
		image.push_back(tmpimg);
	}

	glGenTextures(6, texId);
	for (int i = 0; i < 6; i++)
		std::cout << texId[i] << std::endl;
	/*SDL_Rect position;
	position.x = 1;
	position.y = 1;
	position.h = 10;
	position.w = 10;
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, SDL_CreateTextureFromSurface(renderer, image.at(0)), NULL, &position);
	SDL_RenderPresent(renderer);*/
	
	/****** Main Game Loop ******/
	while (quit == false)
	{

		/****** Get Most Current Time ******/
		var::frame_start_time = SDL_GetTicks();

		/****** Draw Rectangle ******/
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();
		glTranslatef(0.0f, 0.0f, -6.0f);
		glRotatef(rotation, 1.0f, 1.0f, 0.0f);
		//errorcheck();

		RenewTexture(image.at(0), 0);
		glBegin(GL_QUADS);
		/* Cube Top */
		glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
		glTexCoord2f(0, 1.0); glVertex3f(-1.0f, 1.0f, 1.0f);
		glTexCoord2f(0, 0); glVertex3f(-1.0f, 1.0f, -1.0f);
		glTexCoord2f(1.0, 0); glVertex3f(1.0f, 1.0f, -1.0f);
		glTexCoord2f(1.0, 1.0); glVertex3f(1.0f, 1.0f, 1.0f);
		glEnd();

		RenewTexture(image.at(1), 1);
		/* Cube Bottom */
		glBegin(GL_QUADS);
		glColor4f(1.0f, 0.5f, 0.0f, 1.0f);
		glTexCoord2f(0, 1.0); glVertex3f(-1.0f, -1.0f, 1.0f);
		glTexCoord2f(0, 0); glVertex3f(-1.0f, -1.0f, -1.0f);
		glTexCoord2f(1.0, 0); glVertex3f(1.0f, -1.0f, -1.0f);
		glTexCoord2f(1.0, 1.0); glVertex3f(1.0f, -1.0f, 1.0f);
		glEnd();

		RenewTexture(image.at(2), 2);
		/* Cube Front */
		glBegin(GL_QUADS);
		glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
		glTexCoord2f(0, 1.0); glVertex3f(-1.0f, 1.0f, 1.0f);
		glTexCoord2f(0, 0); glVertex3f(1.0f, 1.0f, 1.0f);
		glTexCoord2f(1.0, 0); glVertex3f(1.0f, -1.0f, 1.0f);
		glTexCoord2f(1.0, 1.0); glVertex3f(-1.0f, -1.0f, 1.0f);
		glEnd();

		RenewTexture(image.at(3), 3);
		/* Cube Back */
		glBegin(GL_QUADS);
		glColor4f(0.0f, 1.0f, 0.5f, 1.0f);
		glTexCoord2f(0, 1.0); glVertex3f(-1.0f, 1.0f, -1.0f);
		glTexCoord2f(0, 0); glVertex3f(1.0f, 1.0f, -1.0f);
		glTexCoord2f(1.0, 0); glVertex3f(1.0f, -1.0f, -1.0f);
		glTexCoord2f(1.0, 1.0); glVertex3f(-1.0f, -1.0f, -1.0f);
		glEnd();

		RenewTexture(image.at(4), 4);
		/* Cube Left Side */
		glBegin(GL_QUADS);
		glColor4f(0.5f, 0.5f, 0.5f, 1.0f);
		glTexCoord2f(0, 1.0); glVertex3f(-1.0f, 1.0f, -1.0f);
		glTexCoord2f(0, 0); glVertex3f(-1.0f, 1.0f, 1.0f);
		glTexCoord2f(1.0, 0); glVertex3f(-1.0f, -1.0f, 1.0f);
		glTexCoord2f(1.0, 1.0); glVertex3f(-1.0f, -1.0f, -1.0f);
		glEnd();

		RenewTexture(image.at(5), 5);
		/* Cube Right Side */
		glBegin(GL_QUADS);
		glColor4f(0.15f, 0.25f, 0.75f, 1.0f);
		glTexCoord2f(0, 1.0); glVertex3f(1.0f, 1.0f, -1.0f);
		glTexCoord2f(0, 0); glVertex3f(1.0f, 1.0f, 1.0f);
		glTexCoord2f(1.0, 0); glVertex3f(1.0f, -1.0f, 1.0f);
		glTexCoord2f(1.0, 1.0); glVertex3f(1.0f, -1.0f, -1.0f);
		glEnd();
		errorcheck();
		rotation -= 0.5f;
		/****** Check for Key & System input ******/
		while (SDL_PollEvent(&event))
		{

			/******  Application Quit Event ******/
			if (event.type == SDL_QUIT)
			{
				quit = true;
			}
		}

		/****** Update Screen And Frame Counts ******/
		SDL_GL_SwapWindow(win);
		var::frame_count++;
		var::frame_current_time = SDL_GetTicks();

		/****** Frame Rate Handle ******/
		if ((var::frame_current_time - var::frame_start_time) < (1000 / 60))
		{
			var::frame_count = 0;
			SDL_Delay((1000 / 60) - (var::frame_current_time - var::frame_start_time));
		}
	}
	clean_up();
	return 0;
}