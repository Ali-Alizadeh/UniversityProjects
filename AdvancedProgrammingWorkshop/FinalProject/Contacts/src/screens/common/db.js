import AsyncStorage from '@react-native-community/async-storage'

class Contact {
  constructor(firstName, lastName, phoneNumber) {
    this.firstName = firstName;
    this.lastName = lastName;
    this.phoneNumber = phoneNumber;
  }
}

export default class Contacts {
  static async getContacts() {
    const contacts = await AsyncStorage.getItem('contacts')
    if (contacts == null)
      return []
    return JSON.parse(contacts)
  }

  static async addNewContact(firstName, lastName, phoneNumber) {
    if (firstName == '' || lastName == '' || phoneNumber == '')
      throw String('emptyField')

    // TODO: check so that it does not exist before

    const contacts = await this.getContacts()
    const newContact = new Contact(firstName, lastName, phoneNumber)
    contacts.push(newContact)
    await AsyncStorage.setItem('contacts', JSON.stringify(contacts))
  }

  static async deleteContact() {
    const contacts = await this.getContacts()
    // TODO: find the contact and splice it
    await AsyncStorage.setItem('contacts', JSON.stringify(contacts))
  }

  static async editContact(firstName, lastName, phoneNumber) {
    const contacts = await this.getContacts()
    // TODO: find the contact and then edit its info
    await AsyncStorage.setItem('contacts', JSON.stringify(contacts))
  }
}
