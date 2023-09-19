#pragma once

// factory for TestOpenGLView
// https://steinbergmedia.github.io/vst3_doc/vstgui/html/create_your_own_view.html

#include "vstgui/vstgui.h"
#include "vstgui/vstgui_uidescription.h"
#include "vstgui/uidescription/detail/uiviewcreatorattributes.h"

#include "copengl.h"

#define TestOpenGLView_default_w 200
#define TestOpenGLView_default_h 200


namespace VSTGUI {
	class TestOpenGLViewFactory : public ViewCreatorAdapter
	{
	public:
		TestOpenGLViewFactory()
		{
			// register in view factory
			UIViewFactory::registerViewCreator(*this);
		}
		IdStringPtr getViewName() const override
		{
			// provide display name
			return "TestOpenGLView";
		}
		IdStringPtr getBaseViewName() const override
		{
			// provide parent class
			return UIViewCreator::kCView;
		}
		CView* create(const UIAttributes& attributes, const IUIDescription* description) const override
		{
			// set default size
			CRect size(CPoint(45, 45), CPoint(TestOpenGLView_default_w, TestOpenGLView_default_h));
			// return new instance
			return new TestOpenGLView(size);
		}

	};

	// create a static factory instance so that it registers itself with the view factory
	TestOpenGLViewFactory __gRegisterTestOpenGLViewFactory;

} // namespace VSTGUI
