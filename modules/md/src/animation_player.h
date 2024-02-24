#pragma once
#include "scene/2d/sprite_2d.h"
#include "scene/animation/animation_player.h"


class SpriteFrames;
class Button;

class MDAnimationPlayer : public AnimationPlayer {
	GDCLASS(MDAnimationPlayer, AnimationPlayer);

public:
	MDAnimationPlayer();
	~MDAnimationPlayer();

protected:
	void _on_do_import_pressed();

	SpriteFrames *sprite_frames = nullptr;
	StringName sprite_frame_animation_name;

	Sprite2D* dest_sprite = nullptr;

	Button *do_import_button = nullptr;
};
