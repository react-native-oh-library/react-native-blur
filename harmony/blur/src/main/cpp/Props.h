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

namespace facebook {
namespace react {
    
enum class BlurViewBlurType { Dark, Light, Xlight, Prominent, Regular, ExtraDark, ChromeMaterial, Material, ThickMaterial, ThinMaterial, UltraThinMaterial, ChromeMaterialDark, MaterialDark, ThickMaterialDark, ThinMaterialDark, UltraThinMaterialDark, ChromeMaterialLight, MaterialLight, ThickMaterialLight, ThinMaterialLight, UltraThinMaterialLight };

static inline void fromRawValue(const PropsParserContext& context, const RawValue &value, BlurViewBlurType &result) {
  auto string = (std::string)value;
  if (string == "dark") { result = BlurViewBlurType::Dark; return; }
  if (string == "light") { result = BlurViewBlurType::Light; return; }
  if (string == "xlight") { result = BlurViewBlurType::Xlight; return; }
  if (string == "prominent") { result = BlurViewBlurType::Prominent; return; }
  if (string == "regular") { result = BlurViewBlurType::Regular; return; }
  if (string == "extraDark") { result = BlurViewBlurType::ExtraDark; return; }
  if (string == "chromeMaterial") { result = BlurViewBlurType::ChromeMaterial; return; }
  if (string == "material") { result = BlurViewBlurType::Material; return; }
  if (string == "thickMaterial") { result = BlurViewBlurType::ThickMaterial; return; }
  if (string == "thinMaterial") { result = BlurViewBlurType::ThinMaterial; return; }
  if (string == "ultraThinMaterial") { result = BlurViewBlurType::UltraThinMaterial; return; }
  if (string == "chromeMaterialDark") { result = BlurViewBlurType::ChromeMaterialDark; return; }
  if (string == "materialDark") { result = BlurViewBlurType::MaterialDark; return; }
  if (string == "thickMaterialDark") { result = BlurViewBlurType::ThickMaterialDark; return; }
  if (string == "thinMaterialDark") { result = BlurViewBlurType::ThinMaterialDark; return; }
  if (string == "ultraThinMaterialDark") { result = BlurViewBlurType::UltraThinMaterialDark; return; }
  if (string == "chromeMaterialLight") { result = BlurViewBlurType::ChromeMaterialLight; return; }
  if (string == "materialLight") { result = BlurViewBlurType::MaterialLight; return; }
  if (string == "thickMaterialLight") { result = BlurViewBlurType::ThickMaterialLight; return; }
  if (string == "thinMaterialLight") { result = BlurViewBlurType::ThinMaterialLight; return; }
  if (string == "ultraThinMaterialLight") { result = BlurViewBlurType::UltraThinMaterialLight; return; }
  abort();
}

static inline std::string toString(const BlurViewBlurType &value) {
  switch (value) {
    case BlurViewBlurType::Dark: return "dark";
    case BlurViewBlurType::Light: return "light";
    case BlurViewBlurType::Xlight: return "xlight";
    case BlurViewBlurType::Prominent: return "prominent";
    case BlurViewBlurType::Regular: return "regular";
    case BlurViewBlurType::ExtraDark: return "extraDark";
    case BlurViewBlurType::ChromeMaterial: return "chromeMaterial";
    case BlurViewBlurType::Material: return "material";
    case BlurViewBlurType::ThickMaterial: return "thickMaterial";
    case BlurViewBlurType::ThinMaterial: return "thinMaterial";
    case BlurViewBlurType::UltraThinMaterial: return "ultraThinMaterial";
    case BlurViewBlurType::ChromeMaterialDark: return "chromeMaterialDark";
    case BlurViewBlurType::MaterialDark: return "materialDark";
    case BlurViewBlurType::ThickMaterialDark: return "thickMaterialDark";
    case BlurViewBlurType::ThinMaterialDark: return "thinMaterialDark";
    case BlurViewBlurType::UltraThinMaterialDark: return "ultraThinMaterialDark";
    case BlurViewBlurType::ChromeMaterialLight: return "chromeMaterialLight";
    case BlurViewBlurType::MaterialLight: return "materialLight";
    case BlurViewBlurType::ThickMaterialLight: return "thickMaterialLight";
    case BlurViewBlurType::ThinMaterialLight: return "thinMaterialLight";
    case BlurViewBlurType::UltraThinMaterialLight: return "ultraThinMaterialLight";
  }
}

    class JSI_EXPORT BlurViewProps final : public ViewProps
    {
    public:
      BlurViewProps() = default;
      BlurViewProps(const PropsParserContext &context, const BlurViewProps &sourceProps, const RawProps &rawProps);

#pragma mark - Props
      BlurViewBlurType blurType{BlurViewBlurType::Dark};
      int blurAmount{10};
    };

} // namespace react
} // namespace facebook
