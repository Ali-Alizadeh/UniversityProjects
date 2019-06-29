import React, { Component } from 'react'
import { StyleSheet, View, Text, TouchableNativeFeedback, ToastAndroid, BackHandler } from 'react-native'
import { TopAppBar, AppBarText, Icon, TextButton, Modal } from './components/Lib'
import Input from './components/Input'
import db from './common/db'
import Colors from './common/Colors'


export default class NewContact extends Component {
  constructor(props) {
    super(props)
    this.state = {
      editMode: this.props.navigation.getParam('editMode'),
      contact: this.props.navigation.getParam('contact'),

      contactFirstName: '',
      contactLastName: '',
      contactPhoneNumber: '',

      exitConfirmModal: false,
    }
  }

  componentWillMount() {
    if (this.state.contact) {
      const { firstName, lastName, phoneNumber } = this.state.contact
      this.setState({
        contactFirstName: firstName,
        contactLastName: lastName,
        contactPhoneNumber: String(phoneNumber),
      })
    }

    this.backHandler = BackHandler.addEventListener('hardwareBackPress', () => {
      const { editMode, contactFirstName, contactLastName, contactPhoneNumber } = this.state
      if (!editMode) {
        if (contactFirstName != '' || contactLastName != '' || contactPhoneNumber != '') {
          this.setState({ exitConfirmModal: true })
          return true
        }
      } else if (editMode) {
        const { firstName, lastName, phoneNumber } = this.state.contact
        if (contactFirstName != firstName || contactLastName != lastName || contactPhoneNumber != phoneNumber) {
          this.setState({ exitConfirmModal: true })
          return true
        }
      }
      this.setState({ exitConfirmModal: false })
      return false
    })
  }

  componentWillUnmount() {
    this.backHandler.remove()
  }

  _closeButton = () => {
    const { editMode, contactFirstName, contactLastName, contactPhoneNumber } = this.state
    if (!editMode) {
      if (contactFirstName != '' || contactLastName != '' || contactPhoneNumber != '')
        this.setState({ exitConfirmModal: true })
      else
        this.props.navigation.goBack()
    } else if (editMode) {
      const { firstName, lastName, phoneNumber } = this.state.contact
      if (contactFirstName != firstName || contactLastName != lastName || contactPhoneNumber != phoneNumber)
        this.setState({ exitConfirmModal: true })
      else
        this.props.navigation.goBack()
    }
  }

  createNewContact = async () => {
    const { contactFirstName, contactLastName, contactPhoneNumber } = this.state
    try {
      await db.addNewContact(contactFirstName, contactLastName, contactPhoneNumber)
      this.props.navigation.state.params.refresh()
      this.props.navigation.goBack()
    } catch (err) {
      if (err == 'nameIsEmpty') {
        ToastAndroid.show('First name can\'t be empty!', ToastAndroid.SHORT)
      } else if (err == 'phoneNumberIsEmpty') {
        ToastAndroid.show('Phone number can\'t be empty!', ToastAndroid.SHORT)
      }
    }
  }

  editContact = async () => {
    const { contactFirstName, contactLastName, contactPhoneNumber, contact: { id } } = this.state
    try {
      await db.editContactById(contactFirstName, contactLastName, contactPhoneNumber, id)
      this.props.navigation.state.params.refresh()
      this.props.navigation.goBack()
    } catch (err) {
      if (err == 'nameIsEmpty') {
        ToastAndroid.show('First name can\'t be empty!', ToastAndroid.SHORT)
      } else if (err == 'phoneNumberIsEmpty') {
        ToastAndroid.show('Phone number can\'t be empty!', ToastAndroid.SHORT)
      }
    }
  }

  _saveInfo = () => {
    if (this.state.exitConfirmModal)
      this.setState({ exitConfirmModal: false })
    if (this.state.editMode) {
      this.editContact()
    } else {
      this.createNewContact()
    }
  }

  render() {
    return (
      <View style={{ flex: 1 }}>
        <TopAppBar>
          <Icon
            name="close"
            color={Colors.onPrimary}
            ripple
            style={{ marginLeft: 4 }}
            onPress={this._closeButton}
          />
          <AppBarText>{this.state.editMode ? 'Edit contact' : 'Create contact'}</AppBarText>
          <View
            style={{
              position: 'absolute',
              right: 0,
              paddingTop: 24,
            }}
          >
            <TouchableNativeFeedback
              background={TouchableNativeFeedback.Ripple('rgba(255, 255, 255, 0.6)', true)}
              onPress={this._saveInfo}
            >
              <View style={{ width: 48, height: 48, marginRight: 4, alignItems: 'center', justifyContent: 'center' }}>
                <Text style={{ color: Colors.onPrimary }}>Save</Text>
              </View>
            </TouchableNativeFeedback>
          </View>
        </TopAppBar>
        <View style={{ flex: 1 }}>
          <View style={styles.inputContainer}>
            <Icon name="person" style={{ marginRight: 16 }} color={Colors.onBackground} />
            <Input
              placeholder="First name"
              defaultValue={this.state.contactFirstName}
              onChangeText={text => this.setState({ contactFirstName: text })}
              autoCapitalize="words"
              style={{ flex: 1 }}
            />
          </View>
          <View style={styles.inputContainer}>
            <Icon name="call" style={{ marginRight: 16 }} color={Colors.background} />
            <Input
              placeholder="Last name"
              defaultValue={this.state.contactLastName}
              onChangeText={text => this.setState({ contactLastName: text })}
              autoCapitalize="words"
              style={{ flex: 1 }}
            />
          </View>
          <View style={styles.inputContainer}>
            <Icon name="call" style={{ marginRight: 16 }} color={Colors.onBackground} />
            <Input
              placeholder="Phone number"
              defaultValue={this.state.contactPhoneNumber}
              onChangeText={text => this.setState({ contactPhoneNumber: text })}
              autoCapitalize="words"
              style={{ flex: 1 }}
              keyboardType="numeric"
            />
          </View>
        </View>
        <Modal
          visible={this.state.exitConfirmModal}
          onRequestClose={() => this.setState({ exitConfirmModal: false })}
        >
          <View>
            <Text style={{ padding: 16 }}>Your changes have not been saved</Text>
            <View style={{ flexDirection: 'row', justifyContent: 'flex-end', padding: 8, paddingTop: 0 }}>
              <TextButton
                label='Discard'
                onPress={() => {
                  this.setState({ exitConfirmModal: false })
                  this.props.navigation.goBack()
                }}
              />
              <TextButton
                label='Save'
                onPress={this._saveInfo}
              />
            </View>
          </View>
        </Modal>
      </View>
    )
  }
}

const styles = StyleSheet.create({
  inputContainer: {
    flexDirection: 'row',
    alignItems: 'center',
    margin: 16,
    marginBottom: 0,
  },
})
