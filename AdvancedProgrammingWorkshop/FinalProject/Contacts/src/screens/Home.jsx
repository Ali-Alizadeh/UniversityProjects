import React, { Component } from 'react'
import { View, Text, FlatList, TouchableNativeFeedback, ActivityIndicator } from 'react-native'
import { TopAppBar, AppBarText, Icon } from './components/Lib'
import NewContactFAB from './home/NewContactFAB'
import ContactsListItem from './home/ContactsListItem'
import db from './common/db'
import Colors from './common/Colors'
import AsyncStorage from '@react-native-community/async-storage';


export default class Home extends Component {
  constructor(props) {
    super(props)
    this.state = {
      contacts: null,
      mBottom: -100
    }
  }

  async componentWillMount() {
    // this is only for test
    // AsyncStorage.clear()
    const res = await db.getContacts()
    // alert(JSON.stringify(res))
    // alert(typeof res)
    if (res == '')
      for (let i = 1; i <= 20; i++)
        await db.addNewContact('ali', 'alizadeh ' + i, '78645312')

    // TODO: sort the list alphabetically
    this.setState({ contacts: await db.getContacts() })
  }

  renderItem = ({ item, index }) => <ContactsListItem item={item} onPress={() => this.props.navigation.navigate('Contact', { contact: item })} />

  keyExtractor = (item, index) => String(index)

  _addNewContact = () => {

  }

  _deleteContact() {

  }

  render() {
    const { contacts, mBottom } = this.state;

    return (
      <View style={{ flex: 1 }}>
        <TopAppBar>
          <AppBarText>Contacts</AppBarText>
          <View
            style={{
              position: 'absolute',
              right: 0,
            }}
          >
            <Icon
              name="info"
              color={Colors.onPrimary}
              ripple
            />
          </View>
        </TopAppBar>

        {
          this.state.contacts == null
            ? (
              <View style={{ flex: 1, justifyContent: 'center', alignItems: 'center' }}>
                <ActivityIndicator size="large" color={Colors.secondary} />
              </View>
            )
            : (
              <FlatList
                data={contacts}
                renderItem={this.renderItem}
                keyExtractor={this.keyExtractor}
              />
            )
        }

        <NewContactFAB onPress={this._addNewContact()} />
        <View style={{ backgroundColor: 'tomato', width: 300, height: 100, marginBottom: mBottom }} />
      </View>
    )
  }
}
