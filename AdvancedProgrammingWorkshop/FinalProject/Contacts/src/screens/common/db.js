import AsyncStorage from '@react-native-community/async-storage'

class Contact {
  constructor(firstName, lastName, phoneNumber) {
    this.firstName = firstName
    this.lastName = lastName
    this.phoneNumber = phoneNumber
    this.id = Date.now()
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
    const contacts = await this.getContacts()
    if (firstName == '')
      throw String('nameIsEmpty')
    else if (phoneNumber == '')
      throw String('phoneNumberIsEmpty')

    const newContact = new Contact(firstName, lastName, phoneNumber)
    contacts.push(newContact)
    await AsyncStorage.setItem('contacts', JSON.stringify(contacts))
  }

  static async deleteContactById(id) {
    const contacts = await this.getContacts()
    for (let i = 0; i < contacts.length; i++) {
      if (contacts[i].id == id) {
        contacts.splice(i, 1)
        break
      }
    }

    await AsyncStorage.setItem('contacts', JSON.stringify(contacts))
  }

  static async editContactById(firstName, lastName, phoneNumber, id) {
    const contacts = await this.getContacts()
    if (firstName == '')
      throw String('nameIsEmpty')
    else if (phoneNumber == '')
      throw String('phoneNumberIsEmpty')

    for (let i = 0; i < contacts.length; i++) {
      if (contacts[i].id == id) {
        contacts[i].firstName = firstName
        contacts[i].lastName = lastName
        contacts[i].phoneNumber = phoneNumber
        break
      }
    }

    await AsyncStorage.setItem('contacts', JSON.stringify(contacts))
  }
}
