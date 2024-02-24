#include "animation_player.h"

#include "editor/editor_inspector.h"
#include "editor/plugins/animation_player_editor_plugin.h"
#include "editor/plugins/packed_scene_editor_plugin.h"
#include "scene/gui/button.h"
#include "scene/resources/sprite_frames.h"

MDAnimationPlayer::MDAnimationPlayer() {
	do_import_button = EditorInspector::create_inspector_action_button(TTR("Open Scene"));
	do_import_button->connect(SNAME("pressed"), callable_mp(this, &MDAnimationPlayer::_on_do_import_pressed));
	//do_import_button->set_disabled(!sprite_frames);
	add_child(do_import_button);
}

MDAnimationPlayer::~MDAnimationPlayer() {
}

void MDAnimationPlayer::_on_do_import_pressed() {
	if (!sprite_frames) {// || !dest_sprite) {
		return;
	}

	if (!sprite_frames->has_animation(sprite_frame_animation_name)) {
		print_error("Invalid animation name");
		return;
	}

	AnimationPlayerEditor* player_editor = AnimationPlayerEditor::get_singleton();
	if (!player_editor) {
		print_error("invalid player editor");
		return;
	}

	AnimationTrackEditor* track_editor = player_editor->get_track_editor();
	if (!track_editor) {
		print_error("invalid track editor");
		return;
	}

	Ref<Animation> current_animation = track_editor->get_current_animation();
	if (!current_animation.is_valid()) {
		print_error("invalid animation");
		return;
	}

	print_line("selected animation: %s", current_animation->get_name());

	const int track_count = current_animation->get_track_count();

#if 0
	const int new_track = Animation::add_track(TrackType p_type, int p_at_pos) {
	for (int track_index = 0; track_index < track_count; ++track_index) {
		if (current_animation->track_get_type(track_index) != Animation::TrackType::TYPE_VALUE) {
			continue;
		}

		Variant track_key_value = current_animation->track_get_key_value()

		int track_get_key_count(int p_track) const;
	Variant track_get_key_value(int p_track, int p_key_idx) const;
		current_animation->
	}

	animation->find_track()

	Ref<Animation> dest_anim = find_animation(dest_animation_name);
	const int anim_frame_count = sprite_frames->get_frame_count(sprite_frame_animation_name);

	for (int frame_index = 0; frame_index < anim_frame_count; ++frame_index) {
		const Ref<Texture2D> texture = sprite_frames->get_frame_texture(sprite_frame_animation_name, frame_index);
		const float frame_duration = sprite_frames->get_frame_duration(sprite_frame_animation_name, frame_index);
	}
#endif

}
