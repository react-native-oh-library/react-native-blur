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
import {
  Descriptor,
  ComponentBuilderContext,
  RNOHContext,
  RNViewBase,
  ViewBaseProps,
  ViewRawProps,
} from '@rnoh/react-native-openharmony'
import Logger from './Logger'

export const BLUR_TYPE: string = "BlurView"

const TAG: string = "[RNOH] BlurView"

export interface BlurViewState {}

export interface BlurRawProps extends ViewRawProps {
  blurType: string
  blurAmount: number
}

const colorModelTypes: Map<string, BlurStyle> = new Map([
  ['dark', BlurStyle.BACKGROUND_THICK],
  ['light', BlurStyle.COMPONENT_THIN],
  ['thickMaterialDark', BlurStyle.Thick],
  ['thinMaterialDark', BlurStyle.Thin],
  ['thickMaterialLight', BlurStyle.Thick],
  ['thinMaterialLight', BlurStyle.Thin],
  ['xlight', BlurStyle.COMPONENT_THICK],
  ['extraDark', BlurStyle.COMPONENT_THICK],
  ['regular', BlurStyle.Regular],
  ['ultraThinMaterialDark', BlurStyle.COMPONENT_ULTRA_THIN],
  ['ultraThinMaterialLight', BlurStyle.COMPONENT_ULTRA_THIN],
  ['chromeMaterialDark', BlurStyle.COMPONENT_ULTRA_THICK],
  ['materialDark', BlurStyle.COMPONENT_REGULAR],
  ['materialLight', BlurStyle.COMPONENT_REGULAR],
  ['chromeMaterialLight', BlurStyle.COMPONENT_ULTRA_THICK],
  ['prominent', BlurStyle.Thick],
  ['chromeMaterial', BlurStyle.COMPONENT_ULTRA_THICK],
  ['material', BlurStyle.COMPONENT_ULTRA_THICK],
  ['thickMaterial', BlurStyle.COMPONENT_THICK],
  ['thinMaterial', BlurStyle.COMPONENT_THIN],
  ['ultraThinMaterial', BlurStyle.COMPONENT_ULTRA_THIN],
]);



export type BlurDescriptor = Descriptor<"BlurView", ViewBaseProps, BlurViewState, BlurRawProps>

@Component
export struct BlurView {
  ctx!: RNOHContext
  tag: number = 0
  @BuilderParam buildCustomComponent: (componentBuilderContext: ComponentBuilderContext) => void
  @State descriptor: BlurDescriptor = {} as BlurDescriptor
  private unregisterDescriptorChangesListener?: () => void = undefined

  aboutToAppear() {
    this.descriptor = this.ctx.descriptorRegistry.getDescriptor<BlurDescriptor>(this.tag)
    this.unregisterDescriptorChangesListener = this.ctx.descriptorRegistry.subscribeToDescriptorChanges(this.tag,
      (newDescriptor) => {
        this.descriptor = (newDescriptor as BlurDescriptor)
      }
    )
    Logger.debug(TAG, `props ${JSON.stringify(this.descriptor.rawProps)} ${this.descriptor.rawProps.blurType}`)
  }

  aboutToDisappear() {
    this.unregisterDescriptorChangesListener?.()
  }

  getColorMode(blurType: string): ThemeColorMode {
    if (blurType.toLowerCase().endsWith('light')) {
      return ThemeColorMode.LIGHT
    }
    if (blurType.toLowerCase().endsWith('dark')) {
      return ThemeColorMode.DARK
    }
    return ThemeColorMode.SYSTEM
  }


  getBlurType(blurType: string): BlurStyle {
    return colorModelTypes.get(blurType) ?? BlurStyle.BACKGROUND_THICK
  }

  build() {
    RNViewBase({ ctx: this.ctx, tag: this.tag }) {
      Column()
        .width('100%')
        .height('100%')
        .foregroundBlurStyle(this.getBlurType(this.descriptor.rawProps.blurType),
        {
          colorMode: this.getColorMode(this.descriptor.rawProps.blurType),
          adaptiveColor: AdaptiveColor.DEFAULT,
          scale: this.descriptor.rawProps.blurAmount / 100
        })
    }
  }
}
