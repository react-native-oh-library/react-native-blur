
/**
 * MIT License
 *
 * Copyright (C) 2021 Huawei Device Co., Ltd.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANT KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#pragma once

#include <jsi/jsi.h>
#include <react/renderer/components/view/ViewProps.h>
#include <react/renderer/core/PropsParserContext.h>

namespace facebook
{
  namespace react
  {
    enum class HarmonyBlurViewBlurType {
        Dark,
        Light,
        ThickMaterialDark,
        ThinMaterialDark,
        ThickMaterialLight,
        ThinMaterialLight
    };


    static inline void fromRawValue(const PropsParserContext &context, const RawValue &value,
                                    HarmonyBlurViewBlurType &result) {
        auto string = (std::string)value;
        if (string == "dark") {
            result = HarmonyBlurViewBlurType::Dark;
            return;
        }
        if (string == "light") {
            result = HarmonyBlurViewBlurType::Light;
            return;
        }
        if (string == "thickMaterialDark") {
            result = HarmonyBlurViewBlurType::ThickMaterialDark;
            return;
        }
        if (string == "thinMaterialDark") {
            result = HarmonyBlurViewBlurType::ThinMaterialDark;
            return;
        }
        if (string == "thickMaterialLight") {
            result = HarmonyBlurViewBlurType::ThickMaterialLight;
            return;
        }
        if (string == "thinMaterialLight") {
            result = HarmonyBlurViewBlurType::ThinMaterialLight;
            return;
        }
        abort();
    }

    static inline std::string toString(const HarmonyBlurViewBlurType &value) {
        switch (value) {
        case HarmonyBlurViewBlurType::Dark:
            return "dark";
        case HarmonyBlurViewBlurType::Light:
            return "light";
        case HarmonyBlurViewBlurType::ThickMaterialDark:
            return "thickMaterialDark";
        case HarmonyBlurViewBlurType::ThinMaterialDark:
            return "thinMaterialDark";
        case HarmonyBlurViewBlurType::ThickMaterialLight:
            return "thickMaterialLight";
        case HarmonyBlurViewBlurType::ThinMaterialLight:
            return "thinMaterialLight";
        }
    }

    class JSI_EXPORT BlurViewProps final : public ViewProps
    {
    public:
      BlurViewProps() = default;
      BlurViewProps(const PropsParserContext &context, const BlurViewProps &sourceProps, const RawProps &rawProps);

#pragma mark - Props
      HarmonyBlurViewBlurType blurType{HarmonyBlurViewBlurType::Dark};
      int blurAmount{10};
    };

  } // namespace react
} // namespace facebook
