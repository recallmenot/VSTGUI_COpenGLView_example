This is an example for the Steinberg VST3SDK VSTGUI librarys COpenGLView object.

Note: since Apples deprecation of their own OpenGL library to enforce adoption of Metal, development on the COpenGLView has ceased.
It has been implemented for Windows, mac os and iOS.

Created with the [generous help](https://forums.steinberg.net/t/vstgui4-and-pure-opengl-editor/201982/10) of @scheffle.

It is a nice addition to the [tutorial on subclassing views to create your own](https://steinbergmedia.github.io/vst3_doc/vstgui/html/create_your_own_view.html).

## usage
 * with a new VST3SDK project, paste these files in your sources dir
 * insert them into your build project (solution in VS)
 * build
 * load the VST (on Windows, built VSTs are symlinked to `%LOCALAPPDATA%\Programs\Common\VST3`)
 * open the VSTGUI editor
 * add the TestOpenGLView
 * save
 * close the VSTGUI editor
 * ??
 * profit!
