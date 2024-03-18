import type { View } from 'react-native';

import BlurViewUntyped from './components/BlurView.harmony';
import VibrancyViewUntyped from './components/VibrancyView.harmony';

import type { BlurViewProps as BlurViewPropsIOS } from '@react-native-community/blur/src/components/BlurView.ios';
import type { BlurViewProps as BlurViewPropsAndroid } from '@react-native-community/blur/src/components/BlurView.android';
import type { BlurViewProps as BlurViewPropsHarmony } from './components/BlurView.harmony';
import type { VibrancyViewProps as VibrancyViewPropsIOS } from '@react-native-community/blur/src/components/VibrancyView.ios';

type BlurViewProps =
  | BlurViewPropsIOS
  | BlurViewPropsAndroid
  | BlurViewPropsHarmony;

type VibrancyViewProps = VibrancyViewPropsIOS;

const BlurView = BlurViewUntyped as React.ForwardRefExoticComponent<
  BlurViewProps & React.RefAttributes<View>
>;

const VibrancyView = VibrancyViewUntyped as unknown as React.ForwardRefExoticComponent<
  VibrancyViewProps & React.RefAttributes<View>
>;

export { BlurView, VibrancyView };
export type { BlurViewProps, VibrancyViewProps };
