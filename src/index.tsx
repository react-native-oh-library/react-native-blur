import BlurView from './components/BlurView.harmony';
import VibrancyView from './components/VibrancyView.harmony';

import type { BlurViewProps as BlurViewPropsIOS } from '@react-native-community/blur/src/components/BlurView.ios';
import type { BlurViewProps as BlurViewPropsAndroid } from '@react-native-community/blur/src/components/BlurView.android';
import type { BlurViewProps as BlurViewPropsHarmony } from './components/BlurView.harmony';
import type { VibrancyViewProps as VibrancyViewPropsIOS } from '@react-native-community/blur/src/components/VibrancyView.ios';

type BlurViewProps =
  | BlurViewPropsIOS
  | BlurViewPropsAndroid
  | BlurViewPropsHarmony;
type VibrancyViewProps = VibrancyViewPropsIOS;


export { BlurView, VibrancyView };
export type { BlurViewProps, VibrancyViewProps };
