import React from 'react'
import { View, Text } from 'react-native'
import { TopAppBar, AppBarText, Icon } from './components/Lib'
import Colors from './common/Colors'


const About = ({ navigation }) => (
  <View style={{ flex: 1, backgroundColor: Colors.background }}>
    <TopAppBar>
      <Icon
        name="arrow-back"
        color={Colors.onPrimary}
        ripple
        style={{ marginLeft: 4 }}
        onPress={() => navigation.goBack()}
      />
      <AppBarText>About</AppBarText>
    </TopAppBar>
    <View style={{ flex: 1, padding: 16, alignItems: 'center' }}>
      <Text style={{ fontSize: 16, letterSpacing: 0.5, lineHeight: 24, color: Colors.onBackground }}>
        Developer: Ali Alizadeh
      </Text>
      <Text style={styles.text}>
        Student ID: 97440175
      </Text>
    </View>
  </View>
)

export default About
