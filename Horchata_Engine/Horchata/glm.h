// OpenGL Mathematics Copyright (c) 2005 - 2011 G-Truc Creation (www.g-truc.net)
// Created : 2005-01-14
// Updated : 2011-01-19
// Licence : This source is under MIT License
// File    : glm/glm.hpp

#include "core/_fixes.hpp"

#ifndef glm_glm
#define glm_glm

#include <cmath>
#include <climits>
#include <cfloat>
#include <limits>
#include "core/setup.hpp"

#if(defined(GLM_MESSAGES) && !defined(GLM_MESSAGE_CORE_INCLUDED_DISPLAYED))
#       define GLM_MESSAGE_CORE_INCLUDED_DISPLAYED
#       pragma message("GLM: Core library included")
#endif//GLM_MESSAGE

namespace glm
{
	namespace test
		{
		        bool main_bug();
		        bool main_core();
		}//namespace test

		namespace core
		{
		        namespace type {}

			        namespace function {}
		}
	//namespace core
	
		namespace gtc {}

		namespace gtx {}

		namespace img {}

} //namespace glm

#include "./core/_detail.hpp"
#include "./core/type.hpp"

#include "./core/func_trigonometric.hpp"
#include "./core/func_exponential.hpp"
#include "./core/func_common.hpp"
#include "./core/func_packing.hpp"
#include "./core/func_geometric.hpp"
#include "./core/func_matrix.hpp"
#include "./core/func_vector_relational.hpp"
#include "./core/func_integer.hpp"
#include "./core/func_noise.hpp"
#include "./core/_swizzle.hpp"

namespace glm
{
	    using namespace core::type;
	    using namespace core::type::precision;
	    using namespace core::function;
} //namespace glm

// check type sizes
#ifndef GLM_STATIC_ASSERT_NULL
        GLM_STATIC_ASSERT(sizeof(glm::detail::int8) == 1, "int8 size isn't 1 byte on this platform");
        GLM_STATIC_ASSERT(sizeof(glm::detail::int16) == 2, "int16 size isn't 2 bytes on this platform");
        GLM_STATIC_ASSERT(sizeof(glm::detail::int32) == 4, "int32 size isn't 4 bytes on this platform");
        GLM_STATIC_ASSERT(sizeof(glm::detail::int64) == 8, "int64 size isn't 8 bytes on this platform");

        GLM_STATIC_ASSERT(sizeof(glm::detail::uint8) == 1, "uint8 size isn't 1 byte on this platform");
        GLM_STATIC_ASSERT(sizeof(glm::detail::uint16) == 2, "uint16 size isn't 2 bytes on this platform");
        GLM_STATIC_ASSERT(sizeof(glm::detail::uint32) == 4, "uint32 size isn't 4 bytes on this platform");
        GLM_STATIC_ASSERT(sizeof(glm::detail::uint64) == 8, "uint64 size isn't 8 bytes on this platform");

        GLM_STATIC_ASSERT(sizeof(glm::detail::float16) == 2, "float16 size isn't 2 bytes on this platform");
        GLM_STATIC_ASSERT(sizeof(glm::detail::float32) == 4, "float32 size isn't 4 bytes on this platform");
        GLM_STATIC_ASSERT(sizeof(glm::detail::float64) == 8, "float64 size isn't 8 bytes on this platform");
#endif//GLM_STATIC_ASSERT_NULL

#endif //glm_glm