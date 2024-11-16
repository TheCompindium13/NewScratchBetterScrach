# OpenGL Renderer with Shader and Texture Management

This project provides a basic implementation of an OpenGL-based renderer that includes shader management, texture handling, and utility classes for rendering objects. Below is a breakdown of the project's structure and functionality.

---

## **Features**

1. **Shader Management**  
   - Vertex and fragment shader support.
   - Dynamic uniform management.
   - GLSL-based shader parsing.

2. **Texture Management**  
   - Supports loading and binding textures using `stb_image`.
   - Texture settings like filtering and wrapping are configurable.

3. **Vertex and Index Buffers**  
   - Efficient buffer management for vertices and indices.
   - Supports custom layouts for vertex attributes.

4. **Error Logging**  
   - OpenGL error logging with detailed function, file, and line information.

5. **Shape Management**  
   - Ability to define, store, and draw shapes dynamically.

---

## **File Structure**

### **Core Components**
- **`Renderer.h` and `Renderer.cpp`**  
  Handles rendering and provides utilities for OpenGL calls.

- **`Shader.h` and `Shader.cpp`**  
  Parses, compiles, and links vertex and fragment shaders.  
  Provides methods to set shader uniforms.

- **`Texture.h` and `Texture.cpp`**  
  Manages texture loading, binding, and cleanup using `stb_image`.

- **`VertexBuffer.h` and `VertexBuffer.cpp`**  
  Handles the storage of vertex data.

- **`IndexBuffer.h` and `IndexBuffer.cpp`**  
  Manages index data for drawing elements.

- **`VertexArray.h` and `VertexArray.cpp`**  
  Manages the association of vertex buffers with shaders.

- **`VertexBufferLayout.h`**  
  Defines layouts for vertex attributes.

### **Utility**
- **`Shape.h` and `Shape.cpp`**  
  Abstracts drawable objects with associated buffers, textures, and shaders.

- **`vendor/stb_image/stb_image.h`**  
  Library for loading images into memory.

---

## **Dependencies**

- **OpenGL 4.6**  
  For rendering and shader functionality.

- **GLEW**  
  For OpenGL extension handling.

- **STB Image**  
  To load image files (e.g., PNG, JPEG) into OpenGL textures.

---

## **Usage**

### **Initialization**

1. Create and initialize buffers:
   ```cpp
   unsigned int indices[] = { 0, 1, 2, 2, 3, 0 };
   float positions[] = {
       // positions    // texture coordinates
       -0.5f, -0.5f,   0.0f, 0.0f,
        0.5f, -0.5f,   1.0f, 0.0f,
        0.5f,  0.5f,   1.0f, 1.0f,
       -0.5f,  0.5f,   0.0f, 1.0f
   };

   Shape shape("Quad", positions, indices, 4, 6, "path/to/texture.png", "path/to/shader.shader");
   ```

2. Add the shape to the collection:
   ```cpp
   Shape::AddShape("Quad", &shape);
   ```

### **Rendering Loop**

- Clear the screen:
   ```cpp
   Renderer renderer;
   renderer.Clear();
   ```

- Draw the shape:
   ```cpp
   Shape* quad = Shape::GetShape("Quad");
   quad->Draw(renderer, 1.0f); // Pass desired color intensity (r-value)
   ```

---

## **Shaders**

### Example Shader File (`shader.shader`)

```glsl
#shader vertex
#version 460
layout(location = 0) in vec4 position;
layout(location = 1) in vec2 texCoord;

out vec2 v_TexCoord;

void main()
{
    gl_Position = position;
    v_TexCoord = texCoord;
};

#shader fragment
#version 460
layout(location = 0) out vec4 color;

in vec2 v_TexCoord;

uniform vec4 u_Color;
uniform sampler2D u_Texture;

void main()
{
    color = texture(u_Texture, v_TexCoord) * u_Color;
};
```

---

## **Build Instructions**

### **Requirements**
- A C++17 compatible compiler.
- OpenGL 4.6.
- [GLEW](http://glew.sourceforge.net/) for OpenGL extension loading.
- [STB Image](https://github.com/nothings/stb) for texture loading.

### **Steps**
1. Clone the repository:
   ```bash
   git clone [https://github.com/TheCompindium13/NewScratchBetterScrach]
   ```

2. Build the project:
   - Use your preferred build system (e.g., Make, CMake).

---

## **License**

This project is licensed under the MIT License. See `LICENSE` for details.
