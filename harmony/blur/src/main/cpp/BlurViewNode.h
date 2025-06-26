/**
 * Used only in C-API based Architecture.
 */
#pragma once
#include "Props.h"
#include "RNOH/arkui/ArkUINode.h"

namespace rnoh {
class BlurViewNode : public ArkUINode {
public:
    BlurViewNode();
    BlurViewNode &setBlurtype(facebook::react::BlurViewBlurType const &blurType, const int &blurAmount);
    void insertChild(ArkUINode &child, std::size_t index);
    void removeChild(ArkUINode &child);
};
} // namespace rnoh