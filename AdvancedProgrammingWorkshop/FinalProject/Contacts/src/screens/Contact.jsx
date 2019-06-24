import React, { Component } from 'react'
import { View, Text, FlatList, TouchableNativeFeedback, ActivityIndicator } from 'react-native'
import { TopAppBar, AppBarText, Icon } from './components/Lib'
import NewContactFAB from './home/NewContactFAB'
import ContactsListItem from './home/ContactsListItem'
import db from './common/db'
import Colors from './common/Colors'
import AsyncStorage from '@react-native-community/async-storage';


export default class Contact extends Component {
  constructor(props) {
    super(props)
    this.state = {
      contact: this.props.navigation.getParam('contact'),
    }
  }

  render() {
    const { contact } = this.state

    return (
      <View style={{ flex: 1 }}>
        <TopAppBar>
          <AppBarText>{`${contact.firstName} info`}</AppBarText>
          <View
            style={{
              position: 'absolute',
              right: 0,
            }}
          >
            <Icon
              name="more-horiz"
              color={Colors.onPrimary}
              ripple
            />
          </View>
        </TopAppBar>
        <View style={{ flex: 1 }}>
          <Text>{contact.firstName}</Text>
          <Text>{contact.lastName}</Text>
          <Text>{contact.phoneNumber}</Text>
        </View>
      </View>
    )
  }
}
