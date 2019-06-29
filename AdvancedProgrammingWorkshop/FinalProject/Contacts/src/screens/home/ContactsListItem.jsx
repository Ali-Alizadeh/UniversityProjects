import React from 'react'
import { View, Text, TouchableNativeFeedback } from 'react-native'
import Colors from '../common/Colors'

const colors = ['#F44336', '#e91e63', '#9c27b0', '#673ab7', '#3f51b5', '#2196f3', '#03a9f4', '#009688', '#ff9800', '#ff5722', '#795548', '#607d8b']

const getBackgroundColor = (item) => {
  let total = 0
  let str = item.firstName + item.lastName + item.phoneNumber
  for (let i = 0; i < str.length; i++) {
    total += str.charCodeAt(i)
  }
  return colors[total % colors.length]
}

const ContactsListItem = ({ item, onPress, style }) => (
  <TouchableNativeFeedback onPress={onPress}>
    <View
      style={[
        {
          flexDirection: 'row',
          alignItems: 'center',
          padding: 8,
          paddingLeft: 16,
        },
        style,
      ]}
    >
      <View
        style={{
          width: 48,
          height: 48,
          justifyContent: 'center',
          alignItems: 'center',
          backgroundColor: getBackgroundColor(item),
          borderRadius: 28,
        }}
      >
        <Text style={{ fontSize: 24, lineHeight: 32, color: '#fff' }}>{item.firstName[0].toUpperCase()}</Text>
      </View>
      <Text
        style={{
          fontSize: 16,
          letterSpacing: 0.5,
          fontWeight: 'normal',
          color: Colors.onBackground,
          paddingLeft: 16,
        }}
      >
        {`${item.firstName} ${item.lastName}`}
      </Text>
    </View>
  </TouchableNativeFeedback>
)

export default ContactsListItem;
