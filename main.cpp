#include <iostream>
#include "raylib.h"

int main(void)
{
	InitWindow(800, 800, "Minecraft");

	Camera3D camera = {0};
	camera.position = (Vector3){0.0f, 0.0f, 10.0f};
	camera.target = (Vector3){0.0f, 0.0f, 0.0f};
	camera.up = (Vector3){0.0f, 1.0f, 0.0f};
	camera.fovy = 45.0f;
	camera.projection = CAMERA_PERSPECTIVE;

	Vector3 cubePosition = {0.0f, 0.0f, 0.0f};
	DisableCursor();
	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		UpdateCamera(&camera, CAMERA_FREE);
		if (IsKeyPressed(KEY_R))
			camera.target = (Vector3){0.0f, 0.0f, 0.0f};

		BeginDrawing();
			ClearBackground(SKYBLUE);
			BeginMode3D(camera);

			DrawCube(cubePosition, 1.0f, 1.0f, 1.0f, RED);
			EndMode3D();
		EndDrawing();
	}

	CloseWindow();
	return 0;
}
