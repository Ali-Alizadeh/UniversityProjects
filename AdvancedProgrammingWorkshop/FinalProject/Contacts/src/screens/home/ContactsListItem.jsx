import React from 'react'
import { View, Text, TouchableNativeFeedback } from 'react-native'
import { Icon } from '../components/Lib'
import Colors from '../common/Colors'

const ContactsListItem = ({ item, onPress }) => (
  <TouchableNativeFeedback onPress={onPress}>
    <View
      style={{
        flexDirection: 'row',
        alignItems: 'center',
        padding: 16,
        borderBottomWidth: 1,
        borderBottomColor: 'rgba(0, 0, 0, 0.1)',
      }}
    >
      <Icon name="person-outline" color={Colors.onBackground} />
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
