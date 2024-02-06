import codegenNativeComponent from 'react-native/Libraries/Utilities/codegenNativeComponent';
import type { ViewProps, HostComponent } from 'react-native';
import type {
  WithDefault,
  Int32,
} from 'react-native/Libraries/Types/CodegenTypes';

interface NativeProps extends ViewProps {
  blurType?: WithDefault<
    | 'dark'
    | 'light'
    | 'thickMaterialDark'
    | 'thinMaterialDark'
    | 'thickMaterialLight'
    | 'thinMaterialLight',
    'dark'
  >;
  blurAmount?: WithDefault<Int32, 10>;
}

export default codegenNativeComponent<NativeProps>('BlurView', {
  excludedPlatforms: ['android', 'iOS'],
}) as HostComponent<NativeProps>;
