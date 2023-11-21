
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
    enum class BlurType {
        Dark,
        Light,
        Xlight,
        Prominent,
        Regular,
        ExtraDark,
        ChromeMaterial,
        Material,
        ThickMaterial,
        ThinMaterial,
        UltraThinMaterial,
        ChromeMaterialDark,
        MaterialDark,
        ThickMaterialDark,
        ThinMaterialDark,
        UltraThinMaterialDark,
        ChromeMaterialLight,
        MaterialLight,
        ThickMaterialLight,
        ThinMaterialLight,
        UltraThinMaterialLight
    };

    static inline void fromRawValue(const PropsParserContext &context, const RawValue &value,
                                    BlurType &result) {
        auto string = (std::string)value;
        if (string == "dark") {
            result = BlurType::Dark;
            return;
        }
        if (string == "light") {
            result = BlurType::Light;
            return;
        }
        if (string == "xlight") {
            result = BlurType::Xlight;
            return;
        }
        if (string == "prominent") {
            result = BlurType::Prominent;
            return;
        }
        if (string == "regular") {
            result = BlurType::Regular;
            return;
        }
        if (string == "extraDark") {
            result = BlurType::ExtraDark;
            return;
        }
        if (string == "chromeMaterial") {
            result = BlurType::ChromeMaterial;
            return;
        }
        if (string == "material") {
            result = BlurType::Material;
            return;
        }
        if (string == "thickMaterial") {
            result = BlurType::ThickMaterial;
            return;
        }
        if (string == "thinMaterial") {
            result = BlurType::ThinMaterial;
            return;
        }
        if (string == "ultraThinMaterial") {
            result = BlurType::UltraThinMaterial;
            return;
        }
        if (string == "chromeMaterialDark") {
            result = BlurType::ChromeMaterialDark;
            return;
        }
        if (string == "materialDark") {
            result = BlurType::MaterialDark;
            return;
        }
        if (string == "thickMaterialDark") {
            result = BlurType::ThickMaterialDark;
            return;
        }
        if (string == "thinMaterialDark") {
            result = BlurType::ThinMaterialDark;
            return;
        }
        if (string == "ultraThinMaterialDark") {
            result = BlurType::UltraThinMaterialDark;
            return;
        }
        if (string == "chromeMaterialLight") {
            result = BlurType::ChromeMaterialLight;
            return;
        }
        if (string == "materialLight") {
            result = BlurType::MaterialLight;
            return;
        }
        if (string == "thickMaterialLight") {
            result = BlurType::ThickMaterialLight;
            return;
        }
        if (string == "thinMaterialLight") {
            result = BlurType::ThinMaterialLight;
            return;
        }
        if (string == "ultraThinMaterialLight") {
            result = BlurType::UltraThinMaterialLight;
            return;
        }
        abort();
    }

    static inline std::string toString(const BlurType &value) {
        switch (value) {
        case BlurType::Dark:
            return "dark";
        case BlurType::Light:
            return "light";
        case BlurType::Xlight:
            return "xlight";
        case BlurType::Prominent:
            return "prominent";
        case BlurType::Regular:
            return "regular";
        case BlurType::ExtraDark:
            return "extraDark";
        case BlurType::ChromeMaterial:
            return "chromeMaterial";
        case BlurType::Material:
            return "material";
        case BlurType::ThickMaterial:
            return "thickMaterial";
        case BlurType::ThinMaterial:
            return "thinMaterial";
        case BlurType::UltraThinMaterial:
            return "ultraThinMaterial";
        case BlurType::ChromeMaterialDark:
            return "chromeMaterialDark";
        case BlurType::MaterialDark:
            return "materialDark";
        case BlurType::ThickMaterialDark:
            return "thickMaterialDark";
        case BlurType::ThinMaterialDark:
            return "thinMaterialDark";
        case BlurType::UltraThinMaterialDark:
            return "ultraThinMaterialDark";
        case BlurType::ChromeMaterialLight:
            return "chromeMaterialLight";
        case BlurType::MaterialLight:
            return "materialLight";
        case BlurType::ThickMaterialLight:
            return "thickMaterialLight";
        case BlurType::ThinMaterialLight:
            return "thinMaterialLight";
        case BlurType::UltraThinMaterialLight:
            return "ultraThinMaterialLight";
        }
    }

    class JSI_EXPORT BlurViewProps final : public ViewProps
    {
    public:
      BlurViewProps() = default;
      BlurViewProps(const PropsParserContext &context, const BlurViewProps &sourceProps, const RawProps &rawProps);

#pragma mark - Props
      BlurType blurType{BlurType::Light};
      int blurAmount{10};
    };

  } // namespace react
} // namespace facebook
