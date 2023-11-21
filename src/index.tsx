import BlurViewUntyped from './components/BlurView';
import type { View } from 'react-native';

import type { BlurViewProps } from './components/BlurView';

const BlurView = BlurViewUntyped as React.ForwardRefExoticComponent<
  BlurViewProps & React.RefAttributes<View>
>;

export { BlurView };
export type { BlurViewProps };
