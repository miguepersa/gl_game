#include "Object.h"
#include "Vertices.h"
#include "Projectile.h"
#include "Obstacle.h"
#include <cstdlib>
#include <ctime>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

const unsigned int windowWidth = 1900;
const unsigned int windowHeight = 1000;
float elevationAngleDegrees = 45.0f;

void spawnObstacles(float x, float z, Mesh cubeMesh, Mesh pyramidMesh, std::vector<Obstacle>& activeObstacles);

int main() {

	// GLFW Initialization
	glfwInit();

	// OpenGL version setup for GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	// Selecting core profile for OpenGL in GLFW
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Window instantiation
	GLFWwindow* window = glfwCreateWindow(windowWidth, windowHeight, "OpenGL", NULL, NULL);

	// Window error check
	if (window == NULL) {
		std::cout << "Error" << std::endl;
		glfwTerminate();
		return -1;
	}

	// Add the window to the context
	glfwMakeContextCurrent(window);

	// glad init
	gladLoadGL();

	// Specifying the viewport of OpenGL in the window
	// (0, 0) -> (800, 800)
	glViewport(0, 0, windowWidth, windowHeight);

	Texture floorTextures[]
	{
		Texture("textures/sand-ground-textured.jpg", "diffuse", 0)

	};

	// Generate shader program
	Shader shaderProgram("shaders/default.vert", "shaders/default.frag");
	Shader tankShader("shaders/default.vert", "shaders/default.frag");
	Shader turretShader("shaders/default.vert", "shaders/default.frag");
	Shader skyboxShader("shaders/skybox.vert", "shaders/skybox.frag");

	std::vector<Vertex> floorVerts(floorVertices, floorVertices + sizeof(floorVertices) / sizeof(Vertex));
	std::vector<GLuint> floorInd(floorIndices, floorIndices + sizeof(floorIndices) / sizeof(GLuint));
	std::vector<Texture> floorTex(floorTextures, floorTextures + sizeof(floorTextures) / sizeof(floorTextures));

	Mesh floor(floorVerts, floorInd, floorTex);

	Texture tankTextures[]
	{
		Texture("textures/tank.jpg", "diffuse", 0)

	};

	std::vector<Vertex> tankVerts(tankVertices, tankVertices + sizeof(tankVertices) / sizeof(Vertex));
	std::vector<GLuint> tankInd(tankIndices, tankIndices + sizeof(tankIndices) / sizeof(GLuint));
	std::vector<Texture> tankTex(tankTextures, tankTextures + sizeof(tankTextures) / sizeof(tankTextures));

	// Texturas para la torreta (puedes usar la misma textura que el tanque o una diferente)
	Texture turretTextures[]
	{
		Texture("textures/tank.jpg", "diffuse", 0)
	};

	std::vector<Vertex> turretVerts(turretVertices, turretVertices + sizeof(turretVertices) / sizeof(Vertex));
	std::vector<GLuint> turretInd(turretIndices, turretIndices + sizeof(turretIndices) / sizeof(GLuint));
	std::vector<Texture> turretTex(turretTextures, turretTextures + sizeof(turretTextures) / sizeof(turretTextures));

	
	std::vector<Mesh>tankMeshes = { Mesh(tankVerts, tankInd, tankTex), Mesh(turretVerts, turretInd, turretTex) };

	Texture projectileTextures[]
	{
		Texture("textures/projectile.jpg", "diffuse", 0)
	};
	std::vector<Vertex> projectileVerts(projectileVertices, projectileVertices + sizeof(projectileVertices) / sizeof(Vertex));
	std::vector<GLuint> projectileInd(projectileIndices, projectileIndices + sizeof(projectileIndices) / sizeof(GLuint));
	std::vector<Texture> projectileTex(projectileTextures, projectileTextures + sizeof(projectileTextures) / sizeof(Texture));
	Mesh projectileMesh(projectileVerts, projectileInd, projectileTex);
	// Vector para almacenar proyectiles activos
	std::vector<Projectile> activeProjectiles;

	Object tankObject(tankMeshes);
	tankObject.setMeshOffset(glm::vec3(0.0f, 0.0f, 0.0f), 0);
	tankObject.setMeshOffset(glm::vec3(0.0f, 1.0f, 0.0f), 1);

	Texture obstacleTextures[]
	{
		Texture("textures/obstacle.jpg", "diffuse", 0)
	};
	std::vector<Vertex> cubeVerts(cubeVertices, cubeVertices + sizeof(cubeVertices) / sizeof(Vertex));
	std::vector<GLuint> cubeInd(cubeIndices, cubeIndices + sizeof(cubeIndices) / sizeof(GLuint));
	std::vector<Texture> obstacleTex(obstacleTextures, obstacleTextures + sizeof(obstacleTextures) / sizeof(Texture));
	Mesh cubeMesh(cubeVerts, cubeInd, obstacleTex);
	std::vector<Vertex> pyramidVerts(pyramidVertices, pyramidVertices + sizeof(pyramidVertices) / sizeof(Vertex));
	std::vector<GLuint> pyramidInd(pyramidIndices, pyramidIndices + sizeof(pyramidIndices) / sizeof(GLuint));
	Mesh pyramidMesh(pyramidVerts, pyramidInd, obstacleTex);
	// Arreglo de obstaculos presentes en pantalla
	std::vector<Obstacle> activeObstacles;

	// Light Shader
	Shader lightShader("shaders/light.vert", "shaders/light.frag");
	std::vector<Vertex> lightVerts(lightVertices, lightVertices + sizeof(lightVertices) / sizeof(Vertex));
	std::vector<GLuint> lightInd(lightIndices, lightIndices + sizeof(lightIndices) / sizeof(GLuint) );
	Mesh light(lightVerts, lightInd, floorTex);
	
	glm::vec4 lightColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	glm::vec3 lightPos = glm::vec3(1.0f, 10.0f, 1.0f);
	glm::mat4 lightModel = glm::mat4(1.0f);
	lightModel = glm::translate(lightModel, lightPos);

	glm::vec3 objPos = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::mat4 objModel = glm::mat4(1.0f);
	objModel = glm::translate(objModel, objPos);

	lightShader.Activate();
	glUniformMatrix4fv(glGetUniformLocation(lightShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(lightModel));
	glUniform4f(glGetUniformLocation(lightShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);

	shaderProgram.Activate();
	glUniformMatrix4fv(glGetUniformLocation(shaderProgram.ID, "model"), 1, GL_FALSE, glm::value_ptr(objModel));
	glUniform4f(glGetUniformLocation(shaderProgram.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	glUniform3f(glGetUniformLocation(shaderProgram.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);
	glUniform3f(glGetUniformLocation(shaderProgram.ID, "position"), 0.0f, 0.0f, 0.0f );

	tankShader.Activate();
	glUniformMatrix4fv(glGetUniformLocation(tankShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(objModel));
	glUniform4f(glGetUniformLocation(tankShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	glUniform3f(glGetUniformLocation(tankShader.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);
	glUniform3f(glGetUniformLocation(shaderProgram.ID, "position"), 0.0f, 0.0f, 0.0f);

	turretShader.Activate();
	glUniformMatrix4fv(glGetUniformLocation(tankShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(objModel));
	glUniform4f(glGetUniformLocation(tankShader.ID, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	glUniform3f(glGetUniformLocation(tankShader.ID, "lightPos"), lightPos.x, lightPos.y, lightPos.z);
	glUniform3f(glGetUniformLocation(shaderProgram.ID, "position"), 0.0f, 0.0f, 0.0f);

	skyboxShader.Activate();
	glUniform1i(glGetUniformLocation(skyboxShader.ID, "skybox"), 0);
	// Deltatime = crntTime - prevTime

	// Enable depth buffer
	glEnable(GL_DEPTH_TEST);

	Camera camera(windowWidth, windowHeight, glm::vec3(0.0f, 1.5f, 6.0f));

	double prevTime = 0.0;
	double currentTime = 0.0;
	double deltaTime;

	unsigned int counter = 0;

	glfwSwapInterval(1);

	// Vertex Array, Vertex Buffer and Element Buffer for the skybox
	unsigned int sbVertexArray, sbVertexBuffer, sbElementBuffer;
	glGenVertexArrays(1, &sbVertexArray);
	glGenBuffers(1, &sbVertexBuffer);
	glGenBuffers(1, &sbElementBuffer);
	glBindVertexArray(sbVertexArray);
	glBindBuffer(GL_ARRAY_BUFFER, sbVertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), &skyboxVertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, sbElementBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(skyboxIndices), &skyboxIndices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	// All the faces of the cubemap (make sure they are in this exact order)
	std::string facesCubemap[6] =
	{
		"textures/skybox/right.jpg",
		"textures/skybox/left.jpg",
		"textures/skybox/top.jpg",
		"textures/skybox/bottom.jpg",
		"textures/skybox/front.jpg",
		"textures/skybox/back.jpg"
	};

	// Creates the cubemap texture object
	unsigned int cubemapTexture;
	glGenTextures(1, &cubemapTexture);
	glBindTexture(GL_TEXTURE_CUBE_MAP, cubemapTexture);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	// These are very important to prevent seams
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	// This might help with seams on some systems
	//glEnable(GL_TEXTURE_CUBE_MAP_SEAMLESS);

	// Cycles through all the textures and attaches them to the cubemap object
	for (unsigned int i = 0; i < 6; i++)
	{
		int width, height, nrChannels;
		unsigned char* data = stbi_load(facesCubemap[i].c_str(), &width, &height, &nrChannels, 0);
		if (data)
		{
			stbi_set_flip_vertically_on_load(false);
			glTexImage2D
			(
				GL_TEXTURE_CUBE_MAP_POSITIVE_X + i,
				0,
				GL_RGB,
				width,
				height,
				0,
				GL_RGB,
				GL_UNSIGNED_BYTE,
				data
			);
			stbi_image_free(data);
		}
		else
		{
			std::cout << "Failed to load texture: " << facesCubemap[i] << std::endl;
			stbi_image_free(data);
		}
	}

	std::vector<Shader> tankShaders = { tankShader, turretShader };

	// Main loop
	while (!glfwWindowShouldClose(window)) 
	{

		currentTime = glfwGetTime();
		deltaTime = currentTime - prevTime;
		counter++;
		if (deltaTime >= 1.0 / 30.0)
		{
			std::string FPS = std::to_string((1.0 / deltaTime) * counter);
			std::string ms = std::to_string((deltaTime / counter) * 1000);
			std::string windowTitle = "TankWars - " + FPS + "FPS / " + ms + "ms";
			glfwSetWindowTitle(window, windowTitle.c_str());
			prevTime = currentTime;
			counter = 0;
		}

		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);

		// Clean back buffer and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		// Manejo de input tanque
		tankObject.HandleInput(window, camera.Orientation, (float)currentTime, windowWidth, windowHeight);

		//camera.Inputs(window, (float) currentTime, tankObject.Position);
		camera.followObject(tankObject.Position, tankObject.Orientation);
		camera.updateMatrix(45.0f, 0.1f, 100.0f);

		static bool canSpawnObstacle = true;

		if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)
		{

			if (canSpawnObstacle)
			{
				spawnObstacles(tankObject.Position.x, tankObject.Position.z, cubeMesh, pyramidMesh, activeObstacles);

				canSpawnObstacle = false;
			}
		}
		else
		{
			canSpawnObstacle = true;
		}

		static bool canShoot = true;

		if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS)
		{

			if (canShoot)
			{
				//glm::vec3 barrelOffset = glm::vec3(tankObject.meshes[1].Orientation.x * 0.5, tankObject.meshes[1].Orientation.y * 0.5, tankObject.meshes[1].Orientation.z * 0.5);

				// rotar segun rotacion de la torre
				/*glm::mat4 turretRotationMatrix = glm::rotate(glm::mat4(1.0f), tankObject.meshes[1].rotateAngles, glm::vec3(0.0f, 1.0f, 0.0f));
				glm::vec3 rotatedBarrelOffset = glm::vec3(turretRotationMatrix * glm::vec4(barrelOffset, 1.0f));*/

				// direccion
				glm::vec3 projectileDirection = tankObject.meshes[1].Orientation;
				
				// pos init projectile
				glm::vec3 projectileStartPos = tankObject.meshes[1].Position + projectileDirection;


				Projectile newProjectile(projectileMesh, projectileStartPos, projectileDirection, 20.0f);

				// Agregar el proyectil al la lista
				activeProjectiles.push_back(newProjectile);

				canShoot = false;
			}
		}
		else
		{
			canShoot = true;
		}

		// flecha arriba para subir angulo
		if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
		{
			elevationAngleDegrees += 30.0f * deltaTime;
			if (elevationAngleDegrees > 89.0f)
				elevationAngleDegrees = 89.0f; // limite de 90 grados
		}

		// flecha abajo para disminuir angulo
		if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
		{
			elevationAngleDegrees -= 30.0f * deltaTime;
			if (elevationAngleDegrees < 1.0f)
				elevationAngleDegrees = 1.0f; // Limite 1 grado
		}

		static bool canShootParabolic = true;

		if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
		{	

			if (canShootParabolic)
			{
				//glm::vec3 barrelOffset = glm::vec3(0.0f, 0.0f, 0.5f); // ******Cambiar cuando se ponga ca�on*********

				// rotar segun rotacion de la torre
				/*glm::mat4 turretRotationMatrix = glm::rotate(glm::mat4(1.0f), tankObject.meshes[1].rotateAngles, glm::vec3(0.0f, 1.0f, 0.0f));
				glm::vec3 rotatedBarrelOffset = glm::vec3(turretRotationMatrix * glm::vec4(barrelOffset, 1.0f));*/

				// pos init projectile

				// Callculo de parabola
				float elevationAngle = glm::radians(elevationAngleDegrees);
				glm::vec3 projectileDirection = tankObject.meshes[1].Orientation;
				float projectileSpeed = 20.0f;
				glm::vec3 projectileStartPos = tankObject.meshes[1].Position + projectileDirection;

				Projectile newProjectile(projectileMesh, projectileStartPos, projectileDirection, projectileSpeed, true);

				activeProjectiles.push_back(newProjectile);
				canShootParabolic = false;
			}
		}
		else
		{
			canShootParabolic = true;
		}

		for (size_t i = 0; i < activeProjectiles.size();)
		{
			activeProjectiles[i].Update(deltaTime);

			bool projectileDestroyed = false;

			// Verificar colisiones
			for (size_t j = 0; j < activeObstacles.size();)
			{
				float distance = glm::distance(activeProjectiles[i].position, activeObstacles[j].position);
				float collisionDistance = activeProjectiles[i].collisionRadius + activeObstacles[j].collisionRadius;

				if (distance <= collisionDistance)
				{
					// Si colisionan, se eliminan ambos
					activeProjectiles.erase(activeProjectiles.begin() + i);
					activeObstacles.erase(activeObstacles.begin() + j);
					projectileDestroyed = true;
					break;
				}
				else
				{
					++j;
				}
			}

			if (!projectileDestroyed)
			{
				// Si el rpoeyctil tienen mucho tiempo de vida, borrarlo
				if (!activeProjectiles[i].IsAlive())
				{
					activeProjectiles.erase(activeProjectiles.begin() + i);
				}
				else
				{
					++i;
				}
			}
		}

		floor.Draw(shaderProgram, camera);
		light.Draw(lightShader, camera);
		tankObject.Draw(tankShaders, camera);
				// Usamos shader de tanque porque hacer shaders nuevos es r word
		for (Projectile& proj : activeProjectiles)
		{
			proj.Draw(tankShader, camera);
		}
		for (Obstacle& obstacle : activeObstacles)
		{
			obstacle.Draw(tankShader, camera);
		}


		glDepthFunc(GL_LEQUAL);
		
		skyboxShader.Activate();
		glm::mat4 view = glm::mat4(1.0f);
		glm::mat4 projection = glm::mat4(1.0f);
		// We make the mat4 into a mat3 and then a mat4 again in order to get rid of the last row and column
		// The last row and column affect the translation of the skybox (which we don't want to affect)
		view = glm::mat4(glm::mat3(glm::lookAt(camera.Position, camera.Position + camera.Orientation, camera.Up)));
		projection = glm::perspective(glm::radians(45.0f), (float)windowWidth / windowHeight, 0.1f, 100.0f);
		glUniformMatrix4fv(glGetUniformLocation(skyboxShader.ID, "view"), 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(glGetUniformLocation(skyboxShader.ID, "projection"), 1, GL_FALSE, glm::value_ptr(projection));

		// Draws the cubemap as the last object so we can save a bit of performance by discarding all fragments
		// where an object is present (a depth of 1.0f will always fail against any object's depth value)
		glBindVertexArray(sbVertexArray);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_CUBE_MAP, cubemapTexture);
		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);

		// Switch back to the normal depth function
		glDepthFunc(GL_LESS);
		// Flip
		glfwSwapBuffers(window);

		// Calling of the update function
		glfwPollEvents();
	}

	// Deleting remaining objects 
	shaderProgram.Delete();
	lightShader.Delete();
	skyboxShader.Delete();

	// Window closing
	glfwDestroyWindow(window);
	
	// GLFW closing
	glfwTerminate();

	return 0;
}

void spawnObstacles(float x, float z, Mesh cubeMesh, Mesh pyramidMesh, std::vector<Obstacle>& activeObstacles)
{
	float spawnRange = 10.0f;
	float randomX = x + ((float(rand()) / float(RAND_MAX)) * spawnRange - spawnRange / 2.0f);
	float randomZ = z + ((float(rand()) / float(RAND_MAX)) * spawnRange - spawnRange / 2.0f);
	float randomY = ((float(rand()) / float(RAND_MAX)) * 5);

	glm::vec3 obstaclePosition = glm::vec3(randomX, randomY, randomZ);
	ObstacleType type = (rand() % 2 == 0) ? CUBE : PYRAMID;

	if (type == CUBE)
	{
		Obstacle newObstacle(cubeMesh, obstaclePosition, CUBE);
		activeObstacles.push_back(newObstacle);
	}
	else
	{
		Obstacle newObstacle(pyramidMesh, obstaclePosition, PYRAMID);
		activeObstacles.push_back(newObstacle);
	}
}