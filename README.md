If you wanna start making shaders, yr gonna have to set up yr Visual Studio (the purple one, not Visual Studio Code)
I have provided a template that is configured to my paths, but I'll explain here how u can set up everything easily for yourself.

First we are going to make a template for OpenGL projects. 
If you want to use mine as an example then put the OpenGL_Temp.zip file in this folder
C:\Users\cjulg\OneDrive\Documents\Visual Studio 2022\Templates\ProjectTemplates
This template won't work for u but it may come in handy to have side by side while u make yr own. 

To make your own template, you'll have to create a new project in Visual Studio, then go to
Debug > Properties > General > Include Directories
Put the path to the include folder (inside the OpenGL Library folder)
It should look something like this C:\Users\cjulg\OneDrive\Documents\OpenGLlibrary\include

Next go to 
Debug > Properties > Linker > (General) > Additional Library Directories
Put the path to the lib folder (inside the OpenGL Library folder)
It shold look something like this C:\Users\cjulg\OneDrive\Documents\OpenGLlibrary\lib

Last, go to
Debug > Properties > Linker > Input > Additional Dependencies
Write this stuff in. They're libraries and some important files.
glfw3.lib;glew32.lib;soil2-debug.lib;opengl32.lib;gdi32.lib;user32.lib;shell32.lib

In Visual Studio there is rectangular button "Debug" next to x64. 
Make sure you complete all of these steps in both Debbug mode AND Release mode. Yes, you gotta do it all twice.

Before we save this as a template we can make sure it works by running the main.cpp file i provided. 
Place the glew32.dll in the folder created by Visual Studio

Lastly make sure your cpp file is in your Solution Explorer > Source Files. If not, 
right click your project in Solution Explorer > Add > Add Existing (if you already have your cpp file ready) or Add New (if you are making a cpp file for the first time).
And boom there u go. Press the run button and a window should pop up and Success should appear in the Out log.

If everything works, then u can save your project template by doing Project > Export Template > click through some stuff until you name yr project
Now whenever u want to create a shader project with OpenGL u can select this template. 


