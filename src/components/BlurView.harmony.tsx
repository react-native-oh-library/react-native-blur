import React, { forwardRef } from 'react';
import { StyleSheet, ViewProps, ViewStyle, View } from 'react-native';
import NativeBlurView from '../fabric/BlurViewNativeComponentHarmony';

type BlurType =
  | 'dark'
  | 'light'
  | 'thickMaterialDark'
  | 'thinMaterialDark'
  | 'thickMaterialLight'
  | 'thinMaterialLight';

export type BlurViewProps = ViewProps & {
  blurType?: BlurType;
  blurAmount?: number;
};

const BlurView = forwardRef<View, BlurViewProps>(
  ({ blurType = 'dark', blurAmount = 10, style, ...rest }, ref) => (
    <NativeBlurView
      ref={ref}
      style={StyleSheet.compose(styles.transparent, style)}
      blurType={blurType}
      blurAmount={blurAmount}
      {...rest}
    />
  )
);

const styles = StyleSheet.create<{ transparent: ViewStyle }>({
  transparent: { backgroundColor: 'transparent' },
});

export default BlurView;
