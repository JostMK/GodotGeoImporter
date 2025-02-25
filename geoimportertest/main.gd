extends Node

func _on_gd_example_position_changed(node, new_pos):
	print("The position of " + node.get_name() + " is now " + str(new_pos))
