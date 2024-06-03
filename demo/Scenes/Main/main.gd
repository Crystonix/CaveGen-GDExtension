@tool
extends Node2D
@export_category("Exports")
@export var texture_rect:TextureRect
@export var cam:Camera2D

@export_category("Grid")
@export var GRID_SIZE:Vector2 = Vector2(512,512)
@export_range(0,1,0.05) var init_threshold:float = 0.45

@export_category("CA")
@export_range(0,50,1) var Iterations:int = 4
@export_range(0.1,0.5,0.1) var animation:float = 0.1

var voxel_data:Array = []

func _ready():
	var ca:CAErosion = CAErosion.new()
	print(ca.get_cell_state(0,0))
	#voxel_data = generate_initial_voxel_data(GRID_SIZE)
	#await get_tree().create_timer(1).timeout
	#update_texture(voxel_data)
	
func generate_initial_voxel_data(size:Vector2) -> Array:
	var grid:Array = []
	for y in range(size.y):
		var row:Array = []
		for x in range(size.x):
			if randf() < init_threshold:
				row.append(255.0)
			else:
				row.append(0.0)
		grid.append(row)
	return grid
	
func create_texture_from_voxel_data(p_grid:Array) -> ImageTexture:
	var width:int = p_grid.size()
	var height:int = p_grid[0].size()
	
	var image = Image.create(width, height, false, Image.FORMAT_RGBA8)
	
	for x in range(width):
		for y in range(height):
			var color_value = p_grid[x][y]
			image.set_pixel(x, y, Color(color_value / 255.0, color_value / 255.0, color_value / 255.0))
	return ImageTexture.create_from_image(image)

func update_texture(p_data:Array):
	texture_rect.set_texture(create_texture_from_voxel_data(p_data))
