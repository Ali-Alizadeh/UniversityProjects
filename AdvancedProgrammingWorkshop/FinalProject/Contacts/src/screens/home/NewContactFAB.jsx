import React from 'react';
import { View, TouchableNativeFeedback } from 'react-native';
import Icon from 'react-native-vector-icons/MaterialIcons';
import Colors from '../common/Colors';


const NewContactFAB = ({ onPress }) => (
  <View
    style={{
      position: 'absolute',
      bottom: 16,
      right: 16,
      height: 56,
      width: 56,
      borderRadius: 28,
      elevation: 6,
      zIndex: 100,
    }}
  >
    <TouchableNativeFeedback
      onPress={onPress}
      background={TouchableNativeFeedback.Ripple('rgba(0, 0, 0, 0.4)', true)}
    >
      <View
        style={{
          height: 56,
          width: 56,
          backgroundColor: Colors.secondary,
          justifyContent: 'center',
          alignItems: 'center',
          borderRadius: 28,
          zIndex: 100,
        }}
      >
        <Icon
          name="person-add"
          size={24}
          color="#fff"
        />
      </View>
    </TouchableNativeFeedback>
  </View>
)

export default NewContactFAB;
