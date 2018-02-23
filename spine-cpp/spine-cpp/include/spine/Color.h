/******************************************************************************
 * Spine Runtimes Software License v2.5
 *
 * Copyright (c) 2013-2016, Esoteric Software
 * All rights reserved.
 *
 * You are granted a perpetual, non-exclusive, non-sublicensable, and
 * non-transferable license to use, install, execute, and perform the Spine
 * Runtimes software and derivative works solely for personal or internal
 * use. Without the written permission of Esoteric Software (see Section 2 of
 * the Spine Software License Agreement), you may not (a) modify, translate,
 * adapt, or develop new applications using the Spine Runtimes or otherwise
 * create derivative works or improvements of the Spine Runtimes or (b) remove,
 * delete, alter, or obscure any trademarks or any copyright, trademark, patent,
 * or other intellectual property or proprietary rights notices on or in the
 * Software, including any copy thereof. Redistributions in binary or source
 * form must include this license and terms.
 *
 * THIS SOFTWARE IS PROVIDED BY ESOTERIC SOFTWARE "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 * EVENT SHALL ESOTERIC SOFTWARE BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES, BUSINESS INTERRUPTION, OR LOSS OF
 * USE, DATA, OR PROFITS) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
 * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *****************************************************************************/
#ifndef SPINE_COLOR_H
#define SPINE_COLOR_H

#include <spine/MathUtil.h>

namespace Spine {
	class Color : public SpineObject {
	public:
		Color() : _r(0), _g(0), _b(0), _a(0) {
		}

		Color(float r, float g, float b, float a) : _r(r), _g(g), _b(b), _a(a) {
			clamp();
		}

		inline Color& set(float r, float g, float b, float a) {
			_r = r;
			_g = g;
			_b = b;
			_a = a;
			clamp();
			return *this;
		}

		inline Color& set(const Color& other) {
			_r = other._r;
			_g = other._g;
			_b = other._b;
			_a = other._a;
			clamp();
			return *this;
		}

		inline Color& add(float r, float g, float b, float a) {
			_r += r;
			_g += g;
			_b += b;
			_a += a;
			clamp();
			return *this;
		}

		inline Color& add(const Color& other) {
			_r += other._r;
			_g += other._g;
			_b += other._b;
			_a += other._a;
			clamp();
			return *this;
		}

		inline Color& clamp() {
			_r = MathUtil::clamp(this->_r, 0, 1);
			_g = MathUtil::clamp(this->_g, 0, 1);
			_b = MathUtil::clamp(this->_b, 0, 1);
			_a = MathUtil::clamp(this->_a, 0, 1);
			return *this;
		}

		float _r, _g, _b, _a;

		inline String toString() const {
			String str;
			str.append("Color { r: ").append(_r).append(", g: ").append(_g).append(", b: ").append(_b).append(", a: ").append(_a).append(" }");
			return str;
		}
	};
}


#endif //SPINE_COLOR_H
