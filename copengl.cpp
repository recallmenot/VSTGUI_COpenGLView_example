#include "copengl.h"

namespace VSTGUI {

	TestOpenGLView::TestOpenGLView(const CRect& size) : COpenGLView(size) {
		xRotation = yRotation = zRotation = 0.f;
	}

	bool TestOpenGLView::attached(CView* parent)
	{
		if (COpenGLView::attached(parent))
		{
			updateViewPort();
			remember();
			addAnimation("XRotation", this, new Animation::RepeatTimingFunction(new Animation::LinearTimingFunction(4000), -1, false));
			remember();
			addAnimation("YRotation", this, new Animation::RepeatTimingFunction(new Animation::LinearTimingFunction(6000), -1, false));
			remember();
			addAnimation("ZRotation", this, new Animation::RepeatTimingFunction(new Animation::LinearTimingFunction(8000), -1, false));
			return true;
		}
		return false;
	}

	bool TestOpenGLView::removed(CView* parent)
	{
		return COpenGLView::removed(parent);
	}

	void TestOpenGLView::setViewSize(const CRect& rect, bool invalid = true)
	{
		COpenGLView::setViewSize(rect, invalid);
		updateViewPort();
	}

	void TestOpenGLView::parentSizeChanged()
	{
		COpenGLView::parentSizeChanged();
		updateViewPort();
	}

	void TestOpenGLView::updateViewPort()
	{
		platformGLview = getPlatformOpenGLView();

		if (platformGLview)
		{
			platformGLview->lockContext();
			platformGLview->makeContextCurrent();

			glEnable(GL_DEPTH_TEST);
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

			CRect r(getViewSize());
			glViewport(0, 0, r.getWidth(), r.getHeight());

			glClearColor(0, 0, 0, 0);

			platformGLview->unlockContext();
		}
	}

	

	void TestOpenGLView::drawOpenGL(const CRect& updateRect)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		glScaled(0.5, 0.5, 0.2);
		glRotated(xRotation, 1, 0, 0);
		glRotated(yRotation, 0, 1, 0);
		glRotated(zRotation, 0, 0, 1);

		glBegin(GL_TRIANGLES);

		glColor4f(0.0f, 0.0f, 1.0f, 0.5f);
		glVertex3f(0.0f, 1.0f, 0.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);

		glColor4f(1.0f, 0.0f, 0.0f, 0.5f);
		glVertex3f(0.0f, 1.0f, 0.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, -1.0f);

		glColor4f(0.0f, 1.0f, 0.0f, 0.5f);
		glVertex3f(0.0f, 1.0f, 0.0f);
		glVertex3f(1.0f, -1.0f, -1.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f);

		glColor4f(1.0f, 1.0f, 0.0f, 0.5f);
		glVertex3f(0.0f, 1.0f, 0.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f);

		glEnd();

		glBegin(GL_QUADS);
		glColor4f(0.5f, 0.5f, 0.5f, 0.9f);
		glVertex3f(-1.f, -1.f, 1.f);
		glVertex3f(1.f, -1.f, 1.f);
		glVertex3f(1.f, -1.f, -1.f);
		glVertex3f(-1.f, -1.f, -1.f);
		glEnd();

		glFlush();

		if (platformGLview) {
			platformGLview->swapBuffers();
		}
	}

	void TestOpenGLView::animationStart(CView* view, IdStringPtr name) {}
	void TestOpenGLView::animationTick(CView* view, IdStringPtr name, float pos)
	{
		if (strcmp(name, "XRotation") == 0)
			xRotation = pos * 360.f;
		else if (strcmp(name, "ZRotation") == 0)
			zRotation = pos * 360.f;
		else if (strcmp(name, "YRotation") == 0)
			yRotation = pos * 360.f;
		invalid();
	}
	void TestOpenGLView::animationFinished(CView* view, IdStringPtr name, bool wasCanceled) {}

}
