import React, { Component } from 'react'
import {
  View,
  Text,
  StatusBar,
  FlatList,
  ActivityIndicator,
  TextInput,
  Modal,
  Animated,
  Easing,
  Dimensions,
  TouchableWithoutFeedback,
  ToastAndroid,
  I18nManager,
  Linking,
} from 'react-native'
import { AppBarText, Icon, TextButton } from './components/Lib'
import MyModal from './components/Modal'
import NewContactFAB from './home/NewContactFAB'
import ContactsListItem from './home/ContactsListItem'
import EmptyList from './home/EmptyList'
import db from './common/db'
import Colors from './common/Colors'

I18nManager.forceRTL(false)

const { width, height } = Dimensions.get('screen')

export default class Home extends Component {
  constructor(props) {
    super(props)
    this.state = {
      allContacts: null,
      shownContacts: null,
      modal: false,
      selectedContact: null,
      bottom: new Animated.Value(-height / 2),
      backgroundOpacity: new Animated.Value(0),
      modalBackgroundOpacity: new Animated.Value(0),

      deleteConfirmModal: false,
    }
  }

  async componentWillMount() {
    const contacts = await db.getContacts()
    for (let i = 0; i < contacts.length; i++) {
      for (let j = i + 1; j < contacts.length; j++) {
        if (contacts[i].firstName.toLowerCase() > contacts[j].firstName.toLowerCase()) {
          let temp = contacts[i];
          contacts[i] = contacts[j];
          contacts[j] = temp;
        } else if (contacts[i].firstName == contacts[j].firstName) {
          if (contacts[i].lastName.toLowerCase() > contacts[j].lastName.toLowerCase()) {
            let temp = contacts[i];
            contacts[i] = contacts[j];
            contacts[j] = temp;
          }
        }
      }
    }
    this.setState({
      shownContacts: contacts,
      allContacts: contacts,
    })
  }

  clearSearchTextInput = () => {
    this.textInput.clear()
  }

  showBottomDrawer = (contact) => {
    this.setState({
      selectedContact: contact,
      modal: true,
    })

    const showAnimationDuration = 300 // 250 or 300
    Animated.parallel([
      Animated.timing(this.state.bottom, {
        toValue: 0,
        duration: showAnimationDuration,
        easing: Easing.bezier(0.0, 0.0, 0.2, 1),
      }),
      Animated.timing(this.state.backgroundOpacity, {
        toValue: 1,
        duration: showAnimationDuration,
      }),
      Animated.timing(this.state.modalBackgroundOpacity, {
        toValue: 1,
        duration: showAnimationDuration,
      }),
    ]).start()
  }

  hideBottomDrawer = () => {
    const hideAnimationDuration = 250 // 200 or 250
    Animated.parallel([
      Animated.timing(this.state.bottom, {
        toValue: -height / 2,
        duration: hideAnimationDuration,
        easing: Easing.bezier(0.4, 0.0, 1, 1),
      }),
      Animated.timing(this.state.backgroundOpacity, {
        toValue: 0,
        duration: hideAnimationDuration,
      }),
      Animated.timing(this.state.modalBackgroundOpacity, {
        toValue: 0,
        duration: hideAnimationDuration,
      }),
    ]).start(() => {
      this.setState({ modal: false })
    })
  }

  _createNewContact = () => {
    this.props.navigation.navigate('NewContact', {
      editMode: false,
      refresh: () => {
        this.componentWillMount()
        this.clearSearchTextInput()
      },
    })
  }

  _editContact = () => {
    this.hideBottomDrawer()
    this.props.navigation.navigate('NewContact', {
      editMode: true,
      contact: this.state.selectedContact,
      refresh: () => {
        this.componentWillMount()
        this.clearSearchTextInput()
      },
    })
  }

  _deleteContact = async () => {
    await db.deleteContactById(this.state.selectedContact.id)
    this.componentWillMount()
    this.clearSearchTextInput()
    this.hideBottomDrawer()
    this.setState({ deleteConfirmModal: false })
    ToastAndroid.show(`${this.state.selectedContact.firstName} ${this.state.selectedContact.lastName} deleted`, ToastAndroid.SHORT);
  }

  search = (text) => {
    const res = this.state.allContacts.filter(contact => (
      contact.firstName.toLowerCase().indexOf(text.toLowerCase()) == 0
      || contact.lastName.toLowerCase().indexOf(text.toLowerCase()) == 0
      || contact.phoneNumber.toLowerCase().indexOf(text.toLowerCase()) == 0
    ))
    this.setState({ shownContacts: res })
  }

  renderItem = ({ item, index }) => (
    <ContactsListItem
      item={item}
      onPress={() => this.showBottomDrawer(item)}
      style={{
        marginTop: index == 0 ? 8 : 0,
        marginBottom: index == this.state.allContacts.length - 1 ? 8 : 0,
      }}
    />
  )

  keyExtractor = (item, index) => String(index)

  renderBody = () => {
    if (this.state.shownContacts == null && this.state.allContacts == null)
      return (
        <View style={{ flex: 1, justifyContent: 'center', alignItems: 'center' }}>
          <ActivityIndicator size="large" color={Colors.secondary} />
        </View>
      )
    else if (this.state.allContacts.length == 0)
      return (
        <EmptyList text="You don't have any contacts" />
      )
    else if (this.state.shownContacts.length == 0)
      return (
        <EmptyList text="Oops! Couldn't find anyone with such info" />
      )
    return (
      <FlatList
        data={this.state.shownContacts}
        renderItem={this.renderItem}
        keyExtractor={this.keyExtractor}
        keyboardShouldPersistTaps="always"
      />
    )
  }

  render() {
    const modalBackgroundOpacityInterpolate = this.state.modalBackgroundOpacity.interpolate({
      inputRange: [0, 1],
      outputRange: ['rgba(0, 0, 0, 0)', 'rgba(0, 0, 0, 0.32)']
    })

    return (
      <View style={{ flex: 1 }}>
        <StatusBar
          translucent
          animated
          backgroundColor="rgba(0, 0, 0, 0.3)"
          barStyle="light-content"
        />
        <View
          style={{
            backgroundColor: Colors.primary,
            height: 136,
            width: '100%',
            elevation: 6,
            paddingTop: 24,
          }}
        >
          <View style={{ flex: 0.5, justifyContent: 'center' }}>
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
                onPress={() => this.props.navigation.navigate('About')}
              />
            </View>
          </View>
          <View style={{ flex: 0.5, justifyContent: 'center' }}>
            <TextInput
              ref={input => this.textInput = input}
              style={{
                fontSize: 16,
                color: Colors.onPrimary,
                backgroundColor: 'rgba(255, 255, 255, 0.2)',
                marginRight: 8,
                marginLeft: 8,
                marginBottom: 8,
                paddingLeft: 12,
                paddingTop: 12,
                paddingRight: 12,
                borderRadius: 45,
              }}
              selectionColor={Colors.secondary}
              onChangeText={text => this.search(text)}
              placeholder="Enter name or phone number..."
              placeholderTextColor="rgba(255, 255, 255, 0.5)"
            />
          </View>
        </View>

        {this.renderBody()}

        <NewContactFAB onPress={this._createNewContact} />

        <Modal
          visible={this.state.modal}
          onRequestClose={this.hideBottomDrawer}
          transparent
          presentationStyle="overFullScreen"
        >
          <View
            style={{
              position: 'absolute',
              top: 0,
              bottom: 0,
              right: 0,
              left: 0,
              zIndex: 10,
            }}
          >
            <TouchableWithoutFeedback onPress={this.hideBottomDrawer}>
              <Animated.View
                style={{
                  width,
                  height,
                  backgroundColor: modalBackgroundOpacityInterpolate,
                }}
              />
            </TouchableWithoutFeedback>
            <Animated.View
              style={{
                backgroundColor: Colors.background,
                opacity: this.state.backgroundOpacity,
                position: 'absolute',
                width,
                height: height / 2,
                bottom: this.state.bottom,
                borderTopLeftRadius: 16,
                borderTopRightRadius: 16,
                elevation: 16,
              }}
            >
              <View
                style={{
                  flexDirection: 'row',
                  height: 80,
                  alignItems: 'center',
                  justifyContent: 'space-around',
                  paddingLeft: 16,
                  paddingRight: 16,
                  borderTopLeftRadius: 16,
                  borderTopRightRadius: 16,
                }}
              >
                <Icon
                  name="delete"
                  onPress={() => this.setState({ deleteConfirmModal: true })}
                  color={Colors.primary}
                  ripple rippleColor="rgba(0, 0, 0, 0.4)"
                />
                <Icon
                  name="edit"
                  onPress={this._editContact}
                  color={Colors.primary}
                  ripple
                  rippleColor="rgba(0, 0, 0, 0.4)"
                />
                <Icon
                  name="call"
                  onPress={() => Linking.openURL(`tel://${this.state.selectedContact.phoneNumber}`)}
                  color={Colors.primary}
                  ripple
                  rippleColor="rgba(0, 0, 0, 0.4)"
                />
              </View>
              <View
                style={{
                  flexDirection: 'row',
                  height: 56,
                  alignItems: 'center',
                  backgroundColor: Colors.background,
                  padding: 16,
                  paddingTop: 24,
                }}
              >
                <Icon name="account-circle" color={Colors.onBackground} />
                <Text style={{ fontSize: 16, letterSpacing: 0.5, paddingLeft: 16, paddingRight: 16, flexShrink: 1 }}>{this.state.selectedContact ? `${this.state.selectedContact.firstName} ${this.state.selectedContact.lastName}` : null}</Text>
              </View>
              <View style={{ flexDirection: 'row', height: 56, alignItems: 'center', backgroundColor: Colors.background, padding: 16 }}>
                <Icon name="call" color={Colors.onBackground} />
                <Text style={{ fontSize: 16, letterSpacing: 0.5, paddingLeft: 16, paddingRight: 16, flexShrink: 1 }}>{this.state.selectedContact ? `${this.state.selectedContact.phoneNumber}` : null}</Text>
              </View>
            </Animated.View>
          </View>
        </Modal>

        <MyModal
          visible={this.state.deleteConfirmModal}
          onRequestClose={() => this.setState({ deleteConfirmModal: false })}
        >
          <View>
            <Text style={{ padding: 16 }}>Delete this contact?</Text>
            <View style={{ flexDirection: 'row', justifyContent: 'flex-end', padding: 8, paddingTop: 0 }}>
              <TextButton
                label='Cancel'
                onPress={() => this.setState({ deleteConfirmModal: false })}
              />
              <TextButton
                label='Delete'
                onPress={this._deleteContact}
              />
            </View>
          </View>
        </MyModal>
      </View>
    )
  }
}
