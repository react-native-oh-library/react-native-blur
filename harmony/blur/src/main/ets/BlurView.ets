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
} from 'rnoh'
import Logger from './Logger'

export const BLUR_TYPE: string = "HarmonyBlurView"
const TAG: string = "[RNOH] HarmonyBlurView"

export interface BlurProps extends ViewBaseProps {
  blurType:string
  blurAmount:number
}
export type BlurDescriptor = Descriptor<"HarmonyBlurView", BlurProps>
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
    Logger.debug(TAG, `props ${JSON.stringify(this.descriptor.props)}`)
  }

  aboutToDisappear() {
    this.unregisterDescriptorChangesListener?.()
  }

  getColorMode(blurType:string):ThemeColorMode {
    if (blurType.toLowerCase().endsWith('light')){
      return ThemeColorMode.LIGHT
    }
    return ThemeColorMode.DARK
  }

  getBlurType(blurType:string):BlurStyle {
    if (blurType.toLowerCase().includes('thin')){
      return BlurStyle.Thin
    } else if(blurType.toLowerCase().includes('thick')){
      return BlurStyle.Thick
    }
    return BlurStyle.Regular
  }

  build() {
    RNViewBase({ ctx: this.ctx, tag: this.tag }) {
      Column()
        .width('100%')
        .height('100%')
        .foregroundBlurStyle(this.getBlurType(this.descriptor.props.blurType),
          { colorMode: this.getColorMode(this.descriptor.props.blurType),
            adaptiveColor: AdaptiveColor.DEFAULT,
            scale: this.descriptor.props.blurAmount / 100 })
    }
  }
}
