<h1>Sakura Project</h1>
A WIP custom 2D game engine / graphics framework built from scratch using Modern C++ and OpenGL.

<h2>Technical Dependencies</h2>
<ul>
  <li>Language: C++23</li>
  <li>Graphics API: OpenGL 3.3 (Core Profile)</li>
  <li>Build System: Modern CMake (Out-of-source build)</li>
  <li>Dependencies: GLFW, GLAD</li>
  <li>Tools: Visual Studio 2022</li>
</ul>

<h2>How to build</h2>
<p>This project uses Git Submodules (vcpkg) to manage dependencies.</p>
<ol>
  <li>
    <strong>Clone the repository:</strong><br>
    If you are using the command line, use the <code>--recursive</code> flag:<br>
    <code>git clone --recursive https://github.com/takumi-shibamoto/SakuraProject.git</code><br>
    <small><em>(GitHub Desktop downloads submodules automatically.)</em></small>
  </li>
  <li>
    <strong>Generate the Visual Studio solution:</strong><br>
    Run <code>setup.bat</code>. This will automatically set up vcpkg, download dependencies, and create the build files.
  </li>
  <li>
    <strong>Build and run:</strong><br>
    Open <code>build/SakuraProject.sln</code> in Visual Studio and run!
  </li>
</ol>
