#pragma once

#include "renderable2d.h"

namespace gt3d {  namespace graphics {

	class Renderer2D
	{
		/** adds object to list of objects to be affect by shaders*/
	protected:
		virtual void submit(const Renderable2D* renderable) = 0;
		virtual void flush() = 0;

	};

}}