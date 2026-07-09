# WE ARE BULIDING A RADAR USING THE CPP AND RAYLIB
# g++ main.cpp -IC:\raylib\include -LC:\raylib\lib -lraylib -lopengl32 -lgdi32 -lwinmm -o main
"command to complie"
Because Raylib has over 500+ functions, dumping them all in a single raw wall of text would break your scroll wheel. Instead, here is the complete, comprehensive master list of Raylib's functions organized by module.

Every single function follows the exact same translation rule:

C++ API: Uses CamelCase (e.g., InitWindow).

Python (pyray) API: Uses snake_case (e.g., init_window).

1. Core Module (rcore)
This handles windows, system configuration, timing, inputs (mouse, keyboard, gamepad, touch), and 3D cameras.

Window & Context Management
C++ Function	Python (pyray) Function	Description
InitWindow()	init_window()	Initialize window and OpenGL context
CloseWindow()	close_window()	Close window and unload OpenGL context
WindowShouldClose()	window_should_close()	Check if application should close
IsWindowReady()	is_window_ready()	Check if window has been initialized successfully
IsWindowFullscreen()	is_window_fullscreen()	Check if window is currently fullscreen
IsWindowHidden()	is_window_hidden()	Check if window is currently hidden
IsWindowMinimized()	is_window_minimized()	Check if window is currently minimized
IsWindowMaximized()	is_window_maximized()	Check if window is currently maximized
IsWindowFocused()	is_window_focused()	Check if window is currently focused
IsWindowResized()	is_window_resized()	Check if window has been resized since last frame
IsWindowState()	is_window_state()	Check if a specific window state flag is set
SetWindowState()	set_window_state()	Set window configuration flags
ClearWindowState()	clear_window_state()	Clear window configuration flags
ToggleFullscreen()	toggle_fullscreen()	Toggle window state: fullscreen/windowed
ToggleBorderlessWindowed()	toggle_borderless_windowed()	Toggle window state: borderless windowed
MaximizeWindow()	maximize_window()	Set window state: maximized
MinimizeWindow()	minimize_window()	Set window state: minimized
RestoreWindow()	restore_window()	Set window state: restored
SetWindowIcon()	set_window_icon()	Set icon for window (using an Image)
SetWindowSize()	set_window_size()	Set window dimensions
SetWindowMinSize()	set_window_min_size()	Set window minimum dimensions
SetWindowMaxSize()	set_window_max_size()	Set window maximum dimensions
SetWindowOpacity()	set_window_opacity()	Set window opacity (0.0f to 1.0f)
SetWindowFocused()	set_window_focused()	Set window focused state
GetScreenWidth()	get_screen_width()	Get current screen width
GetScreenHeight()	get_screen_height()	Get current screen height
GetRenderWidth()	get_render_width()	Get current render width
GetRenderHeight()	get_render_height()	Get current render height
GetWindowHandle()	get_window_handle()	Get native window handle pointer
GetWindowPosition()	get_window_position()	Get window position XY on monitor
GetWindowScaleDpi()	get_window_scale_dpi()	Get window DPI scale factor
SetWindowTitle()	set_window_title()	Change the window title string
Drawing Context & Timing
C++ Function	Python Function	Description
ClearBackground()	clear_background()	Set background color
BeginDrawing()	begin_drawing()	Setup canvas to start drawing
EndDrawing()	end_drawing()	End canvas drawing and swap buffers
BeginMode2D()	begin_mode_2d()	Begin 2D mode with custom camera
EndMode2D()	end_mode_2d()	End 2D mode with custom camera
BeginMode3D()	begin_mode_3d()	Begin 3D mode with custom camera
EndMode3D()	end_mode_3d()	End 3D mode with custom camera
BeginTextureMode()	begin_texture_mode()	Begin drawing to a render texture
EndTextureMode()	end_texture_mode()	End drawing to a render texture
BeginShaderMode()	begin_shader_mode()	Begin custom shader drawing
EndShaderMode()	end_shader_mode()	End custom shader drawing
BeginBlendMode()	begin_blend_mode()	Begin custom color blending mode
EndBlendMode()	end_blend_mode()	End custom color blending mode
BeginScissorMode()	begin_scissor_mode()	Begin scissor mode (cropping region)
EndScissorMode()	end_scissor_mode()	End scissor mode
SetTargetFPS()	set_target_fps()	Set target FPS (frames per second)
GetFrameTime()	get_frame_time()	Get time in seconds for last frame (delta time)
GetTime()	get_time()	Get elapsed time in seconds since initialization
GetFPS()	get_fps()	Get current FPS
Input Handling (Keyboard, Mouse, Gamepad)
C++ Function	Python Function	Description
IsKeyPressed()	is_key_pressed()	Check if a key has been pressed once
IsKeyDown()	is_key_down()	Check if a key is being pressed down
IsKeyReleased()	is_key_released()	Check if a key has been released once
IsKeyUp()	is_key_up()	Check if a key is NOT being pressed
GetKeyPressed()	get_key_pressed()	Get key pressed (keycode), call repeatedly for queue
GetCharPressed()	get_char_pressed()	Get char pressed (unicode), call repeatedly for queue
IsMouseButtonPressed()	is_mouse_button_pressed()	Check if a mouse button has been pressed once
IsMouseButtonDown()	is_mouse_button_down()	Check if a mouse button is being pressed down
IsMouseButtonReleased()	is_mouse_button_released()	Check if a mouse button has been released once
IsMouseButtonUp()	is_mouse_button_up()	Check if a mouse button is NOT being pressed
GetMouseX()	get_mouse_x()	Get mouse position X
GetMouseY()	get_mouse_y()	Get mouse position Y
GetMousePosition()	get_mouse_position()	Get mouse position XY
GetMouseDelta()	get_mouse_delta()	Get mouse delta between frames
SetMousePosition()	set_mouse_position()	Set mouse position XY
SetMouseOffset()	set_mouse_offset()	Set mouse offset
SetMouseScale()	set_mouse_scale()	Set mouse scale
GetMouseWheelMove()	get_mouse_wheel_move()	Get mouse wheel movement for X or Y
SetCursor()	set_cursor()	Set mouse cursor icon style
IsGamepadAvailable()	is_gamepad_available()	Check if a gamepad is available
GetGamepadName()	get_gamepad_name()	Get gamepad internal name string
IsGamepadButtonPressed()	is_gamepad_button_pressed()	Check if a gamepad button has been pressed once
IsGamepadButtonDown()	is_gamepad_button_down()	Check if a gamepad button is being pressed down
GetGamepadAxisCount()	get_gamepad_axis_count()	Get gamepad axis count
GetGamepadAxisMovement()	get_gamepad_axis_movement()	Get gamepad axis movement value
2. Shapes Module (rshapes)
Used for rendering basic 2D primitives and handling flat geometric collision checks.

C++ Function	Python Function	Description
SetShapesTexture()	set_shapes_texture()	Define a custom texture to draw shapes
DrawPixel()	draw_pixel()	Draw a single pixel
DrawPixelV()	draw_pixel_v()	Draw a single pixel using Vector2
DrawLine()	draw_line()	Draw a straight line
DrawLineV()	draw_line_v()	Draw a straight line using Vector2
DrawLineEx()	draw_line_ex()	Draw a line with a custom thickness value
DrawLineStrip()	draw_line_strip()	Draw a sequence of lines
DrawLineBezier()	draw_line_bezier()	Draw a line using cubic-bezier curves
DrawCircle()	draw_circle()	Draw a filled circle
DrawCircleSector()	draw_circle_sector()	Draw a piece of a circle
DrawCircleSectorLines()	draw_circle_sector_lines()	Draw the outline of a circle piece
DrawCircleGradient()	draw_circle_gradient()	Draw a circle with a radial gradient color
DrawCircleLines()	draw_circle_lines()	Draw circle outline
DrawEllipse()	draw_ellipse()	Draw a filled ellipse
DrawEllipseLines()	draw_ellipse_lines()	Draw ellipse outline
DrawRing()	draw_ring()	Draw a ring shape
DrawRingLines()	draw_ring_lines()	Draw ring outline
DrawRectangle()	draw_rectangle()	Draw a filled rectangle
DrawRectangleV()	draw_rectangle_v()	Draw a filled rectangle using Vector2
DrawRectangleRec()	draw_rectangle_rec()	Draw a filled rectangle using a Rectangle data struct
DrawRectanglePro()	draw_rectangle_pro()	Draw rectangle with custom origin, rotation, and color
DrawRectangleGradientV()	draw_rectangle_gradient_v()	Draw rectangle with vertical gradient
DrawRectangleGradientH()	draw_rectangle_gradient_h()	Draw rectangle with horizontal gradient
DrawRectangleLines()	draw_rectangle_lines()	Draw rectangle outline
DrawRectangleLinesEx()	draw_rectangle_lines_ex()	Draw rectangle outline with custom line thickness
DrawTriangle()	draw_triangle()	Draw a filled triangle
DrawTriangleLines()	draw_triangle_lines()	Draw triangle outline
DrawPoly()	draw_poly()	Draw a regular polygon (hexagon, octagon, etc.)
DrawPolyLines()	draw_poly_lines()	Draw regular polygon outline
CheckCollisionRecs()	check_collision_recs()	Check collision between two Rectangles
CheckCollisionCircles()	check_collision_circles()	Check collision between two Circles
CheckCollisionCircleRec()	check_collision_circle_rec()	Check collision between a Circle and a Rectangle
CheckCollisionPointRec()	check_collision_point_rec()	Check if a Vector2 point is inside a Rectangle
CheckCollisionPointCircle()	check_collision_point_circle()	Check if a Vector2 point is inside a Circle
CheckCollisionPointTriangle()	check_collision_point_triangle()	Check if a Vector2 point is inside a Triangle
GetCollisionRec()	get_collision_rec()	Get the overlapping collision Rectangle area
3. Textures Module (rtextures)
Handles CPU Image parsing and GPU Texture management, wrapping actions like scaling, filtering, and blending configurations.

C++ Function	Python Function	Description
LoadImage()	load_image()	Load image from file into CPU memory
LoadImageRaw()	load_image_raw()	Load image from raw data stream
LoadImageAnim()	load_image_anim()	Load animated image (GIF) framework
LoadImageFromMemory()	load_image_from_memory()	Load image from file-data memory buffer
LoadImageFromTexture()	load_image_from_texture()	Load image from a GPU texture
LoadImageFromScreen()	load_image_from_screen()	Take a screenshot and load into Image
IsImageReady()	is_image_ready()	Verify image load status
UnloadImage()	unload_image()	Free CPU image from memory
ExportImage()	export_image()	Export image context to file format
LoadTexture()	load_texture()	Load texture into GPU memory
LoadTextureFromImage()	load_texture_from_image()	Load texture into GPU memory from Image data
LoadRenderTexture()	load_render_texture()	Load render texture object (for rendering to texture)
IsTextureReady()	is_texture_ready()	Verify GPU texture status
UnloadTexture()	unload_texture()	Free GPU texture from VRAM
IsRenderTextureReady()	is_render_texture_ready()	Verify render texture status
UnloadRenderTexture()	unload_render_texture()	Free render texture object from VRAM
UpdateTexture()	update_texture()	Update GPU texture pixel data with new arrays
ImageCopy()	image_copy()	Duplicate an image structure
ImageFromImage()	image_from_image()	Create an image from a cropped section of another
ImageToPOT()	image_to_pot()	Convert image to Power-of-Two dimensions
ImageFormat()	image_format()	Convert image pixel format
ImageAlphaMask()	image_alpha_mask()	Apply an alpha mask to an image
ImageAlphaClear()	image_alpha_clear()	Clear alpha channel using a threshold
ImageAlphaCrop()	image_alpha_crop()	Crop image alpha borders
ImageAlphaPremultiply()	image_alpha_premultiply()	Premultiply alpha channels
ImageCrop()	image_crop()	Crop image context
ImageResize()	image_resize()	Resize image (Bicubic filter)
ImageResizeNN()	image_resize_nn()	Resize image (Nearest-Neighbor filter)
ImageMipmaps()	image_mipmaps()	Generate mipmaps for an Image
ImageDither()	image_dither()	Dither image to 16-bit or lower formats
ImageFlipVertical()	image_flip_vertical()	Flip image vertically
ImageFlipHorizontal()	image_flip_horizontal()	Flip image horizontally
ImageRotate()	image_rotate()	Rotate image by 90-degree steps
ImageRotateCW()	image_rotate_cw()	Rotate image clockwise
ImageRotateCCW()	image_rotate_ccw()	Rotate image counter-clockwise
ImageColorTint()	image_color_tint()	Tint image pixels with a target color
ImageColorInvert()	image_color_invert()	Invert image colors
ImageColorGrayscale()	image_color_grayscale()	Convert image to grayscale
ImageColorContrast()	image_color_contrast()	Modify image contrast
ImageColorBrightness()	image_color_brightness()	Modify image brightness
DrawTexture()	draw_texture()	Draw a GPU texture on screen
DrawTextureV()	draw_texture_v()	Draw texture using Vector2 position
DrawTextureEx()	draw_texture_ex()	Draw texture with scaling and rotation transformations
DrawTextureRec()	draw_texture_rec()	Draw part of a texture defined by a source Rectangle
DrawTexturePro()	draw_texture_pro()	Draw texture with comprehensive transformations and origin adjustments
4. Text Module (rtext)
Manages bitmap fonts and processes multi-line string drawing tasks.

C++ Function	Python Function	Description
GetFontDefault()	get_font_default()	Get the default fallback system Font
LoadFont()	load_font()	Load a Font file (TTF/XNA)
LoadFontEx()	load_font_ex()	Load a Font file with custom sizing specifications
IsFontReady()	is_font_ready()	Verify font loading state
UnloadFont()	unload_font()	Unload font context from memory
DrawFPS()	draw_fps()	Built-in utility to draw FPS text counter
DrawText()	draw_text()	Basic text rendering utility
DrawTextEx()	draw_text_ex()	Render text with custom Font, spacing, and size
DrawTextPro()	draw_text_pro()	Render text with Font, rotation, origin transformations
MeasureText()	measure_text()	Measure default text width in pixels
MeasureTextEx()	measure_text_ex()	Measure custom font text width/height dimensions
5. Models Module (rmodels)
Handles 3D coordinate transformations, bounding boxes, meshes, materials, and skeleton drawing.

C++ Function	Python Function	Description
DrawLine3D()	draw_line_3d()	Draw a line in 3D space
DrawPoint3D()	draw_point_3d()	Draw a point/pixel in 3D space
DrawCircle3D()	draw_circle_3d()	Draw a circle in 3D space
DrawTriangle3D()	draw_triangle_3d()	Draw a triangle in 3D space
DrawCube()	draw_cube()	Draw a filled 3D cube
DrawCubeWires()	draw_cube_wires()	Draw 3D cube outline wires
DrawSphere()	draw_sphere()	Draw a filled 3D sphere
DrawSphereWires()	draw_sphere_wires()	Draw 3D sphere outline wires
DrawCylinder()	draw_cylinder()	Draw a 3D cylinder
DrawCylinderWires()	draw_cylinder_wires()	Draw 3D cylinder outline wires
DrawCapsule()	draw_capsule()	Draw a 3D capsule shape
DrawCapsuleWires()	draw_capsule_wires()	Draw 3D capsule outline wires
DrawPlane()	draw_plane()	Draw a 3D flat plane
DrawRay()	draw_ray()	Draw a 3D line ray
DrawGrid()	draw_grid()	Draw a standard 3D visual reference grid
LoadModel()	load_model()	Load 3D model path (OBJ, GLTF)
LoadModelFromMesh()	load_model_from_mesh()	Build model out of manual Mesh calculations
IsModelReady()	is_model_ready()	Verify model loading state
UnloadModel()	unload_model()	Free model object structure from system
DrawModel()	draw_model()	Draw a loaded 3D model frame
DrawModelEx()	draw_model_ex()	Draw model with advanced rotation/scaling vectors
DrawModelWires()	draw_model_wires()	Draw model wireframe outlines
DrawModelWiresEx()	draw_model_wires_ex()	Draw model wireframes with advanced scaling
DrawBoundingBox()	draw_bounding_box()	Draw a 3D structural bounding box container
UploadMesh()	upload_mesh()	Send CPU structural mesh data to GPU VRAM
UpdateMeshBuffer()	update_mesh_buffer()	Update specific data attributes within mesh buffers
UnloadMesh()	unload_mesh()	Free mesh structure from memory
DrawMesh()	draw_mesh()	Draw a single GPU mesh instance
LoadMaterials()	load_materials()	Load material files
SetMaterialTexture()	set_material_texture()	Map a texture target to a model material slot
6. Audio Module (raudio)
Manages audio hardware streams, loads sound effects (Sound), and ticks music loops (Music).

C++ Function	Python Function	Description
InitAudioDevice()	init_audio_device()	Initialize audio device context
CloseAudioDevice()	close_audio_device()	Close audio device context
IsAudioDeviceReady()	is_audio_device_ready()	Verify audio driver system status
SetMasterVolume()	set_master_volume()	Set main volume amplitude output
GetMasterVolume()	get_master_volume()	Get current main volume configuration
LoadSound()	load_sound()	Load audio sample clip into memory
LoadSoundFromWave()	load_sound_from_wave()	Build sound instance using Wave structures
IsSoundReady()	is_sound_ready()	Verify sound loading state
UnloadSound()	unload_sound()	Free audio sample data from memory
PlaySound()	play_sound()	Play a single instance of a sound effect
StopSound()	stop_sound()	Stop playing a specific sound effect
PauseSound()	pause_sound()	Pause a sound effect
ResumeSound()	resume_sound()	Resume a paused sound effect
IsSoundPlaying()	is_sound_playing()	Verify if a specific sound is actively outputting
SetSoundVolume()	set_sound_volume()	Adjust sound volume context
SetSoundPitch()	set_sound_pitch()	Adjust sound pitch playback modifier
SetSoundPan()	set_sound_pan()	Adjust sound structural stereo panning
LoadMusicStream()	load_music_stream()	Load streaming audio track structure (OGG/MP3)
IsMusicStreamReady()	is_music_stream_ready()	Verify music stream loading state
UnloadMusicStream()	unload_music_stream()	Free streaming music track file
PlayMusicStream()	play_music_stream()	Initiate streaming audio loop tracking
IsMusicStreamPlaying()	is_music_stream_playing()	Verify if stream is active
UpdateMusicStream()	update_music_stream()	Refresh streaming buffers (Call inside frame loop)
StopMusicStream()	stop_music_stream()	Halt active streaming tracks
PauseMusicStream()	pause_music_stream()	Pause music tracking frames
ResumeMusicStream()	resume_music_stream()	Resume playback tracking
SetMusicVolume()	set_music_volume()	Adjust streaming volume values
SetMusicPitch()	set_music_pitch()	Adjust streaming pitch values
SetMusicPan()	set_music_pan()	Adjust streaming stereo panning configurations
GetMusicTimeLength()	get_music_time_length()	Get music loop audio length in seconds
GetMusicTimePlayed()	get_music_time_played()	Get current tracking position in seconds
