
/*
 * StoryMode implements a story about The Planet of Choices.
 *
 */

#include "ColorTextureProgram.hpp"
#include "Mode.hpp"
#include "GL.hpp"
#include "Sound.hpp"
#include "Puzzles.hpp"

struct StoryMode : Mode {
	StoryMode();
	virtual ~StoryMode();

	virtual bool handle_event(SDL_Event const &, glm::uvec2 const &window_size) override;
	virtual void update(float elapsed) override;
	virtual void draw(glm::uvec2 const &drawable_size) override;

	//called to create menu for current scene:
	// void enter_scene();
  void play_sound(int note);

	//------ story state -------
	// enum {
	// 	Dunes,
	// 	Oasis,
	// 	Hill
	// } location = Dunes;
	// bool have_stone = false;
	// bool added_stone = false;
	// struct {
	// 	bool first_visit = true;
	// 	bool wont_leave = false;
	// } dunes;
	// struct {
	// 	bool first_visit = true;
	// 	bool took_stone = false;
	// } oasis;
	// struct {
	// 	bool first_visit = true;
	// 	bool added_stone = false;
	// } hill;

  int player_puzznum;
  Puzzle player_puzzle;
  int player_note;
  int player_x, player_y;
  int is_transitioning = 0;

	glm::vec2 view_min = glm::vec2(0,0);
	glm::vec2 view_max = glm::vec2(256, 224);
  glm::vec2 grid_radius = glm::vec2(10, 10);
  glm::vec2 player_radius = glm::vec2(7, 7);
	struct Vertex {
		Vertex(glm::vec3 const &Position_, glm::u8vec4 const &Color_, glm::vec2 const &TexCoord_) :
			Position(Position_), Color(Color_), TexCoord(TexCoord_) { }
		glm::vec3 Position;
		glm::u8vec4 Color;
		glm::vec2 TexCoord;
	};

  //Shader program that draws transformed, vertices tinted with vertex colors:
  ColorTextureProgram color_texture_program;

  //Buffer used to hold vertex data during drawing:
  GLuint vertex_buffer = 0;

  //Vertex Array Object that maps buffer locations to color_texture_program attribute locations:
  GLuint vertex_buffer_for_color_texture_program = 0;

  //Solid white texture:
  GLuint white_tex = 0;

  //matrix that maps from clip coordinates to court-space coordinates:
  glm::mat3x2 clip_to_court = glm::mat3x2(1.0f);
  // computed in draw() as the inverse of OBJECT_TO_CLIP
  // (stored here so that the mouse handling code can use it to position the paddle)

	//------ background music -------
	// std::shared_ptr< Sound::PlayingSample > background_music;
};
