#pragma once

// https://forums.steinberg.net/t/vstgui4-and-pure-opengl-editor/201982/10
/*
#include <windows.h>
#include <GL/GL.h>

#pragma comment (lib, "opengl32.lib")
#pragma comment (lib,"glu32.lib")

#include <vstgui4/vstgui/lib/copenglview.h>

//#include <vstgui4/vstgui/lib/animation/animations.h>
#include <vstgui4/vstgui/lib/animation/ianimationtarget.h>
#include <vstgui4/vstgui/lib/animation/timingfunctions.h>
*/

#include "vstgui/vstgui.h"

#include <windows.h>
#include <GL/GL.h>

#pragma comment (lib, "opengl32.lib")
#pragma comment (lib,"glu32.lib")

namespace VSTGUI {

	class TestOpenGLView : public COpenGLView, public Animation::IAnimationTarget
	{
	public:

		TestOpenGLView(const CRect& size);

		bool attached(CView* parent) override;
		bool removed(CView* parent) override;

		void setViewSize(const CRect& rect, bool invalid) override;
		void parentSizeChanged() override;

		void updateViewPort();

		void drawOpenGL(const CRect& updateRect);

	protected:
		virtual void animationStart(CView* view, IdStringPtr name);
		virtual void animationTick(CView* view, IdStringPtr name, float pos);
		virtual void animationFinished(CView* view, IdStringPtr name, bool wasCanceled);

		float xRotation;
		float yRotation;
		float zRotation;

		VSTGUI::IPlatformOpenGLView* platformGLview;
	};

}
