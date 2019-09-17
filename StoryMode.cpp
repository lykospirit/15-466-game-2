#include "StoryMode.hpp"

#include "Sprite.hpp"
#include "DrawSprites.hpp"
#include "Load.hpp"
#include "data_path.hpp"
#include "gl_errors.hpp"
#include "MenuMode.hpp"
#include "Sound.hpp"
#include "Puzzles.hpp"

#include <glm/gtc/type_ptr.hpp>
#include <algorithm>

Load< Sound::Sample > sound_C4(LoadTagDefault, []() -> Sound::Sample *{
	std::vector< float > data(size_t(48000 * 0.2f), 0.0f);
	for (uint32_t i = 0; i < data.size(); ++i) {
		float t = i / float(48000);
		//phase-modulated sine wave (creates some metal-like sound):
		data[i] = std::sin(3.1415926f * 2.0f * 250.0f * t + std::sin(3.1415926f * 2.0f * 255.0f * t));
		//quadratic falloff:
		data[i] *= 0.3f * std::pow(std::max(0.0f, (1.0f - t / 0.2f)), 2.0f);
	}
	return new Sound::Sample(data);
});
Load< Sound::Sample > sound_D4(LoadTagDefault, []() -> Sound::Sample *{
	std::vector< float > data(size_t(48000 * 0.2f), 0.0f);
	for (uint32_t i = 0; i < data.size(); ++i) {
		float t = i / float(48000);
		data[i] = std::sin(3.1415926f * 2.0f * 279.0f * t + std::sin(3.1415926f * 2.0f * 289.0f * t));
		data[i] *= 0.3f * std::pow(std::max(0.0f, (1.0f - t / 0.2f)), 2.0f);
	}
	return new Sound::Sample(data);
});
Load< Sound::Sample > sound_E4(LoadTagDefault, []() -> Sound::Sample *{
	std::vector< float > data(size_t(48000 * 0.2f), 0.0f);
	for (uint32_t i = 0; i < data.size(); ++i) {
		float t = i / float(48000);
		data[i] = std::sin(3.1415926f * 2.0f * 320.0f * t + std::sin(3.1415926f * 2.0f * 330.0f * t));
		data[i] *= 0.3f * std::pow(std::max(0.0f, (1.0f - t / 0.2f)), 2.0f);
	}
	return new Sound::Sample(data);
});
Load< Sound::Sample > sound_F4(LoadTagDefault, []() -> Sound::Sample *{
	std::vector< float > data(size_t(48000 * 0.2f), 0.0f);
	for (uint32_t i = 0; i < data.size(); ++i) {
		float t = i / float(48000);
		data[i] = std::sin(3.1415926f * 2.0f * 337.0f * t + std::sin(3.1415926f * 2.0f * 347.0f * t));
		data[i] *= 0.3f * std::pow(std::max(0.0f, (1.0f - t / 0.2f)), 2.0f);
	}
	return new Sound::Sample(data);
});
Load< Sound::Sample > sound_G4(LoadTagDefault, []() -> Sound::Sample *{
	std::vector< float > data(size_t(48000 * 0.2f), 0.0f);
	for (uint32_t i = 0; i < data.size(); ++i) {
		float t = i / float(48000);
		data[i] = std::sin(3.1415926f * 2.0f * 385.0f * t + std::sin(3.1415926f * 2.0f * 395.0f * t));
		data[i] *= 0.3f * std::pow(std::max(0.0f, (1.0f - t / 0.2f)), 2.0f);
	}
	return new Sound::Sample(data);
});
Load< Sound::Sample > sound_A5(LoadTagDefault, []() -> Sound::Sample *{
	std::vector< float > data(size_t(48000 * 0.2f), 0.0f);
	for (uint32_t i = 0; i < data.size(); ++i) {
		float t = i / float(48000);
		data[i] = std::sin(3.1415926f * 2.0f * 435.0f * t + std::sin(3.1415926f * 2.0f * 445.0f * t));
		data[i] *= 0.3f * std::pow(std::max(0.0f, (1.0f - t / 0.2f)), 2.0f);
	}
	return new Sound::Sample(data);
});
Load< Sound::Sample > sound_B5(LoadTagDefault, []() -> Sound::Sample *{
	std::vector< float > data(size_t(48000 * 0.2f), 0.0f);
	for (uint32_t i = 0; i < data.size(); ++i) {
		float t = i / float(48000);
		data[i] = std::sin(3.1415926f * 2.0f * 485.0f * t + std::sin(3.1415926f * 2.0f * 495.0f * t));
		data[i] *= 0.3f * std::pow(std::max(0.0f, (1.0f - t / 0.2f)), 2.0f);
	}
	return new Sound::Sample(data);
});
Load< Sound::Sample > sound_C5(LoadTagDefault, []() -> Sound::Sample *{
	std::vector< float > data(size_t(48000 * 0.2f), 0.0f);
	for (uint32_t i = 0; i < data.size(); ++i) {
		float t = i / float(48000);
		data[i] = std::sin(3.1415926f * 2.0f * 510.0f * t + std::sin(3.1415926f * 2.0f * 520.0f * t));
		data[i] *= 0.3f * std::pow(std::max(0.0f, (1.0f - t / 0.2f)), 2.0f);
	}
	return new Sound::Sample(data);
});
Load< Sound::Sample > sound_D5(LoadTagDefault, []() -> Sound::Sample *{
	std::vector< float > data(size_t(48000 * 0.2f), 0.0f);
	for (uint32_t i = 0; i < data.size(); ++i) {
		float t = i / float(48000);
		data[i] = std::sin(3.1415926f * 2.0f * 560.0f * t + std::sin(3.1415926f * 2.0f * 570.0f * t));
		data[i] *= 0.3f * std::pow(std::max(0.0f, (1.0f - t / 0.2f)), 2.0f);
	}
	return new Sound::Sample(data);
});
Load< Sound::Sample > sound_E5(LoadTagDefault, []() -> Sound::Sample *{
	std::vector< float > data(size_t(48000 * 0.2f), 0.0f);
	for (uint32_t i = 0; i < data.size(); ++i) {
		float t = i / float(48000);
		data[i] = std::sin(3.1415926f * 2.0f * 650.0f * t + std::sin(3.1415926f * 2.0f * 660.0f * t));
		data[i] *= 0.3f * std::pow(std::max(0.0f, (1.0f - t / 0.2f)), 2.0f);
	}
	return new Sound::Sample(data);
});
Load< Sound::Sample > sound_F5(LoadTagDefault, []() -> Sound::Sample *{
	std::vector< float > data(size_t(48000 * 0.2f), 0.0f);
	for (uint32_t i = 0; i < data.size(); ++i) {
		float t = i / float(48000);
		data[i] = std::sin(3.1415926f * 2.0f * 690.0f * t + std::sin(3.1415926f * 2.0f * 700.0f * t));
		data[i] *= 0.3f * std::pow(std::max(0.0f, (1.0f - t / 0.2f)), 2.0f);
	}
	return new Sound::Sample(data);
});
Load< Sound::Sample > sound_G5(LoadTagDefault, []() -> Sound::Sample *{
	std::vector< float > data(size_t(48000 * 0.2f), 0.0f);
	for (uint32_t i = 0; i < data.size(); ++i) {
		float t = i / float(48000);
		data[i] = std::sin(3.1415926f * 2.0f * 760.0f * t + std::sin(3.1415926f * 2.0f * 770.0f * t));
		data[i] *= 0.3f * std::pow(std::max(0.0f, (1.0f - t / 0.2f)), 2.0f);
	}
	return new Sound::Sample(data);
});
Load< Sound::Sample > sound_A6(LoadTagDefault, []() -> Sound::Sample *{
	std::vector< float > data(size_t(48000 * 0.2f), 0.0f);
	for (uint32_t i = 0; i < data.size(); ++i) {
		float t = i / float(48000);
		data[i] = std::sin(3.1415926f * 2.0f * 870.0f * t + std::sin(3.1415926f * 2.0f * 880.0f * t));
		data[i] *= 0.3f * std::pow(std::max(0.0f, (1.0f - t / 0.2f)), 2.0f);
	}
	return new Sound::Sample(data);
});
Load< Sound::Sample > sound_B6(LoadTagDefault, []() -> Sound::Sample *{
	std::vector< float > data(size_t(48000 * 0.2f), 0.0f);
	for (uint32_t i = 0; i < data.size(); ++i) {
		float t = i / float(48000);
		data[i] = std::sin(3.1415926f * 2.0f * 990.0f * t + std::sin(3.1415926f * 2.0f * 1000.0f * t));
		data[i] *= 0.3f * std::pow(std::max(0.0f, (1.0f - t / 0.2f)), 2.0f);
	}
	return new Sound::Sample(data);
});
Load< Sound::Sample > sound_C6(LoadTagDefault, []() -> Sound::Sample *{
	std::vector< float > data(size_t(48000 * 0.2f), 0.0f);
	for (uint32_t i = 0; i < data.size(); ++i) {
		float t = i / float(48000);
		data[i] = std::sin(3.1415926f * 2.0f * 1050.0f * t + std::sin(3.1415926f * 2.0f * 1060.0f * t));
		data[i] *= 0.3f * std::pow(std::max(0.0f, (1.0f - t / 0.2f)), 2.0f);
	}
	return new Sound::Sample(data);
});
Load< Sound::Sample > sound_end(LoadTagDefault, []() -> Sound::Sample *{
	std::vector< float > data(size_t(48000 * 2.5f), 0.0f);
	for (uint32_t i = 0; i < data.size(); ++i) {
		float t = i / float(48000);
		data[i] = std::sin(3.1415926f * 2.0f * 510.0f * t + std::sin(3.1415926f * 2.0f * 520.0f * t));
		data[i] *= 0.3f * std::pow(std::max(0.0f, (1.0f - t / 2.5f)), 2.0f);
	}
	return new Sound::Sample(data);
});

Load< Puzzles > puzzles(LoadTagDefault, []() -> Puzzles const * {
  return new Puzzles(data_path("puzzle.list"));
});

StoryMode::StoryMode() {
	//----- allocate OpenGL resources -----
	{ //vertex buffer:
		glGenBuffers(1, &vertex_buffer);
		GL_ERRORS(); //PARANOIA: print out any OpenGL errors that may have happened
	}

	{ //vertex array mapping buffer for color_texture_program:
		//ask OpenGL to fill vertex_buffer_for_color_texture_program with the name of an unused vertex array object:
		glGenVertexArrays(1, &vertex_buffer_for_color_texture_program);
		//set vertex_buffer_for_color_texture_program as the current vertex array object:
		glBindVertexArray(vertex_buffer_for_color_texture_program);
		//set vertex_buffer as the source of glVertexAttribPointer() commands:
		glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
		//set up the vertex array object to describe arrays of FroggerMode::Vertex:
		glVertexAttribPointer(
			color_texture_program.Position_vec4, //attribute
			3, //size
			GL_FLOAT, //type
			GL_FALSE, //normalized
			sizeof(Vertex), //stride
			(GLbyte *)0 + 0 //offset
		);
		glEnableVertexAttribArray(color_texture_program.Position_vec4);
		//[Note that it is okay to bind a vec3 input to a vec4 attribute -- the w component will be filled with 1.0 automatically]
		glVertexAttribPointer(
			color_texture_program.Color_vec4, //attribute
			4, //size
			GL_UNSIGNED_BYTE, //type
			GL_TRUE, //normalized
			sizeof(Vertex), //stride
			(GLbyte *)0 + 4*3 //offset
		);
		glEnableVertexAttribArray(color_texture_program.Color_vec4);
		glVertexAttribPointer(
			color_texture_program.TexCoord_vec2, //attribute
			2, //size
			GL_FLOAT, //type
			GL_FALSE, //normalized
			sizeof(Vertex), //stride
			(GLbyte *)0 + 4*3 + 4*1 //offset
		);
		glEnableVertexAttribArray(color_texture_program.TexCoord_vec2);
		//done referring to vertex_buffer, so unbind it:
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		//done setting up vertex array object, so unbind it:
		glBindVertexArray(0);
		GL_ERRORS(); //PARANOIA: print out any OpenGL errors that may have happened
	}

	{ //solid white texture:
		//ask OpenGL to fill white_tex with the name of an unused texture object:
		glGenTextures(1, &white_tex);

		//bind that texture object as a GL_TEXTURE_2D-type texture:
		glBindTexture(GL_TEXTURE_2D, white_tex);

		//upload a 1x1 image of solid white to the texture:
		glm::uvec2 size = glm::uvec2(1,1);
		std::vector< glm::u8vec4 > data(size.x*size.y, glm::u8vec4(0xff, 0xff, 0xff, 0xff));
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, size.x, size.y, 0, GL_RGBA, GL_UNSIGNED_BYTE, data.data());

		//set filtering and wrapping parameters:
		//(it's a bit silly to mipmap a 1x1 texture, but I'm doing it because you may want to use this code to load different sizes of texture)
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		//since texture uses a mipmap and we haven't uploaded one, instruct opengl to make one for us:
		glGenerateMipmap(GL_TEXTURE_2D);

		//Okay, texture uploaded, can unbind it:
		glBindTexture(GL_TEXTURE_2D, 0);

		GL_ERRORS(); //PARANOIA: print out any OpenGL errors that may have happened
	}

  player_puzznum = 0;
  player_puzzle = puzzles->get_puzzle(player_puzznum);
  player_note = 1;
  player_x = player_puzzle.start_x;
  player_y = player_puzzle.start_y;
}

StoryMode::~StoryMode() {
}

void StoryMode::play_sound(int note) {
  switch (note) {
    case 1: Sound::play(*sound_C4); break;
    case 2: Sound::play(*sound_D4); break;
    case 3: Sound::play(*sound_E4); break;
    case 4: Sound::play(*sound_F4); break;
    case 5: Sound::play(*sound_G4); break;
    case 6: Sound::play(*sound_A5); break;
    case 7: Sound::play(*sound_B5); break;
    case 8: Sound::play(*sound_C5); break;
    case 9: Sound::play(*sound_D5); break;
    case 10: Sound::play(*sound_E5); break;
    case 11: Sound::play(*sound_F5); break;
    case 12: Sound::play(*sound_G5); break;
    case 13: Sound::play(*sound_A6); break;
    case 14: Sound::play(*sound_B6); break;
    case 15: Sound::play(*sound_C6); break;
    default: throw std::runtime_error("Unrecognized note in StoryMode::play_sound.");
  }
}

bool StoryMode::handle_event(SDL_Event const &evt, glm::uvec2 const &window_size) {
  if (is_transitioning) return false;
	// if (Mode::current.get() != this) return false;
  auto check_bounds = [&](int x, int y) {
    return (   x >= 0 && x < player_puzzle.height
            && y >= 0 && y < player_puzzle.width
            && player_puzzle.cells[x][y] != 0);
  };
  auto change_note = [&](int x, int y, int note) {
    int change, cell = player_puzzle.cells[x][y];
    switch (cell) {
      case 1: change = 0; break;
      case 2: change = 1; break;
      case 3: change = -1; break;
      case 4: change = 2; break;
      case 8: change = 1; break;
      case 9: change = 1; break;
      default: change = 0;
    }
    return std::min(std::max(change + note, 1), 15);
  };

	if (evt.type == SDL_KEYDOWN) {
    bool unknown_key = 0;
		if (evt.key.keysym.scancode == SDL_SCANCODE_W) {
      if (check_bounds(player_x-1, player_y)){
        player_x--;
        player_note = change_note(player_x, player_y, player_note);
      }
		} else if (evt.key.keysym.scancode == SDL_SCANCODE_A) {
      if (check_bounds(player_x, player_y-1)){
        player_y--;
        player_note = change_note(player_x, player_y, player_note);
      }
		} else if (evt.key.keysym.scancode == SDL_SCANCODE_S) {
      if (check_bounds(player_x+1, player_y)){
        player_x++;
        player_note = change_note(player_x, player_y, player_note);
      }
		} else if (evt.key.keysym.scancode == SDL_SCANCODE_D) {
      if (check_bounds(player_x, player_y+1)){
        player_y++;
        player_note = change_note(player_x, player_y, player_note);
      }
		} else if (evt.key.keysym.scancode == SDL_SCANCODE_R) {
      // reset game
      player_note = 1;
      player_x = player_puzzle.start_x;
      player_y = player_puzzle.start_y;
    } else unknown_key = 1;

    if (!unknown_key && !(player_x == player_puzzle.end_x && player_y == player_puzzle.end_y && player_note == 8)) {
      play_sound(player_note);
    }
	}
	return false;
}

void StoryMode::update(float elapsed) {
  if (is_transitioning) {
    is_transitioning--;
    if (!is_transitioning){
      player_puzzle = puzzles->get_puzzle(player_puzznum);
      player_note = 1;
      player_x = player_puzzle.start_x;
      player_y = player_puzzle.start_y;
    }
  } else if (player_x == player_puzzle.end_x && player_y == player_puzzle.end_y && player_note == 8) {
    Sound::play(*sound_end);
    player_puzznum = (player_puzznum + 1) % puzzles->puzzles.size();
    is_transitioning = 120;
  }
}

void StoryMode::draw(glm::uvec2 const &drawable_size) {
	//clear the color buffer:
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	//use alpha blending:
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//don't use the depth test:
	glDisable(GL_DEPTH_TEST);

	std::vector< Vertex > vertices;
	auto draw_rectangle = [&vertices](glm::vec2 const &center, glm::vec2 const &radius, glm::u8vec4 const &color) {
		//split rectangle into two CCW-oriented triangles:
		vertices.emplace_back(glm::vec3(center.x-radius.x, center.y-radius.y, 0.0f), color, glm::vec2(0.5f, 0.5f));
		vertices.emplace_back(glm::vec3(center.x+radius.x, center.y-radius.y, 0.0f), color, glm::vec2(0.5f, 0.5f));
		vertices.emplace_back(glm::vec3(center.x+radius.x, center.y+radius.y, 0.0f), color, glm::vec2(0.5f, 0.5f));

		vertices.emplace_back(glm::vec3(center.x-radius.x, center.y-radius.y, 0.0f), color, glm::vec2(0.5f, 0.5f));
		vertices.emplace_back(glm::vec3(center.x+radius.x, center.y+radius.y, 0.0f), color, glm::vec2(0.5f, 0.5f));
		vertices.emplace_back(glm::vec3(center.x-radius.x, center.y+radius.y, 0.0f), color, glm::vec2(0.5f, 0.5f));
	};

  glm::vec2 puzzle_tl = glm::vec2((view_max.x - 2*grid_radius.x * player_puzzle.width) / 2,
                                  (view_max.y + 2*grid_radius.y * player_puzzle.height) / 2);

  //Grid
  #define HEX_TO_U8VEC4( HX ) (glm::u8vec4( (HX >> 24) & 0xff, (HX >> 16) & 0xff, (HX >> 8) & 0xff, (HX) & 0xff ))
  glm::u8vec4 color;
  for (int x=0; x<player_puzzle.height; x++){
    for (int y=0; y<player_puzzle.width; y++){
      switch (player_puzzle.cells[x][y]) {
        case 0: color = HEX_TO_U8VEC4(0x000000ff); break;
        case 1: color = HEX_TO_U8VEC4(0xffffffff); break;
        case 2: color = HEX_TO_U8VEC4(0x00ff00ff); break;
        case 3: color = HEX_TO_U8VEC4(0xff0000ff); break;
        case 4: color = HEX_TO_U8VEC4(0x00ffffff); break;
        case 8: color = HEX_TO_U8VEC4(0xddbb00ff); break;
        case 9: color = HEX_TO_U8VEC4(0x440077ff); break;
      }
      glm::vec3 tl = glm::vec3(puzzle_tl.x + 2*grid_radius.x*y + grid_radius.x,
                               puzzle_tl.y - 2*grid_radius.y*x - grid_radius.y, 0.0f);
      draw_rectangle(tl, grid_radius, color);
      if (player_x == x && player_y == y) {
        draw_rectangle(tl, player_radius, HEX_TO_U8VEC4(0x000000ff));
      }
    }
  }
	#undef HEX_TO_U8VEC4

	//compute window aspect ratio: (scale the x coordinate by 1.0 / aspect to make sure things stay square.)
	float aspect = drawable_size.x / float(drawable_size.y);
	//compute scale factor for court given that...
	float scale = std::min(
		(2.0f * aspect) / (view_max.x - view_min.x), //... x must fit in [-aspect,aspect] ...
		(2.0f) / (view_max.y - view_min.y) //... y must fit in [-1,1].
	);
	glm::vec2 center = 0.5f * (view_max + view_min);

	//build matrix that scales and translates appropriately:
	glm::mat4 court_to_clip = glm::mat4(
		glm::vec4(scale / aspect, 0.0f, 0.0f, 0.0f),
		glm::vec4(0.0f, scale, 0.0f, 0.0f),
		glm::vec4(0.0f, 0.0f, 1.0f, 0.0f),
		glm::vec4(-center.x * (scale / aspect), -center.y * scale, 0.0f, 1.0f)
	);
	//also build the matrix that takes clip coordinates to court coordinates (used for mouse handling):
	clip_to_court = glm::mat3x2(
		glm::vec2(aspect / scale, 0.0f),
		glm::vec2(0.0f, 1.0f / scale),
		glm::vec2(center.x, center.y)
	);

	//upload vertices to vertex_buffer:
	glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer); //set vertex_buffer as current
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(vertices[0]), vertices.data(), GL_STREAM_DRAW); //upload vertices array
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//set color_texture_program as current program:
	glUseProgram(color_texture_program.program);

	//upload OBJECT_TO_CLIP to the proper uniform location:
	glUniformMatrix4fv(color_texture_program.OBJECT_TO_CLIP_mat4, 1, GL_FALSE, glm::value_ptr(court_to_clip));

	//use the mapping vertex_buffer_for_color_texture_program to fetch vertex data:
	glBindVertexArray(vertex_buffer_for_color_texture_program);
	//bind the solid white texture to location zero:
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, white_tex);

	//run the OpenGL pipeline:
	glDrawArrays(GL_TRIANGLES, 0, GLsizei(vertices.size()));

	glBindTexture(GL_TEXTURE_2D, 0); //unbind the solid white texture
	glBindVertexArray(0); //reset vertex array to none
	glUseProgram(0); //reset current program to none

	GL_ERRORS(); //did the DrawSprites do something wrong?
}
